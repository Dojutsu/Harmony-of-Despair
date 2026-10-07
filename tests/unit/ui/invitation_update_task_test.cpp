#include <rex/ui/overlay/invitation_update_task.h>
#include <catch2/catch_test_macros.hpp>

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <future>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <thread>

using namespace std::chrono_literals;
using rex::ui::InvitationUpdateTask;

TEST_CASE("invitation task joins cancelled submission and discards its result",
          "[ui][runtime-invite][lifetime]") {
  std::promise<void> entered;
  auto entry = entered.get_future();
  std::atomic<bool> cancellation_observed = false;
  std::atomic<unsigned> calls = 0;
  InvitationUpdateTask task([&](std::string code, std::stop_token stop) {
    ++calls;
    CHECK(code == "ABC234");
    std::mutex mutex;
    std::condition_variable_any changed;
    std::unique_lock lock(mutex);
    entered.set_value();
    changed.wait(lock, stop, [] { return false; });
    cancellation_observed = stop.stop_requested();
    return std::string("stale successful submission");
  });
  REQUIRE(task.Submit("ABC234"));
  REQUIRE(entry.wait_for(2s) == std::future_status::ready);
  CHECK_FALSE(task.Submit("DEF567"));
  CHECK_FALSE(task.Poll());
  task.Close();
  CHECK(cancellation_observed.load());
  CHECK(calls.load() == 1);
  CHECK_FALSE(task.busy());
  CHECK_FALSE(task.Poll());
  CHECK_FALSE(task.Submit("DEF567"));
  task.Close();
}

TEST_CASE("invitation dialog destruction retains callback owner through join",
          "[ui][runtime-invite][lifetime]") {
  struct Owner { std::atomic<bool> returned = false; };
  auto owner = std::make_shared<Owner>();
  auto weak = std::weak_ptr<Owner>(owner);
  std::promise<void> entered;
  auto entry = entered.get_future();
  auto task = std::make_unique<InvitationUpdateTask>(
      [owner, &entered](std::string, std::stop_token stop) {
        std::mutex mutex;
        std::condition_variable_any changed;
        std::unique_lock lock(mutex);
        entered.set_value();
        changed.wait(lock, stop, [] { return false; });
        owner->returned = true;
        return std::string("cancelled");
      });
  REQUIRE(task->Submit("ABC234"));
  REQUIRE(entry.wait_for(2s) == std::future_status::ready);
  owner.reset();
  REQUIRE_FALSE(weak.expired());
  task.reset();
  CHECK(weak.expired());
}

TEST_CASE("invitation task publishes once and permits an explicit new submission",
          "[ui][runtime-invite]") {
  std::atomic<unsigned> calls = 0;
  std::promise<void> returned;
  auto completion = returned.get_future();
  InvitationUpdateTask task([&](std::string code, std::stop_token) {
    if (++calls == 1) returned.set_value();
    return code;
  });
  REQUIRE(task.Submit("ABC234"));
  REQUIRE(completion.wait_for(2s) == std::future_status::ready);
  std::optional<std::string> result;
  const auto deadline = std::chrono::steady_clock::now() + 2s;
  do { result = task.Poll(); std::this_thread::yield(); }
  while (!result && std::chrono::steady_clock::now() < deadline);
  REQUIRE(result);
  CHECK(*result == "ABC234");
  CHECK_FALSE(task.Poll());
  CHECK_FALSE(task.busy());
  REQUIRE(task.Submit("DEF567"));
  task.Close();
  CHECK(calls.load() == 2);
}

TEST_CASE("invitation task hides callback failure details",
          "[ui][runtime-invite]") {
  InvitationUpdateTask task([](std::string, std::stop_token) -> std::string {
    throw std::runtime_error("private capability must never appear in UI");
  });
  REQUIRE(task.Submit("ABC234"));
  std::optional<std::string> result;
  const auto deadline = std::chrono::steady_clock::now() + 2s;
  do { result = task.Poll(); std::this_thread::yield(); }
  while (!result && std::chrono::steady_clock::now() < deadline);
  REQUIRE(result);
  CHECK(*result == "Invitation unavailable.");
}

TEST_CASE("invitation task without a provider refuses submission",
          "[ui][runtime-invite]") {
  InvitationUpdateTask task({});
  CHECK_FALSE(task.Submit("ABC234"));
  CHECK_FALSE(task.busy());
  CHECK_FALSE(task.Poll());
}
