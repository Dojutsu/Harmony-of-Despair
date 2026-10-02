#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <deque>
#include <future>
#include <limits>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include <nlohmann/json.hpp>

#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

#include <rex/system/xam/session.h>
#include <rex/system/xam/nat_probe.h>

namespace rex::system::xam {
namespace {
using Clock = ClientAdmissionLeaseState::Clock;

constexpr std::string_view kAttempt = "00112233445566778899aabbccddeeff";
constexpr std::string_view kCapability = "ffeeddccbbaa99887766554433221100";
constexpr std::string_view kGeneration = "0123456789abcdef0123456789abcdef";
constexpr uint32_t kUser = 0;
constexpr uint32_t kTitle = 0x58410A7A;
constexpr uint64_t kToken = 41;
constexpr uint64_t kLocalXuid = 0xB13E000000000001ull;

#pragma pack(push, 1)
struct ClientNatPacket {
  char magic[4];
  uint8_t version;
  uint8_t type;
  uint8_t participant;
  uint8_t role;
  uint8_t attempt[16];
  uint8_t credential[16];
  uint32_t observed_ipv4;
  uint16_t observed_port;
  uint32_t peer_ipv4;
  uint16_t peer_port;
  uint32_t reserved;
};

struct ClientWireMember {
  uint64_t xuid;
  uint32_t flags;
  char name[16];
};

struct ClientDiscoveryPacket {
  uint32_t magic;
  uint16_t version;
  uint8_t type;
  uint8_t reserved;
  uint32_t title_id;
  uint8_t session_id[8];
  uint8_t session_key[16];
  uint64_t host_xuid;
  uint32_t host_ipv4;
  uint16_t host_port;
  uint16_t reserved2;
  uint32_t flags;
  uint32_t public_slots;
  uint32_t private_slots;
  uint32_t member_count;
  char host_name[16];
  ClientWireMember members[8];
};
struct ClientInviteLanPacket {
  char magic[4];
  uint8_t version;
  uint8_t type;
  uint16_t reserved;
  uint8_t selector[16];
  uint8_t proof[16];
};
#pragma pack(pop)
static_assert(sizeof(ClientNatPacket) == 56);
static_assert(sizeof(ClientInviteLanPacket) == 40);

uint64_t ClientSwap64(uint64_t value) {
  const uint32_t high = htonl(static_cast<uint32_t>(value >> 32));
  const uint32_t low = htonl(static_cast<uint32_t>(value));
  return (uint64_t(low) << 32) | high;
}

ClientDiscoveryPacket ClientAdvertisement(const SessionRecord& session) {
  std::lock_guard lock(*session.mutex);
  ClientDiscoveryPacket packet{};
  packet.magic = htonl(0x5245584Cu);
  packet.version = htons(1);
  packet.type = 2;
  packet.title_id = htonl(kTitle);
  std::memcpy(packet.session_id, session.info.id.data(), sizeof(packet.session_id));
  std::memcpy(packet.session_key, session.info.key.data(), sizeof(packet.session_key));
  packet.host_xuid = ClientSwap64(session.host_xuid);
  packet.host_ipv4 = session.info.host_address.ipv4;
  packet.host_port = htons(session.info.host_address.port);
  packet.flags = htonl(session.flags);
  packet.public_slots = htonl(session.max_public_slots);
  packet.private_slots = htonl(session.max_private_slots);
  const auto host_name_size =
      std::min(session.host_name.size(), sizeof(packet.host_name) - 1);
  std::memcpy(packet.host_name, session.host_name.data(), host_name_size);
  return packet;
}

uint8_t ClientHexDigit(char value) {
  return uint8_t(value <= '9' ? value - '0' : value - 'a' + 10);
}

void ClientParseHex(std::string_view value, uint8_t* output) {
  for (size_t i = 0; i < 16; ++i)
    output[i] = uint8_t((ClientHexDigit(value[i * 2]) << 4) |
                        ClientHexDigit(value[i * 2 + 1]));
}

ClientNatPacket ClientRegistered(std::string_view attempt, std::string_view capability,
                                 LanAddress peer) {
  ClientNatPacket packet{};
  std::memcpy(packet.magic, "HNAT", 4);
  packet.version = 1;
  packet.type = 2;
  packet.participant = 1;
  packet.role = uint8_t(NatProbeRole::kDiscovery);
  ClientParseHex(attempt, packet.attempt);
  ClientParseHex(capability, packet.credential);
  packet.observed_ipv4 = htonl(0xCB007109u);
  packet.observed_port = htons(35000);
  packet.peer_ipv4 = peer.ipv4;
  packet.peer_port = htons(peer.port);
  return packet;
}

ClientNatPacket ClientAck(std::string_view attempt) {
  ClientNatPacket packet{};
  std::memcpy(packet.magic, "HNAT", 4);
  packet.version = 1;
  packet.type = 4;
  packet.participant = 0;
  packet.role = uint8_t(NatProbeRole::kDiscovery);
  ClientParseHex(attempt, packet.attempt);
  return packet;
}

struct ClientNatFixture {
  std::vector<std::string> attempts;
  std::vector<uint64_t> sockets;
  ~ClientNatFixture() {
    for (auto socket : sockets)
      NatProbeDetach(socket);
    for (const auto& attempt : attempts)
      NatProbeRetireIdentity(attempt);
  }
  void Bind(uint64_t socket, const DirectoryTraversalAttempt& attempt, LanAddress peer) {
    attempts.push_back(attempt.attempt_id);
    sockets.push_back(socket);
    REQUIRE(NatProbeInstallIdentity({attempt.attempt_id, attempt.capability,
                                     attempt.rendezvous_host, attempt.rendezvous_port, 1}));
    NatProbeAttach(socket, NatProbeRole::kDiscovery,
                   {htonl(0x7F000001u), uint16_t(socket)});
    auto registered = ClientRegistered(attempt.attempt_id, attempt.capability, peer);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                            sizeof(registered), htonl(0x7F000001u), 30740));
    auto ack = ClientAck(attempt.attempt_id);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack), sizeof(ack),
                            peer.ipv4, peer.port));
  }
};

TEST_CASE("configured invite route selection resists late competing candidates",
          "[session][configured-invite][lan][race]") {
  const LanAddress local{htonl(0x0A0000D9u), 53854};
  const LanAddress public_peer{htonl(0xCB00712Au), 30741};
  const LanAddress lan_peer{htonl(0x0A0000D5u), 30741};
  auto run = [&](uint64_t socket, bool lan_first) {
    NatProbeAttach(socket, NatProbeRole::kDiscovery, local);
    REQUIRE(NatProbeInstallIdentityForSocket(
        {std::string(kAttempt), std::string(kCapability), "127.0.0.1", 30740,
         1, true}, socket));
    auto registered = ClientRegistered(kAttempt, kCapability, public_peer);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                            sizeof(registered), htonl(INADDR_LOOPBACK), 30740));
    if (lan_first) {
      REQUIRE(NatProbeRegisterInviteLanPeer(socket, kAttempt, lan_peer));
      REQUIRE(NatProbeSelectInviteDiscoveryPeer(socket, kAttempt, lan_peer));
    }
    auto ack = ClientAck(kAttempt);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack),
                            sizeof(ack), public_peer.ipv4, public_peer.port));
    if (!lan_first) {
      REQUIRE(NatProbeSelectInviteDiscoveryPeer(socket, kAttempt, public_peer));
      REQUIRE(NatProbeRegisterInviteLanPeer(socket, kAttempt, lan_peer));
    }
    const auto winner = lan_first ? lan_peer : public_peer;
    const auto loser = lan_first ? public_peer : lan_peer;
    CHECK(NatProbePeer(socket) == winner);
    CHECK_FALSE(NatProbeSelectInviteDiscoveryPeer(socket, kAttempt, loser));
    CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, loser).empty());
    CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, winner) ==
          std::vector<std::string>{std::string(kAttempt)});
    NatProbeRetireIdentity(kAttempt);
    NatProbeDetach(socket);
  };
  SECTION("LAN wins before public ACK") { run(0xF2311, true); }
  SECTION("public wins before LAN reply") { run(0xF2312, false); }
}

TEST_CASE("simultaneous LAN and public candidates select exactly one route",
          "[session][configured-invite][lan][race]") {
  constexpr uint64_t socket = 0xF2313;
  const LanAddress local{htonl(0x0A0000D9u), 53854};
  const LanAddress public_peer{htonl(0xCB00712Au), 30741};
  const LanAddress lan_peer{htonl(0x0A0000D5u), 30741};
  NatProbeAttach(socket, NatProbeRole::kDiscovery, local);
  REQUIRE(NatProbeInstallIdentityForSocket(
      {std::string(kAttempt), std::string(kCapability), "127.0.0.1", 30740,
       1, true}, socket));
  auto registered = ClientRegistered(kAttempt, kCapability, public_peer);
  REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                          sizeof(registered), htonl(INADDR_LOOPBACK), 30740));
  auto ack = ClientAck(kAttempt);
  REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack),
                          sizeof(ack), public_peer.ipv4, public_peer.port));
  REQUIRE(NatProbeRegisterInviteLanPeer(socket, kAttempt, lan_peer));
  std::atomic<bool> start = false;
  auto select = [&](LanAddress peer) {
    while (!start.load(std::memory_order_acquire))
      std::this_thread::yield();
    return NatProbeSelectInviteDiscoveryPeer(socket, kAttempt, peer);
  };
  auto public_result = std::async(std::launch::async, select, public_peer);
  auto lan_result = std::async(std::launch::async, select, lan_peer);
  start.store(true, std::memory_order_release);
  const bool public_won = public_result.get();
  const bool lan_won = lan_result.get();
  CHECK(public_won != lan_won);
  CHECK(NatProbePeer(socket) == (public_won ? public_peer : lan_peer));
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(
            socket, public_won ? lan_peer : public_peer).empty());
  NatProbeRetireIdentity(kAttempt);
  NatProbeDetach(socket);
}

struct StageBarrier {
  std::mutex mutex;
  std::condition_variable cv;
  bool entered = false;
  bool released = false;

  void ArriveAndWait() {
    std::unique_lock lock(mutex);
    entered = true;
    cv.notify_all();
    cv.wait(lock, [&] { return released; });
  }

  bool WaitUntilEntered() {
    std::unique_lock lock(mutex);
    return cv.wait_for(lock, std::chrono::seconds(2), [&] { return entered; });
  }

  void Release() {
    std::lock_guard lock(mutex);
    released = true;
    cv.notify_all();
  }
};

struct ConfiguredInviteCvarFixture {
  std::string url = REXCVAR_GET(session_directory_url);
  std::string code = REXCVAR_GET(session_directory_invite_code);
  std::string candidate_type = REXCVAR_GET(session_directory_candidate_type);
  uint32_t index = REXCVAR_GET(session_directory_session_index);
  std::string direct = REXCVAR_GET(direct_connect_address);
  std::string bind = REXCVAR_GET(lan_bind_address);

  explicit ConfiguredInviteCvarFixture(std::string_view configured_code = "ABC234") {
    REXCVAR_SET(session_directory_url, "");
    REXCVAR_SET(session_directory_invite_code, std::string(configured_code));
    REXCVAR_SET(session_directory_candidate_type, "public");
    REXCVAR_SET(session_directory_session_index, 0xFFFFFFFFu);
    REXCVAR_SET(direct_connect_address, "");
    REXCVAR_SET(lan_bind_address, "127.0.0.1");
  }
  ~ConfiguredInviteCvarFixture() {
    REXCVAR_SET(lan_bind_address, bind);
    REXCVAR_SET(direct_connect_address, direct);
    REXCVAR_SET(session_directory_session_index, index);
    REXCVAR_SET(session_directory_candidate_type, candidate_type);
    REXCVAR_SET(session_directory_invite_code, code);
    REXCVAR_SET(session_directory_url, url);
  }
};

DirectoryInviteJoinAttempt ConfiguredAttempt(uint16_t rendezvous_port = 39071,
                                             uint16_t discovery_port = 39072) {
  DirectoryTraversalAttempt attempt{
      "session-a", std::string(kAttempt), std::string(kCapability),
      "127.0.0.1", rendezvous_port, 1, "invite_code_private_eligible",
      {}, 0, 0, false};
  DirectorySession session;
  session.session_id = attempt.session_id;
  session.server_name = "Host";
  session.player_count = 1;
  session.max_players = 6;
  session.title_id = kTitle;
  session.protocol_version = 1;
  session.build_id = "test";
  session.connectivity_candidates.push_back(
      {"public", "127.0.0.1", discovery_port, 30742});
  return {std::move(session), std::move(attempt)};
}

