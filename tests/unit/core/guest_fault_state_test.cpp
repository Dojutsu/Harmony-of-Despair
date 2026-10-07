/** Normal-context ownership tests; hardware capture is covered by guest_fault_test. */
#include <rex/platform/guest_fault_state.h>
#include <rex/platform/guest_memory.h>
#include <rex/platform/exceptions.h>
#include <rex/platform/seh.h>

#include <algorithm>
#include <atomic>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <catch2/catch_test_macros.hpp>

#include <sys/wait.h>
#include <unistd.h>

namespace {
using namespace rex::guest;

CapturedFault FakeCapture(uint32_t intent = 0) {
  CapturedFault fault{};
  fault.signal_number = 11;
  fault.signal_code = 2;
  fault.access_intent = intent;
  fault.address = 0x12345000;
  fault.instruction_pointer = 0x789000;
  fault.stack_pointer = 0xabcd000;
  fault.integer_registers[2] = 0x44556677;
  fault.xmm_registers[3][7] = 0xcc;
  return fault;
}

struct Cleanup {
  explicit Cleanup(int& value) : count(value) {}
  int& count;
  ~Cleanup() { ++count; }
};

AccessResult<uint32_t> NonthrowingGateway(unsigned depth, int& cleanup) noexcept {
  GatewayScope gateway;
  Cleanup resource{cleanup};
  auto heap = std::make_unique<Cleanup>(cleanup);
  if (depth) return NonthrowingGateway(depth - 1, cleanup).Forward();
  return AccessResult<uint32_t>::Failure(ExecutionActivation::Current()->Publish(FakeCapture(1)));
}

struct RawContext {
  int cleanup = 0;
  FaultToken fault{};
  uint32_t output = 0xfeedface;
};
extern "C" void NonthrowingCallback(void* opaque) noexcept {
  auto& context = *static_cast<RawContext*>(opaque);
  GatewayScope gateway;
  Cleanup cleanup{context.cleanup};
  auto result = NonthrowingGateway(2, context.cleanup);
  if (result.Failed()) {
    context.fault = result.Fault();
    return;
  }
  context.output = result.Value();
}

struct ChildOutcome {
  int status;
  std::string diagnostic;
};
ChildOutcome RunViolation(const std::function<void()>& body) {
  int pipe_fds[2];
  if (pipe(pipe_fds)) return {-1, "pipe-failed"};
  const pid_t pid = fork();
  if (!pid) {
    close(pipe_fds[0]);
    if (dup2(pipe_fds[1], STDERR_FILENO) < 0) std::_Exit(99);
    close(pipe_fds[1]);
    alarm(5);
    body();
    std::_Exit(0);
  }
  close(pipe_fds[1]);
  if (pid < 0) {
    close(pipe_fds[0]);
    return {-1, "fork-failed"};
  }
  std::string diagnostic;
  char bytes[512];
  ssize_t count;
  while ((count = read(pipe_fds[0], bytes, sizeof(bytes))) > 0)
    diagnostic.append(bytes, static_cast<size_t>(count));
  close(pipe_fds[0]);
  int status;
  if (waitpid(pid, &status, 0) != pid) return {-1, "wait-failed"};
  return {status, std::move(diagnostic)};
}
void CheckViolation(const std::function<void()>& body, const char* reason) {
  const auto outcome = RunViolation(body);
  REQUIRE(outcome.status != -1);
  REQUIRE(WIFEXITED(outcome.status));
  CHECK(WEXITSTATUS(outcome.status) == kFaultContractFailureExitCode);
  CHECK(outcome.diagnostic.find("guest-fault-contract-failure") != std::string::npos);
  CHECK(outcome.diagnostic.find(reason) != std::string::npos);
  CHECK(outcome.diagnostic.find("terminate") == std::string::npos);
}

void TooDeep(unsigned depth) {
  GatewayScope scope;
  if (depth) TooDeep(depth - 1);
}
}  // namespace

TEST_CASE("Guest fault activation owns immutable record and consumes once", "[guest_fault][ownership]") {
  REQUIRE(ExecutionActivation::Current() == nullptr);
  ExecutionActivation activation;
  const auto capture = FakeCapture(1);
  const auto first = activation.Publish(capture);
  CHECK(first.activation_id() == activation.id());
  CHECK(first.sequence() == 1);
  CHECK(activation.HasPendingFault());
  CHECK(activation.PendingToken() == first);
  CHECK(activation.PendingFault().address == capture.address);
  CHECK(activation.PendingFault().integer_registers[2] == capture.integer_registers[2]);
  CHECK(activation.PendingFault().xmm_registers[3][7] == 0xcc);
  const auto consumed = activation.Consume(first);
  CHECK(consumed.access_intent == 1);
  CHECK_FALSE(activation.HasPendingFault());
  CHECK(activation.published_faults() == 1);
  CHECK(activation.consumed_faults() == 1);
  const auto second = activation.Publish(FakeCapture());
  CHECK(second.sequence() == 2);
  CHECK(second != first);
  activation.Consume(second);
}

