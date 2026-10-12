#pragma once

#include <array>
#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <optional>
#include <span>
#include <stop_token>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <rex/cvar.h>
#include <rex/system/xam/accepted_invite.h>
#include <rex/system/xam/online_status.h>
#include <rex/system/xam/session_directory.h>
#include <rex/system/xam/session_arbitration.h>
#include <rex/system/xobject.h>

namespace rex::system {
class KernelState;

namespace xam {

// Attempt-keyed proof used by configured-invite LAN discovery. The attempt
// identifier is never put on the LAN probe wire in cleartext.
std::optional<std::array<uint8_t, 16>> InviteLanAuthenticationTag(
    std::string_view attempt_id, std::string_view domain,
    std::span<const uint8_t> payload = {});

REXCVAR_DECLARE(std::string, private_lan_invitation_file);
REXCVAR_DECLARE(bool, private_lan_allow_legacy_diagnostics);
REXCVAR_DECLARE(std::string, lan_bind_address);
REXCVAR_DECLARE(std::string, lan_discovery_listen_address);
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

  std::optional<LanAddress> TakeAcknowledgedPeer(bool search_active,
                                                 std::optional<LanAddress> acknowledged_peer);

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

struct ReadyConfiguredInvite;
std::array<uint8_t, 60> SerializeGuestSessionInfo(const SessionInfo& info);
std::optional<AcceptedInviteRecord> SerializeAcceptedInviteRecord(
    const ReadyConfiguredInvite& ready);

struct XnAddrIdentity {
  std::array<uint8_t, 6> ethernet_address{};
  std::array<uint8_t, 20> online_address{};
  bool operator==(const XnAddrIdentity&) const = default;
};

// SessionRegistry::Create, discovery reconstruction, and XNetGetTitleXnAddr
// all use this exact title-visible identity rule.
XnAddrIdentity ReconstructXnAddrIdentity(uint64_t xuid);

// Local immutable proof of the winning admission transaction. Never serialized
// into title/discovery packets and never inferred from XUID or IPv4 alone.
struct GameplayAdmissionBinding {
  std::string directory_session_id;
  std::string attempt_id;
  std::string admission_generation;
};

struct SessionMember {
  uint64_t xuid = 0;
  std::string name;
  uint32_t user_index = 0;
  bool local = false;
  bool private_slot = false;
  bool ready = false;
  std::shared_ptr<const GameplayAdmissionBinding> gameplay_admission;
  uint64_t machine_id = 0;
  LanAddress gameplay_address{};
};

struct SessionRecord;
class PrivateLanInvitation;
class PrivateLanAuthority;
class PrivateLanClientBinding;
struct GameplayAuthorization;
class ArbitrationClientBinding;

enum class DiscoveryAdmissionSource { kPublicDiscovery, kInviteGrant };

struct DiscoveryAdmissionContext {
  DiscoveryAdmissionSource source = DiscoveryAdmissionSource::kPublicDiscovery;
};

// Authoritative hosted-session mutation seam. Public discovery ignores a peer
// private-bit claim. A verified invite permits private-first allocation with
// public fallback; the stored private_slot always describes the allocated pool.
bool ApplyDiscoveryMemberBatch(SessionRecord& session, std::span<const SessionMember> members,
                               DiscoveryAdmissionContext context);

enum class SessionState : uint32_t { kLobby, kRegistration, kInGame, kReporting, kDeleted };

struct SessionRecord {
  // Session records are shared between the guest-facing XGI path and the LAN
  // discovery listener. A recursive mutex keeps compound slot calculations
  // safe without forcing callers to copy mutable records.
  std::shared_ptr<std::recursive_mutex> mutex = std::make_shared<std::recursive_mutex>();
  // Public display metadata only. Protected by mutex; never sent on the wire.
  std::weak_ptr<OnlineStatusSignal> status_signal;
  std::string status_invite_code;
  void NotifyStatus() const {
    if (auto signal = status_signal.lock()) signal->Notify();
  }
  void SetStatusInviteCode(std::string code) {
    std::lock_guard lock(*mutex);
    if (status_invite_code == code) return;
    status_invite_code = std::move(code);
    NotifyStatus();
  }
  // Process-local private LAN authority; never guest/discovery serialization.
  std::shared_ptr<const PrivateLanInvitation> private_lan_invitation;
  std::shared_ptr<PrivateLanAuthority> private_lan_authority;
  mutable std::shared_ptr<PrivateLanClientBinding> private_lan_client;
  std::shared_ptr<const GameplayAuthorization> private_lan_gameplay;
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
  uint64_t host_machine_id = 0;
  ArbitrationToken arbitration_incarnation{};
  std::shared_ptr<SessionArbitrationAuthority> arbitration;
  ArbitrationToken arbitration_local_attempt{};
  uint64_t arbitration_revision = 0;
  mutable std::shared_ptr<ArbitrationClientBinding> arbitration_client;
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

enum class ConfiguredInviteLifecycleState {
  kUnclaimed,
  kClaimed,
  kAttemptIssued,
  kTraversalReady,
  kHostCorrelated,
  kReadyForAcceptedInvite,
  kPublished,
  kCompleted,
  kCancelled,
  kExpired,
  kFailed,
};

enum class ConfiguredInviteStage {
  kWorkerStarted,
  kBeforeAttemptIssue,
  kAttemptIssued,
  kBeforeSocketSetup,
  kTraversalReady,
  kBeforeFirstDiscoverySend,
  kDiscoveryWaiting,
  kBeforeDiscoveryRetry,
  kHostCorrelated,
  kReadyForAcceptedInvite,
  kCancellationVisible,
  kCleanup,
  kCleanupComplete,
};

struct ConfiguredInviteOperationIdentity {
  uint64_t operation_token = 0;
  uint64_t title_generation = 0;
  uint32_t title_id = 0;
  uint32_t local_user_index = 0;
  uint64_t local_xuid = 0;
  std::string invite_code;
};

struct ReadyConfiguredInvite {
  ConfiguredInviteOperationIdentity operation;
  std::string directory_session_id;
  std::string directory_attempt_id;
  std::string admission_generation;
  uint64_t lease_revision = 0;
  uint64_t client_admission_lifecycle_token = 0;
  bool host_ready = false;
  bool private_allocation_eligible = false;
  std::array<uint8_t, 8> xbox_session_id{};
  uint64_t host_xuid = 0;
  std::array<uint8_t, 16> exchange_key{};
  LanAddress host_endpoint{};
  LanAddress discovery_endpoint{};
  XnAddrIdentity xnaddr;
  uint64_t nonce = 0;
};

struct ConfiguredInviteDiscoveryResult {
  SessionRecord session;
  uint64_t socket = 0;
};

class LanDiscoveryService;
using ConfiguredInviteDiscoveryOperation =
    std::function<std::optional<ConfiguredInviteDiscoveryResult>(
        LanDiscoveryService&, const DirectoryInviteJoinAttempt&, uint32_t,
        const std::function<bool()>&,
        const std::function<void(ConfiguredInviteStage)>&)>;

class SessionRegistry {
 public:
  using ChangeObserver = std::function<void(const std::array<uint8_t, 8>&)>;
  explicit SessionRegistry(ChangeObserver observer = {});
  uint64_t local_machine_id() const { return machine_id_; }
  std::optional<uint64_t> FindArbitrationMachineId(const XnAddrIdentity& identity,
      uint32_t ipv4, uint16_t port, uint64_t local_xuid) const;
  bool CommitArbitration(const std::shared_ptr<SessionRecord>& expected,
      const ArbitrationIdentity& identity, uint64_t revision, const std::function<bool()>& publish);
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
  bool JoinBatch(const std::shared_ptr<SessionRecord>& expected,
                 std::span<const SessionMember> members);
  bool Leave(const std::array<uint8_t, 8>& id, uint64_t xuid);
  bool Modify(const std::array<uint8_t, 8>& id, uint32_t flags, uint32_t public_slots,
              uint32_t private_slots);
  bool Start(const std::array<uint8_t, 8>& id);
  bool End(const std::array<uint8_t, 8>& id);
  std::shared_ptr<SessionRecord> UpsertDiscovered(SessionRecord record);
  bool CommitJoinedRecord(const std::shared_ptr<SessionRecord>& expected,
                          SessionRecord updated, const std::function<bool()>& object_current);