SessionRecord CorrelatedSession(const DirectoryInviteJoinAttempt& issued,
                                LanAddress discovery_address) {
  SessionRecord session;
  session.info.id = {1, 2, 3, 4, 5, 6, 7, 8};
  session.info.key = {0, 1, 2, 3, 4, 5, 6, 7,
                      8, 9, 10, 11, 12, 13, 14, 15};
  session.host_xuid = 0xB13E000000000099ull;
  session.host_name = "ConfiguredHost";
  session.info.host_address = {htonl(INADDR_LOOPBACK), 30742};
  const auto identity = ReconstructXnAddrIdentity(session.host_xuid);
  session.info.ethernet_address = identity.ethernet_address;
  session.info.online_address = identity.online_address;
  session.discovery_address = discovery_address;
  session.traversal_session_id = issued.attempt.session_id;
  session.traversal_attempt_id = issued.attempt.attempt_id;
  session.traversal_capability = issued.attempt.capability;
  session.nonce = 0x1122334455667788ull;
  session.max_public_slots = 4;
  session.max_private_slots = 2;
  session.members.push_back(
      {session.host_xuid, session.host_name, 0, true, false, false});
  return session;
}

enum class InviteLanTamper : uint8_t {
  kNone, kTitle, kSessionId, kKey, kHostXuid, kHostIpv4, kHostPort
};

struct ConfiguredInviteNetworkFixture {
#if REX_PLATFORM_WIN32
  using Socket = SOCKET;
  static constexpr Socket kInvalidSocket = INVALID_SOCKET;
#else
  using Socket = int;
  static constexpr Socket kInvalidSocket = -1;
#endif

  uint16_t rendezvous_port;
  uint16_t peer_port;
  bool respond_to_discovery;
  bool public_ack;
  bool lan_response;
  InviteLanTamper tamper_advertisement = InviteLanTamper::kNone;
  bool spoof_first = false;
  Socket rendezvous_socket = kInvalidSocket;
  Socket peer_socket = kInvalidSocket;
  ClientDiscoveryPacket advertisement{};
  std::jthread worker;
  std::atomic<uint32_t> registrations = 0;
  std::atomic<uint32_t> discovery_queries = 0;

  ConfiguredInviteNetworkFixture(uint16_t rendezvous, uint16_t peer,
                                 const SessionRecord& advertised,
                                 bool respond = true, bool ack_public = true,
                                 bool respond_lan = false,
                                 InviteLanTamper tamper = InviteLanTamper::kNone,
                                 bool spoof = false)
      : rendezvous_port(rendezvous),
        peer_port(peer),
        respond_to_discovery(respond),
        public_ack(ack_public),
        lan_response(respond_lan),
        tamper_advertisement(tamper),
        spoof_first(spoof),
        advertisement(ClientAdvertisement(advertised)) {
#if REX_PLATFORM_WIN32
    WSADATA data{};
    REQUIRE(WSAStartup(MAKEWORD(2, 2), &data) == 0);
#endif
    rendezvous_socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    peer_socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    REQUIRE(rendezvous_socket != kInvalidSocket);
    REQUIRE(peer_socket != kInvalidSocket);
    REQUIRE(BindLoopback(rendezvous_socket, rendezvous_port));
    REQUIRE(BindLoopback(peer_socket, peer_port));
    worker = std::jthread([this](std::stop_token stop) { Run(stop); });
  }

  ~ConfiguredInviteNetworkFixture() {
    worker.request_stop();
    if (worker.joinable())
      worker.join();
    Close(rendezvous_socket);
    Close(peer_socket);
#if REX_PLATFORM_WIN32
    WSACleanup();
#endif
  }

 private:
  static bool BindLoopback(Socket socket, uint16_t port) {
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address.sin_port = htons(port);
    return bind(socket, reinterpret_cast<const sockaddr*>(&address), sizeof(address)) == 0;
  }

  static void Close(Socket socket) {
    if (socket == kInvalidSocket)
      return;
#if REX_PLATFORM_WIN32
    closesocket(socket);
#else
    close(socket);
#endif
  }

  void Run(std::stop_token stop) {
    while (!stop.stop_requested()) {
      fd_set readers;
      FD_ZERO(&readers);
      FD_SET(rendezvous_socket, &readers);
      FD_SET(peer_socket, &readers);
      timeval timeout{0, 10000};
#if REX_PLATFORM_WIN32
      const int ready = select(0, &readers, nullptr, nullptr, &timeout);
#else
      const int ready = select(std::max(rendezvous_socket, peer_socket) + 1,
                               &readers, nullptr, nullptr, &timeout);
#endif
      if (ready <= 0)
        continue;
      if (FD_ISSET(rendezvous_socket, &readers)) {
        ClientNatPacket request{};
        sockaddr_in source{};
#if REX_PLATFORM_WIN32
        int source_length = sizeof(source);
#else
        socklen_t source_length = sizeof(source);
#endif
        const int count = recvfrom(
            rendezvous_socket, reinterpret_cast<char*>(&request), sizeof(request),
            0, reinterpret_cast<sockaddr*>(&source), &source_length);
        if (count == sizeof(request) &&
            std::memcmp(request.magic, "HNAT", 4) == 0 && request.type == 1) {
          auto registered = request;
          registered.type = 2;
          registered.observed_ipv4 = source.sin_addr.s_addr;
          registered.observed_port = source.sin_port;
          registered.peer_ipv4 = public_ack ? htonl(INADDR_LOOPBACK) : 0;
          registered.peer_port = public_ack ? htons(peer_port) : 0;
          sendto(rendezvous_socket, reinterpret_cast<const char*>(&registered),
                 sizeof(registered), 0,
                 reinterpret_cast<const sockaddr*>(&source), sizeof(source));
          if (public_ack) {
            auto ack = request;
            ack.type = 4;
            ack.participant = 0;
            std::memset(ack.credential, 0, sizeof(ack.credential));
            sendto(peer_socket, reinterpret_cast<const char*>(&ack), sizeof(ack), 0,
                   reinterpret_cast<const sockaddr*>(&source), sizeof(source));
          }
          ++registrations;
        }
      }
      if (FD_ISSET(peer_socket, &readers)) {
        std::array<uint8_t, 2048> packet{};
        sockaddr_in source{};
#if REX_PLATFORM_WIN32
        int source_length = sizeof(source);
#else
        socklen_t source_length = sizeof(source);
#endif
        const int count = recvfrom(peer_socket,
                                   reinterpret_cast<char*>(packet.data()),
                                   int(packet.size()), 0,
                                   reinterpret_cast<sockaddr*>(&source),
                                   &source_length);
        if (count <= 0)
          continue;
        if (count == sizeof(ClientInviteLanPacket)) {
          ClientInviteLanPacket probe{};
          std::memcpy(&probe, packet.data(), sizeof(probe));
          if (std::memcmp(probe.magic, "HILN", 4) == 0 && probe.version == 1 &&
              probe.type == 1) {
            std::array<uint8_t, 6> source_bytes{};
            std::memcpy(source_bytes.data(), &source.sin_addr.s_addr, 4);
            std::memcpy(source_bytes.data() + 4, &source.sin_port, 2);
            const auto selector = InviteLanAuthenticationTag(kAttempt,
                                                               "invite-lan-selector-v1");
            const auto request_proof = InviteLanAuthenticationTag(
                kAttempt, "invite-lan-request-v1", source_bytes);
            if (lan_response && selector && request_proof &&
                std::memcmp(probe.selector, selector->data(), 16) == 0 &&
                std::memcmp(probe.proof, request_proof->data(), 16) == 0) {
              std::array<uint8_t, 42> tuple{};
              size_t offset = 0;
              auto append = [&](const void* data, size_t size) {
                std::memcpy(tuple.data() + offset, data, size);
                offset += size;
              };
              append(&advertisement.title_id, 4);
              append(advertisement.session_id, 8);
              append(advertisement.session_key, 16);
              append(&advertisement.host_xuid, 8);
              append(&advertisement.host_ipv4, 4);
              append(&advertisement.host_port, 2);
              const auto proof = InviteLanAuthenticationTag(
                  kAttempt, "invite-lan-response-v1", tuple);
              if (proof) {
                ClientInviteLanPacket reply{};
                std::memcpy(reply.magic, "HILN", 4);
                reply.version = 1;
                reply.type = 2;
                std::memcpy(reply.selector, selector->data(), 16);
                std::memcpy(reply.proof, proof->data(), 16);
                if (spoof_first) {
                  auto spoof = reply;
                  spoof.proof[0] ^= 1;
                  sendto(peer_socket, reinterpret_cast<const char*>(&spoof),
                         sizeof(spoof), 0,
                         reinterpret_cast<const sockaddr*>(&source), sizeof(source));
                }
                sendto(peer_socket, reinterpret_cast<const char*>(&reply),
                       sizeof(reply), 0,
                       reinterpret_cast<const sockaddr*>(&source), sizeof(source));
              }
            }
            continue;
          }
        }
        if (count == sizeof(ClientNatPacket)) {
          ClientNatPacket control{};
          std::memcpy(&control, packet.data(), sizeof(control));
          if (std::memcmp(control.magic, "HNAT", 4) == 0 && control.type == 3) {
            auto ack = ClientAck(kAttempt);
            sendto(peer_socket, reinterpret_cast<const char*>(&ack), sizeof(ack), 0,
                   reinterpret_cast<const sockaddr*>(&source), sizeof(source));
            continue;
          }
        }
        ++discovery_queries;
        if (respond_to_discovery) {
          auto response = advertisement;
          switch (tamper_advertisement) {
            case InviteLanTamper::kNone: break;
            case InviteLanTamper::kTitle: response.title_id ^= 1; break;
            case InviteLanTamper::kSessionId: response.session_id[0] ^= 1; break;
            case InviteLanTamper::kKey: response.session_key[0] ^= 1; break;
            case InviteLanTamper::kHostXuid: response.host_xuid ^= 1; break;
            case InviteLanTamper::kHostIpv4: response.host_ipv4 ^= 1; break;
            case InviteLanTamper::kHostPort: response.host_port ^= 1; break;
          }
          sendto(peer_socket, reinterpret_cast<const char*>(&response),
                 sizeof(response), 0,
                 reinterpret_cast<const sockaddr*>(&source), sizeof(source));
        }
      }
    }
  }
};

TEST_CASE("configured invite LAN candidate works without public traversal ACK",
          "[session][configured-invite][lan][network]") {
  ConfiguredInviteCvarFixture cvars;
  constexpr uint16_t rendezvous_port = 39341;
  constexpr uint16_t peer_port = 39342;
  auto issued = ConfiguredAttempt(rendezvous_port, peer_port);
  auto advertised = CorrelatedSession(issued, {htonl(INADDR_LOOPBACK), peer_port});
  ConfiguredInviteNetworkFixture network(rendezvous_port, peer_port, advertised,
                                         true, false, true);
  LanDiscoveryService discovery(kTitle, peer_port + 1);
  auto result = discovery.DiscoverConfiguredInvite(
      issued, 800, [] { return true; }, {},
      {htonl(INADDR_LOOPBACK), peer_port});
  REQUIRE(result);
  CHECK(result->session.info.id == advertised.info.id);
  CHECK(result->session.info.key == advertised.info.key);
  CHECK(result->session.host_xuid == advertised.host_xuid);
  CHECK(result->session.discovery_address == LanAddress{htonl(INADDR_LOOPBACK), peer_port});
  CHECK(network.registrations.load() >= 1);
  CHECK(network.discovery_queries.load() >= 1);
  NatProbeDetach(result->socket);
#if REX_PLATFORM_WIN32
  closesocket(SOCKET(result->socket));
#else
  close(int(result->socket));
#endif
  NatProbeRetireIdentity(issued.attempt.attempt_id);
}

