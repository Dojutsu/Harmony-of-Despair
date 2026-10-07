// Real production Linux hardware-fault contracts without a test framework's
// replacement signal handler. Fatal/native cases execute in bounded children.
#include <rex/platform/guest_memory.h>
#include <rex/platform/exceptions.h>
#include <rex/platform/seh.h>

#include <signal.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <ucontext.h>
#include <unistd.h>

#include <array>
#include <atomic>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <thread>
#include <vector>

namespace {
using namespace rex::guest;
std::atomic<unsigned> checks{0}, failures{0};
size_t page_size;
// An explicit interpreter changes /proc/self/exe to the loader. The deployment
// harness supplies the same verified loader/library path for every child; the
// program argv[0] remains the actual fixture ELF. Direct CTest needs no override.
std::string child_loader, child_library_path, child_program;

void Check(bool condition, const char* name) {
  ++checks;
  if (!condition) ++failures;
  std::printf("{\"stage\":\"linux_guest_fault\",\"check\":\"%s\",\"result\":\"%s\"}\n",
              name, condition ? "PASS" : "FAIL");
}
struct Mapping {
  unsigned char* data;
  size_t size;
  explicit Mapping(size_t bytes, int protection = PROT_READ | PROT_WRITE) : size(bytes) {
    data = static_cast<unsigned char*>(
        mmap(nullptr, bytes, protection, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    if (data == MAP_FAILED) std::_Exit(90);
  }
  ~Mapping() { munmap(data, size); }
  void Protect(size_t offset, size_t bytes, int protection) {
    if (mprotect(data + offset, bytes, protection)) std::_Exit(91);
  }
};
struct Cleanup {
  explicit Cleanup(unsigned& value) : count(value) {}
  unsigned& count;
  ~Cleanup() { ++count; }
};

void CheckFault(const AccessAttempt& attempt, const void* address, unsigned intent,
                const char* name) {
  Check(!attempt.success, name);
  Check(attempt.fault.signal_number == SIGSEGV, "captured_sigsegv");
  Check(attempt.fault.signal_code == SEGV_ACCERR, "captured_accerr");
  Check(attempt.fault.address == reinterpret_cast<uintptr_t>(address), "captured_fault_address");
  Check(attempt.fault.access_intent == intent, "captured_access_intent");
  Check(bool(attempt.fault.page_fault_error & 2) == bool(intent), "reg_err_intent_matches");
  Check(!(attempt.fault.page_fault_error & 16), "data_fault_not_execute");
  Check(attempt.fault.instruction_pointer != 0, "captured_native_pc");
  Check(attempt.fault.stack_pointer == attempt.fault.integer_registers[4], "native_sp_mapping");
  Check(!HasArmedAccessFrame(), "access_frame_disarmed_after_return");
}

void ScalarAndVectorIntent() {
  Mapping inaccessible(page_size, PROT_NONE);
  for (size_t width : {1u, 2u, 4u, 8u}) {
    uint64_t output = 0xDEADBEEFCAFEBABE;
    const uint64_t payload = 0x1234567887654321;
    auto read = CaptureRead(inaccessible.data, &output, width);
    CheckFault(read, inaccessible.data, 0, "scalar_read_fault");
    Check(output == 0xDEADBEEFCAFEBABE, "failed_scalar_read_does_not_commit_output");
    Check(read.completed == 0, "failed_scalar_read_zero_progress");
    auto write = CaptureWrite(inaccessible.data, &payload, width);
    CheckFault(write, inaccessible.data, 1, "scalar_write_fault");
    const uint64_t mask = width == 8 ? ~uint64_t(0) : (uint64_t(1) << (width * 8)) - 1;
    Check((write.fault.integer_registers[2] & mask) == (payload & mask), "write_payload_register");
    Check(write.completed == 0, "failed_scalar_write_zero_progress");
  }
  alignas(16) std::array<unsigned char, 16> payload{}, output{};
  for (unsigned i = 0; i < payload.size(); ++i) payload[i] = 0x40 + i;
  output.fill(0xDD);
  auto read = CaptureVectorRead(inaccessible.data, output.data());
  CheckFault(read, inaccessible.data, 0, "simd_read_fault");
  Check(output == std::array<unsigned char, 16>{0xDD,0xDD,0xDD,0xDD,0xDD,0xDD,0xDD,0xDD,
                                               0xDD,0xDD,0xDD,0xDD,0xDD,0xDD,0xDD,0xDD},
        "failed_simd_read_does_not_commit_output");
  auto write = CaptureVectorWrite(inaccessible.data, payload.data());
  CheckFault(write, inaccessible.data, 1, "simd_write_fault");
  Check(!std::memcmp(write.fault.xmm_registers[0], payload.data(), 16), "simd_fault_payload_snapshot");
}

void Scalar64SplitFaults() {
  Mapping ram(page_size*2);
  for(unsigned first_bytes=1;first_bytes<8;++first_bytes) {
    auto* cell=ram.data+page_size-first_bytes;
    for(unsigned denied=0;denied<4;++denied) {
      bool store_ok=true,read_ok=true,sentinels_ok=true,intent_ok=true;
      for(unsigned repeat=0;repeat<100;++repeat) {
        std::memset(cell-1,0xA5,10);
        ram.Protect(0,page_size,denied&1?PROT_READ:PROT_READ|PROT_WRITE);
        ram.Protect(page_size,page_size,denied&2?PROT_READ:PROT_READ|PROT_WRITE);
        uint64_t payload=0x00001A3E0080503FULL;
        auto write=CaptureWrite(cell,&payload,8);
        intent_ok &= write.success || write.fault.access_intent==1;
        ram.Protect(0,ram.size,PROT_READ|PROT_WRITE);
        store_ok &= write.success==(denied==0);
        store_ok &= !std::memcmp(cell,denied?"\xA5\xA5\xA5\xA5\xA5\xA5\xA5\xA5":"\x3F\x50\x80\x00\x3E\x1A\x00\x00",8);
        sentinels_ok &= cell[-1]==0xA5 && cell[8]==0xA5;
        ram.Protect(0,page_size,denied&1?PROT_NONE:PROT_READ|PROT_WRITE);
        ram.Protect(page_size,page_size,denied&2?PROT_NONE:PROT_READ|PROT_WRITE);
        uint64_t output=0xDEADBEEFCAFEBABEULL;
        auto read=CaptureRead(cell,&output,8);
        read_ok &= read.success==(denied==0);
        read_ok &= output==(denied?0xDEADBEEFCAFEBABEULL:payload);
        intent_ok &= read.success || read.fault.access_intent==0;
        ram.Protect(0,ram.size,PROT_READ|PROT_WRITE);
      }
      Check(store_ok,"split_movq_store_single_commit_or_unchanged");
      Check(read_ok,"split_movq_read_staged_output");
      Check(sentinels_ok,"split_movq_surrounding_bytes_unchanged");
      Check(intent_ok,"split_movq_fault_intent");
      Check(!HasArmedAccessFrame(),"split_movq_access_frame_disarmed");
    }
  }
}

void AtomicIntentAndCompletion() {
  Mapping ram(page_size);
  auto* value64 = reinterpret_cast<uint64_t*>(ram.data);
  *value64 = 0;
  ram.Protect(0, page_size, PROT_READ);
  uint64_t previous64 = 0xBADF00D;
  auto fault64 = CaptureCompareExchange64(value64, 0, 1, &previous64);
  CheckFault(fault64, value64, 1, "atomic64_fault_is_write");
  Check(*value64 == 0 && previous64 == 0xBADF00D, "faulting_atomic64_not_committed");
  ram.Protect(0, page_size, PROT_READ | PROT_WRITE);
  auto complete64 = CaptureCompareExchange64(value64, 0, 1, &previous64);
  Check(complete64.success && previous64 == 0 && *value64 == 1, "atomic64_retry_exactly_once");
  auto mismatch64 = CaptureCompareExchange64(value64, 0, 2, &previous64);
  Check(mismatch64.success && previous64 == 1 && *value64 == 1, "atomic64_mismatch_not_fault");
  auto* value32 = reinterpret_cast<uint32_t*>(ram.data + 16);
  *value32 = 0;
  ram.Protect(0, page_size, PROT_READ);
  uint32_t previous32 = 0xDEADBEEF;
  auto fault32 = CaptureCompareExchange32(value32, 0, 1, &previous32);
  CheckFault(fault32, value32, 1, "atomic32_fault_is_write");
  Check(*value32 == 0 && previous32 == 0xDEADBEEF, "faulting_atomic32_not_committed");
  ram.Protect(0, page_size, PROT_READ | PROT_WRITE);
  auto complete32 = CaptureCompareExchange32(value32, 0, 1, &previous32);
  Check(complete32.success && previous32 == 0 && *value32 == 1, "atomic32_retry_exactly_once");
}

void BulkProgress(bool write_fault) {
  Mapping source(page_size * 2), destination(page_size * 2);
  for (size_t i = 0; i < source.size; ++i) source.data[i] = static_cast<unsigned char>(i * 17 + 3);
  std::memset(destination.data, 0xCC, destination.size);
  if (write_fault) destination.Protect(page_size, page_size, PROT_READ);
  else source.Protect(page_size, page_size, PROT_NONE);
  auto attempt = CaptureCopy(destination.data, source.data, source.size);
  CheckFault(attempt, (write_fault ? destination.data : source.data) + page_size,
             write_fault ? 1 : 0, "bulk_fault_classified");
  Check(attempt.completed == page_size, "bulk_completed_prefix_retained");
  Check(attempt.fault.integer_registers[1] == page_size, "rep_rcx_remaining");
  Check(attempt.fault.integer_registers[6] == reinterpret_cast<uintptr_t>(source.data + page_size),
        "rep_rsi_remaining_source");
  Check(attempt.fault.integer_registers[7] == reinterpret_cast<uintptr_t>(destination.data + page_size),
        "rep_rdi_remaining_destination");
  Check(!std::memcmp(destination.data, source.data, page_size), "bulk_prefix_completed_before_fault");
  if (write_fault) {
    // Any whole-copy replay now faults in the already completed prefix.
    destination.Protect(0, page_size, PROT_READ);
    destination.Protect(page_size, page_size, PROT_READ | PROT_WRITE);
  } else {
    source.Protect(0, page_size, PROT_NONE);
    source.Protect(page_size, page_size, PROT_READ | PROT_WRITE);
  }
  auto remainder = CaptureCopy(destination.data + attempt.completed,
                               source.data + attempt.completed, source.size - attempt.completed);
  Check(remainder.success && remainder.completed == page_size, "bulk_only_unfinished_suffix_retried");
  source.Protect(0, page_size * 2, PROT_READ | PROT_WRITE);
  destination.Protect(0, page_size * 2, PROT_READ | PROT_WRITE);
  Check(!std::memcmp(destination.data, source.data, source.size), "bulk_final_contents_exact");
  Check(!HasArmedAccessFrame(), "bulk_access_frame_clean");
}

AccessResult<uint32_t> FaultingGateway(void* address, unsigned depth, unsigned& cleanup) noexcept {
  GatewayScope gateway;
  Cleanup resource(cleanup);
  auto heap = std::make_unique<Cleanup>(cleanup);
  if (depth) return FaultingGateway(address, depth - 1, cleanup).Forward();
  auto write = TryWrite<uint32_t>(address, 0x12345678);
  if (write.Failed()) return write.Forward<uint32_t>();
  return AccessResult<uint32_t>::Success(0x12345678);
}
struct CallbackContext {
  void* address;
  FaultToken token{};
  unsigned cleanup = 0;
  uint32_t output = 0xCAFEBABE;
};
extern "C" void RawGateway(void* opaque) noexcept {
  auto& context = *static_cast<CallbackContext*>(opaque);
  GatewayScope gateway;
  Cleanup resource(context.cleanup);
  auto result = FaultingGateway(context.address, 2, context.cleanup);
  if (result.Failed()) {
    context.token = result.Fault();
    return;
  }
  context.output = result.Value();
}
void GuestTerminalAndCleanup() {
  Mapping inaccessible(page_size, PROT_NONE);
  ExecutionActivation owner;
  rex::SehGuard protected_scope;
  CallbackContext context{inaccessible.data};
  RawGateway(&context);
  Check(context.cleanup == 7, "raw_noexcept_gateway_cleanup_exactly_once");
  Check(context.output == 0xCAFEBABE, "raw_noexcept_return_output_not_committed");
  Check(owner.gateway_depth() == 0, "raw_noexcept_gateway_returned_before_delivery");
  Check(owner.HasPendingFault() && owner.published_faults() == 1, "hardware_fault_published_once");
  Check(owner.PendingFault().access_intent == 1, "hardware_write_pending_intent");
  unsigned normal_cleanup = 0, handled = 0;
  try {
    Cleanup boundary(normal_cleanup);
    DeliverFault(context.token);
    Check(false, "hardware_write_delivery_expected_exception");
  } catch (const rex::SehException& exception) {
    ++handled;
    Check(exception.code() == rex::SehException::ACCESS_VIOLATION, "guest_av_code_preserved");
    Check(exception.address() == reinterpret_cast<uintptr_t>(inaccessible.data), "guest_av_address_preserved");
  }
  Check(handled == 1 && normal_cleanup == 1, "guest_handler_and_cpp_unwind_once");
  Check(!owner.HasPendingFault() && owner.consumed_faults() == 1, "guest_fault_consumed_once");
  Check(rex::platform::seh_thread_state().info[0] == 1, "guest_write_intent_delivery");
  auto read = TryRead<uint32_t>(inaccessible.data);
  Check(read.Failed(), "hardware_guest_read_tagged_failure");
  try { ValueOrThrow(std::move(read)); }
  catch (const rex::SehException&) { ++handled; }
  Check(handled == 2 && owner.published_faults() == 2 && owner.consumed_faults() == 2,
        "read_fault_delivered_once");
  Check(rex::platform::seh_thread_state().info[0] == 0, "guest_read_intent_delivery");
  Check(!owner.HasPendingFault() && !HasArmedAccessFrame(), "terminal_fault_owner_and_leaf_clean");
}

void HardwareTlsIsolation() {
  Mapping inaccessible(page_size, PROT_NONE);
  std::atomic<unsigned> errors{0}, completed{0};
  std::vector<std::thread> threads;
  for (unsigned index = 0; index < 4; ++index) threads.emplace_back([&, index] {
    for (unsigned iteration = 0; iteration < 4; ++iteration) {
      ExecutionActivation owner;
      unsigned handled = 0;
      try {
        if (index & 1) Write<uint32_t>(inaccessible.data, 0xDD);
        else (void)Read<uint32_t>(inaccessible.data);
      } catch (const rex::SehException& exception) {
        ++handled;
        if (exception.address() != reinterpret_cast<uintptr_t>(inaccessible.data) ||
            rex::platform::seh_thread_state().info[0] != (index & 1)) ++errors;
      }
      if (handled != 1 || owner.HasPendingFault() || owner.consumed_faults() != 1 ||
          owner.published_faults() != 1 || HasArmedAccessFrame()) ++errors;
      ++completed;
    }
    if (ExecutionActivation::Current()) ++errors;
  });
  for (auto& thread : threads) thread.join();
  Check(completed == 16 && errors == 0, "hardware_fault_tls_thread_isolation");
  Check(ExecutionActivation::Current() == nullptr, "hardware_threads_leave_no_parent_owner");
}

volatile uintptr_t expected_address = 0;
volatile sig_atomic_t expected_intent = 0;
volatile unsigned char* expected_prefix = nullptr;
volatile uint64_t* completed_atomic = nullptr;
void* prior_read_address = nullptr;
FaultToken prior_delivery_token;
void Prior(int sig, siginfo_t* info, void* raw) {
  auto* context = static_cast<ucontext_t*>(raw);
  bool valid = sig == SIGSEGV && info && context && info->si_code == SEGV_ACCERR &&
      reinterpret_cast<uintptr_t>(info->si_addr) == expected_address &&
      bool(context->uc_mcontext.gregs[REG_ERR] & 2) == bool(expected_intent);
  if (expected_prefix) for (unsigned i = 0; i < 16; ++i) valid &= expected_prefix[i] == 0x5A;
  if (completed_atomic) valid &= *completed_atomic == 1;
  constexpr char event[] = "{\"event\":\"native-prior-chain\"}\n";
  write(STDOUT_FILENO, event, sizeof(event) - 1);
  _exit(valid ? 77 : 78);
}
void PriorCheckedReentry(int, siginfo_t*, void*) {
  constexpr char event[] = "{\"event\":\"prior-checked-reentry\"}\n";
  write(STDOUT_FILENO, event, sizeof(event) - 1);
  auto result = TryRead<uint32_t>(prior_read_address);
  (void)result;
  _exit(79);
}
void PriorLowReentry(int, siginfo_t*, void*) {
  uint32_t output = 0;
  (void)CaptureRead(prior_read_address, &output, sizeof(output));
  _exit(79);
}
void PriorLowZeroReentry(int, siginfo_t*, void*) {
  (void)CaptureCopy(nullptr, nullptr, 0);
  _exit(79);
}
void PriorDelivery(int, siginfo_t*, void*) { DeliverFault(prior_delivery_token); }
void InstallPrior(void (*handler)(int, siginfo_t*, void*)) {
  struct sigaction action{};
  sigemptyset(&action.sa_mask);
  action.sa_flags = SA_SIGINFO;
  action.sa_sigaction = handler;
  if (sigaction(SIGSEGV, &action, nullptr)) std::_Exit(92);
}

int ChildMode(const std::string& mode) {
  Mapping ram(page_size * 2), inaccessible(page_size, PROT_NONE);
  expected_address = reinterpret_cast<uintptr_t>(inaccessible.data);
  expected_intent = 1;
  if (mode == "default-native") {
    rex::initialize_seh();
    rex::SehGuard legacy_scope;
    *static_cast<volatile unsigned char*>(inaccessible.data) = 1;
  } else if (mode == "prior-checked" || mode == "prior-low" || mode == "prior-low-zero" ||
             mode == "prior-delivery") {
    InstallPrior(mode == "prior-checked" ? PriorCheckedReentry :
                 mode == "prior-low" ? PriorLowReentry :
                 mode == "prior-low-zero" ? PriorLowZeroReentry : PriorDelivery);
    rex::initialize_seh();
    ExecutionActivation owner;
    prior_read_address = ram.data;
    if (mode == "prior-delivery") {
      CapturedFault record{};
      record.address = expected_address;
      prior_delivery_token = owner.Publish(record);
    }
    *static_cast<volatile unsigned char*>(inaccessible.data) = 1;
  } else if (mode == "adjudication-low" || mode == "adjudication-low-zero") {
    rex::initialize_seh();
    ExecutionActivation owner;
    CapturedFault original{};
    original.address = expected_address;
    AdjudicationScope scope(original);
    if (mode == "adjudication-low-zero") {
      (void)CaptureCopy(nullptr, nullptr, 0);
    } else {
      uint32_t output;
      (void)CaptureRead(ram.data, &output, sizeof(output));
    }
  } else {
    InstallPrior(Prior);
    rex::initialize_seh();
    if (mode == "native-prior") {
      *static_cast<volatile unsigned char*>(inaccessible.data) = 1;
    } else if (mode == "host-read-output") {
      CaptureRead(ram.data, inaccessible.data, 4);
    } else if (mode == "host-write-payload") {
      expected_intent = 0;
      CaptureWrite(ram.data, inaccessible.data, 4);
    } else if (mode == "host-vector-output") {
      CaptureVectorRead(ram.data, inaccessible.data);
    } else if (mode == "host-vector-payload") {
      expected_intent = 0;
      CaptureVectorWrite(ram.data, inaccessible.data);
    } else if (mode == "host-cas-output") {
      completed_atomic = reinterpret_cast<uint64_t*>(ram.data);
      CaptureCompareExchange64(ram.data, 0, 1, reinterpret_cast<uint64_t*>(inaccessible.data));
    } else if (mode == "bulk-host-source" || mode == "bulk-host-destination") {
      Mapping source(page_size * 2), destination(page_size * 2);
      std::memset(source.data, 0x5A, source.size);
      expected_prefix = destination.data;
      if (mode == "bulk-host-source") {
        source.Protect(page_size, page_size, PROT_NONE);
        expected_intent = 0;
        expected_address = reinterpret_cast<uintptr_t>(source.data + page_size);
        CaptureCopy(destination.data, source.data, source.size, CopyEndpoints::kDestination);
      } else {
        destination.Protect(page_size, page_size, PROT_NONE);
        expected_address = reinterpret_cast<uintptr_t>(destination.data + page_size);
        CaptureCopy(destination.data, source.data, source.size, CopyEndpoints::kSource);
      }
    } else return 93;
  }
  return 94;
}

void RunChild(const char* executable, const char* mode, int expected_exit, int expected_signal = 0) {
  int pipe_fds[2];
  if (pipe(pipe_fds)) std::_Exit(95);
  std::fflush(nullptr);
  const pid_t child = fork();
  if (!child) {
    close(pipe_fds[0]);
    dup2(pipe_fds[1], STDERR_FILENO);
    close(pipe_fds[1]);
    alarm(10);
    if (child_loader.empty()) {
      execl(executable, executable, mode, nullptr);
    } else {
      execl(child_loader.c_str(), child_loader.c_str(), "--library-path",
            child_library_path.c_str(), child_program.c_str(), mode, nullptr);
    }
    _exit(96);
  }
  close(pipe_fds[1]);
  std::string error;
  char buffer[512];
  ssize_t count;
  while ((count = read(pipe_fds[0], buffer, sizeof(buffer))) > 0) error.append(buffer, count);
  close(pipe_fds[0]);
  int status = 0;
  while (waitpid(child, &status, 0) < 0 && errno == EINTR) {}
  bool expected = expected_signal ? WIFSIGNALED(status) && WTERMSIG(status) == expected_signal
                                 : WIFEXITED(status) && WEXITSTATUS(status) == expected_exit;
  Check(expected, mode);
  Check(!WIFSIGNALED(status) || WTERMSIG(status) != SIGABRT, "child_never_aborts");
  Check(error.empty(), "child_stderr_empty");
  if (!error.empty()) {
    std::printf("{\"stage\":\"linux_guest_fault_child_stderr\",\"mode\":\"%s\",\"stderr\":\"", mode);
    for (char value : error) {
      if (value == '\n') std::printf("\\n");
      else if (value == '\r') std::printf("\\r");
      else if (value == '\t') std::printf("\\t");
      else if (value == '\"' || value == '\\') std::printf("\\%c", value);
      else std::putchar(value);
    }
    std::printf("\"}\n");
  }
  std::printf("{\"stage\":\"linux_guest_fault_child\",\"mode\":\"%s\",\"exit\":%d,\"signal\":%d}\n",
              mode, WIFEXITED(status) ? WEXITSTATUS(status) : -1,
              WIFSIGNALED(status) ? WTERMSIG(status) : 0);
}
}  // namespace

int main(int argc, char** argv) {
  const rlimit no_core{0, 0};
  setrlimit(RLIMIT_CORE, &no_core);
  page_size = static_cast<size_t>(sysconf(_SC_PAGESIZE));
  if (page_size == 0 || page_size == static_cast<size_t>(-1)) return 97;
  if (argc == 2) return ChildMode(argv[1]);
  std::setvbuf(stdout, nullptr, _IONBF, 0);
  char executable[4096];
  const auto length = readlink("/proc/self/exe", executable, sizeof(executable) - 1);
  if (length <= 0) return 98;
  executable[length] = 0;
  const char* loader = std::getenv("HARMONY_TEST_ELF_LOADER");
  const char* library_path = std::getenv("HARMONY_TEST_LIBRARY_PATH");
  if (bool(loader) != bool(library_path)) {
    std::fputs("fixture child loader and library path must be configured together\n", stderr);
    return 99;
  }
  if (loader) {
    if (loader[0] != '/' || argv[0][0] != '/' || !library_path[0]) return 99;
    child_loader = loader;
    child_library_path = library_path;
    child_program = argv[0];
  }
  std::printf("{\"stage\":\"linux_guest_fault_launch\",\"child_mode\":\"%s\"}\n",
              child_loader.empty() ? "direct" : "explicit-loader");
  for (const char* mode : {"native-prior", "host-read-output", "host-write-payload", "host-vector-output",
                           "host-vector-payload", "host-cas-output", "bulk-host-source", "bulk-host-destination"})
    RunChild(executable, mode, 77);
  RunChild(executable, "default-native", 0, SIGSEGV);
  for (const char* mode : {"prior-checked", "prior-low", "prior-low-zero", "prior-delivery"})
    RunChild(executable, mode, 139);
  RunChild(executable, "adjudication-low", 86);
  RunChild(executable, "adjudication-low-zero", 86);
  rex::initialize_seh();
  ScalarAndVectorIntent();
  Scalar64SplitFaults();
  AtomicIntentAndCompletion();
  BulkProgress(false);
  BulkProgress(true);
  GuestTerminalAndCleanup();
  HardwareTlsIsolation();
  {
    ExecutionActivation owner;
    auto noop = CaptureCopy(nullptr, nullptr, 0);
    CopyBytes(nullptr, nullptr, 0);
    Check(noop.success && noop.completed == 0, "zero_length_bulk_noop");
    Check(!owner.HasPendingFault() && owner.published_faults() == 0 && !HasArmedAccessFrame(),
          "noop_has_no_fault_or_side_effect");
  }
  std::printf("{\"stage\":\"linux_guest_fault_summary\",\"checks\":%u,\"failures\":%u}\n",
              checks.load(), failures.load());
  return failures ? 1 : 0;
}
