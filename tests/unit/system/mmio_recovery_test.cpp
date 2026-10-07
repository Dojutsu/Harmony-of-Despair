/**
 * Normal-context Linux MMIO/write-watch recovery acceptance.
 * Synthetic captured contexts below test the adjudication API, not signal
 * delivery; registered-leaf physical-watch cases exercise the real signal path.
 */
#include <catch2/catch_test_macros.hpp>

#include <rex/platform.h>
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
#include <rex/exception_handler.h>
#include <rex/memory.h>
#include <rex/platform/guest_fault_state.h>
#include <rex/platform/guest_memory.h>
#include <rex/system/mmio_handler.h>
#include <rex/system/thread_state.h>
#include <rex/types.h>

#include <array>
#include <atomic>
#include <barrier>
#include <cstring>
#include <thread>
#include <cerrno>
#include <cstdlib>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdexcept>

#include "test_memory.h"

namespace {
using Handler = rex::runtime::MMIOHandler;
using Recovery = Handler::DeferredRecovery;
using Kind = Handler::DeferredAccessKind;
using Phase = Handler::DeferredTransaction::Phase;
constexpr uint32_t kDeviceAddress = 0x7F123000;
constexpr uint8_t kReadInstruction[] = {0x8B, 0x17, 0xC3};  // mov (%rdi), %edx
constexpr uint8_t kWriteInstruction[] = {0x89, 0x37, 0xC3}; // mov %esi, (%rdi)

struct Device {
  uint32_t reads = 0;
  uint32_t writes = 0;
  uint32_t last_write = 0;
  std::array<uint32_t, 8> addresses{};
  bool callbacks_in_normal_phase = true;
  bool throw_after_write = false;
  bool reject_callback = false;
  void Reset() { *this = {}; }
  void CheckOwner() {
    const auto* activation = rex::guest::ExecutionActivation::Current();
    callbacks_in_normal_phase &= activation &&
        activation->phase() == rex::guest::ActivationPhase::Adjudicating;
  }
};
uint32_t ReadDevice(void*, void* context, uint32_t address) {
  auto& device = *static_cast<Device*>(context);
  device.CheckOwner();
  if (device.reject_callback) _exit(93);
  device.addresses[device.reads % device.addresses.size()] = address;
  return 0x11223340 + ++device.reads;  // A read has an observable side effect.
}
void WriteDevice(void*, void* context, uint32_t address, uint32_t value) {
  auto& device = *static_cast<Device*>(context);
  device.CheckOwner();
  if (device.reject_callback) _exit(93);
  device.addresses[device.writes % device.addresses.size()] = address;
  ++device.writes;
  device.last_write = value;
  if (device.throw_after_write) throw std::runtime_error("indeterminate device completion");
}
Device& GetDevice() {
  // A registered range retains its context for the runtime's entire lifetime.
  // No callback points to a test's expired stack object.
  static Device device;
  static const bool registered = [] {
    (void)rex::testing::GetTestMemory();
    return Handler::global_handler()->RegisterRange(kDeviceAddress, 0xFFFFF000, 4096,
                                                    &device, ReadDevice, WriteDevice);
  }();
  REQUIRE(registered);
  device.Reset();
  return device;
}
struct NormalFault {
  rex::arch::HostThreadContext context{};
  rex::arch::Exception exception;
  rex::guest::CapturedFault captured{};
  NormalFault(bool write, uint32_t address = kDeviceAddress, uint32_t value = 0) {
    auto& memory = rex::testing::GetTestMemory();
    auto* pointer = memory.TranslateVirtual<uint8_t*>(address);
    context.rip = reinterpret_cast<uintptr_t>(write ? kWriteInstruction : kReadInstruction);
    context.rdi = reinterpret_cast<uintptr_t>(pointer);
    context.rsi = value;
    context.rdx = 0xCAFEBABE;
    exception.InitializeAccessViolation(&context, reinterpret_cast<uintptr_t>(pointer),
        write ? rex::arch::Exception::AccessViolationOperation::kWrite
              : rex::arch::Exception::AccessViolationOperation::kRead);
  }
};
Recovery Resolve(NormalFault& fault, Kind kind, Handler::DeferredTransaction& transaction) {
  rex::guest::AdjudicationScope scope(fault.captured);
  return Handler::global_handler()->ResolveAccessFault(fault.exception, kind, transaction);
}
struct PhysicalWatch {
  uint32_t expected_physical = 0;
  std::atomic<uint32_t> notifications{0};
  std::atomic<uint32_t> incorrect_phase{0};
  std::atomic<uint32_t> incorrect_range{0};
};
std::pair<uint32_t, uint32_t> InvalidatePhysical(void* context, uint32_t start,
                                              uint32_t length, bool exact) {
  auto& watch = *static_cast<PhysicalWatch*>(context);
  const auto* activation = rex::guest::ExecutionActivation::Current();
  if (!activation || activation->phase() != rex::guest::ActivationPhase::Adjudicating)
    ++watch.incorrect_phase;
  if (!(start <= watch.expected_physical && watch.expected_physical < start + length) || exact)
    ++watch.incorrect_range;
  ++watch.notifications;
  return {start, length};
}
struct PhysicalRegistration {
  rex::memory::Memory& memory;
  void* handle;
  ~PhysicalRegistration() { memory.UnregisterPhysicalMemoryInvalidationCallback(handle); }
};
struct PhysicalAllocation {
  rex::memory::BaseHeap* heap;
  uint32_t address = 0;
  ~PhysicalAllocation() { if (address) heap->Release(address); }
};
Recovery ResolveCaptured(const rex::guest::CapturedFault& fault, Kind kind,
                         Handler::DeferredTransaction& transaction) {
  rex::arch::HostThreadContext context{};
  context.rip = fault.instruction_pointer;
  for (unsigned index = 0; index < 16; ++index)
    context.int_registers[index] = fault.integer_registers[index];
  rex::arch::Exception exception;
  exception.InitializeAccessViolation(&context, fault.address,
      fault.access_intent == 1 ? rex::arch::Exception::AccessViolationOperation::kWrite
                               : rex::arch::Exception::AccessViolationOperation::kRead);
  const auto pc = context.rip;
  rex::guest::AdjudicationScope scope(fault);
  auto result = Handler::global_handler()->ResolveAccessFault(exception, kind, transaction);
  if (result == Recovery::kRetry) {
    CHECK(context.rip == pc);
    CHECK(exception.modified_int_registers() == 0);
  }
  return result;
}
}  // namespace

