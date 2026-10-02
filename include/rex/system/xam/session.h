#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <rex/cvar.h>
#include <rex/system/xam/session_directory.h>
#include <rex/system/xobject.h>

namespace rex::system {
class KernelState;

namespace xam {

REXCVAR_DECLARE(std::string, lan_bind_address);
REXCVAR_DECLARE(uint32_t, lan_gameplay_port);
REXCVAR_DECLARE(std::string, direct_connect_address);

struct LanAddress {
  uint32_t ipv4 = 0;  // Network byte order.
  uint16_t port = 0;  // Host byte order.
  bool operator==(const LanAddress&) const = default;
};

class LateTraversalQueryState {
 public:
  LateTraversalQueryState(bool traversal_enabled,
                          std::optional<LanAddress> initially_queried_peer = std::nullopt)
      : traversal_enabled_(traversal_enabled), queried_peer_(initially_queried_peer) {}

  std::optional<LanAddress> TakeAcknowledgedPeer(
      bool search_active, std::optional<LanAddress> acknowledged_peer);

 private:
  bool traversal_enabled_ = false;
  bool late_query_sent_ = false;
  std::optional<LanAddress> queried_peer_;
};

class SearchTimingBudget {
 public:
  static constexpr uint32_t kNatGraceMs = 1250;

  SearchTimingBudget(uint32_t original_window_ms, bool traversal_enabled)
      : original_window_ms_(original_window_ms),
        total_window_ms_(original_window_ms + (traversal_enabled ? kNatGraceMs : 0)) {}

  uint32_t original_window_ms() const { return original_window_ms_; }
  uint32_t total_window_ms() const { return total_window_ms_; }
  bool IsActive(uint32_t elapsed_ms) const { return elapsed_ms < total_window_ms_; }
  bool InNatExtension(uint32_t elapsed_ms) const {
    return elapsed_ms >= original_window_ms_ && IsActive(elapsed_ms);
  }

 private:
  uint32_t original_window_ms_ = 0;
  uint32_t total_window_ms_ = 0;
};

class RetainedDiscoverySearchState {
 public:
  void Retain(uint64_t generation) { generation_ = generation; }
  std::optional<uint64_t> Retire() {
    auto generation = generation_;
    generation_.reset();
    return generation;
  }
  bool IsRetained(uint64_t generation) const { return generation_ == generation; }
  std::optional<uint64_t> generation() const { return generation_; }

 private:
  std::optional<uint64_t> generation_;
};

struct SessionInfo {
  std::array<uint8_t, 8> id{};
  LanAddress host_address{};
  std::array<uint8_t, 6> ethernet_address{};
  std::array<uint8_t, 20> online_address{};
  std::array<uint8_t, 16> key{};
};

struct SessionMember {
  uint64_t xuid = 0;
  std::string name;
  uint32_t user_index = 0;
  bool local = false;
  bool private_slot = false;
  bool ready = false;
};

enum class SessionState : uint32_t { kLobby, kRegistration, kInGame, kReporting, kDeleted };

struct SessionRecord {
  // Session records are shared between the guest-facing XGI path and the LAN
  // discovery listener. A recursive mutex keeps compound slot calculations
  // safe without forcing callers to copy mutable records.
  std::shared_ptr<std::recursive_mutex> mutex = std::make_shared<std::recursive_mutex>();
  SessionInfo info{};
  // Discovery/join control endpoint. SessionInfo::host_address remains the
  // independent gameplay endpoint exposed to XGI/XNet.
  LanAddress discovery_address{};
  // Process-local directory capability state; never serialized into guest or
  // discovery packets.
  std::string traversal_session_id;
  std::string traversal_attempt_id;
  std::string traversal_capability;
  uint64_t nonce = 0;
  uint64_t host_xuid = 0;
  std::string host_name;
  uint32_t flags = 0;
  uint32_t max_public_slots = 0;
  uint32_t max_private_slots = 0;
  SessionState state = SessionState::kLobby;
  std::vector<SessionMember> members;

