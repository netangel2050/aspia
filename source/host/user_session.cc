//
// Aspia Project
// Copyright (C) 2020 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#include "host/user_session.h"

#include "base/location.h"
#include "base/logging.h"
#include "base/task_runner.h"
#include "base/crypto/password_generator.h"
#include "base/desktop/frame.h"
#include "base/net/adapter_enumerator.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_util.h"
#include "base/strings/unicode.h"
#include "host/client_session_desktop.h"
#include "host/desktop_session_proxy.h"

namespace host {

UserSession::UserSession(std::shared_ptr<base::TaskRunner> task_runner,
                         base::SessionId session_id,
                         std::unique_ptr<base::IpcChannel> channel)
    : task_runner_(task_runner),
      channel_(std::move(channel)),
      attach_timer_(task_runner),
      session_id_(session_id)
{
    DCHECK(task_runner_);

    type_ = UserSession::Type::CONSOLE;

    if (session_id_ != base::activeConsoleSessionId())
        type_ = UserSession::Type::RDP;

    router_state_.set_state(proto::internal::RouterState::DISABLED);
}

UserSession::~UserSession() = default;

void UserSession::start(base::HostId host_id, Delegate* delegate)
{
    delegate_ = delegate;
    host_id_ = host_id;

    DCHECK(delegate_);

    LOG(LS_INFO) << "User session started "
                 << (channel_ ? "with" : "without")
                 << " connection to UI";

    desktop_session_ = std::make_unique<DesktopSessionManager>(task_runner_, this);
    desktop_session_proxy_ = desktop_session_->sessionProxy();
    desktop_session_->attachSession(FROM_HERE, session_id_);

    updateCredentials();

    if (channel_)
    {
        channel_->setListener(this);
        channel_->resume();
    }

    state_ = State::STARTED;
    delegate_->onUserSessionStarted();
}

void UserSession::restart(std::unique_ptr<base::IpcChannel> channel)
{
    channel_ = std::move(channel);

    LOG(LS_INFO) << "User session restarted "
                 << (channel_ ? "with" : "without")
                 << " connection to UI";

    attach_timer_.stop();
    updateCredentials();

    desktop_session_->attachSession(FROM_HERE, session_id_);

    if (channel_)
    {
        channel_->setListener(this);
        channel_->resume();

        auto send_connection_list = [this](const ClientSessionList& list)
        {
            for (const auto& client : list)
                sendConnectEvent(*client);
        };

        send_connection_list(desktop_clients_);
        send_connection_list(file_transfer_clients_);
        sendRouterState();
    }

    state_ = State::STARTED;
    delegate_->onUserSessionStarted();
}

base::User UserSession::user() const
{
    base::User user = base::User::create(
        base::utf16FromAscii(username_), base::utf16FromAscii(password_));

    user.sessions = proto::SESSION_TYPE_ALL;
    user.flags = base::User::ENABLED;

    return user;
}

void UserSession::addNewSession(std::unique_ptr<ClientSession> client_session)
{
    DCHECK(client_session);

    ClientSession* client_session_ptr = client_session.get();

    switch (client_session_ptr->sessionType())
    {
        case proto::SESSION_TYPE_DESKTOP_MANAGE:
        case proto::SESSION_TYPE_DESKTOP_VIEW:
        {
            desktop_clients_.emplace_back(std::move(client_session));

            ClientSessionDesktop* desktop_client_session =
                static_cast<ClientSessionDesktop*>(client_session_ptr);

            desktop_client_session->setDesktopSessionProxy(desktop_session_proxy_);
            desktop_session_proxy_->control(proto::internal::Control::ENABLE);
            desktop_session_proxy_->captureScreen();
        }
        break;

        case proto::SESSION_TYPE_FILE_TRANSFER:
        {
            file_transfer_clients_.emplace_back(std::move(client_session));
        }
        break;

        default:
        {
            NOTREACHED();
            return;
        }
        break;
    }

    client_session_ptr->setSessionId(sessionId());
    client_session_ptr->start(this);

    // Notify the UI of a new connection.
    sendConnectEvent(*client_session_ptr);
}

void UserSession::setSessionEvent(base::win::SessionStatus status, base::SessionId session_id)
{
    switch (status)
    {
        case base::win::SessionStatus::CONSOLE_CONNECT:
        {
            session_id_ = session_id;

            for (const auto& client : desktop_clients_)
                client->setSessionId(session_id);

            if (desktop_session_)
                desktop_session_->attachSession(FROM_HERE, session_id);
        }
        break;

        case base::win::SessionStatus::CONSOLE_DISCONNECT:
        {
            if (desktop_session_)
                desktop_session_->dettachSession(FROM_HERE);

            onSessionDettached(FROM_HERE);
        }
        break;

        default:
        {
            // Ignore other events.
        }
        break;
    }
}

void UserSession::setRouterState(const proto::internal::RouterState& router_state)
{
    router_state_ = router_state;
    sendRouterState();
}

void UserSession::setHostId(base::HostId host_id)
{
    host_id_ = host_id;
    sendCredentials();
}

void UserSession::onDisconnected()
{
    onSessionDettached(FROM_HERE);
}

void UserSession::onMessageReceived(const base::ByteArray& buffer)
{
    incoming_message_.Clear();

    if (!base::parse(buffer, &incoming_message_))
    {
        LOG(LS_ERROR) << "Invalid message from UI";
        return;
    }

    if (incoming_message_.has_credentials_request())
    {
        proto::internal::CredentialsRequest::Type type =
            incoming_message_.credentials_request().type();

        if (type == proto::internal::CredentialsRequest::NEW_PASSWORD)
        {
            updateCredentials();
        }
        else
        {
            DCHECK_EQ(type, proto::internal::CredentialsRequest::REFRESH);
        }

        sendCredentials();
    }
    else if (incoming_message_.has_kill_session())
    {
        killClientSession(incoming_message_.kill_session().id());
    }
    else
    {
        LOG(LS_WARNING) << "Unhandled message from UI";
    }
}

void UserSession::onDesktopSessionStarted()
{
    LOG(LS_INFO) << "Desktop session is connected";

    proto::internal::Control::Action action = proto::internal::Control::ENABLE;
    if (desktop_clients_.empty())
        action = proto::internal::Control::DISABLE;

    desktop_session_proxy_->control(action);
    onClientSessionConfigured();
}

void UserSession::onDesktopSessionStopped()
{
    LOG(LS_INFO) << "Desktop session is disconnected";

    if (type_ == Type::RDP)
    {
        desktop_clients_.clear();
        file_transfer_clients_.clear();

        onSessionDettached(FROM_HERE);
    }
}

void UserSession::onScreenCaptured(const base::Frame* frame, const base::MouseCursor* cursor)
{
    for (const auto& client : desktop_clients_)
        static_cast<ClientSessionDesktop*>(client.get())->encode(frame, cursor);
}

void UserSession::onScreenListChanged(const proto::ScreenList& list)
{
    for (const auto& client : desktop_clients_)
        static_cast<ClientSessionDesktop*>(client.get())->setScreenList(list);
}

void UserSession::onClipboardEvent(const proto::ClipboardEvent& event)
{
    for (const auto& client : desktop_clients_)
        static_cast<ClientSessionDesktop*>(client.get())->injectClipboardEvent(event);
}

void UserSession::onClientSessionConfigured()
{
    if (desktop_clients_.empty())
        return;

    DesktopSession::Config system_config;
    memset(&system_config, 0, sizeof(system_config));

    for (const auto& client : desktop_clients_)
    {
        const DesktopSession::Config& client_config =
            static_cast<ClientSessionDesktop*>(client.get())->desktopSessionConfig();

        // If at least one client has disabled font smoothing, then the font smoothing will be
        // disabled for everyone.
        system_config.disable_font_smoothing =
            system_config.disable_font_smoothing || client_config.disable_font_smoothing;

        // If at least one client has disabled effects, then the effects will be disabled for
        // everyone.
        system_config.disable_effects =
            system_config.disable_effects || client_config.disable_effects;

        // If at least one client has disabled the wallpaper, then the effects will be disabled for
        // everyone.
        system_config.disable_wallpaper =
            system_config.disable_wallpaper || client_config.disable_wallpaper;

        // If at least one client has enabled input block, then the block will be enabled for
        // everyone.
        system_config.block_input = system_config.block_input || client_config.block_input;

        system_config.lock_at_disconnect =
            system_config.lock_at_disconnect || client_config.lock_at_disconnect;
    }

    desktop_session_proxy_->configure(system_config);
}

void UserSession::onClientSessionFinished()
{
    auto delete_finished = [this](ClientSessionList* list)
    {
        for (auto it = list->begin(); it != list->end();)
        {
            ClientSession* client_session = it->get();

            if (client_session->state() == ClientSession::State::FINISHED)
            {
                // Notification of the UI about disconnecting the client.
                sendDisconnectEvent(client_session->id());

                // Session will be destroyed after completion of the current call.
                task_runner_->deleteSoon(std::move(*it));

                // Delete a session from the list.
                it = list->erase(it);
            }
            else
            {
                ++it;
            }
        }
    };

    delete_finished(&desktop_clients_);
    delete_finished(&file_transfer_clients_);

    if (desktop_clients_.empty())
        desktop_session_proxy_->control(proto::internal::Control::DISABLE);
}

void UserSession::onSessionDettached(const base::Location& location)
{
    if (state_ == State::DETTACHED)
        return;

    LOG(LS_INFO) << "Dettach session (from: " << location.toString() << ")";

    task_runner_->deleteSoon(std::move(channel_));
    username_.clear();
    password_.clear();

    // Stop one-time desktop clients.
    for (const auto& client : desktop_clients_)
    {
        if (base::startsWith(client->userName(), "#"))
            client->stop();
    }

    // Stop all file transfer clients.
    for (const auto& client : file_transfer_clients_)
        client->stop();

    state_ = State::DETTACHED;
    delegate_->onUserSessionDettached();

    if (type_ == Type::RDP)
    {
        delegate_->onUserSessionFinished();
    }
    else
    {
        attach_timer_.start(std::chrono::minutes(1), [this]()
        {
            LOG(LS_INFO) << "Session attach timeout";

            state_ = State::FINISHED;
            delegate_->onUserSessionFinished();
        });
    }
}

void UserSession::sendConnectEvent(const ClientSession& client_session)
{
    if (!channel_)
        return;

    outgoing_message_.Clear();
    proto::internal::ConnectEvent* event = outgoing_message_.mutable_connect_event();

    event->set_remote_address(base::utf8FromUtf16(client_session.peerAddress()));
    event->set_username(client_session.userName());
    event->set_session_type(client_session.sessionType());
    event->set_id(client_session.id());

    channel_->send(base::serialize(outgoing_message_));
}

void UserSession::sendDisconnectEvent(uint32_t session_id)
{
    if (!channel_)
        return;

    outgoing_message_.Clear();
    outgoing_message_.mutable_disconnect_event()->set_id(session_id);
    channel_->send(base::serialize(outgoing_message_));
}

void UserSession::updateCredentials()
{
    base::PasswordGenerator generator;

    static const uint32_t kPasswordCharacters = base::PasswordGenerator::UPPER_CASE |
        base::PasswordGenerator::LOWER_CASE | base::PasswordGenerator::DIGITS;
    static const int kPasswordLength = 6;

    // TODO: Get password parameters from settings.
    generator.setCharacters(kPasswordCharacters);
    generator.setLength(kPasswordLength);

    username_ = "#" + base::numberToString(sessionId());
    password_ = generator.result();
}

void UserSession::sendCredentials()
{
    if (!channel_)
        return;

    LOG(LS_INFO) << "Sending credentials to UI";
    LOG(LS_INFO) << "Host ID: " << host_id_;
    LOG(LS_INFO) << "User Name: " << username_;

    outgoing_message_.Clear();

    proto::internal::Credentials* credentials = outgoing_message_.mutable_credentials();
    credentials->set_host_id(host_id_);
    credentials->set_username(username_);
    credentials->set_password(password_);

    for (base::AdapterEnumerator adapters; !adapters.isAtEnd(); adapters.advance())
    {
        for (base::AdapterEnumerator::IpAddressEnumerator addresses(adapters);
             !addresses.isAtEnd(); addresses.advance())
        {
            std::string ip = addresses.address();

            if (ip != "127.0.0.1")
                credentials->add_host_ip(std::move(ip));
        }
    }

    channel_->send(base::serialize(outgoing_message_));
}

void UserSession::killClientSession(uint32_t id)
{
    auto stop_by_id = [](ClientSessionList* list, uint32_t id)
    {
        for (const auto& client_session : *list)
        {
            if (client_session->id() == id)
            {
                client_session->stop();
                break;
            }
        }
    };

    stop_by_id(&desktop_clients_, id);
    stop_by_id(&file_transfer_clients_, id);
}

void UserSession::sendRouterState()
{
    if (!channel_)
        return;

    LOG(LS_INFO) << "Sending router state to UI";
    LOG(LS_INFO) << "Router: " << router_state_.host_name() << ":" << router_state_.host_port();
    LOG(LS_INFO) << "New state: " << router_state_.state();

    outgoing_message_.Clear();
    outgoing_message_.mutable_router_state()->CopyFrom(router_state_);
    channel_->send(base::serialize(outgoing_message_));
}

} // namespace host