TEST_CASE("Linux deferred MMIO read completes once and synthesizes result",
          "[linux][guest-fault][mmio]") {
  auto& device = GetDevice();
  rex::guest::ExecutionActivation owner;
  NormalFault fault(false);
  const auto pc = fault.context.rip;
  Handler::DeferredTransaction transaction;
  REQUIRE(Resolve(fault, Kind::kScalar32, transaction) == Recovery::kCompleted);
  CHECK(transaction.phase() == Phase::kCompleted);
  CHECK(device.reads == 1);
  CHECK(device.writes == 0);
  CHECK(device.callbacks_in_normal_phase);
  CHECK(fault.context.rdx == rex::byte_swap(uint32_t(0x11223341)));
  CHECK(fault.context.rip == pc + 2);
  CHECK_FALSE(transaction.BeginRetry());
  CHECK_FALSE(transaction.CompleteNative());
  CHECK(Resolve(fault, Kind::kScalar32, transaction) == Recovery::kUnsupported);
  CHECK(transaction.phase() == Phase::kCompleted);
  CHECK(device.reads == 1);
  CHECK_FALSE(owner.HasPendingFault());
  CHECK(owner.phase() == rex::guest::ActivationPhase::Running);
}

TEST_CASE("Linux deferred MMIO write commits once without retry",
          "[linux][guest-fault][mmio]") {
  auto& device = GetDevice();
  rex::guest::ExecutionActivation owner;
  NormalFault fault(true, kDeviceAddress, rex::byte_swap(uint32_t(0xAABBCCDD)));
  const auto pc = fault.context.rip;
  Handler::DeferredTransaction transaction;
  REQUIRE(Resolve(fault, Kind::kScalar32, transaction) == Recovery::kCompleted);
  CHECK(device.writes == 1);
  CHECK(device.last_write == 0xAABBCCDD);
  CHECK(device.callbacks_in_normal_phase);
  CHECK(fault.context.rip == pc + 2);
  CHECK_FALSE(transaction.BeginRetry());
  CHECK_FALSE(transaction.CompleteNative());
  CHECK(Resolve(fault, Kind::kScalar32, transaction) == Recovery::kUnsupported);
  CHECK(device.writes == 1);
  CHECK_FALSE(owner.HasPendingFault());
}

TEST_CASE("Linux rejects unsupported mapped MMIO before callback or decoder",
          "[linux][guest-fault][mmio]") {
  auto& device = GetDevice();
  rex::guest::ExecutionActivation owner;
  for (auto kind : {Kind::kScalarRam, Kind::kVector128, Kind::kAtomic, Kind::kForwardBulk}) {
    NormalFault fault(true);
    Handler::DeferredTransaction transaction;
    const auto pc = fault.context.rip;
    CHECK(Resolve(fault, kind, transaction) == Recovery::kUnsupported);
    CHECK(transaction.phase() == Phase::kUnsupported);
    CHECK(fault.context.rip == pc);
    CHECK_FALSE(transaction.BeginRetry());
  }
  // Even a scalar class must be a decodable supported instruction. An unknown
  // PC does not enter the legacy decoder's assert or issue a device effect.
  constexpr uint8_t unsupported[] = {0x0F, 0x0B};
  NormalFault fault(true);
  fault.context.rip = reinterpret_cast<uintptr_t>(unsupported);
  Handler::DeferredTransaction transaction;
  CHECK(Resolve(fault, Kind::kScalar32, transaction) == Recovery::kUnsupported);
  CHECK(device.reads == 0);
  CHECK(device.writes == 0);
  CHECK_FALSE(owner.HasPendingFault());
  Handler::DeferredTransaction illegal_transaction;
  fault.exception.InitializeIllegalInstruction(&fault.context);
  CHECK(Resolve(fault, Kind::kScalar32, illegal_transaction) == Recovery::kUnsupported);
  CHECK(illegal_transaction.phase() == Phase::kUnsupported);
  CHECK(device.reads == 0);
  CHECK(device.writes == 0);
}

TEST_CASE("Linux poisons ambiguous MMIO callback completion without replay",
          "[linux][guest-fault][mmio]") {
  auto& device = GetDevice();
  device.throw_after_write = true;
  rex::guest::ExecutionActivation owner;
  NormalFault fault(true, kDeviceAddress, 0);
  Handler::DeferredTransaction transaction;
  CHECK(Resolve(fault, Kind::kScalar32, transaction) == Recovery::kUnsupported);
  CHECK(transaction.phase() == Phase::kPoisoned);
  CHECK(device.writes == 1);
  CHECK_FALSE(transaction.BeginRetry());
  CHECK_FALSE(transaction.CompleteNative());
  CHECK(Resolve(fault, Kind::kScalar32, transaction) == Recovery::kUnsupported);
  CHECK(device.writes == 1);
  CHECK(owner.phase() == rex::guest::ActivationPhase::Running);
}

