// Real Runtime/HLE wait observations across duplicate/last-handle close.
// Each bounded CTest mode uses its own process; no title or network session.
#include <rex/runtime.h>
#include <rex/logging.h>
#include <rex/cvar.h>
#include <rex/ppc/context.h>
#include <rex/platform/guest_fault_state.h>
#include <rex/system/xthread.h>
#include <rex/system/xsemaphore.h>
#include <rex/system/util/object_table.h>
#include <spdlog/sinks/base_sink.h>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

REX_EXTERN(__imp__NtCreateSemaphore);
REX_EXTERN(__imp__NtDuplicateObject);
REX_EXTERN(__imp__NtWaitForSingleObjectEx);
REX_EXTERN(__imp__NtReleaseSemaphore);
REX_EXTERN(__imp__NtClose);

using namespace rex;
using namespace rex::system;
using namespace std::chrono_literals;
static size_t checks = 0;
static void Check(bool condition, const char* message) {
  ++checks;
  if (!condition) throw std::runtime_error(message);
}
class CaptureSink : public spdlog::sinks::base_sink<std::mutex> {
 public:
  bool WaitFor(const std::string& fragment, std::chrono::milliseconds timeout = 3s) {
    std::unique_lock lock(mutex_);
    return changed_.wait_for(lock, timeout, [&] {
      for (const auto& line : lines_) if (line.find(fragment) != std::string::npos) return true;
      return false;
    });
  }
  std::vector<std::string> Snapshot() {
    std::lock_guard lock(mutex_); return lines_;
  }
 private:
  void sink_it_(const spdlog::details::log_msg& message) override {
    lines_.emplace_back(message.payload.data(), message.payload.size()); changed_.notify_all();
  }
  void flush_() override {}
  std::condition_variable changed_;
  std::vector<std::string> lines_;
};
static uint32_t Invoke(PPCFunc* function, std::initializer_list<uint64_t> arguments) {
  auto* current = XThread::GetCurrentThread();
  if (!current || runtime::ThreadState::Get() != current->thread_state())
    throw std::runtime_error("HLE call requires real bound XThread/ThreadState");
  auto* context = current->thread_state()->context();
  PPCRegister* registers[] = {&context->r3, &context->r4, &context->r5, &context->r6};
  size_t index = 0;
  for (auto argument : arguments) registers[index++]->u64 = argument;
  guest::ExecutionActivation activation;
  function(*context, current->memory()->virtual_membase());
  return context->r3.u32;
}
static uint32_t ReadGuest(memory::Memory* memory, uint32_t address) {
  return *memory->TranslateVirtual<be<uint32_t>*>(address);
}
static std::string HexHandle(uint32_t handle) { return fmt::format("handle={:08X}", handle); }
static bool HasRecord(const std::vector<std::string>& lines, uint32_t handle,
                      const std::string& operation, const std::string& status = {}) {
  for (const auto& line : lines)
    if (line.find("Guest wait trace seq=") != std::string::npos &&
        line.find(HexHandle(handle)) != std::string::npos &&
        line.find("op=" + operation + " ") != std::string::npos &&
        (status.empty() || line.find("status=" + status) != std::string::npos)) return true;
  return false;
}
// Actual Linux waiter-state observation in both enabled and disabled cases.
// This own-process thread performs no blocking call between publishing its tid
// and the semaphore HLE call except the semaphore wait itself.
static bool WaitForNativeBlock(const std::atomic<uint32_t>& tid) {
  const auto deadline = std::chrono::steady_clock::now() + 3s;
  while (std::chrono::steady_clock::now() < deadline) {
    const auto id = tid.load(std::memory_order_acquire);
    if (id) {
      std::ifstream file("/proc/self/task/" + std::to_string(id) + "/wchan");
      std::string state; file >> state;
      if (state.find("futex") != std::string::npos) return true;
    }
    std::this_thread::sleep_for(1ms);
  }
  return false;
}
static void Run(KernelState* kernel, CaptureSink& sink, bool enabled, bool alias_mode) {
  auto* memory = kernel->memory();
  const auto guest_address = memory->SystemHeapAlloc(4096);
  Check(guest_address != 0, "actual guest allocation");
  Check(Invoke(__imp__NtCreateSemaphore, {guest_address, 0, 0, 1}) == X_STATUS_SUCCESS,
        "real NtCreateSemaphore empty count, limit1");
  const auto original = ReadGuest(memory, guest_address);
  auto retained = kernel->object_table()->LookupObject<XSemaphore>(original);
  Check(bool(retained), "retain actual HLE-created semaphore");
  uint32_t alias = 0;
  if (alias_mode) {
    Check(Invoke(__imp__NtDuplicateObject, {original, guest_address + 4, 0}) == X_STATUS_SUCCESS,
          "real NtDuplicateObject");
    alias = ReadGuest(memory, guest_address + 4);
    Check(alias != original && alias != 0, "distinct duplicate handle");
    Check(kernel->object_table()->LookupObject<XSemaphore>(alias).get() == retained.get(),
          "duplicate alias refers to same native semaphore");
  }
  Check(cvar::SetFlagFromCommandLine("guest_wait_trace_handle", enabled ? std::to_string(original) : "0"),
        "actual trace cvar accepts selected handle/disabled value");
  Check(cvar::GetFlagByName("guest_wait_trace_handle") == (enabled ? std::to_string(original) : "0"),
        "actual trace cvar value");
  Check(cvar::SetFlagFromCommandLine("guest_wait_trace_delay_ms", "0"), "actual zero-delay cvar");
  std::atomic<uint32_t> native_tid{0};
  std::atomic<uint32_t> wait_result{0xFFFFFFFF};
  auto waiter = object_ref<XHostThread>(new XHostThread(kernel, 128 * 1024, 0, [&] {
    native_tid.store(rex::thread::current_thread_system_id(), std::memory_order_release);
    wait_result.store(Invoke(__imp__NtWaitForSingleObjectEx, {original, 1, 0, 0}),
                      std::memory_order_release);
    return 0;
  }));
  Check(waiter->Create() == X_STATUS_SUCCESS, "real bound waiter thread creation");
  bool blocked = (!enabled || (sink.WaitFor(HexHandle(original) + " native_tid=") &&
      sink.WaitFor("op=wait_begin "))) && WaitForNativeBlock(native_tid);
  // Never leave a native waiter behind if its readiness observation fails.
  if (!blocked) {
    (void)retained->ReleaseSemaphore(1, nullptr);
    waiter->Wait(0, 0, 0, nullptr);
    Invoke(__imp__NtClose, {original});
    if (alias_mode) Invoke(__imp__NtClose, {alias});
    throw std::runtime_error("bounded actual wait readiness observation failed");
  }
  Check(wait_result.load(std::memory_order_acquire) == 0xFFFFFFFF,
        "empty semaphore keeps actual HLE wait pending before close");
  Check(Invoke(__imp__NtClose, {original}) == X_STATUS_SUCCESS, "close original during retained HLE wait");
  Check(!kernel->object_table()->LookupObject<XSemaphore>(original), "closed original no longer resolves");
  if (alias_mode) {
    Check(retained->handles().size() == 1 && retained->handles()[0] == alias,
          "only duplicate alias remains after original close");
    Check(Invoke(__imp__NtReleaseSemaphore, {alias, 1, guest_address + 8}) == X_STATUS_SUCCESS,
          "real alias NtReleaseSemaphore wakes original retained wait");
    Check(ReadGuest(memory, guest_address + 8) == 0, "actual successful native previous count");
  } else {
    Check(retained->handles().empty(), "legitimate retained object has zero handles");
    Check(retained->ReleaseSemaphore(1, nullptr), "native retained-object release after last handle close");
  }
  uint64_t bounded_timeout = static_cast<uint64_t>(-30000000LL);
  Check(waiter->Wait(0, 0, 0, &bounded_timeout) == X_STATUS_SUCCESS, "retained wait completes within3seconds");
  Check(wait_result.load(std::memory_order_acquire) == X_STATUS_SUCCESS,
        "actual original-handle HLE wait returns success after concurrent close");
  FlushLogging();
  const auto lines = sink.Snapshot();
  { std::ofstream output("artifacts/" + std::string(alias_mode ? "alias-" : "last-") +
                         (enabled ? "on" : "off") + "-trace.log");
    for (const auto& line : lines) output << line << '\n'; }
  if (enabled) {
    Check(HasRecord(lines, original, "wait_begin"), "selected original wait_begin observed");
    Check(HasRecord(lines, original, "handle_close", "00000000"), "selected original close observed");
    // Deterministic old807 failure: object.handle() becomes alias after close,
    // so its post-native wait trace is filtered out of the original selection.
    Check(HasRecord(lines, original, "wait_return", "00000000"),
          "current ABI wait_return preserves original identity after primary/last handle close");
  } else {
    bool any_trace = false;
    for (const auto& line : lines) if (line.find("Guest wait trace") != std::string::npos) any_trace = true;
    Check(!any_trace, "actual disabled trace emits no records");
  }
  if (alias_mode) Check(Invoke(__imp__NtClose, {alias}) == X_STATUS_SUCCESS, "close duplicate after wait");
  Check(retained->handles().empty(), "final retained semaphore has no handles");
  uint64_t immediate = 0;
  Check(retained->Wait(3, 1, 0, &immediate) == X_STATUS_TIMEOUT,
        "retained no-handle wait remains legitimate and consumed token exactlyonce");
  Check(Invoke(__imp__NtWaitForSingleObjectEx, {original, 1, 0, guest_address + 16}) == X_STATUS_INVALID_HANDLE,
        "new HLE wait on closed handle correctly fails");
  retained.reset(); waiter.reset(); memory->SystemHeapFree(guest_address);
}
static void RunReleaseFailure(KernelState* kernel, CaptureSink& sink) {
  auto* memory = kernel->memory();
  const auto guest_address = memory->SystemHeapAlloc(4096);
  Check(guest_address != 0, "actual guest allocation");
  Check(Invoke(__imp__NtCreateSemaphore, {guest_address, 0, 1, 1}) == X_STATUS_SUCCESS,
        "real NtCreateSemaphore full count, limit1");
  const auto handle = ReadGuest(memory, guest_address);
  auto retained = kernel->object_table()->LookupObject<XSemaphore>(handle);
  Check(bool(retained), "retain actual full HLE-created semaphore");
  Check(cvar::SetFlagFromCommandLine("guest_wait_trace_handle", std::to_string(handle)),
        "actual trace cvar selects release-failure handle");
  Check(cvar::SetFlagFromCommandLine("guest_wait_trace_delay_ms", "0"), "actual zero-delay cvar");
  auto native = rex::thread::Semaphore::Create(1, 1);
  Check(bool(native), "actual underlying native full semaphore creation");
  int native_previous = 765;
  Check(!native->Release(1, &native_previous), "actual underlying native full-semaphore release fails");
  Check(native_previous == 765, "failed underlying native release leaves previous-count output untouched");
  Check(rex::thread::Wait(native.get(), false, 0ms) == rex::thread::WaitResult::kSuccess,
        "failed underlying native release preserves original token");
  Check(rex::thread::Wait(native.get(), false, 0ms) == rex::thread::WaitResult::kTimeout,
        "failed underlying native release adds no token");
  int32_t wrapper_previous = 765;
  Check(!retained->ReleaseSemaphore(1, &wrapper_previous), "actual XSemaphore full release fails");
  Check(wrapper_previous == 0, "existing XSemaphore failure output policy remains zero");
  *memory->TranslateVirtual<be<uint32_t>*>(guest_address + 4) = 0xDEADBEEF;
  Check(Invoke(__imp__NtReleaseSemaphore, {handle, 1, guest_address + 4}) ==
        X_STATUS_SEMAPHORE_LIMIT_EXCEEDED, "actual HLE full-semaphore release fails");
  Check(ReadGuest(memory, guest_address + 4) == 0,
        "existing HLE failure output policy remains zero, distinct from diagnostic sentinel");
  FlushLogging();
  const auto lines = sink.Snapshot();
  { std::ofstream output("artifacts/release-failure-trace.log");
    for (const auto& line : lines) output << line << '\n'; }
  bool failure_observed = false;
  for (const auto& line : lines) {
    if (line.find(HexHandle(handle)) != std::string::npos &&
        line.find("op=semaphore_release value1=-1 value2=1 ") != std::string::npos &&
        line.find(fmt::format("status={:08X}", X_STATUS_SEMAPHORE_LIMIT_EXCEEDED)) != std::string::npos)
      failure_observed = true;
  }
  Check(failure_observed, "failed HLE release trace carries unknown previous-count sentinel and real status");
  uint64_t immediate = 0;
  Check(retained->Wait(3, 1, 0, &immediate) == X_STATUS_SUCCESS,
        "failed releases leave original token available");
  Check(retained->Wait(3, 1, 0, &immediate) == X_STATUS_TIMEOUT,
        "failed releases do not add a token");
  Check(Invoke(__imp__NtClose, {handle}) == X_STATUS_SUCCESS, "close release-failure semaphore");
  Check(retained->handles().empty(), "release-failure retained object has no remaining handles");
  retained.reset(); memory->SystemHeapFree(guest_address);
}
int main(int argc, char** argv) {
  if (argc != 2) { std::cerr << "use alias-on, alias-off, last-on, last-off, or release-failure\n"; return 2; }
  const std::string mode = argv[1];
  const bool enabled = mode == "alias-on" || mode == "last-on";
  const bool alias = mode == "alias-on" || mode == "alias-off";
  if (!enabled && mode != "alias-off" && mode != "last-off" && mode != "release-failure") return 2;
  InitLogging(); auto sink = std::make_shared<CaptureSink>(); AddSink(sink);
  Runtime runtime(""); RuntimeConfig config; config.tool_mode = true;
  if (runtime.Setup(std::move(config))) return 3;
  int result = 0;
  auto controller = object_ref<XHostThread>(new XHostThread(runtime.kernel_state(), 128 * 1024, 0, [&] {
    try {
      if (mode == "release-failure") RunReleaseFailure(runtime.kernel_state(), *sink);
      else Run(runtime.kernel_state(), *sink, enabled, alias);
    }
    catch (const std::exception& error) { std::cerr << "FAIL " << mode << " after " << checks << ": " << error.what() << '\n'; result = 1; }
    return result;
  }));
  if (controller->Create() != X_STATUS_SUCCESS) return 4;
  controller->Wait(0, 0, 0, nullptr); controller.reset(); runtime.Shutdown();
  if (!result) std::cout << "PASS " << mode << ' ' << checks << " actual Runtime/HLE checks\n";
  return result;
}
