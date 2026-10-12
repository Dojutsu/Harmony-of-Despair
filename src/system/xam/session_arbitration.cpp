#include <rex/system/xam/session_arbitration.h>
#include <rex/platform.h>

#include <algorithm>
#include <cerrno>
#include <cstring>
#include <span>

#if REX_PLATFORM_WIN32
#include <windows.h>
#include <bcrypt.h>
#elif REX_PLATFORM_LINUX
#include <sys/random.h>
#if REX_PLATFORM_GNU_LINUX
#include <openssl/crypto.h>
#endif
#endif

namespace rex::system::xam {
namespace {
template <size_t N> bool Nonzero(const std::array<uint8_t, N>& bytes) {
  return std::any_of(bytes.begin(), bytes.end(), [](uint8_t value) { return value != 0; });
}
bool ValidEndpoint(ArbitrationEndpoint value) { return value.ipv4 != 0 && value.port != 0; }
bool CredentialEqual(const ArbitrationToken& left, const ArbitrationToken& right) {
#if REX_PLATFORM_GNU_LINUX
  return CRYPTO_memcmp(left.data(), right.data(), left.size()) == 0;
#else
  // Same fixed-length XOR reduction used by the existing invite LAN seam.
  // CNG supplies HMAC/randomness on Windows but exposes no generic compare.
  uint8_t difference = 0;
  for (size_t i = 0; i < left.size(); ++i) difference |= left[i] ^ right[i];
  return difference == 0;
#endif
}
bool RandomBytes(std::span<uint8_t> bytes) {
#if REX_PLATFORM_WIN32
  return BCryptGenRandom(nullptr, bytes.data(), ULONG(bytes.size()), BCRYPT_USE_SYSTEM_PREFERRED_RNG) >= 0;
#elif REX_PLATFORM_LINUX
  size_t completed = 0;
  while (completed < bytes.size()) {
    const auto count = ::getrandom(bytes.data() + completed, bytes.size() - completed, 0);
    if (count < 0) { if (errno == EINTR) continue; return false; }
    if (!count) return false;
    completed += static_cast<size_t>(count);
  }
  return true;
#else
  (void)bytes; return false;
#endif
}
} // namespace

std::optional<ArbitrationToken> NewArbitrationToken() {
  for (unsigned attempt = 0; attempt < 8; ++attempt) {
    ArbitrationToken token{};
    if (!RandomBytes(token)) return std::nullopt;
    if (Nonzero(token)) return token;
  }
  return std::nullopt;
}
std::optional<uint64_t> NewArbitrationMachineId() {
  for (unsigned attempt = 0; attempt < 8; ++attempt) {
    std::array<uint8_t, 8> bytes{};
    if (!RandomBytes(bytes)) return std::nullopt;
    uint64_t value = 0;
    for (const auto byte : bytes) value = (value << 8) | byte;
    if (value) return value;
  }
  return std::nullopt;
}

SessionArbitrationAuthority::SessionArbitrationAuthority(ArbitrationIdentity identity,
                                                       ArbitrationToken local_credential)
    : identity_(identity) {
  alive_ = Nonzero(identity.session_id) && Nonzero(identity.exchange_key) &&
           Nonzero(identity.incarnation) && identity.nonce && identity.host_xuid &&
           identity.host_machine_id && Nonzero(local_credential);
  if (!alive_) return;
  auto& host = members_[0]; host.occupied = true; host.local = true;
  host.xuid = identity.host_xuid; host.machine_id = identity.host_machine_id;
  host.credential = local_credential;
}

ArbitrationJoinResult SessionArbitrationAuthority::CheckAdmissionLocked(
    const ArbitrationJoinClaim& claim, Clock::time_point now) const {
  if (!alive_) return {ArbitrationStatus::kClosed, {}};
  if (!claim.xuid || !claim.machine_id || claim.xuid == identity_.host_xuid ||
      !ValidEndpoint(claim.endpoint) || !Nonzero(claim.challenge))
    return {ArbitrationStatus::kInvalid, {}};
  if (std::any_of(retired_.begin(), retired_.begin() + static_cast<ptrdiff_t>(retired_count_),
                  [&](const auto& attempt) { return attempt.challenge == claim.challenge; }))
    return {ArbitrationStatus::kRetiredAttempt, {}};
  bool vacant = false;
  for (const auto& member : members_) {
    if (!member.occupied) { vacant = true; continue; }
    if (member.join_challenge == claim.challenge && member.xuid != claim.xuid)
      return {ArbitrationStatus::kRetiredAttempt, {}};
    if (member.machine_id == claim.machine_id && member.xuid != claim.xuid)
      return {ArbitrationStatus::kMachineConflict, {}};
    if (member.xuid != claim.xuid) continue;
    if (member.local || member.machine_id != claim.machine_id || member.endpoint != claim.endpoint)
      return {ArbitrationStatus::kCredentialMismatch, {}};
    const bool credential_matches = Nonzero(claim.credential) && CredentialEqual(claim.credential, member.credential);
    const bool initial_retry = !Nonzero(claim.credential) && claim.challenge == member.join_challenge &&
                               now < member.initial_retry_deadline;
    if (!credential_matches && !initial_retry)
      return {ArbitrationStatus::kCredentialMismatch, {}};
    return {ArbitrationStatus::kReplay, member.credential};
  }
  if (Nonzero(claim.credential)) return {ArbitrationStatus::kCredentialMismatch, {}};
  if (retired_count_ == retired_.size() || !vacant) return {ArbitrationStatus::kExhausted, {}};
  return {ArbitrationStatus::kAccepted, {}};
}
ArbitrationJoinResult SessionArbitrationAuthority::CheckAdmission(
    const ArbitrationJoinClaim& claim, Clock::time_point now) const {
  std::lock_guard lock(mutex_); return CheckAdmissionLocked(claim, now);
}
ArbitrationJoinResult SessionArbitrationAuthority::Admit(
    const ArbitrationJoinClaim& claim, ArbitrationToken new_credential, Clock::time_point now) {
  std::lock_guard lock(mutex_);
  auto result = CheckAdmissionLocked(claim, now);
  if (result.status != ArbitrationStatus::kAccepted) {
    if (result.status == ArbitrationStatus::kReplay && Nonzero(claim.credential))
      for (auto& member : members_) if (member.occupied && member.xuid == claim.xuid) member.confirmed = true;
    return result;
  }
  if (!Nonzero(new_credential)) return {ArbitrationStatus::kInvalid, {}};
  if (std::any_of(members_.begin(), members_.end(), [&](const auto& member) {
        return member.occupied && CredentialEqual(member.credential, new_credential);
      }) || std::any_of(retired_.begin(), retired_.begin() + static_cast<ptrdiff_t>(retired_count_),
                       [&](const auto& attempt) {
                         return Nonzero(attempt.expiry_credential) &&
                             CredentialEqual(attempt.expiry_credential, new_credential);
                       })) return {ArbitrationStatus::kInvalid, {}};
  auto it = std::find_if(members_.begin(), members_.end(), [](const auto& member) { return !member.occupied; });
  if (it == members_.end()) return {ArbitrationStatus::kExhausted, {}};
  it->occupied = true; it->xuid = claim.xuid; it->machine_id = claim.machine_id;
  it->endpoint = claim.endpoint; it->join_challenge = claim.challenge; it->credential = new_credential;
  it->initial_retry_deadline = now + kInitialJoinRetryWindow;
  ++revision_;
  return {ArbitrationStatus::kAccepted, new_credential};
}
ArbitrationStatus SessionArbitrationAuthority::RegisterLocked(
    Member& member, const ArbitrationToken& attempt) {
  if (!Nonzero(attempt)) return ArbitrationStatus::kInvalid;
  if (member.registered)
    return member.registration_attempt == attempt ? ArbitrationStatus::kReplay : ArbitrationStatus::kRetiredAttempt;
  member.registered = true; member.registration_attempt = attempt; ++revision_;
  return ArbitrationStatus::kAccepted;
}
ArbitrationStatus SessionArbitrationAuthority::RegisterRemoteLocked(
    const ArbitrationRegistration& request, bool verified_endpoint_transfer) {
  if (!alive_) return ArbitrationStatus::kClosed;
  if (request.identity != identity_ || !request.xuid || !request.machine_id ||
      !Nonzero(request.credential) || !ValidEndpoint(request.endpoint)) return ArbitrationStatus::kInvalid;
  auto it = std::find_if(members_.begin(), members_.end(), [&](const auto& member) {
    return member.occupied && member.xuid == request.xuid;
  });
  if (it == members_.end()) return ArbitrationStatus::kUnknownMember;
  if (it->local || it->machine_id != request.machine_id ||
      !CredentialEqual(it->credential, request.credential)) return ArbitrationStatus::kCredentialMismatch;
  const auto required_endpoint = it->registered ? it->registration_endpoint : it->endpoint;
  if (required_endpoint != request.endpoint && (it->registered || !verified_endpoint_transfer))
    return ArbitrationStatus::kCredentialMismatch;
  const auto result = RegisterLocked(*it, request.attempt);
  if (result == ArbitrationStatus::kAccepted) it->registration_endpoint = request.endpoint;
  return result;
}
ArbitrationStatus SessionArbitrationAuthority::Register(const ArbitrationRegistration& request) {
  std::lock_guard lock(mutex_); return RegisterRemoteLocked(request, false);
}
ArbitrationStatus SessionArbitrationAuthority::RegisterFromVerifiedEndpoint(
    const ArbitrationRegistration& request) {
  std::lock_guard lock(mutex_); return RegisterRemoteLocked(request, true);
}
std::optional<ArbitrationSnapshot> SessionArbitrationAuthority::RegisterFromVerifiedEndpointIf(
    const ArbitrationRegistration& request,
    const std::function<bool(const ArbitrationSnapshot&)>& prepare_reply) {
  if(!prepare_reply)return std::nullopt;
  std::lock_guard lock(mutex_);
  auto previous=members_;const auto revision=revision_;
  struct Restore {
    SessionArbitrationAuthority& owner;decltype(members_)& previous;uint64_t revision;bool committed=false;
    ~Restore(){if(!committed){owner.members_=previous;owner.revision_=revision;}
#if REX_PLATFORM_GNU_LINUX
      OPENSSL_cleanse(previous.data(),sizeof(previous));
#elif REX_PLATFORM_WIN32
      SecureZeroMemory(previous.data(),sizeof(previous));
#else
      { volatile uint8_t* bytes=reinterpret_cast<volatile uint8_t*>(previous.data());
        for(size_t i=0;i<sizeof(previous);++i)bytes[i]=0; }
#endif
    }
  } restore{*this,previous,revision};
  try {
    const auto status=RegisterRemoteLocked(request,true);
    if(status!=ArbitrationStatus::kAccepted&&status!=ArbitrationStatus::kReplay)return std::nullopt;
    ArbitrationSnapshot snapshot{identity_,revision_,{}};
    for(const auto& member:members_)if(member.occupied&&member.registered)
      snapshot.registrants.push_back({member.machine_id,0,{member.xuid}});
    if(!prepare_reply(snapshot))return std::nullopt;
    restore.committed=true;return snapshot;
  }catch(...){return std::nullopt;}
}
std::optional<ArbitrationToken> SessionArbitrationAuthority::CredentialForVerification(
    const ArbitrationIdentity& identity, uint64_t xuid, uint64_t machine_id) const {
  std::lock_guard lock(mutex_);
  if (!alive_ || identity != identity_ || !xuid || !machine_id) return std::nullopt;
  for (const auto& member : members_)
    if (member.occupied && !member.local && member.xuid == xuid && member.machine_id == machine_id)
      return member.credential;
  return std::nullopt;
}
std::optional<ArbitrationToken> SessionArbitrationAuthority::ExpiredJoinCredentialForVerification(
    const ArbitrationIdentity& identity, const ArbitrationJoinClaim& claim) const {
  std::lock_guard lock(mutex_);
  if (!alive_ || identity != identity_ || !claim.xuid || !claim.machine_id ||
      !ValidEndpoint(claim.endpoint) || !Nonzero(claim.challenge)) return std::nullopt;
  // A current admission for this XUID takes precedence over retired receipts.
  if (std::any_of(members_.begin(), members_.end(), [&](const auto& member) {
        return member.occupied && member.xuid == claim.xuid;
      })) return std::nullopt;
  for (size_t index = 0; index < retired_count_; ++index) {
    const auto& attempt = retired_[index];
    if (attempt.reason == RetirementReason::kUnconfirmedExpired &&
        attempt.xuid == claim.xuid && attempt.machine_id == claim.machine_id &&
        attempt.endpoint == claim.endpoint && attempt.challenge == claim.challenge &&
        Nonzero(attempt.expiry_credential)) return attempt.expiry_credential;
  }
  return std::nullopt;
}
ArbitrationStatus SessionArbitrationAuthority::RegisterLocal(
    uint64_t xuid, uint64_t machine_id, uint64_t nonce, const ArbitrationToken& attempt) {
  std::lock_guard lock(mutex_);
  if (!alive_) return ArbitrationStatus::kClosed;
  if (xuid != identity_.host_xuid || machine_id != identity_.host_machine_id || nonce != identity_.nonce)
    return ArbitrationStatus::kInvalid;
  return RegisterLocked(members_[0], attempt);
}
bool SessionArbitrationAuthority::Remove(uint64_t xuid) {
  std::lock_guard lock(mutex_);
  if (!alive_) return false;
  // Explicit cancellation also revokes older expiry receipts for this XUID.
  for (size_t index = 0; index < retired_count_; ++index) {
    auto& attempt = retired_[index];
    if (attempt.xuid == xuid) {
      attempt.expiry_credential = {};
      attempt.reason = RetirementReason::kLeft;
    }
  }
  auto it = std::find_if(members_.begin(), members_.end(), [&](const auto& member) {
    return member.occupied && member.xuid == xuid;
  });
  if (!alive_ || it == members_.end() || it->local) return false;
  // Once the bounded tombstone budget is exhausted, no further admission is
  // permitted. Never evict a still-live session's old challenge.
  if (retired_count_ < retired_.size())
    retired_[retired_count_++] = {it->join_challenge, it->xuid, it->machine_id, it->endpoint, {},
                                RetirementReason::kLeft};
  else alive_ = false;
  *it = Member{}; ++revision_; return true;
}
bool SessionArbitrationAuthority::RemoveBatch(std::span<const uint64_t> xuids) noexcept {
  std::lock_guard lock(mutex_);
  if (!alive_ || xuids.size() >= kMaxMembers || xuids.size() > retired_.size() - retired_count_)
    return false;
  std::array<size_t, kMaxMembers - 1> indices{};
  for (size_t index = 0; index < xuids.size(); ++index) {
    if (!xuids[index] || std::find(xuids.begin(), xuids.begin() + index, xuids[index]) != xuids.begin() + index)
      return false;
    const auto member = std::find_if(members_.begin(), members_.end(), [&](const auto& value) {
      return value.occupied && !value.local && value.xuid == xuids[index];
    });
    if (member == members_.end()) return false;
    indices[index] = size_t(member - members_.begin());
  }
  for (size_t index = 0; index < xuids.size(); ++index) {
    auto& member = members_[indices[index]];
    for (size_t retired = 0; retired < retired_count_; ++retired)
      if (retired_[retired].xuid == member.xuid) {
        retired_[retired].expiry_credential = {};
        retired_[retired].reason = RetirementReason::kLeft;
      }
    retired_[retired_count_++] = {member.join_challenge, member.xuid, member.machine_id,
                                member.endpoint, {}, RetirementReason::kLeft};
    member = Member{};
    ++revision_;
  }
  return true;
}
std::vector<uint64_t> SessionArbitrationAuthority::ExpireUnconfirmed(Clock::time_point now) {
  std::lock_guard lock(mutex_);
  std::vector<uint64_t> expired;
  if (!alive_) return expired;
  for (auto& member : members_) {
    if (!member.occupied || member.local || member.registered || member.confirmed ||
        now < member.initial_retry_deadline) continue;
    expired.push_back(member.xuid);
    if (retired_count_ < retired_.size())
      retired_[retired_count_++] = {member.join_challenge, member.xuid, member.machine_id,
                                  member.endpoint, member.credential,
                                  RetirementReason::kUnconfirmedExpired};
    else alive_ = false;
    member = Member{}; ++revision_;
  }
  return expired;
}
void SessionArbitrationAuthority::Invalidate() {
  std::lock_guard lock(mutex_); alive_ = false; members_ = {}; retired_ = {}; ++revision_;
}
std::optional<ArbitrationSnapshot> SessionArbitrationAuthority::Snapshot() const {
  std::lock_guard lock(mutex_);
  if (!alive_) return std::nullopt;
  ArbitrationSnapshot result; result.identity = identity_; result.revision = revision_;
  for (const auto& member : members_)
    if (member.occupied && member.registered)
      result.registrants.push_back({member.machine_id, 0, {member.xuid}});
  return result;
}
std::optional<uint64_t> SessionArbitrationAuthority::MachineId(uint64_t xuid) const {
  std::lock_guard lock(mutex_);
  if (!alive_) return std::nullopt;
  for (const auto& member : members_) if (member.occupied && member.xuid == xuid) return member.machine_id;
  return std::nullopt;
}
} // namespace rex::system::xam
