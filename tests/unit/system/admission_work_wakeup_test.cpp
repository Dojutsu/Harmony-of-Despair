#include <catch2/catch_test_macros.hpp>

#include <atomic>
#include <chrono>
#include <future>
#include <thread>

#include "system/xam/admission_work_wakeup.h"

namespace rex::system::xam::detail {
namespace {
using namespace std::chrono_literals;
constexpr auto kLongPoll = 3s;
constexpr auto kPrompt = 700ms;

// A real blocking operation barrier. Failed assertions cannot leave the worker
// indefinitely blocked: the operation has its own finite bound.
struct RpcBarrier {
  std::promise<void> entered;
  std::promise<void> release;
  std::shared_future<void> released = release.get_future().share();
  std::atomic<bool> timed_out{false};
  void Arrive() {
    entered.set_value();
    timed_out = released.wait_for(2s) != std::future_status::ready;
  }
};
}

TEST_CASE("admission work published before waiting cannot lose its notification",
          "[directory][admission-wakeup][race]") {
  AdmissionWorkWakeup work;
  const auto before_poll = work.Observe();
  work.Notify();  // Schedule/Bind has completed before the worker reaches wait.
  const auto start = std::chrono::steady_clock::now();
  CHECK(work.Wait({}, before_poll, kLongPoll));
  CHECK(std::chrono::steady_clock::now() - start < kPrompt);
  const auto consumed = work.Observe();
  CHECK_FALSE(work.Wait({}, consumed, 40ms));
}

TEST_CASE("schedule and bind wake an idle admission worker without poll latency",
          "[directory][admission-wakeup][thread]") {
  AdmissionWorkWakeup work;
  std::atomic<unsigned> polls{0};
  std::atomic<unsigned> scheduled{0};
  std::atomic<unsigned> consumed{0};
  std::atomic<bool> reported{false};
  std::promise<void> idle, applied;
  auto idle_future = idle.get_future();
  auto applied_future = applied.get_future();
  std::jthread worker([&](std::stop_token stop) {
    work.Run(stop, [&] {
      const auto pass = ++polls;
      if (pass == 1) idle.set_value();
      consumed = scheduled.load();
      if (consumed == 2 && !reported.exchange(true)) applied.set_value();
    }, [] { return true; }, kLongPoll);
  });
  REQUIRE(idle_future.wait_for(kPrompt) == std::future_status::ready);
  // Both Schedule and Bind publish work, whether they coalesce or arrive on
  // separate passes. Neither must wait for the full polling interval.
  scheduled = 1;
  work.Notify();
  scheduled = 2;
  work.Notify();
  REQUIRE(applied_future.wait_for(kPrompt) == std::future_status::ready);
  CHECK(consumed == 2);
  worker.request_stop();
  worker.join();
}

TEST_CASE("work scheduled during admission RPC is polled immediately after it returns",
          "[directory][admission-wakeup][race]") {
  AdmissionWorkWakeup work;
  RpcBarrier rpc;
  auto entered = rpc.entered.get_future();
  std::promise<void> next_pass;
  auto next = next_pass.get_future();
  std::atomic<unsigned> polls{0};
  std::jthread worker([&](std::stop_token stop) {
    work.Run(stop, [&] {
      const auto pass = ++polls;
      if (pass == 1) rpc.Arrive();
      if (pass == 2) next_pass.set_value();
    }, [] { return true; }, kLongPoll);
  });
  REQUIRE(entered.wait_for(kPrompt) == std::future_status::ready);
  work.Notify();
  rpc.release.set_value();
  REQUIRE(next.wait_for(kPrompt) == std::future_status::ready);
  CHECK_FALSE(rpc.timed_out);
  std::this_thread::sleep_for(60ms);
  CHECK(polls == 2);  // Consumed work does not make the wait predicate stay true.
  worker.request_stop();
  worker.join();
}

TEST_CASE("coalesced admission work and cancellation do not cause a busy loop",
          "[directory][admission-wakeup][race]") {
  AdmissionWorkWakeup work;
  RpcBarrier rpc;
  auto entered = rpc.entered.get_future();
  std::promise<void> cancellation_polled;
  auto cancelled = cancellation_polled.get_future();
  std::atomic<unsigned> polls{0};
  std::atomic<bool> cancellation{false};
  std::jthread worker([&](std::stop_token stop) {
    work.Run(stop, [&] {
      const auto pass = ++polls;
      if (pass == 1) rpc.Arrive();
      if (pass == 2 && cancellation) cancellation_polled.set_value();
    }, [] { return true; }, kLongPoll);
  });
  REQUIRE(entered.wait_for(kPrompt) == std::future_status::ready);
  for (unsigned i = 0; i < 1000; ++i) work.Notify();
  cancellation = true;
  work.Notify();
  rpc.release.set_value();
  REQUIRE(cancelled.wait_for(kPrompt) == std::future_status::ready);
  CHECK_FALSE(rpc.timed_out);
  std::this_thread::sleep_for(60ms);
  CHECK(polls == 2);
  worker.request_stop();
  worker.join();
}

TEST_CASE("admission shutdown interrupts long waits and performs final drain",
          "[directory][admission-wakeup][lifetime]") {
  AdmissionWorkWakeup work;
  std::atomic<unsigned> polls{0};
  std::promise<void> idle, finished;
  auto idle_future = idle.get_future();
  auto finished_future = finished.get_future();
  std::jthread worker([&](std::stop_token stop) {
    work.Run(stop, [&] {
      if (++polls == 1) idle.set_value();
    }, [&] { return polls >= 3; }, kLongPoll);
    finished.set_value();
  });
  REQUIRE(idle_future.wait_for(kPrompt) == std::future_status::ready);
  worker.request_stop();  // No explicit Notify is needed for stop-aware wait.
  REQUIRE(finished_future.wait_for(kPrompt) == std::future_status::ready);
  worker.join();
  CHECK(polls == 3);
}

TEST_CASE("periodic renewal polling is retained without an external notification",
          "[directory][admission-wakeup][timing]") {
  AdmissionWorkWakeup work;
  std::atomic<unsigned> polls{0};
  std::promise<std::chrono::steady_clock::time_point> renewed;
  auto renewal = renewed.get_future();
  const auto started = std::chrono::steady_clock::now();
  std::jthread worker([&](std::stop_token stop) {
    work.Run(stop, [&] {
      if (++polls == 3) renewed.set_value(std::chrono::steady_clock::now());
    }, [] { return true; }, 40ms);
  });
  REQUIRE(renewal.wait_for(kPrompt) == std::future_status::ready);
  CHECK(polls >= 3);
  CHECK(renewal.get() - started >= 60ms);
  worker.request_stop();
  worker.join();
}

TEST_CASE("already requested admission shutdown cannot sleep before draining",
          "[directory][admission-wakeup][lifetime]") {
  AdmissionWorkWakeup work;
  std::stop_source stop;
  stop.request_stop();
  unsigned polls = 0;
  const auto start = std::chrono::steady_clock::now();
  work.Run(stop.get_token(), [&] { ++polls; }, [&] { return polls == 2; }, kLongPoll);
  CHECK(polls == 2);
  CHECK(std::chrono::steady_clock::now() - start < kPrompt);
}
}  // namespace rex::system::xam::detail
