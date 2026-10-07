#pragma once

#include <rex/platform.h>
#include <rex/platform/guest_fault_state.h>

#if REX_PLATFORM_GNU_LINUX
#include <signal.h>
#include <cstdlib>

namespace rex::guest::detail {
// The startup-loaded runtime owns one preinitialized TLS state. These private
// declarations share its identity across runtime translation units; constinit
// avoids an extern TLS initialization thunk on every checked access. No owner
// or phase value is cached across an operation or callback.
extern thread_local constinit ExecutionActivation* current_activation
    __attribute__((visibility("hidden"), tls_model("initial-exec")));
extern thread_local constinit volatile sig_atomic_t signal_depth
    __attribute__((visibility("hidden"), tls_model("initial-exec")));

__attribute__((visibility("hidden")))
inline ExecutionActivation* CurrentAccessState() noexcept {
  if (signal_depth) std::_Exit(139);
  return current_activation;
}

// Canonical normal-context admission for both the exported API and private
// runtime consumers. Keep signal, owner, phase and pending checks in order.
__attribute__((visibility("hidden")))
inline ExecutionActivation* CheckedAccessState(bool required) noexcept {
  auto* owner = CurrentAccessState();
  if (!owner) {
    if (required) FaultContractFailure("guest-access-without-activation");
    return nullptr;
  }
  if (owner->phase() != ActivationPhase::Running)
    FaultContractFailure("guest-access-during-adjudication");
  if (owner->HasPendingFault())
    FaultContractFailure("guest-continuation-with-pending-fault");
  return owner;
}

__attribute__((visibility("hidden")))
inline void RequireAccessState() noexcept {
  (void)CheckedAccessState(true);
}
}  // namespace rex::guest::detail
#else
namespace rex::guest::detail {
inline ExecutionActivation* CurrentAccessState() noexcept {
  return ExecutionActivation::Current();
}
inline void RequireAccessState() noexcept { RequireAccess(); }
inline ExecutionActivation* CheckedAccessState(bool required) noexcept {
  if (!required) return CurrentForAccessOrNull();
  RequireAccess();
  return ExecutionActivation::Current();
}
}  // namespace rex::guest::detail
#endif
