// Production Linux marshaling and raw-format paths use real protected memory.
#include <rex/hook.h>
#include <rex/platform/exceptions.h>
#include <rex/platform/guest_memory.h>
#include <rex/platform/seh.h>
#include <rex/system/format.h>
#include <rex/system/export_resolver.h>
#include <rex/system/function_dispatcher.h>

#include <catch2/catch_test_macros.hpp>

#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cerrno>
#include <cstring>
#include <new>

#include "test_memory.h"

namespace rex::kernel::crt {
rex::u32 CreateFiber_entry(rex::u32, rex::u32, ::mapped_void);
}

namespace {

struct GuardedArguments {
  size_t page = static_cast<size_t>(sysconf(_SC_PAGESIZE));
  uint8_t* base = static_cast<uint8_t*>(
      mmap(nullptr, page * 2, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
  GuardedArguments() {
    REQUIRE(base != MAP_FAILED);
    REQUIRE(mprotect(base + page, page, PROT_NONE) == 0);
    rex::initialize_seh();
  }
  ~GuardedArguments() { munmap(base, page * 2); }
};

int calls = 0;
int cleanups = 0;

uint32_t NineArguments(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
                       uint32_t, uint32_t, uint32_t) {
  ++calls;
  return 42;
}

void GuestNineArguments(PPCContext& context, uint8_t*) {
  ++calls;
  context.r3.u64 = 42;
}

uint32_t ReadWithCleanup(uint32_t* pointer) {
  struct Cleanup {
    ~Cleanup() { ++cleanups; }
  } cleanup;
  return rex::guest::Read<uint32_t>(pointer);
}

const void* dispatch_fault_address = nullptr;
void DispatchFault(PPCContext& context, uint8_t*) {
  context.r14.u64 = 0xBADC0DE;
  context.cr2.set_raw(0xF);
  rex::guest::Read<uint32_t>(dispatch_fault_address);
  ++calls;
}

}  // namespace

TEST_CASE("Linux typed HLE marshaling relays a ninth-argument read fault",
          "[linux][guest_fault][gateway]") {
  GuardedArguments memory;
  PPCContext context{};
  context.r1.u32 = static_cast<uint32_t>(memory.page) - 0x54;
  context.r3.u64 = 0x12345678;
  calls = 0;
  rex::guest::ExecutionActivation activation;
  CHECK_THROWS_AS(rex::ppc::HostToGuestFunction<&NineArguments>(context, memory.base),
                  rex::SehException);
  CHECK(calls == 0);
  CHECK(context.r3.u64 == 0x12345678);
  CHECK(activation.published_faults() == 1);
  CHECK(activation.consumed_faults() == 1);
  CHECK_FALSE(activation.HasPendingFault());
  CHECK(activation.gateway_depth() == 0);
  CHECK(rex::platform::seh_thread_state().code == rex::SehException::ACCESS_VIOLATION);
  CHECK(rex::platform::seh_thread_state().info[0] == 0);
  CHECK(rex::platform::seh_thread_state().info[1] ==
        reinterpret_cast<uintptr_t>(memory.base + memory.page));
}

TEST_CASE("Linux typed import marshaling relays a ninth-argument write fault",
          "[linux][guest_fault][gateway]") {
  GuardedArguments memory;
  PPCContext context{};
  context.r1.u32 = static_cast<uint32_t>(memory.page) - 0x54;
  calls = 0;
  rex::ppc::ImportFunction<uint32_t(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
                                   uint32_t, uint32_t, uint32_t, uint32_t)>
      import{GuestNineArguments};
  rex::guest::ExecutionActivation activation;
  CHECK_THROWS_AS(import(context, memory.base, 1, 2, 3, 4, 5, 6, 7, 8, 9), rex::SehException);
  CHECK(calls == 0);
  CHECK(context.r1.u32 == static_cast<uint32_t>(memory.page) - 0x54);
  CHECK(activation.published_faults() == 1);
  CHECK(activation.consumed_faults() == 1);
  CHECK_FALSE(activation.HasPendingFault());
  CHECK(activation.gateway_depth() == 0);
  CHECK(rex::platform::seh_thread_state().info[0] == 1);
}

TEST_CASE("Linux HLE body fault preserves normal C++ cleanup and return register",
          "[linux][guest_fault][gateway]") {
  GuardedArguments memory;
  PPCContext context{};
  context.r3.u64 = memory.page;
  cleanups = 0;
  rex::guest::ExecutionActivation activation;
  CHECK_THROWS_AS(rex::ppc::HostToGuestFunction<&ReadWithCleanup>(context, memory.base),
                  rex::SehException);
  CHECK(cleanups == 1);
  CHECK(context.r3.u64 == memory.page);
  CHECK(activation.published_faults() == 1);
  CHECK(activation.consumed_faults() == 1);
  CHECK_FALSE(activation.HasPendingFault());
}

TEST_CASE("Linux checked stack marshaling preserves slot spacing and endian values",
          "[linux][guest_fault][gateway]") {
  GuardedArguments memory;
  PPCContext context{};
  context.r1.u32 = 128;
  rex::guest::ExecutionActivation activation;
  auto write = rex::ppc::ArgTranslator::TrySetIntegerArgumentValue(context, memory.base, 10,
                                                                 0xA1B2C3D4);
  REQUIRE(write.IsSuccess());
  auto value = rex::ppc::ArgTranslator::TryGetIntegerArgumentValue(context, memory.base, 10);
  REQUIRE(value.IsSuccess());
  CHECK(value.Value() == 0xA1B2C3D4);
  auto* bytes = memory.base + 128 + 0x54 + 16;
  CHECK(bytes[0] == 0xA1);
  CHECK(bytes[1] == 0xB2);
  CHECK(bytes[2] == 0xC3);
  CHECK(bytes[3] == 0xD4);
  CHECK(activation.published_faults() == 0);
  CHECK_FALSE(activation.HasPendingFault());
}

TEST_CASE("Linux dispatcher restores thread binding, LR and stack after a guest fault",
          "[linux][guest_fault][gateway][dispatcher]") {
  GuardedArguments guard;
  auto& memory = rex::testing::GetTestMemory();
  rex::runtime::ExportResolver exports;
  rex::runtime::FunctionDispatcher dispatcher(&memory, &exports);
  constexpr uint32_t code = 0x86A00000;
  REQUIRE(dispatcher.InitializeFunctionTable(code, 0x10000, code, 0x100000, code + 0x100000));
  REQUIRE(dispatcher.SetFunction(code + 0x40, &DispatchFault));
  rex::runtime::ThreadState thread(93, 0x70000000, 0x60000000, &memory);
  auto* context = thread.context();
  context->lr = 0x12345678;
  uint64_t stack = context->r1.u64;
  auto* previous = rex::runtime::ThreadState::Get();
  dispatch_fault_address = guard.base + guard.page;
  calls = 0;
  uint64_t args[] = {7};
  CHECK_THROWS_AS(dispatcher.Execute(&thread, code + 0x40, args, 1), rex::SehException);
  CHECK(calls == 0);
  CHECK(context->r1.u64 == stack);
  CHECK(context->lr == 0x12345678);
  CHECK(rex::runtime::ThreadState::Get() == previous);
  CHECK(rex::guest::ExecutionActivation::Current() == nullptr);
}

TEST_CASE("Linux trap dispatcher restores the interrupted context on fault delivery",
          "[linux][guest_fault][gateway][dispatcher]") {
  GuardedArguments guard;
  auto& memory = rex::testing::GetTestMemory();
  rex::runtime::ExportResolver exports;
  rex::runtime::FunctionDispatcher dispatcher(&memory, &exports);
  constexpr uint32_t code = 0x86C00000;
  REQUIRE(dispatcher.InitializeFunctionTable(code, 0x10000, code, 0x100000, code + 0x100000));
  REQUIRE(dispatcher.SetFunction(code + 0x40, &DispatchFault));
  rex::runtime::ThreadState thread(94, 0x70000000, 0x60000000, &memory);
  auto* context = thread.context();
  context->r14.u64 = 0x14141414;
  context->cr2.set_raw(2);
  context->r3.u64 = 0x51515151;
  context->lr = 0xABCD;
  uint64_t stack = context->r1.u64;
  auto* previous = rex::runtime::ThreadState::Get();
  dispatch_fault_address = guard.base + guard.page;
  calls = 0;
  uint64_t args[] = {7};
  CHECK_THROWS_AS(dispatcher.ExecuteTrap(&thread, code + 0x40, args, 1), rex::SehException);
  CHECK(calls == 0);
  CHECK(context->r14.u64 == 0x14141414);
  CHECK(context->cr2.raw() == 2);
  CHECK(context->r3.u64 == 0x51515151);
  CHECK(context->r1.u64 == stack);
  CHECK(context->lr == 0xABCD);
  CHECK(rex::runtime::ThreadState::Get() == previous);
  CHECK(rex::guest::ExecutionActivation::Current() == nullptr);
}

TEST_CASE("Linux checked register and precision translators reject missing or pending owner",
          "[linux][guest_fault][gateway][translator-admission]") {
  REQUIRE(rex::guest::ExecutionActivation::Current() == nullptr);
  // Exercise each public Try* entry directly, not only the already-guarded
  // recursive gateways. Shared memory proves no register/output commit occurs
  // before refusal. Children must return the controlled diagnostic, not abort.
  for (bool pending : {false, true}) {
    for (unsigned operation = 0; operation != 4; ++operation) {
      CAPTURE(pending, operation);
      SharedTranslatorFixture fixture;
      int diagnostic[2];
      REQUIRE(pipe(diagnostic) == 0);
      const auto child = fork();
      REQUIRE(child >= 0);
      if (!child) {
        close(diagnostic[0]);
        if (dup2(diagnostic[1], STDERR_FILENO) < 0) _exit(92);
        close(diagnostic[1]);
        alarm(3);
        std::optional<rex::guest::ExecutionActivation> activation;
        if (pending) {
          activation.emplace();
          (void)activation->Publish(rex::guest::CapturedFault{});
        }
        auto& context = fixture.state->context;
        switch (operation) {
          case 0: {
            auto result = rex::ppc::ArgTranslator::TryGetIntegerArgumentValue(context, nullptr, 0);
            (void)result;
            break;
          }
          case 1: {
            auto result = rex::ppc::ArgTranslator::TrySetIntegerArgumentValue(
                context, nullptr, 0, 0xFEDCBA98);
            (void)result;
            break;
          }
          case 2: {
            auto result = rex::ppc::ArgTranslator::TryGetValue(
                context, nullptr, 0, fixture.state->output);
            (void)result;
            break;
          }
          default: {
            auto result = rex::ppc::ArgTranslator::TrySetValue(context, nullptr, 0, 8.5);
            (void)result;
            break;
          }
        }
        _exit(93);  // A return here would mean an unchecked continuation.
      }
      close(diagnostic[1]);
      int status = 0;
      pid_t waited;
      do { waited = waitpid(child, &status, 0); } while (waited < 0 && errno == EINTR);
      char message[2048]{};
      ssize_t length;
      do { length = read(diagnostic[0], message, sizeof(message)-1); }
      while (length < 0 && errno == EINTR);
      close(diagnostic[0]);
      REQUIRE(waited == child);
      REQUIRE(WIFEXITED(status));
      CHECK(WEXITSTATUS(status) == rex::guest::kFaultContractFailureExitCode);
      REQUIRE(length > 0);
      CHECK(std::strstr(message, pending ? "guest-continuation-with-pending-fault"
                                        : "guest-access-without-activation") != nullptr);
      CHECK(fixture.state->context.r3.u64 == 0x12345678);
      CHECK(fixture.state->context.f1.f64 == 4.5);
      CHECK(fixture.state->output == 9.25);
    }
  }
}