TEST_CASE("configured invite LAN proof rejects altered host tuple",
          "[session][configured-invite][lan][security][network]") {
  ConfiguredInviteCvarFixture cvars;
  constexpr std::array tamper_fields{
      InviteLanTamper::kTitle, InviteLanTamper::kSessionId,
      InviteLanTamper::kKey, InviteLanTamper::kHostXuid,
      InviteLanTamper::kHostIpv4, InviteLanTamper::kHostPort};
  for (size_t i = 0; i < tamper_fields.size(); ++i) {
    const uint16_t rendezvous_port = uint16_t(39350 + i * 2);
    const uint16_t peer_port = uint16_t(rendezvous_port + 1);
    auto issued = ConfiguredAttempt(rendezvous_port, peer_port);
    auto advertised = CorrelatedSession(issued, {htonl(INADDR_LOOPBACK), peer_port});
    ConfiguredInviteNetworkFixture network(rendezvous_port, peer_port, advertised,
                                           true, false, true, tamper_fields[i]);
    LanDiscoveryService discovery(kTitle, uint16_t(39370 + i));
    auto result = discovery.DiscoverConfiguredInvite(
        issued, 250, [] { return true; }, {},
        {htonl(INADDR_LOOPBACK), peer_port});
    CHECK_FALSE(result);
    CHECK(network.registrations.load() >= 1);
    CHECK(network.discovery_queries.load() >= 1);
  }
}

TEST_CASE("configured invite LAN ignores forged response before valid one",
          "[session][configured-invite][lan][security][network]") {
  ConfiguredInviteCvarFixture cvars;
  constexpr uint16_t rendezvous_port = 39345;
  constexpr uint16_t peer_port = 39346;
  auto issued = ConfiguredAttempt(rendezvous_port, peer_port);
  auto advertised = CorrelatedSession(issued, {htonl(INADDR_LOOPBACK), peer_port});
  ConfiguredInviteNetworkFixture network(rendezvous_port, peer_port, advertised,
                                         true, false, true, InviteLanTamper::kNone, true);
  LanDiscoveryService discovery(kTitle, peer_port + 1);
  auto result = discovery.DiscoverConfiguredInvite(
      issued, 800, [] { return true; }, {},
      {htonl(INADDR_LOOPBACK), peer_port});
  REQUIRE(result);
  CHECK(result->session.info.id == advertised.info.id);
  NatProbeDetach(result->socket);
#if REX_PLATFORM_WIN32
  closesocket(SOCKET(result->socket));
#else
  close(int(result->socket));
#endif
  NatProbeRetireIdentity(issued.attempt.attempt_id);
}

TEST_CASE("host LAN listener answers only server-issued private invite attempts",
          "[session][configured-invite][lan][security][network]") {
  ConfiguredInviteCvarFixture cvars;
  constexpr uint16_t host_port = 39348;
  auto issued = ConfiguredAttempt(39349, host_port);
  auto advertised = CorrelatedSession(issued, {htonl(INADDR_LOOPBACK), host_port});
  LanDiscoveryService host(kTitle, host_port);
  REQUIRE(host.Advertise(std::make_shared<SessionRecord>(advertised)));
#if REX_PLATFORM_WIN32
  WSADATA data{};
  REQUIRE(WSAStartup(MAKEWORD(2, 2), &data) == 0);
  SOCKET client = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  REQUIRE(client != INVALID_SOCKET);
#else
  int client = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  REQUIRE(client >= 0);
#endif
  sockaddr_in local{};
  local.sin_family = AF_INET;
  local.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  local.sin_port = 0;
  REQUIRE(bind(client, reinterpret_cast<const sockaddr*>(&local), sizeof(local)) == 0);
#if REX_PLATFORM_WIN32
  int local_length = sizeof(local);
#else
  socklen_t local_length = sizeof(local);
#endif
  REQUIRE(getsockname(client, reinterpret_cast<sockaddr*>(&local), &local_length) == 0);
  std::array<uint8_t, 6> source{};
  std::memcpy(source.data(), &local.sin_addr.s_addr, 4);
  std::memcpy(source.data() + 4, &local.sin_port, 2);
  const auto selector = InviteLanAuthenticationTag(kAttempt, "invite-lan-selector-v1");
  const auto proof = InviteLanAuthenticationTag(kAttempt, "invite-lan-request-v1", source);
  REQUIRE(selector);
  REQUIRE(proof);
  ClientInviteLanPacket probe{};
  std::memcpy(probe.magic, "HILN", 4);
  probe.version = 1;
  probe.type = 1;
  std::memcpy(probe.selector, selector->data(), 16);
  std::memcpy(probe.proof, proof->data(), 16);
  sockaddr_in target{};
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  target.sin_port = htons(host_port);
  auto send_probe = [&] {
    return sendto(client, reinterpret_cast<const char*>(&probe), sizeof(probe), 0,
                  reinterpret_cast<const sockaddr*>(&target), sizeof(target)) == sizeof(probe);
  };
  auto receive_reply = [&] {
    fd_set readers;
    FD_ZERO(&readers);
    FD_SET(client, &readers);
    timeval timeout{0, 100000};
#if REX_PLATFORM_WIN32
    if (select(0, &readers, nullptr, nullptr, &timeout) <= 0)
#else
    if (select(client + 1, &readers, nullptr, nullptr, &timeout) <= 0)
#endif
      return std::optional<ClientInviteLanPacket>{};
    ClientInviteLanPacket reply{};
    sockaddr_in source_address{};
#if REX_PLATFORM_WIN32
    int source_length = sizeof(source_address);
#else
    socklen_t source_length = sizeof(source_address);
#endif
    if (recvfrom(client, reinterpret_cast<char*>(&reply), sizeof(reply), 0,
                 reinterpret_cast<sockaddr*>(&source_address), &source_length) != sizeof(reply))
      return std::optional<ClientInviteLanPacket>{};
    return std::optional<ClientInviteLanPacket>{reply};
  };
  REQUIRE(send_probe());
  CHECK_FALSE(receive_reply());
  REQUIRE(NatProbeInstallIdentity({std::string(kAttempt), std::string(kCapability),
                                   "127.0.0.1", 39349, 0, false}));
  REQUIRE(send_probe());
  CHECK_FALSE(receive_reply());
  NatProbeRetireIdentity(kAttempt);
  REQUIRE(NatProbeInstallIdentity({std::string(kAttempt), std::string(kCapability),
                                   "127.0.0.1", 39349, 0, true}));
  const auto before_reply = NatProbeAcknowledgedDiscoveryAttempts();
  CHECK(std::none_of(before_reply.begin(), before_reply.end(), [](const auto& attempt) {
    return attempt.attempt_id == kAttempt;
  }));
  REQUIRE(send_probe());
  auto reply = receive_reply();
  REQUIRE(reply);
  CHECK(std::memcmp(reply->magic, "HILN", 4) == 0);
  CHECK(reply->version == 1);
  CHECK(reply->type == 2);
  CHECK(std::memcmp(reply->selector, selector->data(), 16) == 0);
  // The reply can be received just before the host listener records its
  // successful send as a prepared attempt on the other thread.
  std::vector<NatProbePeerAttempt> prepared;
  for (int retry = 0; retry < 100; ++retry) {
    prepared = NatProbeAcknowledgedDiscoveryAttempts();
    if (std::any_of(prepared.begin(), prepared.end(), [](const auto& attempt) {
          return attempt.attempt_id == kAttempt;
        }))
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  CHECK(std::any_of(prepared.begin(), prepared.end(), [](const auto& attempt) {
    return attempt.attempt_id == kAttempt;
  }));
  NatProbeRetireIdentity(kAttempt);
  const auto after_retirement = NatProbeAcknowledgedDiscoveryAttempts();
  CHECK(std::none_of(after_retirement.begin(), after_retirement.end(), [](const auto& attempt) {
    return attempt.attempt_id == kAttempt;
  }));
#if REX_PLATFORM_WIN32
  closesocket(client);
  WSACleanup();
#else
  close(client);
#endif
  host.StopAdvertising();
}

std::string AdmissionBody(uint64_t revision, bool ready, uint32_t remaining_ms = 59000,
                          std::string_view phase = {},
                          std::string_view attempt_id = kAttempt) {
  const auto effective_phase = phase.empty()
                                   ? (ready ? "admission_ready" : "admission_awaiting_host")
                                   : phase;
  nlohmann::json body = {{"attempt_id", attempt_id},
                         {"purpose", "invite_code_private_eligible"},
                         {"phase", effective_phase},
                         {"admission_generation", kGeneration},
                         {"lease_revision", revision},
                         {"admission_lease_duration_ms", 60000},
                         {"admission_expires_in_ms", remaining_ms},
                         {"host_ready", ready}};
  if (effective_phase == "terminal") {
    body["admission_expires_in_ms"] = 0;
    body["host_ready"] = false;
  }
  return body.dump();
}

ClientAdmissionTransportResponse AdmissionHttp(std::string body, Clock::time_point completed_at,
                                               uint32_t status = 200) {
  return {status, std::move(body), completed_at};
}

ClientAdmissionOperation Begin(ClientAdmissionLeaseState& state, Clock::time_point now) {
  auto operation = state.BeginOperation(7001, 0x01020304, 41000, now);
  REQUIRE(operation);
  return *operation;
}

ClientAdmissionApplyResult ApplyArm(ClientAdmissionLeaseState& state,
                                    const DirectoryAdmissionState& response,
                                    Clock::time_point now) {
  auto operation = Begin(state, now);
  REQUIRE(operation.action == ClientAdmissionAction::kArm);
  return state.ApplyResponse(operation, response, now);
}

ClientAdmissionApplyResult ApplyStatus(ClientAdmissionLeaseState& state,
                                       const DirectoryAdmissionState& response,
                                       Clock::time_point now) {
  auto operation = Begin(state, now);
  REQUIRE(operation.action == ClientAdmissionAction::kStatus);
  return state.ApplyResponse(operation, response, now);
}

ClientAdmissionApplyResult ApplyRenewal(ClientAdmissionLeaseState& state,
                                        const DirectoryAdmissionState& response,
                                        Clock::time_point now) {
  auto operation = Begin(state, now);
  REQUIRE(operation.action == ClientAdmissionAction::kRenew);
  return state.ApplyResponse(operation, response, now);
}

DirectoryTraversalAttempt InviteAttempt() {
  return {"session-a",
          std::string(kAttempt),
          std::string(kCapability),
          "203.0.113.2",
          30740,
          1,
          "invite_code_private_eligible",
          {},
          0,
          0,
          false};
}

DirectoryTraversalAttempt InviteAttemptFor(std::string session_id, std::string attempt_id,
                                           std::string capability) {
  auto attempt = InviteAttempt();
  attempt.session_id = std::move(session_id);
  attempt.attempt_id = std::move(attempt_id);
  attempt.capability = std::move(capability);
  return attempt;
}

std::shared_ptr<SessionRecord> ExactDiscovery() {
  auto session = std::make_shared<SessionRecord>();
  session->info.id = {1, 2, 3, 4, 5, 6, 7, 8};
  session->info.host_address = {0x01020304, 30742};
  session->discovery_address = {0x05060708, 41000};
  session->traversal_session_id = "session-a";
  session->traversal_attempt_id = kAttempt;
  session->traversal_capability = kCapability;
  session->host_xuid = 1001;
  session->host_name = "Host";
  session->max_public_slots = 4;
  session->max_private_slots = 2;
  return session;
}

std::shared_ptr<SessionRecord> ExactDiscoveryFor(const DirectoryTraversalAttempt& attempt,
                                                 uint8_t session_tag, LanAddress peer) {
  auto session = ExactDiscovery();
  session->info.id[0] = session_tag;
  session->discovery_address = peer;
  session->traversal_session_id = attempt.session_id;
  session->traversal_attempt_id = attempt.attempt_id;
  session->traversal_capability = attempt.capability;
  return session;
}

DirectoryAdmissionState Admission(uint64_t revision = 1, bool ready = false,
                                  uint32_t remaining_ms = 59000,
                                  std::string generation = std::string(kGeneration)) {
  return {std::string(kAttempt),
          "invite_code_private_eligible",
          ready ? "admission_ready" : "admission_awaiting_host",
          std::move(generation),
          revision,
          60000,
          remaining_ms,
          ready};
}

nlohmann::json AtomicInviteDocument(std::string purpose = "invite_code_private_eligible") {
  return {{"session",
           {{"session_id", "session-a"},
            {"server_name", "Host"},
            {"player_count", 1},
            {"max_players", 6},
            {"title_id", "58410A7A"},
            {"protocol_version", 1},
            {"build_id", "build-a"},
            {"connectivity_candidates", nlohmann::json::array({{{"type", "public"},
                                                                {"address", "203.0.113.10"},
                                                                {"discovery_port", 30741},
                                                                {"gameplay_port", 30742}}})}}},
          {"attempt",
           {{"attempt_id", kAttempt},
            {"capability", kCapability},
            {"rendezvous_host", "203.0.113.2"},
            {"rendezvous_port", 30740},
            {"participant", "client"},
            {"purpose", std::move(purpose)},
            {"admission_generation", nullptr},
            {"lease_revision", nullptr},
            {"admission_expires_in_ms", nullptr},
            {"host_ready", false}}}};
}

TEST_CASE("client admission binds only exact private invite discovery",
          "[session][directory][client-admission]") {
  ClientAdmissionLeaseState state;
  auto attempt = InviteAttempt();
  auto exact = ExactDiscovery();

  auto public_attempt = attempt;
  public_attempt.purpose = "public";
  CHECK_FALSE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, public_attempt, exact));

  auto wrong_session = ExactDiscovery();
  wrong_session->traversal_session_id = "session-b";
  CHECK_FALSE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, attempt, wrong_session));

  auto missing_discovery = ExactDiscovery();
  missing_discovery->discovery_address = {};
  CHECK_FALSE(
      state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, attempt, missing_discovery));

  CHECK(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, attempt, exact));
  CHECK(state.bound());
  CHECK(state.purpose() == "invite_code_private_eligible");
  CHECK(state.NextAction() == ClientAdmissionAction::kArm);
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid));
}