TEST_CASE("Linux preserves ordered 32-bit MMIO suboperations",
          "[linux][guest-fault][mmio]") {
  auto& device = GetDevice();
  rex::guest::ExecutionActivation owner;
  rex::guest::CapturedFault captured{};
  uint32_t first = 0, second = 0;
  Handler::DeferredTransaction first_read, second_read, first_write, second_write;
  {
    rex::guest::AdjudicationScope scope(captured);
    REQUIRE(Handler::global_handler()->CheckLoad(kDeviceAddress, &first));
    REQUIRE(first_read.CompleteExplicit());
    CHECK_FALSE(first_read.CompleteExplicit());
    REQUIRE(Handler::global_handler()->CheckLoad(kDeviceAddress + 4, &second));
    REQUIRE(second_read.CompleteExplicit());
    REQUIRE(Handler::global_handler()->CheckStore(kDeviceAddress, 0xAABBCCDD));
    REQUIRE(first_write.CompleteExplicit());
    REQUIRE(Handler::global_handler()->CheckStore(kDeviceAddress + 4, 0x11223344));
    REQUIRE(second_write.CompleteExplicit());
    CHECK_FALSE(second_write.CompleteExplicit());
  }
  CHECK(first == 0x11223341);
  CHECK(second == 0x11223342);
  CHECK(device.reads == 2);
  CHECK(device.writes == 2);
  CHECK(device.addresses[0] == kDeviceAddress);
  CHECK(device.addresses[1] == kDeviceAddress + 4);
  CHECK(device.last_write == 0x11223344);
  CHECK(device.callbacks_in_normal_phase);
  CHECK_FALSE(owner.HasPendingFault());
}
TEST_CASE("Linux mapped interval admission preserves mask semantics and interior matches",
          "[linux][guest-fault][mmio]") {
  auto& device = GetDevice();
  auto& memory = rex::testing::GetTestMemory();
  auto* handler = Handler::global_handler();
  uint32_t translated = 0;
  CHECK(handler->IsMappedAddress(memory.TranslateVirtual<uint8_t*>(kDeviceAddress), &translated));
  CHECK(translated == kDeviceAddress);
  CHECK(handler->IsMappedRange(memory.TranslateVirtual<uint8_t*>(kDeviceAddress - 16), 32));
  CHECK_FALSE(handler->IsMappedRange(memory.TranslateVirtual<uint8_t*>(kDeviceAddress - 16), 16));
  CHECK_FALSE(handler->IsMappedRange(memory.TranslateVirtual<uint8_t*>(kDeviceAddress), 0));
  // Distinct high prefixes keep these metadata-only test ranges independent.
  // size=1 intentionally tests the original mask matching, which is not a
  // size-bounded interval. Each interval oracle checks every contained word.
  constexpr uint32_t masks[] = {0, 1, 2, 3, 0x55, 0xAA, 0x80, 0xFE, 0xFF};
  constexpr uint32_t points[] = {0, 1, 2, 3, 7, 8, 15, 16, 31, 32, 63, 64,
                                127, 128, 129, 254, 255};
  uint32_t test_index = 0;
  for (uint32_t low_mask : masks) {
    for (uint32_t low_pattern : {uint32_t(0), low_mask, low_mask & 0x5A}) {
      const uint32_t prefix = 0x6F000000 + (++test_index << 12);
      const uint32_t mask = 0xFFFFFF00 | low_mask;
      const uint32_t pattern = prefix | low_pattern;
      REQUIRE(handler->RegisterRange(pattern, mask, 1, &device, ReadDevice, WriteDevice));
      for (uint32_t first : points) {
        for (uint32_t last : points) {
          if (last < first) continue;
          bool expected = false;
          for (uint32_t word = first; word <= last; ++word)
            expected |= ((prefix + word) & mask) == pattern;
          CAPTURE(low_mask, low_pattern, first, last);
          CHECK(handler->IsMappedRange(memory.TranslateVirtual<uint8_t*>(prefix + first),
                                       last - first + 1) == expected);
        }
      }
    }
  }
  // RAM intervals have a fixed high prefix conflicting with every device.
  // This must remain false for all generated scalar/vector widths and bulk.
  for (size_t width : {size_t(1), size_t(2), size_t(4), size_t(8), size_t(16),
                       size_t(128), size_t(4096), size_t(65536)}) {
    CHECK_FALSE(handler->IsMappedRange(memory.TranslateVirtual<uint8_t*>(0x40001000), width));
  }
  // Sparse fixed bits below the common prefix must keep the general matching
  // path. Query actual metadata against an independent contained-byte oracle.
  uint32_t sparse_index = 0;
  for (uint32_t low_mask : {0xA5A5u, 0x55555u, 0x80000u, 0xFFFFFu}) {
    for (uint32_t low_pattern : {0u, low_mask, low_mask & 0x15555u}) {
      const uint32_t prefix = 0x6D000000 + (++sparse_index << 20);
      const uint32_t mask = 0xFFF00000 | low_mask;
      const uint32_t pattern = prefix | low_pattern;
      REQUIRE(handler->RegisterRange(pattern, mask, 0, &device, ReadDevice, WriteDevice));
      for (uint32_t first : {0u, 1u, 15u, 255u, 256u, 0xFFFFu, 0x10000u,
                             0x55554u, 0x7FFFFu, 0x80000u, 0xFFFFEu}) {
        for (uint32_t width : {1u, 2u, 4u, 16u, 128u, 256u}) {
          bool expected = false;
          for (uint32_t offset = 0; offset < width; ++offset)
            expected |= ((prefix + first + offset) & mask) == pattern;
          CAPTURE(low_mask, low_pattern, first, width);
          CHECK(handler->IsMappedRange(memory.TranslateVirtual<uint8_t*>(prefix + first), width) == expected);
        }
      }
    }
  }
  // Differing endpoints can cover all32 bits. The prefix check must not shift
  // a uint32 by32 or suppress an interior device match. These reads are metadata
  // only, including the protected guest zero page.
  CHECK(handler->IsMappedRange(memory.TranslateVirtual<uint8_t*>(0), size_t(1) << 32));
  CHECK_FALSE(handler->IsMappedRange(memory.physical_membase(), 4096));
  CHECK(device.reads == 0);
  CHECK(device.writes == 0);
}