  uint32_t FilledPublicSlots() const;
  uint32_t FilledPrivateSlots() const;
  uint32_t OpenPublicSlots() const;
  uint32_t OpenPrivateSlots() const;
};

class SessionRegistry {
 public:
  std::shared_ptr<SessionRecord> Create(uint64_t host_xuid, std::string host_name,
                                        LanAddress host_address, uint32_t flags,
                                        uint32_t public_slots, uint32_t private_slots);
  bool Delete(const std::array<uint8_t, 8>& id);
  size_t DeleteHostedBy(uint64_t host_xuid);
  size_t UpdateHostedPort(uint64_t host_xuid, uint16_t port);
  size_t UpdateRemoteGameplayEndpoint(uint64_t local_xuid, LanAddress address);
  std::shared_ptr<SessionRecord> Find(const std::array<uint8_t, 8>& id) const;
  std::vector<std::shared_ptr<SessionRecord>> List() const;
  std::vector<std::shared_ptr<SessionRecord>> ListRemote(uint64_t local_xuid) const;
  bool Join(const std::array<uint8_t, 8>& id, SessionMember member);
  bool Leave(const std::array<uint8_t, 8>& id, uint64_t xuid);
  bool Modify(const std::array<uint8_t, 8>& id, uint32_t flags, uint32_t public_slots,
              uint32_t private_slots);
  bool Start(const std::array<uint8_t, 8>& id);
  bool End(const std::array<uint8_t, 8>& id);
  void UpsertDiscovered(SessionRecord record);

 private:
  static uint64_t IdKey(const std::array<uint8_t, 8>& id);
  mutable std::mutex mutex_;
  std::unordered_map<uint64_t, std::shared_ptr<SessionRecord>> sessions_;
  // Retain IDs created by this instance for its lifetime. This prevents a
  // delayed/cached advertisement for an abandoned local lobby from being
  // reintroduced under a different address or malformed host identity.
  std::unordered_set<uint64_t> local_session_ids_;
};

class LanDiscoveryService {
 public:
  LanDiscoveryService(uint32_t title_id, uint16_t port);
  ~LanDiscoveryService();
  LanDiscoveryService(const LanDiscoveryService&) = delete;
  LanDiscoveryService& operator=(const LanDiscoveryService&) = delete;

  bool Advertise(const std::shared_ptr<SessionRecord>& session);
  void SetTitleId(uint32_t title_id);
  void StopAdvertising();
  bool IsAdvertising() const;
  std::vector<SessionRecord> Search(uint32_t timeout_ms, uint32_t max_results);
  std::optional<SessionRecord> Join(const SessionRecord& session, const SessionMember& member,
                                    uint32_t timeout_ms);
  std::optional<SessionRecord> Leave(const SessionRecord& session, uint64_t xuid,
                                     uint32_t timeout_ms);
  static uint32_t DetermineLanIpv4();

 private:
  class Impl;
  std::unique_ptr<Impl> impl_;
  SessionDirectoryClient directory_;
};

class XSession final : public XObject {
 public:
  static const XObject::Type kObjectType = XObject::Type::Session;
  explicit XSession(KernelState* kernel_state);
  ~XSession() override;
  bool Initialize();
  std::shared_ptr<SessionRecord> record() const { return record_; }
  void set_record(std::shared_ptr<SessionRecord> record);

 private:
  std::shared_ptr<SessionRecord> record_;
};

class SessionManager {
 public:
  SessionManager(KernelState* kernel_state, uint16_t discovery_port);
  ~SessionManager();
  SessionRegistry& registry() { return registry_; }
  LanDiscoveryService& discovery() { return discovery_; }
  void RegisterObject(XSession* session);
  void UnregisterObject(XSession* session);
  void ReleaseRecord(const std::shared_ptr<SessionRecord>& record);
  XSession* LookupObject(uint32_t guest_object) const;

 private:
  KernelState* kernel_state_;
  SessionRegistry registry_;
  LanDiscoveryService discovery_;
  mutable std::mutex object_mutex_;
  std::unordered_map<uint32_t, XSession*> objects_;
};

}  // namespace xam
}  // namespace rex::system
