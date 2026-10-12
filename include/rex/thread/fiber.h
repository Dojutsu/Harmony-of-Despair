/**
 * @file        rex/thread/fiber.h
 * @brief       Host OS fiber primitive for cooperative context switching
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 *              All rights reserved.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#pragma once

#include <rex/platform.h>
#include <cstddef>

#if REX_PLATFORM_ANDROID
// Bionic has no makecontext/swapcontext; fibers are backed by parked host
// threads handed the CPU one at a time (see fiber_android.cpp).
#include <condition_variable>
#include <cstdint>
#include <mutex>
#include <thread>
#elif REX_PLATFORM_LINUX || REX_PLATFORM_MAC
#if REX_PLATFORM_MAC && !defined(_XOPEN_SOURCE)
// Darwin hides the deprecated ucontext APIs unless _XOPEN_SOURCE is defined
// before including <ucontext.h>.
#define _XOPEN_SOURCE 700
#endif
#include <ucontext.h>
#include <cstdint>
#include <vector>
#endif

namespace rex::thread {

/// Host OS fiber primitive.
/// Each guest fiber gets one Fiber. Switching preserves the entire C++ call
/// stack, so mid-function resume works without any LR lookup.
struct Fiber {
  /// Convert the calling thread into a fiber.
  /// Must be called once on a thread before any SwitchTo.
  /// Returns a handle for the thread's current execution context.
  static Fiber* ConvertCurrentThread();

  /// Create a new fiber with its own host stack.
  /// entry(arg) is called when the fiber is first switched to.
  static Fiber* Create(size_t stack_size, void (*entry)(void*), void* arg);

  /// Suspend the current fiber and resume target.
  /// Returns when another fiber calls SwitchTo back to this one.
  static void SwitchTo(Fiber* target);

  /// Destroy this fiber. Must not be called while it is executing.
  void Destroy();

  /// Returns the fiber currently executing on this thread, or nullptr.
  static Fiber* Current() { return tls_current_; }

 private:
  static thread_local Fiber* tls_current_;

#if REX_PLATFORM_WIN32
  void* handle_ = nullptr;
  bool is_thread_fiber_ = false;
#elif REX_PLATFORM_ANDROID
  // Shared by every fiber of one host thread: serializes which fiber runs.
  struct Scheduler {
    std::mutex mutex;
    std::condition_variable cv;
    Fiber* running = nullptr;
  };
  Scheduler* scheduler_ = nullptr;
  std::thread thread_;
  void (*entry_)(void*) = nullptr;
  void* arg_ = nullptr;
  bool is_thread_fiber_ = false;
  bool started_ = false;
  bool finished_ = false;

  void WaitUntilRunning();
  static void ThreadMain(Fiber* self);
#elif REX_PLATFORM_LINUX || REX_PLATFORM_MAC
  ucontext_t context_{};
  std::vector<uint8_t> stack_;
  void (*entry_)(void*) = nullptr;
  void* arg_ = nullptr;
  bool is_thread_fiber_ = false;

  static void Trampoline();
#endif
};

}  // namespace rex::thread