TEST_CASE("Linux real PhysicalHeap write watch defers notification and retries once",
          "[linux][guest-fault][mmio][physical-watch]") {
  {
  auto& memory = rex::testing::GetTestMemory();
  auto* heap = memory.LookupHeapByType(true, 4096);
  REQUIRE(heap != nullptr);
  PhysicalAllocation allocation{heap};
  REQUIRE(heap->Alloc(4096, 4096,
      rex::memory::kMemoryAllocationReserve | rex::memory::kMemoryAllocationCommit,
      rex::memory::kMemoryProtectRead | rex::memory::kMemoryProtectWrite,
      false, &allocation.address));
  auto* pointer = memory.TranslateVirtual<uint32_t*>(allocation.address);
  *pointer = 0;
  PhysicalWatch watch;
  watch.expected_physical = memory.GetPhysicalAddress(allocation.address);
  REQUIRE(watch.expected_physical != UINT32_MAX);
  PhysicalRegistration registration{memory,
      memory.RegisterPhysicalMemoryInvalidationCallback(InvalidatePhysical, &watch)};
  rex::guest::ExecutionActivation activation;
  for (uint32_t epoch = 1; epoch <= 32; ++epoch) {
    CAPTURE(epoch);
    const auto before = watch.notifications.load();
    memory.EnablePhysicalMemoryAccessCallbacks(watch.expected_physical, 4096, true, false);
    rex::memory::PageAccess access = rex::memory::PageAccess::kNoAccess;
    size_t length = rex::memory::page_size();
    REQUIRE(rex::memory::QueryProtect(pointer, length, access));
    REQUIRE(access == rex::memory::PageAccess::kReadOnly);
    rex::guest::RequireAccess();
    auto attempt = rex::guest::CaptureWrite(pointer, &epoch, sizeof(epoch));
    REQUIRE_FALSE(attempt.success);
    CHECK(attempt.fault.access_intent == 1);
    CHECK(attempt.fault.address == reinterpret_cast<uintptr_t>(pointer));
    CHECK(watch.notifications == before);  // No callback in signal context.
    CHECK_FALSE(rex::guest::HasArmedAccessFrame());
    Handler::DeferredTransaction transaction;
    REQUIRE(ResolveCaptured(attempt.fault, Kind::kScalar32, transaction) == Recovery::kRetry);
    CHECK(transaction.phase() == Phase::kRetryReady);
    CHECK(watch.notifications == before + 1);
    REQUIRE(rex::memory::QueryProtect(pointer, length, access));
    CHECK(access == rex::memory::PageAccess::kReadWrite);
    REQUIRE(transaction.BeginRetry());
    rex::guest::RequireAccess();
    REQUIRE(rex::guest::CaptureWrite(pointer, &epoch, sizeof(epoch)).success);
    REQUIRE(transaction.CompleteNative());
    CHECK_FALSE(transaction.CompleteNative());
    CHECK(transaction.phase() == Phase::kCompleted);
    CHECK_FALSE(transaction.BeginRetry());
    CHECK(*pointer == epoch);
    CHECK(watch.notifications == before + 1);
    auto lock = rex::thread::global_critical_region::AcquireDirect();
    CHECK_FALSE(memory.TriggerPhysicalMemoryCallbacks(std::move(lock), allocation.address,
                                                      1, true, true));
    CHECK_FALSE(activation.HasPendingFault());
    CHECK(activation.phase() == rex::guest::ActivationPhase::Running);
  }
  CHECK(watch.notifications == 32);
  CHECK(watch.incorrect_phase == 0);
  CHECK(watch.incorrect_range == 0);
  }
  {
  auto& memory = rex::testing::GetTestMemory();
  auto* heap = memory.LookupHeapByType(true, 4096);
  REQUIRE(heap != nullptr);
  PhysicalAllocation allocation{heap};
  REQUIRE(heap->Alloc(4096, 4096,
      rex::memory::kMemoryAllocationReserve | rex::memory::kMemoryAllocationCommit,
      rex::memory::kMemoryProtectRead | rex::memory::kMemoryProtectWrite,
      false, &allocation.address));
  auto* pointer = memory.TranslateVirtual<uint32_t*>(allocation.address);
  pointer[0] = pointer[1] = 0;
  PhysicalWatch watch;
  watch.expected_physical = memory.GetPhysicalAddress(allocation.address);
  PhysicalRegistration registration{memory,
      memory.RegisterPhysicalMemoryInvalidationCallback(InvalidatePhysical, &watch)};
  memory.EnablePhysicalMemoryAccessCallbacks(watch.expected_physical, 4096, true, false);
  std::barrier captured(2);
  std::atomic<uint32_t> successful{0}, incorrect{0};
  auto worker = [&](uint32_t word) {
    rex::guest::ExecutionActivation activation;
    const uint32_t value = 0xABC00000 + word;
    rex::guest::RequireAccess();
    auto attempt = rex::guest::CaptureWrite(pointer + word, &value, sizeof(value));
    if (attempt.success || attempt.fault.access_intent != 1) ++incorrect;
    captured.arrive_and_wait();  // Both captures precede either adjudication.
    Handler::DeferredTransaction transaction;
    rex::arch::HostThreadContext context{};
    context.rip = attempt.fault.instruction_pointer;
    for (unsigned index = 0; index < 16; ++index)
      context.int_registers[index] = attempt.fault.integer_registers[index];
    rex::arch::Exception exception;
    exception.InitializeAccessViolation(&context, attempt.fault.address,
        rex::arch::Exception::AccessViolationOperation::kWrite);
    {
      rex::guest::AdjudicationScope scope(attempt.fault);
      if (Handler::global_handler()->ResolveAccessFault(exception, Kind::kScalar32, transaction)
          != Recovery::kRetry) ++incorrect;
    }
    if (!transaction.BeginRetry()) ++incorrect;
    rex::guest::RequireAccess();
    if (rex::guest::CaptureWrite(pointer + word, &value, sizeof(value)).success) ++successful;
    if (!transaction.CompleteNative() || transaction.CompleteNative()) ++incorrect;
    if (activation.HasPendingFault() || rex::guest::HasArmedAccessFrame()) ++incorrect;
  };
  std::thread first(worker, 0), second(worker, 1);
  first.join();
  second.join();
  CHECK(successful == 2);
  CHECK(incorrect == 0);
  CHECK(pointer[0] == 0xABC00000);
  CHECK(pointer[1] == 0xABC00001);
  CHECK(watch.notifications == 1);
  CHECK(watch.incorrect_phase == 0);
  CHECK(watch.incorrect_range == 0);
  }
  // The registered signal entry remains installed throughout this case. Fatal
  // unsupported device operations are bounded children, never C++ recovery.
  auto& device = GetDevice();
  auto& memory = rex::testing::GetTestMemory();
  auto* device_pointer = memory.TranslateVirtual<uint8_t*>(kDeviceAddress);
  const size_t host_page_size = rex::memory::page_size();
  rex::memory::PageAccess prior_access;
  REQUIRE(rex::memory::Protect(device_pointer, host_page_size,
                               rex::memory::PageAccess::kReadWrite, &prior_access));
  const uint64_t native_sentinel = 0x1122334455667788;
  std::memcpy(device_pointer, &native_sentinel, sizeof(native_sentinel));
  for (bool protected_page : {false, true}) {
    REQUIRE(rex::memory::Protect(device_pointer, host_page_size,
        protected_page ? rex::memory::PageAccess::kNoAccess : rex::memory::PageAccess::kReadWrite));
    for (unsigned mode = 0; mode != 4; ++mode) {
      CAPTURE(mode, protected_page);
      int diagnostic_pipe[2];
      REQUIRE(pipe(diagnostic_pipe) == 0);
      const pid_t child = fork();
      REQUIRE(child >= 0);
      if (child == 0) {
        close(diagnostic_pipe[0]);
        if (dup2(diagnostic_pipe[1], STDERR_FILENO) == -1) _exit(92);
        close(diagnostic_pipe[1]);
        alarm(3);
        device.reject_callback = true;  // Any callback invocation exits93.
        switch (mode) {
          case 0: (void)rex::guest::ReadReserved32(device_pointer); break;
          case 1: (void)rex::guest::ReadReserved64(device_pointer); break;
          case 2: (void)rex::guest::CompareExchange32(device_pointer,
                      uint32_t(native_sentinel), 1); break;
          case 3: (void)rex::guest::CompareExchange64(device_pointer, native_sentinel, 1); break;
        }
        _exit(94);  // No device emulation, native RAM access or fake success.
      }
      close(diagnostic_pipe[1]);
      int status = 0;
      pid_t waited;
      do { waited = waitpid(child, &status, 0); } while (waited == -1 && errno == EINTR);
      char diagnostic[2048]{};
      const auto count = read(diagnostic_pipe[0], diagnostic, sizeof(diagnostic) - 1);
      close(diagnostic_pipe[0]);
      REQUIRE(waited == child);
      CHECK(WIFEXITED(status));
      CHECK(WEXITSTATUS(status) == rex::guest::kFaultContractFailureExitCode);
      CHECK(count > 0);
      CHECK(std::strstr(diagnostic, "unadmitted-mapped-atomic-access") != nullptr);
      CHECK(device.reads == 0);
      CHECK(device.writes == 0);
    }
  }
  REQUIRE(rex::memory::Protect(device_pointer, host_page_size,
                              rex::memory::PageAccess::kReadWrite));
  uint64_t final_value = 0;
  std::memcpy(&final_value, device_pointer, sizeof(final_value));
  CHECK(final_value == native_sentinel);  // No CAS touched shared backing RAM.
  REQUIRE(rex::memory::Protect(device_pointer, host_page_size, prior_access));

  // Mapping metadata, rather than current protection, selects scalar device
  // access. Both accessible and trapped pages must call the device exactly once
  // in normal context and must leave the backing RAM untouched.
  for (bool protected_page : {false, true}) {
    CAPTURE(protected_page);
    device.Reset();
    REQUIRE(rex::memory::Protect(device_pointer, host_page_size,
        protected_page ? rex::memory::PageAccess::kNoAccess : rex::memory::PageAccess::kReadWrite));
    {
      rex::guest::ExecutionActivation owner;
      CHECK(rex::guest::ValueOrThrow(rex::guest::TryRead<uint32_t>(device_pointer)) ==
            rex::byte_swap(uint32_t(0x11223341)));
      rex::guest::ValueOrThrow(rex::guest::TryWrite<uint32_t>(device_pointer,
          rex::byte_swap(uint32_t(0xAABBCCDD))));
      CHECK(device.reads == 1);
      CHECK(device.writes == 1);
      CHECK(device.last_write == 0xAABBCCDD);
      CHECK(device.callbacks_in_normal_phase);
      CHECK(owner.phase() == rex::guest::ActivationPhase::Running);
      CHECK_FALSE(owner.HasPendingFault());
      CHECK_FALSE(rex::guest::HasArmedAccessFrame());
    }
    REQUIRE(rex::memory::Protect(device_pointer, host_page_size,
                                 rex::memory::PageAccess::kReadWrite));
    std::memcpy(&final_value, device_pointer, sizeof(final_value));
    CHECK(final_value == native_sentinel);
  }

  // Unsupported widths, vector operations and bulk operations are rejected
  // before any device callback or any prefix of a guest destination is changed.
  // An interior match is important: the bulk start itself is not mapped.
  auto* bulk_begin = device_pointer - 256;
  rex::memory::PageAccess prior_prefix_access;
  REQUIRE(rex::memory::Protect(device_pointer - host_page_size, host_page_size,
                               rex::memory::PageAccess::kReadWrite, &prior_prefix_access));
  std::array<uint8_t, 512> native_bytes{};
  for (size_t index = 0; index < native_bytes.size(); ++index)
    native_bytes[index] = static_cast<uint8_t>(index ^ 0x5A);
  std::memcpy(bulk_begin, native_bytes.data(), native_bytes.size());
  device.Reset();
  for (bool protected_page : {false, true}) {
    REQUIRE(rex::memory::Protect(device_pointer, host_page_size,
        protected_page ? rex::memory::PageAccess::kNoAccess : rex::memory::PageAccess::kReadWrite));
    for (unsigned mode = 0; mode != 11; ++mode) {
      CAPTURE(mode, protected_page);
      int diagnostic_pipe[2];
      REQUIRE(pipe(diagnostic_pipe) == 0);
      const pid_t child = fork();
      REQUIRE(child >= 0);
      if (child == 0) {
        close(diagnostic_pipe[0]);
        if (dup2(diagnostic_pipe[1], STDERR_FILENO) == -1) _exit(92);
        close(diagnostic_pipe[1]);
        alarm(3);
        device.reject_callback = true;
        std::array<uint8_t, 512> host_bytes{};
        host_bytes.fill(0xA5);
        switch (mode) {
          case 0: (void)rex::guest::Read<uint8_t>(device_pointer); break;
          case 1: (void)rex::guest::Read<uint16_t>(device_pointer); break;
          case 2: (void)rex::guest::Read<uint64_t>(device_pointer); break;
          case 3: rex::guest::Write<uint8_t>(device_pointer, 0xA5); break;
          case 4: rex::guest::Write<uint16_t>(device_pointer, 0xA5A5); break;
          case 5: rex::guest::Write<uint64_t>(device_pointer, UINT64_MAX); break;
          case 6: (void)rex::guest::ReadVector<std::array<uint32_t, 4>>(device_pointer); break;
          case 7: rex::guest::WriteVector(device_pointer,
                      std::array<uint32_t, 4>{1, 2, 3, 4}); break;
          case 8: rex::guest::CopyToGuest(bulk_begin, host_bytes.data(), host_bytes.size()); break;
          case 9: rex::guest::CopyFromGuest(host_bytes.data(), bulk_begin, host_bytes.size()); break;
          case 10: rex::guest::FillBytes(bulk_begin, 0xA5, host_bytes.size()); break;
        }
        _exit(94);
      }
      close(diagnostic_pipe[1]);
      int status = 0;
      pid_t waited;
      do { waited = waitpid(child, &status, 0); } while (waited == -1 && errno == EINTR);
      char diagnostic[2048]{};
      const auto count = read(diagnostic_pipe[0], diagnostic, sizeof(diagnostic) - 1);
      close(diagnostic_pipe[0]);
      REQUIRE(waited == child);
      CHECK(WIFEXITED(status));
      CHECK(WEXITSTATUS(status) == rex::guest::kFaultContractFailureExitCode);
      CHECK(count > 0);
      CHECK(std::strstr(diagnostic, mode < 8 ? "unadmitted-mapped-data-access"
                                           : "unadmitted-mapped-bulk-access") != nullptr);
      CHECK(device.reads == 0);
      CHECK(device.writes == 0);
      // The always-accessible prefix is shared guest backing, so a child which
      // copied even the first RAM chunk would make this assertion fail.
      CHECK(std::memcmp(bulk_begin, native_bytes.data(), 256) == 0);
    }
  }
  REQUIRE(rex::memory::Protect(device_pointer, host_page_size,
                               rex::memory::PageAccess::kReadWrite));
  CHECK(std::memcmp(bulk_begin, native_bytes.data(), native_bytes.size()) == 0);
  REQUIRE(rex::memory::Protect(device_pointer - host_page_size, host_page_size,
                               prior_prefix_access));
  REQUIRE(rex::memory::Protect(device_pointer, host_page_size, prior_access));

}

