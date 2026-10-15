#pragma once

#include <array>
#include <chrono>
#include <deque>
#include <filesystem>
#include <functional>
#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <span>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <rex/cvar.h>

namespace rex::system::xam {

struct SessionRecord;
class ClientAdmissionSocketOwner;

// Move-only receive ownership, acquired with an exact admission lifecycle.
// Cancellation invalidates the lease immediately, but cannot close or reuse
// its native socket until every in-flight operation has released ownership.
class ClientAdmissionSocketLease final {
 public:
  ClientAdmissionSocketLease() = default;
  ClientAdmissionSocketLease(const ClientAdmissionSocketLease&) = delete;
  ClientAdmissionSocketLease& operator=(const ClientAdmissionSocketLease&) = delete;
  ClientAdmissionSocketLease(ClientAdmissionSocketLease&&) noexcept;
  ClientAdmissionSocketLease& operator=(ClientAdmissionSocketLease&&) noexcept;
  ~ClientAdmissionSocketLease();
  uint64_t socket() const;
  bool active() const;
 private:
  friend class SessionDirectoryClient;
  explicit ClientAdmissionSocketLease(std::shared_ptr<ClientAdmissionSocketOwner> owner);
  void Release();
  std::shared_ptr<ClientAdmissionSocketOwner> owner_;
};

REXCVAR_DECLARE(std::string, session_directory_url);
REXCVAR_DECLARE(std::string, session_directory_build_id);
REXCVAR_DECLARE(std::string, session_directory_publish_address);
REXCVAR_DECLARE(std::string, session_directory_candidate_type);
REXCVAR_DECLARE(uint32_t, session_directory_session_index);
REXCVAR_DECLARE(std::string, session_directory_invite_code);

struct DirectoryCandidate {
  std::string type;
  std::string address;
  uint16_t discovery_port = 0;
  uint16_t gameplay_port = 0;
};

struct DirectorySession {
  std::string session_id;
  std::string server_name;
  uint32_t player_count = 0;
  uint32_t max_players = 0;
  uint32_t title_id = 0;
  uint32_t protocol_version = 0;
  std::string build_id;
  std::vector<DirectoryCandidate> connectivity_candidates;
};

// A lobby the host chose to make findable through in-game team search. The
// Xbox session fields are the same ones a searcher would receive from the
// host's discovery reply; joining still goes through the invite-code
// admission, so a listing alone grants nothing.
struct DirectoryListing {
  std::string session_id;
  std::string invite_code;
  std::string server_name;
  std::array<uint8_t, 8> xbox_session_id{};
  std::array<uint8_t, 16> key{};
  uint32_t host_ipv4 = 0;  // Network byte order.
  uint16_t host_port = 0;
  std::array<uint8_t, 6> ethernet_address{};
  std::array<uint8_t, 20> online_address{};
  uint64_t host_xuid = 0;
  uint32_t open_public_slots = 0;
  uint32_t open_private_slots = 0;
  uint32_t filled_public_slots = 0;
  uint32_t filled_private_slots = 0;
  std::vector<std::pair<uint32_t, uint32_t>> contexts;
  std::vector<std::pair<uint32_t, std::vector<uint8_t>>> properties;
};

// Host-side title search attributes (XUserSetContext/XUserSetProperty for
// local user 0), published with the hosted lobby's listing.
void SetDirectoryListingContext(uint32_t context_id, uint32_t value);
void SetDirectoryListingProperty(uint32_t property_id, std::span<const uint8_t> value);
void ClearDirectoryListingAttributes();
// Searchable lobbies from a GET /sessions body, excluding the caller's own.
std::vector<DirectoryListing> ParseDirectoryListingResponse(std::string_view body,
                                                            uint32_t title_id,
                                                            std::string_view build_id,
                                                            uint64_t exclude_host_xuid);

struct DirectoryTraversalAttempt {
  std::string session_id;
  std::string attempt_id;
  std::string capability;
  std::string rendezvous_host;
  uint16_t rendezvous_port = 0;
  uint8_t participant = 0;
  std::string purpose;
  std::string admission_generation;
  uint64_t lease_revision = 0;
  uint32_t admission_expires_in_ms = 0;
  bool host_ready = false;
};

struct DirectoryInviteJoinAttempt {
  DirectorySession session;
  DirectoryTraversalAttempt attempt;
};

struct DirectoryAdmissionState {
  std::string attempt_id;
  std::string purpose;
  std::string phase;
  std::string admission_generation;
  uint64_t lease_revision = 0;
  uint32_t admission_lease_duration_ms = 0;
  uint32_t admission_expires_in_ms = 0;
  bool host_ready = false;
  // Only set on a terminal phase; "completed" means the host finished the
  // attempt after admitting this player.
  std::string terminal_reason;
};

struct ReadyAcceptedSessionCandidate {
  uint32_t local_user_index = 0;
  uint64_t local_user_xuid = 0;
  uint32_t title_id = 0;
  uint64_t lifecycle_token = 0;
  std::string directory_session_id;
  std::string attempt_id;
  std::string admission_generation;
  uint64_t lease_revision = 0;
  bool private_allocation_eligible = false;
  std::shared_ptr<const SessionRecord> session;
};

enum class ClientAdmissionAction { kNone, kArm, kStatus, kRenew };
enum class ClientAdmissionApplyResult { kApplied, kIgnoredStale, kInvalidated };
enum class ClientAdmissionPrepareResult { kPrepared, kBusy, kInvalid };
enum class ClientAdmissionResponseDisposition {
  kApply,
  kRetainUntilExpiry,
  kReconcileStatus,
  kInvalidate,
};

struct ClientAdmissionOperation {
  ClientAdmissionAction action = ClientAdmissionAction::kNone;
  uint32_t local_user_index = 0;
  uint64_t lifecycle_token = 0;
  uint32_t title_id = 0;
  uint64_t local_user_xuid = 0;
  std::string directory_session_id;
  std::string attempt_id;
  std::string capability;
  std::string admission_generation;
  uint64_t expected_revision = 0;
  uint64_t discovery_socket = 0;
  uint32_t peer_ipv4 = 0;
  uint16_t peer_port = 0;
  std::chrono::steady_clock::time_point request_started_at{};
  std::shared_ptr<ClientAdmissionSocketOwner> socket_owner;
};

struct ClientAdmissionCancellation {
  uint32_t local_user_index = 0;
  uint64_t lifecycle_token = 0;
  std::string directory_session_id;
  std::string attempt_id;
  std::string capability;
  std::string admission_generation;
  uint64_t lease_revision = 0;
  bool admission_armed = false;
  uint64_t discovery_socket = 0;
  std::shared_ptr<ClientAdmissionSocketOwner> socket_owner;
};

enum class ClientAdmissionTransportAction { kArm, kStatus, kRenew, kRevoke, kDelete };

struct ClientAdmissionTransportRequest {
  ClientAdmissionTransportAction action = ClientAdmissionTransportAction::kStatus;
  uint32_t local_user_index = 0;
  uint64_t lifecycle_token = 0;
  std::string directory_session_id;
  std::string attempt_id;
  std::string capability;
  std::string admission_generation;
  uint64_t expected_revision = 0;
  std::chrono::steady_clock::time_point request_started_at{};
};

struct ClientAdmissionTransportResponse {
  std::optional<uint32_t> status;
  std::string body;
  std::optional<std::chrono::steady_clock::time_point> completed_at;
};

// Generic, process-local client authority. HTTP and NAT ownership stay outside
// this reducer so its lease timing and stale-response behavior are deterministic
// under a fake monotonic clock.
class ClientAdmissionLeaseState {
 public:
  using Clock = std::chrono::steady_clock;

