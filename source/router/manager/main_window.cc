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

#include "router/manager/main_window.h"

#include "base/logging.h"
#include "base/peer/user.h"
#include "qt_base/application.h"
#include "router/manager/user_dialog.h"
#include "router/manager/router.h"
#include "router/manager/router_proxy.h"
#include "router/manager/router_window_proxy.h"
#include "router/manager/status_dialog.h"

#include <QDateTime>
#include <QMessageBox>
#include <QTimer>

namespace router {

namespace {

class HostTreeItem : public QTreeWidgetItem
{
public:
    explicit HostTreeItem(const proto::Host& host)
        : host_id(host.host_id())
    {
        setText(0, QString::number(host.host_id()));
        setText(1, QDateTime::fromTime_t(host.timepoint()).toString(Qt::DefaultLocaleShortDate));
        setText(2, QString::fromStdString(host.ip_address()));
        setText(3, QString("%1.%2.%3")
                .arg(host.version().major())
                .arg(host.version().minor())
                .arg(host.version().patch()));
        setText(4, QString::fromStdString(host.computer_name()));
        setText(5, QString::fromStdString(host.os_name()));
    }

    ~HostTreeItem() = default;

    base::HostId host_id;

private:
    DISALLOW_COPY_AND_ASSIGN(HostTreeItem);
};

class RelayTreeItem : public QTreeWidgetItem
{
public:
    explicit RelayTreeItem(const proto::Relay& relay)
    {
        setText(0, QString::fromStdString(relay.address()));
        setText(1, QDateTime::fromTime_t(relay.timepoint()).toString(Qt::DefaultLocaleShortDate));
        setText(2, QString::number(relay.pool_size()));
        setText(3, QString("%1.%2.%3")
                .arg(relay.version().major())
                .arg(relay.version().minor())
                .arg(relay.version().patch()));
        setText(4, QString::fromStdString(relay.computer_name()));
        setText(5, QString::fromStdString(relay.os_name()));
    }

private:
    DISALLOW_COPY_AND_ASSIGN(RelayTreeItem);
};

class UserTreeItem : public QTreeWidgetItem
{
public:
    explicit UserTreeItem(const proto::User& user)
        : user(base::User::parseFrom(user))
    {
        setText(0, QString::fromStdString(user.name()));

        if (user.flags() & base::User::ENABLED)
            setIcon(0, QIcon(QLatin1String(":/img/user.png")));
        else
            setIcon(0, QIcon(QLatin1String(":/img/user-disabled.png")));
    }