TEST_CASE("Linux physical watch repair excludes a concurrent rewatch until native completion",
          "[linux][guest-fault][mmio][physical-watch][repair-race]") {
  auto& memory=rex::testing::GetTestMemory();
  auto* heap=memory.LookupHeapByType(true,65536);
  REQUIRE(heap!=nullptr);
  PhysicalAllocation allocation{heap};
  REQUIRE(heap->Alloc(0x200000,65536,
      rex::memory::kMemoryAllocationReserve|rex::memory::kMemoryAllocationCommit,
      rex::memory::kMemoryProtectRead|rex::memory::kMemoryProtectWrite|
      rex::memory::kMemoryProtectWriteCombine,false,&allocation.address));
  auto address=allocation.address+0x41380;
  auto* pointer=memory.TranslateVirtual<uint32_t*>(address);
  *pointer=0x11223344;
  PhysicalWatch watch;watch.expected_physical=memory.GetPhysicalAddress(address);
  PhysicalRegistration registration{memory,memory.RegisterPhysicalMemoryInvalidationCallback(InvalidatePhysical,&watch)};
  rex::guest::ExecutionActivation activation;
  memory.EnablePhysicalMemoryAccessCallbacks(watch.expected_physical&~4095u,4096,true,false);
  uint32_t value=0x00002609;
  auto captured=rex::guest::CaptureWrite(pointer,&value,4);
  REQUIRE_FALSE(captured.success);
  REQUIRE(captured.fault.access_intent==1);
  Handler::DeferredTransaction transaction;
  REQUIRE(ResolveCaptured(captured.fault,Kind::kScalar32,transaction)==Recovery::kRetry);
  bool rewatch_admitted=false;
  std::thread gpu([&]{
    rex::thread::global_critical_region region;
    auto lock=region.TryAcquire();
    rewatch_admitted=lock.owns_lock();
    if(rewatch_admitted)
      memory.EnablePhysicalMemoryAccessCallbacks(watch.expected_physical&~4095u,4096,true,false);
  });
  gpu.join();
  CHECK_FALSE(rewatch_admitted);
  rex::memory::PageAccess access=rex::memory::PageAccess::kNoAccess;
  size_t length=4096;
  REQUIRE(rex::memory::QueryProtect(pointer,length,access));
  CHECK(access==rex::memory::PageAccess::kReadWrite);
  CHECK(watch.notifications==1);
  REQUIRE(transaction.BeginRetry());
  auto completion=rex::guest::CaptureWrite(pointer,&value,4);
  CHECK(completion.success);
  if(completion.success) {
    REQUIRE(transaction.CompleteNative());
    CHECK(*pointer==value);
  }
  // Completion must release the watch lock, allowing a new legitimate watch.
  // Use try-lock to keep a broken implementation bounded rather than hanging.
  bool rewatch_after_completion=false;
  std::thread next_gpu([&]{
    rex::thread::global_critical_region region;
    auto lock=region.TryAcquire();rewatch_after_completion=lock.owns_lock();
    if(rewatch_after_completion)
      memory.EnablePhysicalMemoryAccessCallbacks(watch.expected_physical&~4095u,4096,true,false);
  });
  next_gpu.join();
  CHECK(rewatch_after_completion);
  if(completion.success&&rewatch_after_completion) {
    length=4096;REQUIRE(rex::memory::QueryProtect(pointer,length,access));
    CHECK(access==rex::memory::PageAccess::kReadOnly);
    auto second=rex::guest::TryWrite<uint32_t>(pointer,0x77889900);
    REQUIRE(second.IsSuccess());CHECK(second.Value());CHECK(*pointer==0x77889900);
    CHECK(watch.notifications==2);CHECK(watch.incorrect_phase==0);
  }
}

