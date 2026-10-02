#include <rex/system/xam/accepted_invite.h>

#include <mutex>

namespace rex::system::xam {

bool AcceptedInviteStore::Publish(const AcceptedInviteIdentity& identity,
                                  const AcceptedInviteRecord& record) {
  if (!identity.operation_token || !identity.title_id || !identity.local_xuid ||
      !identity.admission_lifecycle_token)
    return false;
  std::unique_lock lock(mutex_);
  if (closed_)
    return false;
  auto found = entries_.find(identity.local_user_index);
  if (found != entries_.end()) {
    if (found->second.identity == identity)
      return false;
    if (found->second.identity.title_generation > identity.title_generation ||
        (found->second.identity.title_generation == identity.title_generation &&
         found->second.identity.operation_token >= identity.operation_token))
      return false;
  }
  entries_[identity.local_user_index] = {identity, record};
  return true;
}

std::optional<AcceptedInviteStore::ReadLease> AcceptedInviteStore::Acquire(
    uint32_t local_user_index, uint32_t title_id) const {
  std::shared_lock lock(mutex_);
  auto found = entries_.find(local_user_index);
  if (closed_ || found == entries_.end() ||
      found->second.identity.title_id != title_id)
    return std::nullopt;
  return ReadLease(std::move(lock), &found->second.record);
}

bool AcceptedInviteStore::Invalidate(const AcceptedInviteIdentity& identity) {
  std::unique_lock lock(mutex_);
  auto found = entries_.find(identity.local_user_index);
  if (found == entries_.end() || found->second.identity != identity)
    return false;
  entries_.erase(found);
  return true;
}

void AcceptedInviteStore::Clear() {
  std::unique_lock lock(mutex_);
  entries_.clear();
}

void AcceptedInviteStore::Close() {
  std::unique_lock lock(mutex_);
  closed_ = true;
  entries_.clear();
}

size_t AcceptedInviteStore::size() const {
  std::shared_lock lock(mutex_);
  return entries_.size();
}

std::optional<AcceptedInviteIdentity> AcceptedInviteStore::Identity(
    uint32_t local_user_index) const {
  std::shared_lock lock(mutex_);
  auto found = entries_.find(local_user_index);
  if (closed_ || found == entries_.end())
    return std::nullopt;
  return found->second.identity;
}

std::optional<std::pair<AcceptedInviteIdentity, AcceptedInviteRecord>>
AcceptedInviteStore::Snapshot(uint32_t local_user_index) const {
  std::shared_lock lock(mutex_);
  auto found = entries_.find(local_user_index);
  if (closed_ || found == entries_.end())
    return std::nullopt;
  return std::pair{found->second.identity, found->second.record};
}

}  // namespace rex::system::xam
