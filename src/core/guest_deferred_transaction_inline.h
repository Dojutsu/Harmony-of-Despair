#pragma once
#include "guest_access_state.h"
#include "../system/guest_deferred_transaction.h"

namespace rex::guest::detail {
inline uint64_t DeferredTransactionBridge::InlineOwnerId() noexcept {
  const auto* owner = CurrentAccessState();
  if (!owner) FaultContractFailure("mmio-transaction-without-owner");
  return owner->id();
}
inline DeferredTransactionBridge::Transaction DeferredTransactionBridge::CreateInline() noexcept {
  return Transaction(Transaction::InlineAdmission{}, InlineOwnerId());
}
inline bool DeferredTransactionBridge::CompleteNativeInline(Transaction& transaction) {
  const auto* owner = CurrentAccessState();
  if (!owner || owner->id() != transaction.owner_id_)
    FaultContractFailure("mmio-transaction-wrong-owner");
  RequireAccessState();
  if (transaction.phase_ != Transaction::Phase::kUnstarted) return false;
  transaction.phase_ = Transaction::Phase::kCompleted;
  if (transaction.retry_lock_.owns_lock()) transaction.retry_lock_.unlock();
  return true;
}
} // namespace rex::guest::detail
