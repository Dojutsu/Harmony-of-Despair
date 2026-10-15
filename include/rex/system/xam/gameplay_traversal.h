#pragma once

#include <array>
#include <chrono>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <rex/system/xam/nat_probe.h>
#include <rex/system/xam/gameplay_datagram.h>

namespace rex::system::xam {

struct GameplayPeerAuthorization {
  uint64_t xuid = 0;
  std::string member_nonce;
  std::string admission_attempt;
  std::string admission_generation;
  LanAddress logical;
  NatProbeIdentity traversal;
  GameplayTrafficKey traffic_key{};
  // Present only after an authenticated private LAN ticket supplies the exact
  // physical route. It never creates membership or a public fallback.
  std::optional<LanAddress> authenticated_lan_endpoint;
};

struct GameplayAuthorization {
  std::string directory_session;
  std::array<uint8_t, 8> xbox_session{};
  uint64_t host_xuid = 0;
  uint64_t xuid = 0;
  std::string admission_attempt;
  std::string admission_generation;
  std::string member_nonce;
  std::string member_capability;
  LanAddress logical;
  std::chrono::steady_clock::time_point expires_at{};
  std::vector<GameplayPeerAuthorization> peers;
};

// Local platform authority: a live exact session/member record plus a ticket
// obtained from the existing host-authorized HTTPS admission path. No entry
// point creates membership or treats an IPv4 address as member identity.
void RegisterGameplaySocketCandidate(uint64_t local_xuid, uint64_t socket, uint16_t guest_port);
bool TrackGameplayAdmission(const std::shared_ptr<SessionRecord>& session, uint64_t xuid);
bool InstallGameplayAuthorization(const std::shared_ptr<SessionRecord>& session,
                                   const GameplayAuthorization& authorization);
// Trusted private LAN transaction. Stages the complete roster, protected scope
// and direct routes under gameplay -> record -> route lock order. The final
// bounded callback may commit staged authority/arbitration state only; it must
// not enter gameplay, routes, network operations or throw. Provider/allocation,
// invalid route, stale authority and callback failures publish no state.
bool CommitPrivateLanGameplayAuthorization(const std::shared_ptr<SessionRecord>& session,
    const GameplayAuthorization& authorization,std::vector<SessionMember> members,
    bool (*commit)(void*) noexcept,void* context,
    bool (*validate)(void*) noexcept=nullptr) noexcept;
bool BindGameplaySocket(const std::shared_ptr<SessionRecord>& session, uint64_t local_xuid,
                        uint64_t socket, uint16_t guest_port);
void CloseGameplaySocket(uint64_t socket);
void RevokeGameplayAuthorization(const std::shared_ptr<SessionRecord>& session,
                                  uint64_t local_xuid);
bool GameplayAuthorizationCurrent(const std::shared_ptr<SessionRecord>& session,
                                   uint64_t local_xuid, std::string_view member_nonce);
bool IsAuthorizedGameplaySocket(uint64_t socket);
// A public (cellular/relay) route replaces SessionInfo::host_address with the
// host's public endpoint, but the title keeps addressing the host by the
// endpoint it was advertised (listing / XNADDR). Recorded once, at that rewrite,
// for exactly this session and host; it only ever names this joiner's host peer.
void RecordAdvertisedHostAddress(const std::array<uint8_t, 8>& xbox_session, uint64_t host_xuid,
                                 LanAddress advertised);
// Returns an exact peer alias; an unknown/expired scoped destination has no route.
std::optional<LanAddress> GameplayLogicalDestination(uint64_t socket, LanAddress requested);
// The address the guest last used to reach this logical peer, when it differs.
std::optional<uint32_t> GameplayGuestSourceAlias(uint64_t socket, LanAddress logical);

// Protected transport admits an exact live peer under the same authority lock.
// There is no raw scoped fallback. Cipher state survives ordinary ticket renewal.
std::optional<std::vector<uint8_t>> SealGameplayDatagram(
    uint64_t socket, LanAddress logical, std::span<const uint8_t> plaintext);
bool OpenGameplayDatagram(uint64_t socket, LanAddress logical,
    std::span<const uint8_t> packet, std::vector<uint8_t>& plaintext, bool consume);
// Why OpenGameplayDatagram refused a datagram from this logical peer (diagnostics).
std::string_view GameplayOpenFailureReason(uint64_t socket, LanAddress logical);

struct GameplayXnAddr {
  std::array<uint8_t, 8> session_id{};
  uint64_t xuid = 0;
  LanAddress logical;
  uint64_t host_xuid = 0;  // The session host's xuid (equal to xuid for the host).
};
std::optional<GameplayXnAddr> GameplayXnAddrToLogical(
    const std::array<uint8_t, 8>& session_id, const XnAddrIdentity& identity);
std::optional<GameplayXnAddr> GameplayLogicalToXnAddr(uint32_t ipv4);
// One-line summary of why a logical address does or does not resolve, for logs.
std::string DescribeGameplayLogical(uint32_t ipv4);
bool IsGameplayLogicalAddress(uint32_t ipv4);

}  // namespace rex::system::xam
