//
// PROJECT:         Aspia
// FILE:            client/file_transfer.h
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_CLIENT__FILE_TRANSFER_H
#define _ASPIA_CLIENT__FILE_TRANSFER_H

#include "client/file_reply_receiver.h"
#include "client/file_request_sender_proxy.h"
#include "client/file_task_queue_builder.h"
#include "client/file_constants.h"

namespace aspia {

class FileTransfer
    : public FileReplyReceiver
{
public:
    using ActionCallback = std::function<void(FileAction action)>;

    class Delegate
    {
    public:
        virtual ~Delegate() = default;

        virtual void OnTransferStarted(uint64_t size) = 0;

        virtual void OnTransferComplete() = 0;

        virtual void OnFileOperationFailure(const std::experimental::filesystem::path& file_path,
                                            proto::file_transfer::Status status,
                                            ActionCallback callback) = 0;

        virtual void OnObjectTransferStarted(const std::experimental::filesystem::path& object_path,
                                             uint64_t object_size) = 0;

        virtual void OnObjectTransfer(uint64_t left_object_size) = 0;
    };

    FileTransfer(std::shared_ptr<FileRequestSenderProxy> local_sender,
                 std::shared_ptr<FileRequestSenderProxy> remote_sender,
                 Delegate* delegate)
        : local_sender_(local_sender),
          remote_sender_(remote_sender),
          delegate_(delegate)
    {
        // Nothing
    }

    virtual ~FileTransfer() = default;

    virtual void Start(const std::experimental::filesystem::path& source_path,
                       const std::experimental::filesystem::path& target_path,
                       const FileTaskQueueBuilder::FileList& file_list) = 0;

protected:
    std::shared_ptr<FileRequestSenderProxy> remote_sender_;
    std::shared_ptr<FileRequestSenderProxy> local_sender_;
    Delegate* delegate_;

    FileAction create_directory_failure_action_ = FileAction::ASK;
    FileAction file_create_failure_action_ = FileAction::ASK;
    FileAction file_open_failure_action_ = FileAction::ASK;
    FileAction file_write_failure_action_ = FileAction::ASK;
    FileAction file_read_failure_action_ = FileAction::ASK;
};

} // namespace aspia

#endif // _ASPIA_CLIENT__FILE_TRANSFER_H