 private:
  friend class SessionManager;
  // Runs only a local lifecycle mutation while registry/record membership is
  // stable. The callback must not wait, call observers or perform I/O.
  bool WithNoLiveLocalMember(const std::function<void()>& mutation);
  static uint64_t IdKey(const std::array<uint8_t, 8>& id);
  uint64_t machine_id_ = 0;
  mutable std::mutex mutex_;
  std::unordered_map<uint64_t, std::shared_ptr<SessionRecord>> sessions_;
  // Retain IDs created by this instance for its lifetime. This prevents a
  // delayed/cached advertisement for an abandoned local lobby from being
  // reintroduced under a different address or malformed host identity.
  std::unordered_set<uint64_t> local_session_ids_;
  ChangeObserver change_observer_;
};

class LanDiscoveryService {
 public:
  LanDiscoveryService(uint32_t title_id, uint16_t port,
                      std::shared_ptr<HostAdmissionGrantStore> admission_grants = {},
                      SessionDirectoryClient::LocalUserIdentityProvider user_identity = {},
                      SessionDirectoryClient::ClientAdmissionTransport client_admission_transport = {},
                      bool automatic_client_admission_driver = true,
                      SessionDirectoryClient::InviteJoinAttemptTransport
                          invite_join_attempt_transport = {},
                      SessionDirectoryClient::JoinAttemptCompletionTransport
                          join_attempt_completion_transport = {});
  ~LanDiscoveryService();
  LanDiscoveryService(const LanDiscoveryService&) = delete;
  LanDiscoveryService& operator=(const LanDiscoveryService&) = delete;

