/**
 * @file        core/fiber_android.cpp
 * @brief       Android backend for rex::thread::Fiber (parked host threads)
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 *
 * Bionic does not implement makecontext/swapcontext, so each created fiber
 * owns a host thread that is parked on a condition variable. SwitchTo hands
 * the single "running" token to the target fiber and blocks until the token
 * comes back. Exactly one fiber of a host thread's group executes at a time,
 * which preserves the cooperative semantics the ucontext backend provides.
 */

#include <rex/platform.h>

#if REX_PLATFORM_ANDROID

#include <rex/thread/fiber.h>

#include <cassert>

namespace rex::thread {

thread_local Fiber* Fiber::tls_current_ = nullptr;

Fiber* Fiber::ConvertCurrentThread() {
  auto* f = new Fiber();
  f->is_thread_fiber_ = true;
  f->scheduler_ = new Scheduler();
  f->scheduler_->running = f;
  f->started_ = true;
  tls_current_ = f;
  return f;
}

Fiber* Fiber::Create(size_t stack_size, void (*entry)(void*), void* arg) {
  (void)stack_size;  // The host thread gets the platform default stack.
  Fiber* current = tls_current_;
  assert(current && "ConvertCurrentThread must run before Fiber::Create");
  if (!current) {
    return nullptr;
  }
  auto* f = new Fiber();
  f->entry_ = entry;
  f->arg_ = arg;
  f->scheduler_ = current->scheduler_;
  return f;
}

void Fiber::WaitUntilRunning() {
  std::unique_lock<std::mutex> lock(scheduler_->mutex);
  scheduler_->cv.wait(lock, [this] { return scheduler_->running == this; });
}

/*static*/ void Fiber::ThreadMain(Fiber* self) {
  self->WaitUntilRunning();
  tls_current_ = self;
  self->entry_(self->arg_);
  // A fiber entry that returns ends the host thread; the Windows and ucontext
  // backends treat this as undefined, so callers always switch away instead.
  self->finished_ = true;
}

void Fiber::SwitchTo(Fiber* target) {
  Fiber* from = tls_current_;
  assert(from && target && from->scheduler_ == target->scheduler_);
  if (from == target) {
    return;
  }
  Scheduler* sched = from->scheduler_;
  {
    std::lock_guard<std::mutex> lock(sched->mutex);
    sched->running = target;
    if (!target->started_) {
      target->started_ = true;
      target->thread_ = std::thread(&Fiber::ThreadMain, target);
    }
  }
  sched->cv.notify_all();
  from->WaitUntilRunning();
  tls_current_ = from;
}

void Fiber::Destroy() {
  if (is_thread_fiber_) {
    tls_current_ = nullptr;
    // The scheduler outlives created fibers only while their threads may still
    // touch it; those are joined in their own Destroy, so release it here.
    delete scheduler_;
    scheduler_ = nullptr;
  } else {
    assert(this != tls_current_ && "Destroy called on the currently running fiber");
    if (thread_.joinable()) {
      if (finished_) {
        thread_.join();
      } else {
        // The fiber is parked mid-entry and can never be resumed; leaking the
        // parked thread is the safe equivalent of freeing a suspended stack.
        thread_.detach();
      }
    }
  }
  delete this;
}

}  // namespace rex::thread

#endif  // REX_PLATFORM_ANDROID
