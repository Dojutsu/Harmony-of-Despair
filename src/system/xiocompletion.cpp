/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

#include <rex/system/xiocompletion.h>
#include <rex/system/xthread.h>
#include "absolute_wait_deadline.h"

namespace rex::system {

XIOCompletion::XIOCompletion(KernelState* kernel_state) : XObject(kernel_state, kObjectType) {
  notification_semaphore_ = rex::thread::Semaphore::Create(0, kMaxNotifications);
  assert_not_null(notification_semaphore_);
}

XIOCompletion::~XIOCompletion() = default;

void XIOCompletion::QueueNotification(IONotification& notification) {
  std::unique_lock<std::mutex> lock(notification_lock_);

  notifications_.push(notification);
  notification_semaphore_->Release(1, nullptr);
}

bool XIOCompletion::WaitForNotification(uint64_t wait_ticks, IONotification* notify) {
  const bool absolute = static_cast<int64_t>(wait_ticks) > 0;
  for (;;) {
    auto ms = absolute ? detail::AbsoluteWaitSlice(wait_ticks)
                       : std::chrono::milliseconds(TimeoutTicksToMs(wait_ticks));
    XThread::CheckTitleTermination();
    auto res = rex::thread::Wait(notification_semaphore_.get(), false, ms);
    XThread::CheckTitleTermination();
    if (absolute && res == rex::thread::WaitResult::kTimeout &&
        detail::AbsoluteWaitPending(wait_ticks)) {
      continue;
    }
    if (res == rex::thread::WaitResult::kSuccess) {
      std::unique_lock<std::mutex> lock(notification_lock_);
      assert_false(notifications_.empty());

      std::memcpy(notify, &notifications_.front(), sizeof(IONotification));
      notifications_.pop();

      return true;
    }

    return false;
  }
}

}  // namespace rex::system
