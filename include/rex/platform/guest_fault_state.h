/**
 * @file platform/guest_fault_state.h
 * @brief Normal-context ownership and nonthrowing guest fault transport.
 *
 * These objects are never inspected or mutated by the signal handler. Registered
 * leaves capture first, return normally, and only then publish a terminal fault.
 */
#pragma once

#include <cstdint>
#include <type_traits>
#include <utility>

#include <rex/platform/guest_access.h>

namespace rex::guest {

inline constexpr int kFaultContractFailureExitCode = 86;
inline constexpr uint32_t kMaximumGatewayDepth = 32;

/// An internal/native contract failure, not a guest exception. NORMAL context
/// only. Terminates with a diagnostic rather than invoking std::terminate.
[[noreturn]] void FaultContractFailure(const char* reason) noexcept;

class FaultToken {
 public:
  constexpr FaultToken() noexcept = default;
  constexpr uint64_t activation_id() const noexcept { return activation_id_; }
  constexpr uint64_t sequence() const noexcept { return sequence_; }
  constexpr explicit operator bool() const noexcept { return activation_id_ && sequence_; }
  friend constexpr bool operator==(FaultToken, FaultToken) noexcept = default;

 private:
  friend class ExecutionActivation;
  constexpr FaultToken(uint64_t activation, uint64_t sequence) noexcept
      : activation_id_(activation), sequence_(sequence) {}
  uint64_t activation_id_ = 0;
  uint64_t sequence_ = 0;
};

enum class ActivationPhase : uint8_t { Running, Adjudicating, Poisoned };

/// The designated normal-context consumer. This object stays on its creating
/// thread/stack. A child may run only while its parent has no pending fault or
/// adjudication, and must consume its own faults before returning to the parent.
class ExecutionActivation {
 public:
  ExecutionActivation() noexcept;
  ~ExecutionActivation() noexcept;
  ExecutionActivation(const ExecutionActivation&) = delete;
  ExecutionActivation& operator=(const ExecutionActivation&) = delete;
  ExecutionActivation(ExecutionActivation&&) = delete;
  ExecutionActivation& operator=(ExecutionActivation&&) = delete;

  static ExecutionActivation* Current() noexcept;
  uint64_t id() const noexcept { return id_; }
  ActivationPhase phase() const noexcept { return phase_; }
  uint32_t gateway_depth() const noexcept { return gateway_depth_; }
  bool HasPendingFault() const noexcept { return has_pending_fault_; }
  uint64_t published_faults() const noexcept { return published_faults_; }
  uint64_t consumed_faults() const noexcept { return consumed_faults_; }

  FaultToken Publish(const CapturedFault& fault) noexcept;
  const CapturedFault& PendingFault() const noexcept;
  FaultToken PendingToken() const noexcept;
  CapturedFault Consume(FaultToken token) noexcept;

 private:
  friend class GatewayScope;
  friend class AdjudicationScope;
  friend void FaultContractFailure(const char* reason) noexcept;
  friend void RequireAccess() noexcept;
  friend void ValidateFaultToken(FaultToken) noexcept;
  void RequireCurrent() const noexcept;

  ExecutionActivation* parent_ = nullptr;
  uint64_t id_ = 0;
  uint64_t fault_sequence_ = 0;
  uint64_t published_faults_ = 0;
  uint64_t consumed_faults_ = 0;
  uint32_t gateway_depth_ = 0;
  ActivationPhase phase_ = ActivationPhase::Running;
  bool has_pending_fault_ = false;
  FaultToken pending_token_{};
  CapturedFault pending_fault_{};
  const CapturedFault* adjudicating_fault_ = nullptr;
};

/// Refuse access before entering a leaf when ownership or phase is invalid.
void RequireAccess() noexcept;
/// Validate a current owner, or return null for a consumer that establishes one.
ExecutionActivation* CurrentForAccessOrNull() noexcept;
/// Validate normal transport against the creating activation/thread; no consume.
void ValidateFaultToken(FaultToken token) noexcept;

class GatewayScope {
 public:
  GatewayScope() noexcept;
  ~GatewayScope() noexcept;
  GatewayScope(const GatewayScope&) = delete;
  GatewayScope& operator=(const GatewayScope&) = delete;

