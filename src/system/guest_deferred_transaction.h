#pragma once
#include <rex/platform/guest_fault_state.h>
#include <rex/system/mmio_handler.h>

namespace rex::guest::detail {
// One canonical implementation shared by the existing public entry points and
// checked consumers. No activation or mapping decision survives an operation.
struct __attribute__((visibility("hidden"))) DeferredTransactionBridge {
  using Transaction = runtime::MMIOHandler::DeferredTransaction;
  // Definitions are runtime-private: foreign fixtures retain the public checked
  // entry points and cannot directly reference the runtime's hidden TLS.
  __attribute__((visibility("hidden"))) static uint64_t InlineOwnerId() noexcept;
  __attribute__((visibility("hidden"))) static Transaction CreateInline() noexcept;
  __attribute__((visibility("hidden"))) static bool CompleteNativeInline(Transaction& transaction);

  static uint64_t OwnerId() noexcept {
    const auto* owner = ExecutionActivation::Current();
    if (!owner) FaultContractFailure("mmio-transaction-without-owner");
    return owner->id();
  }
  static Transaction Create() noexcept {
    return Transaction(Transaction::InlineAdmission{}, OwnerId());
  }
  static bool CompleteNative(Transaction& transaction) {
    const auto* owner = ExecutionActivation::Current();
    if (!owner || owner->id() != transaction.owner_id_)
      FaultContractFailure("mmio-transaction-wrong-owner");
    RequireAccess();
    if (transaction.phase_ != Transaction::Phase::kUnstarted) return false;
    transaction.phase_ = Transaction::Phase::kCompleted;
    if (transaction.retry_lock_.owns_lock()) transaction.retry_lock_.unlock();
    return true;
  }
};
} // namespace rex::guest::detail