TEST_CASE("atomic invite response retains server-owned private purpose",
          "[session][directory][client-admission]") {
  auto parsed =
      ParseInviteCodeJoinAttemptResponse(AtomicInviteDocument().dump(), 0x58410A7A, "build-a");
  REQUIRE(parsed);
  CHECK(parsed->session.session_id == "session-a");
  CHECK(parsed->attempt.session_id == "session-a");
  CHECK(parsed->attempt.participant == 1);
  CHECK(parsed->attempt.purpose == "invite_code_private_eligible");

  CHECK_FALSE(ParseInviteCodeJoinAttemptResponse(AtomicInviteDocument("public").dump(), 0x58410A7A,
                                                 "build-a"));
  CHECK_FALSE(
      ParseInviteCodeJoinAttemptResponse(AtomicInviteDocument().dump(), 0x58410A7A, "wrong-build"));
}

TEST_CASE("client admission parser rejects unsafe lease values",
          "[session][directory][client-admission]") {
  nlohmann::json document = {{"attempt_id", kAttempt},
                             {"purpose", "invite_code_private_eligible"},
                             {"phase", "admission_awaiting_host"},
                             {"admission_generation", kGeneration},
                             {"lease_revision", 1},
                             {"admission_lease_duration_ms", 60000},
                             {"admission_expires_in_ms", 59000},
                             {"host_ready", false}};
  REQUIRE(ParseDirectoryAdmissionResponse(document.dump()));

  document["admission_expires_in_ms"] = 0;
  CHECK_FALSE(ParseDirectoryAdmissionResponse(document.dump()));
  document["admission_expires_in_ms"] = std::numeric_limits<uint32_t>::max();
  CHECK_FALSE(ParseDirectoryAdmissionResponse(document.dump()));
  document["admission_expires_in_ms"] = 59000;
  document["host_ready"] = true;
  CHECK_FALSE(ParseDirectoryAdmissionResponse(document.dump()));

  document["phase"] = "terminal";
  document["admission_expires_in_ms"] = 0;
  document["host_ready"] = false;
  REQUIRE(ParseDirectoryAdmissionResponse(document.dump()));
}

TEST_CASE("arm waits for current host readiness and replay does not extend",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  CHECK(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
  CHECK_FALSE(state.host_ready());
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, start));
  CHECK(state.lease_deadline() == start + std::chrono::seconds(59));
  CHECK(state.renewal_deadline() == start + std::chrono::seconds(20));
  CHECK(state.NextAction(start + std::chrono::milliseconds(19999)) ==
        ClientAdmissionAction::kStatus);
  CHECK(state.NextAction(start + std::chrono::seconds(20)) == ClientAdmissionAction::kStatus);

  const auto original_deadline = state.lease_deadline();
  CHECK(ApplyStatus(state, Admission(1, false, 57000), start + std::chrono::seconds(1)) ==
        ClientAdmissionApplyResult::kApplied);
  CHECK(state.lease_deadline() <= original_deadline);

  CHECK(ApplyStatus(state, Admission(1, true, 56000), start + std::chrono::seconds(2)) ==
        ClientAdmissionApplyResult::kApplied);
  CHECK(state.NextAction(start + std::chrono::seconds(20)) == ClientAdmissionAction::kRenew);
  auto ready = state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::seconds(2));
  REQUIRE(ready);
  CHECK(ready->directory_session_id == "session-a");
  CHECK(ready->attempt_id == kAttempt);
  CHECK(ready->lease_revision == 1);
  CHECK(ready->private_allocation_eligible);
  REQUIRE(ready->session);
  CHECK(ready->session->info.id == ExactDiscovery()->info.id);
}

TEST_CASE("renewal changes revision and clears readiness until current ack",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  REQUIRE(ApplyArm(state, Admission(1, false), start) == ClientAdmissionApplyResult::kApplied);
  REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
          ClientAdmissionApplyResult::kApplied);
  REQUIRE(state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::seconds(1)));

  const auto renewed_at = start + std::chrono::seconds(20);
  CHECK(ApplyRenewal(state, Admission(2, false, 60000), renewed_at) ==
        ClientAdmissionApplyResult::kApplied);
  CHECK(state.lease_revision() == 2);
  CHECK_FALSE(state.host_ready());
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, renewed_at));
  CHECK(state.renewal_deadline() == renewed_at + std::chrono::seconds(20));

  CHECK(ApplyStatus(state, Admission(1, true, 39000), renewed_at) ==
        ClientAdmissionApplyResult::kIgnoredStale);
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, renewed_at));
  CHECK(ApplyStatus(state, Admission(2, true, 59000, "1123456789abcdef0123456789abcdef"),
                    renewed_at) == ClientAdmissionApplyResult::kInvalidated);
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, renewed_at));

  CHECK_FALSE(state.bound());
}

TEST_CASE("renewal uncertainty preserves only the old deadline",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  REQUIRE(ApplyArm(state, Admission(1, false), start) == ClientAdmissionApplyResult::kApplied);
  REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
          ClientAdmissionApplyResult::kApplied);
  const auto old_deadline = state.lease_deadline();
  const auto renewal_time = start + std::chrono::seconds(20);
  auto renewal = Begin(state, renewal_time);
  REQUIRE(renewal.action == ClientAdmissionAction::kRenew);
  REQUIRE(state.ApplyTransportFailure(renewal, renewal_time) ==
          ClientAdmissionApplyResult::kApplied);
  CHECK(state.lease_deadline() == old_deadline);
  CHECK(state.NextAction(renewal_time) == ClientAdmissionAction::kStatus);
  CHECK(ClassifyClientAdmissionResponse(ClientAdmissionAction::kRenew, std::nullopt, false) ==
        ClientAdmissionResponseDisposition::kRetainUntilExpiry);
  CHECK(ClassifyClientAdmissionResponse(ClientAdmissionAction::kRenew, 409, false) ==
        ClientAdmissionResponseDisposition::kReconcileStatus);

  CHECK(ApplyStatus(state, Admission(1, true, 39000), renewal_time) ==
        ClientAdmissionApplyResult::kApplied);
  CHECK(state.lease_deadline() <= old_deadline);
  CHECK(state.NextAction(renewal_time) == ClientAdmissionAction::kRenew);

  auto renewal_retry = Begin(state, renewal_time);
  REQUIRE(renewal_retry.action == ClientAdmissionAction::kRenew);
  REQUIRE(state.ApplyTransportFailure(renewal_retry, renewal_time) ==
          ClientAdmissionApplyResult::kApplied);
  REQUIRE(ApplyStatus(state, Admission(2, false, 59000), renewal_time) ==
          ClientAdmissionApplyResult::kApplied);
  CHECK(state.lease_revision() == 2);
  CHECK(state.lease_deadline() == renewal_time + std::chrono::seconds(59));
}

TEST_CASE("authoritative failures and expiry remove the candidate",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  REQUIRE(ApplyArm(state, Admission(1, false, 1000), start) ==
          ClientAdmissionApplyResult::kApplied);
  REQUIRE(ApplyStatus(state, Admission(1, true, 900), start + std::chrono::milliseconds(50)) ==
          ClientAdmissionApplyResult::kApplied);
  REQUIRE(state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::milliseconds(50)));
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::seconds(1)));
  CHECK(state.ExpireIfNeeded(start + std::chrono::seconds(1)));
  CHECK_FALSE(state.bound());

  REQUIRE(state.BindExactDiscovery(kUser, kToken + 1, kTitle, kLocalXuid, InviteAttempt(), exact));
  REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
  DirectoryAdmissionState terminal = Admission();
  terminal.phase = "terminal";
  terminal.admission_expires_in_ms = 0;
  terminal.host_ready = false;
  CHECK(ApplyStatus(state, terminal, start) == ClientAdmissionApplyResult::kInvalidated);
  CHECK_FALSE(state.bound());

  CHECK(ClassifyClientAdmissionResponse(ClientAdmissionAction::kStatus, 404, false) ==
        ClientAdmissionResponseDisposition::kInvalidate);
  CHECK(ClassifyClientAdmissionResponse(ClientAdmissionAction::kStatus, 200, false) ==
        ClientAdmissionResponseDisposition::kInvalidate);
}

TEST_CASE("arm and renewal responses cannot claim host readiness",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  SECTION("arm") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    CHECK(ApplyArm(state, Admission(1, true), start) == ClientAdmissionApplyResult::kInvalidated);
    CHECK_FALSE(state.bound());
  }
  SECTION("renew") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
    REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
            ClientAdmissionApplyResult::kApplied);
    CHECK(ApplyRenewal(state, Admission(2, true), start + std::chrono::seconds(20)) ==
          ClientAdmissionApplyResult::kInvalidated);
    CHECK_FALSE(state.bound());
  }
}

TEST_CASE("generation and ordinary future revisions fail closed",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  SECTION("different generation") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
    CHECK(ApplyStatus(state, Admission(1, false, 59000, "1123456789abcdef0123456789abcdef"),
                      start + std::chrono::seconds(1)) == ClientAdmissionApplyResult::kInvalidated);
    CHECK_FALSE(state.bound());
  }
  SECTION("ordinary status N plus one") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
    CHECK(ApplyStatus(state, Admission(2, false), start + std::chrono::seconds(1)) ==
          ClientAdmissionApplyResult::kInvalidated);
    CHECK_FALSE(state.bound());
  }
}

TEST_CASE("uncertain renewal reconciles only exact next revision",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  auto prepare_uncertainty = [&](ClientAdmissionLeaseState& state,
                                 const std::shared_ptr<SessionRecord>& exact) {
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
    REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
            ClientAdmissionApplyResult::kApplied);
    auto renewal = Begin(state, start + std::chrono::seconds(20));
    REQUIRE(renewal.action == ClientAdmissionAction::kRenew);
    REQUIRE(state.ApplyTransportFailure(renewal, start + std::chrono::seconds(20)) ==
            ClientAdmissionApplyResult::kApplied);
  };
  SECTION("N plus one") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    prepare_uncertainty(state, exact);
    CHECK(ApplyStatus(state, Admission(2, false), start + std::chrono::seconds(20)) ==
          ClientAdmissionApplyResult::kApplied);
    CHECK(state.lease_revision() == 2);
    CHECK_FALSE(state.host_ready());
    CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::seconds(20)));
  }
  SECTION("N plus two") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    prepare_uncertainty(state, exact);
    CHECK(ApplyStatus(state, Admission(3, false), start + std::chrono::seconds(20)) ==
          ClientAdmissionApplyResult::kInvalidated);
    CHECK_FALSE(state.bound());
  }
}

TEST_CASE("post-HTTP local expiry always wins", "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  REQUIRE(ApplyArm(state, Admission(1, false, 1000), start) ==
          ClientAdmissionApplyResult::kApplied);
  auto status = Begin(state, start + std::chrono::milliseconds(900));
  REQUIRE(status.action == ClientAdmissionAction::kStatus);
  CHECK(state.ApplyResponse(status, Admission(1, true), start + std::chrono::seconds(1)) ==
        ClientAdmissionApplyResult::kInvalidated);
  CHECK_FALSE(state.bound());
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::seconds(1)));
}