  bool Advertise(const std::shared_ptr<SessionRecord>& session);
  void SetTitleId(uint32_t title_id);
  void SetArbitrationMachineId(uint64_t machine_id);
  void SetLocalUserIdentity(uint32_t local_user_index, std::optional<uint64_t> xuid);
  ClientAdmissionPrepareResult PrepareClientAdmission(
      uint32_t local_user_index, const DirectoryTraversalAttempt& attempt,
      const SessionRecord& discovered, uint64_t discovery_socket);
  bool ConfirmClientAdmissionSession(uint32_t local_user_index,
                                     const std::shared_ptr<const SessionRecord>& session);
  bool HasClientAdmission(uint32_t local_user_index) const;
  std::optional<uint64_t> ClientAdmissionLifecycleToken(
      uint32_t local_user_index) const;
  std::optional<ReadyAcceptedSessionCandidate> ReadyAcceptedSession(
      uint32_t local_user_index = 0);
  void PollClientAdmissions(
      std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now());
  void StopClientAdmission(uint32_t local_user_index);
  void QueueGameplayAdmission(const std::shared_ptr<SessionRecord>& session,
                              uint32_t user_index, uint64_t xuid,
                              const DirectoryTraversalAttempt& attempt,
                              const std::string& generation);
  bool ActivatePrivateLanGameplay(const std::shared_ptr<SessionRecord>& session,uint64_t xuid);
  void StopAllClientAdmissions();
  void StopAdvertising();
  bool IsAdvertising() const;
  std::vector<SessionRecord> Search(uint32_t timeout_ms, uint32_t max_results,
                                    uint32_t local_user_index = 0);
  // Online team search: the directory's open, searchable lobbies. Empty for
  // LAN, private-invitation and legacy diagnostic modes.
  std::vector<DirectoryListing> SearchListings(uint64_t exclude_host_xuid);
  std::optional<DirectoryInviteJoinAttempt> IssueConfiguredInviteAttempt(
      std::string_view code, uint32_t title_id);
  void ReleaseConfiguredInviteAttempt(const DirectoryTraversalAttempt& attempt);
  std::optional<ConfiguredInviteDiscoveryResult> DiscoverConfiguredInvite(
      const DirectoryInviteJoinAttempt& issued, uint32_t timeout_ms,
      const std::function<bool()>& operation_is_current,
      const std::function<void(ConfiguredInviteStage)>& stage_observer = {},
      LanAddress lan_probe_target = {});
  std::optional<SessionRecord> Join(const SessionRecord& session, const SessionMember& member,
                                    uint32_t timeout_ms);
  std::optional<SessionRecord> Leave(const SessionRecord& session, uint64_t xuid,
                                     uint32_t timeout_ms);
  std::optional<ReadyConfiguredInvite> ReadyConfiguredInviteResult(
      const ConfiguredInviteOperationIdentity& operation,
      const DirectoryTraversalAttempt& attempt,
      uint64_t client_admission_lifecycle_token,
      uint32_t local_user_index = 0);
  std::optional<ArbitrationSnapshot> RegisterArbitration(
      const std::shared_ptr<SessionRecord>& session, uint64_t local_xuid, uint64_t nonce);
  static uint32_t DetermineLanIpv4();

