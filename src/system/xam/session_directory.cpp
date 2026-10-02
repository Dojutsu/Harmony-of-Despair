#include <rex/system/xam/session_directory.h>

#include <algorithm>
#include <cctype>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <future>
#include <iomanip>
#include <iterator>
#include <mutex>
#include <optional>
#include <sstream>
#include <thread>
#include <unordered_set>

#include <inja/third_party/include/nlohmann/json.hpp>

#include <rex/logging.h>
#include <rex/system/xam/session.h>
#include <rex/system/xam/nat_probe.h>

#if REX_PLATFORM_WIN32
#include <windows.h>

#include <bcrypt.h>
#include <winhttp.h>
#include <ws2tcpip.h>
#else
#include <unistd.h>
#endif

namespace rex::system::xam {

namespace {
bool IsLowerHex128(std::string_view value) {
  return value.size() == 32 && std::all_of(value.begin(), value.end(), [](char ch) {
           return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f');
         });
}

bool IsUrlToken(std::string_view value, size_t max_length);

std::optional<HostAdmissionGrantStore::Clock::time_point> AdmissionDeadline(
    HostAdmissionGrantStore::Clock::time_point poll_started_at, uint32_t admission_expires_in_ms) {
  if (!admission_expires_in_ms || admission_expires_in_ms == UINT32_MAX)
    return std::nullopt;
  const auto remaining = std::chrono::duration_cast<HostAdmissionGrantStore::Clock::duration>(
      std::chrono::milliseconds(admission_expires_in_ms));
  if (remaining <= HostAdmissionGrantStore::Clock::duration::zero() ||
      poll_started_at > HostAdmissionGrantStore::Clock::time_point::max() - remaining)
    return std::nullopt;
  return poll_started_at + remaining;
}
}  // namespace

bool ClientAdmissionLeaseState::BindExactDiscovery(uint32_t local_user_index,
                                                   uint64_t lifecycle_token, uint32_t title_id,
                                                   uint64_t local_user_xuid,
                                                   const DirectoryTraversalAttempt& attempt,
                                                   std::shared_ptr<const SessionRecord> session,
                                                   bool session_confirmed) {
  Invalidate();
  if (!session || !lifecycle_token || !title_id || !local_user_xuid || attempt.participant != 1 ||
      attempt.purpose != "invite_code_private_eligible" || !IsUrlToken(attempt.session_id, 64) ||
      !IsLowerHex128(attempt.attempt_id) || !IsLowerHex128(attempt.capability) ||
      !attempt.admission_generation.empty() || attempt.lease_revision ||
      attempt.admission_expires_in_ms || attempt.host_ready ||
      session->traversal_session_id != attempt.session_id ||
      session->traversal_attempt_id != attempt.attempt_id ||
      session->traversal_capability != attempt.capability || !session->discovery_address.ipv4 ||
      !session->discovery_address.port)
    return false;
  {
    std::lock_guard lock(*session->mutex);
    xbox_session_id_ = session->info.id;
    xbox_session_key_ = session->info.key;
    xbox_host_ipv4_ = session->info.host_address.ipv4;
    xbox_host_port_ = session->info.host_address.port;
    xbox_nonce_ = session->nonce;
    xbox_host_xuid_ = session->host_xuid;
  }
  local_user_index_ = local_user_index;
  lifecycle_token_ = lifecycle_token;
  title_id_ = title_id;
  local_user_xuid_ = local_user_xuid;
  directory_session_id_ = attempt.session_id;
  attempt_id_ = attempt.attempt_id;
  capability_ = attempt.capability;
  purpose_ = attempt.purpose;
  session_confirmed_ = session_confirmed;
  if (session_confirmed)
    live_session_ = session;
  else
    pending_session_ = std::move(session);
  return true;
}

bool ClientAdmissionLeaseState::ExactSessionMatches(const SessionRecord& session) const {
  std::lock_guard lock(*session.mutex);
  return session.info.id == xbox_session_id_ && session.info.key == xbox_session_key_ &&
         session.info.host_address.ipv4 == xbox_host_ipv4_ &&
         session.info.host_address.port == xbox_host_port_ && session.nonce == xbox_nonce_ &&
         session.host_xuid == xbox_host_xuid_ &&
         session.traversal_session_id == directory_session_id_ &&
         session.traversal_attempt_id == attempt_id_ && session.traversal_capability == capability_;
}

bool ClientAdmissionLeaseState::ConfirmExactSession(std::shared_ptr<const SessionRecord> session) {
  if (!bound() || !session || !ExactSessionMatches(*session)) {
    Terminalize();
    return false;
  }
  live_session_ = std::move(session);
  pending_session_.reset();
  session_confirmed_ = true;
  return true;
}

bool ClientAdmissionLeaseState::Matches(const ClientAdmissionOperation& operation) const {
  return bound() && operation.local_user_index == local_user_index_ &&
         operation.lifecycle_token == lifecycle_token_ && operation.title_id == title_id_ &&
         operation.local_user_xuid == local_user_xuid_ &&
         operation.directory_session_id == directory_session_id_ &&
         operation.attempt_id == attempt_id_ && operation.capability == capability_ &&
         operation.admission_generation == admission_generation_ &&
         operation.expected_revision == lease_revision_;
}

std::optional<ClientAdmissionOperation> ClientAdmissionLeaseState::BeginOperation(
    uint64_t discovery_socket, uint32_t peer_ipv4, uint16_t peer_port,
    Clock::time_point request_started_at) {
  if (ExpireIfNeeded(request_started_at))
    return std::nullopt;
  auto action = NextAction(request_started_at);
  if (action == ClientAdmissionAction::kNone)
    return std::nullopt;
  return ClientAdmissionOperation{action,          local_user_index_, lifecycle_token_,
                                  title_id_,       local_user_xuid_,  directory_session_id_,
                                  attempt_id_,     capability_,       admission_generation_,
                                  lease_revision_, discovery_socket,  peer_ipv4,
                                  peer_port,       request_started_at};
}

ClientAdmissionApplyResult ClientAdmissionLeaseState::InstallLease(
    const DirectoryAdmissionState& admission, Clock::time_point request_started_at,
    bool may_extend) {
  if ((admission.phase != "admission_awaiting_host" && admission.phase != "admission_ready") ||
      !IsLowerHex128(admission.admission_generation) || !admission.lease_revision ||
      !admission.admission_lease_duration_ms || !admission.admission_expires_in_ms ||
      admission.admission_lease_duration_ms == UINT32_MAX ||
      admission.admission_expires_in_ms == UINT32_MAX ||
      admission.host_ready != (admission.phase == "admission_ready")) {
    Invalidate();
    return ClientAdmissionApplyResult::kInvalidated;
  }
  auto returned_deadline = AdmissionDeadline(request_started_at, admission.admission_expires_in_ms);
  const uint32_t normal_renew_after_ms =
      std::max<uint32_t>(1, admission.admission_lease_duration_ms / 3);
  const uint32_t renew_after_ms =
      admission.admission_expires_in_ms > normal_renew_after_ms
          ? normal_renew_after_ms
          : std::max<uint32_t>(1, admission.admission_expires_in_ms / 3);
  auto returned_renewal = AdmissionDeadline(request_started_at, renew_after_ms);
  if (!returned_deadline || !returned_renewal || *returned_renewal >= *returned_deadline) {
    Invalidate();
    return ClientAdmissionApplyResult::kInvalidated;
  }

  if (may_extend) {
    admission_generation_ = admission.admission_generation;
    lease_revision_ = admission.lease_revision;
    lease_deadline_ = *returned_deadline;
    renewal_deadline_ = *returned_renewal;
  } else {
    // Status and replay responses for one revision may only shorten the
    // conservative local lifetime; they never renew it.
    lease_deadline_ = std::min(lease_deadline_, *returned_deadline);
    renewal_deadline_ = std::min(renewal_deadline_, *returned_renewal);
  }
  host_ready_ = admission.host_ready;
  has_ever_been_ready_ = has_ever_been_ready_ || host_ready_;
  return ClientAdmissionApplyResult::kApplied;
}

ClientAdmissionApplyResult ClientAdmissionLeaseState::ApplyResponse(
    const ClientAdmissionOperation& operation, const DirectoryAdmissionState& admission,
    Clock::time_point response_received_at) {
  if (!Matches(operation))
    return ClientAdmissionApplyResult::kIgnoredStale;
  // The old local deadline always wins over a delayed HTTP completion.
  if (leased() && response_received_at >= lease_deadline_) {
    Terminalize();
    return ClientAdmissionApplyResult::kInvalidated;
  }
  if (admission.attempt_id != attempt_id_ || admission.purpose != purpose_ ||
      admission.phase == "terminal") {
    Terminalize();
    return ClientAdmissionApplyResult::kInvalidated;
  }

  if (operation.action == ClientAdmissionAction::kArm) {
    if (leased() || admission.phase != "admission_awaiting_host" || admission.host_ready ||
        admission.lease_revision != 1 || !IsLowerHex128(admission.admission_generation)) {
      Terminalize();
      return ClientAdmissionApplyResult::kInvalidated;
    }
    renewal_uncertainty_.reset();
    return InstallLease(admission, operation.request_started_at, true);
  }

  if (!leased() || admission.admission_generation != admission_generation_) {
    Terminalize();
    return ClientAdmissionApplyResult::kInvalidated;
  }
  if (admission.lease_revision < lease_revision_)
    return ClientAdmissionApplyResult::kIgnoredStale;

  if (operation.action == ClientAdmissionAction::kRenew) {
    if (lease_revision_ == UINT64_MAX || admission.lease_revision != lease_revision_ + 1 ||
        admission.phase != "admission_awaiting_host" || admission.host_ready) {
      Terminalize();
      return ClientAdmissionApplyResult::kInvalidated;
    }
    renewal_uncertainty_.reset();
    return InstallLease(admission, operation.request_started_at, true);
  }

  if (operation.action != ClientAdmissionAction::kStatus) {
    Terminalize();
    return ClientAdmissionApplyResult::kInvalidated;
  }
  if (admission.lease_revision == lease_revision_) {
    renewal_uncertainty_.reset();
    return InstallLease(admission, operation.request_started_at, false);
  }
  const bool reconciles_uncertain_renewal =
      renewal_uncertainty_ && renewal_uncertainty_->admission_generation == admission_generation_ &&
      renewal_uncertainty_->previous_revision == lease_revision_ && lease_revision_ != UINT64_MAX &&
      admission.lease_revision == lease_revision_ + 1;
  if (!reconciles_uncertain_renewal || admission.phase != "admission_awaiting_host" ||
      admission.host_ready) {
    Terminalize();
    return ClientAdmissionApplyResult::kInvalidated;
  }
  renewal_uncertainty_.reset();
  return InstallLease(admission, operation.request_started_at, true);
}

ClientAdmissionApplyResult ClientAdmissionLeaseState::ApplyTransportFailure(
    const ClientAdmissionOperation& operation, Clock::time_point response_received_at) {
  if (!Matches(operation))
    return ClientAdmissionApplyResult::kIgnoredStale;
  if (leased() && response_received_at >= lease_deadline_) {
    Terminalize();
    return ClientAdmissionApplyResult::kInvalidated;
  }
  if (operation.action == ClientAdmissionAction::kRenew) {
    renewal_uncertainty_ = RenewalUncertainty{
        operation.admission_generation, operation.expected_revision, operation.request_started_at};
  }
  return ClientAdmissionApplyResult::kApplied;
}

ClientAdmissionApplyResult ClientAdmissionLeaseState::EndAttemptAuthority(
    const ClientAdmissionOperation& operation) {
  if (!Matches(operation))
    return ClientAdmissionApplyResult::kIgnoredStale;
  Terminalize();
  return ClientAdmissionApplyResult::kInvalidated;
}

bool ClientAdmissionLeaseState::ExpireIfNeeded(Clock::time_point now) {
  if (!leased() || now < lease_deadline_)
    return false;
  Invalidate();
  return true;
}

void ClientAdmissionLeaseState::Invalidate() {
  local_user_index_ = 0;
  lifecycle_token_ = 0;
  title_id_ = 0;
  local_user_xuid_ = 0;
  directory_session_id_.clear();
  attempt_id_.clear();
  capability_.clear();
  purpose_.clear();
  admission_generation_.clear();
  lease_revision_ = 0;
  lease_deadline_ = {};
  renewal_deadline_ = {};
  host_ready_ = false;
  has_ever_been_ready_ = false;
  renewal_uncertainty_.reset();
  session_confirmed_ = false;
  pending_session_.reset();
  live_session_.reset();
  xbox_session_id_ = {};
  xbox_session_key_ = {};
  xbox_host_ipv4_ = 0;
  xbox_host_port_ = 0;
  xbox_nonce_ = 0;
  xbox_host_xuid_ = 0;
}

void ClientAdmissionLeaseState::Terminalize() {
  directory_session_id_.clear();
  attempt_id_.clear();
  capability_.clear();
  purpose_.clear();
  admission_generation_.clear();
  lease_revision_ = 0;
  lease_deadline_ = {};
  renewal_deadline_ = {};
  host_ready_ = false;
  renewal_uncertainty_.reset();
  session_confirmed_ = false;
  pending_session_.reset();
  live_session_.reset();
}

ClientAdmissionAction ClientAdmissionLeaseState::NextAction(Clock::time_point now) const {
  if (!bound() || (leased() && now >= lease_deadline_))
    return ClientAdmissionAction::kNone;
  if (!leased())
    return ClientAdmissionAction::kArm;
  if (renewal_uncertainty_ || !host_ready_)
    return ClientAdmissionAction::kStatus;
  return now >= renewal_deadline_ ? ClientAdmissionAction::kRenew : ClientAdmissionAction::kStatus;
}

bool ClientAdmissionLeaseState::ValidateLiveness(uint32_t current_title_id,
                                                 std::optional<uint64_t> current_user_xuid) const {
  if (!bound() || !current_user_xuid || *current_user_xuid != local_user_xuid_ ||
      current_title_id != title_id_)
    return false;
  if (!session_confirmed_)
    return bool(pending_session_) && ExactSessionMatches(*pending_session_);
  auto session = live_session_.lock();
  return session && ExactSessionMatches(*session);
}

std::optional<ReadyAcceptedSessionCandidate> ClientAdmissionLeaseState::ReadyCandidate(
    uint32_t current_title_id, std::optional<uint64_t> current_user_xuid,
    Clock::time_point now) const {
  if (!bound() || !leased() || !host_ready_ || now >= lease_deadline_ || !session_confirmed_ ||
      !ValidateLiveness(current_title_id, current_user_xuid))
    return std::nullopt;
  auto live = live_session_.lock();
  if (!live)
    return std::nullopt;
  auto snapshot = std::make_shared<SessionRecord>();
  {
    std::lock_guard lock(*live->mutex);
    snapshot->info = live->info;
    snapshot->discovery_address = live->discovery_address;
    snapshot->traversal_session_id = live->traversal_session_id;
    snapshot->traversal_attempt_id = live->traversal_attempt_id;
    snapshot->traversal_capability = live->traversal_capability;
    snapshot->nonce = live->nonce;
    snapshot->host_xuid = live->host_xuid;
    snapshot->host_name = live->host_name;
    snapshot->flags = live->flags;
    snapshot->max_public_slots = live->max_public_slots;
    snapshot->max_private_slots = live->max_private_slots;
    snapshot->state = live->state;
    snapshot->members = live->members;
  }
  return ReadyAcceptedSessionCandidate{local_user_index_,     directory_session_id_, attempt_id_,
                                       admission_generation_, lease_revision_,       true,
                                       std::move(snapshot)};
}

bool ClientAdmissionMayReplaceLifecycle(bool join_by_code_action,
                                        const ClientAdmissionLeaseState* existing) {
  if (!join_by_code_action)
    return false;
  return !existing || !existing->has_ever_been_ready();
}

void HostAdmissionGrantStore::InvalidateGrantLocked(Grant& grant) {
  if (grant.reservation_id) {
    grant.invalidated_while_reserved = true;
  } else if (!grant.consumed_xuid) {
    grant.expires_at = {};
  }
}

void HostAdmissionGrantStore::ApplyAuthenticatedPoll(
    std::string_view directory_session_id, std::span<const HostAdmissionPollAttempt> attempts,
    Clock::time_point poll_started_at) {
  std::lock_guard lock(mutex_);
  hosted_directory_session_ = std::string(directory_session_id);
  std::unordered_set<std::string> seen;
  for (const auto& attempt : attempts) {
    if (!seen.insert(attempt.attempt_id).second)
      continue;
    auto found = grants_.find(attempt.attempt_id);
    const bool installable = attempt.purpose == "invite_code_private_eligible" &&
                             attempt.host_ready && IsLowerHex128(attempt.attempt_id) &&
                             IsLowerHex128(attempt.admission_generation) &&
                             attempt.lease_revision && attempt.admission_expires_in_ms;
    const auto returned_expiry =
        installable ? AdmissionDeadline(poll_started_at, attempt.admission_expires_in_ms)
                    : std::nullopt;
    if (!installable || !returned_expiry) {
      if (found != grants_.end())
        InvalidateGrantLocked(found->second);
      continue;
    }
    // The server computed its remaining lifetime before transmitting the
    // response. Anchor to the earlier local request time so response transit
    // can only shorten, never extend, private authority.
    if (found == grants_.end()) {
      Grant grant;
      grant.directory_session_id = directory_session_id;
      grant.attempt_id = attempt.attempt_id;
      grant.capability = attempt.capability;
      grant.admission_generation = attempt.admission_generation;
      grant.lease_revision = attempt.lease_revision;
      grant.expires_at = *returned_expiry;
      grants_.emplace(grant.attempt_id, std::move(grant));
      continue;
    }
    auto& grant = found->second;
    if (grant.directory_session_id != directory_session_id ||
        grant.admission_generation != attempt.admission_generation ||
        attempt.lease_revision < grant.lease_revision ||
        attempt.lease_revision > grant.lease_revision + 1 || grant.consumed_xuid)
      continue;
    if (grant.reservation_id) {
      if (attempt.lease_revision != grant.lease_revision)
        grant.invalidated_while_reserved = true;
      continue;
    }
    grant.capability = attempt.capability;
    if (attempt.lease_revision == grant.lease_revision) {
      grant.expires_at = std::min(grant.expires_at, *returned_expiry);
    } else {
      grant.lease_revision = attempt.lease_revision;
      grant.expires_at = *returned_expiry;
      grant.reserved_socket = 0;
      grant.reserved_ipv4 = 0;
      grant.reserved_port = 0;
      grant.reserved_xuid = 0;
      grant.invalidated_while_reserved = false;
    }
  }
  for (auto& [attempt_id, grant] : grants_) {
    if (grant.directory_session_id == directory_session_id && !seen.contains(attempt_id))
      InvalidateGrantLocked(grant);
  }
  std::erase_if(grants_, [](const auto& item) {
    const auto& grant = item.second;
    return !grant.reservation_id && !grant.consumed_xuid && grant.expires_at == Clock::time_point{};
  });
}

HostAdmissionReservationResult HostAdmissionGrantStore::Reserve(
    std::string_view directory_session_id, uint64_t discovery_socket, uint32_t peer_ipv4,
    uint16_t peer_port, std::span<const std::string> acknowledged_attempt_ids, uint64_t xuid,
    Clock::time_point now) {
  HostAdmissionReservationResult result;
  if (!xuid || !discovery_socket || !peer_ipv4 || !peer_port)
    return result;
  std::lock_guard lock(mutex_);
  std::unordered_set<std::string> acknowledged(acknowledged_attempt_ids.begin(),
                                               acknowledged_attempt_ids.end());
  std::vector<Grant*> candidates;
  Grant* consumed_duplicate = nullptr;
  size_t consumed_duplicate_count = 0;
  for (auto& [attempt_id, grant] : grants_) {
    if (!acknowledged.contains(attempt_id) || grant.directory_session_id != directory_session_id)
      continue;
    if (grant.consumed_xuid) {
      if (grant.consumed_xuid == xuid) {
        consumed_duplicate = &grant;
        ++consumed_duplicate_count;
      }
      continue;
    }
    if (!grant.reservation_id && now >= grant.expires_at)
      continue;
    if (grant.reservation_id &&
        (grant.reserved_socket != discovery_socket || grant.reserved_ipv4 != peer_ipv4 ||
         grant.reserved_port != peer_port || grant.reserved_xuid != xuid))
      continue;
    candidates.push_back(&grant);
  }
  if (candidates.size() > 1) {
    result.status = HostAdmissionReservationStatus::kAmbiguous;
    return result;
  }
  if (candidates.empty()) {
    if (consumed_duplicate_count > 1)
      result.status = HostAdmissionReservationStatus::kAmbiguous;
    else if (consumed_duplicate)
      result.status = HostAdmissionReservationStatus::kConsumedDuplicate;
    return result;
  }
  auto& grant = *candidates.front();
  if (grant.reservation_id) {
    result.status = HostAdmissionReservationStatus::kDuplicateReservation;
  } else {
    grant.reservation_id = next_reservation_id_++;
    if (!grant.reservation_id)
      grant.reservation_id = next_reservation_id_++;
    grant.reserved_socket = discovery_socket;
    grant.reserved_ipv4 = peer_ipv4;
    grant.reserved_port = peer_port;
    grant.reserved_xuid = xuid;
    result.status = HostAdmissionReservationStatus::kReserved;
  }
  result.reservation = {grant.directory_session_id,
                        grant.attempt_id,
                        grant.admission_generation,
                        grant.lease_revision,
                        discovery_socket,
                        peer_ipv4,
                        peer_port,
                        xuid,
                        grant.reservation_id};
  return result;
}

void HostAdmissionGrantStore::Finish(const HostAdmissionReservation& reservation, bool committed,
                                     Clock::time_point now) {
  if (!reservation)
    return;
  std::lock_guard lock(mutex_);
  auto found = grants_.find(reservation.attempt_id);
  if (found == grants_.end())
    return;
  auto& grant = found->second;
  if (grant.directory_session_id != reservation.directory_session_id ||
      grant.admission_generation != reservation.admission_generation ||
      grant.lease_revision != reservation.lease_revision ||
      grant.reservation_id != reservation.reservation_id ||
      grant.reserved_socket != reservation.discovery_socket ||
      grant.reserved_ipv4 != reservation.peer_ipv4 ||
      grant.reserved_port != reservation.peer_port || grant.reserved_xuid != reservation.xuid)
    return;
  if (committed) {
    grant.consumed_xuid = reservation.xuid;
    grant.reservation_id = 0;
    completions_.push_back({grant.directory_session_id, grant.attempt_id, grant.capability});
    return;
  }
  if (grant.invalidated_while_reserved || now >= grant.expires_at) {
    grants_.erase(found);
    return;
  }
  grant.reservation_id = 0;
  grant.reserved_socket = 0;
  grant.reserved_ipv4 = 0;
  grant.reserved_port = 0;
  grant.reserved_xuid = 0;
}

void HostAdmissionGrantStore::InvalidateSession(std::string_view directory_session_id) {
  std::lock_guard lock(mutex_);
  for (auto& [_, grant] : grants_)
    if (grant.directory_session_id == directory_session_id)
      InvalidateGrantLocked(grant);
  std::erase_if(grants_, [](const auto& item) {
    const auto& grant = item.second;
    return !grant.reservation_id && !grant.consumed_xuid && grant.expires_at == Clock::time_point{};
  });
  std::erase_if(completions_, [&](const auto& completion) {
    return completion.directory_session_id == directory_session_id;
  });
  if (hosted_directory_session_ == directory_session_id)
    hosted_directory_session_.clear();
}

void HostAdmissionGrantStore::Clear() {
  std::lock_guard lock(mutex_);
  grants_.clear();
  completions_.clear();
  hosted_directory_session_.clear();
}

std::vector<HostAdmissionCompletion> HostAdmissionGrantStore::TakeCompletions() {
  std::lock_guard lock(mutex_);
  auto result = std::move(completions_);
  completions_.clear();
  return result;
}

std::optional<std::string> HostAdmissionGrantStore::hosted_directory_session() const {
  std::lock_guard lock(mutex_);
  if (hosted_directory_session_.empty())
    return std::nullopt;
  return hosted_directory_session_;
}

size_t HostAdmissionGrantStore::available_grant_count(Clock::time_point now) const {
  std::lock_guard lock(mutex_);
  return std::count_if(grants_.begin(), grants_.end(), [&](const auto& item) {
    const auto& grant = item.second;
    return !grant.reservation_id && !grant.consumed_xuid && now < grant.expires_at;
  });
}

namespace {
constexpr uint32_t kDirectoryProtocolVersion = 1;
constexpr uint32_t kNoSessionIndex = 0xFFFFFFFFu;
constexpr size_t kMaxResponseBytes = 64 * 1024;
constexpr auto kHeartbeatInterval = std::chrono::seconds(15);
constexpr auto kHeartbeatRetryInitial = std::chrono::seconds(1);
constexpr auto kTraversalPollInterval = std::chrono::milliseconds(250);
constexpr auto kListCacheLifetime = std::chrono::seconds(5);
constexpr std::string_view kInviteCodeAlphabet = "ABCDEFGHJKMNPQRSTUVWXYZ23456789";
constexpr size_t kInviteCodeLength = 6;

bool IsSafeDirectoryUrl(std::string_view value) {
  if (value.empty())
    return true;
  if (value.size() > 512)
    return false;
  if (value.starts_with("https://"))
    return true;
  for (std::string_view prefix : {"http://127.0.0.1", "http://localhost"}) {
    if (!value.starts_with(prefix))
      continue;
    auto suffix = value.substr(prefix.size());
    return suffix.empty() || suffix.front() == ':' || suffix.front() == '/';
  }
  return false;
}

bool IsIpv4(std::string_view value) {
  if (value.empty())
    return true;
#if REX_PLATFORM_WIN32
  in_addr address{};
  std::string text(value);
  return inet_pton(AF_INET, text.c_str(), &address) == 1 && address.s_addr != htonl(INADDR_ANY) &&
         address.s_addr != htonl(INADDR_BROADCAST) && address.s_addr != htonl(INADDR_LOOPBACK);
#else
  return value.size() <= 45;
#endif
}

std::string TitleIdString(uint32_t title_id) {
  std::ostringstream stream;
  stream << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << title_id;
  return stream.str();
}

bool IsUrlToken(std::string_view value, size_t max_length) {
  return !value.empty() && value.size() <= max_length &&
         std::all_of(value.begin(), value.end(),
                     [](unsigned char ch) { return std::isalnum(ch) || ch == '-' || ch == '_'; });
}

bool IsPrintableName(std::string_view value) {
  return !value.empty() && value.size() <= 48 &&
         std::all_of(value.begin(), value.end(),
                     [](unsigned char ch) { return ch >= 0x20 && ch != 0x7F; });
}

std::optional<std::string> NormalizeInviteCode(std::string_view value) {
  if (value.size() != kInviteCodeLength)
    return std::nullopt;
  std::string normalized(value);
  for (char& ch : normalized) {
    ch = char(std::toupper(static_cast<unsigned char>(ch)));
    if (kInviteCodeAlphabet.find(ch) == std::string_view::npos)
      return std::nullopt;
  }
  return normalized;
}

bool IsInviteCodeSetting(std::string_view value) {
  return value.empty() || NormalizeInviteCode(value).has_value();
}

std::optional<std::filesystem::path> ActiveInviteCodePath() {
#if REX_PLATFORM_WIN32
  const char* local_app_data = std::getenv("LOCALAPPDATA");
  if (local_app_data && *local_app_data)
    return std::filesystem::path(local_app_data) / "HarmonyRecomp" / "active-invite-code.txt";
#endif
  return std::nullopt;
}

std::optional<DirectorySession> ParseDirectorySession(const nlohmann::json& item, uint32_t title_id,
                                                      std::string_view build_id) {
  try {
    if (!item.is_object())
      return std::nullopt;
    auto session_id = item.find("session_id");
    auto server_name = item.find("server_name");
    auto item_title_id = item.find("title_id");
    auto protocol = item.find("protocol_version");
    auto item_build = item.find("build_id");
    auto player_count = item.find("player_count");
    auto max_players = item.find("max_players");
    if (session_id == item.end() || !session_id->is_string() ||
        !IsUrlToken(session_id->get_ref<const std::string&>(), 64) || server_name == item.end() ||
        !server_name->is_string() || !IsPrintableName(server_name->get_ref<const std::string&>()) ||
        item_title_id == item.end() || !item_title_id->is_string() ||
        item_title_id->get<std::string>() != TitleIdString(title_id) || protocol == item.end() ||
        !protocol->is_number_unsigned() || protocol->get<uint64_t>() != kDirectoryProtocolVersion ||
        item_build == item.end() || !item_build->is_string() ||
        item_build->get<std::string>() != build_id || player_count == item.end() ||
        !player_count->is_number_unsigned() || max_players == item.end() ||
        !max_players->is_number_unsigned())
      return std::nullopt;
    uint64_t players = player_count->get<uint64_t>();
    uint64_t capacity = max_players->get<uint64_t>();
    if (!capacity || capacity > 64 || players > capacity)
      return std::nullopt;
    DirectorySession session;
    session.session_id = session_id->get<std::string>();
    session.server_name = server_name->get<std::string>().substr(0, 48);
    session.player_count = uint32_t(players);
    session.max_players = uint32_t(capacity);
    session.title_id = title_id;
    session.protocol_version = kDirectoryProtocolVersion;
    session.build_id = std::string(build_id);
    auto candidates = item.find("connectivity_candidates");
    if (candidates != item.end() && candidates->is_array()) {
      for (const auto& candidate : *candidates) {
        if (!candidate.is_object())
          continue;
        DirectoryCandidate parsed;
        auto type = candidate.find("type");
        auto address = candidate.find("address");
        auto discovery = candidate.find("discovery_port");
        auto gameplay = candidate.find("gameplay_port");
        if (type == candidate.end() || !type->is_string() || address == candidate.end() ||
            !address->is_string() || discovery == candidate.end() ||
            !discovery->is_number_unsigned() || gameplay == candidate.end() ||
            !gameplay->is_number_unsigned())
          continue;
        uint64_t discovery_value = discovery->get<uint64_t>();
        uint64_t gameplay_value = gameplay->get<uint64_t>();
        if (!discovery_value || discovery_value > 65535 || !gameplay_value ||
            gameplay_value > 65535)
          continue;
        parsed.type = type->get<std::string>();
        parsed.address = address->get<std::string>();
        parsed.discovery_port = uint16_t(discovery_value);
        parsed.gameplay_port = uint16_t(gameplay_value);
        if ((parsed.type == "direct" || parsed.type == "tailscale" || parsed.type == "public") &&
            !parsed.address.empty() && IsIpv4(parsed.address))
          session.connectivity_candidates.push_back(std::move(parsed));
      }
    }
    return session.connectivity_candidates.empty()
               ? std::nullopt
               : std::optional<DirectorySession>(std::move(session));
  } catch (const nlohmann::json::exception&) {
    return std::nullopt;
  }
}

std::optional<DirectoryTraversalAttempt> ParseTraversalAttempt(const nlohmann::json& document,
                                                               std::string session_id,
                                                               uint8_t participant) {
  if (!document.is_object())
    return std::nullopt;
  try {
    auto attempt = document.value("attempt_id", "");
    auto capability = document.value("capability", "");
    auto host = document.value("rendezvous_host", "");
    auto port = document.value("rendezvous_port", 0u);
    auto role = document.value("participant", "");
    auto purpose = document.value("purpose", "");
    if (!IsLowerHex128(attempt) || !IsLowerHex128(capability) || host.empty() ||
        host.size() > 255 || !port || port > 65535 || role != (participant ? "client" : "host") ||
        (purpose != "public" && purpose != "invite_code_private_eligible"))
      return std::nullopt;
    DirectoryTraversalAttempt result;
    result.session_id = std::move(session_id);
    result.attempt_id = std::move(attempt);
    result.capability = std::move(capability);
    result.rendezvous_host = std::move(host);
    result.rendezvous_port = uint16_t(port);
    result.participant = participant;
    result.purpose = std::move(purpose);
    auto generation = document.find("admission_generation");
    auto revision = document.find("lease_revision");
    auto expires = document.find("admission_expires_in_ms");
    auto ready = document.find("host_ready");
    if (generation != document.end() && !generation->is_null()) {
      if (!generation->is_string() || !IsLowerHex128(generation->get_ref<const std::string&>()) ||
          revision == document.end() || !revision->is_number_unsigned() ||
          !revision->get<uint64_t>() || expires == document.end() ||
          !expires->is_number_unsigned() || !expires->get<uint64_t>() ||
          expires->get<uint64_t>() >= UINT32_MAX || ready == document.end() || !ready->is_boolean())
        return std::nullopt;
      result.admission_generation = generation->get<std::string>();
      result.lease_revision = revision->get<uint64_t>();
      result.admission_expires_in_ms = uint32_t(expires->get<uint64_t>());
      result.host_ready = ready->get<bool>();
    }
    return result;
  } catch (const nlohmann::json::exception&) {
    return std::nullopt;
  }
}

std::optional<std::string> RandomUrlToken(size_t byte_count) {
#if REX_PLATFORM_WIN32
  std::vector<uint8_t> bytes(byte_count);
  if (BCryptGenRandom(nullptr, bytes.data(), ULONG(bytes.size()), BCRYPT_USE_SYSTEM_PREFERRED_RNG) <
      0)
    return std::nullopt;
  constexpr char kHex[] = "0123456789abcdef";
  std::string result(bytes.size() * 2, '0');
  for (size_t index = 0; index < bytes.size(); ++index) {
    result[index * 2] = kHex[bytes[index] >> 4];
    result[index * 2 + 1] = kHex[bytes[index] & 0x0F];
  }
  return result;
#else
  return std::nullopt;
#endif
}

struct HttpResult {
  uint32_t status = 0;
  std::string body;
};

#if REX_PLATFORM_WIN32
std::wstring WidenAscii(std::string_view value) {
  return std::wstring(value.begin(), value.end());
}

std::optional<HttpResult> Request(std::string_view base_url, std::wstring_view method,
                                  std::string_view relative_path, std::string_view body,
                                  std::string_view bearer = {}) {
  auto full_url = std::string(base_url);
  while (full_url.ends_with('/'))
    full_url.pop_back();
  if (!relative_path.starts_with('/'))
    full_url.push_back('/');
  full_url.append(relative_path);
  auto wide_url = WidenAscii(full_url);
  URL_COMPONENTS parts{};
  parts.dwStructSize = sizeof(parts);
  parts.dwSchemeLength = DWORD(-1);
  parts.dwHostNameLength = DWORD(-1);
  parts.dwUrlPathLength = DWORD(-1);
  parts.dwExtraInfoLength = DWORD(-1);
  if (!WinHttpCrackUrl(wide_url.c_str(), DWORD(wide_url.size()), 0, &parts))
    return std::nullopt;
  std::wstring host(parts.lpszHostName, parts.dwHostNameLength);
  std::wstring path(parts.lpszUrlPath, parts.dwUrlPathLength);
  if (parts.dwExtraInfoLength)
    path.append(parts.lpszExtraInfo, parts.dwExtraInfoLength);
  HINTERNET session = WinHttpOpen(L"HarmonyRecomp/1", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                                  WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
  if (!session)
    return std::nullopt;
  // Directory failure must not stall the guest's existing LAN search or
  // session teardown. These are per-stage bounds; gameplay never uses HTTP.
  WinHttpSetTimeouts(session, 500, 500, 500, 1000);
  DWORD connect_retries = 0;
  WinHttpSetOption(session, WINHTTP_OPTION_CONNECT_RETRIES, &connect_retries,
                   sizeof(connect_retries));
  HINTERNET connection = WinHttpConnect(session, host.c_str(), parts.nPort, 0);
  if (!connection) {
    WinHttpCloseHandle(session);
    return std::nullopt;
  }
  DWORD flags = parts.nScheme == INTERNET_SCHEME_HTTPS ? WINHTTP_FLAG_SECURE : 0;
  HINTERNET request = WinHttpOpenRequest(connection, method.data(), path.c_str(), nullptr,
                                         WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, flags);
  if (!request) {
    WinHttpCloseHandle(connection);
    WinHttpCloseHandle(session);
    return std::nullopt;
  }
  std::wstring headers = L"Accept: application/json\r\nContent-Type: application/json\r\n";
  if (!bearer.empty()) {
    headers += L"Authorization: Bearer ";
    headers += WidenAscii(bearer);
    headers += L"\r\n";
  }
  BOOL sent =
      WinHttpSendRequest(request, headers.c_str(), DWORD(headers.size()),
                         body.empty() ? WINHTTP_NO_REQUEST_DATA : const_cast<char*>(body.data()),
                         DWORD(body.size()), DWORD(body.size()), 0);
  BOOL received = sent && WinHttpReceiveResponse(request, nullptr);
  HttpResult result;
  DWORD status_size = sizeof(result.status);
  if (received)
    WinHttpQueryHeaders(request, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                        WINHTTP_HEADER_NAME_BY_INDEX, &result.status, &status_size,
                        WINHTTP_NO_HEADER_INDEX);
  while (received && result.body.size() < kMaxResponseBytes) {
    DWORD available = 0;
    if (!WinHttpQueryDataAvailable(request, &available) || !available)
      break;
    available = std::min<DWORD>(available, DWORD(kMaxResponseBytes - result.body.size()));
    size_t offset = result.body.size();
    result.body.resize(offset + available);
    DWORD read = 0;
    if (!WinHttpReadData(request, result.body.data() + offset, available, &read)) {
      received = false;
      break;
    }
    result.body.resize(offset + read);
  }
  WinHttpCloseHandle(request);
  WinHttpCloseHandle(connection);
  WinHttpCloseHandle(session);
  return received ? std::optional<HttpResult>(std::move(result)) : std::nullopt;
}
#else
std::optional<HttpResult> Request(std::string_view, std::wstring_view, std::string_view,
                                  std::string_view, std::string_view = {}) {
  return std::nullopt;
}
#endif

nlohmann::json RegistrationPayload(const SessionRecord& session, uint32_t title_id,
                                   uint16_t discovery_port) {
  std::lock_guard lock(*session.mutex);
  uint32_t max_players = session.max_public_slots + session.max_private_slots;
  uint32_t gameplay_port = REXCVAR_GET(lan_gameplay_port);
  if (!gameplay_port)
    gameplay_port = session.info.host_address.port;
  return {
      {"server_name", session.host_name.substr(0, 48)},
      {"player_count", session.members.size()},
      {"max_players", max_players},
      {"title_id", TitleIdString(title_id)},
      {"protocol_version", kDirectoryProtocolVersion},
      {"build_id", REXCVAR_GET(session_directory_build_id)},
      {"connectivity_candidates",
       nlohmann::json::array({{{"type", REXCVAR_GET(session_directory_candidate_type)},
                               {"address", REXCVAR_GET(session_directory_publish_address)},
                               {"discovery_port", discovery_port},
                               {"gameplay_port", gameplay_port}}})},
  };
}
}  // namespace

std::optional<std::string> NormalizeDirectoryInviteCode(std::string_view value) {
  return NormalizeInviteCode(value);
}

std::optional<DirectorySession> ParseInviteCodeSessionResponse(std::string_view body,
                                                               uint32_t title_id,
                                                               std::string_view build_id) {
  auto document = nlohmann::json::parse(body, nullptr, false);
  if (!document.is_object() || !document.contains("session"))
    return std::nullopt;
  return ParseDirectorySession(document["session"], title_id, build_id);
}

std::optional<DirectoryInviteJoinAttempt> ParseInviteCodeJoinAttemptResponse(
    std::string_view body, uint32_t title_id, std::string_view build_id) {
  auto document = nlohmann::json::parse(body, nullptr, false);
  if (!document.is_object() || !document.contains("session") || !document.contains("attempt"))
    return std::nullopt;
  auto session = ParseDirectorySession(document["session"], title_id, build_id);
  if (!session)
    return std::nullopt;
  auto attempt = ParseTraversalAttempt(document["attempt"], session->session_id, 1);
  if (!attempt || attempt->purpose != "invite_code_private_eligible" ||
      !attempt->admission_generation.empty() || attempt->lease_revision ||
      attempt->admission_expires_in_ms || attempt->host_ready)
    return std::nullopt;
  return DirectoryInviteJoinAttempt{std::move(*session), std::move(*attempt)};
}

std::optional<DirectoryAdmissionState> ParseDirectoryAdmissionResponse(std::string_view body) {
  auto document = nlohmann::json::parse(body, nullptr, false);
  if (!document.is_object())
    return std::nullopt;
  try {
    DirectoryAdmissionState result;
    result.attempt_id = document.value("attempt_id", "");
    result.purpose = document.value("purpose", "");
    result.phase = document.value("phase", "");
    auto duration = document.find("admission_lease_duration_ms");
    auto expires = document.find("admission_expires_in_ms");
    auto ready = document.find("host_ready");
    if (!IsLowerHex128(result.attempt_id) || result.purpose != "invite_code_private_eligible" ||
        duration == document.end() || !duration->is_number_unsigned() ||
        !duration->get<uint64_t>() || duration->get<uint64_t>() >= UINT32_MAX ||
        expires == document.end() || !expires->is_number_unsigned() ||
        expires->get<uint64_t>() >= UINT32_MAX || ready == document.end() || !ready->is_boolean())
      return std::nullopt;
    result.admission_lease_duration_ms = uint32_t(duration->get<uint64_t>());
    result.admission_expires_in_ms = uint32_t(expires->get<uint64_t>());
    result.host_ready = ready->get<bool>();
    auto generation = document.find("admission_generation");
    auto revision = document.find("lease_revision");
    const bool leased_phase =
        result.phase == "admission_awaiting_host" || result.phase == "admission_ready";
    if (leased_phase) {
      if (generation == document.end() || !generation->is_string() ||
          !IsLowerHex128(generation->get_ref<const std::string&>()) || revision == document.end() ||
          !revision->is_number_unsigned() || !revision->get<uint64_t>() ||
          !result.admission_expires_in_ms ||
          result.host_ready != (result.phase == "admission_ready"))
        return std::nullopt;
      result.admission_generation = generation->get<std::string>();
      result.lease_revision = revision->get<uint64_t>();
    } else if (result.phase == "rendezvous_active" || result.phase == "terminal") {
      const bool has_generation = generation != document.end() && !generation->is_null();
      const bool has_revision = revision != document.end() && !revision->is_null();
      if (result.admission_expires_in_ms || result.host_ready || has_generation != has_revision)
        return std::nullopt;
      if (has_generation) {
        if (!generation->is_string() || !IsLowerHex128(generation->get_ref<const std::string&>()) ||
            !revision->is_number_unsigned() || !revision->get<uint64_t>())
          return std::nullopt;
        result.admission_generation = generation->get<std::string>();
        result.lease_revision = revision->get<uint64_t>();
      }
    } else {
      return std::nullopt;
    }
    return result;
  } catch (const nlohmann::json::exception&) {
    return std::nullopt;
  }
}

ClientAdmissionResponseDisposition ClassifyClientAdmissionResponse(ClientAdmissionAction action,
                                                                   std::optional<uint32_t> status,
                                                                   bool valid_body) {
  if (!status)
    return ClientAdmissionResponseDisposition::kRetainUntilExpiry;
  if (action == ClientAdmissionAction::kRenew && *status == 409)
    return ClientAdmissionResponseDisposition::kReconcileStatus;
  const bool expected =
      (action == ClientAdmissionAction::kArm && (*status == 200 || *status == 201)) ||
      ((action == ClientAdmissionAction::kStatus || action == ClientAdmissionAction::kRenew) &&
       *status == 200);
  return expected && valid_body ? ClientAdmissionResponseDisposition::kApply
                                : ClientAdmissionResponseDisposition::kInvalidate;
}

std::optional<std::vector<DirectoryTraversalAttempt>> ParseDirectoryHostPollSnapshot(
    std::string_view body, std::string_view directory_session_id) {
  auto document = nlohmann::json::parse(body, nullptr, false);
  if (!document.is_object() || !document.contains("attempts") || !document["attempts"].is_array())
    return std::nullopt;
  std::vector<DirectoryTraversalAttempt> attempts;
  attempts.reserve(document["attempts"].size());
  for (const auto& item : document["attempts"]) {
    auto attempt = ParseTraversalAttempt(item, std::string(directory_session_id), 0);
    if (!attempt)
      return std::nullopt;
    attempts.push_back(std::move(*attempt));
  }
  return attempts;
}

REXCVAR_DEFINE_STRING(session_directory_url, "", "Network",
                      "HTTPS Harmony session-directory URL (empty disables directory access)")
    .validator(IsSafeDirectoryUrl)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_build_id, "", "Network",
                      "Session-directory compatibility identifier")
    .validator([](std::string_view value) {
      return value.size() <= 64 && std::all_of(value.begin(), value.end(), [](unsigned char ch) {
               return std::isalnum(ch) || ch == '.' || ch == '_' || ch == '-';
             });
    })
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_publish_address, "", "Network",
                      "Explicit IPv4 address published by a directory host")
    .validator(IsIpv4)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_candidate_type, "tailscale", "Network",
                      "Published directory candidate type: direct, tailscale, or public")
    .validator([](std::string_view value) {
      return value == "direct" || value == "tailscale" || value == "public";
    })
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_UINT32(session_directory_session_index, kNoSessionIndex, "Network",
                      "Directory result index to resolve through Direct Connect")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_invite_code, "", "Network",
                      "Resolve one directory lobby by its six-character invite code")
    .validator(IsInviteCodeSetting)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