TEST_CASE("pre-arm retries stop with authoritative attempt lifetime",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  auto first = Begin(state, start);
  REQUIRE(state.ApplyTransportFailure(first, start) == ClientAdmissionApplyResult::kApplied);
  auto retry = Begin(state, start + std::chrono::seconds(1));
  REQUIRE(retry.action == ClientAdmissionAction::kArm);
  REQUIRE(state.ApplyTransportFailure(retry, start + std::chrono::seconds(1)) ==
          ClientAdmissionApplyResult::kApplied);
  auto last = Begin(state, start + std::chrono::seconds(2));
  CHECK(state.EndAttemptAuthority(last) == ClientAdmissionApplyResult::kInvalidated);
  CHECK_FALSE(state.bound());
  CHECK_FALSE(state.BeginOperation(7001, 0x01020304, 41000, start + std::chrono::seconds(3)));
  CHECK(state.ApplyResponse(last, Admission(), start + std::chrono::seconds(3)) ==
        ClientAdmissionApplyResult::kIgnoredStale);
}

TEST_CASE("stale arm status and renew operations cannot mutate replacements",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  SECTION("arm") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    auto old_arm = Begin(state, start);
    REQUIRE(
        state.BindExactDiscovery(kUser, kToken + 1, kTitle, kLocalXuid, InviteAttempt(), exact));
    CHECK(state.ApplyResponse(old_arm, Admission(), start) ==
          ClientAdmissionApplyResult::kIgnoredStale);
    CHECK(state.lifecycle_token() == kToken + 1);
    CHECK_FALSE(state.leased());
  }
  SECTION("status") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
    REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
            ClientAdmissionApplyResult::kApplied);
    auto old_status = Begin(state, start + std::chrono::seconds(2));
    REQUIRE(ApplyRenewal(state, Admission(2, false), start + std::chrono::seconds(20)) ==
            ClientAdmissionApplyResult::kApplied);
    auto deadline = state.lease_deadline();
    CHECK(state.ApplyResponse(old_status, Admission(1, true), start + std::chrono::seconds(21)) ==
          ClientAdmissionApplyResult::kIgnoredStale);
    CHECK(state.lease_revision() == 2);
    CHECK(state.lease_deadline() == deadline);
    CHECK_FALSE(state.host_ready());
  }
  SECTION("renew after cancellation") {
    ClientAdmissionLeaseState state;
    auto exact = ExactDiscovery();
    REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
    REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
    REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
            ClientAdmissionApplyResult::kApplied);
    auto old_renew = Begin(state, start + std::chrono::seconds(20));
    state.Invalidate();
    REQUIRE(
        state.BindExactDiscovery(kUser, kToken + 1, kTitle, kLocalXuid, InviteAttempt(), exact));
    CHECK(state.ApplyResponse(old_renew, Admission(2, false), start + std::chrono::seconds(20)) ==
          ClientAdmissionApplyResult::kIgnoredStale);
    CHECK(state.lifecycle_token() == kToken + 1);
    CHECK_FALSE(state.leased());
  }
}

TEST_CASE("ready candidate is user-bound immutable and live",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
  REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
          ClientAdmissionApplyResult::kApplied);
  auto ready = state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::seconds(1));
  REQUIRE(ready);
  CHECK(ready->local_user_index == kUser);
  CHECK(ready->private_allocation_eligible);
  CHECK(ready->session.get() != exact.get());
  CHECK_FALSE(state.ReadyCandidate(kTitle + 1, kLocalXuid, start + std::chrono::seconds(1)));
  CHECK_FALSE(state.ReadyCandidate(kTitle, std::nullopt, start + std::chrono::seconds(1)));
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid + 1, start + std::chrono::seconds(1)));
  CHECK(state.has_ever_been_ready());

  exact->info.key[0] ^= 0xff;
  CHECK_FALSE(state.ValidateLiveness(kTitle, kLocalXuid));
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid, start + std::chrono::seconds(1)));
}

TEST_CASE("ever-ready latch survives renewal readiness loss",
          "[session][directory][client-admission]") {
  const auto start = Clock::time_point(std::chrono::seconds(100));
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  REQUIRE(ApplyArm(state, Admission(), start) == ClientAdmissionApplyResult::kApplied);
  REQUIRE(ApplyStatus(state, Admission(1, true), start + std::chrono::seconds(1)) ==
          ClientAdmissionApplyResult::kApplied);
  REQUIRE(state.has_ever_been_ready());
  CHECK_FALSE(ClientAdmissionMayReplaceLifecycle(false, &state));
  CHECK_FALSE(ClientAdmissionMayReplaceLifecycle(true, &state));
  REQUIRE(ApplyRenewal(state, Admission(2, false), start + std::chrono::seconds(20)) ==
          ClientAdmissionApplyResult::kApplied);
  CHECK_FALSE(state.host_ready());
  CHECK(state.has_ever_been_ready());
  CHECK_FALSE(ClientAdmissionMayReplaceLifecycle(false, &state));
  CHECK_FALSE(ClientAdmissionMayReplaceLifecycle(true, &state));
}

TEST_CASE("public Search cannot replace an invite lifecycle",
          "[session][directory][client-admission]") {
  ClientAdmissionLeaseState state;
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid, InviteAttempt(), exact));
  CHECK_FALSE(ClientAdmissionMayReplaceLifecycle(false, &state));
  CHECK(state.bound());
  CHECK(state.lifecycle_token() == kToken);
  CHECK(ClientAdmissionMayReplaceLifecycle(true, &state));
}

TEST_CASE("production driver completes the client admission lease lifecycle",
          "[session][directory][client-admission][production]") {
  const auto start = Clock::now();
  ClientNatFixture nat;
  auto attempt = InviteAttempt();
  auto exact = ExactDiscovery();
  constexpr uint64_t socket = 53001;
  nat.Bind(socket, attempt, exact->discovery_address);

  std::vector<ClientAdmissionTransportRequest> requests;
  SessionDirectoryClient directory(
      [](uint32_t user) -> std::optional<uint64_t> {
        return ResolveRexGlueLocalUserXuid(user, kLocalXuid);
      },
      [&](const ClientAdmissionTransportRequest& request) {
        requests.push_back(request);
        if (request.action == ClientAdmissionTransportAction::kArm)
          return AdmissionHttp(AdmissionBody(1, false), request.request_started_at);
        if (request.action == ClientAdmissionTransportAction::kRenew)
          return AdmissionHttp(AdmissionBody(2, false), request.request_started_at);
        if (request.action == ClientAdmissionTransportAction::kStatus) {
          const bool second_revision = request.expected_revision == 2;
          if (second_revision &&
              std::count_if(requests.begin(), requests.end(), [](const auto& value) {
                return value.action == ClientAdmissionTransportAction::kStatus &&
                       value.expected_revision == 2;
              }) > 1)
            return AdmissionHttp(AdmissionBody(2, false, 0, "terminal"),
                                 request.request_started_at);
          return AdmissionHttp(AdmissionBody(second_revision ? 2 : 1, true),
                               request.request_started_at);
        }
        return ClientAdmissionTransportResponse{204, {}, request.request_started_at};
      },
      false);
  directory.SetClientAdmissionTitle(kTitle);
  REQUIRE(directory.PrepareClientAdmission(0, kTitle, attempt, *exact, socket) ==
          ClientAdmissionPrepareResult::kPrepared);
  REQUIRE(directory.ConfirmClientAdmissionSession(0, exact));
  REQUIRE(directory.HasClientAdmission(0));

  directory.PollClientAdmissions(start);
  CHECK_FALSE(directory.ReadyClientAdmission(0));
  REQUIRE(requests.back().action == ClientAdmissionTransportAction::kArm);

  directory.PollClientAdmissions(start + std::chrono::seconds(1));
  auto ready = directory.ReadyClientAdmission(0);
  REQUIRE(ready);
  CHECK(ready->local_user_index == 0);
  CHECK(ready->lease_revision == 1);

  directory.PollClientAdmissions(start + std::chrono::seconds(20));
  CHECK(requests.back().action == ClientAdmissionTransportAction::kRenew);
  CHECK_FALSE(directory.ReadyClientAdmission(0));

  directory.PollClientAdmissions(start + std::chrono::seconds(21));
  ready = directory.ReadyClientAdmission(0);
  REQUIRE(ready);
  CHECK(ready->lease_revision == 2);

  directory.PollClientAdmissions(start + std::chrono::seconds(22));
  CHECK_FALSE(directory.HasClientAdmission(0));
  CHECK_FALSE(directory.ReadyClientAdmission(0));
}

TEST_CASE("production identity rejects nonzero users without disturbing user zero",
          "[session][directory][client-admission][production]") {
  const auto start = Clock::now();
  ClientNatFixture nat;
  auto user_zero_attempt = InviteAttempt();
  auto user_zero_session = ExactDiscovery();
  constexpr uint64_t socket_zero = 53101;
  nat.Bind(socket_zero, user_zero_attempt, user_zero_session->discovery_address);

  std::vector<ClientAdmissionTransportRequest> requests;
  SessionDirectoryClient directory(
      [](uint32_t user) -> std::optional<uint64_t> {
        return ResolveRexGlueLocalUserXuid(user, kLocalXuid);
      },
      [&](const ClientAdmissionTransportRequest& request) {
        requests.push_back(request);
        if (request.action == ClientAdmissionTransportAction::kArm)
          return AdmissionHttp(AdmissionBody(1, false), request.request_started_at);
        return AdmissionHttp(AdmissionBody(1, true), request.request_started_at);
      },
      false);
  directory.SetClientAdmissionTitle(kTitle);
  REQUIRE(directory.PrepareClientAdmission(0, kTitle, user_zero_attempt, *user_zero_session,
                                           socket_zero) ==
          ClientAdmissionPrepareResult::kPrepared);
  REQUIRE(directory.ConfirmClientAdmissionSession(0, user_zero_session));
  directory.PollClientAdmissions(start);
  directory.PollClientAdmissions(start + std::chrono::seconds(1));
  const auto user_zero_ready = directory.ReadyClientAdmission(0);
  REQUIRE(user_zero_ready);
  const auto request_count = requests.size();

  const auto user_one_attempt = InviteAttemptFor(
      "session-b", "11112222333344445555666677778888",
      "88887777666655554444333322221111");
  const LanAddress user_one_peer{htonl(0xCB007166u), 47000};
  auto user_one_session = ExactDiscoveryFor(user_one_attempt, 2, user_one_peer);
  CHECK(directory.PrepareClientAdmission(1, kTitle, user_one_attempt, *user_one_session, 53102) ==
        ClientAdmissionPrepareResult::kInvalid);
  directory.PollClientAdmissions(start + std::chrono::seconds(2));
  CHECK_FALSE(directory.HasClientAdmission(1));
  CHECK_FALSE(directory.ReadyClientAdmission(1));
  CHECK(requests.size() == request_count + 1);  // user 0 status only
  auto still_ready = directory.ReadyClientAdmission(0);
  REQUIRE(still_ready);
  CHECK(still_ready->attempt_id == user_zero_ready->attempt_id);
  CHECK(still_ready->lease_revision == user_zero_ready->lease_revision);
}

TEST_CASE("ready candidate synchronously rejects retired NAT correlation",
          "[session][directory][client-admission][production][nat]") {
  const auto start = Clock::now();
  ClientNatFixture nat;
  auto attempt = InviteAttempt();
  auto exact = ExactDiscovery();
  constexpr uint64_t socket = 53201;
  nat.Bind(socket, attempt, exact->discovery_address);
  SessionDirectoryClient directory(
      [](uint32_t user) -> std::optional<uint64_t> {
        return ResolveRexGlueLocalUserXuid(user, kLocalXuid);
      },
      [](const ClientAdmissionTransportRequest& request) {
        return AdmissionHttp(
            AdmissionBody(1, request.action == ClientAdmissionTransportAction::kStatus),
            request.request_started_at);
      },
      false);
  directory.SetClientAdmissionTitle(kTitle);
  REQUIRE(directory.PrepareClientAdmission(0, kTitle, attempt, *exact, socket) ==
          ClientAdmissionPrepareResult::kPrepared);
  REQUIRE(directory.ConfirmClientAdmissionSession(0, exact));
  directory.PollClientAdmissions(start);
  directory.PollClientAdmissions(start + std::chrono::seconds(1));
  REQUIRE(directory.ReadyClientAdmission(0));

  NatProbeDetach(socket);
  CHECK_FALSE(directory.ReadyClientAdmission(0));
  CHECK_FALSE(directory.HasClientAdmission(0));
  CHECK_FALSE(directory.ReadyClientAdmission(0));
}

