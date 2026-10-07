#pragma once

#include <array>
#include <chrono>
#include <cstdint>
#include <mutex>
#include <optional>
#include <vector>

namespace rex::system::xam {
using ArbitrationToken = std::array<uint8_t, 16>;

struct ArbitrationIdentity {
  std::array<uint8_t, 8> session_id{};
  std::array<uint8_t, 16> exchange_key{};
  ArbitrationToken incarnation{};
  uint64_t nonce = 0;
  uint64_t host_xuid = 0;
  uint64_t host_machine_id = 0;
  bool operator==(const ArbitrationIdentity&) const = default;
};
struct ArbitrationEndpoint {
  uint32_t ipv4 = 0; // Native network byte order.
  uint16_t port = 0; // Host byte order.
  bool operator==(const ArbitrationEndpoint&) const = default;
};
struct ArbitrationJoinClaim {
  uint64_t xuid = 0;
  uint64_t machine_id = 0;
  ArbitrationEndpoint endpoint{};
  ArbitrationToken challenge{};
  ArbitrationToken credential{};
};
struct ArbitrationRegistration {
  ArbitrationIdentity identity{};
  uint64_t xuid = 0;
  uint64_t machine_id = 0;
  ArbitrationEndpoint endpoint{};
  ArbitrationToken credential{};
  ArbitrationToken attempt{};
};
struct ArbitrationRegistrant {
  uint64_t machine_id = 0;
  uint32_t trustworthiness = 0; // LAN continuity does not authenticate Xbox Live ownership.
  std::vector<uint64_t> xuids;
};
struct ArbitrationSnapshot {
  ArbitrationIdentity identity{};
  uint64_t revision = 0;
  std::vector<ArbitrationRegistrant> registrants;
};
enum class ArbitrationStatus {
  kAccepted, kReplay, kClosed, kInvalid, kUnknownMember, kCredentialMismatch,
  kMachineConflict, kRetiredAttempt, kExhausted
};
struct ArbitrationJoinResult {
  ArbitrationStatus status = ArbitrationStatus::kInvalid;
  ArbitrationToken credential{};
  bool accepted() const {
    return status == ArbitrationStatus::kAccepted || status == ArbitrationStatus::kReplay;
  }
};

// Private per-hosted-record authority. Only a successful, real roster admission
// invokes Admit; joining alone never registers. This current platform exposes
// one local profile per runtime, so each admitted machine owns one member.
// Callers retain registry -> record -> authority lock order and do no transport
// work while holding any of those locks.
class SessionArbitrationAuthority final {
 public:
  using Clock = std::chrono::steady_clock;
  static constexpr size_t kMaxMembers = 8;
  static constexpr size_t kMaxRetiredAttempts = 64;
  static constexpr auto kInitialJoinRetryWindow = std::chrono::seconds(30);

  SessionArbitrationAuthority(ArbitrationIdentity identity, ArbitrationToken local_credential);
  ArbitrationJoinResult CheckAdmission(const ArbitrationJoinClaim& claim,
                                       Clock::time_point now) const;
  ArbitrationJoinResult Admit(const ArbitrationJoinClaim& claim,
                              ArbitrationToken new_credential, Clock::time_point now);
  ArbitrationStatus Register(const ArbitrationRegistration& request);
  // Only the host wire handler calls these after observing recvfrom source and
  // verifying the complete request HMAC with this private continuity token.
  // A first registration may use a separately owned socket; replay pins its
  // observed endpoint and cannot redirect either endpoint.
  std::optional<ArbitrationToken> CredentialForVerification(
      const ArbitrationIdentity& identity, uint64_t xuid, uint64_t machine_id) const;
  ArbitrationStatus RegisterFromVerifiedEndpoint(const ArbitrationRegistration& request);
  ArbitrationStatus RegisterLocal(uint64_t xuid, uint64_t machine_id, uint64_t nonce,
                                  const ArbitrationToken& attempt);
  bool Remove(uint64_t xuid);
  std::vector<uint64_t> ExpireUnconfirmed(Clock::time_point now);
  void Invalidate();
  std::optional<ArbitrationSnapshot> Snapshot() const;
  std::optional<uint64_t> MachineId(uint64_t xuid) const;
  ArbitrationIdentity identity() const { return identity_; }

 private:
  struct Member {
    bool occupied = false;
    bool local = false;
    bool registered = false;
    bool confirmed = false;
    uint64_t xuid = 0;
    uint64_t machine_id = 0;
    ArbitrationEndpoint endpoint{}; // Initial admission socket source.
    ArbitrationEndpoint registration_endpoint{}; // Pinned first-registration source.
    ArbitrationToken join_challenge{};
    ArbitrationToken credential{};
    ArbitrationToken registration_attempt{};
    Clock::time_point initial_retry_deadline{};
  };
  ArbitrationJoinResult CheckAdmissionLocked(const ArbitrationJoinClaim& claim,
                                              Clock::time_point now) const;
  ArbitrationStatus RegisterLocked(Member& member, const ArbitrationToken& attempt);
  ArbitrationStatus RegisterRemoteLocked(const ArbitrationRegistration& request,
                                         bool verified_endpoint_transfer);
  ArbitrationIdentity identity_;
  mutable std::mutex mutex_;
  bool alive_ = false;
  uint64_t revision_ = 1;
  std::array<Member, kMaxMembers> members_{};
  std::array<ArbitrationToken, kMaxRetiredAttempts> retired_{};
  size_t retired_count_ = 0;
};

// Uses the existing operating-system cryptographic randomness seam; failures
// and all-zero outputs remain explicit rather than becoming authority IDs.
std::optional<ArbitrationToken> NewArbitrationToken();
std::optional<uint64_t> NewArbitrationMachineId();
} // namespace rex::system::xam