DirectoryHeartbeatDisposition ClassifyDirectoryHeartbeatResponse(std::optional<uint32_t> status,
                                                                 bool valid_session_id) {
  if (!status)
    return DirectoryHeartbeatDisposition::kRetrySameRegistration;
  if (*status == 404)
    return DirectoryHeartbeatDisposition::kRecoverRegistration;
  if (*status == 400 || *status == 401 || *status == 403)
    return DirectoryHeartbeatDisposition::kRejected;
  if (*status == 200 && valid_session_id)
    return DirectoryHeartbeatDisposition::kAccepted;
  return DirectoryHeartbeatDisposition::kRetrySameRegistration;
}

DirectoryHostPollDisposition ClassifyDirectoryHostPollResponse(std::optional<uint32_t> status,
                                                               bool valid_snapshot) {
  if (!status)
    return DirectoryHostPollDisposition::kRetainUntilExpiry;
  if (*status == 404)
    return DirectoryHostPollDisposition::kRecoverRegistration;
  if (*status != 200)
    return DirectoryHostPollDisposition::kRetainUntilExpiry;
  return valid_snapshot ? DirectoryHostPollDisposition::kAccepted
                        : DirectoryHostPollDisposition::kRejectSnapshot;
}

DirectoryHostPollTransition ApplyDirectoryHostPollResult(
    DirectoryHostPollDisposition disposition, std::span<const DirectoryTraversalAttempt> attempts,
    DirectoryHostPollRuntimeState& state, HostAdmissionGrantStore* admission_grants,
    SessionRecord& hosted, HostAdmissionGrantStore::Clock::time_point poll_started_at) {
  DirectoryHostPollTransition transition;
  switch (disposition) {
    case DirectoryHostPollDisposition::kAccepted: {
      std::unordered_set<std::string> next_host_attempts;
      std::unordered_map<std::string, HostAdmissionPollAttempt> next_private_attempts;
      std::vector<HostAdmissionPollAttempt> grant_snapshot;
      for (const auto& attempt : attempts) {
        next_host_attempts.insert(attempt.attempt_id);
        NatProbeInstallIdentity({attempt.attempt_id, attempt.capability, attempt.rendezvous_host,
                                 attempt.rendezvous_port, 0});
        HostAdmissionPollAttempt host_attempt{
            attempt.attempt_id,     attempt.capability,
            attempt.purpose,        attempt.admission_generation,
            attempt.lease_revision, attempt.admission_expires_in_ms,
            attempt.host_ready};
        grant_snapshot.push_back(host_attempt);
        if (attempt.purpose == "invite_code_private_eligible" &&
            !attempt.admission_generation.empty())
          next_private_attempts.emplace(attempt.attempt_id, std::move(host_attempt));
      }
      for (const auto& attempt : state.host_attempts)
        if (!next_host_attempts.contains(attempt))
          NatProbeRetireIdentity(attempt);
      state.host_attempts = std::move(next_host_attempts);
      state.private_attempts = std::move(next_private_attempts);
      if (admission_grants)
        admission_grants->ApplyAuthenticatedPoll(state.directory_session_id, grant_snapshot,
                                                 poll_started_at);
      break;
    }
    case DirectoryHostPollDisposition::kRejectSnapshot:
      if (admission_grants)
        admission_grants->ApplyAuthenticatedPoll(state.directory_session_id,
                                                 std::span<const HostAdmissionPollAttempt>{},
                                                 poll_started_at);
      state.private_attempts.clear();
      break;
    case DirectoryHostPollDisposition::kRecoverRegistration: {
      hosted.SetStatusInviteCode({});
      if (auto path = ActiveInviteCodePath())
        RemoveActiveInviteCodeFile(*path);
      const auto invalidated_session = state.directory_session_id;
      if (admission_grants)
        admission_grants->InvalidateSession(invalidated_session);
      for (const auto& attempt : state.host_attempts)
        NatProbeRetireIdentity(attempt);
      state.host_attempts.clear();
      state.private_attempts.clear();
      state.pending_completions.clear();
      state.directory_session_id.clear();
      state.registration_token.clear();
      state.public_invite_code.clear();
      state.recovering = true;
      transition.recover_now = true;
      break;
    }
    case DirectoryHostPollDisposition::kRetainUntilExpiry:
      break;
  }
  return transition;
}