TEST_CASE("production pre-arm retry ends with real NAT rendezvous lifetime",
          "[session][directory][client-admission][production][nat]") {
  const auto start = Clock::now();
  ClientNatFixture nat;
  auto attempt = InviteAttempt();
  auto exact = ExactDiscovery();
  constexpr uint64_t socket = 53301;
  nat.Bind(socket, attempt, exact->discovery_address);
  size_t arm_requests = 0;
  SessionDirectoryClient directory(
      [](uint32_t user) -> std::optional<uint64_t> {
        return ResolveRexGlueLocalUserXuid(user, kLocalXuid);
      },
      [&](const ClientAdmissionTransportRequest& request) {
        if (request.action == ClientAdmissionTransportAction::kArm)
          ++arm_requests;
        return ClientAdmissionTransportResponse{std::nullopt, {}, request.request_started_at};
      },
      false);
  directory.SetClientAdmissionTitle(kTitle);
  REQUIRE(directory.PrepareClientAdmission(0, kTitle, attempt, *exact, socket) ==
          ClientAdmissionPrepareResult::kPrepared);
  REQUIRE(directory.ConfirmClientAdmissionSession(0, exact));
  REQUIRE(NatProbeRendezvousAttemptActive(socket, attempt.attempt_id));

  directory.PollClientAdmissions(start);
  directory.PollClientAdmissions(start + std::chrono::seconds(1));
  CHECK(arm_requests == 2);
  CHECK(directory.HasClientAdmission(0));

  directory.PollClientAdmissions(start + std::chrono::seconds(21));
  CHECK_FALSE(NatProbeRendezvousAttemptActive(socket, attempt.attempt_id));
  REQUIRE(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, exact->discovery_address) ==
          std::vector<std::string>{attempt.attempt_id});
  CHECK(arm_requests == 2);
  CHECK_FALSE(directory.HasClientAdmission(0));
  CHECK_FALSE(directory.ReadyClientAdmission(0));
}

TEST_CASE("production public Search leaves invite admission isolated",
          "[session][directory][client-admission][production]") {
  const auto start = Clock::now();
  constexpr uint16_t discovery_port = 39151;
  ClientNatFixture nat;
  auto attempt = InviteAttempt();
  auto exact = ExactDiscovery();
  constexpr uint64_t socket = 53351;
  nat.Bind(socket, attempt, exact->discovery_address);
  std::vector<ClientAdmissionTransportRequest> requests;
  LanDiscoveryService discovery(
      kTitle, discovery_port, {},
      [](uint32_t user) -> std::optional<uint64_t> {
        return ResolveRexGlueLocalUserXuid(user, kLocalXuid);
      },
      [&](const ClientAdmissionTransportRequest& request) {
        requests.push_back(request);
        return AdmissionHttp(
            AdmissionBody(1, request.action == ClientAdmissionTransportAction::kStatus),
            request.request_started_at);
      },
      false);
  discovery.SetTitleId(kTitle);
  REQUIRE(discovery.PrepareClientAdmission(0, attempt, *exact, socket) ==
          ClientAdmissionPrepareResult::kPrepared);
  REQUIRE(discovery.ConfirmClientAdmissionSession(0, exact));
  discovery.PollClientAdmissions(start);
  discovery.PollClientAdmissions(start + std::chrono::seconds(1));
  auto ready = discovery.ReadyAcceptedSession(0);
  REQUIRE(ready);
  const auto request_count = requests.size();

  const auto previous_url = REXCVAR_GET(session_directory_url);
  const auto previous_code = REXCVAR_GET(session_directory_invite_code);
  const auto previous_index = REXCVAR_GET(session_directory_session_index);
  const auto previous_direct = REXCVAR_GET(direct_connect_address);
  struct SearchCvarRestore {
    std::string url;
    std::string code;
    uint32_t index;
    std::string direct;
    ~SearchCvarRestore() {
      REXCVAR_SET(direct_connect_address, direct);
      REXCVAR_SET(session_directory_session_index, index);
      REXCVAR_SET(session_directory_invite_code, code);
      REXCVAR_SET(session_directory_url, url);
    }
  } restore{previous_url, previous_code, previous_index, previous_direct};
  REXCVAR_SET(session_directory_url, "");
  REXCVAR_SET(session_directory_invite_code, "");
  REXCVAR_SET(session_directory_session_index, 0xFFFFFFFFu);
  REXCVAR_SET(direct_connect_address, "");
  SessionRegistry public_host_registry;
  auto public_host = public_host_registry.Create(
      0xB13E000000000099ull, "PublicHost",
      {LanDiscoveryService::DetermineLanIpv4(), 30742}, 1, 4, 0);
  LanDiscoveryService public_host_discovery(kTitle, discovery_port);
  REQUIRE(public_host_discovery.Advertise(public_host));
  const auto public_results = discovery.Search(500, 1, 0);

  REQUIRE(public_results.size() == 1);
  CHECK(public_results[0].info.id == public_host->info.id);
  CHECK(requests.size() == request_count);
  CHECK(discovery.HasClientAdmission(0));
  auto still_ready = discovery.ReadyAcceptedSession(0);
  REQUIRE(still_ready);
  CHECK(still_ready->attempt_id == ready->attempt_id);
  CHECK(still_ready->admission_generation == ready->admission_generation);
  CHECK(still_ready->lease_revision == ready->lease_revision);
}

TEST_CASE("production stale cancellation targets only the replaced attempt",
          "[session][directory][client-admission][production]") {
  const auto start = Clock::now();
  ClientNatFixture nat;
  auto attempt_a = InviteAttemptFor("session-a", std::string(kAttempt), std::string(kCapability));
  auto attempt_b = InviteAttemptFor("session-b", "11112222333344445555666677778888",
                                    "88887777666655554444333322221111");
  const LanAddress peer_a{0x05060708, 41000};
  const LanAddress peer_b{htonl(0xCB007188u), 48000};
  auto session_a = ExactDiscoveryFor(attempt_a, 1, peer_a);
  auto session_b = ExactDiscoveryFor(attempt_b, 2, peer_b);
  constexpr uint64_t socket_a = 53401;
  constexpr uint64_t socket_b = 53402;
  nat.Bind(socket_a, attempt_a, peer_a);
  nat.Bind(socket_b, attempt_b, peer_b);

  std::vector<ClientAdmissionTransportRequest> requests;
  SessionDirectoryClient directory(
      [](uint32_t user) -> std::optional<uint64_t> {
        return ResolveRexGlueLocalUserXuid(user, kLocalXuid);
      },
      [&](const ClientAdmissionTransportRequest& request) {
        requests.push_back(request);
        if (request.action == ClientAdmissionTransportAction::kArm)
          return AdmissionHttp(AdmissionBody(1, false, 59000, {}, request.attempt_id),
                               request.request_started_at);
        return ClientAdmissionTransportResponse{204, {}, request.request_started_at};
      },
      false);
  directory.SetClientAdmissionTitle(kTitle);
  REQUIRE(directory.PrepareClientAdmission(0, kTitle, attempt_a, *session_a, socket_a) ==
          ClientAdmissionPrepareResult::kPrepared);
  REQUIRE(directory.ConfirmClientAdmissionSession(0, session_a));
  directory.PollClientAdmissions(start);
  REQUIRE(requests.size() == 1);
  REQUIRE(requests[0].action == ClientAdmissionTransportAction::kArm);
  REQUIRE(requests[0].attempt_id == attempt_a.attempt_id);
  REQUIRE(directory.PrepareClientAdmission(0, kTitle, attempt_b, *session_b, socket_b) ==
          ClientAdmissionPrepareResult::kPrepared);
  REQUIRE(directory.ConfirmClientAdmissionSession(0, session_b));

  directory.PollClientAdmissions(start + std::chrono::seconds(1));
  REQUIRE(requests.size() == 3);
  CHECK(requests[1].action == ClientAdmissionTransportAction::kRevoke);
  CHECK(requests[1].attempt_id == attempt_a.attempt_id);
  CHECK(requests[1].capability == attempt_a.capability);
  CHECK(requests[1].admission_generation == kGeneration);
  CHECK(requests[1].expected_revision == 1);
  CHECK(requests[2].action == ClientAdmissionTransportAction::kArm);
  CHECK(requests[2].attempt_id == attempt_b.attempt_id);
  CHECK(directory.HasClientAdmission(0));
  CHECK_FALSE(directory.ReadyClientAdmission(0));
}

TEST_CASE("configured invite claim is one-flight and isolated from public Search",
          "[session][configured-invite][race]") {
  ConfiguredInviteCvarFixture cvars;
  StageBarrier worker_gate;
  std::promise<void> cleanup_complete;
  auto cleanup_future = cleanup_complete.get_future();
  std::atomic<bool> cleanup_signaled = false;
  std::atomic<uint32_t> by_code_requests = 0;
  SessionManagerDependencies dependencies;
  dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
    return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
  };
  dependencies.invite_join_attempt_transport =
      [&](std::string_view code, uint32_t title_id)
      -> std::optional<DirectoryInviteJoinAttempt> {
    CHECK(code == "ABC234");
    CHECK(title_id == kTitle);
    ++by_code_requests;
    return std::nullopt;
  };
  dependencies.configured_invite_stage_observer =
      [&](ConfiguredInviteStage stage, const ConfiguredInviteOperationIdentity&) {
    if (stage == ConfiguredInviteStage::kWorkerStarted)
      worker_gate.ArriveAndWait();
    if (stage == ConfiguredInviteStage::kCleanupComplete &&
        !cleanup_signaled.exchange(true))
      cleanup_complete.set_value();
  };
  SessionManager manager(nullptr, 39301, std::move(dependencies));

  std::promise<void> start;
  auto simultaneous = start.get_future().share();
  std::jthread first([&] {
    simultaneous.wait();
    manager.OnTitleTransition(kTitle);
  });
  std::jthread second([&] {
    simultaneous.wait();
    manager.OnTitleTransition(kTitle);
  });
  std::jthread racing_search([&] {
    simultaneous.wait();
    manager.discovery().Search(1, 1, 0);
  });
  start.set_value();
  REQUIRE(worker_gate.WaitUntilEntered());
  CHECK(manager.configured_invite_state() ==
        ConfiguredInviteLifecycleState::kClaimed);
  CHECK(by_code_requests.load() == 0);

  // A second ordinary Search after the claim remains list/public-only too.
  manager.discovery().Search(1, 1, 0);
  CHECK(by_code_requests.load() == 0);
  worker_gate.Release();
  first.join();
  second.join();
  racing_search.join();
  REQUIRE(cleanup_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  manager.ShutdownAsyncActivity();
  CHECK(by_code_requests.load() == 1);
  CHECK_FALSE(manager.ready_configured_invite());
}

TEST_CASE("configured invite cancellation boundaries precede worker progression",
          "[session][configured-invite][race][cancellation]") {
  auto run_boundary = [](ConfiguredInviteStage target, uint16_t port) {
    ConfiguredInviteCvarFixture cvars;
    StageBarrier target_gate;
    std::promise<void> cancellation_visible;
    auto cancellation_future = cancellation_visible.get_future();
    std::atomic<bool> cancellation_signaled = false;
    std::atomic<uint32_t> attempts = 0;
    std::atomic<uint32_t> discoveries = 0;
    std::atomic<uint32_t> releases = 0;
    auto issued = ConfiguredAttempt();
    SessionManagerDependencies dependencies;
    dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
      return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
    };
    dependencies.invite_join_attempt_transport =
        [&](std::string_view, uint32_t) -> std::optional<DirectoryInviteJoinAttempt> {
      ++attempts;
      return issued;
    };
    dependencies.join_attempt_completion_transport =
        [&](const DirectoryTraversalAttempt&) { ++releases; };
    dependencies.configured_invite_discovery =
        [&](LanDiscoveryService&, const DirectoryInviteJoinAttempt&, uint32_t,
            const std::function<bool()>& current,
            const std::function<void(ConfiguredInviteStage)>&)
        -> std::optional<ConfiguredInviteDiscoveryResult> {
      ++discoveries;
      CHECK_FALSE(current());
      return std::nullopt;
    };
    dependencies.configured_invite_stage_observer =
        [&](ConfiguredInviteStage stage,
            const ConfiguredInviteOperationIdentity&) {
      if (stage == target)
        target_gate.ArriveAndWait();
      if (stage == ConfiguredInviteStage::kCancellationVisible &&
          !cancellation_signaled.exchange(true))
        cancellation_visible.set_value();
    };
    SessionManager manager(nullptr, port, std::move(dependencies));
    manager.OnTitleTransition(kTitle);
    REQUIRE(target_gate.WaitUntilEntered());
    auto cancel = std::async(std::launch::async,
                             [&] { manager.OnTitleTermination(); });
    REQUIRE(cancellation_future.wait_for(std::chrono::seconds(2)) ==
            std::future_status::ready);
    target_gate.Release();
    REQUIRE(cancel.wait_for(std::chrono::seconds(2)) ==
            std::future_status::ready);
    cancel.get();
    CHECK_FALSE(manager.ready_configured_invite());
    if (target == ConfiguredInviteStage::kWorkerStarted ||
        target == ConfiguredInviteStage::kBeforeAttemptIssue) {
      CHECK(attempts.load() == 0);
      CHECK(discoveries.load() == 0);
      CHECK(releases.load() == 0);
    } else {
      CHECK(attempts.load() == 1);
      CHECK(discoveries.load() == 0);
      CHECK(releases.load() == 1);
    }
  };

  SECTION("cancellation before worker work") {
    run_boundary(ConfiguredInviteStage::kWorkerStarted, 39302);
  }
  SECTION("cancellation before attempt issuance") {
    run_boundary(ConfiguredInviteStage::kBeforeAttemptIssue, 39303);
  }
  SECTION("cancellation after attempt issuance") {
    run_boundary(ConfiguredInviteStage::kAttemptIssued, 39304);
  }
}

