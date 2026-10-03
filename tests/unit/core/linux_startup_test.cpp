// Native Linux startup contracts; destructive faults run only in bounded children.
#include <rex/exception_handler.h>
#include <rex/memory/utils.h>
#include <rex/platform/exceptions.h>
#include <rex/platform/guest_fault_state.h>
#include <rex/thread.h>

#include <signal.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

#include <atomic>
#include <cstdio>
#include <cstring>
#include <functional>
#include <thread>

namespace {
int failures = 0;
int checks = 0;
volatile sig_atomic_t handled = 0;

void Check(bool result, const char* name) {
  ++checks;
  if (!result) ++failures;
  std::printf("{\"stage\":\"linux_startup_test\",\"check\":\"%s\",\"result\":\"%s\"}\n",
              name, result ? "PASS" : "FAIL");
}

bool Decline(rex::arch::Exception*, void*) { return false; }
void PreviousInfo(int sig, siginfo_t* info, void* context) {
  sigset_t current;
  sigprocmask(SIG_SETMASK, nullptr, &current);
  _exit(info && info->si_signo == sig && context && sigismember(&current, SIGUSR1) ? 42 : 43);
}
void PreviousSimple(int) { _exit(42); }
void PreviousOnce(int) { ++handled; }

void InstallPrevious(int sig, bool simple = false, bool once = false) {
  struct sigaction action {};
  sigemptyset(&action.sa_mask);
  sigaddset(&action.sa_mask, SIGUSR1);
  action.sa_flags = simple ? 0 : SA_SIGINFO;
  if (once) {
    action.sa_handler = PreviousOnce;
    action.sa_flags = SA_RESETHAND;
  } else if (simple) {
    action.sa_handler = PreviousSimple;
  } else {
    action.sa_sigaction = PreviousInfo;
  }
  if (sigaction(sig, &action, nullptr) != 0) _exit(44);
}

void Child(const char* name, const std::function<void()>& test,
           int expected_signal = 0, int expected_exit = 0) {
  std::fflush(nullptr);
  pid_t child = fork();
  if (child == 0) {
    struct rlimit no_core {0, 0};
    setrlimit(RLIMIT_CORE, &no_core);
    alarm(3);
    test();
    _exit(0);
  }
  if (child < 0) {
    Check(false, name);
    return;
  }
  int status = 0;
  if (waitpid(child, &status, 0) != child) {
    Check(false, name);
    return;
  }
  bool result = expected_signal ? WIFSIGNALED(status) && WTERMSIG(status) == expected_signal
                                : WIFEXITED(status) && WEXITSTATUS(status) == expected_exit;
  Check(result, name);
  if (!result) {
    std::printf("{\"check\":\"%s\",\"exit\":%d,\"signal\":%d}\n", name,
                WIFEXITED(status) ? WEXITSTATUS(status) : -1,
                WIFSIGNALED(status) ? WTERMSIG(status) : 0);
  }
}

struct Recovery {
  void* address;
  volatile sig_atomic_t seen = 0;
};
bool RecoverRead(rex::arch::Exception* ex, void* data) {
  auto* recovery = static_cast<Recovery*>(data);
  if (ex->code() != rex::arch::Exception::Code::kAccessViolation ||
      ex->fault_address() != reinterpret_cast<uintptr_t>(recovery->address) ||
      ex->access_violation_operation() !=
          rex::arch::Exception::AccessViolationOperation::kRead) return false;
  const auto* activation = rex::guest::ExecutionActivation::Current();
  if (!activation || activation->phase() != rex::guest::ActivationPhase::Adjudicating ||
      rex::guest::HasArmedAccessFrame()) return false;
  ++recovery->seen;
  // The registered byte-read leaf's MOV DL,[RDI] is two bytes. This is a
  // normal-context synthetic continuation, not a signal-handler PC rewrite.
  ex->set_resume_pc(ex->pc() + 2);
  return true;
}

void Signals() {
  const int signals[] = {SIGSEGV, SIGBUS, SIGILL, SIGFPE};
  const char* default_names[] = {"default_segv", "default_bus", "default_ill", "default_fpe"};
  const char* previous_names[] = {"previous_segv", "previous_bus", "previous_ill", "previous_fpe"};
  for (int i = 0; i != 4; ++i) {
    int sig = signals[i];
    Child(default_names[i], [sig] { rex::initialize_seh(); raise(sig); }, sig);
    Child(previous_names[i], [sig] {
      InstallPrevious(sig);
      rex::initialize_seh();
      raise(sig);
    }, 0, 42);
  }
  Child("arch_declines_segv", [] {
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    raise(SIGSEGV);
  }, SIGSEGV);
  Child("arch_declines_ill", [] {
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    raise(SIGILL);
  }, SIGILL);
  Child("arch_preserves_prior", [] {
    InstallPrevious(SIGSEGV);
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    raise(SIGSEGV);
  }, 0, 42);
  Child("seh_preserves_simple_prior", [] {
    InstallPrevious(SIGFPE, true);
    rex::initialize_seh();
    raise(SIGFPE);
  }, 0, 42);
  Child("preserves_explicit_ignore_for_raised_signal", [] {
    signal(SIGILL, SIG_IGN);
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    raise(SIGILL);
  });
  Child("preserves_one_shot_prior", [] {
    InstallPrevious(SIGILL, false, true);
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    raise(SIGILL);
    if (handled != 1) _exit(45);
    raise(SIGILL);
  }, SIGILL);
  Child("uninstall_restores_seh_chain", [] {
    InstallPrevious(SIGSEGV);
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    rex::arch::ExceptionHandler::Uninstall(Decline, nullptr);
    raise(SIGSEGV);
  }, 0, 42);
  Child("real_unclaimed_page_fault", [] {
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    void* page = mmap(nullptr, 4096, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (page == MAP_FAILED) _exit(46);
    *static_cast<volatile char*>(page) = 1;
  }, SIGSEGV);
  Child("real_bus_fault", [] {
    rex::initialize_seh();
    int fd = memfd_create("rex-startup-bus", MFD_CLOEXEC);
    if (fd == -1) _exit(46);
    void* page = mmap(nullptr, 4096, PROT_READ, MAP_SHARED, fd, 0);
    if (page == MAP_FAILED) _exit(46);
    (void)*static_cast<volatile char*>(page);
  }, SIGBUS);
  Child("real_illegal_instruction", [] {
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    asm volatile("ud2");
  }, SIGILL);
  Child("real_integer_divide_fault", [] {
    rex::initialize_seh();
    asm volatile("movl $1, %%eax; xorl %%edx, %%edx; xorl %%ecx, %%ecx; divl %%ecx"
                 : : : "eax", "edx", "ecx");
  }, SIGFPE);
  Child("owned_fault_updates_resume_context", [] {
    using namespace rex::memory;
    const size_t size = page_size();
    void* guard = AllocFixed(nullptr, size, AllocationType::kReserve, PageAccess::kNoAccess);
    if (!guard) _exit(46);
    Recovery recovery {guard};
    rex::guest::ExecutionActivation activation;
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(RecoverRead, &recovery);
    unsigned char output = 0xA5;
    rex::guest::RequireAccess();
    auto captured = rex::guest::CaptureRead(guard, &output, sizeof(output));
    // Capture must return through the same leaf, without committing a failed
    // read or invoking a rich callback from signal context.
    if (captured.success || captured.completed != 0 || output != 0xA5 || recovery.seen != 0 ||
        captured.fault.signal_number != SIGSEGV || captured.fault.signal_code != SEGV_ACCERR ||
        captured.fault.access_intent != 0 ||
        captured.fault.address != reinterpret_cast<uintptr_t>(guard) ||
        !captured.fault.instruction_pointer || rex::guest::HasArmedAccessFrame()) _exit(47);
    rex::arch::HostThreadContext context{};
    context.rip = captured.fault.instruction_pointer;
    context.eflags = captured.fault.flags;
    for (unsigned index = 0; index != 16; ++index)
      context.int_registers[index] = captured.fault.integer_registers[index];
    std::memcpy(context.xmm_registers, captured.fault.xmm_registers,
                sizeof(captured.fault.xmm_registers));
    rex::arch::Exception exception;
    exception.InitializeAccessViolation(&context, captured.fault.address,
        rex::arch::Exception::AccessViolationOperation::kRead);
    bool completed = false;
    {
      rex::guest::AdjudicationScope adjudication(captured.fault);
      completed = rex::arch::ExceptionHandler::DispatchDeferred(&exception);
    }
    rex::arch::ExceptionHandler::Uninstall(RecoverRead, &recovery);
    if (!completed || recovery.seen != 1 ||
        context.rip != captured.fault.instruction_pointer + 2 ||
        exception.modified_int_registers() || exception.modified_xmm_registers() ||
        activation.phase() != rex::guest::ActivationPhase::Running ||
        activation.HasPendingFault() || rex::guest::HasArmedAccessFrame()) _exit(47);
    if (!DeallocFixed(guard, size, DeallocationType::kRelease)) _exit(48);
  });
  Child("execute_without_exec_protection_is_fatal", [] {
    using namespace rex::memory;
    void* code = AllocFixed(nullptr, page_size(), AllocationType::kReserveCommit,
                           PageAccess::kReadWrite);
    if (!code) _exit(46);
    *static_cast<unsigned char*>(code) = 0xc3;
    rex::initialize_seh();
    rex::arch::ExceptionHandler::Install(Decline, nullptr);
    reinterpret_cast<void (*)()>(code)();
  }, SIGSEGV);
}

void VirtualMemory() {
  using namespace rex::memory;
  const size_t size = page_size();
  void* page = AllocFixed(nullptr, 3 * size, AllocationType::kReserve, PageAccess::kNoAccess);
  Check(page != nullptr && reinterpret_cast<uintptr_t>(page) % size == 0, "page_aligned_reservation");
  if (!page) return;
  size_t length = 0;
  PageAccess access;
  Check(QueryProtect(page, length, access) && length >= 3 * size && access == PageAccess::kNoAccess,
        "reservation_has_no_access");
  auto* committed = static_cast<unsigned char*>(page) + size;
  Check(AllocFixed(committed, size, AllocationType::kCommit, PageAccess::kReadWrite) == committed,
        "commit_preserves_reservation_address");
  const unsigned char instructions[] = {0xb8, 0x07, 0, 0, 0, 0xc3};
  std::memcpy(committed, instructions, sizeof(instructions));
  Check(QueryProtect(committed, length, access) && access == PageAccess::kReadWrite,
        "committed_page_rw_without_execute");
  PageAccess old_access;
  bool executable = Protect(committed, size, PageAccess::kExecuteReadOnly, &old_access);
  Check(executable && old_access == PageAccess::kReadWrite, "rw_to_rx_transition");
  Check(QueryProtect(committed, length, access) && access == PageAccess::kExecuteReadOnly,
        "executable_page_is_not_writable");
  if (executable) Check(reinterpret_cast<int (*)()>(committed)() == 7, "native_rx_code_executes");
  Check(QueryProtect(page, length, access) && access == PageAccess::kNoAccess,
        "adjacent_guard_page_stays_protected");
  Check(DeallocFixed(committed, size, DeallocationType::kDecommit), "decommit_succeeds");
  Check(QueryProtect(committed, length, access) && access == PageAccess::kNoAccess,
        "decommit_removes_access");
  Check(AllocFixed(committed, size, AllocationType::kCommit, PageAccess::kReadWrite) == committed,
        "recommit_same_page");
  Check(*committed == 0, "decommitted_anonymous_contents_discarded");
  Check(DeallocFixed(page, 3 * size, DeallocationType::kRelease), "release_reservation");
}

void ThreadLocalState() {
  using namespace rex;
  auto key = thread::AllocateTlsHandle();
  Check(key != thread::kInvalidTlsHandle && thread::GetTlsValue(key) == 0, "tls_slot_initializes_zero");
  Check(thread::SetTlsValue(key, 11), "tls_main_thread_value_set");
  initialize_seh_thread();
  platform::seh_thread_state().code = 123;
  bool child_ok = false;
  std::atomic<int> destructed = 0;
  std::thread worker([&] {
    struct OnExit { std::atomic<int>* count; ~OnExit() { ++*count; } };
    thread_local OnExit cleanup {&destructed};
    (void)cleanup;
    initialize_seh_thread();
    child_ok = thread::GetTlsValue(key) == 0 && !platform::seh_active() &&
               platform::seh_thread_state().code == 0 && thread::SetTlsValue(key, 22);
    {
      SehGuard outer;
      { SehGuard inner; child_ok = child_ok && platform::seh_active(); }
      child_ok = child_ok && platform::seh_active();
    }
    child_ok = child_ok && !platform::seh_active() && thread::GetTlsValue(key) == 22;
  });
  worker.join();
  Check(child_ok, "tls_and_nested_seh_guard_isolated_per_thread");
  Check(thread::GetTlsValue(key) == 11 && platform::seh_thread_state().code == 123 &&
        !platform::seh_active(), "main_thread_state_unchanged_after_worker");
  Check(destructed == 1, "native_thread_local_destructor_runs_on_exit");
  Check(thread::FreeTlsHandle(key), "tls_slot_released");
  bool caught = false;
  try { throw SehException(SehException::ACCESS_VIOLATION, 1234); }
  catch (const SehException& exception) { caught = exception.address() == 1234; }
  Check(caught, "ordinary_cpp_exception_unwind");
}
}  // namespace

int main() {
  Signals();
  VirtualMemory();
  ThreadLocalState();
  std::printf("{\"stage\":\"linux_startup_test\",\"checks\":%d,\"failures\":%d}\n", checks, failures);
  return failures ? 1 : 0;
}