    base::User user;

private:
    DISALLOW_COPY_AND_ASSIGN(UserTreeItem);
};

} // namespace

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      status_dialog_(new StatusDialog(this)),
      window_proxy_(std::make_shared<RouterWindowProxy>(qt_base::Application::uiTaskRunner(), this))
{
    ui.setupUi(this);

    connect(ui.button_refresh_hosts, &QPushButton::released, this, &MainWindow::refreshHostList);
    connect(ui.button_disconnect_host, &QPushButton::released, this, &MainWindow::disconnectHost);
    connect(ui.button_disconnect_all_hosts, &QPushButton::released, this, &MainWindow::disconnectAllHosts);
    connect(ui.button_refresh_relay, &QPushButton::released, this, &MainWindow::refreshRelayList);
    connect(ui.button_refresh_users, &QPushButton::released, this, &MainWindow::refreshUserList);
    connect(ui.button_add_user, &QPushButton::released, this, &MainWindow::addUser);
    connect(ui.button_modify_user, &QPushButton::released, this, &MainWindow::modifyUser);
    connect(ui.button_delete_user, &QPushButton::released, this, &MainWindow::deleteUser);
    connect(ui.tree_users, &QTreeWidget::currentItemChanged, this, &MainWindow::onCurrentUserChanged);
}

MainWindow::~MainWindow()
{
    window_proxy_->dettach();
}

void MainWindow::connectToRouter(const QString& address,
                                 uint16_t port,
                                 const QString& user_name,
                                 const QString& password)
{
    peer_address_ = address;
    peer_port_ = port;

    status_dialog_->setStatus(tr("Connecting to %1:%2...").arg(address).arg(port));
    status_dialog_->show();
    status_dialog_->activateWindow();

    connect(status_dialog_, &StatusDialog::canceled, [this]()
    {
        router_proxy_.reset();
        close();
    });

    std::unique_ptr<Router> router = std::make_unique<Router>(
        window_proxy_, qt_base::Application::ioTaskRunner());

    router->setUserName(user_name.toStdU16String());
    router->setPassword(password.toStdU16String());

    router_proxy_ = std::make_unique<RouterProxy>(
        qt_base::Application::ioTaskRunner(), std::move(router));

    router_proxy_->connectToRouter(address.toStdU16String(), port);
}

void MainWindow::onConnected(const base::Version& peer_version)
{
    status_dialog_->hide();

    ui.statusbar->showMessage(tr("Connected to: %1:%2 (version %3)")
                              .arg(peer_address_)
                              .arg(peer_port_)
                              .arg(QString::fromStdString(peer_version.toString())));
    show();
    activateWindow();

    if (router_proxy_)
    {
        router_proxy_->refreshHostList();
        router_proxy_->refreshRelayList();
        router_proxy_->refreshUserList();
    }
}

void MainWindow::onDisconnected(base::NetworkChannel::ErrorCode error_code)
{
    const char* message;

    switch (error_code)
    {
        case base::NetworkChannel::ErrorCode::ACCESS_DENIED:
            message = QT_TR_NOOP("Cryptography error (message encryption or decryption failed).");
            break;

        case base::NetworkChannel::ErrorCode::NETWORK_ERROR:
            message = QT_TR_NOOP("An error occurred with the network (e.g., the network cable was accidentally plugged out).");
            break;

        case base::NetworkChannel::ErrorCode::CONNECTION_REFUSED:
            message = QT_TR_NOOP("Connection was refused by the peer (or timed out).");
            break;

        case base::NetworkChannel::ErrorCode::REMOTE_HOST_CLOSED:
            message = QT_TR_NOOP("Remote host closed the connection.");
            break;

        case base::NetworkChannel::ErrorCode::SPECIFIED_HOST_NOT_FOUND:
            message = QT_TR_NOOP("Host address was not found.");
            break;

        case base::NetworkChannel::ErrorCode::SOCKET_TIMEOUT:
            message = QT_TR_NOOP("Socket operation timed out.");
            break;

        case base::NetworkChannel::ErrorCode::ADDRESS_IN_USE:
            message = QT_TR_NOOP("Address specified is already in use and was set to be exclusive.");
            break;

        case base::NetworkChannel::ErrorCode::ADDRESS_NOT_AVAILABLE:
            message = QT_TR_NOOP("Address specified does not belong to the host.");
            break;

        default:
        {
            if (error_code != base::NetworkChannel::ErrorCode::UNKNOWN)
            {
                LOG(LS_WARNING) << "Unknown error code: " << static_cast<int>(error_code);
            }

            message = QT_TR_NOOP("An unknown error occurred.");
        }
        break;
    }

    status_dialog_->setStatus(tr("Error: %1").arg(tr(message)));
    status_dialog_->show();
}

void MainWindow::onAccessDenied(base::ClientAuthenticator::ErrorCode error_code)
{
    const char* message;

    switch (error_code)
    {
        case base::ClientAuthenticator::ErrorCode::SUCCESS:
            message = QT_TR_NOOP("Authentication successfully completed.");
            break;

        case base::ClientAuthenticator::ErrorCode::NETWORK_ERROR:
            message = QT_TR_NOOP("Network authentication error.");
            break;

        case base::ClientAuthenticator::ErrorCode::PROTOCOL_ERROR:
            message = QT_TR_NOOP("Violation of the data exchange protocol.");
            break;

        case base::ClientAuthenticator::ErrorCode::ACCESS_DENIED:
            message = QT_TR_NOOP("An error occured while authenticating: wrong user name or password.");
            break;

        case base::ClientAuthenticator::ErrorCode::SESSION_DENIED:
            message = QT_TR_NOOP("Specified session type is not allowed for the user.");
            break;

        default:
            message = QT_TR_NOOP("An unknown error occurred.");
            break;
    }

    status_dialog_->setStatus(tr("Error: %1").arg(tr(message)));
    status_dialog_->show();
}

void MainWindow::onHostList(std::shared_ptr<proto::HostList> host_list)
{
    ui.tree_hosts->clear();

    int host_size = host_list->host_size();

    for (int i = 0; i < host_size; ++i)
        ui.tree_hosts->addTopLevelItem(new HostTreeItem(host_list->host(i)));
    ui.label_hosts_conn_count->setText(QString::number(host_size));

    for (int i = 0; i < ui.tree_hosts->columnCount(); ++i)
        ui.tree_hosts->resizeColumnToContents(i);

    afterRequest();
}

void MainWindow::onHostResult(std::shared_ptr<proto::HostResult> host_result)
{
    if (host_result->error_code() != proto::HostResult::SUCCESS)
    {
        const char* message;

        switch (host_result->error_code())
        {
            case proto::HostResult::INVALID_REQUEST:
                message = QT_TR_NOOP("Invalid request.");
                break;

            case proto::HostResult::INTERNAL_ERROR:
                message = QT_TR_NOOP("Unknown internal error.");
                break;

            case proto::HostResult::INVALID_HOST_ID:
                message = QT_TR_NOOP("Invalid host ID was passed.");
                break;

            case proto::HostResult::HOST_MISSED:
                message = QT_TR_NOOP("The specified host is not connected to the router.");
                break;

            default:
                message = QT_TR_NOOP("Unknown error type.");
                break;
        }

        QMessageBox::warning(this, tr("Warning"), tr(message), QMessageBox::Ok);
    }

    refreshHostList();
    afterRequest();
}

void MainWindow::onRelayList(std::shared_ptr<proto::RelayList> relay_list)
{
    ui.tree_relay->clear();

    int relay_size = relay_list->relay_size();
    for (int i = 0; i < relay_size; ++i)
        ui.tree_relay->addTopLevelItem(new RelayTreeItem(relay_list->relay(i)));
    ui.label_relay_conn_count->setText(QString::number(relay_size));

    for (int i = 0; i < ui.tree_relay->columnCount(); ++i)
        ui.tree_relay->resizeColumnToContents(i);

    afterRequest();
}

void MainWindow::onUserList(std::shared_ptr<proto::UserList> user_list)
{
    ui.tree_users->clear();

    for (int i = 0; i < user_list->user_size(); ++i)
        ui.tree_users->addTopLevelItem(new UserTreeItem(user_list->user(i)));

    afterRequest();
}

void MainWindow::onUserResult(std::shared_ptr<proto::UserResult> user_result)
{
    if (user_result->error_code() != proto::UserResult::SUCCESS)
    {
        const char* message;

        switch (user_result->error_code())
        {
            case proto::UserResult::INTERNAL_ERROR:
                message = QT_TR_NOOP("Unknown internal error.");
                break;

            case proto::UserResult::INVALID_DATA:
                message = QT_TR_NOOP("Invalid data was passed.");
                break;

            case proto::UserResult::ALREADY_EXISTS:
                message = QT_TR_NOOP("A user with the specified name already exists.");
                break;

            default:
                message = QT_TR_NOOP("Unknown error type.");
                break;
        }

        QMessageBox::warning(this, tr("Warning"), tr(message), QMessageBox::Ok);
    }

    refreshUserList();
    afterRequest();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (router_proxy_)
        router_proxy_->disconnectFromRouter();

    QApplication::quit();
}

void MainWindow::refreshHostList()
{
    if (router_proxy_)
    {
        beforeRequest();
        router_proxy_->refreshHostList();
    }
}

void MainWindow::disconnectHost()
{
    HostTreeItem* tree_item = static_cast<HostTreeItem*>(ui.tree_hosts->currentItem());
    if (!tree_item)
        return;

    if (QMessageBox::question(this,
                              tr("Confirmation"),
                              tr("Are you sure you want to disconnect host with ID \"%1\"?")
                              .arg(tree_item->host_id),
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    if (router_proxy_)
    {
        beforeRequest();
        router_proxy_->disconnectHost(tree_item->host_id);
    }
}

void MainWindow::disconnectAllHosts()
{
    if (!router_proxy_)
        return;

    if (QMessageBox::question(this,
                              tr("Confirmation"),
                              tr("Are you sure you want to disconnect all hosts?"),
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    beforeRequest();

    for (int i = 0; i < ui.tree_hosts->topLevelItemCount(); ++i)
    {
        HostTreeItem* tree_item = static_cast<HostTreeItem*>(ui.tree_hosts->topLevelItem(i));
        if (tree_item)
            router_proxy_->disconnectHost(tree_item->host_id);
    }
}

void MainWindow::refreshRelayList()
{
    if (router_proxy_)
    {
        beforeRequest();
        router_proxy_->refreshRelayList();
    }
}

void MainWindow::refreshUserList()
{
    if (router_proxy_)
    {
        beforeRequest();
        router_proxy_->refreshUserList();
    }
}

void MainWindow::addUser()
{
    std::vector<std::u16string> users;

    for (int i = 0; i < ui.tree_users->topLevelItemCount(); ++i)
    {
        users.emplace_back(static_cast<UserTreeItem*>(
            ui.tree_users->topLevelItem(i))->user.name);
    }

    UserDialog dialog(base::User(), users, this);
    if (dialog.exec() == QDialog::Accepted)
    {
        if (router_proxy_)
        {
            beforeRequest();
            router_proxy_->addUser(dialog.user().serialize());
        }
    }
}

void MainWindow::modifyUser()
{
    UserTreeItem* tree_item = static_cast<UserTreeItem*>(ui.tree_users->currentItem());
    if (!tree_item)
        return;

    std::vector<std::u16string> users;

    for (int i = 0; i < ui.tree_users->topLevelItemCount(); ++i)
    {
        UserTreeItem* current_item = static_cast<UserTreeItem*>(ui.tree_users->topLevelItem(i));
        if (current_item->text(0).compare(tree_item->text(0), Qt::CaseInsensitive) != 0)
            users.emplace_back(current_item->user.name);
    }

    UserDialog dialog(tree_item->user, users, this);
    if (dialog.exec() == QDialog::Accepted)
    {
        if (router_proxy_)
        {
            beforeRequest();
            router_proxy_->modifyUser(dialog.user().serialize());
        }
    }
}

void MainWindow::deleteUser()
{
    UserTreeItem* tree_item = static_cast<UserTreeItem*>(ui.tree_users->currentItem());
    if (!tree_item)
        return;

    if (QMessageBox::question(this,
                              tr("Confirmation"),
                              tr("Are you sure you want to delete user \"%1\"?")
                              .arg(tree_item->text(0)),
                              QMessageBox::Yes,
                              QMessageBox::No) == QMessageBox::Yes)
    {
        if (router_proxy_)
        {
            beforeRequest();
            router_proxy_->deleteUser(tree_item->user.entry_id);
        }
    }
}

void MainWindow::onCurrentUserChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous)
{
    ui.button_modify_user->setEnabled(true);
    ui.button_delete_user->setEnabled(true);
}

void MainWindow::beforeRequest()
{
    ui.tab->setEnabled(false);
}

void MainWindow::afterRequest()
{
    ui.tab->setEnabled(true);
}

} // namespace router