  bool BindExactDiscovery(uint32_t local_user_index, uint64_t lifecycle_token, uint32_t title_id,
                          uint64_t local_user_xuid, const DirectoryTraversalAttempt& attempt,
                          std::shared_ptr<const SessionRecord> session,
                          bool session_confirmed = true);
  bool ConfirmExactSession(std::shared_ptr<const SessionRecord> session);
  bool MatchesExactSession(const SessionRecord& session) const { return ExactSessionMatches(session); }
  std::optional<ClientAdmissionOperation> BeginOperation(
      uint64_t discovery_socket, uint32_t peer_ipv4, uint16_t peer_port,
      Clock::time_point request_started_at = Clock::now());
  ClientAdmissionApplyResult ApplyResponse(const ClientAdmissionOperation& operation,
                                           const DirectoryAdmissionState& admission,
                                           Clock::time_point response_received_at = Clock::now());
  ClientAdmissionApplyResult ApplyTransportFailure(
      const ClientAdmissionOperation& operation,
      Clock::time_point response_received_at = Clock::now());
  ClientAdmissionApplyResult EndAttemptAuthority(const ClientAdmissionOperation& operation);
  bool ExpireIfNeeded(Clock::time_point now = Clock::now());
  void Invalidate();
  ClientAdmissionAction NextAction(Clock::time_point now = Clock::now()) const;
  bool ValidateLiveness(uint32_t current_title_id, std::optional<uint64_t> current_user_xuid) const;
  std::optional<ReadyAcceptedSessionCandidate> ReadyCandidate(
      uint32_t current_title_id, std::optional<uint64_t> current_user_xuid,
      Clock::time_point now = Clock::now()) const;

