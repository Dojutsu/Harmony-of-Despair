// Real POSIX condition-lock contention must not defeat a finite wait deadline.
#include <catch2/catch_test_macros.hpp>
#include <rex/thread.h>
#if REX_PLATFORM_LINUX
#include <pthread.h>
#include <chrono>
#include <future>
#include <thread>
using namespace std::chrono_literals;

TEST_CASE("POSIX multiple waits expire while a condition lock is contended",
          "[thread][wait][timeout]") {
  // Hold an actual production condition mutex long enough to distinguish its
  // release from the requested deadline, without leaving a hanging negative test.
  for (bool wait_all : {false, true}) {
    for (auto timeout : {0ms, 20ms}) {
      DYNAMIC_SECTION("all=" << wait_all << " timeout=" << timeout.count()) {
        auto ready = rex::thread::Event::CreateManualResetEvent(false);
        auto mutant = rex::thread::Mutant::Create(false);
        auto* native = static_cast<pthread_mutex_t*>(mutant->native_handle());
        std::promise<int> acquired;
        auto locked = acquired.get_future();
        std::jthread blocker([&] {
          int rc = pthread_mutex_lock(native);
          acquired.set_value(rc);
          if (rc == 0) {
            std::this_thread::sleep_for(250ms);
            pthread_mutex_unlock(native);
          }
        });
        REQUIRE(locked.get() == 0);
        rex::thread::WaitHandle* handles[] = {ready.get(), mutant.get()};
        const auto began = std::chrono::steady_clock::now();
        auto result = rex::thread::WaitMultiple(handles, 2, wait_all, false, timeout);
        const auto elapsed = std::chrono::steady_clock::now() - began;
        CHECK(result.first == rex::thread::WaitResult::kTimeout);
        CHECK(elapsed < 150ms);
        blocker.join();
        // The failed attempt must release partial locks and leave state intact.
        CHECK(rex::thread::Wait(ready.get(), false, 0ms) == rex::thread::WaitResult::kTimeout);
        ready->Set();
        auto success = rex::thread::WaitMultiple(handles, 2, wait_all, false, 0ms);
        CHECK(success.first == rex::thread::WaitResult::kSuccess);
        if (wait_all) CHECK(mutant->Release());
      }
    }
  }
}
#endif