TEST_CASE("Child guest activation handles its own fault and restores parent", "[guest_fault][ownership]") {
  ExecutionActivation parent;
  const auto parent_id = parent.id();
  {
    ExecutionActivation child;
    CHECK(child.id() != parent_id);
    auto result = AccessResult<uint32_t>::Failure(child.Publish(FakeCapture()));
    CHECK_THROWS_AS(ValueOrThrow(std::move(result)), rex::SehException);
    CHECK(child.consumed_faults() == 1);
  }
  CHECK(ExecutionActivation::Current() == &parent);
  CHECK_FALSE(parent.HasPendingFault());
  CHECK(parent.published_faults() == 0);
  CHECK(parent.consumed_faults() == 0);
}

TEST_CASE("Noexcept gateway returns fault with all cleanup intact", "[guest_fault][gateway]") {
  ExecutionActivation activation;
  int cleanup = 0;
  int outer_cleanup = 0;
  bool delivered = false;
  try {
    Cleanup outer{outer_cleanup};
    auto result = NonthrowingGateway(3, cleanup);
    CHECK(activation.gateway_depth() == 0);
    CHECK(cleanup == 8);  // one scope and one heap resource per gateway
    ValueOrThrow(std::move(result));
    FAIL("Expected guest fault delivery");
  } catch (const rex::SehException& exception) {
    delivered = true;
    CHECK(exception.code() == rex::SehException::ACCESS_VIOLATION);
    CHECK(exception.address() == FakeCapture().address);
  }
  CHECK(delivered);
  CHECK(outer_cleanup == 1);
  CHECK_FALSE(activation.HasPendingFault());
  CHECK(activation.published_faults() == 1);
  CHECK(activation.consumed_faults() == 1);
}

TEST_CASE("Raw callback conveys fault before output commit", "[guest_fault][gateway]") {
  ExecutionActivation activation;
  RawContext context;
  NonthrowingCallback(&context);
  CHECK(context.output == 0xfeedface);
  CHECK(context.cleanup == 7);
  CHECK(activation.gateway_depth() == 0);
  CHECK_THROWS_AS(DeliverFault(context.fault), rex::SehException);
  CHECK_FALSE(activation.HasPendingFault());
  CHECK(activation.consumed_faults() == 1);
}

TEST_CASE("Fault delivery retains read and write guest AV information", "[guest_fault][intent]") {
  ExecutionActivation activation;
  for (uint32_t intent : {0u, 1u}) {
    const auto fault = FakeCapture(intent);
    const auto token = activation.Publish(fault);
    CHECK_THROWS_AS(DeliverFault(token), rex::SehException);
    const auto& state = rex::platform::seh_thread_state();
    CHECK(state.code == rex::SehException::ACCESS_VIOLATION);
    CHECK(state.info[0] == intent);
    CHECK(state.info[1] == fault.address);
    CHECK_FALSE(activation.HasPendingFault());
  }
  CHECK(activation.published_faults() == 2);
  CHECK(activation.consumed_faults() == 2);
}

TEST_CASE("Tagged fault transport moves and forwards without losing ownership", "[guest_fault][ownership]") {
  static_assert(!std::is_copy_constructible_v<AccessResult<uint32_t>>);
  static_assert(std::is_nothrow_move_constructible_v<AccessResult<uint32_t>>);
  ExecutionActivation activation;
  auto original = AccessResult<uint32_t>::Failure(activation.Publish(FakeCapture()));
  auto moved = std::move(original);
  auto forwarded = moved.Forward<uint64_t>();
  CHECK(forwarded.Failed());
  CHECK_THROWS_AS(ValueOrThrow(std::move(forwarded)), rex::SehException);
  auto success = AccessResult<uint32_t>::Success(42);
  CHECK(success.IsSuccess());
  CHECK(ValueOrThrow(std::move(success)) == 42);
  CHECK(activation.consumed_faults() == 1);
}

