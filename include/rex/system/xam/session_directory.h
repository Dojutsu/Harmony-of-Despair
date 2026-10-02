#pragma once

#include <chrono>
#include <filesystem>
#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <span>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <rex/cvar.h>

namespace rex::system::xam {

struct SessionRecord;

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
  HostAdmissionReservationResult Reserve(
      std::string_view directory_session_id, uint64_t discovery_socket,
      uint32_t peer_ipv4, uint16_t peer_port,
      std::span<const std::string> acknowledged_attempt_ids, uint64_t xuid,
      Clock::time_point now = Clock::now());
  void Finish(const HostAdmissionReservation& reservation, bool committed,
              Clock::time_point now = Clock::now());
  void InvalidateSession(std::string_view directory_session_id);
  void Clear();
  std::vector<HostAdmissionCompletion> TakeCompletions();
  std::optional<std::string> hosted_directory_session() const;
  size_t available_grant_count(Clock::time_point now = Clock::now()) const;

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
DirectoryHostPollDisposition ClassifyDirectoryHostPollResponse(
    std::optional<uint32_t> status, bool valid_snapshot);
std::optional<std::vector<DirectoryTraversalAttempt>> ParseDirectoryHostPollSnapshot(
    std::string_view body, std::string_view directory_session_id);
DirectoryHostPollTransition ApplyDirectoryHostPollResult(
    DirectoryHostPollDisposition disposition,
    std::span<const DirectoryTraversalAttempt> attempts,
    DirectoryHostPollRuntimeState& state,
    HostAdmissionGrantStore* admission_grants, SessionRecord& hosted,
    HostAdmissionGrantStore::Clock::time_point poll_started_at =
        HostAdmissionGrantStore::Clock::now());
std::optional<std::string> NormalizeDirectoryInviteCode(std::string_view value);
bool WriteActiveInviteCodeFile(const std::filesystem::path& path, std::string_view code);
void RemoveActiveInviteCodeFile(const std::filesystem::path& path);
std::optional<DirectorySession> ParseInviteCodeSessionResponse(std::string_view body,
                                                               uint32_t title_id,
                                                               std::string_view build_id);

class SessionDirectoryClient {
 public:
  SessionDirectoryClient();
  ~SessionDirectoryClient();
  SessionDirectoryClient(const SessionDirectoryClient&) = delete;
  SessionDirectoryClient& operator=(const SessionDirectoryClient&) = delete;

  void StartHosting(const std::shared_ptr<SessionRecord>& session, uint32_t title_id,
                    uint16_t discovery_port,
                    std::shared_ptr<HostAdmissionGrantStore> admission_grants = {});
  void StopHosting();
  std::vector<DirectorySession> List(uint32_t title_id) const;
  void RequestList(uint32_t title_id) const;
  std::optional<std::vector<DirectorySession>> CachedList(uint32_t title_id) const;
  std::optional<DirectorySession> ResolveInviteCode(std::string_view code,
                                                    uint32_t title_id) const;
  std::optional<DirectoryTraversalAttempt> CreateJoinAttempt(const std::string& session_id) const;
  void CompleteJoinAttempt(const DirectoryTraversalAttempt& attempt) const;

 private:
  class Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace rex::system::xam