  bool bound() const { return !attempt_id_.empty(); }
  bool leased() const { return !admission_generation_.empty(); }
  bool host_ready() const { return host_ready_; }
  bool renewal_uncertain() const { return renewal_uncertainty_.has_value(); }
  bool has_ever_been_ready() const { return has_ever_been_ready_; }
  bool host_completed() const { return host_completed_; }
  uint32_t local_user_index() const { return local_user_index_; }
  uint64_t lifecycle_token() const { return lifecycle_token_; }
  uint32_t title_id() const { return title_id_; }
  uint64_t local_user_xuid() const { return local_user_xuid_; }
  const std::string& directory_session_id() const { return directory_session_id_; }
  const std::string& attempt_id() const { return attempt_id_; }
  const std::string& capability() const { return capability_; }
  const std::string& purpose() const { return purpose_; }
  const std::string& admission_generation() const { return admission_generation_; }
  uint64_t lease_revision() const { return lease_revision_; }
  Clock::time_point lease_deadline() const { return lease_deadline_; }
  Clock::time_point renewal_deadline() const { return renewal_deadline_; }

 private:
  bool Matches(const ClientAdmissionOperation& operation) const;
  bool ExactSessionMatches(const SessionRecord& session) const;
  ClientAdmissionApplyResult InstallLease(const DirectoryAdmissionState& admission,
                                          Clock::time_point request_started_at, bool may_extend);
  void Terminalize();

  uint32_t local_user_index_ = 0;
  uint64_t lifecycle_token_ = 0;
  uint32_t title_id_ = 0;
  uint64_t local_user_xuid_ = 0;
  std::string directory_session_id_;
  std::string attempt_id_;
  std::string capability_;
  std::string purpose_;
  std::string admission_generation_;
  uint64_t lease_revision_ = 0;
  Clock::time_point lease_deadline_{};
  Clock::time_point renewal_deadline_{};
  bool host_ready_ = false;
  bool has_ever_been_ready_ = false;
  bool host_completed_ = false;
  struct RenewalUncertainty {
    std::string admission_generation;
    uint64_t previous_revision = 0;
    Clock::time_point request_started_at{};
  };
  std::optional<RenewalUncertainty> renewal_uncertainty_;
  bool session_confirmed_ = false;
  std::shared_ptr<const SessionRecord> pending_session_;
  std::weak_ptr<const SessionRecord> live_session_;
  std::array<uint8_t, 8> xbox_session_id_{};
  std::array<uint8_t, 16> xbox_session_key_{};
  std::array<uint8_t, 6> xbox_ethernet_address_{};
  std::array<uint8_t, 20> xbox_online_address_{};
  uint32_t xbox_host_ipv4_ = 0;
  uint16_t xbox_host_port_ = 0;
  uint64_t xbox_nonce_ = 0;
  uint64_t xbox_host_xuid_ = 0;
};

bool ClientAdmissionMayReplaceLifecycle(bool join_by_code_action,
                                        const ClientAdmissionLeaseState* existing);

struct HostAdmissionPollAttempt {
  std::string attempt_id;
  std::string capability;
  std::string purpose;
  std::string admission_generation;
  uint64_t lease_revision = 0;
  uint32_t admission_expires_in_ms = 0;
  bool host_ready = false;
};

struct HostAdmissionReservation {
  std::string directory_session_id;
  std::string attempt_id;
  std::string admission_generation;
  uint64_t lease_revision = 0;
  uint64_t discovery_socket = 0;
  uint32_t peer_ipv4 = 0;
  uint16_t peer_port = 0;
  uint64_t xuid = 0;
  uint64_t reservation_id = 0;
  explicit operator bool() const { return reservation_id != 0; }
};

enum class HostAdmissionReservationStatus {
  kNoMatch,
  kAmbiguous,
  kReserved,
  kDuplicateReservation,
  kConsumedDuplicate,
};

struct HostAdmissionReservationResult {
  HostAdmissionReservationStatus status = HostAdmissionReservationStatus::kNoMatch;
  HostAdmissionReservation reservation;
};

struct HostAdmissionCompletion {
  std::string directory_session_id;
  std::string attempt_id;
  std::string capability;
};

// Process-local host authority. Callers snapshot NAT state before entering this
// lock and release it before taking any session-membership lock.
class HostAdmissionGrantStore {
 public:
  using Clock = std::chrono::steady_clock;