bool WriteActiveInviteCodeFile(const std::filesystem::path& path, std::string_view code) {
  auto normalized = NormalizeInviteCode(code);
  if (!normalized)
    return false;
  std::error_code error;
  std::filesystem::create_directories(path.parent_path(), error);
  if (error)
    return false;
  auto temporary = path;
  temporary += ".tmp";
  {
    std::ofstream output(temporary, std::ios::binary | std::ios::trunc);
    if (!output || !output.write(normalized->data(), normalized->size()))
      return false;
  }
#if REX_PLATFORM_WIN32
  if (!MoveFileExW(temporary.c_str(), path.c_str(),
                   MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
    std::filesystem::remove(temporary, error);
    return false;
  }
#else
  std::filesystem::rename(temporary, path, error);
  if (error) {
    std::filesystem::remove(temporary, error);
    return false;
  }
#endif
  return true;
}

void RemoveActiveInviteCodeFile(const std::filesystem::path& path) {
  std::error_code error;
  std::filesystem::remove(path, error);
  auto temporary = path;
  temporary += ".tmp";
  std::filesystem::remove(temporary, error);
}

class SessionDirectoryClient::Impl {
 public:
  explicit Impl(LocalUserIdentityProvider user_identity,
                ClientAdmissionTransport admission_transport,
                bool automatic_client_admission_driver)
      : client_admission_user_identity(std::move(user_identity)),
        client_admission_transport(std::move(admission_transport)) {
    if (automatic_client_admission_driver) {
      client_admission_worker =
          std::jthread([this](std::stop_token stop) { ClientAdmissionLoop(stop); });
    }
  }
  ~Impl() {
    StopAllClientAdmissions();
    client_admission_worker.request_stop();
    client_admission_wake.notify_all();
    if (client_admission_worker.joinable())
      client_admission_worker.join();
    StopHosting();
    std::future<std::vector<DirectorySession>> pending;
    {
      std::lock_guard lock(list_mutex);
      pending = std::move(list_future);
    }
    if (pending.valid())
      pending.wait();
  }

  void StartHosting(std::shared_ptr<SessionRecord> value, uint32_t value_title_id,
                    uint16_t value_discovery_port,
                    std::shared_ptr<HostAdmissionGrantStore> value_admission_grants) {
    StopHosting();
    if (REXCVAR_GET(session_directory_url).empty())
      return;
    if (REXCVAR_GET(session_directory_build_id).empty() ||
        (REXCVAR_GET(session_directory_candidate_type) != "public" &&
         REXCVAR_GET(session_directory_publish_address).empty())) {
      REXSYS_WARN(
          "Session directory: hosting disabled; build ID and a publish address for non-public "
          "candidates are required");
      return;
    }
#if !REX_PLATFORM_WIN32
    REXSYS_WARN("Session directory: HTTPS client is not available on this platform");
    return;
#endif
    hosted = std::move(value);
    admission_grants = std::move(value_admission_grants);
    title_id = value_title_id;
    discovery_port = value_discovery_port;
    worker = std::jthread([this](std::stop_token stop) { HostLoop(stop); });
  }

  void StopHosting() {
    if (worker.joinable()) {
      worker.request_stop();
      wake.notify_all();
      worker.join();
    }
    if (hosted) hosted->SetStatusInviteCode({});
    if (admission_grants) admission_grants->Clear();
    hosted.reset();
    admission_grants.reset();
    if (auto path = ActiveInviteCodePath())
      RemoveActiveInviteCodeFile(*path);
  }

  std::vector<DirectorySession> List(uint32_t value_title_id) const {
    std::vector<DirectorySession> result;
    const auto& url = REXCVAR_GET(session_directory_url);
    const auto& build_id = REXCVAR_GET(session_directory_build_id);
    if (url.empty() || build_id.empty())
      return result;
    std::string path = "/sessions?title_id=" + TitleIdString(value_title_id) +
                       "&protocol_version=1&build_id=" + build_id;
    auto response = Request(url, L"GET", path, "");
    if (!response || response->status != 200) {
      REXSYS_WARN("Session directory: list request unavailable");
      return result;
    }
    auto document = nlohmann::json::parse(response->body, nullptr, false);
    if (document.is_discarded() || !document.is_object() || !document.contains("sessions") ||
        !document["sessions"].is_array()) {
      REXSYS_WARN("Session directory: invalid list response");
      return result;
    }
    for (const auto& item : document["sessions"]) {
      if (auto session = ParseDirectorySession(item, value_title_id, build_id))
        result.push_back(std::move(*session));
    }
    REXSYS_INFO("Session directory: query returned {} compatible session(s)", result.size());
    return result;
  }

  std::optional<DirectorySession> ResolveInviteCode(std::string_view code,
                                                    uint32_t value_title_id) const {
    auto normalized = NormalizeInviteCode(code);
    const auto& url = REXCVAR_GET(session_directory_url);
    const auto& build_id = REXCVAR_GET(session_directory_build_id);
    if (!normalized || url.empty() || build_id.empty())
      return std::nullopt;
    auto response = Request(url, L"GET", "/sessions/by-code/" + *normalized, "");
    if (!response || response->status != 200)
      return std::nullopt;
    return ParseInviteCodeSessionResponse(response->body, value_title_id, build_id);
  }

  std::optional<DirectoryInviteJoinAttempt> CreateInviteCodeJoinAttempt(
      std::string_view code, uint32_t value_title_id) const {
    auto normalized = NormalizeInviteCode(code);
    auto request_id = RandomUrlToken(16);
    const auto& url = REXCVAR_GET(session_directory_url);
    const auto& build_id = REXCVAR_GET(session_directory_build_id);
    if (!normalized || !request_id || url.empty() || build_id.empty())
      return std::nullopt;
    const auto body = nlohmann::json{
        {"request_id", *request_id},
        {"title_id", TitleIdString(value_title_id)},
        {"protocol_version", kDirectoryProtocolVersion},
        {"build_id",
         build_id}}.dump();
    // The request ID is deliberately reused when the first response is lost;
    // the directory owns idempotency and immutable attempt purpose.
    for (uint32_t try_index = 0; try_index < 2; ++try_index) {
      auto response =
          Request(url, L"POST", "/sessions/by-code/" + *normalized + "/join-attempts", body);
      if (!response)
        continue;
      if (response->status != 200 && response->status != 201)
        return std::nullopt;
      return ParseInviteCodeJoinAttemptResponse(response->body, value_title_id, build_id);
    }
    return std::nullopt;
  }

  void RequestList(uint32_t value_title_id) const {
    std::lock_guard lock(list_mutex);
    HarvestListLocked();
    auto now = std::chrono::steady_clock::now();
    if (list_cache && list_cache_title_id == value_title_id &&
        now - list_cache_time < kListCacheLifetime)
      return;
    if (list_future.valid())
      return;
    list_future_title_id = value_title_id;
    list_future =
        std::async(std::launch::async, [this, value_title_id] { return List(value_title_id); });
  }

  std::optional<std::vector<DirectorySession>> CachedList(uint32_t value_title_id) const {
    std::lock_guard lock(list_mutex);
    HarvestListLocked();
    if (!list_cache || list_cache_title_id != value_title_id ||
        std::chrono::steady_clock::now() - list_cache_time >= kListCacheLifetime)
      return std::nullopt;
    return list_cache;
  }

  std::optional<DirectoryTraversalAttempt> CreateJoinAttempt(const std::string& session_id) const {
    const auto& url = REXCVAR_GET(session_directory_url);
    if (url.empty() || !IsUrlToken(session_id, 64))
      return std::nullopt;
    auto response = Request(url, L"POST", "/sessions/" + session_id + "/join-attempts", "{}");
    if (!response || response->status != 201)
      return std::nullopt;
    auto document = nlohmann::json::parse(response->body, nullptr, false);
    return ParseTraversalAttempt(document, session_id, 1);
  }

  void CompleteJoinAttempt(const DirectoryTraversalAttempt& attempt) const {
    const auto& url = REXCVAR_GET(session_directory_url);
    if (url.empty() || !IsUrlToken(attempt.session_id, 64) || !IsUrlToken(attempt.attempt_id, 64) ||
        attempt.capability.empty())
      return;
    Request(url, L"DELETE",
            "/sessions/" + attempt.session_id + "/join-attempts/" + attempt.attempt_id, "",
            attempt.capability);
    NatProbeRetireIdentity(attempt.attempt_id);
  }

  ClientAdmissionPrepareResult PrepareClientAdmission(uint32_t local_user_index,
                                                      uint32_t value_title_id,
                                                      const DirectoryTraversalAttempt& attempt,
                                                      const SessionRecord& discovered,
                                                      uint64_t discovery_socket) {
    auto exact = std::make_shared<SessionRecord>();
    {
      std::lock_guard lock(*discovered.mutex);
      exact->info = discovered.info;
      exact->discovery_address = discovered.discovery_address;
      exact->traversal_session_id = discovered.traversal_session_id;
      exact->traversal_attempt_id = discovered.traversal_attempt_id;
      exact->traversal_capability = discovered.traversal_capability;
      exact->nonce = discovered.nonce;
      exact->host_xuid = discovered.host_xuid;
      exact->host_name = discovered.host_name;
      exact->flags = discovered.flags;
      exact->max_public_slots = discovered.max_public_slots;
      exact->max_private_slots = discovered.max_private_slots;
      exact->state = discovered.state;
      exact->members = discovered.members;
    }
    auto current_user = client_admission_user_identity
                            ? client_admission_user_identity(local_user_index)
                            : std::optional<uint64_t>{};
    std::lock_guard lock(client_admission_mutex);
    if (!client_admission_user_identity) {
      auto known_user = client_admission_users.find(local_user_index);
      if (known_user != client_admission_users.end())
        current_user = known_user->second;
    }
    if (!current_user || !value_title_id || value_title_id != client_admission_title_id)
      return ClientAdmissionPrepareResult::kInvalid;
    auto old = client_admissions.find(local_user_index);
    if (old != client_admissions.end() &&
        !ClientAdmissionMayReplaceLifecycle(true, &old->second.state))
      return ClientAdmissionPrepareResult::kBusy;
    if (old != client_admissions.end()) {
      QueueCancellationLocked(old->second);
      client_admissions.erase(old);
    }
    if (++next_client_admission_token == 0)
      ++next_client_admission_token;
    ClientAdmissionContext context;
    context.socket = discovery_socket;
    context.peer = discovered.discovery_address;
    if (!context.state.BindExactDiscovery(local_user_index, next_client_admission_token,
                                          value_title_id, *current_user, attempt, std::move(exact),
                                          false))
      return ClientAdmissionPrepareResult::kInvalid;
    client_admissions.emplace(local_user_index, std::move(context));
    client_admission_wake.notify_all();
    return ClientAdmissionPrepareResult::kPrepared;
  }

  bool ConfirmClientAdmissionSession(uint32_t local_user_index,
                                     const std::shared_ptr<const SessionRecord>& session) {
    std::lock_guard lock(client_admission_mutex);
    auto found = client_admissions.find(local_user_index);
    if (found == client_admissions.end())
      return false;
    if (!found->second.state.ConfirmExactSession(session)) {
      QueueCancellationLocked(found->second);
      client_admissions.erase(found);
      client_admission_wake.notify_all();
      return false;
    }
    return true;
  }

  void SetClientAdmissionTitle(uint32_t value_title_id) {
    std::lock_guard lock(client_admission_mutex);
    if (client_admission_title_id == value_title_id)
      return;
    client_admission_title_id = value_title_id;
    for (auto& [_, context] : client_admissions)
      QueueCancellationLocked(context);
    client_admissions.clear();
    client_admission_wake.notify_all();
  }

  void SetClientAdmissionUserIdentity(uint32_t local_user_index, std::optional<uint64_t> xuid) {
    std::lock_guard lock(client_admission_mutex);
    client_admission_users[local_user_index] = xuid;
    if (!xuid) {
      auto found = client_admissions.find(local_user_index);
      if (found != client_admissions.end()) {
        QueueCancellationLocked(found->second);
        client_admissions.erase(found);
      }
    }
    client_admission_wake.notify_all();
  }

  void StopClientAdmission(uint32_t local_user_index) {
    std::lock_guard lock(client_admission_mutex);
    auto found = client_admissions.find(local_user_index);
    if (found == client_admissions.end())
      return;
    QueueCancellationLocked(found->second);
    client_admissions.erase(found);
    client_admission_wake.notify_all();
  }

  void StopAllClientAdmissions() {
    std::lock_guard lock(client_admission_mutex);
    for (auto& [_, context] : client_admissions)
      QueueCancellationLocked(context);
    client_admissions.clear();
    client_admission_wake.notify_all();
  }

  bool HasClientAdmission(uint32_t local_user_index) const {
    std::lock_guard lock(client_admission_mutex);
    return client_admissions.contains(local_user_index);
  }

  bool HasProtectedClientAdmission(uint32_t local_user_index) const {
    std::lock_guard lock(client_admission_mutex);
    auto found = client_admissions.find(local_user_index);
    return found != client_admissions.end() && found->second.state.has_ever_been_ready();
  }

  std::optional<uint64_t> ClientAdmissionSocketForSession(uint32_t local_user_index,
                                                          const SessionRecord& session) const {
    std::lock_guard lock(client_admission_mutex);
    auto found = client_admissions.find(local_user_index);
    if (found == client_admissions.end() ||
        session.traversal_session_id != found->second.state.directory_session_id() ||
        session.traversal_attempt_id != found->second.state.attempt_id())
      return std::nullopt;
    return found->second.socket;
  }

  void SetClientAdmissionExchange(uint32_t local_user_index, bool active) {
    std::lock_guard lock(client_admission_mutex);
    auto found = client_admissions.find(local_user_index);
    if (found != client_admissions.end())
      found->second.exchange_active = active;
  }

  std::optional<ReadyAcceptedSessionCandidate> ReadyClientAdmission(
      uint32_t local_user_index) {
    struct Snapshot {
      uint64_t lifecycle_token = 0;
      uint64_t discovery_socket = 0;
      LanAddress peer{};
      std::string directory_session_id;
      std::string attempt_id;
      std::string admission_generation;
      uint64_t lease_revision = 0;
      ReadyAcceptedSessionCandidate candidate;
    } snapshot;

    auto current_user = client_admission_user_identity
                            ? client_admission_user_identity(local_user_index)
                            : std::optional<uint64_t>{};
    {
      std::lock_guard lock(client_admission_mutex);
      auto found = client_admissions.find(local_user_index);
      auto active = client_admission_users.find(local_user_index);
      if (!client_admission_user_identity && active != client_admission_users.end())
        current_user = active->second;
      if (found == client_admissions.end() || !current_user)
        return std::nullopt;
      auto candidate = found->second.state.ReadyCandidate(client_admission_title_id, current_user);
      if (!candidate)
        return std::nullopt;
      snapshot.lifecycle_token = found->second.state.lifecycle_token();
      snapshot.discovery_socket = found->second.socket;
      snapshot.peer = found->second.peer;
      snapshot.directory_session_id = found->second.state.directory_session_id();
      snapshot.attempt_id = found->second.state.attempt_id();
      snapshot.admission_generation = found->second.state.admission_generation();
      snapshot.lease_revision = found->second.state.lease_revision();
      snapshot.candidate = std::move(*candidate);
    }

    const auto matches =
        NatProbeMatchAcknowledgedDiscoveryAttempts(snapshot.discovery_socket, snapshot.peer);
    const bool exact_nat =
        std::find(matches.begin(), matches.end(), snapshot.attempt_id) != matches.end();
    auto revalidated_user = client_admission_user_identity
                                ? client_admission_user_identity(local_user_index)
                                : std::optional<uint64_t>{};

    std::lock_guard lock(client_admission_mutex);
    auto found = client_admissions.find(local_user_index);
    if (found == client_admissions.end() ||
        found->second.state.lifecycle_token() != snapshot.lifecycle_token ||
        found->second.state.directory_session_id() != snapshot.directory_session_id ||
        found->second.state.attempt_id() != snapshot.attempt_id ||
        found->second.state.admission_generation() != snapshot.admission_generation ||
        found->second.state.lease_revision() != snapshot.lease_revision)
      return std::nullopt;
    auto active = client_admission_users.find(local_user_index);
    if (!client_admission_user_identity && active != client_admission_users.end())
      revalidated_user = active->second;
    auto current = found->second.state.ReadyCandidate(client_admission_title_id, revalidated_user);
    if (!exact_nat || !current) {
      QueueCancellationLocked(found->second);
      client_admissions.erase(found);
      client_admission_wake.notify_all();
      if (!exact_nat)
        REXSYS_WARN("Session directory: ready candidate lost exact NAT correlation");
      return std::nullopt;
    }
    return current;
  }

 private:
  struct ClientAdmissionContext {
    ClientAdmissionLeaseState state;
    uint64_t socket = 0;
    LanAddress peer{};
    bool exchange_active = false;
  };

  void QueueCancellationLocked(const ClientAdmissionContext& context) {
    if (!context.state.bound())
      return;
    client_admission_cancellations.push_back(
        {context.state.local_user_index(), context.state.lifecycle_token(),
         context.state.directory_session_id(), context.state.attempt_id(),
         context.state.capability(), context.state.admission_generation(),
         context.state.lease_revision(), context.state.leased(), context.socket});
  }

  void HarvestListLocked() const {
    if (!list_future.valid() ||
        list_future.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
      return;
    try {
      list_cache = list_future.get();
    } catch (const std::exception& exception) {
      REXSYS_WARN("Session directory: asynchronous list request failed: {}", exception.what());
      list_cache = std::vector<DirectorySession>{};
    }
    list_cache_title_id = list_future_title_id;
    list_cache_time = std::chrono::steady_clock::now();
  }

  void HostLoop(std::stop_token stop) {
    auto host_instance_id = RandomUrlToken(16);
    auto host_instance_token = RandomUrlToken(32);
    if (!host_instance_id || !host_instance_token) {
      REXSYS_WARN("Session directory: secure host registration identity unavailable");
      return;
    }
    DirectoryHostPollRuntimeState poll_state;
    auto& session_id = poll_state.directory_session_id;
    auto& host_attempts = poll_state.host_attempts;
    auto& polled_private_attempts = poll_state.private_attempts;
    auto& pending_completions = poll_state.pending_completions;
    auto& recovering = poll_state.recovering;
    auto& token = poll_state.registration_token;
    auto& public_invite_code = poll_state.public_invite_code;
    auto next_heartbeat = std::chrono::steady_clock::time_point{};
    auto next_registration = std::chrono::steady_clock::time_point{};
    auto retry_delay = kHeartbeatRetryInitial;
    auto schedule_retry = [&] {
      next_registration = std::chrono::steady_clock::now() + retry_delay;
      retry_delay = std::min(retry_delay * 2, kHeartbeatInterval);
    };
    auto schedule_heartbeat = [&] {
      retry_delay = kHeartbeatRetryInitial;
      next_heartbeat = std::chrono::steady_clock::now() + kHeartbeatInterval;
    };
    while (!stop.stop_requested()) {
      auto registration = RegistrationPayload(*hosted, title_id, discovery_port);
      auto heartbeat_body = registration.dump();
      registration["host_instance_id"] = *host_instance_id;
      registration["host_instance_token"] = *host_instance_token;
      auto registration_body = registration.dump();
      std::optional<HttpResult> response;
      auto now = std::chrono::steady_clock::now();
      if ((session_id.empty() || recovering) && now >= next_registration) {
        response =
            Request(REXCVAR_GET(session_directory_url), L"POST", "/sessions", registration_body);
        bool accepted = false;
        if (response && (response->status == 200 || response->status == 201)) {
          auto document = nlohmann::json::parse(response->body, nullptr, false);
          if (document.is_object()) {
            auto candidate_session_id = document.value("session_id", "");
            auto candidate_token = document.value("registration_token", "");
            auto candidate_invite_code = document.value("invite_code", "");
            if (IsUrlToken(candidate_session_id, 64) && IsUrlToken(candidate_token, 128) &&
                NormalizeInviteCode(candidate_invite_code)) {
              bool changed = !session_id.empty() && candidate_session_id != session_id;
              session_id = std::move(candidate_session_id);
              token = std::move(candidate_token);
              accepted = true;
              if (recovering && changed)
                REXSYS_INFO("Session directory: recovered '{}' with replacement {}",
                            hosted->host_name, session_id);
              else if (recovering)
                REXSYS_INFO("Session directory: recovered '{}' as {}", hosted->host_name,
                            session_id);
              else
                REXSYS_INFO("Session directory: registered '{}' as {}", hosted->host_name,
                            session_id);
              public_invite_code = *NormalizeInviteCode(candidate_invite_code);
              hosted->SetStatusInviteCode(public_invite_code);
              REXSYS_INFO("Harmony invite code: {}", candidate_invite_code);
              if (auto path = ActiveInviteCodePath();
                  path && !WriteActiveInviteCodeFile(*path, candidate_invite_code))
                REXSYS_WARN("Harmony invite code: could not publish launcher state");
            }
          }
        }
        if (accepted) {
          recovering = false;
          schedule_heartbeat();
        } else {
          if (response &&
              (response->status == 400 || response->status == 401 || response->status == 403))
            REXSYS_WARN("Session directory: host registration rejected with HTTP {}",
                        response->status);
          else if (response)
            REXSYS_WARN("Session directory: host registration HTTP {}; retrying same identity",
                        response->status);
          else
            REXSYS_WARN(
                "Session directory: host registration transport failure; retrying same identity");
          schedule_retry();
        }
      } else if (!recovering && !session_id.empty() && now >= next_heartbeat) {
        response = Request(REXCVAR_GET(session_directory_url), L"POST",
                           "/sessions/" + session_id + "/heartbeat", heartbeat_body, token);
        bool valid_session_id = false;
        if (response && response->status == 200) {
          auto document = nlohmann::json::parse(response->body, nullptr, false);
          valid_session_id = document.is_object() && document.value("session_id", "") == session_id;
        }
        auto disposition = ClassifyDirectoryHeartbeatResponse(
            response ? std::optional<uint32_t>(response->status) : std::nullopt, valid_session_id);
        switch (disposition) {
          case DirectoryHeartbeatDisposition::kAccepted:
            hosted->SetStatusInviteCode(public_invite_code);
            schedule_heartbeat();
            break;
          case DirectoryHeartbeatDisposition::kRetrySameRegistration:
            if (response)
              REXSYS_WARN("Session directory: heartbeat HTTP {}; retrying same registration",
                          response->status);
            else
              REXSYS_WARN(
                  "Session directory: heartbeat transport failure; retrying same registration");
            next_heartbeat = std::chrono::steady_clock::now() + retry_delay;
            retry_delay = std::min(retry_delay * 2, kHeartbeatInterval);
            break;
          case DirectoryHeartbeatDisposition::kRecoverRegistration:
            hosted->SetStatusInviteCode({});
            REXSYS_WARN("Session directory: heartbeat returned 404; recovering logical lobby");
            if (admission_grants)
              admission_grants->InvalidateSession(session_id);
            for (const auto& attempt : host_attempts)
              NatProbeRetireIdentity(attempt);
            host_attempts.clear();
            polled_private_attempts.clear();
            pending_completions.clear();
            recovering = true;
            next_registration = std::chrono::steady_clock::now();
            retry_delay = kHeartbeatRetryInitial;
            break;
          case DirectoryHeartbeatDisposition::kRejected:
            hosted->SetStatusInviteCode({});
            REXSYS_WARN("Session directory: heartbeat rejected with HTTP {}", response->status);
            next_heartbeat = std::chrono::steady_clock::now() + kHeartbeatInterval;
            break;
        }
      }
      if (!session_id.empty() && !recovering) {
        if (admission_grants) {
          auto completed = admission_grants->TakeCompletions();
          pending_completions.insert(pending_completions.end(),
                                     std::make_move_iterator(completed.begin()),
                                     std::make_move_iterator(completed.end()));
          std::erase_if(pending_completions, [&](const auto& completion) {
            if (completion.directory_session_id != session_id)
              return true;
            auto response =
                Request(REXCVAR_GET(session_directory_url), L"DELETE",
                        "/sessions/" + session_id + "/join-attempts/" + completion.attempt_id, "",
                        completion.capability);
            return response && (response->status == 204 || response->status == 404);
          });
        }
        nlohmann::json acknowledgements = nlohmann::json::array();
        std::unordered_set<std::string> acknowledged_ids;
        for (const auto& acknowledged : NatProbeAcknowledgedDiscoveryAttempts()) {
          auto found = polled_private_attempts.find(acknowledged.attempt_id);
          if (found == polled_private_attempts.end() ||
              !acknowledged_ids.insert(acknowledged.attempt_id).second)
            continue;
          const auto& attempt = found->second;
          acknowledgements.push_back({{"attempt_id", attempt.attempt_id},
                                      {"admission_generation", attempt.admission_generation},
                                      {"lease_revision", attempt.lease_revision}});
        }
        const auto poll_started_at = std::chrono::steady_clock::now();
        auto pending =
            Request(REXCVAR_GET(session_directory_url), L"POST",
                    "/sessions/" + session_id + "/join-attempts/poll",
                    nlohmann::json{{"acknowledged", std::move(acknowledgements)}}.dump(), token);
        auto snapshot = pending && pending->status == 200
                            ? ParseDirectoryHostPollSnapshot(pending->body, session_id)
                            : std::nullopt;
        const auto disposition = ClassifyDirectoryHostPollResponse(
            pending ? std::optional<uint32_t>(pending->status) : std::nullopt,
            snapshot.has_value());
        const auto attempts = snapshot ? std::span<const DirectoryTraversalAttempt>(*snapshot)
                                       : std::span<const DirectoryTraversalAttempt>{};
        auto transition = ApplyDirectoryHostPollResult(
            disposition, attempts, poll_state, admission_grants.get(), *hosted, poll_started_at);
        if (transition.recover_now) {
          REXSYS_WARN("Session directory: host poll returned 404; recovering logical lobby");
          next_registration = std::chrono::steady_clock::now();
          retry_delay = kHeartbeatRetryInitial;
        }
      }
      std::unique_lock lock(wait_mutex);
      wake.wait_for(lock, kTraversalPollInterval, [&] { return stop.stop_requested(); });
    }
    for (const auto& attempt : host_attempts)
      NatProbeRetireIdentity(attempt);
    if (admission_grants)
      admission_grants->InvalidateSession(session_id);
    if (!session_id.empty())
      Request(REXCVAR_GET(session_directory_url), L"DELETE", "/sessions/" + session_id, "", token);
    hosted->SetStatusInviteCode({});
    if (auto path = ActiveInviteCodePath())
      RemoveActiveInviteCodeFile(*path);
  }

  ClientAdmissionTransportResponse PerformClientAdmissionTransport(
      const ClientAdmissionTransportRequest& request) {
    if (client_admission_transport)
      return client_admission_transport(request);

    std::wstring_view method = L"GET";
    std::string suffix = "/admission";
    std::string body;
    if (request.action == ClientAdmissionTransportAction::kArm) {
      method = L"POST";
      suffix += "/arm";
      body = "{}";
    } else if (request.action == ClientAdmissionTransportAction::kRenew) {
      method = L"POST";
      suffix += "/renew";
      body = nlohmann::json{{"admission_generation", request.admission_generation},
                            {"previous_lease_revision", request.expected_revision}}
                 .dump();
    } else if (request.action == ClientAdmissionTransportAction::kRevoke) {
      method = L"POST";
      suffix = "/admission/revoke";
      body = "{}";
    } else if (request.action == ClientAdmissionTransportAction::kDelete) {
      method = L"DELETE";
      suffix.clear();
    }
    auto response = Request(REXCVAR_GET(session_directory_url), method,
                            "/sessions/" + request.directory_session_id + "/join-attempts/" +
                                request.attempt_id + suffix,
                            body, request.capability);
    ClientAdmissionTransportResponse result;
    if (response) {
      result.status = response->status;
      result.body = std::move(response->body);
    }
    result.completed_at = ClientAdmissionLeaseState::Clock::now();
    return result;
  }

 public:
  void PollClientAdmissions(ClientAdmissionLeaseState::Clock::time_point now) {
    std::lock_guard poll_lock(client_admission_poll_mutex);
    std::vector<ClientAdmissionCancellation> cancellations;
    std::vector<ClientAdmissionOperation> operations;
    std::unordered_map<uint32_t, std::optional<uint64_t>> live_users;
    if (client_admission_user_identity) {
      std::vector<uint32_t> users;
      {
        std::lock_guard lock(client_admission_mutex);
        users.reserve(client_admissions.size());
        for (const auto& [local_user_index, _] : client_admissions)
          users.push_back(local_user_index);
      }
      for (uint32_t local_user_index : users)
        live_users[local_user_index] = client_admission_user_identity(local_user_index);
    }
    {
      std::lock_guard lock(client_admission_mutex);
      cancellations.assign(client_admission_cancellations.begin(),
                           client_admission_cancellations.end());
      client_admission_cancellations.clear();
      for (auto iterator = client_admissions.begin(); iterator != client_admissions.end();) {
        auto& context = iterator->second;
        auto user = client_admission_users.find(iterator->first);
        auto current_user = client_admission_user_identity ? live_users[iterator->first]
                                                           : (user == client_admission_users.end()
                                                                  ? std::optional<uint64_t>{}
                                                                  : user->second);
        if ((context.state.leased() && now >= context.state.lease_deadline()) ||
            !context.state.ValidateLiveness(client_admission_title_id, current_user)) {
          QueueCancellationLocked(context);
          iterator = client_admissions.erase(iterator);
          continue;
        }
        if (auto operation = context.state.BeginOperation(context.socket, context.peer.ipv4,
                                                          context.peer.port, now))
          operations.push_back(std::move(*operation));
        ++iterator;
      }
      cancellations.insert(cancellations.end(), client_admission_cancellations.begin(),
                           client_admission_cancellations.end());
      client_admission_cancellations.clear();
    }

    for (const auto& cancellation : cancellations) {
      ClientAdmissionTransportRequest request;
      request.action = cancellation.admission_armed ? ClientAdmissionTransportAction::kRevoke
                                                    : ClientAdmissionTransportAction::kDelete;
      request.local_user_index = cancellation.local_user_index;
      request.lifecycle_token = cancellation.lifecycle_token;
      request.directory_session_id = cancellation.directory_session_id;
      request.attempt_id = cancellation.attempt_id;
      request.capability = cancellation.capability;
      request.admission_generation = cancellation.admission_generation;
      request.expected_revision = cancellation.lease_revision;
      request.request_started_at = now;
      PerformClientAdmissionTransport(request);
      NatProbeRetireIdentity(cancellation.attempt_id);
      if (cancellation.discovery_socket) {
        NatProbeDetach(cancellation.discovery_socket);
#if REX_PLATFORM_WIN32
        closesocket(SOCKET(cancellation.discovery_socket));
#else
        close(int(cancellation.discovery_socket));
#endif
      }
    }

    for (auto& operation : operations) {
        NatProbeTickAt(operation.discovery_socket, now);
        if (operation.action == ClientAdmissionAction::kArm &&
            !NatProbeRendezvousAttemptActive(operation.discovery_socket, operation.attempt_id)) {
          std::lock_guard lock(client_admission_mutex);
          auto found = client_admissions.find(operation.local_user_index);
          if (found != client_admissions.end() &&
              found->second.state.lifecycle_token() == operation.lifecycle_token) {
            const ClientAdmissionCancellation cancellation{
                found->second.state.local_user_index(),
                found->second.state.lifecycle_token(),
                found->second.state.directory_session_id(),
                found->second.state.attempt_id(),
                found->second.state.capability(),
                found->second.state.admission_generation(),
                found->second.state.lease_revision(),
                found->second.state.leased(),
                found->second.socket};
            found->second.state.EndAttemptAuthority(operation);
            client_admission_cancellations.push_back(cancellation);
            client_admissions.erase(found);
          }
          REXSYS_WARN("Session directory: pre-arm attempt authority ended");
          continue;
        }

        bool exchange_active = false;
        {
          std::lock_guard lock(client_admission_mutex);
          auto found = client_admissions.find(operation.local_user_index);
          exchange_active = found != client_admissions.end() &&
                            found->second.state.lifecycle_token() == operation.lifecycle_token &&
                            found->second.exchange_active;
        }
#if REX_PLATFORM_WIN32
        if (!exchange_active) {
          sockaddr_in source{};
          int source_length = sizeof(source);
          std::array<uint8_t, 512> packet{};
          int count =
              recvfrom(SOCKET(operation.discovery_socket), reinterpret_cast<char*>(packet.data()),
                       int(packet.size()), 0, reinterpret_cast<sockaddr*>(&source), &source_length);
          if (count > 0)
            NatProbeConsume(operation.discovery_socket, packet.data(), size_t(count),
                            source.sin_addr.s_addr, ntohs(source.sin_port));
        }
#endif

        const LanAddress peer{operation.peer_ipv4, operation.peer_port};
        auto matches = NatProbeMatchAcknowledgedDiscoveryAttempts(operation.discovery_socket, peer);
        if (std::find(matches.begin(), matches.end(), operation.attempt_id) == matches.end()) {
          std::lock_guard lock(client_admission_mutex);
          auto found = client_admissions.find(operation.local_user_index);
          if (found != client_admissions.end() &&
              found->second.state.lifecycle_token() == operation.lifecycle_token) {
            QueueCancellationLocked(found->second);
            client_admissions.erase(found);
          }
          REXSYS_WARN("Session directory: client admission lost exact discovery binding");
          continue;
        }

        ClientAdmissionTransportRequest request;
        request.action = operation.action == ClientAdmissionAction::kArm
                             ? ClientAdmissionTransportAction::kArm
                         : operation.action == ClientAdmissionAction::kRenew
                             ? ClientAdmissionTransportAction::kRenew
                             : ClientAdmissionTransportAction::kStatus;
        request.local_user_index = operation.local_user_index;
        request.lifecycle_token = operation.lifecycle_token;
        request.directory_session_id = operation.directory_session_id;
        request.attempt_id = operation.attempt_id;
        request.capability = operation.capability;
        request.admission_generation = operation.admission_generation;
        request.expected_revision = operation.expected_revision;
        request.request_started_at = operation.request_started_at;
        auto response = PerformClientAdmissionTransport(request);

        const auto response_matches = NatProbeMatchAcknowledgedDiscoveryAttempts(
            operation.discovery_socket, peer);
        const bool response_nat_current =
            std::find(response_matches.begin(), response_matches.end(), operation.attempt_id) !=
            response_matches.end();

        auto response_user = client_admission_user_identity
                                 ? client_admission_user_identity(operation.local_user_index)
                                 : std::optional<uint64_t>{};

        std::lock_guard lock(client_admission_mutex);
        auto found = client_admissions.find(operation.local_user_index);
        if (found == client_admissions.end() ||
            found->second.state.lifecycle_token() != operation.lifecycle_token ||
            found->second.state.directory_session_id() != operation.directory_session_id ||
            found->second.state.attempt_id() != operation.attempt_id ||
            (found->second.state.leased() &&
             (found->second.state.admission_generation() != operation.admission_generation ||
              found->second.state.lease_revision() != operation.expected_revision)))
          continue;
        const auto response_received_at =
            response.completed_at.value_or(ClientAdmissionLeaseState::Clock::now());
        const auto user = client_admission_users.find(operation.local_user_index);
        if (!client_admission_user_identity && user != client_admission_users.end())
          response_user = user->second;
        const ClientAdmissionCancellation cancellation_before_apply{
            found->second.state.local_user_index(),
            found->second.state.lifecycle_token(),
            found->second.state.directory_session_id(),
            found->second.state.attempt_id(),
            found->second.state.capability(),
            found->second.state.admission_generation(),
            found->second.state.lease_revision(),
            found->second.state.leased(),
            found->second.socket};
        if (!response_nat_current ||
            !found->second.state.ValidateLiveness(client_admission_title_id, response_user) ||
            (found->second.state.leased() &&
             response_received_at >= found->second.state.lease_deadline())) {
          client_admission_cancellations.push_back(cancellation_before_apply);
          client_admissions.erase(found);
          REXSYS_WARN(
              "Session directory: client admission expired or lost ownership while HTTP was in "
              "flight");
          continue;
        }
        auto admission = response.status ? ParseDirectoryAdmissionResponse(response.body)
                                         : std::nullopt;
        auto disposition = ClassifyClientAdmissionResponse(
            operation.action, response.status, admission.has_value());
        const bool was_ready = found->second.state.host_ready();
        ClientAdmissionApplyResult applied = ClientAdmissionApplyResult::kApplied;
        if (disposition == ClientAdmissionResponseDisposition::kRetainUntilExpiry) {
          applied = found->second.state.ApplyTransportFailure(operation, response_received_at);
        } else if (disposition == ClientAdmissionResponseDisposition::kReconcileStatus) {
          applied = found->second.state.ApplyTransportFailure(operation, response_received_at);
        } else if (disposition == ClientAdmissionResponseDisposition::kApply) {
          applied = found->second.state.ApplyResponse(operation, *admission, response_received_at);
          if (operation.action == ClientAdmissionAction::kRenew &&
              applied == ClientAdmissionApplyResult::kApplied)
            REXSYS_INFO("Session directory: client admission renewed revision={}",
                        found->second.state.lease_revision());
          if (!was_ready && found->second.state.host_ready())
            REXSYS_INFO("Session directory: client admission ready revision={}",
                        found->second.state.lease_revision());
        } else {
          applied = ClientAdmissionApplyResult::kInvalidated;
        }
        if (applied == ClientAdmissionApplyResult::kInvalidated) {
          client_admission_cancellations.push_back(cancellation_before_apply);
          client_admissions.erase(found);
          REXSYS_WARN("Session directory: authoritative client admission state invalidated");
        }
    }
  }

 private:
  void ClientAdmissionLoop(std::stop_token stop) {
    for (;;) {
      PollClientAdmissions(ClientAdmissionLeaseState::Clock::now());

      if (stop.stop_requested()) {
        std::lock_guard lock(client_admission_mutex);
        if (client_admissions.empty() && client_admission_cancellations.empty())
          break;
      }
      std::unique_lock lock(client_admission_wait_mutex);
      client_admission_wake.wait_for(lock, kTraversalPollInterval,
                                     [&] { return stop.stop_requested(); });
    }
  }

  std::shared_ptr<SessionRecord> hosted;
  std::shared_ptr<HostAdmissionGrantStore> admission_grants;
  uint32_t title_id = 0;
  uint16_t discovery_port = 0;
  std::jthread worker;
  std::condition_variable wake;
  std::mutex wait_mutex;
  mutable std::mutex list_mutex;
  mutable std::future<std::vector<DirectorySession>> list_future;
  mutable std::optional<std::vector<DirectorySession>> list_cache;
  mutable uint32_t list_future_title_id = 0;
  mutable uint32_t list_cache_title_id = 0;
  mutable std::chrono::steady_clock::time_point list_cache_time{};
  mutable std::mutex client_admission_mutex;
  LocalUserIdentityProvider client_admission_user_identity;
  ClientAdmissionTransport client_admission_transport;
  uint32_t client_admission_title_id = 0;
  uint64_t next_client_admission_token = 0;
  std::unordered_map<uint32_t, std::optional<uint64_t>> client_admission_users;
  std::unordered_map<uint32_t, ClientAdmissionContext> client_admissions;
  std::deque<ClientAdmissionCancellation> client_admission_cancellations;
  std::mutex client_admission_poll_mutex;
  std::condition_variable client_admission_wake;
  std::mutex client_admission_wait_mutex;
  std::jthread client_admission_worker;
};

SessionDirectoryClient::SessionDirectoryClient(
    LocalUserIdentityProvider user_identity,
    ClientAdmissionTransport client_admission_transport,
    bool automatic_client_admission_driver)
    : impl_(std::make_unique<Impl>(std::move(user_identity),
                                  std::move(client_admission_transport),
                                  automatic_client_admission_driver)) {}
SessionDirectoryClient::~SessionDirectoryClient() = default;
void SessionDirectoryClient::StartHosting(
    const std::shared_ptr<SessionRecord>& session, uint32_t title_id, uint16_t discovery_port,
    std::shared_ptr<HostAdmissionGrantStore> admission_grants) {
  impl_->StartHosting(session, title_id, discovery_port, std::move(admission_grants));
}
void SessionDirectoryClient::StopHosting() {
  impl_->StopHosting();
}
std::vector<DirectorySession> SessionDirectoryClient::List(uint32_t title_id) const {
  return impl_->List(title_id);
}
void SessionDirectoryClient::RequestList(uint32_t title_id) const {
  impl_->RequestList(title_id);
}
std::optional<std::vector<DirectorySession>> SessionDirectoryClient::CachedList(
    uint32_t title_id) const {
  return impl_->CachedList(title_id);
}
std::optional<DirectorySession> SessionDirectoryClient::ResolveInviteCode(std::string_view code,
                                                                          uint32_t title_id) const {
  return impl_->ResolveInviteCode(code, title_id);
}
std::optional<DirectoryInviteJoinAttempt> SessionDirectoryClient::CreateInviteCodeJoinAttempt(
    std::string_view code, uint32_t title_id) const {
  return impl_->CreateInviteCodeJoinAttempt(code, title_id);
}
std::optional<DirectoryTraversalAttempt> SessionDirectoryClient::CreateJoinAttempt(
    const std::string& session_id) const {
  return impl_->CreateJoinAttempt(session_id);
}
void SessionDirectoryClient::CompleteJoinAttempt(const DirectoryTraversalAttempt& attempt) const {
  impl_->CompleteJoinAttempt(attempt);
}
ClientAdmissionPrepareResult SessionDirectoryClient::PrepareClientAdmission(
    uint32_t local_user_index, uint32_t title_id, const DirectoryTraversalAttempt& attempt,
    const SessionRecord& discovered, uint64_t discovery_socket) {
  return impl_->PrepareClientAdmission(local_user_index, title_id, attempt, discovered,
                                       discovery_socket);
}
bool SessionDirectoryClient::ConfirmClientAdmissionSession(
    uint32_t local_user_index, const std::shared_ptr<const SessionRecord>& session) {
  return impl_->ConfirmClientAdmissionSession(local_user_index, session);
}
void SessionDirectoryClient::SetClientAdmissionTitle(uint32_t title_id) {
  impl_->SetClientAdmissionTitle(title_id);
}
void SessionDirectoryClient::SetClientAdmissionUserIdentity(uint32_t local_user_index,
                                                            std::optional<uint64_t> xuid) {
  impl_->SetClientAdmissionUserIdentity(local_user_index, xuid);
}
void SessionDirectoryClient::StopClientAdmission(uint32_t local_user_index) {
  impl_->StopClientAdmission(local_user_index);
}
void SessionDirectoryClient::StopAllClientAdmissions() {
  impl_->StopAllClientAdmissions();
}
bool SessionDirectoryClient::HasClientAdmission(uint32_t local_user_index) const {
  return impl_->HasClientAdmission(local_user_index);
}
bool SessionDirectoryClient::HasProtectedClientAdmission(uint32_t local_user_index) const {
  return impl_->HasProtectedClientAdmission(local_user_index);
}
std::optional<uint64_t> SessionDirectoryClient::ClientAdmissionSocketForSession(
    uint32_t local_user_index, const SessionRecord& session) const {
  return impl_->ClientAdmissionSocketForSession(local_user_index, session);
}
void SessionDirectoryClient::SetClientAdmissionExchange(uint32_t local_user_index, bool active) {
  impl_->SetClientAdmissionExchange(local_user_index, active);
}
std::optional<ReadyAcceptedSessionCandidate> SessionDirectoryClient::ReadyClientAdmission(
    uint32_t local_user_index) {
  return impl_->ReadyClientAdmission(local_user_index);
}
void SessionDirectoryClient::PollClientAdmissions(
    std::chrono::steady_clock::time_point now) {
  impl_->PollClientAdmissions(now);
}

}  // namespace rex::system::xam
