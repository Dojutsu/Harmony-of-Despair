#pragma once

#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <mutex>
#include <stop_token>

namespace rex::system::xam::detail {

// Owned by one directory worker. Notifiers never inspect admission state under
// this mutex, and the wait predicate never takes admission/session locks.
class AdmissionWorkWakeup final {
 public:
  using Revision = uint64_t;

  Revision Observe() {
    std::lock_guard lock(mutex_);
    return revision_;
  }

  void Notify() {
    {
      std::lock_guard lock(mutex_);
      ++revision_;
    }
    changed_.notify_all();
  }

  template <typename Rep, typename Period>
  bool Wait(std::stop_token stop, Revision observed,
            std::chrono::duration<Rep, Period> timeout) {
    std::unique_lock lock(mutex_);
    return changed_.wait_for(lock, stop, timeout,
                             [&] { return revision_ != observed; });
  }

  template <typename Poll, typename Drained, typename Rep, typename Period>
  void Run(std::stop_token stop, Poll&& poll, Drained&& drained,
           std::chrono::duration<Rep, Period> interval) {
    for (;;) {
      // Observe BEFORE the RPC/poll pass: work notified during a blocking RPC
      // must remain visible when the worker reaches its next wait.
      const auto observed = Observe();
      poll();
      if (stop.stop_requested() && drained())
        break;
      Wait(stop, observed, interval);
    }
  }

 private:
  std::mutex mutex_;
  std::condition_variable_any changed_;
  Revision revision_ = 0;
};

}  // namespace rex::system::xam::detail
