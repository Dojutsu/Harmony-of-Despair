#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include <utility>

namespace rex::system::xam {

inline constexpr size_t kAcceptedInviteRecordSize = 84;
inline constexpr uint32_t kXnLiveInviteAccepted = 0x02000002;

// Lease revision is deliberately excluded: a renewal of this exact operation
// must not change the bytes already handed to either title listener.
struct AcceptedInviteIdentity {
  uint64_t operation_token = 0;
  uint64_t title_generation = 0;
  uint32_t title_id = 0;
  uint32_t local_user_index = 0;
  uint64_t local_xuid = 0;
  std::string directory_session_id;
  std::string directory_attempt_id;
  std::string admission_generation;
  uint64_t admission_lifecycle_token = 0;
  std::array<uint8_t, 8> xbox_session_id{};
  bool operator==(const AcceptedInviteIdentity&) const = default;
};

using AcceptedInviteRecord = std::array<uint8_t, kAcceptedInviteRecordSize>;

class AcceptedInviteStore {
 public:
  class ReadLease {
   public:
    ReadLease(ReadLease&&) = default;
    ReadLease& operator=(ReadLease&&) = default;
    ReadLease(const ReadLease&) = delete;
    ReadLease& operator=(const ReadLease&) = delete;
    const AcceptedInviteRecord& record() const { return *record_; }

   private:
    friend class AcceptedInviteStore;
    ReadLease(std::shared_lock<std::shared_mutex> lock,
              const AcceptedInviteRecord* record)
        : lock_(std::move(lock)), record_(record) {}
    std::shared_lock<std::shared_mutex> lock_;
    const AcceptedInviteRecord* record_;
  };

  // Returns true only for a new publication. Repeating an exact operation is
  // idempotent; conflicting bytes for the same operation are rejected.
  bool Publish(const AcceptedInviteIdentity& identity,
               const AcceptedInviteRecord& record);
  std::optional<ReadLease> Acquire(uint32_t local_user_index,
                                   uint32_t title_id) const;
  bool Invalidate(const AcceptedInviteIdentity& identity);
  void Clear();
  void Close();
  size_t size() const;
  std::optional<AcceptedInviteIdentity> Identity(uint32_t local_user_index) const;
  std::optional<std::pair<AcceptedInviteIdentity, AcceptedInviteRecord>> Snapshot(
      uint32_t local_user_index) const;

 private:
  struct Entry {
    AcceptedInviteIdentity identity;
    AcceptedInviteRecord record;
  };
  mutable std::shared_mutex mutex_;
  std::unordered_map<uint32_t, Entry> entries_;
  bool closed_ = false;
};

}  // namespace rex::system::xam
