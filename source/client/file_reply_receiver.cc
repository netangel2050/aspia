//
// PROJECT:         Aspia
// FILE:            client/file_reply_receiver.cc
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "client/file_reply_receiver.h"
#include "client/file_reply_receiver_proxy.h"
#include "base/logging.h"

namespace aspia {

FileReplyReceiver::FileReplyReceiver()
{
    receiver_proxy_.reset(new FileReplyReceiverProxy(this));
}

FileReplyReceiver::~FileReplyReceiver()
{
    receiver_proxy_->WillDestroyCurrentReplyReceiver();
    receiver_proxy_ = nullptr;
}

void FileReplyReceiver::OnDriveListReply(
    std::shared_ptr<proto::file_transfer::DriveList> /* drive_list */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: drive list";
}

void FileReplyReceiver::OnFileListReply(
    const std::experimental::filesystem::path& /* path */,
    std::shared_ptr<proto::file_transfer::FileList> /* file_list */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: file list";
}

void FileReplyReceiver::OnDirectorySizeReply(
    const std::experimental::filesystem::path& /* path */,
    uint64_t /* size */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: directory size";
}

void FileReplyReceiver::OnCreateDirectoryReply(
    const std::experimental::filesystem::path& /* path */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: create directory";
}

void FileReplyReceiver::OnRemoveReply(
    const std::experimental::filesystem::path& /* path */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: remove";
}

void FileReplyReceiver::OnRenameReply(
    const std::experimental::filesystem::path& /* old_name */,
    const std::experimental::filesystem::path& /* new_name */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: rename";
}

void FileReplyReceiver::OnFileUploadReply(
    const std::experimental::filesystem::path& /* file_path */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: file upload";
}

void FileReplyReceiver::OnFileDownloadReply(
    const std::experimental::filesystem::path& /* file_path */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: file download";
}

void FileReplyReceiver::OnFilePacketSended(
    uint32_t /* flags */, proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: file packet sended";
}

void FileReplyReceiver::OnFilePacketReceived(
    std::shared_ptr<proto::file_transfer::FilePacket> /* file_packet */,
    proto::file_transfer::Status /* status */)
{
    DLOG(LS_WARNING) << "Unhandled reply: file packet received";
}

} // namespace aspia
