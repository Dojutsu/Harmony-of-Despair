#include <rex/system/xam/gameplay_traversal.h>

#include <algorithm>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <rex/logging.h>
#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

namespace rex::system::xam {
namespace {
using Clock = std::chrono::steady_clock;
struct Scope {
  std::weak_ptr<SessionRecord> session;
  uint64_t xuid = 0;
  GameplayAuthorization authorization;
  std::optional<uint64_t> socket;
  uint16_t guest_port = 0;
  bool closed = false;
};
std::mutex gameplay_mutex;
std::vector<Scope> scopes;
struct SocketCandidate { uint64_t xuid, socket; uint16_t port; bool owned = false; };
std::vector<SocketCandidate> socket_candidates;

void ClaimSocketCandidate(Scope& scope) {
  if (scope.socket || scope.closed) return;
  SocketCandidate* selected = nullptr;
  for (auto& candidate : socket_candidates) {
    if (candidate.xuid != scope.xuid || candidate.owned) continue;
    if (selected) return; // Ambiguous sockets may never inherit a credential.
    selected = &candidate;
  }
  if (selected) {
    selected->owned = true;
    scope.socket = selected->socket;
    scope.guest_port = selected->port;
    REXSYS_INFO("GAMEPLAY_SOCKET_BOUND socket={} xuid={:016X} session={} admission={}",
        *scope.socket, scope.xuid, scope.authorization.directory_session,
        scope.authorization.admission_generation);
  }
}

bool MemberCurrent(const Scope& scope) {
  const auto session = scope.session.lock();
  if (!session || scope.closed) return false;
  std::lock_guard lock(*session->mutex);
  if (session->state == SessionState::kDeleted) return false;
  const auto member = std::find_if(session->members.begin(), session->members.end(),
      [&](const auto& value) { return value.xuid == scope.xuid && value.local; });
  if (member == session->members.end()) return false;
  if (scope.authorization.member_nonce.empty())
    return session->host_xuid == scope.xuid || bool(member->gameplay_admission);
  if (scope.authorization.xbox_session != session->info.id ||
      scope.authorization.host_xuid != session->host_xuid) return false;
  if (scope.xuid == session->host_xuid) return true;
  const auto& binding = member->gameplay_admission;
  return binding && binding->directory_session_id == scope.authorization.directory_session &&
         binding->attempt_id == scope.authorization.admission_attempt &&
         binding->admission_generation == scope.authorization.admission_generation;
}

bool Current(const Scope& scope) {
  return MemberCurrent(scope) && !scope.authorization.member_nonce.empty() &&
         Clock::now() < scope.authorization.expires_at;
}

bool PeerCurrent(const Scope& scope, const GameplayPeerAuthorization& peer) {
  const auto session = scope.session.lock();
  if (!session) return false;
  if (scope.xuid != scope.authorization.host_xuid) return true;
  std::lock_guard lock(*session->mutex);
  auto found = std::find_if(session->members.begin(), session->members.end(),
      [&](const auto& m) { return m.xuid == peer.xuid; });
  if (found == session->members.end() || !found->gameplay_admission) return false;
  return found->gameplay_admission->directory_session_id == scope.authorization.directory_session &&
         found->gameplay_admission->attempt_id == peer.admission_attempt &&
         found->gameplay_admission->admission_generation == peer.admission_generation;
}

void RemoveRoutes(Scope& scope) {
  if (scope.socket)
    for (const auto& peer : scope.authorization.peers)
      NatProbeRemoveGameplayIdentity(*scope.socket, peer.traversal.attempt_id);
}

void Reap() {
  for (auto& scope : scopes)
    if (!Current(scope)) RemoveRoutes(scope);
    else if (scope.socket)
      for (const auto& peer : scope.authorization.peers)
        if (!PeerCurrent(scope, peer))
          NatProbeRemoveGameplayIdentity(*scope.socket, peer.traversal.attempt_id);
  std::erase_if(scopes, [](const auto& scope) { return scope.session.expired(); });
}

bool InstallRoutes(Scope& scope) {
  if (!scope.socket || !Current(scope)) return true;
  for (const auto& peer : scope.authorization.peers) {
    if (!PeerCurrent(scope, peer)) {
      NatProbeRemoveGameplayIdentity(*scope.socket, peer.traversal.attempt_id);
      continue;
    }
    auto logical = peer.logical;
    logical.port = scope.guest_port;
    if (!NatProbeInstallGameplayIdentity(peer.traversal, *scope.socket, logical,
                                         scope.authorization.expires_at)) return false;
  }
  return true;
}
}  // namespace

bool IsGameplayLogicalAddress(uint32_t ipv4) {
  return (ntohl(ipv4) & 0xff000000u) == 0xf0000000u;
}

void RegisterGameplaySocketCandidate(uint64_t local_xuid, uint64_t socket, uint16_t guest_port) {
  if (!local_xuid) {
    REXSYS_WARN("GAMEPLAY_SOCKET_CANDIDATE_REJECT reason=missing_xuid socket={} port={}",
                socket, guest_port);
    return;
  }
  if (!guest_port) {
    REXSYS_WARN("GAMEPLAY_SOCKET_CANDIDATE_REJECT reason=missing_port socket={} xuid={:016X}",
                socket, local_xuid);
    return;
  }
  std::lock_guard lock(gameplay_mutex);
  if (std::none_of(socket_candidates.begin(), socket_candidates.end(),
                  [&](const auto& candidate) { return candidate.socket == socket; })) {
    socket_candidates.push_back({local_xuid, socket, guest_port});
    REXSYS_INFO("GAMEPLAY_SOCKET_CANDIDATE_ADDED socket={} xuid={:016X} port={}",
                socket, local_xuid, guest_port);
  } else {
    REXSYS_WARN("GAMEPLAY_SOCKET_CANDIDATE_DUPLICATE socket={} xuid={:016X} port={}",
                socket, local_xuid, guest_port);
  }
}

bool TrackGameplayAdmission(const std::shared_ptr<SessionRecord>& session, uint64_t xuid) {
  REXSYS_INFO("GAMEPLAY_ADMISSION_TRACK_BEGIN session_present={} xuid={:016X}",
              session != nullptr, xuid);
  if (!session) {
    REXSYS_WARN("GAMEPLAY_ADMISSION_TRACK_REJECT reason=missing_session xuid={:016X}", xuid);
    return false;
  }
  if (!xuid) {
    REXSYS_WARN("GAMEPLAY_ADMISSION_TRACK_REJECT reason=missing_xuid");
    return false;
  }
  Scope candidate;
  candidate.session = session;
  candidate.xuid = xuid;
  std::lock_guard lock(gameplay_mutex);
  Reap();
  if (!MemberCurrent(candidate)) {
    REXSYS_WARN("GAMEPLAY_ADMISSION_TRACK_REJECT reason=member_not_current xuid={:016X}", xuid);
    return false;
  }
  auto found = std::find_if(scopes.begin(), scopes.end(), [&](const auto& scope) {
    return scope.session.lock() == session && scope.xuid == xuid;
  });
  if (found != scopes.end()) {
    const bool accepted = !found->closed;
    REXSYS_INFO("GAMEPLAY_ADMISSION_TRACK_RESULT success={} reason={} xuid={:016X}",
                accepted, accepted ? "already_tracked" : "scope_closed", xuid);
    return accepted;
  }
  scopes.push_back(std::move(candidate));
  REXSYS_INFO("GAMEPLAY_ADMISSION_TRACK_RESULT success=1 reason=created xuid={:016X}", xuid);
  return true;
}

bool InstallGameplayAuthorization(const std::shared_ptr<SessionRecord>& session,
                                   const GameplayAuthorization& authorization) {
  auto reject = [&](const char* reason) {
    REXSYS_WARN(
        "GAMEPLAY_AUTH_INSTALL_REJECT reason={} session={} xuid={:016X} host={:016X} "
        "admission={} attempt={} peers={}",
        reason, authorization.directory_session, authorization.xuid,
        authorization.host_xuid, authorization.admission_generation,
        authorization.admission_attempt, authorization.peers.size());
    return false;
  };
  if (!session) return reject("missing_session");
  if (!authorization.xuid) return reject("missing_xuid");
  if (!authorization.host_xuid) return reject("missing_host_xuid");
  if (authorization.directory_session.empty()) return reject("missing_directory_session");
  if (authorization.member_nonce.size() != 32) return reject("invalid_member_nonce");
  if (authorization.member_capability.size() != 32)
    return reject("invalid_member_capability");
  if (!IsGameplayLogicalAddress(authorization.logical.ipv4))
    return reject("invalid_logical_address");
  if (authorization.expires_at <= Clock::now()) return reject("authorization_expired");
  if (authorization.peers.size() > 5) return reject("too_many_peers");
  std::unordered_set<uint64_t> peers{authorization.xuid};
  std::unordered_set<uint32_t> addresses{authorization.logical.ipv4};
  std::unordered_set<std::string> links;
  for (const auto& peer : authorization.peers) {
    if (!peer.xuid) return reject("peer_missing_xuid");
    if (!peers.insert(peer.xuid).second) return reject("duplicate_peer_xuid");
    if (!addresses.insert(peer.logical.ipv4).second) return reject("duplicate_logical_address");
    if (!IsGameplayLogicalAddress(peer.logical.ipv4)) return reject("invalid_peer_logical_address");
    if (peer.member_nonce.size() != 32) return reject("invalid_peer_nonce");
    if (peer.traversal.attempt_id.size() != 32) return reject("invalid_peer_attempt");
    if (peer.traversal.capability.size() != 32) return reject("invalid_peer_capability");
    if (peer.traversal.participant > 1) return reject("invalid_peer_participant");
    if (!links.insert(peer.traversal.attempt_id).second) return reject("duplicate_peer_attempt");
  }
  Scope candidate;
  candidate.session = session;
  candidate.xuid = authorization.xuid;
  candidate.authorization = authorization;
  std::lock_guard lock(gameplay_mutex);
  Reap();
  if (!MemberCurrent(candidate)) return reject("member_not_current");
  auto found = std::find_if(scopes.begin(), scopes.end(), [&](const auto& s) {
    return s.session.lock() == session && s.xuid == authorization.xuid;
  });
  if (found != scopes.end()) {
    if (found->closed) return reject("scope_closed");
    if (!found->authorization.member_nonce.empty() &&
        found->authorization.member_nonce != authorization.member_nonce)
      return reject("member_nonce_changed");
    if (!found->authorization.member_nonce.empty() &&
        found->authorization.directory_session != authorization.directory_session)
      return reject("directory_session_changed");
    if (!found->authorization.member_nonce.empty() &&
        found->authorization.admission_attempt != authorization.admission_attempt)
      return reject("admission_attempt_changed");
    if (!found->authorization.member_nonce.empty() &&
        found->authorization.admission_generation != authorization.admission_generation)
      return reject("admission_generation_changed");
    candidate.socket = found->socket;
    candidate.guest_port = found->guest_port;
    // Preserve existing acknowledged link state; retire only omitted links.
    if (found->socket)
      for (const auto& old : found->authorization.peers)
        if (!links.contains(old.traversal.attempt_id))
          NatProbeRemoveGameplayIdentity(*found->socket, old.traversal.attempt_id);
    *found = std::move(candidate);
  } else {
    scopes.push_back(std::move(candidate));
    found = std::prev(scopes.end());
    REXSYS_INFO("GAMEPLAY_AUTH_ACQUIRED session={} xuid={:016X} admission={} links={}",
                authorization.directory_session, authorization.xuid,
                authorization.admission_generation, authorization.peers.size());
  }
  ClaimSocketCandidate(*found);
  const bool installed = InstallRoutes(*found);
  REXSYS_INFO(
      "GAMEPLAY_AUTH_INSTALL_RESULT success={} session={} xuid={:016X} admission={} "
      "attempt={} socket={} port={}",
      installed, authorization.directory_session, authorization.xuid,
      authorization.admission_generation, authorization.admission_attempt,
      found->socket.value_or(0), found->guest_port);
  return installed;
}

bool BindGameplaySocket(const std::shared_ptr<SessionRecord>& session, uint64_t local_xuid,
                        uint64_t socket, uint16_t guest_port) {
  auto reject = [&](const char* reason) {
    REXSYS_WARN("GAMEPLAY_SOCKET_BIND_REJECT reason={} socket={} xuid={:016X} port={}",
                reason, socket, local_xuid, guest_port);
    return false;
  };
  if (!session) return reject("missing_session");
  if (!local_xuid) return reject("missing_xuid");
  if (!guest_port) return reject("missing_port");
  std::lock_guard lock(gameplay_mutex);
  Reap();
  // One socket may serve exactly one session/local-member incarnation.
  for (const auto& scope : scopes)
    if (scope.socket == socket && (scope.session.lock() != session || scope.xuid != local_xuid))
      return reject("socket_owned_by_other_scope");
  auto found = std::find_if(scopes.begin(), scopes.end(), [&](const auto& s) {
    return s.session.lock() == session && s.xuid == local_xuid;
  });
  if (found == scopes.end()) {
    Scope candidate;
    candidate.session = session;
    candidate.xuid = local_xuid;
    if (!MemberCurrent(candidate)) return reject("member_not_current_for_new_scope");
    scopes.push_back(std::move(candidate));
    found = std::prev(scopes.end());
  }
  if (!MemberCurrent(*found)) return reject("member_not_current");
  if (found->socket && found->socket != socket) return reject("scope_has_other_socket");
  for (auto& candidate : socket_candidates)
    if (candidate.socket == socket) candidate.owned = true;
  found->socket = socket;
  found->guest_port = guest_port;
  REXSYS_INFO("GAMEPLAY_SOCKET_BOUND socket={} xuid={:016X} session={} admission={}",
              socket, local_xuid, found->authorization.directory_session,
              found->authorization.admission_generation);
  const bool installed = InstallRoutes(*found);
  REXSYS_INFO("GAMEPLAY_SOCKET_BIND_RESULT success={} socket={} xuid={:016X} port={}",
              installed, socket, local_xuid, guest_port);
  return installed;
}

void CloseGameplaySocket(uint64_t socket) {
  std::lock_guard lock(gameplay_mutex);
  bool associated = false;
  std::erase_if(socket_candidates, [&](const auto& candidate) { return candidate.socket == socket; });
  for (auto& scope : scopes)
    if (scope.socket == socket) {
      associated = true;
      REXSYS_INFO(
          "GAMEPLAY_SOCKET_CLOSE_ASSOCIATION socket={} xuid={:016X} session={} admission={} "
          "attempt={} authorized={}",
          socket, scope.xuid, scope.authorization.directory_session,
          scope.authorization.admission_generation,
          scope.authorization.admission_attempt,
          !scope.authorization.member_nonce.empty());
      RemoveRoutes(scope);
      scope.closed = true;  // A recycled native handle cannot inherit this ticket.
      scope.socket.reset();
    }
  if (!associated)
    REXSYS_INFO("GAMEPLAY_SOCKET_CLOSE_ASSOCIATION socket={} associated=0", socket);
}

void RevokeGameplayAuthorization(const std::shared_ptr<SessionRecord>& session, uint64_t local_xuid) {
  std::lock_guard lock(gameplay_mutex);
  for (auto& scope : scopes)
    if (scope.session.lock() == session && scope.xuid == local_xuid) {
      RemoveRoutes(scope);
      scope.closed = true;
    }
}

bool GameplayAuthorizationCurrent(const std::shared_ptr<SessionRecord>& session,
                                   uint64_t xuid, std::string_view nonce) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  return std::any_of(scopes.begin(), scopes.end(), [&](const auto& scope) {
    return scope.session.lock() == session && scope.xuid == xuid &&
           scope.authorization.member_nonce == nonce && Current(scope);
  });
}