TEST_CASE("Linux genuine unrepaired readonly watch still rejects retry progress",
          "[linux][guest-fault][mmio][physical-watch][repair-no-progress]") {
  auto& memory=rex::testing::GetTestMemory();auto* heap=memory.LookupHeapByType(true,65536);
  REQUIRE(heap!=nullptr);PhysicalAllocation allocation{heap};
  REQUIRE(heap->Alloc(65536,65536,
    rex::memory::kMemoryAllocationReserve|rex::memory::kMemoryAllocationCommit,
    rex::memory::kMemoryProtectRead|rex::memory::kMemoryProtectWrite,false,&allocation.address));
  auto* pointer=memory.TranslateVirtual<uint32_t*>(allocation.address);*pointer=0x12345678;
  PhysicalWatch watch;watch.expected_physical=memory.GetPhysicalAddress(allocation.address);
  PhysicalRegistration registration{memory,memory.RegisterPhysicalMemoryInvalidationCallback(InvalidatePhysical,&watch)};
  memory.EnablePhysicalMemoryAccessCallbacks(watch.expected_physical,4096,true,false);
  REQUIRE(heap->Protect(allocation.address,65536,rex::memory::kMemoryProtectRead));
  int fd[2];REQUIRE(pipe(fd)==0);auto child=fork();REQUIRE(child>=0);
  if(!child) {
    close(fd[0]);if(dup2(fd[1],STDERR_FILENO)==-1)_exit(92);close(fd[1]);alarm(5);
    rex::guest::ExecutionActivation activation;
    auto result=rex::guest::TryWrite<uint32_t>(pointer,0xDEADBEEF);
    (void)result;_exit(94);
  }
  close(fd[1]);std::string diagnostic;char bytes[1024];ssize_t size;
  while((size=read(fd[0],bytes,sizeof(bytes)))>0)diagnostic.append(bytes,size);
  close(fd[0]);int status=0;REQUIRE(waitpid(child,&status,0)==child);
  REQUIRE(WIFEXITED(status));CHECK(WEXITSTATUS(status)==rex::guest::kFaultContractFailureExitCode);
  CHECK(diagnostic.find("deferred-repair-made-no-protection-progress")!=std::string::npos);
  CHECK(diagnostic.find("terminate")==std::string::npos);
  CHECK(*pointer==0x12345678);
  rex::guest::ExecutionActivation cleanup;
  REQUIRE(heap->Protect(allocation.address,65536,rex::memory::kMemoryProtectRead|rex::memory::kMemoryProtectWrite));
}
TEST_CASE("Linux unadmitted cross-page scalar writes remain side-effect free and diagnostic",
          "[linux][guest-fault][cross-page][negative-control]") {
  auto* pages=static_cast<unsigned char*>(mmap(nullptr,8192,PROT_READ|PROT_WRITE,
      MAP_SHARED|MAP_ANONYMOUS,-1,0));
  REQUIRE(pages!=MAP_FAILED);
  std::memset(pages,0xA5,8192);
  int fd[2];REQUIRE(pipe(fd)==0);auto child=fork();REQUIRE(child>=0);
  if(!child) {
    close(fd[0]);if(dup2(fd[1],STDERR_FILENO)==-1)_exit(92);close(fd[1]);alarm(5);
    rex::guest::ExecutionActivation activation;
    auto result=rex::guest::TryWrite<uint32_t>(pages+4094,0x11223344);
    (void)result;_exit(94);
  }
  close(fd[1]);std::string diagnostic;char bytes[1024];ssize_t size;
  while((size=read(fd[0],bytes,sizeof(bytes)))>0)diagnostic.append(bytes,size);
  close(fd[0]);int status=0;REQUIRE(waitpid(child,&status,0)==child);
  REQUIRE(WIFEXITED(status));CHECK(WEXITSTATUS(status)==rex::guest::kFaultContractFailureExitCode);
  CHECK(diagnostic.find("unadmitted-cross-page-access")!=std::string::npos);
  CHECK(diagnostic.find("\"width\":4,\"first_bytes\":2")!=std::string::npos);
  CHECK(diagnostic.find("\"atomic\":false,\"vector\":false,\"write\":true")!=std::string::npos);
  CHECK(diagnostic.find("\"native_access_started\":false")!=std::string::npos);
  CHECK(diagnostic.find("terminate")==std::string::npos);
  CHECK(pages[4094]==0xA5);CHECK(pages[4095]==0xA5);
  CHECK(pages[4096]==0xA5);CHECK(pages[4097]==0xA5);
  CHECK(munmap(pages,8192)==0);
}

