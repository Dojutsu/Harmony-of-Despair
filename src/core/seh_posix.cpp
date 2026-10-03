/**
 * @file        core/seh_posix.cpp
 * @brief       POSIX platform SEH implementations
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 * @license     BSD 3-Clause License
 */

#include <rex/platform.h>
#include <rex/platform/seh.h>

static_assert(REX_PLATFORM_LINUX || REX_PLATFORM_MAC, "This file is POSIX-only");

#include <signal.h>
#include <cstdlib>  // std::abort()
#include <initializer_list>

#include <rex/platform/exceptions.h>

#if REX_PLATFORM_LINUX
#include "signal_posix.h"
#endif

namespace rex::platform {

static thread_local SehThreadState tls_seh_state;
static thread_local bool tls_seh_active = false;
#if REX_PLATFORM_LINUX
static struct sigaction previous_handlers[NSIG] {};
#endif

SehThreadState& seh_thread_state() {
  return tls_seh_state;
}

int seh_filter(uint32_t /*code*/, void* /*ep*/) {
  // Not used on POSIX - signal handlers throw directly
  return 0;
}

/// Signal handler for SIGSEGV/SIGBUS/SIGFPE/SIGILL
static void signal_handler(int sig, siginfo_t* info, void* ucontext) {
  // Only handle if we're in SEH-protected code
  if (!tls_seh_active) {
#if REX_PLATFORM_LINUX
    ForwardSignal(sig, info, ucontext, previous_handlers[sig]);
#else
    signal(sig, SIG_DFL);
    raise(sig);
#endif
    return;
  }

  // Determine exception code based on signal
  SehException::Code code;
  switch (sig) {
    case SIGSEGV:
      code = SehException::ACCESS_VIOLATION;
      break;
    case SIGBUS:
      code = SehException::IN_PAGE_ERROR;
      break;
    case SIGFPE:
      code = SehException::FLOAT_DIVIDE_BY_ZERO;
      break;
    case SIGILL:
      code = SehException::ILLEGAL_INSTRUCTION;
      break;
    default:
      code = SehException::UNKNOWN;
      break;
  }

  // Get fault address
  uintptr_t address = info ? reinterpret_cast<uintptr_t>(info->si_addr) : 0;

  // Store in thread state for potential rethrow
  tls_seh_state.code = static_cast<uint32_t>(code);
  tls_seh_state.info[0] = 0;
  tls_seh_state.info[1] = address;

  // Existing guest SEH translation requires compiler support for unwinding
  // from the faulting instruction, not merely signal-frame unwind metadata.
  // Native startup probes must not assume this is a safe general fault escape.
  throw SehException(code, address);
}

[[noreturn]] void seh_rethrow() {
  // Map stored code back to signal and re-raise
  uint32_t code = tls_seh_state.code;
  int sig;
  switch (code) {
    case SehException::ACCESS_VIOLATION:
      sig = SIGSEGV;
      break;
    case SehException::IN_PAGE_ERROR:
      sig = SIGBUS;
      break;
    case SehException::FLOAT_DIVIDE_BY_ZERO:
    case SehException::INTEGER_DIVIDE_BY_ZERO:
      sig = SIGFPE;
      break;
    case SehException::ILLEGAL_INSTRUCTION:
      sig = SIGILL;
      break;
    default:
      abort();
  }
  // Restore default handler and re-raise
  signal(sig, SIG_DFL);
  raise(sig);
  abort();  // Should not reach here
}

void seh_initialize() {
  if (g_seh_initialized.exchange(true)) {
    return;  // Already initialized
  }

  struct sigaction sa {};
  sa.sa_sigaction = signal_handler;
  sigemptyset(&sa.sa_mask);
#if REX_PLATFORM_LINUX
  sa.sa_flags = SA_SIGINFO;
  for (int sig : {SIGSEGV, SIGBUS, SIGFPE, SIGILL}) {
    if (sigaction(sig, &sa, &previous_handlers[sig]) != 0) {
      std::abort();
    }
  }
#else
  sa.sa_flags = SA_SIGINFO | SA_NODEFER;
  sigaction(SIGSEGV, &sa, nullptr);
  sigaction(SIGBUS, &sa, nullptr);
  sigaction(SIGFPE, &sa, nullptr);
  sigaction(SIGILL, &sa, nullptr);
#endif
}

bool& seh_active() {
  return tls_seh_active;
}

}  // namespace rex::platform
