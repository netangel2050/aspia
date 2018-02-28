//
// PROJECT:         Aspia
// FILE:            base/threading/thread_checker.cc
// LICENSE:         GNU Lesser General Public License 2.1
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "base/threading/thread_checker.h"

namespace aspia {

ThreadChecker::ThreadChecker()
{
    EnsureAssigned();
}

bool ThreadChecker::CalledOnValidThread() const
{
    std::scoped_lock<std::mutex> lock(thread_id_lock_);
    if (thread_id_ == std::this_thread::get_id())
        return true;

    return false;
}

void ThreadChecker::DetachFromThread()
{
    std::scoped_lock<std::mutex> lock(thread_id_lock_);
    thread_id_ = std::thread::id();
}

void ThreadChecker::EnsureAssigned()
{
    std::scoped_lock<std::mutex> lock(thread_id_lock_);
    thread_id_ = std::this_thread::get_id();
}

} // namespace aspia