bool IsAuthorizedGameplaySocket(uint64_t socket) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  // Keep failed/expired scopes fail-closed rather than falling back to raw UDP.
  return std::any_of(scopes.begin(), scopes.end(), [&](const auto& s) {
    if (s.socket != socket) return false;
    auto session = s.session.lock();
    return !s.authorization.member_nonce.empty() || (session && s.xuid != session->host_xuid);
  });
}

std::optional<LanAddress> GameplayLogicalDestination(uint64_t socket, LanAddress requested) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  for (const auto& scope : scopes) {
    if (scope.socket != socket) continue;
    auto session = scope.session.lock();
    if (!session) return std::nullopt;
    LanAddress original_host;
    { std::lock_guard session_lock(*session->mutex); original_host = session->info.host_address; }
    if (!Current(scope)) {
      // A pending or expired admitted client must not send its initial host
      // handshake through an unauthenticated endpoint fallback.
      if (scope.xuid != session->host_xuid && requested.ipv4 == original_host.ipv4)
        return requested;
      continue;
    }
    for (const auto& peer : scope.authorization.peers) {
      if (!PeerCurrent(scope, peer)) continue;
      const bool exact_alias = requested.ipv4 == peer.logical.ipv4;
      // The accepted-invite record was serialized before gameplay authorization.
      // Its exact host endpoint remains a valid initial destination for this
      // client only; it is never a fallback for another member or session.
      const bool initial_host = scope.xuid != scope.authorization.host_xuid &&
          peer.xuid == scope.authorization.host_xuid && requested.ipv4 == original_host.ipv4 &&
          (requested.port == scope.guest_port || requested.port == original_host.port);
      if (exact_alias || initial_host) return LanAddress{peer.logical.ipv4, scope.guest_port};
    }
  }
  return std::nullopt;
}

std::optional<GameplayXnAddr> GameplayXnAddrToLogical(
    const std::array<uint8_t, 8>& session_id, const XnAddrIdentity& identity) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  for (const auto& scope : scopes) {
    if (!Current(scope) || scope.authorization.xbox_session != session_id) continue;
    for (const auto& peer : scope.authorization.peers)
      if (PeerCurrent(scope, peer) && ReconstructXnAddrIdentity(peer.xuid) == identity)
        return GameplayXnAddr{session_id, peer.xuid, peer.logical};
  }
  return std::nullopt;
}

std::optional<GameplayXnAddr> GameplayLogicalToXnAddr(uint32_t ipv4) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  std::optional<GameplayXnAddr> result;
  for (const auto& scope : scopes) {
    if (!Current(scope)) continue;
    for (const auto& peer : scope.authorization.peers)
      if (peer.logical.ipv4 == ipv4 && PeerCurrent(scope, peer)) {
        if (result && (result->session_id != scope.authorization.xbox_session || result->xuid != peer.xuid))
          return std::nullopt;
        result = GameplayXnAddr{scope.authorization.xbox_session, peer.xuid, peer.logical};
      }
  }
  return result;
}
}  // namespace rex::system::xam