TEST_CASE("Linux scalar16 cross-page virtual RAM reads stage results and retain terminal ownership",
          "[linux][guest-fault][cross-page][scalar16]") {
  auto& memory=rex::testing::GetTestMemory();auto* heap=memory.LookupHeapByType(false,65536);
  REQUIRE(heap!=nullptr);PhysicalAllocation allocation{heap};
  REQUIRE(heap->Alloc(65536,65536,
    rex::memory::kMemoryAllocationReserve|rex::memory::kMemoryAllocationCommit,
    rex::memory::kMemoryProtectRead|rex::memory::kMemoryProtectWrite,false,&allocation.address));
  auto* pages=memory.TranslateVirtual<unsigned char*>(allocation.address);
  pages[4095]=0x12;pages[4096]=0x34;
  struct Binding {
    rex::runtime::ThreadState* saved=rex::runtime::ThreadState::Get();
    rex::runtime::ThreadState thread;
    Binding(rex::memory::Memory& memory):thread(99,0,0,&memory){rex::runtime::ThreadState::Bind(&thread);}
    ~Binding(){rex::runtime::ThreadState::Bind(saved);}
  } binding(memory);
  for(unsigned protected_pages=0;protected_pages<4;++protected_pages) {
    INFO("protected pages: "<<protected_pages);
    REQUIRE(mprotect(pages,4096,protected_pages&1?PROT_NONE:PROT_READ|PROT_WRITE)==0);
    REQUIRE(mprotect(pages+4096,4096,protected_pages&2?PROT_NONE:PROT_READ|PROT_WRITE)==0);
    rex::guest::ExecutionActivation activation;uint16_t value=0xABCD;
    auto result=rex::guest::detail::TryReadBytes(pages+4095,&value,2);
    CHECK(result.IsSuccess()==(protected_pages==0));
    if(result.Failed()) {
      CHECK(value==0xABCD);CHECK(activation.HasPendingFault());
      auto fault=activation.Consume(result.Fault());
      CHECK(fault.access_intent==0);
      CHECK(fault.address==reinterpret_cast<uintptr_t>(pages+(protected_pages&1?4095:4096)));
      CHECK(!activation.HasPendingFault());
    } else {
      CHECK(value==0x3412);CHECK(rex::byte_swap(value)==0x1234);
      CHECK(!activation.HasPendingFault());
    }
    REQUIRE(mprotect(pages,8192,PROT_READ|PROT_WRITE)==0);
    CHECK(pages[4095]==0x12);CHECK(pages[4096]==0x34);
  }
}

