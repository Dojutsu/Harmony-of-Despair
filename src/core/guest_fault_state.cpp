/**
 * @file core/guest_fault_state.cpp
 * @brief Normal-context guest fault ownership. No signal-handler entrypoints.
 */
#include <rex/platform/guest_fault_state.h>

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <limits>

#include <rex/platform/exceptions.h>
#include <rex/platform/seh.h>

namespace rex::guest {
namespace {
// This TLS owner is normal-context state. The signal layer has its own minimal
// preinitialized TLS frame and never calls Current() or touches this object.
// The admitted GNU/Linux runtime is linked at process startup, as required by
// the signal layer's initial-exec TLS. Preserve all normal-context ownership
// checks while avoiding a dynamic TLS lookup at every guest memory boundary.
#if REX_PLATFORM_GNU_LINUX
thread_local ExecutionActivation* current_activation
    __attribute__((tls_model("initial-exec"))) = nullptr;
#else
thread_local ExecutionActivation* current_activation = nullptr;
#endif
std::atomic<uint64_t> next_activation_id{0};
}  // namespace

[[noreturn]] void FaultContractFailure(const char* reason) noexcept {
  if (InSignalContext()) std::_Exit(139);
  const auto* owner = ExecutionActivation::Current();
  std::fprintf(stderr,
               "{\"event\":\"guest-fault-contract-failure\",\"reason\":\"%s\","
               "\"activation\":%llu,\"pending\":%s,\"gateway_depth\":%u,"
               "\"published\":%llu,\"consumed\":%llu}\n",
               reason ? reason : "unspecified", static_cast<unsigned long long>(owner ? owner->id() : 0),
               owner && owner->HasPendingFault() ? "true" : "false", owner ? owner->gateway_depth() : 0,
               static_cast<unsigned long long>(owner ? owner->published_faults() : 0),
               static_cast<unsigned long long>(owner ? owner->consumed_faults() : 0));
  if (owner && owner->adjudicating_fault_) {
    const auto& fault = *owner->adjudicating_fault_;
    std::fprintf(stderr,
                 "{\"event\":\"retained-adjudication-fault\",\"address\":\"0x%llx\","
                 "\"instruction_pointer\":\"0x%llx\",\"access_intent\":%u}\n",
                 static_cast<unsigned long long>(fault.address),
                 static_cast<unsigned long long>(fault.instruction_pointer), fault.access_intent);
  }
  std::fflush(stderr);
  std::_Exit(kFaultContractFailureExitCode);
}

ExecutionActivation::ExecutionActivation() noexcept : parent_(Current()) {
  if (InSignalContext()) std::_Exit(139);
  if (parent_) RequireAccess();
  id_ = next_activation_id.fetch_add(1, std::memory_order_relaxed) + 1;
  if (!id_) FaultContractFailure("activation-identity-overflow");
  current_activation = this;
}

ExecutionActivation::~ExecutionActivation() noexcept {
  RequireCurrent();
  if (has_pending_fault_) FaultContractFailure("activation-left-with-pending-fault");
  if (gateway_depth_ || phase_ != ActivationPhase::Running)
    FaultContractFailure("activation-left-with-live-boundary");
  current_activation = parent_;
}

ExecutionActivation* ExecutionActivation::Current() noexcept {
  if (InSignalContext()) std::_Exit(139);
  return current_activation;
}

void ExecutionActivation::RequireCurrent() const noexcept {
  if (InSignalContext()) std::_Exit(139);
  if (current_activation != this) FaultContractFailure("wrong-activation-or-thread");
}

namespace {
// One normal-context admission implementation for strict and nullable callers.
ExecutionActivation* CheckedAccessOwner(bool required) noexcept {
  if (InSignalContext()) std::_Exit(139);
  auto* owner = current_activation;
  if (!owner) {
    if (required) FaultContractFailure("guest-access-without-activation");
    return nullptr;
  }
  if (owner->phase() != ActivationPhase::Running)
    FaultContractFailure("guest-access-during-adjudication");
  if (owner->HasPendingFault()) FaultContractFailure("guest-continuation-with-pending-fault");
  return owner;
}
}  // namespace

ExecutionActivation* CurrentForAccessOrNull() noexcept { return CheckedAccessOwner(false); }
void RequireAccess() noexcept { (void)CheckedAccessOwner(true); }

FaultToken ExecutionActivation::Publish(const CapturedFault& fault) noexcept {
  RequireCurrent();
  if (phase_ != ActivationPhase::Running) FaultContractFailure("publication-during-adjudication");
  if (has_pending_fault_) FaultContractFailure("pending-fault-overwrite");
  if (fault_sequence_ == std::numeric_limits<uint64_t>::max())
    FaultContractFailure("fault-identity-overflow");
  pending_fault_ = fault;
  pending_token_ = FaultToken(id_, ++fault_sequence_);
  has_pending_fault_ = true;
  ++published_faults_;
  return pending_token_;
}

const CapturedFault& ExecutionActivation::PendingFault() const noexcept {
  RequireCurrent();
  if (!has_pending_fault_) FaultContractFailure("read-without-pending-fault");
  return pending_fault_;
}

FaultToken ExecutionActivation::PendingToken() const noexcept {
  RequireCurrent();
  if (!has_pending_fault_) FaultContractFailure("token-without-pending-fault");
  return pending_token_;
}

void ValidateFaultToken(FaultToken token) noexcept {
  if (InSignalContext()) std::_Exit(139);
  const auto* owner = current_activation;
  if (!owner || !token || token.activation_id() != owner->id_ || !owner->has_pending_fault_ ||
      token != owner->pending_token_ || owner->phase_ != ActivationPhase::Running)
    FaultContractFailure("invalid-fault-token-or-thread");
}

CapturedFault ExecutionActivation::Consume(FaultToken token) noexcept {
  RequireCurrent();
  ValidateFaultToken(token);
  if (gateway_depth_) FaultContractFailure("consumption-inside-nonthrowing-gateway");
  const auto captured = pending_fault_;
  // Preserve the diagnostic payload/token until the next publication; validity
  // is governed by has_pending_fault_, not by zeroing memory as a second owner.
  has_pending_fault_ = false;
  ++consumed_faults_;
  return captured;
}

GatewayScope::GatewayScope() noexcept : owner_(ExecutionActivation::Current()) {
  RequireAccess();
  if (owner_->gateway_depth_ == kMaximumGatewayDepth)
    FaultContractFailure("gateway-depth-overflow");
  ++owner_->gateway_depth_;
}
GatewayScope::~GatewayScope() noexcept {
  owner_->RequireCurrent();
  if (!owner_->gateway_depth_) FaultContractFailure("gateway-depth-underflow");
  --owner_->gateway_depth_;
}

AdjudicationScope::AdjudicationScope(const CapturedFault& fault) noexcept
    : owner_(ExecutionActivation::Current()), uncaught_exceptions_(std::uncaught_exceptions()) {
  RequireAccess();
  owner_->phase_ = ActivationPhase::Adjudicating;
  SuppressAccessCapture(true);
  owner_->adjudicating_fault_ = &fault;
}
AdjudicationScope::~AdjudicationScope() noexcept {
  owner_->RequireCurrent();
  if (owner_->phase_ != ActivationPhase::Adjudicating)
    FaultContractFailure("invalid-adjudication-completion");
  // A callback that faults/throws after a side effect has indeterminate state.
  // It must never be treated as an unfinished operation suitable for retry.
  if (std::uncaught_exceptions() != uncaught_exceptions_) {
    owner_->phase_ = ActivationPhase::Poisoned;
    FaultContractFailure("exception-during-deferred-adjudication");
  }
  SuppressAccessCapture(false);
  owner_->adjudicating_fault_ = nullptr;
  owner_->phase_ = ActivationPhase::Running;
}

[[noreturn]] void DeliverFault(FaultToken token) {
  auto* owner = ExecutionActivation::Current();
  if (!owner) FaultContractFailure("delivery-without-activation");
  const auto captured = owner->Consume(token);
  if (captured.access_intent > 1) FaultContractFailure("unsupported-guest-access-intent");
  auto& state = platform::seh_thread_state();
  state.code = SehException::ACCESS_VIOLATION;
  state.info[0] = captured.access_intent;
  state.info[1] = captured.address;
  throw SehException(SehException::ACCESS_VIOLATION, captured.address);
}

}  // namespace rex::guest