TEST_CASE("Deferred adjudication changes phase and restores clean TLS", "[guest_fault][adjudication]") {
  ExecutionActivation activation;
  const auto capture = FakeCapture();
  {
    AdjudicationScope adjudication(capture);
    CHECK(activation.phase() == ActivationPhase::Adjudicating);
    CHECK(ExecutionActivation::Current() == &activation);
    CHECK_FALSE(activation.HasPendingFault());
  }
  CHECK(activation.phase() == ActivationPhase::Running);
  RequireAccess();
}

TEST_CASE("Guest fault activations and gateways stay isolated across threads", "[guest_fault][threads]") {
  std::atomic<unsigned> failures = 0;
  std::atomic<unsigned> completed = 0;
  std::mutex ids_mutex;
  std::vector<uint64_t> ids;
  std::vector<std::thread> threads;
  for (unsigned thread = 0; thread < 4; ++thread) {
    threads.emplace_back([&] {
      if (ExecutionActivation::Current()) ++failures;
      for (unsigned iteration = 0; iteration < 16; ++iteration) {
        ExecutionActivation activation;
        {
          std::lock_guard lock(ids_mutex);
          ids.push_back(activation.id());
        }
        RawContext context;
        NonthrowingCallback(&context);
        try {
          DeliverFault(context.fault);
          ++failures;
        } catch (const rex::SehException& exception) {
          if (exception.code() != rex::SehException::ACCESS_VIOLATION ||
              context.cleanup != 7 || context.output != 0xfeedface ||
              activation.HasPendingFault() || activation.gateway_depth() ||
              activation.consumed_faults() != 1)
            ++failures;
          ++completed;
        }
      }
      if (ExecutionActivation::Current()) ++failures;
    });
  }
  for (auto& thread : threads) thread.join();
  CHECK(failures.load() == 0);
  CHECK(completed.load() == 64);
  std::sort(ids.begin(), ids.end());
  CHECK(std::adjacent_find(ids.begin(), ids.end()) == ids.end());
  CHECK(ExecutionActivation::Current() == nullptr);
}

TEST_CASE("Fault ownership rejects invalid transport before continuation", "[guest_fault][contract]") {
  SECTION("No owner") {
    CheckViolation([] { RequireAccess(); }, "guest-access-without-activation");
  }
  SECTION("Pending overwrite") {
    CheckViolation([] {
      ExecutionActivation owner;
      owner.Publish(FakeCapture());
      owner.Publish(FakeCapture(1));
    }, "pending-fault-overwrite");
  }
  SECTION("Ignored result") {
    CheckViolation([] {
      ExecutionActivation owner;
      auto result = AccessResult<uint32_t>::Failure(owner.Publish(FakeCapture()));
    }, "ignored-fault-result");
  }
  SECTION("Acknowledged but unconsumed token") {
    CheckViolation([] {
      ExecutionActivation owner;
      auto result = AccessResult<uint32_t>::Failure(owner.Publish(FakeCapture()));
      result.Fault();
    }, "activation-left-with-pending-fault");
  }
  SECTION("Pending continuation") {
    CheckViolation([] {
      ExecutionActivation owner;
      owner.Publish(FakeCapture());
      RequireAccess();
    }, "guest-continuation-with-pending-fault");
  }
  SECTION("Duplicate consumption") {
    CheckViolation([] {
      ExecutionActivation owner;
      const auto token = owner.Publish(FakeCapture());
      owner.Consume(token);
      owner.Consume(token);
    }, "invalid-fault-token-or-thread");
  }
  SECTION("Stale token") {
    CheckViolation([] {
      ExecutionActivation owner;
      const auto old = owner.Publish(FakeCapture());
      owner.Consume(old);
      owner.Publish(FakeCapture(1));
      owner.Consume(old);
    }, "invalid-fault-token-or-thread");
  }
  SECTION("Cross-thread consume") {
    CheckViolation([] {
      ExecutionActivation owner;
      const auto token = owner.Publish(FakeCapture());
      std::thread other([&] { owner.Consume(token); });
      other.join();
    }, "wrong-activation-or-thread");
  }
  SECTION("Pending child activation") {
    CheckViolation([] {
      ExecutionActivation owner;
      owner.Publish(FakeCapture());
      ExecutionActivation child;
    }, "guest-continuation-with-pending-fault");
  }
  SECTION("Adjudication guest reentry") {
    CheckViolation([] {
      ExecutionActivation owner;
      const auto fault = FakeCapture();
      AdjudicationScope adjudication(fault);
      RequireAccess();
    }, "guest-access-during-adjudication");
  }
  SECTION("Nested adjudication") {
    CheckViolation([] {
      ExecutionActivation owner;
      const auto fault = FakeCapture();
      AdjudicationScope adjudication(fault);
      AdjudicationScope nested(fault);
    }, "guest-access-during-adjudication");
  }
  SECTION("Gateway consumer prohibited") {
    CheckViolation([] {
      ExecutionActivation owner;
      GatewayScope gateway;
      const auto token = owner.Publish(FakeCapture());
      DeliverFault(token);
    }, "consumption-inside-nonthrowing-gateway");
  }
  SECTION("Gateway depth bounded") {
    CheckViolation([] {
      ExecutionActivation owner;
      TooDeep(kMaximumGatewayDepth);
    }, "gateway-depth-overflow");
  }
  SECTION("Adjudication callback throws after starting") {
    CheckViolation([] {
      ExecutionActivation owner;
      const auto fault = FakeCapture();
      try {
        AdjudicationScope adjudication(fault);
        throw 7;
      } catch (...) {
      }
    }, "exception-during-deferred-adjudication");
  }
}