  void ApplyAuthenticatedPoll(std::string_view directory_session_id,
                              std::span<const HostAdmissionPollAttempt> attempts,
                              Clock::time_point poll_started_at = Clock::now());
  HostAdmissionReservationResult Reserve(std::string_view directory_session_id,
                                         uint64_t discovery_socket, uint32_t peer_ipv4,
                                         uint16_t peer_port,
                                         std::span<const std::string> acknowledged_attempt_ids,
                                         uint64_t xuid, Clock::time_point now = Clock::now());
  void Finish(const HostAdmissionReservation& reservation, bool committed,
              Clock::time_point now = Clock::now());
  void InvalidateSession(std::string_view directory_session_id);
  void Clear();
  std::vector<HostAdmissionCompletion> TakeCompletions();
  std::optional<std::string> hosted_directory_session() const;
  size_t available_grant_count(Clock::time_point now = Clock::now()) const;
  // The caller supplies only exact native-source acknowledgments from NatProbe.
  // This read-only check discloses no grant data and spends no admission.
  bool HasCurrentPrivateDiscoveryGrant(std::string_view directory_session_id,
      std::span<const std::string> acknowledged_attempt_ids,Clock::time_point now=Clock::now()) const;
  // True once any grant (current, consumed, expired or invalidated) exists for
  // one of these attempts; before that, the attempt is still awaiting its grant.
  bool HasPrivateDiscoveryGrantRecord(std::string_view directory_session_id,
      std::span<const std::string> acknowledged_attempt_ids) const;

 private:
  struct Grant {
    std::string directory_session_id;
    std::string attempt_id;
    std::string capability;
    std::string admission_generation;
    uint64_t lease_revision = 0;
    Clock::time_point expires_at{};
    uint64_t reservation_id = 0;
    uint64_t reserved_socket = 0;
    uint32_t reserved_ipv4 = 0;
    uint16_t reserved_port = 0;
    uint64_t reserved_xuid = 0;
    uint64_t consumed_xuid = 0;
    bool invalidated_while_reserved = false;
  };

  void InvalidateGrantLocked(Grant& grant);
  mutable std::mutex mutex_;
  std::unordered_map<std::string, Grant> grants_;
  std::vector<HostAdmissionCompletion> completions_;
  std::string hosted_directory_session_;
  uint64_t next_reservation_id_ = 1;
};

enum class DirectoryHeartbeatDisposition {
  kAccepted,
  kRetrySameRegistration,
  kRecoverRegistration,
  kRejected,
};

enum class DirectoryHostPollDisposition {
  kAccepted,
  kRetainUntilExpiry,
  kRecoverRegistration,
  kRejectSnapshot,
};

struct DirectoryHostPollRuntimeState {
  std::string directory_session_id;
  std::string registration_token;
  std::string public_invite_code;
  std::unordered_set<std::string> host_attempts;
  std::unordered_map<std::string, HostAdmissionPollAttempt> private_attempts;
  std::vector<HostAdmissionCompletion> pending_completions;
  bool recovering = false;
};

struct DirectoryHostPollTransition {
  bool recover_now = false;
};

// Keep transport and server failures distinct from an authoritative 404. This
// policy is public only so the host lifecycle can be covered without real HTTP
// timing in unit tests.
DirectoryHeartbeatDisposition ClassifyDirectoryHeartbeatResponse(std::optional<uint32_t> status,
                                                                 bool valid_session_id);
DirectoryHostPollDisposition ClassifyDirectoryHostPollResponse(std::optional<uint32_t> status,
                                                               bool valid_snapshot);
std::optional<std::vector<DirectoryTraversalAttempt>> ParseDirectoryHostPollSnapshot(
    std::string_view body, std::string_view directory_session_id);
DirectoryHostPollTransition ApplyDirectoryHostPollResult(
    DirectoryHostPollDisposition disposition, std::span<const DirectoryTraversalAttempt> attempts,
    DirectoryHostPollRuntimeState& state, HostAdmissionGrantStore* admission_grants,
    SessionRecord& hosted,
    HostAdmissionGrantStore::Clock::time_point poll_started_at =
        HostAdmissionGrantStore::Clock::now());
std::optional<std::string> NormalizeDirectoryInviteCode(std::string_view value);
bool WriteActiveInviteCodeFile(const std::filesystem::path& path, std::string_view code);
void RemoveActiveInviteCodeFile(const std::filesystem::path& path);
std::optional<DirectorySession> ParseInviteCodeSessionResponse(std::string_view body,
                                                               uint32_t title_id,
                                                               std::string_view build_id);
std::optional<DirectoryInviteJoinAttempt> ParseInviteCodeJoinAttemptResponse(
    std::string_view body, uint32_t title_id, std::string_view build_id);
std::optional<DirectoryAdmissionState> ParseDirectoryAdmissionResponse(std::string_view body);
ClientAdmissionResponseDisposition ClassifyClientAdmissionResponse(ClientAdmissionAction action,
                                                                   std::optional<uint32_t> status,
                                                                   bool valid_body);

class SessionDirectoryClient {
 public:
  using LocalUserIdentityProvider = std::function<std::optional<uint64_t>(uint32_t)>;
  using ClientAdmissionTransport =
      std::function<ClientAdmissionTransportResponse(const ClientAdmissionTransportRequest&)>;
  using InviteJoinAttemptTransport =
      std::function<std::optional<DirectoryInviteJoinAttempt>(std::string_view, uint32_t)>;
  using JoinAttemptCompletionTransport =
      std::function<void(const DirectoryTraversalAttempt&)>;
  explicit SessionDirectoryClient(LocalUserIdentityProvider user_identity = {},
                                  ClientAdmissionTransport client_admission_transport = {},
                                  bool automatic_client_admission_driver = true,
                                  InviteJoinAttemptTransport invite_join_attempt_transport = {},
                                  JoinAttemptCompletionTransport
                                      join_attempt_completion_transport = {});
  ~SessionDirectoryClient();
  SessionDirectoryClient(const SessionDirectoryClient&) = delete;
  SessionDirectoryClient& operator=(const SessionDirectoryClient&) = delete;

