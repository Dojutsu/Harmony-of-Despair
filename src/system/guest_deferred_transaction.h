#pragma once
#include <rex/platform/guest_fault_state.h>
#include "../core/guest_access_state.h"
#include <rex/system/mmio_handler.h>

namespace rex::guest::detail {
// One canonical implementation shared by the existing public entry points and
// checked consumers. No activation or mapping decision survives an operation.
struct __attribute__((visibility("hidden"))) DeferredTransactionBridge {
  using Transaction = runtime::MMIOHandler::DeferredTransaction;
  static uint64_t OwnerId() noexcept {
    const auto* owner = CurrentAccessState();
    if (!owner) FaultContractFailure("mmio-transaction-without-owner");
    return owner->id();
  }
  static Transaction Create() noexcept {
    return Transaction(Transaction::InlineAdmission{}, OwnerId());
  }
  static bool CompleteNative(Transaction& transaction) {
    const auto* owner = CurrentAccessState();
    if (!owner || owner->id() != transaction.owner_id_)
      FaultContractFailure("mmio-transaction-wrong-owner");
    RequireAccessState();
    if (transaction.phase_ != Transaction::Phase::kUnstarted) return false;
    transaction.phase_ = Transaction::Phase::kCompleted;
    if (transaction.retry_lock_.owns_lock()) transaction.retry_lock_.unlock();
    return true;
  }
};
} // namespace rex::guest::detail
