// Linux guest access capture. Semantic fault ownership lives in guest_fault_state.h.
#pragma once

#include <cstddef>
#include <cstdint>

namespace rex::guest {

// Value snapshot, not a ucontext pointer or a guest PowerPC register context.
// Native integer order: RAX RCX RDX RBX RSP RBP RSI RDI R8..R15 on x86-64.
struct CapturedFault {
  int signal_number = 0;
  int signal_code = 0;
  uint32_t access_intent = 0;
  uint64_t page_fault_error = 0;
  uint64_t flags = 0;
  uintptr_t address = 0;
  uintptr_t instruction_pointer = 0;
  uintptr_t stack_pointer = 0;
  uint64_t integer_registers[16]{};
  unsigned char xmm_registers[16][16]{};
};

enum class CopyEndpoints : unsigned { kSource = 1, kDestination = 2, kBoth = 3 };

struct AccessAttempt {
  bool success = false;
  size_t completed = 0;
  CapturedFault fault{};
};

// Internal capture primitives. Their only recovery target is their own real
// assembly leaf's failure return. Callers own semantic admission/propagation.
AccessAttempt CaptureRead(const void* address, void* output, size_t width) noexcept;
AccessAttempt CaptureWrite(void* address, const void* value, size_t width) noexcept;
AccessAttempt CaptureVectorRead(const void* address, void* output) noexcept;
AccessAttempt CaptureVectorWrite(void* address, const void* value) noexcept;
AccessAttempt CaptureCompareExchange32(void* address, uint32_t expected, uint32_t desired,
                                       uint32_t* previous) noexcept;
AccessAttempt CaptureCompareExchange64(void* address, uint64_t expected, uint64_t desired,
                                       uint64_t* previous) noexcept;
AccessAttempt CaptureCopy(void* destination, const void* source, size_t length,
                          CopyEndpoints endpoints = CopyEndpoints::kBoth) noexcept;

// Called exclusively from the Linux SEH signal entry. No callbacks, allocation,
// locks, exception processing, semantic pending-state mutation or decoding.
#if defined(__GNUC__)
__attribute__((visibility("hidden")))
#endif
bool CaptureOwnedSignal(int signal_number, void* signal_info, void* signal_context) noexcept;
bool HasArmedAccessFrame() noexcept;
#if defined(__GNUC__)
__attribute__((visibility("hidden")))
#endif
bool InSignalContext() noexcept;
#if defined(__GNUC__)
__attribute__((visibility("hidden")))
#endif
void EnterSignalContext() noexcept;
#if defined(__GNUC__)
__attribute__((visibility("hidden")))
#endif
void LeaveSignalContext() noexcept;
// Normal-context phase suppression: deferred callbacks never acquire a leaf.
void SuppressAccessCapture(bool suppressed) noexcept;

}  // namespace rex::guest