 private:
  class Impl;
  std::shared_ptr<HostAdmissionGrantStore> admission_grants_;
  std::unique_ptr<Impl> impl_;
  SessionDirectoryClient directory_;
};

struct SessionManagerDependencies {
  SessionDirectoryClient::LocalUserIdentityProvider user_identity;
  SessionDirectoryClient::ClientAdmissionTransport client_admission_transport;
  SessionDirectoryClient::InviteJoinAttemptTransport invite_join_attempt_transport;
  SessionDirectoryClient::JoinAttemptCompletionTransport join_attempt_completion_transport;
  ConfiguredInviteDiscoveryOperation configured_invite_discovery;
  std::function<void(ConfiguredInviteStage,
                     const ConfiguredInviteOperationIdentity&)>
      configured_invite_stage_observer;
  std::function<size_t(uint32_t)> accepting_listener_count;
  std::function<size_t(uint32_t, uint32_t)> broadcast_notification;
  std::function<uint32_t()> current_title_id;
};

// CURRENT REXGLUE PLATFORM LIMITATION: production local identity currently
// exposes local user 0 only. This is neither an Xbox/XAM limitation nor a
// Harmony protocol requirement.
std::optional<uint64_t> ResolveRexGlueLocalUserXuid(
    uint32_t local_user_index, std::optional<uint64_t> current_profile_xuid);

class XSession final : public XObject {
 public:
  static const XObject::Type kObjectType = XObject::Type::Session;
  explicit XSession(KernelState* kernel_state);
  ~XSession() override;
  bool Initialize();
  std::shared_ptr<SessionRecord> record() const { return record_.load(std::memory_order_acquire); }
  void set_record(std::shared_ptr<SessionRecord> record);

 private:
#if defined(__ANDROID__)
  // The NDK's libc++ has no std::atomic<std::shared_ptr>; a lock gives the
  // same load/exchange contract.
  class LockedRecordPtr {
   public:
    std::shared_ptr<SessionRecord> load(std::memory_order = std::memory_order_seq_cst) const {
      std::lock_guard<std::mutex> lock(mutex_);
      return value_;
    }
    std::shared_ptr<SessionRecord> exchange(std::shared_ptr<SessionRecord> value,
                                            std::memory_order = std::memory_order_seq_cst) {
      std::lock_guard<std::mutex> lock(mutex_);
      std::swap(value_, value);
      return value;
    }

   private:
    mutable std::mutex mutex_;
    std::shared_ptr<SessionRecord> value_;
  };
  LockedRecordPtr record_;
#else
  std::atomic<std::shared_ptr<SessionRecord>> record_;
#endif
};

enum class RuntimeInviteUpdateResult {
  kStarted,
  kCleared,
  kInvalidCode,
  kLiveSession,
  kUnavailable,
  kCancelled,
};

class SessionManager {
 public:
  SessionManager(KernelState* kernel_state, uint16_t discovery_port,
                 SessionManagerDependencies dependencies = {});
  ~SessionManager();
  OnlineStatus& online_status() { return online_status_; }
  SessionRegistry& registry() { return registry_; }
  LanDiscoveryService& discovery() { return discovery_; }
  void RegisterObject(XSession* session);
  void UnregisterObject(XSession* session);
  void ReleaseRecord(const std::shared_ptr<SessionRecord>& record);
  XSession* LookupObject(uint32_t guest_object) const;
  void OnTitleTransition(uint32_t title_id);
  void OnTitleTermination();
  void ShutdownAsyncActivity();
  // Native title-lifetime override; never writes the startup CVAR or config.
  RuntimeInviteUpdateResult UpdateRuntimeInviteCode(
      std::string_view code, std::stop_token cancellation = {});
  std::string runtime_invite_code() const;
  ConfiguredInviteLifecycleState configured_invite_state() const;
  std::optional<ReadyConfiguredInvite> ready_configured_invite() const;
  AcceptedInviteStore& accepted_invites() { return accepted_invites_; }
  std::optional<AcceptedInviteStore::ReadLease> GetAcceptedInviteRecord(
      uint32_t local_user_index, uint32_t title_id);
  bool CompleteAcceptedInviteJoin(uint32_t local_user_index, uint64_t local_xuid,
                                  const std::shared_ptr<SessionRecord>& session);
  // Team search: remember the lobbies last shown to the title, and join one
  // the title picked through the same admission an invite code uses.
  void RememberSearchListings(std::vector<DirectoryListing> listings);
  bool IsSearchListing(const std::array<uint8_t, 8>& xbox_session_id) const;
  bool JoinSearchListing(const std::array<uint8_t, 8>& xbox_session_id,
                         std::chrono::milliseconds timeout = std::chrono::seconds(15));

