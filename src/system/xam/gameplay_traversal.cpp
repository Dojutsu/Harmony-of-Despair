#include <rex/system/xam/gameplay_traversal.h>
#include <rex/system/xam/private_lan_invitation.h>

#include <algorithm>
#include <map>
#include <mutex>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <rex/logging.h>
#include <rex/cvar.h>
#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif

namespace rex::system::xam {
namespace {
using Clock = std::chrono::steady_clock;
// MSVC's hash containers allocate inside their move operations. Keeping both
// tables behind one owning pointer keeps Scope moves nothrow on every
// platform, which the noexcept publish path below relies on.
struct ScopeTables {
  std::unordered_map<std::string, std::shared_ptr<GameplayDatagramCipher>> ciphers;
  std::unordered_set<std::string> retired_links;
  // Logical peer address -> the address the guest last sent to for that peer.
  // The title may address the host by its serialized session endpoint before
  // the logical alias exists; replies must then appear from that same address.
  std::unordered_map<uint32_t, uint32_t> guest_aliases;
};
struct Scope {
  std::weak_ptr<SessionRecord> session;
  uint64_t xuid = 0;
  GameplayAuthorization authorization;
  std::optional<uint64_t> socket;
  uint16_t guest_port = 0;
  bool closed = false;
  std::unique_ptr<ScopeTables> tables = std::make_unique<ScopeTables>();
  auto& ciphers() { return tables->ciphers; }
  const auto& ciphers() const { return tables->ciphers; }
  auto& retired_links() { return tables->retired_links; }
  const auto& retired_links() const { return tables->retired_links; }
};
static_assert(std::is_nothrow_move_assignable_v<Scope>);
static_assert(std::is_nothrow_move_constructible_v<Scope>);
bool SameTrafficKey(const GameplayTrafficKey& a, const GameplayTrafficKey& b) {
  uint8_t difference = 0;
  for (size_t i = 0; i < a.size(); ++i) difference |= a[i] ^ b[i];
  return difference == 0;
}
std::optional<GameplayLinkId> ParseLink(std::string_view hex) {
  if (hex.size() != 32) return std::nullopt;
  GameplayLinkId result{};
  auto digit = [](char c) -> int {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
  };
  uint8_t nonzero = 0;
  for (size_t i = 0; i < result.size(); ++i) {
    const int high = digit(hex[i * 2]), low = digit(hex[i * 2 + 1]);
    if (high < 0 || low < 0) return std::nullopt;
    result[i] = uint8_t((high << 4) | low); nonzero |= result[i];
  }
  if (!nonzero) return std::nullopt;
  return result;
}
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
  if (session->state == SessionState::kDeleted || (session->private_lan_invitation&&!session->private_lan_invitation->Current())) return false;
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

// GAMEPLAY_ROUTE_DIAG only: names the first condition that keeps a scope from
// being Current(), mirroring MemberCurrent()/Current(). Ids are shortened to
// prefixes; credentials and nonces are never logged.
std::string ShortId(std::string_view id) { return std::string(id.substr(0, 8)); }
uint64_t SessionIdValue(const std::array<uint8_t, 8>& id) {
  uint64_t value = 0;
  for (const auto byte : id) value = (value << 8) | byte;
  return value;
}
std::string NotCurrentReason(const Scope& scope) {
  const auto session = scope.session.lock();
  if (!session) return "no_session";
  if (scope.closed) return "closed";
  std::lock_guard lock(*session->mutex);
  if (session->state == SessionState::kDeleted) return "deleted";
  if (session->private_lan_invitation && !session->private_lan_invitation->Current())
    return "private_invitation_not_current";
  const auto member = std::find_if(session->members.begin(), session->members.end(),
      [&](const auto& value) { return value.xuid == scope.xuid && value.local; });
  if (member == session->members.end())
    return fmt::format("no_local_member members={}", session->members.size());
  if (scope.authorization.member_nonce.empty()) return "empty_member_nonce";
  if (scope.authorization.xbox_session != session->info.id)
    return fmt::format("xbox_session_mismatch auth={:016X} session={:016X}",
                       SessionIdValue(scope.authorization.xbox_session),
                       SessionIdValue(session->info.id));
  if (scope.authorization.host_xuid != session->host_xuid)
    return fmt::format("host_xuid_mismatch auth={:016X} session={:016X}",
                       scope.authorization.host_xuid, session->host_xuid);
  if (scope.xuid != session->host_xuid) {
    const auto& binding = member->gameplay_admission;
    if (!binding) return "missing_gameplay_admission";
    if (binding->directory_session_id != scope.authorization.directory_session)
      return fmt::format("directory_session_mismatch auth={} member={}",
                         ShortId(scope.authorization.directory_session),
                         ShortId(binding->directory_session_id));
    if (binding->attempt_id != scope.authorization.admission_attempt)
      return fmt::format("attempt_mismatch auth={} member={}",
                         ShortId(scope.authorization.admission_attempt),
                         ShortId(binding->attempt_id));
    if (binding->admission_generation != scope.authorization.admission_generation)
      return fmt::format("generation_mismatch auth={} member={}",
                         ShortId(scope.authorization.admission_generation),
                         ShortId(binding->admission_generation));
  }
  if (Clock::now() >= scope.authorization.expires_at) return "expired";
  return "current";
}
bool RouteDiagDue(std::unordered_map<uint64_t, Clock::time_point>& last, uint64_t key) {
  const auto now = Clock::now();
  auto& at = last[key];
  if (at != Clock::time_point{} && now - at < std::chrono::seconds(1)) return false;
  at = now;
  return true;
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
  // An open native socket must retain its fail-closed scope after the session
  // dies. CloseGameplaySocket releases the tombstone before descriptor reuse.
  std::erase_if(scopes, [](const auto& scope) {
    return scope.session.expired() && !scope.socket;
  });
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
    const bool installed = peer.authenticated_lan_endpoint
        ? NatProbeInstallAuthenticatedLanPeer(peer.traversal, *scope.socket, logical,
            *peer.authenticated_lan_endpoint, scope.authorization.expires_at)
        : NatProbeInstallGameplayIdentity(peer.traversal, *scope.socket, logical,
            scope.authorization.expires_at);
    if (!installed) return false;
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

namespace {
bool InstallGameplayAuthorizationImpl(const std::shared_ptr<SessionRecord>& session,
    const GameplayAuthorization& authorization,std::vector<SessionMember>* proposed_members,
    bool (*commit)(void*) noexcept,void* context,bool (*validate)(void*) noexcept) {
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
  std::set<std::pair<uint32_t, uint16_t>> private_endpoints;
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
    if (!ParseLink(peer.traversal.attempt_id)) return reject("invalid_crypto_link");
    if (SameTrafficKey(peer.traffic_key, {})) return reject("missing_peer_traffic_key");
    if (peer.authenticated_lan_endpoint) {
      const auto endpoint = *peer.authenticated_lan_endpoint;
      const auto ip = ntohl(endpoint.ipv4);
      const bool private_ip = (ip >> 24) == 127 || (ip >> 24) == 10 ||
                              (ip >> 20) == 0xac1 || (ip >> 16) == 0xc0a8;
      if (!endpoint.port || !private_ip ||
          !private_endpoints.emplace(endpoint.ipv4, endpoint.port).second)
        return reject("invalid_private_lan_endpoint");
    }
  }
  Scope candidate;
  candidate.session = session;
  candidate.xuid = authorization.xuid;
  candidate.authorization = authorization;
  std::lock_guard lock(gameplay_mutex);
  Reap();
  std::unique_lock<std::recursive_mutex> record_lock;
  struct RestoreRoster {
    SessionRecord* record=nullptr;std::vector<SessionMember>* previous=nullptr;bool committed=false;
    ~RestoreRoster(){if(record&&!committed)record->members.swap(*previous);}
  } restore;
  if(proposed_members) {
    if(!commit||authorization.peers.size()+1!=proposed_members->size())return reject("invalid_private_transaction");
    if(std::any_of(authorization.peers.begin(),authorization.peers.end(),[](const auto& peer){return !peer.authenticated_lan_endpoint;}))
      return reject("private_route_required");
    std::unordered_set<uint64_t> roster_ids;
    for(const auto& member:*proposed_members) {
      if(!member.xuid||!roster_ids.insert(member.xuid).second)return reject("duplicate_private_roster");
      if(member.xuid==authorization.xuid) {
        if(!member.local)return reject("private_local_member_missing");
      } else {
        const auto peer=std::find_if(authorization.peers.begin(),authorization.peers.end(),
            [&](const auto& item){return item.xuid==member.xuid;});
        if(peer==authorization.peers.end()||member.local||!member.gameplay_admission||
           member.gameplay_admission->directory_session_id!=authorization.directory_session||
           member.gameplay_admission->attempt_id!=peer->admission_attempt||
           member.gameplay_admission->admission_generation!=peer->admission_generation)
          return reject("private_peer_roster_mismatch");
      }
    }
    if(!roster_ids.contains(authorization.xuid))return reject("private_local_member_missing");
    record_lock=std::unique_lock<std::recursive_mutex>(*session->mutex);
    if(validate&&!validate(context))return reject("stale_private_record_snapshot");
    session->members.swap(*proposed_members);restore.record=session.get();restore.previous=proposed_members;
    for(const auto& peer:authorization.peers)if(!PeerCurrent(candidate,peer))return reject("private_peer_not_current");
    // Reserve before deriving an iterator; no allocation may follow commit.
    scopes.reserve(scopes.size()+1);
  }
  if (!MemberCurrent(candidate)) return reject("member_not_current");
  auto found = std::find_if(scopes.begin(), scopes.end(), [&](const auto& s) {
    return s.session.lock() == session && s.xuid == authorization.xuid;
  });
  // Prepare all crypto state before changing authority or native routes.
  if (found != scopes.end()) {
    if (found->closed) return reject("scope_closed");
    candidate.retired_links() = found->retired_links();
    // Keep learned guest source aliases across authorization refreshes; the
    // scope is replaced about once a second and the alias is otherwise only
    // re-learned on the guest's next send, so host bursts would surface from
    // the logical address and be discarded by the title.
    candidate.tables->guest_aliases = found->tables->guest_aliases;
    for (const auto& old : found->authorization.peers)
      if (!links.contains(old.traversal.attempt_id)) candidate.retired_links().insert(old.traversal.attempt_id);
  }
  if (candidate.retired_links().size() > 4096) return reject("retired_crypto_link_limit");
  for (const auto& peer : authorization.peers) {
    if (candidate.retired_links().contains(peer.traversal.attempt_id)) return reject("retired_crypto_link");
    const GameplayPeerAuthorization* previous = nullptr;
    if (found != scopes.end()) {
      for (const auto& old : found->authorization.peers)
        if (old.traversal.attempt_id == peer.traversal.attempt_id) previous = &old;
    }
    if (previous) {
      if (previous->xuid != peer.xuid || previous->member_nonce != peer.member_nonce ||
          previous->admission_attempt != peer.admission_attempt ||
          previous->admission_generation != peer.admission_generation ||
          previous->logical.ipv4 != peer.logical.ipv4 ||
          previous->traversal.participant != peer.traversal.participant ||
          previous->authenticated_lan_endpoint != peer.authenticated_lan_endpoint ||
          !SameTrafficKey(previous->traffic_key, peer.traffic_key)) return reject("crypto_link_changed");
      const auto state = found->ciphers().find(peer.traversal.attempt_id);
      if (state == found->ciphers().end()) return reject("missing_existing_crypto_state");
      candidate.ciphers().emplace(peer.traversal.attempt_id, state->second);
    } else {
      auto cipher = GameplayDatagramCipher::Create(peer.traffic_key, *ParseLink(peer.traversal.attempt_id),
                                                   peer.traversal.participant);
      if (!cipher) return reject("crypto_provider_unavailable");
      candidate.ciphers().emplace(peer.traversal.attempt_id, std::move(cipher));
    }
  }
  if(proposed_members) {
    if(found!=scopes.end()) {
      if(found->closed)return reject("scope_closed");
      const auto& old=found->authorization;
      if(!old.member_nonce.empty()&&(old.member_nonce!=authorization.member_nonce||
         old.directory_session!=authorization.directory_session||old.admission_attempt!=authorization.admission_attempt||
         old.admission_generation!=authorization.admission_generation))return reject("private_member_generation_changed");
      candidate.socket=found->socket;candidate.guest_port=found->guest_port;
    }
    SocketCandidate* selected=nullptr;
    if(!candidate.socket)for(auto& socket:socket_candidates) {
      if(socket.xuid!=candidate.xuid||socket.owned)continue;
      if(selected)return reject("ambiguous_private_socket");
      selected=&socket;
    }
    if(selected){candidate.socket=selected->socket;candidate.guest_port=selected->port;}
    std::vector<NatProbeAuthenticatedLanPeer> routes;routes.reserve(authorization.peers.size());
    for(const auto& peer:authorization.peers){auto logical=peer.logical;logical.port=candidate.guest_port;
      routes.push_back({peer.traversal,logical,*peer.authenticated_lan_endpoint});}
    struct Publication {
      Scope* candidate;std::vector<Scope>::iterator found;bool existing;SocketCandidate* selected;
      RestoreRoster* restore;bool (*commit)(void*) noexcept;void* context;
    } publication{&candidate,found,found!=scopes.end(),selected,&restore,commit,context};
    auto publish=[](void* context) noexcept {
      auto& state=*static_cast<Publication*>(context);
      if(!state.commit(state.context))return false;
      if(state.existing)*state.found=std::move(*state.candidate);
      else scopes.push_back(std::move(*state.candidate)); // Capacity was reserved.
      if(state.selected)state.selected->owned=true;
      state.restore->committed=true;return true;
    };
    if(candidate.socket)return NatProbeCommitAuthenticatedLanPeers(*candidate.socket,routes,
        authorization.expires_at,publish,&publication);
    return publish(&publication);
  }
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
        if (!links.contains(old.traversal.attempt_id)) {
          candidate.retired_links().insert(old.traversal.attempt_id);
          NatProbeRemoveGameplayIdentity(*found->socket, old.traversal.attempt_id);
        }
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

} // namespace
bool InstallGameplayAuthorization(const std::shared_ptr<SessionRecord>& session,
    const GameplayAuthorization& authorization) {
  return InstallGameplayAuthorizationImpl(session,authorization,nullptr,nullptr,nullptr,nullptr);
}
bool CommitPrivateLanGameplayAuthorization(const std::shared_ptr<SessionRecord>& session,
    const GameplayAuthorization& authorization,std::vector<SessionMember> members,
    bool (*commit)(void*) noexcept,void* context,bool (*validate)(void*) noexcept) noexcept {
  try{return InstallGameplayAuthorizationImpl(session,authorization,&members,commit,context,validate);}
  catch(...){return false;}
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
      scope.ciphers().clear();
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
      scope.ciphers().clear();
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
  if(!REXCVAR_GET(private_lan_invitation_file).empty())return true;
  std::lock_guard lock(gameplay_mutex);
  Reap();
  if(!REXCVAR_GET(private_lan_allow_legacy_diagnostics)&&NatProbeIsGameplaySocket(socket))return true;
  // Keep failed/expired scopes fail-closed rather than falling back to raw UDP.
  return std::any_of(scopes.begin(), scopes.end(), [&](const auto& s) {
    if (s.socket != socket) return false;
    auto session = s.session.lock();
    return s.closed || !session || !s.authorization.member_nonce.empty() ||
           s.xuid != session->host_xuid;
  });
}

namespace {
// Advertised host endpoints recorded at the public-route rewrite, keyed by the
// exact Xbox session and host. Guarded by gameplay_mutex; bounded.
std::map<std::pair<std::array<uint8_t, 8>, uint64_t>, LanAddress> advertised_hosts;
constexpr size_t kMaximumAdvertisedHosts = 64;
}  // namespace

void RecordAdvertisedHostAddress(const std::array<uint8_t, 8>& xbox_session, uint64_t host_xuid,
                                 LanAddress advertised) {
  if (!host_xuid || !advertised.ipv4) return;
  std::lock_guard lock(gameplay_mutex);
  if (advertised_hosts.size() >= kMaximumAdvertisedHosts &&
      !advertised_hosts.contains({xbox_session, host_xuid}))
    advertised_hosts.clear();
  advertised_hosts.insert_or_assign({xbox_session, host_xuid}, advertised);
}

std::optional<LanAddress> GameplayLogicalDestination(uint64_t socket, LanAddress requested) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  for (auto& scope : scopes) {
    if (scope.socket != socket) continue;
    auto session = scope.session.lock();
    if (!session) return std::nullopt;
    LanAddress original_host;
    std::optional<LanAddress> advertised_host;
    {
      std::lock_guard session_lock(*session->mutex);
      original_host = session->info.host_address;
      const auto found = advertised_hosts.find({session->info.id, session->host_xuid});
      if (found != advertised_hosts.end()) advertised_host = found->second;
    }
    // The advertised endpoint names only this joiner's host, at its exact
    // advertised address and either its advertised port or the guest port.
    const bool advertised_match = advertised_host && scope.xuid != session->host_xuid &&
        requested.ipv4 == advertised_host->ipv4 &&
        (requested.port == advertised_host->port || requested.port == scope.guest_port);
    if (!Current(scope)) {
      static std::unordered_map<uint64_t, Clock::time_point> last_logged;  // gameplay_mutex
      if (RouteDiagDue(last_logged, socket))
        REXSYS_INFO("GAMEPLAY_ROUTE_DIAG scope_not_current socket={} xuid={:016X} reason={} "
                    "requested={:08X}:{} host_original={:08X}:{}",
                    socket, scope.xuid, NotCurrentReason(scope), ntohl(requested.ipv4),
                    requested.port, ntohl(original_host.ipv4), original_host.port);
      // A pending or expired admitted client must not send its initial host
      // handshake through an unauthenticated endpoint fallback.
      if (scope.xuid != session->host_xuid && requested.ipv4 == original_host.ipv4)
        return requested;
      if (advertised_match) return LanAddress{advertised_host->ipv4, requested.port};
      continue;
    }
    for (const auto& peer : scope.authorization.peers) {
      if (!PeerCurrent(scope, peer)) continue;
      const bool exact_alias = requested.ipv4 == peer.logical.ipv4;
      // The accepted-invite record was serialized before gameplay authorization.
      // Its exact host endpoint remains a valid initial destination for this
      // client only; it is never a fallback for another member or session.
      const bool initial_host = scope.xuid != scope.authorization.host_xuid &&
          peer.xuid == scope.authorization.host_xuid &&
          ((requested.ipv4 == original_host.ipv4 &&
            (requested.port == scope.guest_port || requested.port == original_host.port)) ||
           (advertised_match && session->host_xuid == scope.authorization.host_xuid));
      if (exact_alias) scope.tables->guest_aliases.erase(peer.logical.ipv4);
      else if (initial_host) scope.tables->guest_aliases[peer.logical.ipv4] = requested.ipv4;
      if (exact_alias || initial_host) return LanAddress{peer.logical.ipv4, scope.guest_port};
    }
  }
  return std::nullopt;
}

std::optional<uint32_t> GameplayGuestSourceAlias(uint64_t socket, LanAddress logical) {
  std::lock_guard lock(gameplay_mutex);
  for (const auto& scope : scopes) {
    if (scope.socket != socket || !Current(scope)) continue;
    const auto found = scope.tables->guest_aliases.find(logical.ipv4);
    if (found != scope.tables->guest_aliases.end()) return found->second;
  }
  return std::nullopt;
}

std::optional<std::vector<uint8_t>> SealGameplayDatagram(
    uint64_t socket, LanAddress logical, std::span<const uint8_t> plaintext) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  for (auto& scope : scopes) {
    if (scope.socket != socket || !Current(scope)) continue;
    for (const auto& peer : scope.authorization.peers) {
      if (peer.logical.ipv4 != logical.ipv4 || logical.port != scope.guest_port || !PeerCurrent(scope, peer)) continue;
      const auto found = scope.ciphers().find(peer.traversal.attempt_id);
      if (found != scope.ciphers().end()) return found->second->Seal(plaintext);
    }
  }
  return std::nullopt;
}
bool OpenGameplayDatagram(uint64_t socket, LanAddress logical,
    std::span<const uint8_t> packet, std::vector<uint8_t>& plaintext, bool consume) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  for (auto& scope : scopes) {
    if (scope.socket != socket || !Current(scope)) continue;
    for (const auto& peer : scope.authorization.peers) {
      if (peer.logical.ipv4 != logical.ipv4 || logical.port != scope.guest_port || !PeerCurrent(scope, peer)) continue;
      const auto found = scope.ciphers().find(peer.traversal.attempt_id);
      if (found != scope.ciphers().end()) return found->second->Open(packet, plaintext, consume);
    }
  }
  return false;
}

