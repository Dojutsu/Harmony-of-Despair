#include <rex/platform/guest_access.h>
#include "guest_access_compact.h"
#include <rex/platform/seh.h>

#include <signal.h>
#include <ucontext.h>

#include <cstring>
#include <cstdlib>
#include <limits>
#include <type_traits>

namespace rex::guest {
namespace {
extern "C" {
#define LEAF(name) int name(const void*, void*); extern char name##_site, name##_fail
LEAF(rex_guest_read1); LEAF(rex_guest_read2); LEAF(rex_guest_read4); LEAF(rex_guest_read8);
LEAF(rex_guest_write1); LEAF(rex_guest_write2); LEAF(rex_guest_write4); LEAF(rex_guest_write8);
LEAF(rex_guest_vector_read); LEAF(rex_guest_vector_write);
#undef LEAF
int rex_guest_cas4(void*, uint32_t, uint32_t, uint32_t*);
int rex_guest_cas8(void*, uint64_t, uint64_t, uint64_t*);
extern char rex_guest_cas4_site, rex_guest_cas4_fail, rex_guest_cas8_site, rex_guest_cas8_fail;
int rex_guest_copy(void*, const void*, size_t);
extern char rex_guest_copy_site, rex_guest_copy_fail;
}
// Owned faults populate every member below; ordinary successful leaves need
// no private fault payload. Keep the public successful AccessAttempt zeroed.
// Keep these fields synchronized with CapturedFault; assertions pin their
// current layout without changing the public capture ABI.
struct CaptureSnapshot {
  int signal_number;
  int signal_code;
  uint32_t access_intent;
  uint64_t page_fault_error;
  uint64_t flags;
  uintptr_t address;
  uintptr_t instruction_pointer;
  uintptr_t stack_pointer;
  uint64_t integer_registers[16];
  unsigned char xmm_registers[16][16];
};
static_assert(std::is_standard_layout_v<CaptureSnapshot>);
static_assert(std::is_standard_layout_v<CapturedFault>);
static_assert(std::is_trivially_copyable_v<CaptureSnapshot>);
static_assert(std::is_trivially_copyable_v<CapturedFault>);
static_assert(sizeof(CaptureSnapshot) == sizeof(CapturedFault));
static_assert(alignof(CaptureSnapshot) == alignof(CapturedFault));
static_assert(offsetof(CaptureSnapshot, signal_number) == offsetof(CapturedFault, signal_number));
static_assert(offsetof(CaptureSnapshot, signal_code) == offsetof(CapturedFault, signal_code));
static_assert(offsetof(CaptureSnapshot, access_intent) == offsetof(CapturedFault, access_intent));
static_assert(offsetof(CaptureSnapshot, page_fault_error) == offsetof(CapturedFault, page_fault_error));
static_assert(offsetof(CaptureSnapshot, flags) == offsetof(CapturedFault, flags));
static_assert(offsetof(CaptureSnapshot, address) == offsetof(CapturedFault, address));
static_assert(offsetof(CaptureSnapshot, instruction_pointer) == offsetof(CapturedFault, instruction_pointer));
static_assert(offsetof(CaptureSnapshot, stack_pointer) == offsetof(CapturedFault, stack_pointer));
static_assert(offsetof(CaptureSnapshot, integer_registers) == offsetof(CapturedFault, integer_registers));
static_assert(offsetof(CaptureSnapshot, xmm_registers) == offsetof(CapturedFault, xmm_registers));
struct AccessFrame {
  volatile sig_atomic_t phase = 0;
  uintptr_t site = 0, failure = 0;
  uintptr_t low[2]{}, high[2]{};
  int expected_intent = -1;
  bool bulk = false;
  CaptureSnapshot fault;
};
// Constant-initialized shared runtime TLS. Initial-exec/direct FS is reviewed
// for the admitted startup-loaded Linux DSOs; late loader use is not admitted.
thread_local AccessFrame* current_frame __attribute__((tls_model("initial-exec"))) = nullptr;
thread_local volatile sig_atomic_t signal_depth __attribute__((tls_model("initial-exec"))) = 0;
thread_local volatile sig_atomic_t capture_suppressed __attribute__((tls_model("initial-exec"))) = 0;
struct FrameScope {
  AccessFrame& frame;
  AccessFrame* saved;
  explicit FrameScope(AccessFrame& value) noexcept : frame(value), saved(current_frame) {
    current_frame = &frame;
    frame.phase = 1;
  }
  ~FrameScope() { frame.phase = 0; current_frame = saved; }
};
void AdmitCapture() noexcept {
  if(signal_depth) std::_Exit(139); // async-signal-safe terminal ABI refusal
  if(capture_suppressed) std::_Exit(86); // no nested guest operation in callback
}
AccessFrame MakeFrame(char* site, char* failure, const void* address, size_t width,
                      int intent) noexcept {
  AccessFrame f;
  f.site = reinterpret_cast<uintptr_t>(site);
  f.failure = reinterpret_cast<uintptr_t>(failure);
  f.low[0] = reinterpret_cast<uintptr_t>(address);
  if (width > std::numeric_limits<uintptr_t>::max() - f.low[0]) std::_Exit(86);
  f.high[0] = f.low[0] + width;
  f.expected_intent = intent;
  return f;
}
AccessAttempt Finish(const AccessFrame& frame, int status, size_t completed) noexcept {
  AccessAttempt result;
  result.success = status == 0;
  result.completed = completed;
  if (status) {
    std::memcpy(&result.fault, &frame.fault, sizeof(result.fault));
  }
  return result;
}
using Leaf = int (*)(const void*, void*);
template<class FinishCapture>
auto ScalarCapture(const void* address, void* value, size_t width, bool write,
                   FinishCapture finish) noexcept {
  AdmitCapture();
  platform::seh_initialize();
  Leaf leaf = nullptr; char *site = nullptr, *failure = nullptr;
#define SELECT(w) case w: if (write) { leaf=rex_guest_write##w; site=&rex_guest_write##w##_site; failure=&rex_guest_write##w##_fail; } else { leaf=rex_guest_read##w; site=&rex_guest_read##w##_site; failure=&rex_guest_read##w##_fail; } break
  switch (width) { SELECT(1); SELECT(2); SELECT(4); SELECT(8); default: std::_Exit(86); }
#undef SELECT
  auto frame = MakeFrame(site, failure, address, width, write ? 1 : 0);
  int status;
  { FrameScope scope(frame); status = leaf(address, value); }
  return finish(frame, status, width);
}
AccessAttempt Scalar(const void* address, void* value, size_t width, bool write) noexcept {
  return ScalarCapture(address, value, width, write,
      [](const AccessFrame& frame, int status, size_t size) noexcept {
        return Finish(frame, status, status ? 0 : size);
      });
}
bool ScalarCompact(const void* address, void* value, size_t width, bool write,
                   detail::ScalarCaptureFailure& failure) noexcept {
  return ScalarCapture(address, value, width, write,
      [&failure](const AccessFrame& frame, int status, size_t) noexcept {
        if (status) {
          failure.emplace();
          std::memcpy(&*failure, &frame.fault, sizeof(frame.fault));
        }
        return status == 0;
      });
}
}  // namespace

namespace detail {
bool CaptureReadCompact(const void* address, void* output, size_t width,
                        ScalarCaptureFailure& failure) noexcept {
  return ScalarCompact(address, output, width, false, failure);
}
bool CaptureWriteCompact(void* address, const void* value, size_t width,
                         ScalarCaptureFailure& failure) noexcept {
  return ScalarCompact(address, const_cast<void*>(value), width, true, failure);
}
} // namespace detail

bool HasArmedAccessFrame() noexcept { return current_frame && current_frame->phase == 1; }
bool InSignalContext() noexcept { return signal_depth != 0; }
void EnterSignalContext() noexcept { signal_depth = signal_depth + 1; }
void LeaveSignalContext() noexcept { signal_depth = signal_depth - 1; }
void SuppressAccessCapture(bool suppressed) noexcept { capture_suppressed = suppressed ? 1 : 0; }

bool CaptureOwnedSignal(int sig, void* raw_info, void* raw_context) noexcept {
  auto* frame = current_frame;
  auto* info = static_cast<siginfo_t*>(raw_info);
  auto* context = static_cast<ucontext_t*>(raw_context);
  if (sig != SIGSEGV || !info || !context || !frame || frame->phase != 1 ||
      info->si_code != SEGV_ACCERR || signal_depth != 1 || capture_suppressed) return false;
  auto& g = context->uc_mcontext.gregs;
  const auto pc = static_cast<uintptr_t>(g[REG_RIP]);
  const auto address = reinterpret_cast<uintptr_t>(info->si_addr);
  const auto error = static_cast<uint64_t>(g[REG_ERR]);
  const int intent = (error & 2) ? 1 : 0;
  if (pc != frame->site || (error & 16) ||
      (frame->expected_intent != -1 && intent != frame->expected_intent) ||
      !((address >= frame->low[0] && address < frame->high[0]) ||
        (address >= frame->low[1] && address < frame->high[1]))) return false;
  if (frame->bulk && !((intent == 1 && address >= frame->low[0] && address < frame->high[0]) ||
                       (intent == 0 && address >= frame->low[1] && address < frame->high[1]))) return false;
  frame->phase = 2;
  frame->fault.signal_number = sig;
  frame->fault.signal_code = info->si_code;
  frame->fault.access_intent = intent;
  frame->fault.page_fault_error = error;
  frame->fault.flags = g[REG_EFL];
  frame->fault.address = address;
  frame->fault.instruction_pointer = pc;
  frame->fault.stack_pointer = g[REG_RSP];
  static constexpr int registers[16] = { REG_RAX, REG_RCX, REG_RDX, REG_RBX, REG_RSP, REG_RBP,
                                 REG_RSI, REG_RDI, REG_R8, REG_R9, REG_R10, REG_R11,
                                 REG_R12, REG_R13, REG_R14, REG_R15 };
  auto* out = reinterpret_cast<volatile uint64_t*>(frame->fault.integer_registers);
  for (unsigned i = 0; i < 16; ++i) out[i] = g[registers[i]];
  if (context->uc_mcontext.fpregs) {
    auto* destination = reinterpret_cast<volatile unsigned char*>(frame->fault.xmm_registers);
    auto* source = reinterpret_cast<const volatile unsigned char*>(context->uc_mcontext.fpregs->_xmm);
    for (unsigned i = 0; i < 256; ++i) destination[i] = source[i];
  } else {
    auto* destination = reinterpret_cast<volatile unsigned char*>(frame->fault.xmm_registers);
    for (unsigned i = 0; i < 256; ++i) destination[i] = 0;
  }
  frame->phase = 3;
  g[REG_RIP] = static_cast<greg_t>(frame->failure);
  return true;
}
AccessAttempt CaptureRead(const void* address, void* output, size_t width) noexcept {
  return Scalar(address, output, width, false);
}
AccessAttempt CaptureWrite(void* address, const void* value, size_t width) noexcept {
  return Scalar(address, const_cast<void*>(value), width, true);
}
AccessAttempt CaptureVectorRead(const void* address, void* output) noexcept {
  AdmitCapture();
  platform::seh_initialize();
  auto frame = MakeFrame(&rex_guest_vector_read_site, &rex_guest_vector_read_fail, address, 16, 0);
  int status; { FrameScope scope(frame); status = rex_guest_vector_read(address, output); }
  return Finish(frame, status, status ? 0 : 16);
}
AccessAttempt CaptureVectorWrite(void* address, const void* value) noexcept {
  AdmitCapture();
  platform::seh_initialize();
  auto frame = MakeFrame(&rex_guest_vector_write_site, &rex_guest_vector_write_fail, address, 16, 1);
  int status; { FrameScope scope(frame); status = rex_guest_vector_write(address, const_cast<void*>(value)); }
  return Finish(frame, status, status ? 0 : 16);
}
AccessAttempt CaptureCompareExchange32(void* address, uint32_t expected, uint32_t desired,
                                      uint32_t* previous) noexcept {
  AdmitCapture();
  platform::seh_initialize();
  auto frame = MakeFrame(&rex_guest_cas4_site, &rex_guest_cas4_fail, address, 4, 1);
  int status; { FrameScope scope(frame); status = rex_guest_cas4(address, expected, desired, previous); }
  return Finish(frame, status, status ? 0 : 4);
}
AccessAttempt CaptureCompareExchange64(void* address, uint64_t expected, uint64_t desired,
                                      uint64_t* previous) noexcept {
  AdmitCapture();
  platform::seh_initialize();
  auto frame = MakeFrame(&rex_guest_cas8_site, &rex_guest_cas8_fail, address, 8, 1);
  int status; { FrameScope scope(frame); status = rex_guest_cas8(address, expected, desired, previous); }
  return Finish(frame, status, status ? 0 : 8);
}
AccessAttempt CaptureCopy(void* destination, const void* source, size_t length, CopyEndpoints endpoints) noexcept {
  AdmitCapture();
  if (!length) return {true, 0, {}};
  platform::seh_initialize();
  auto frame = MakeFrame(&rex_guest_copy_site, &rex_guest_copy_fail, destination, length, -1);
  frame.low[1] = reinterpret_cast<uintptr_t>(source);
  if (length > std::numeric_limits<uintptr_t>::max() - frame.low[1]) std::_Exit(86);
  frame.high[1] = frame.low[1] + length;
  frame.bulk = true;
  auto mask=static_cast<unsigned>(endpoints);
  if (!(mask & 2)) frame.low[0]=frame.high[0]=0;
  if (!(mask & 1)) frame.low[1]=frame.high[1]=0;
  int status; { FrameScope scope(frame); status = rex_guest_copy(destination, source, length); }
  return Finish(frame, status, status ? length - frame.fault.integer_registers[1] : length);
}
}  // namespace rex::guest