TEST_CASE("configured invite cancellation gates every discovery send boundary",
          "[session][configured-invite][race][cancellation][network]") {
  auto run_boundary = [](ConfiguredInviteStage target, uint16_t manager_port,
                         uint16_t rendezvous_port, uint16_t peer_port,
                         uint32_t expected_queries) {
    ConfiguredInviteCvarFixture cvars;
    auto issued = ConfiguredAttempt(rendezvous_port, peer_port);
    auto advertised = CorrelatedSession(
        issued, {htonl(INADDR_LOOPBACK), peer_port});
    ConfiguredInviteNetworkFixture network(rendezvous_port, peer_port,
                                           advertised, false);
    StageBarrier target_gate;
    std::promise<void> cancellation_visible;
    auto cancellation_future = cancellation_visible.get_future();
    std::atomic<bool> cancellation_signaled = false;
    std::atomic<uint32_t> releases = 0;
    SessionManagerDependencies dependencies;
    dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
      return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
    };
    dependencies.invite_join_attempt_transport =
        [issued](std::string_view, uint32_t)
        -> std::optional<DirectoryInviteJoinAttempt> { return issued; };
    dependencies.join_attempt_completion_transport =
        [&](const DirectoryTraversalAttempt&) { ++releases; };
    dependencies.configured_invite_stage_observer =
        [&](ConfiguredInviteStage stage,
            const ConfiguredInviteOperationIdentity&) {
      if (stage == target)
        target_gate.ArriveAndWait();
      if (stage == ConfiguredInviteStage::kCancellationVisible &&
          !cancellation_signaled.exchange(true))
        cancellation_visible.set_value();
    };
    SessionManager manager(nullptr, manager_port, std::move(dependencies));
    manager.OnTitleTransition(kTitle);
    REQUIRE(target_gate.WaitUntilEntered());
    auto cancel = std::async(std::launch::async,
                             [&] { manager.OnTitleTermination(); });
    REQUIRE(cancellation_future.wait_for(std::chrono::seconds(2)) ==
            std::future_status::ready);
    target_gate.Release();
    REQUIRE(cancel.wait_for(std::chrono::seconds(2)) ==
            std::future_status::ready);
    cancel.get();
    CHECK(network.registrations.load() >=
          (target == ConfiguredInviteStage::kBeforeSocketSetup ? 0u : 1u));
    CHECK(network.discovery_queries.load() == expected_queries);
    CHECK(releases.load() == 1);
    CHECK_FALSE(manager.discovery().HasClientAdmission(0));
  };

  SECTION("cancellation before socket setup") {
    run_boundary(ConfiguredInviteStage::kBeforeSocketSetup, 39305, 39315,
                 39316, 0);
  }
  SECTION("cancellation before first discovery send") {
    run_boundary(ConfiguredInviteStage::kBeforeFirstDiscoverySend, 39306,
                 39317, 39318, 0);
  }
  SECTION("cancellation during discovery wait") {
    run_boundary(ConfiguredInviteStage::kDiscoveryWaiting, 39307, 39319,
                 39320, 1);
  }
  SECTION("cancellation before discovery retry") {
    run_boundary(ConfiguredInviteStage::kBeforeDiscoveryRetry, 39308, 39321,
                 39322, 1);
  }
}

TEST_CASE("post-attempt bind failure releases only its exact configured attempt",
          "[session][configured-invite][race][cleanup]") {
  ConfiguredInviteCvarFixture cvars;
  REXCVAR_SET(lan_bind_address, "203.0.113.1");
  auto issued = ConfiguredAttempt(39323, 39324);
  std::atomic<uint32_t> releases = 0;
  std::promise<void> cleanup_complete;
  auto cleanup_future = cleanup_complete.get_future();
  std::atomic<bool> cleanup_signaled = false;
  SessionManagerDependencies dependencies;
  dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
    return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
  };
  dependencies.invite_join_attempt_transport =
      [issued](std::string_view, uint32_t)
      -> std::optional<DirectoryInviteJoinAttempt> { return issued; };
  dependencies.join_attempt_completion_transport =
      [&](const DirectoryTraversalAttempt& attempt) {
    CHECK(attempt.attempt_id == kAttempt);
    ++releases;
  };
  dependencies.configured_invite_stage_observer =
      [&](ConfiguredInviteStage stage, const ConfiguredInviteOperationIdentity&) {
    if (stage == ConfiguredInviteStage::kCleanupComplete &&
        !cleanup_signaled.exchange(true))
      cleanup_complete.set_value();
  };
  SessionManager manager(nullptr, 39309, std::move(dependencies));
  manager.OnTitleTransition(kTitle);
  REQUIRE(cleanup_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  CHECK(manager.configured_invite_state() ==
        ConfiguredInviteLifecycleState::kFailed);
  CHECK(releases.load() == 1);
  CHECK_FALSE(manager.discovery().HasClientAdmission(0));
  manager.OnTitleTermination();
  manager.OnTitleTermination();
  manager.ShutdownAsyncActivity();
  CHECK(releases.load() == 1);
}