 private:
  struct ConfiguredInviteOperation;
  bool StartConfiguredInviteOperation(uint32_t title_id);
  void CancelConfiguredInviteOperation();
  std::shared_ptr<ConfiguredInviteOperation> RetireConfiguredInviteOperationLocked();
  void DrainConfiguredInviteOperation(
      const std::shared_ptr<ConfiguredInviteOperation>& operation);
  void RunConfiguredInviteOperation(
      const std::shared_ptr<ConfiguredInviteOperation>& operation);
  bool IsConfiguredInviteOperationCurrent(
      const ConfiguredInviteOperationIdentity& identity) const;
  void SetConfiguredInviteState(
      const std::shared_ptr<ConfiguredInviteOperation>& operation,
      ConfiguredInviteLifecycleState state);
  void ObserveConfiguredInviteStage(
      const std::shared_ptr<ConfiguredInviteOperation>& operation,
      ConfiguredInviteStage stage) const;
  void TryPublishAcceptedInvite(
      const std::shared_ptr<ConfiguredInviteOperation>& operation);
  void OnRegistryChanged(const std::array<uint8_t, 8>& session_id);
  bool RuntimeIdentityMatches(const ConfiguredInviteOperationIdentity& identity) const;
  KernelState* kernel_state_;
  OnlineStatus online_status_;
  SessionRegistry registry_;
  SessionDirectoryClient::LocalUserIdentityProvider user_identity_;
  ConfiguredInviteDiscoveryOperation configured_invite_discovery_;
  std::function<void(ConfiguredInviteStage,
                     const ConfiguredInviteOperationIdentity&)>
      configured_invite_stage_observer_;
  std::function<size_t(uint32_t)> accepting_listener_count_;
  std::function<size_t(uint32_t, uint32_t)> broadcast_notification_;
  std::function<uint32_t()> current_title_id_;
  LanDiscoveryService discovery_;
  AcceptedInviteStore accepted_invites_;
  mutable std::mutex configured_invite_mutex_;
  mutable std::timed_mutex configured_invite_control_mutex_;
  std::shared_ptr<ConfiguredInviteOperation> configured_invite_operation_;
  ConfiguredInviteLifecycleState configured_invite_state_ =
      ConfiguredInviteLifecycleState::kUnclaimed;
  std::optional<ReadyConfiguredInvite> ready_configured_invite_;
  uint64_t configured_invite_title_generation_ = 0;
  uint32_t configured_invite_active_title_id_ = 0;
  std::optional<std::string> runtime_invite_override_;
  std::optional<uint64_t> runtime_invite_override_xuid_;
  uint64_t next_configured_invite_operation_token_ = 0;
  uint64_t configured_invite_claim_token_ = 0;
  // Set just before a search join starts its invite-code operation.
  bool search_join_next_ = false;
  mutable std::mutex search_listings_mutex_;
  std::vector<DirectoryListing> search_listings_;
  std::atomic<bool> async_shutdown_{false};
  mutable std::mutex async_shutdown_mutex_;
  bool async_shutdown_complete_ = false;
  mutable std::mutex object_mutex_;
  std::unordered_map<uint32_t, XSession*> objects_;
};

}  // namespace xam
}  // namespace rex::system