TEST_CASE("Normal memory consumers preserve nullable checked ownership", "[guest_fault][consumer]") {
  SECTION("No current owner establishes and releases a root") {
    REQUIRE(CurrentForAccessOrNull() == nullptr);
    {
      detail::MemoryConsumer consumer;
      auto* owner = CurrentForAccessOrNull();
      REQUIRE(owner != nullptr);
      CHECK(owner == ExecutionActivation::Current());
      uint32_t value = 42;
      CHECK(Read<uint32_t>(&value) == 42);
      CHECK(CurrentForAccessOrNull() == owner);
      CHECK(owner->published_faults() == 0);
    }
    CHECK(CurrentForAccessOrNull() == nullptr);
  }
  SECTION("Existing running owner stays identical across consumers") {
    ExecutionActivation owner;
    const auto id = owner.id();
    {
      detail::MemoryConsumer consumer;
      CHECK(CurrentForAccessOrNull() == &owner);
      CHECK(ExecutionActivation::Current()->id() == id);
      uint32_t value = 43;
      Write<uint32_t>(&value, 44);
      CHECK(Read<uint32_t>(&value) == 44);
    }
    CHECK(CurrentForAccessOrNull() == &owner);
    CHECK(owner.published_faults() == 0);
  }
  SECTION("Pending fault rejects before the normal consumer leaf") {
    CheckViolation([] {
      ExecutionActivation owner;
      owner.Publish(FakeCapture());
      (void)Read<uint32_t>(nullptr);
    }, "guest-continuation-with-pending-fault");
  }
  SECTION("Adjudication rejects before the normal consumer leaf") {
    CheckViolation([] {
      ExecutionActivation owner;
      auto fault = FakeCapture();
      AdjudicationScope adjudication(fault);
      (void)Read<uint32_t>(nullptr);
    }, "guest-access-during-adjudication");
  }
  SECTION("Pending owner refuses consumer construction before another effect") {
    CheckViolation([] {
      ExecutionActivation owner;
      owner.Publish(FakeCapture());
      detail::MemoryConsumer consumer;
      std::_Exit(0);
    }, "guest-continuation-with-pending-fault");
  }
  SECTION("Adjudication refuses consumer construction before another effect") {
    CheckViolation([] {
      ExecutionActivation owner;
      auto fault = FakeCapture();
      AdjudicationScope adjudication(fault);
      detail::MemoryConsumer consumer;
      std::_Exit(0);
    }, "guest-access-during-adjudication");
  }
  SECTION("Nullable accessor itself retains the same pending refusal") {
    CheckViolation([] {
      ExecutionActivation owner;
      owner.Publish(FakeCapture());
      (void)CurrentForAccessOrNull();
      std::_Exit(0);
    }, "guest-continuation-with-pending-fault");
  }
  SECTION("Fresh native thread establishes its own independent consumer") {
    ExecutionActivation parent;
    std::atomic<bool> good{false};
    std::thread child([&] {
      bool valid = CurrentForAccessOrNull() == nullptr;
      {
        detail::MemoryConsumer consumer;
        auto* owner = CurrentForAccessOrNull();
        valid = valid && owner && owner != &parent;
        uint32_t value = 45;
        valid = valid && Read<uint32_t>(&value) == 45;
      }
      good = valid && CurrentForAccessOrNull() == nullptr;
    });
    child.join();
    CHECK(good);
    CHECK(CurrentForAccessOrNull() == &parent);
  }
}
