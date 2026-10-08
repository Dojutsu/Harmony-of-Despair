// Real POSIX condition-lock contention must not defeat a finite wait deadline.
#include <catch2/catch_test_macros.hpp>
#include <rex/thread.h>
#if REX_PLATFORM_LINUX
#include <pthread.h>
#include <time.h>
#include <memory>
#include <vector>
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

TEST_CASE("POSIX single waits expire while a condition lock is contended",
          "[thread][wait][timeout][single-wait-timeout]") {
  for (bool alertable : {false, true}) {
    for (auto timeout : {0ms, 20ms}) {
      DYNAMIC_SECTION("alertable=" << alertable << " timeout=" << timeout.count()) {
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
        const auto began = std::chrono::steady_clock::now();
        auto result = rex::thread::Wait(mutant.get(), alertable, timeout);
        const auto elapsed = std::chrono::steady_clock::now() - began;
        CHECK(result == rex::thread::WaitResult::kTimeout);
        CHECK(elapsed < 150ms);
        blocker.join();
        if (result == rex::thread::WaitResult::kSuccess) CHECK(mutant->Release());
        CHECK(rex::thread::Wait(mutant.get(), false, 0ms) == rex::thread::WaitResult::kSuccess);
        CHECK(mutant->Release());
      }
    }
  }
}

TEST_CASE("POSIX finite multiple waits sleep through fractional milliseconds",
          "[thread][wait][timeout][multiple-wait-idle-cpu]") {
  for (bool alertable : {false, true}) {
    for (bool wait_all : {false, true}) {
      DYNAMIC_SECTION("alertable=" << alertable << " all=" << wait_all) {
        // Nine real empty production semaphores match the audio worker's
        // alertable WaitAny slice. Measure executing thread CPU, not elapsed
        // wall time, so scheduler delays cannot be mistaken for busy work.
        std::vector<std::unique_ptr<rex::thread::Semaphore>> objects;
        rex::thread::WaitHandle* handles[9];
        for (size_t i = 0; i < 9; ++i) {
          objects.push_back(rex::thread::Semaphore::Create(0, 1));
          REQUIRE(objects.back());
          handles[i] = objects.back().get();
        }
        auto cpu_ns = [] {
          timespec sample{};
          REQUIRE(clock_gettime(CLOCK_THREAD_CPUTIME_ID, &sample) == 0);
          return uint64_t(sample.tv_sec) * 1000000000 + sample.tv_nsec;
        };
        const auto cpu_before = cpu_ns();
        const auto began = std::chrono::steady_clock::now();
        for (unsigned i = 0; i < 80; ++i) {
          CHECK(rex::thread::WaitMultiple(handles, 9, wait_all, alertable, 1ms).first ==
                rex::thread::WaitResult::kTimeout);
        }
        const auto cpu_elapsed_ns = cpu_ns() - cpu_before;
        const auto elapsed = std::chrono::steady_clock::now() - began;
        INFO("thread CPU ns=" << cpu_elapsed_ns);
        CHECK(elapsed >= 75ms);
        CHECK(cpu_elapsed_ns < 30000000);
        // Timed-out polls do not consume later signals; WaitAny keeps its
        // real index and WaitAll consumes only when every handle is ready.
        objects[4]->Release(1, nullptr);
        const auto ready = rex::thread::WaitMultiple(handles, 9, false, alertable, 0ms);
        CHECK(ready.first == rex::thread::WaitResult::kSuccess);
        CHECK(ready.second == 4);
        CHECK(rex::thread::WaitMultiple(handles, 9, false, alertable, 0ms).first ==
              rex::thread::WaitResult::kTimeout);
        for (auto& object : objects) object->Release(1, nullptr);
        CHECK(rex::thread::WaitMultiple(handles, 9, true, alertable, 10ms).first ==
              rex::thread::WaitResult::kSuccess);
        CHECK(rex::thread::WaitMultiple(handles, 9, false, alertable, 0ms).first ==
              rex::thread::WaitResult::kTimeout);
      }
    }
  }
}
#endif