TEST_CASE("Linux cross-page admission keeps physical watches and non-scalar16 classes excluded",
          "[linux][guest-fault][cross-page][negative-control]") {
  auto& memory=rex::testing::GetTestMemory();auto* heap=memory.LookupHeapByType(true,65536);
  REQUIRE(heap!=nullptr);PhysicalAllocation allocation{heap};
  REQUIRE(heap->Alloc(65536,65536,
    rex::memory::kMemoryAllocationReserve|rex::memory::kMemoryAllocationCommit,
    rex::memory::kMemoryProtectRead|rex::memory::kMemoryProtectWrite,false,&allocation.address));
  auto* pages=memory.TranslateVirtual<unsigned char*>(allocation.address);
  pages[4095]=0x12;pages[4096]=0x34;
  PhysicalWatch watch;watch.expected_physical=memory.GetPhysicalAddress(allocation.address);
  PhysicalRegistration registration{memory,memory.RegisterPhysicalMemoryInvalidationCallback(InvalidatePhysical,&watch)};
  memory.EnablePhysicalMemoryAccessCallbacks(watch.expected_physical,8192,true,false);
  for(unsigned mode=0;mode<5;++mode) {
    INFO("rejected mode: "<<mode);
    int fd[2];REQUIRE(pipe(fd)==0);auto child=fork();REQUIRE(child>=0);
    if(!child) {
      close(fd[0]);if(dup2(fd[1],STDERR_FILENO)==-1)_exit(92);close(fd[1]);alarm(5);
      rex::runtime::ThreadState thread(99,0,0,&memory);rex::runtime::ThreadState::Bind(&thread);
      rex::guest::ExecutionActivation activation;uint64_t output=0;
      if(mode==0){auto result=rex::guest::TryRead<uint16_t>(pages+4095);(void)result;}
      if(mode==1){auto result=rex::guest::TryRead<uint32_t>(pages+4095);(void)result;}
      if(mode==2){auto result=rex::guest::detail::TryCompareExchange32(pages+4095,0,1);(void)result;}
      if(mode==3){auto result=rex::guest::detail::TryReadBytes(pages+4095,&output,2,false,true);(void)result;}
      if(mode==4){unsigned char vector[16]{};auto result=rex::guest::detail::TryReadBytes(pages+4095,vector,16,true);(void)result;}
      _exit(94);
    }
    close(fd[1]);std::string diagnostic;char bytes[1024];ssize_t size;
    while((size=read(fd[0],bytes,sizeof(bytes)))>0)diagnostic.append(bytes,size);
    close(fd[0]);int status=0;REQUIRE(waitpid(child,&status,0)==child);
    REQUIRE(WIFEXITED(status));CHECK(WEXITSTATUS(status)==rex::guest::kFaultContractFailureExitCode);
    CHECK(diagnostic.find("unadmitted-cross-page-access")!=std::string::npos);
    CHECK(diagnostic.find("terminate")==std::string::npos);
    CHECK(pages[4095]==0x12);CHECK(pages[4096]==0x34);CHECK(watch.notifications==0);
    rex::memory::PageAccess access{};size_t length=4096;
    REQUIRE(rex::memory::QueryProtect(pages,length,access));CHECK(access==rex::memory::PageAccess::kReadOnly);
  }
}
#endif
