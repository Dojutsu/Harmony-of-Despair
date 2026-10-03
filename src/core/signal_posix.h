// Linux signal forwarding shared by native fault and guest SEH handlers.
#pragma once

#include <signal.h>
#include <unistd.h>

namespace rex::platform {

// Called only when this layer does not own the fault. Keep the original
// siginfo/ucontext for another native handler, and retain fatal dispositions.
inline void ForwardSignal(int sig, siginfo_t* info, void* context,
                          struct sigaction& previous) {
  const bool synchronous_fault = info && info->si_code > 0;
  if (previous.sa_handler == SIG_DFL ||
      (previous.sa_handler == SIG_IGN && synchronous_fault)) {
    struct sigaction action {};
    action.sa_handler = SIG_DFL;
    sigemptyset(&action.sa_mask);
    if (sigaction(sig, &action, nullptr) != 0 || raise(sig) != 0) {
      _exit(128 + sig);
    }
    return;
  }
  if (previous.sa_handler == SIG_IGN) {
    return;
  }

  // Preserve one-shot host handlers even while our dispatch wrapper remains
  // installed. Subsequent unclaimed signals then use the default disposition.
  const struct sigaction action = previous;
  if (action.sa_flags & SA_RESETHAND) {
    previous.sa_handler = SIG_DFL;
    previous.sa_flags = 0;
    sigemptyset(&previous.sa_mask);
  }

  sigset_t old_mask, handler_mask;
  sigprocmask(SIG_BLOCK, &action.sa_mask, &old_mask);
  sigprocmask(SIG_SETMASK, nullptr, &handler_mask);
  if (action.sa_flags & SA_NODEFER) {
    if (!sigismember(&action.sa_mask, sig)) {
      sigdelset(&handler_mask, sig);
    }
  } else {
    sigaddset(&handler_mask, sig);
  }
  sigprocmask(SIG_SETMASK, &handler_mask, nullptr);
  if (action.sa_flags & SA_SIGINFO) {
    action.sa_sigaction(sig, info, context);
  } else {
    action.sa_handler(sig);
  }
  sigprocmask(SIG_SETMASK, &old_mask, nullptr);
}

}  // namespace rex::platform