TEST_CASE("configured invite reaches immutable READY result using its own endpoint",
          "[session][configured-invite][ready][network][accepted-invite]") {
  ConfiguredInviteCvarFixture cvars;
  bool use_lan = false;
  bool one_listener = false;
  bool no_listener = false;
  bool failed_join = false;
  SECTION("public NAT route") {}
  SECTION("same-LAN route without public ACK") { use_lan = true; }
  SECTION("main-menu listener receives native invite before Online opens") {
    use_lan = true;
    one_listener = true;
  }
  SECTION("READY waits without a live invite listener") {
    use_lan = true;
    no_listener = true;
  }
  SECTION("failed downstream join does not notify the same invite twice") {
    use_lan = true;
    one_listener = true;
    failed_join = true;
  }
  constexpr uint16_t rendezvous_port = 39325;
  constexpr uint16_t peer_port = 39326;
  auto issued = ConfiguredAttempt(rendezvous_port, peer_port);
  auto advertised = CorrelatedSession(
      issued, {htonl(INADDR_LOOPBACK), peer_port});
  ConfiguredInviteNetworkFixture network(rendezvous_port, peer_port, advertised,
                                         true, !use_lan, use_lan);
  StageBarrier issued_gate;
  std::promise<void> ready_signal;
  auto ready_future = ready_signal.get_future();
  std::promise<void> published_signal;
  auto published_future = published_signal.get_future();
  std::atomic<bool> ready_signaled = false;
  std::atomic<uint32_t> notifications = 0;
  std::atomic<bool> registry_present_at_notify = false;
  std::atomic<bool> record_present_at_notify = false;
  SessionManager* manager_ptr = nullptr;
  std::atomic<uint32_t> admission_calls = 0;
  std::atomic<uint64_t> revision = 1;
  SessionManagerDependencies dependencies;
  if (use_lan) {
    dependencies.configured_invite_discovery =
        [](LanDiscoveryService& discovery,
                    const DirectoryInviteJoinAttempt& attempt, uint32_t timeout_ms,
                    const std::function<bool()>& current,
                    const std::function<void(ConfiguredInviteStage)>& observe) {
          return discovery.DiscoverConfiguredInvite(
              attempt, timeout_ms, current, observe,
              {htonl(INADDR_LOOPBACK), peer_port});
        };
  }
  dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
    return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
  };
  dependencies.current_title_id = [] { return kTitle; };
  dependencies.accepting_listener_count = [one_listener, no_listener](uint32_t id) {
    return id == kXnLiveInviteAccepted ? (no_listener ? size_t{0} :
                                          one_listener ? size_t{1} : size_t{2})
                                          : size_t{0};
  };
  dependencies.broadcast_notification = [&](uint32_t id, uint32_t data) {
    if (id == kXnLiveInviteAccepted && data == 0 && manager_ptr) {
      registry_present_at_notify = bool(manager_ptr->registry().Find(advertised.info.id));
      record_present_at_notify = bool(manager_ptr->accepted_invites().Snapshot(0));
      if (++notifications == 1)
        published_signal.set_value();
      return one_listener ? size_t{1} : size_t{2};
    }
    return size_t{0};
  };
  dependencies.invite_join_attempt_transport =
      [issued](std::string_view, uint32_t)
      -> std::optional<DirectoryInviteJoinAttempt> { return issued; };
  dependencies.client_admission_transport =
      [&](const ClientAdmissionTransportRequest& request) {
    ++admission_calls;
    if (request.action == ClientAdmissionTransportAction::kArm)
      return AdmissionHttp(AdmissionBody(1, false, failed_join ? 6000 : 59000),
                           request.request_started_at);
    if (request.action == ClientAdmissionTransportAction::kRenew) {
      const auto next = ++revision;
      return AdmissionHttp(AdmissionBody(next, !failed_join,
                                         failed_join ? 6000 : 59000),
                           request.request_started_at);
    }
    if (request.action == ClientAdmissionTransportAction::kStatus)
      return AdmissionHttp(AdmissionBody(revision.load(), true,
                                         failed_join ? 6000 : 59000),
                           request.request_started_at);
    return AdmissionHttp("", request.request_started_at, 204);
  };
  dependencies.configured_invite_stage_observer =
      [&](ConfiguredInviteStage stage, const ConfiguredInviteOperationIdentity&) {
    if (stage == ConfiguredInviteStage::kAttemptIssued)
      issued_gate.ArriveAndWait();
    if (stage == ConfiguredInviteStage::kReadyForAcceptedInvite &&
        !ready_signaled.exchange(true))
      ready_signal.set_value();
  };
  SessionManager manager(nullptr, 39310, std::move(dependencies));
  manager_ptr = &manager;
  manager.OnTitleTransition(kTitle);
  REQUIRE(issued_gate.WaitUntilEntered());

  // These mutable public Search selectors must not redirect the claimed invite.
  REXCVAR_SET(session_directory_candidate_type, "tailscale");
  REXCVAR_SET(session_directory_session_index, 77u);
  REXCVAR_SET(direct_connect_address, "192.0.2.77");
  issued_gate.Release();
  REQUIRE(ready_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  if (no_listener) {
    CHECK(published_future.wait_for(std::chrono::milliseconds(100)) ==
          std::future_status::timeout);
    CHECK(manager.configured_invite_state() ==
          ConfiguredInviteLifecycleState::kReadyForAcceptedInvite);
    CHECK_FALSE(manager.accepted_invites().Snapshot(0));
    CHECK(notifications.load() == 0);
    manager.OnTitleTermination();
    manager.ShutdownAsyncActivity();
    return;
  }
  REQUIRE(published_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  auto ready = manager.ready_configured_invite();
  REQUIRE(ready);
  CHECK(manager.configured_invite_state() ==
        ConfiguredInviteLifecycleState::kPublished);
  CHECK(registry_present_at_notify.load());
  CHECK(record_present_at_notify.load());
  CHECK(notifications.load() == 1);
  auto accepted = manager.accepted_invites().Acquire(0, kTitle);
  REQUIRE(accepted);
  REQUIRE(SerializeAcceptedInviteRecord(*ready));
  CHECK(accepted->record() == *SerializeAcceptedInviteRecord(*ready));
  accepted.reset();
  CHECK(ready->operation.title_id == kTitle);
  CHECK(ready->operation.local_user_index == 0);
  CHECK(ready->operation.local_xuid == kLocalXuid);
  CHECK(ready->operation.invite_code == "ABC234");
  CHECK(ready->directory_session_id == issued.attempt.session_id);
  CHECK(ready->directory_attempt_id == issued.attempt.attempt_id);
  CHECK(ready->host_ready);
  CHECK(ready->private_allocation_eligible);
  CHECK(ready->client_admission_lifecycle_token != 0);
  CHECK(ready->xbox_session_id == advertised.info.id);
  CHECK(ready->host_xuid == advertised.host_xuid);
  CHECK(ready->exchange_key == advertised.info.key);
  CHECK(ready->host_endpoint ==
        LanAddress{htonl(INADDR_LOOPBACK), uint16_t(30742)});
  CHECK(ready->discovery_endpoint ==
        LanAddress{htonl(INADDR_LOOPBACK), peer_port});
  CHECK(ready->xnaddr == ReconstructXnAddrIdentity(advertised.host_xuid));
  CHECK(ready->xnaddr.ethernet_address ==
        advertised.info.ethernet_address);
  CHECK(ready->xnaddr.online_address == advertised.info.online_address);
  // The LAN advertisement format intentionally does not carry the host nonce.
  CHECK(ready->nonce == 0);
  if (failed_join) {
    // XGI deletes its client session object after a failed downstream join.
    // The invite was already delivered; a healthy lease must not notify again.
    REQUIRE(manager.GetAcceptedInviteRecord(0, kTitle));
    manager.registry().Delete(advertised.info.id);
    CHECK_FALSE(manager.accepted_invites().Snapshot(0));
    const auto deadline = Clock::now() + std::chrono::seconds(10);
    while (Clock::now() < deadline && revision.load() == 1)
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    REQUIRE(revision.load() >= 2);
    while (Clock::now() < deadline &&
           manager.configured_invite_state() !=
               ConfiguredInviteLifecycleState::kPublished &&
           notifications.load() == 1)
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    CHECK(manager.configured_invite_state() ==
          ConfiguredInviteLifecycleState::kPublished);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    CHECK(notifications.load() == 1);
    CHECK_FALSE(manager.accepted_invites().Snapshot(0));
  }
  CHECK(network.discovery_queries.load() >= 1);
  CHECK(admission_calls.load() >= 2);
  manager.ShutdownAsyncActivity();
  CHECK_FALSE(manager.ready_configured_invite());
}

TEST_CASE("lease renewal cancellation rejects the in-flight late callback",
          "[session][configured-invite][race][lease]") {
  ConfiguredInviteCvarFixture cvars;
  constexpr uint16_t rendezvous_port = 39327;
  constexpr uint16_t peer_port = 39328;
  auto issued = ConfiguredAttempt(rendezvous_port, peer_port);
  auto advertised = CorrelatedSession(
      issued, {htonl(INADDR_LOOPBACK), peer_port});
  ConfiguredInviteNetworkFixture network(rendezvous_port, peer_port, advertised);
  StageBarrier renewal_gate;
  std::promise<void> ready_signal;
  auto ready_future = ready_signal.get_future();
  std::promise<void> cancellation_visible;
  auto cancellation_future = cancellation_visible.get_future();
  std::atomic<bool> ready_signaled = false;
  std::atomic<bool> cancellation_signaled = false;
  std::atomic<uint32_t> renewals = 0;
  auto lease_body = [](uint64_t revision, bool ready) {
    return nlohmann::json{
        {"attempt_id", kAttempt},
        {"purpose", "invite_code_private_eligible"},
        {"phase", ready ? "admission_ready" : "admission_awaiting_host"},
        {"admission_generation", kGeneration},
        {"lease_revision", revision},
        {"admission_lease_duration_ms", 300},
        {"admission_expires_in_ms", 300},
        {"host_ready", ready}}
        .dump();
  };
  SessionManagerDependencies dependencies;
  dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
    return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
  };
  dependencies.invite_join_attempt_transport =
      [issued](std::string_view, uint32_t)
      -> std::optional<DirectoryInviteJoinAttempt> { return issued; };
  dependencies.client_admission_transport =
      [&](const ClientAdmissionTransportRequest& request) {
    if (request.action == ClientAdmissionTransportAction::kArm)
      return AdmissionHttp(lease_body(1, false), request.request_started_at);
    if (request.action == ClientAdmissionTransportAction::kRenew) {
      ++renewals;
      renewal_gate.ArriveAndWait();
      return AdmissionHttp(lease_body(2, true), request.request_started_at);
    }
    if (request.action == ClientAdmissionTransportAction::kStatus)
      return AdmissionHttp(lease_body(1, true), request.request_started_at);
    return AdmissionHttp("", request.request_started_at, 204);
  };
  dependencies.configured_invite_stage_observer =
      [&](ConfiguredInviteStage stage, const ConfiguredInviteOperationIdentity&) {
    if (stage == ConfiguredInviteStage::kReadyForAcceptedInvite &&
        !ready_signaled.exchange(true))
      ready_signal.set_value();
    if (stage == ConfiguredInviteStage::kCancellationVisible &&
        !cancellation_signaled.exchange(true))
      cancellation_visible.set_value();
  };
  SessionManager manager(nullptr, 39311, std::move(dependencies));
  manager.OnTitleTransition(kTitle);
  REQUIRE(ready_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  REQUIRE(renewal_gate.WaitUntilEntered());
  CHECK(renewals.load() == 1);
  auto shutdown = std::async(std::launch::async,
                             [&] { manager.ShutdownAsyncActivity(); });
  REQUIRE(cancellation_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  renewal_gate.Release();
  REQUIRE(shutdown.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  shutdown.get();
  CHECK_FALSE(manager.ready_configured_invite());
  CHECK_FALSE(manager.discovery().HasClientAdmission(0));
  CHECK(renewals.load() == 1);
}

TEST_CASE("lease expiry wins over a late exact response",
          "[session][configured-invite][race][lease]") {
  const auto start = Clock::now();
  ClientAdmissionLeaseState state;
  auto attempt = InviteAttempt();
  auto exact = ExactDiscovery();
  REQUIRE(state.BindExactDiscovery(kUser, kToken, kTitle, kLocalXuid,
                                   attempt, exact));
  auto short_lease = Admission(1, false, 5);
  REQUIRE(ApplyArm(state, short_lease, start) ==
          ClientAdmissionApplyResult::kApplied);
  auto status = Begin(state, start + std::chrono::milliseconds(1));
  REQUIRE(status.action == ClientAdmissionAction::kStatus);
  auto ready = Admission(1, true, 5);
  CHECK(state.ApplyResponse(status, ready,
                            start + std::chrono::milliseconds(6)) ==
        ClientAdmissionApplyResult::kInvalidated);
  CHECK_FALSE(state.bound());
  CHECK_FALSE(state.ReadyCandidate(kTitle, kLocalXuid,
                                   start + std::chrono::milliseconds(6)));
}

TEST_CASE("stale discovery callback cannot alter a newer configured operation",
          "[session][configured-invite][race][stale]") {
  ConfiguredInviteCvarFixture cvars;
  StageBarrier first_callback;
  StageBarrier second_callback;
  std::promise<void> first_cancelled;
  auto first_cancelled_future = first_cancelled.get_future();
  std::promise<void> second_cancelled;
  auto second_cancelled_future = second_cancelled.get_future();
  std::atomic<uint32_t> cancellation_count = 0;
  std::atomic<uint32_t> issued_count = 0;
  std::atomic<uint32_t> discovery_count = 0;
  std::atomic<uint32_t> released_count = 0;
  std::vector<uint64_t> operation_tokens;
  std::mutex tokens_mutex;
  SessionManagerDependencies dependencies;
  dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
    return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
  };
  dependencies.invite_join_attempt_transport =
      [&](std::string_view, uint32_t title_id)
      -> std::optional<DirectoryInviteJoinAttempt> {
    auto value = ConfiguredAttempt();
    value.session.title_id = title_id;
    if (++issued_count == 2) {
      value.attempt.session_id = "session-b";
      value.session.session_id = "session-b";
      value.attempt.attempt_id = "11112222333344445555666677778888";
      value.attempt.capability = "88887777666655554444333322221111";
    }
    return value;
  };
  dependencies.join_attempt_completion_transport =
      [&](const DirectoryTraversalAttempt&) { ++released_count; };
  dependencies.configured_invite_discovery =
      [&](LanDiscoveryService&, const DirectoryInviteJoinAttempt& value, uint32_t,
          const std::function<bool()>&,
          const std::function<void(ConfiguredInviteStage)>&)
      -> std::optional<ConfiguredInviteDiscoveryResult> {
    const auto call = ++discovery_count;
    if (call == 1)
      first_callback.ArriveAndWait();
    else
      second_callback.ArriveAndWait();
    return ConfiguredInviteDiscoveryResult{
        CorrelatedSession(value, {htonl(INADDR_LOOPBACK), 39329}), 0};
  };
  dependencies.configured_invite_stage_observer =
      [&](ConfiguredInviteStage stage,
          const ConfiguredInviteOperationIdentity& identity) {
    if (stage == ConfiguredInviteStage::kAttemptIssued) {
      std::lock_guard lock(tokens_mutex);
      operation_tokens.push_back(identity.operation_token);
    }
    if (stage == ConfiguredInviteStage::kCancellationVisible) {
      const auto count = ++cancellation_count;
      if (count == 1)
        first_cancelled.set_value();
      else if (count == 2)
        second_cancelled.set_value();
    }
  };
  SessionManager manager(nullptr, 39312, std::move(dependencies));
  manager.OnTitleTransition(kTitle);
  REQUIRE(first_callback.WaitUntilEntered());
  auto replace = std::async(std::launch::async,
                            [&] { manager.OnTitleTransition(kTitle + 1); });
  REQUIRE(first_cancelled_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  first_callback.Release();
  REQUIRE(second_callback.WaitUntilEntered());
  {
    std::lock_guard lock(tokens_mutex);
    REQUIRE(operation_tokens.size() == 2);
    CHECK(operation_tokens[0] != operation_tokens[1]);
  }
  CHECK(manager.configured_invite_state() ==
        ConfiguredInviteLifecycleState::kAttemptIssued);
  CHECK_FALSE(manager.ready_configured_invite());
  auto terminate = std::async(std::launch::async,
                              [&] { manager.OnTitleTermination(); });
  REQUIRE(second_cancelled_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  second_callback.Release();
  REQUIRE(terminate.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  terminate.get();
  REQUIRE(replace.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  replace.get();
  CHECK(released_count.load() == 2);
  CHECK_FALSE(manager.ready_configured_invite());
}

TEST_CASE("shutdown joins an active configured invite worker exactly once",
          "[session][configured-invite][race][shutdown]") {
  ConfiguredInviteCvarFixture cvars;
  StageBarrier worker_gate;
  std::promise<void> cancellation_visible;
  auto cancellation_future = cancellation_visible.get_future();
  std::atomic<bool> cancellation_signaled = false;
  std::atomic<uint32_t> attempts = 0;
  SessionManagerDependencies dependencies;
  dependencies.user_identity = [](uint32_t user) -> std::optional<uint64_t> {
    return user == 0 ? std::optional<uint64_t>(kLocalXuid) : std::nullopt;
  };
  dependencies.invite_join_attempt_transport =
      [&](std::string_view, uint32_t)
      -> std::optional<DirectoryInviteJoinAttempt> {
    ++attempts;
    return std::nullopt;
  };
  dependencies.configured_invite_stage_observer =
      [&](ConfiguredInviteStage stage, const ConfiguredInviteOperationIdentity&) {
    if (stage == ConfiguredInviteStage::kWorkerStarted)
      worker_gate.ArriveAndWait();
    if (stage == ConfiguredInviteStage::kCancellationVisible &&
        !cancellation_signaled.exchange(true))
      cancellation_visible.set_value();
  };
  SessionManager manager(nullptr, 39313, std::move(dependencies));
  manager.OnTitleTransition(kTitle);
  REQUIRE(worker_gate.WaitUntilEntered());
  auto shutdown = std::async(std::launch::async,
                             [&] { manager.ShutdownAsyncActivity(); });
  REQUIRE(cancellation_future.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  worker_gate.Release();
  REQUIRE(shutdown.wait_for(std::chrono::seconds(2)) ==
          std::future_status::ready);
  shutdown.get();
  manager.ShutdownAsyncActivity();
  CHECK(attempts.load() == 0);
  CHECK_FALSE(manager.ready_configured_invite());
}

}  // namespace
}  // namespace rex::system::xam