 private:
  ExecutionActivation* owner_;
};

/// Only one deferred MMIO/watch adjudication is admitted per thread. The leaf
/// must already be disarmed. Faultable callbacks are not given another frame.
class AdjudicationScope {
 public:
  explicit AdjudicationScope(const CapturedFault& fault) noexcept;
  ~AdjudicationScope() noexcept;
  AdjudicationScope(const AdjudicationScope&) = delete;
  AdjudicationScope& operator=(const AdjudicationScope&) = delete;

 private:
  ExecutionActivation* owner_;
  int uncaught_exceptions_;
};

/// An exception-capable dispatcher boundary only; never call from noexcept,
/// signal context, a foreign callback, or while GatewayScope is live.
[[noreturn]] void DeliverFault(FaultToken token);

/// A success payload is deliberately POD/nonthrowing: fault transport must not
/// accidentally construct an allocating result or propagate a native exception.
template <typename T>
class [[nodiscard]] AccessResult {
  static_assert(std::is_trivially_copyable_v<T> && std::is_trivially_default_constructible_v<T> &&
                    std::is_trivially_destructible_v<T> && std::is_nothrow_default_constructible_v<T> &&
                    std::is_nothrow_copy_assignable_v<T> && std::is_nothrow_copy_constructible_v<T>,
                "Guest access transport requires a trivial, nonthrowing payload");

 public:
  static AccessResult Success(T value) noexcept {
    AccessResult result;
    result.value_ = value;
    return result;
  }
  static AccessResult Failure(FaultToken token) noexcept {
    ValidateFaultToken(token);
    AccessResult result;
    result.failed_ = true;
    result.token_ = token;
    return result;
  }
  AccessResult(const AccessResult&) = delete;
  AccessResult& operator=(const AccessResult&) = delete;
  AccessResult(AccessResult&& other) noexcept
      : value_(other.value_), token_(other.token_), failed_(other.failed_),
        acknowledged_(other.acknowledged_) {
    other.acknowledged_ = true;
  }
  AccessResult& operator=(AccessResult&& other) noexcept {
    if (this == &other) return *this;
    CheckAcknowledged();
    value_ = other.value_;
    token_ = other.token_;
    failed_ = other.failed_;
    acknowledged_ = other.acknowledged_;
    other.acknowledged_ = true;
    return *this;
  }
  ~AccessResult() noexcept { CheckAcknowledged(); }

  bool IsSuccess() const noexcept { return !failed_; }
  bool Failed() const noexcept { return failed_; }
  T Value() noexcept {
    if (failed_) FaultContractFailure("value-from-failed-result");
    RequireAccess();
    acknowledged_ = true;
    return value_;
  }
  FaultToken Fault() noexcept {
    if (!failed_ || acknowledged_) FaultContractFailure("invalid-fault-result-relay");
    ValidateFaultToken(token_);
    acknowledged_ = true;
    return token_;
  }
  template <typename U = T>
  AccessResult<U> Forward() noexcept {
    return AccessResult<U>::Failure(Fault());
  }

 private:
  AccessResult() noexcept = default;
  void CheckAcknowledged() const noexcept {
    if (failed_ && !acknowledged_) FaultContractFailure("ignored-fault-result");
  }
  T value_{};
  FaultToken token_{};
  bool failed_ = false;
  bool acknowledged_ = false;
};

/// Ordinary C++ convenience for a proven exception-capable consumer. A failure
/// token is acknowledged before delivery; the activation verifies depth/owner.
template <typename T>
T ValueOrThrow(AccessResult<T>&& result) {
  if (result.Failed()) DeliverFault(result.Fault());
  return result.Value();
}

}  // namespace rex::guest