std::string_view GameplayOpenFailureReason(uint64_t socket, LanAddress logical) {
  std::lock_guard lock(gameplay_mutex);
  Reap();
  bool scope_found = false, peer_found = false;
  for (auto& scope : scopes) {
    if (scope.socket != socket) continue;
    if (!Current(scope)) continue;
    scope_found = true;
    for (const auto& peer : scope.authorization.peers) {
      if (peer.logical.ipv4 != logical.ipv4) continue;
      if (logical.port != scope.guest_port) return "guest_port_mismatch";
      if (!PeerCurrent(scope, peer)) return "peer_not_current";
      peer_found = true;
      if (!scope.ciphers().contains(peer.traversal.attempt_id)) return "no_cipher";
    }
  }
  if (!scope_found) return "no_current_scope";
  return peer_found ? "authentication_or_replay" : "unknown_peer";
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
std::string DescribeGameplayLogical(uint32_t ipv4) {
  std::lock_guard lock(gameplay_mutex);
  size_t total = 0, current = 0, matched = 0, matched_current = 0;
  for (const auto& scope : scopes) {
    ++total;
    const bool scope_current = Current(scope);
    if (scope_current) ++current;
    for (const auto& peer : scope.authorization.peers)
      if (peer.logical.ipv4 == ipv4) {
        ++matched;
        if (scope_current && PeerCurrent(scope, peer)) ++matched_current;
      }
  }
  return fmt::format("scopes={} current={} peers_with_address={} usable={}", total, current, matched,
                     matched_current);
}
}  // namespace rex::system::xam