  void StartHosting(const std::shared_ptr<SessionRecord>& session, uint32_t title_id,
                    uint16_t discovery_port,
                    std::shared_ptr<HostAdmissionGrantStore> admission_grants = {});
  void StopHosting();
  std::vector<DirectorySession> List(uint32_t title_id) const;
  std::vector<DirectoryListing> ListSearchable(uint32_t title_id,
                                               uint64_t exclude_host_xuid) const;
  void RequestList(uint32_t title_id) const;
  std::optional<std::vector<DirectorySession>> CachedList(uint32_t title_id) const;
  std::optional<DirectorySession> ResolveInviteCode(std::string_view code, uint32_t title_id) const;
  std::optional<DirectoryInviteJoinAttempt> CreateInviteCodeJoinAttempt(std::string_view code,
                                                                        uint32_t title_id) const;
  std::optional<DirectoryTraversalAttempt> CreateJoinAttempt(const std::string& session_id) const;
  void CompleteJoinAttempt(const DirectoryTraversalAttempt& attempt) const;
  ClientAdmissionPrepareResult PrepareClientAdmission(uint32_t local_user_index, uint32_t title_id,
                                                      const DirectoryTraversalAttempt& attempt,
                                                      const SessionRecord& discovered,
                                                      uint64_t discovery_socket);
  bool ConfirmClientAdmissionSession(uint32_t local_user_index,
                                     const std::shared_ptr<const SessionRecord>& session);
  void SetClientAdmissionTitle(uint32_t title_id);
  void SetClientAdmissionUserIdentity(uint32_t local_user_index, std::optional<uint64_t> xuid);
  void StopClientAdmission(uint32_t local_user_index);
  void QueueGameplayAdmission(const std::shared_ptr<SessionRecord>& session,
                              uint32_t user_index, uint64_t xuid,
                              const DirectoryTraversalAttempt& attempt,
                              const std::string& generation);
  void StopAllClientAdmissions();
  bool HasClientAdmission(uint32_t local_user_index) const;
  std::optional<uint64_t> ClientAdmissionLifecycleToken(
      uint32_t local_user_index) const;
  bool HasProtectedClientAdmission(uint32_t local_user_index) const;
  std::optional<ClientAdmissionSocketLease> AcquireClientAdmissionSocket(
      uint32_t local_user_index, const SessionRecord& session);
  std::optional<ReadyAcceptedSessionCandidate> ReadyClientAdmission(
      uint32_t local_user_index);
  // Production normally drives this lifecycle from its worker. Embedders and
  // deterministic tests may instead disable that worker and poll explicitly.
  void PollClientAdmissions(
      std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now());

 private:
  class Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace rex::system::xam
