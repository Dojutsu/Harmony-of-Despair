#include "legacy_lan_diagnostics_scope.h"
#include <catch2/catch_test_macros.hpp>

#include <array>
#include <barrier>
#include <chrono>
#include <cstring>
#include <limits>
#include <cstdio>
#include <memory>
#include <thread>

#include <inja/third_party/include/nlohmann/json.hpp>

#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#if REX_PLATFORM_LINUX
#include <dlfcn.h>
#endif
#endif

#include <rex/system/xam/nat_probe.h>
#include <rex/system/xam/session.h>
#include <rex/system/xam/session_arbitration_crypto.h>
#include <rex/cvar.h>

namespace rex::system::xam {
namespace {
using Clock = HostAdmissionGrantStore::Clock;

constexpr std::string_view kAttemptA = "00112233445566778899aabbccddeeff";
constexpr std::string_view kAttemptB = "102132435465768798a9bacbdcedfe0f";
constexpr std::string_view kAttemptC = "2031425364758697a8b9cadbecfd0e1f";
constexpr std::string_view kCapability = "ffeeddccbbaa99887766554433221100";
constexpr std::string_view kGeneration = "0123456789abcdef0123456789abcdef";

HostAdmissionPollAttempt PrivateAttempt(std::string_view attempt = kAttemptA, uint64_t revision = 1,
                                        uint32_t lifetime_ms = 1000) {
  return {std::string(attempt),
          std::string(kCapability),
          "invite_code_private_eligible",
          std::string(kGeneration),
          revision,
          lifetime_ms,
          true};
}

DirectoryTraversalAttempt TraversalAttempt(std::string_view attempt = kAttemptA,
                                            uint64_t revision = 1,
                                            uint32_t lifetime_ms = 1000) {
  return {"session-a",
          std::string(attempt),
          std::string(kCapability),
          "127.0.0.1",
          30740,
          0,
          "invite_code_private_eligible",
          std::string(kGeneration),
          revision,
          lifetime_ms,
          true};
}

nlohmann::json PollSnapshotDocument(nlohmann::json lifetime) {
  return {{"attempts",
           nlohmann::json::array(
               {{{"attempt_id", kAttemptA},
                 {"capability", kCapability},
                 {"rendezvous_host", "127.0.0.1"},
                 {"rendezvous_port", 30740},
                 {"participant", "host"},
                 {"purpose", "invite_code_private_eligible"},
                 {"admission_generation", kGeneration},
                 {"lease_revision", 1},
                 {"admission_expires_in_ms", std::move(lifetime)},
                 {"host_ready", true}}})}};
}

void Install(HostAdmissionGrantStore& store, Clock::time_point now,
             HostAdmissionPollAttempt attempt = PrivateAttempt()) {
  std::array attempts{std::move(attempt)};
  store.ApplyAuthenticatedPoll("session-a", attempts, now);
}

HostAdmissionReservationResult Reserve(HostAdmissionGrantStore& store, uint64_t xuid,
                                       Clock::time_point now,
                                       std::string_view session = "session-a", uint64_t socket = 41,
                                       uint32_t ipv4 = 0x01020304, uint16_t port = 40000,
                                       std::span<const std::string> attempts = {}) {
  std::array default_attempts{std::string(kAttemptA)};
  if (attempts.empty())
    attempts = default_attempts;
  return store.Reserve(session, socket, ipv4, port, attempts, xuid, now);
}

SessionMember Member(uint64_t xuid, bool private_slot = false) {
  return {xuid, "Player" + std::to_string(xuid), 0, false, private_slot, false};
}

#pragma pack(push, 1)
struct NatPacket {
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
#pragma pack(pop)
static_assert(sizeof(NatPacket) == 56);

uint8_t HexDigit(char value) {
  return uint8_t(value <= '9' ? value - '0' : value - 'a' + 10);
}

void ParseHex(std::string_view value, uint8_t* output) {
  for (size_t i = 0; i < 16; ++i)
    output[i] = uint8_t((HexDigit(value[i * 2]) << 4) | HexDigit(value[i * 2 + 1]));
}

NatPacket Registered(std::string_view attempt, LanAddress peer,
                     NatProbeRole role = NatProbeRole::kDiscovery) {
  NatPacket packet{};
  std::memcpy(packet.magic, "HNAT", 4);
  packet.version = 1;
  packet.type = 2;
  packet.participant = 0;
  packet.role = uint8_t(role);
  ParseHex(attempt, packet.attempt);
  ParseHex(kCapability, packet.credential);
  packet.observed_ipv4 = htonl(0xCB007109u);
  packet.observed_port = htons(35000);
  packet.peer_ipv4 = peer.ipv4;
  packet.peer_port = htons(peer.port);
  return packet;
}

NatPacket Ack(std::string_view attempt, NatProbeRole role = NatProbeRole::kDiscovery) {
  NatPacket packet{};
  std::memcpy(packet.magic, "HNAT", 4);
  packet.version = 1;
  packet.type = 4;
  packet.participant = 1;
  packet.role = uint8_t(role);
  ParseHex(attempt, packet.attempt);
  return packet;
}

NatPacket Punch(std::string_view attempt, NatProbeRole role = NatProbeRole::kDiscovery) {
  auto packet = Ack(attempt, role);
  packet.type = 3;
  return packet;
}

struct NatFixture {
  std::vector<std::string> attempts;
  std::vector<uint64_t> sockets;
  ~NatFixture() {
    for (auto socket : sockets)
      NatProbeDetach(socket);
    for (const auto& attempt : attempts)
      NatProbeRetireIdentity(attempt);
  }
  void Add(std::string_view attempt) {
    attempts.emplace_back(attempt);
    REQUIRE(NatProbeInstallIdentity(
        {std::string(attempt), std::string(kCapability), "127.0.0.1", 30740, 0}));
  }
  void Attach(uint64_t socket, NatProbeRole role) {
    sockets.push_back(socket);
    NatProbeAttach(socket, role, {htonl(0x7F000001u), uint16_t(socket)});
  }
  void Acknowledge(uint64_t socket, std::string_view attempt, LanAddress peer,
                   NatProbeRole role = NatProbeRole::kDiscovery) {
    auto registered = Registered(attempt, peer, role);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                            sizeof(registered), htonl(0x7F000001u), 30740));
    auto ack = Ack(attempt, role);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack), sizeof(ack), peer.ipv4,
                            peer.port));
  }
};

using DiscoveryWirePacket = std::array<uint8_t, 640>;

void PutBigEndian(DiscoveryWirePacket& packet, size_t offset, uint64_t value, size_t width = 4) {
  for (size_t index = 0; index < width; ++index)
    packet[offset + index] = uint8_t(value >> (8 * (width - index - 1)));
}

#if REX_PLATFORM_WIN32
using TestSocket = SOCKET;
constexpr TestSocket kBadSocket = INVALID_SOCKET;
#else
using TestSocket = int;
constexpr TestSocket kBadSocket = -1;
#endif

struct SocketFixture {
  TestSocket socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  ~SocketFixture() {
#if REX_PLATFORM_WIN32
    if (socket != kBadSocket)
      closesocket(socket);
#else
    if (socket != kBadSocket)
      close(socket);
#endif
  }
};

struct DirectoryDisabled {
  std::string previous = REXCVAR_GET(session_directory_url);
  DirectoryDisabled() { REXCVAR_SET(session_directory_url, ""); }
  ~DirectoryDisabled() { REXCVAR_SET(session_directory_url, previous); }
};

LanAddress BindLoopback(TestSocket socket) {
  sockaddr_in local{};
  local.sin_family = AF_INET;
  local.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  local.sin_port = 0;
  REQUIRE(bind(socket, reinterpret_cast<sockaddr*>(&local), sizeof(local)) == 0);
#if REX_PLATFORM_WIN32
  int length = sizeof(local);
#else
  socklen_t length = sizeof(local);
#endif
  REQUIRE(getsockname(socket, reinterpret_cast<sockaddr*>(&local), &length) == 0);
  return {local.sin_addr.s_addr, ntohs(local.sin_port)};
}

void SendNatControl(TestSocket socket, uint16_t port, const NatPacket& packet) {
  sockaddr_in target{};
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  target.sin_port = htons(port);
  REQUIRE(sendto(socket, reinterpret_cast<const char*>(&packet), sizeof(packet), 0,
                 reinterpret_cast<sockaddr*>(&target), sizeof(target)) == sizeof(packet));
}

void AcknowledgeHostAttempt(TestSocket socket, uint16_t host_port, std::string_view attempt,
                            LanAddress peer) {
  SendNatControl(socket, host_port, Registered(attempt, peer));
  SendNatControl(socket, host_port, Ack(attempt));
}

bool TransferDiscovery(TestSocket socket, uint16_t port, const DiscoveryWirePacket& packet) {
  sockaddr_in target{};
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  target.sin_port = htons(port);
  if (sendto(socket, reinterpret_cast<const char*>(packet.data()), int(packet.size()), 0,
             reinterpret_cast<sockaddr*>(&target), sizeof(target)) != int(packet.size()))
    return false;
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(150);
  while (std::chrono::steady_clock::now() < deadline) {
    fd_set sockets;
    FD_ZERO(&sockets);
    FD_SET(socket, &sockets);
    const auto remaining = std::chrono::duration_cast<std::chrono::microseconds>(
        deadline - std::chrono::steady_clock::now());
    timeval timeout{long(remaining.count() / 1000000), long(remaining.count() % 1000000)};
    if (select(int(socket) + 1, &sockets, nullptr, nullptr, &timeout) <= 0)
      return false;
    DiscoveryWirePacket response{};
    const int received = recvfrom(socket, reinterpret_cast<char*>(response.data()),
                                  int(response.size()), 0, nullptr, nullptr);
    if (received == int(response.size()))
      return true;
    // NAT punch/ack control can be queued ahead of the discovery response.
  }
  return false;
}

DiscoveryWirePacket JoinPacket(const SessionRecord& session, uint32_t title_id, uint64_t xuid,
                               bool private_slot) {
  DiscoveryWirePacket packet{};
  PutBigEndian(packet, 0, 0x5245584Cu);
  PutBigEndian(packet, 4, 2, 2);
  packet[6] = 3;
  PutBigEndian(packet, 8, title_id);
  std::memcpy(packet.data() + 12, session.info.id.data(), 8);
  std::memcpy(packet.data() + 20, session.info.key.data(), 16);
  PutBigEndian(packet, 36, session.host_xuid, 8);
  PutBigEndian(packet, 436, session.nonce, 8);
  PutBigEndian(packet, 444, session.host_machine_id, 8);
  std::copy(session.arbitration_incarnation.begin(), session.arbitration_incarnation.end(),packet.begin()+452);
  PutBigEndian(packet, 64, 1);
  PutBigEndian(packet, 84, xuid, 8);
  PutBigEndian(packet, 92, private_slot ? 2 : 0);
  std::memcpy(packet.data() + 96, "WirePlayer", 10);
  PutBigEndian(packet, 112, 0x100000000ull+xuid, 8);
  PutBigEndian(packet, 124, 3074, 2);
  PutBigEndian(packet, 468, 0x200000000ull+xuid, 8);
  PutBigEndian(packet,624,0x300000000ull+xuid,8);
  const auto key=NewArbitrationKey(); REQUIRE(key);
  std::copy(key->public_key().begin(),key->public_key().end(),packet.begin()+532);
  return packet;
}
}  // namespace

TEST_CASE("authenticated poll installs only current private-ready grants",
          "[session][invite-grant]") {
  const auto now = Clock::time_point{} + std::chrono::seconds(10);
  HostAdmissionGrantStore store;
  Install(store, now);
  CHECK(store.available_grant_count(now) == 1);

  SECTION("public and unknown purposes fail closed") {
    auto public_attempt = PrivateAttempt();
    public_attempt.purpose = "public";
    Install(store, now, public_attempt);
    CHECK(store.available_grant_count(now) == 0);
    auto unknown = PrivateAttempt(kAttemptB);
    unknown.purpose = "future_private";
    Install(store, now, unknown);
    CHECK(store.available_grant_count(now) == 0);
  }
  SECTION("not-ready and terminal snapshots invalidate") {
    auto not_ready = PrivateAttempt();
    not_ready.host_ready = false;
    Install(store, now, not_ready);
    CHECK(store.available_grant_count(now) == 0);
    Install(store, now);
    store.ApplyAuthenticatedPoll("session-a", std::span<const HostAdmissionPollAttempt>{}, now);
    CHECK(store.available_grant_count(now) == 0);
  }
  SECTION("stale and skipped revisions cannot replace current state") {
    Install(store, now, PrivateAttempt(kAttemptA, 2, 500));
    Install(store, now, PrivateAttempt(kAttemptA, 1, 100000));
    CHECK(store.available_grant_count(now + std::chrono::milliseconds(600)) == 0);
    store.Clear();
    Install(store, now);
    Install(store, now, PrivateAttempt(kAttemptA, 3, 100000));
    CHECK(store.available_grant_count(now + std::chrono::milliseconds(1100)) == 0);
  }
  SECTION("generation mismatch cannot replace current state") {
    auto mismatch = PrivateAttempt();
    mismatch.admission_generation = "1123456789abcdef0123456789abcdef";
    mismatch.admission_expires_in_ms = 100000;
    Install(store, now, mismatch);
    CHECK(store.available_grant_count(now + std::chrono::milliseconds(1100)) == 0);
  }
  SECTION("server lifetime is an upper bound") {
    CHECK(store.available_grant_count(now + std::chrono::milliseconds(999)) == 1);
    CHECK(store.available_grant_count(now + std::chrono::milliseconds(1000)) == 0);
  }
}

TEST_CASE("poll authority distinguishes transit failure 404 and request time",
          "[session][invite-grant][directory]") {
  const auto poll_started = Clock::time_point{} + std::chrono::seconds(100);
  const auto response_received = poll_started + std::chrono::seconds(4);
  auto grants = std::make_shared<HostAdmissionGrantStore>();
  std::array initial_grants{PrivateAttempt(kAttemptA, 1, 10000),
                            PrivateAttempt(kAttemptB, 1, 10000)};
  grants->ApplyAuthenticatedPoll("session-a", initial_grants, poll_started);

  NatFixture nat;
  nat.Add(kAttemptA);
  nat.Add(kAttemptB);
  constexpr uint64_t socket = 42301;
  nat.Attach(socket, NatProbeRole::kDiscovery);
  const LanAddress peer{htonl(0xCB007160u), 46500};
  nat.Acknowledge(socket, kAttemptA, peer);

  DirectoryHostPollRuntimeState state;
  state.directory_session_id = "session-a";
  state.registration_token = "stale-registration-token";
  state.public_invite_code = "ABCDEF";
  state.host_attempts = {std::string(kAttemptA), std::string(kAttemptB)};
  state.private_attempts.emplace(kAttemptA, initial_grants[0]);
  state.private_attempts.emplace(kAttemptB, initial_grants[1]);
  state.pending_completions.push_back(
      {"session-a", std::string(kAttemptB), std::string(kCapability)});
  SessionRecord hosted;
  hosted.SetStatusInviteCode("ABCDEF");

  std::array acknowledged_b{std::string(kAttemptB)};
  auto completed = grants->Reserve("session-a", 99, 0x01020304, 40000,
                                   acknowledged_b, 20, poll_started);
  REQUIRE(completed.status == HostAdmissionReservationStatus::kReserved);
  grants->Finish(completed.reservation, true, poll_started);

  const auto transport = ClassifyDirectoryHostPollResponse(std::nullopt, false);
  REQUIRE(transport == DirectoryHostPollDisposition::kRetainUntilExpiry);
  auto retained = ApplyDirectoryHostPollResult(
      transport, {}, state, grants.get(), hosted, response_received);
  CHECK_FALSE(retained.recover_now);
  CHECK_FALSE(state.recovering);
  CHECK(state.directory_session_id == "session-a");
  CHECK(state.pending_completions.size() == 1);
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, peer) ==
        std::vector<std::string>{std::string(kAttemptA)});
  CHECK(grants->available_grant_count(response_received) == 1);
  CHECK(grants->available_grant_count(poll_started + std::chrono::milliseconds(9999)) == 1);
  CHECK(grants->available_grant_count(poll_started + std::chrono::seconds(10)) == 0);

  const auto missing = ClassifyDirectoryHostPollResponse(404, false);
  REQUIRE(missing == DirectoryHostPollDisposition::kRecoverRegistration);
  auto recovery = ApplyDirectoryHostPollResult(
      missing, {}, state, grants.get(), hosted, response_received);
  CHECK(recovery.recover_now);
  CHECK(state.recovering);
  CHECK(state.directory_session_id.empty());
  CHECK(state.registration_token.empty());
  CHECK(state.public_invite_code.empty());
  CHECK(state.host_attempts.empty());
  CHECK(state.private_attempts.empty());
  CHECK(state.pending_completions.empty());
  CHECK(hosted.status_invite_code.empty());
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, peer).empty());
  CHECK(Reserve(*grants, 10, response_received).status ==
        HostAdmissionReservationStatus::kNoMatch);
  CHECK_FALSE(grants->hosted_directory_session());
  CHECK(grants->TakeCompletions().empty());

  // A recovered registration starts with a new authoritative snapshot and a
  // genuinely new attempt. Neither consumed nor available state from the old
  // registration can reappear implicitly.
  state.directory_session_id = "session-b";
  state.recovering = false;
  auto replacement = TraversalAttempt(kAttemptC, 1, 10000);
  replacement.session_id = "session-b";
  std::array replacement_snapshot{replacement};
  auto accepted = ApplyDirectoryHostPollResult(
      DirectoryHostPollDisposition::kAccepted, replacement_snapshot, state,
      grants.get(), hosted, response_received);
  CHECK_FALSE(accepted.recover_now);
  nat.Add(kAttemptC);
  nat.Acknowledge(socket, kAttemptC, peer);
  auto fresh_matches = NatProbeMatchAcknowledgedDiscoveryAttempts(socket, peer);
  CHECK(fresh_matches == std::vector<std::string>{std::string(kAttemptC)});
  CHECK(Reserve(*grants, 10, response_received, "session-a").status ==
        HostAdmissionReservationStatus::kNoMatch);
  CHECK(Reserve(*grants, 21, response_received, "session-b", socket,
                peer.ipv4, peer.port, fresh_matches)
            .status == HostAdmissionReservationStatus::kReserved);
}

TEST_CASE("poll duration parsing and deadline arithmetic fail closed",
          "[session][invite-grant][directory]") {
  auto parse_lifetime = [](nlohmann::json lifetime) {
    return ParseDirectoryHostPollSnapshot(
        PollSnapshotDocument(std::move(lifetime)).dump(), "session-a");
  };

  REQUIRE(parse_lifetime(10000));
  CHECK_FALSE(parse_lifetime(0));
  CHECK_FALSE(parse_lifetime(uint64_t(UINT32_MAX)));
  CHECK_FALSE(parse_lifetime(uint64_t(UINT32_MAX) + 1));
  CHECK_FALSE(parse_lifetime(-1));
  CHECK_FALSE(parse_lifetime("10000"));

  HostAdmissionGrantStore extreme;
  const auto near_max = Clock::time_point::max() - std::chrono::milliseconds(1000);
  Install(extreme, near_max, PrivateAttempt(kAttemptA, 1, 1001));
  CHECK(extreme.available_grant_count(near_max) == 0);

  HostAdmissionGrantStore exact_safe;
  Install(exact_safe, near_max, PrivateAttempt(kAttemptA, 1, 1000));
  CHECK(exact_safe.available_grant_count(near_max) == 1);
  CHECK(exact_safe.available_grant_count(Clock::time_point::max()) == 0);

  HostAdmissionGrantStore maximum;
  Install(maximum, Clock::time_point{},
          PrivateAttempt(kAttemptA, 1, UINT32_MAX));
  CHECK(maximum.available_grant_count(Clock::time_point{}) == 0);

  HostAdmissionGrantStore malformed_snapshot;
  Install(malformed_snapshot, Clock::time_point{},
          PrivateAttempt(kAttemptA, 1, 1000));
  DirectoryHostPollRuntimeState state;
  state.directory_session_id = "session-a";
  SessionRecord hosted;
  auto malformed = ParseDirectoryHostPollSnapshot(
      PollSnapshotDocument("invalid").dump(), "session-a");
  REQUIRE_FALSE(malformed);
  const auto disposition = ClassifyDirectoryHostPollResponse(200, false);
  REQUIRE(disposition == DirectoryHostPollDisposition::kRejectSnapshot);
  ApplyDirectoryHostPollResult(disposition, {}, state, &malformed_snapshot,
                               hosted, Clock::time_point{});
  CHECK(malformed_snapshot.available_grant_count(Clock::time_point{}) == 0);
}

TEST_CASE("grant reservation is atomic idempotent and consumable once",
          "[session][invite-grant][concurrency]") {
  const auto now = Clock::time_point{} + std::chrono::seconds(20);
  HostAdmissionGrantStore store;
  Install(store, now);

  SECTION("one different-XUID contender wins") {
    std::barrier start(3);
    std::array<HostAdmissionReservationResult, 2> results;
    std::thread first([&] {
      start.arrive_and_wait();
      results[0] = Reserve(store, 10, now);
    });
    std::thread second([&] {
      start.arrive_and_wait();
      results[1] = Reserve(store, 11, now);
    });
    start.arrive_and_wait();
    first.join();
    second.join();
    CHECK((results[0].status == HostAdmissionReservationStatus::kReserved) +
              (results[1].status == HostAdmissionReservationStatus::kReserved) ==
          1);
  }
  SECTION("same identity reuses one reservation") {
    auto first = Reserve(store, 10, now);
    auto duplicate = Reserve(store, 10, now);
    REQUIRE(first.status == HostAdmissionReservationStatus::kReserved);
    CHECK(duplicate.status == HostAdmissionReservationStatus::kDuplicateReservation);
    CHECK(first.reservation.reservation_id == duplicate.reservation.reservation_id);
  }
  SECTION("concurrent duplicate packets share one reservation identity") {
    std::barrier start(3);
    std::array<HostAdmissionReservationResult, 2> results;
    std::thread first([&] {
      start.arrive_and_wait();
      results[0] = Reserve(store, 10, now);
    });
    std::thread second([&] {
      start.arrive_and_wait();
      results[1] = Reserve(store, 10, now);
    });
    start.arrive_and_wait();
    first.join();
    second.join();
    CHECK((results[0].status == HostAdmissionReservationStatus::kReserved) +
              (results[1].status == HostAdmissionReservationStatus::kReserved) ==
          1);
    CHECK(results[0].reservation.reservation_id == results[1].reservation.reservation_id);
  }
  SECTION("capacity failure releases while lease remains live") {
    auto first = Reserve(store, 10, now);
    REQUIRE(first.reservation);
    store.Finish(first.reservation, false, now + std::chrono::milliseconds(10));
    CHECK(Reserve(store, 11, now + std::chrono::milliseconds(11)).status ==
          HostAdmissionReservationStatus::kReserved);
  }
  SECTION("reservation pins nominal expiry through synchronous commit") {
    auto first = Reserve(store, 10, now);
    REQUIRE(first.reservation);
    store.Finish(first.reservation, true, now + std::chrono::seconds(2));
    CHECK(Reserve(store, 11, now + std::chrono::seconds(2)).status ==
          HostAdmissionReservationStatus::kNoMatch);
    CHECK(Reserve(store, 10, now + std::chrono::seconds(2)).status ==
          HostAdmissionReservationStatus::kConsumedDuplicate);
    CHECK(store.TakeCompletions().size() == 1);
  }
  SECTION("expiry before reservation rejects") {
    CHECK(Reserve(store, 10, now + std::chrono::seconds(1)).status ==
          HostAdmissionReservationStatus::kNoMatch);
  }
}

TEST_CASE("grant matching fails closed on session and attempt ambiguity",
          "[session][invite-grant][security]") {
  const auto now = Clock::time_point{} + std::chrono::seconds(30);
  HostAdmissionGrantStore store;
  Install(store, now);
  CHECK(Reserve(store, 10, now, "session-b").status == HostAdmissionReservationStatus::kNoMatch);

  std::array two{PrivateAttempt(kAttemptA), PrivateAttempt(kAttemptB)};
  store.ApplyAuthenticatedPoll("session-a", two, now);
  std::array ids{std::string(kAttemptA), std::string(kAttemptB)};
  CHECK(Reserve(store, 10, now, "session-a", 41, 0x01020304, 40000, ids).status ==
        HostAdmissionReservationStatus::kAmbiguous);

  store.Clear();
  Install(store, now);
  store.InvalidateSession("session-a");
  CHECK(store.available_grant_count(now) == 0);
  CHECK_FALSE(store.hosted_directory_session());
}

TEST_CASE("NAT admission correlation requires exact acknowledged discovery endpoint",
          "[session][invite-grant][nat]") {
  NatFixture fixture;
  fixture.Add(kAttemptA);
  constexpr uint64_t discovery_socket = 41001;
  constexpr uint64_t gameplay_socket = 41002;
  fixture.Attach(discovery_socket, NatProbeRole::kDiscovery);
  fixture.Attach(gameplay_socket, NatProbeRole::kGameplay);
  const LanAddress peer{htonl(0xCB007144u), 45000};
  fixture.Acknowledge(discovery_socket, kAttemptA, peer);

  auto exact = NatProbeMatchAcknowledgedDiscoveryAttempts(discovery_socket, peer);
  REQUIRE(exact.size() == 1);
  CHECK(exact.front() == kAttemptA);
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(discovery_socket,
                                                   {peer.ipv4, uint16_t(peer.port + 1)})
            .empty());
  CHECK(
      NatProbeMatchAcknowledgedDiscoveryAttempts(discovery_socket, {htonl(0xCB007145u), peer.port})
          .empty());
  fixture.Acknowledge(gameplay_socket, kAttemptA, peer, NatProbeRole::kGameplay);
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(gameplay_socket, peer).empty());

  const LanAddress rebound{peer.ipv4, uint16_t(peer.port + 9)};
  auto registered = Registered(kAttemptA, rebound);
  REQUIRE(NatProbeConsume(discovery_socket, reinterpret_cast<const uint8_t*>(&registered),
                          sizeof(registered), htonl(0x7F000001u), 30740));
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(discovery_socket, peer).empty());
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(discovery_socket, rebound).empty());
  auto ack = Ack(kAttemptA);
  REQUIRE(NatProbeConsume(discovery_socket, reinterpret_cast<const uint8_t*>(&ack), sizeof(ack),
                          rebound.ipv4, rebound.port));
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(discovery_socket, rebound).size() == 1);
}

TEST_CASE("NAT correlation returns every ambiguous exact candidate",
          "[session][invite-grant][nat][security]") {
  NatFixture fixture;
  fixture.Add(kAttemptA);
  fixture.Add(kAttemptB);
  constexpr uint64_t socket = 42001;
  fixture.Attach(socket, NatProbeRole::kDiscovery);
  const LanAddress peer{htonl(0xCB007155u), 46000};
  fixture.Acknowledge(socket, kAttemptA, peer);
  fixture.Acknowledge(socket, kAttemptB, peer);
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, peer).size() == 2);
}

TEST_CASE("acknowledged admission correlation outlives rendezvous transmission",
          "[session][invite-grant][nat]") {
  NatFixture fixture;
  const auto attached_before = Clock::now();
  fixture.Add(kAttemptA);
  constexpr uint64_t socket = 42501;
  fixture.Attach(socket, NatProbeRole::kDiscovery);
  const LanAddress peer{htonl(0xCB007166u), 47000};
  fixture.Acknowledge(socket, kAttemptA, peer);

  HostAdmissionGrantStore store;
  Install(store, attached_before, PrivateAttempt(kAttemptA, 1, 60000));
  const auto after_rendezvous = attached_before + std::chrono::seconds(21);
  NatProbeTickAt(socket, after_rendezvous);
  CHECK_FALSE(NatProbeRendezvousAttemptActive(socket, kAttemptA));
  auto matches = NatProbeMatchAcknowledgedDiscoveryAttempts(socket, peer);
  REQUIRE(matches == std::vector<std::string>{std::string(kAttemptA)});

  // A current authenticated renewal, not NAT state, extends authority.
  Install(store, after_rendezvous, PrivateAttempt(kAttemptA, 2, 60000));
  auto reservation =
      Reserve(store, 10, after_rendezvous, "session-a", socket, peer.ipv4, peer.port, matches);
  REQUIRE(reservation.status == HostAdmissionReservationStatus::kReserved);
  store.Finish(reservation.reservation, false, after_rendezvous);

  store.ApplyAuthenticatedPoll("session-a", std::span<const HostAdmissionPollAttempt>{},
                               after_rendezvous);
  CHECK(Reserve(store, 10, after_rendezvous, "session-a", socket, peer.ipv4, peer.port, matches)
            .status == HostAdmissionReservationStatus::kNoMatch);

  fixture.Add(kAttemptB);
  constexpr uint64_t unacknowledged_socket = 42502;
  fixture.Attach(unacknowledged_socket, NatProbeRole::kDiscovery);
  NatProbeTickAt(unacknowledged_socket, after_rendezvous);
  CHECK_FALSE(NatProbeRendezvousAttemptActive(unacknowledged_socket, kAttemptB));
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(unacknowledged_socket, peer).empty());
}

TEST_CASE("unacknowledged rendezvous expiry permanently rejects late control traffic",
          "[session][invite-grant][nat][security]") {
  NatFixture fixture;
  const auto attached_before = Clock::now();
  fixture.Add(kAttemptA);
  constexpr uint64_t socket = 42701;
  fixture.Attach(socket, NatProbeRole::kDiscovery);
  const LanAddress peer{htonl(0xCB007177u), 47500};
  const auto after_rendezvous = attached_before + std::chrono::seconds(21);
  NatProbeTickAt(socket, after_rendezvous);
  CHECK_FALSE(NatProbeRendezvousAttemptActive(socket, kAttemptA));

  auto registered = Registered(kAttemptA, peer);
  auto punch = Punch(kAttemptA);
  auto ack = Ack(kAttemptA);
  CHECK_FALSE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                              sizeof(registered), htonl(0x7F000001u), 30740));
  CHECK_FALSE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&punch),
                              sizeof(punch), peer.ipv4, peer.port));
  CHECK_FALSE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack),
                              sizeof(ack), peer.ipv4, peer.port));
  auto expired_matches = NatProbeMatchAcknowledgedDiscoveryAttempts(socket, peer);
  CHECK(expired_matches.empty());

  HostAdmissionGrantStore grants;
  Install(grants, after_rendezvous, PrivateAttempt(kAttemptA, 1, 60000));
  CHECK(grants.Reserve("session-a", socket, peer.ipv4, peer.port,
                       expired_matches, 10, after_rendezvous)
            .status == HostAdmissionReservationStatus::kNoMatch);

  // Re-polling the same server-issued attempt cannot reattach an expired
  // generation, but a genuinely new attempt can rendezvous normally.
  REQUIRE(NatProbeInstallIdentity(
      {std::string(kAttemptA), std::string(kCapability), "127.0.0.1", 30740, 0}));
  CHECK_FALSE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                              sizeof(registered), htonl(0x7F000001u), 30740));
  fixture.Add(kAttemptB);
  fixture.Acknowledge(socket, kAttemptB, peer);
  auto fresh_matches = NatProbeMatchAcknowledgedDiscoveryAttempts(socket, peer);
  REQUIRE(fresh_matches == std::vector<std::string>{std::string(kAttemptB)});
  std::array refreshed{PrivateAttempt(kAttemptB, 1, 60000)};
  grants.ApplyAuthenticatedPoll("session-a", refreshed, after_rendezvous);
  CHECK(Reserve(grants, 11, after_rendezvous, "session-a", socket,
                peer.ipv4, peer.port, fresh_matches)
            .status == HostAdmissionReservationStatus::kReserved);
}

TEST_CASE("public discovery cannot spend private capacity from a wire flag",
          "[session][invite-grant][admission][network][security]") {
  DirectoryDisabled directory;
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t port = 39137;
  SessionRegistry registry;
  auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 1, 2);
  {
    LegacyLanDiagnosticsScope legacy_lan_diagnostics_0;
    LanDiscoveryService host(title_id, port);
    REQUIRE(host.Advertise(session));
    SocketFixture peer;
    REQUIRE(peer.socket != kBadSocket);
    auto claimed_private = JoinPacket(*session, title_id, 2, true);
    CHECK_FALSE(TransferDiscovery(peer.socket, port, claimed_private));
    CHECK(session->members.size() == 1);
    CHECK(session->FilledPrivateSlots() == 0);

    REQUIRE(registry.Modify(session->info.id, 1, 2, 2));
    REQUIRE(TransferDiscovery(peer.socket, port, claimed_private));
    REQUIRE(session->members.size() == 2);
    CHECK_FALSE(session->members.back().private_slot);
    CHECK(session->FilledPublicSlots() == 2);
    CHECK(session->FilledPrivateSlots() == 0);
  }
}

TEST_CASE("authenticated grant drives the complete host admission path",
          "[session][invite-grant][admission][network]") {
  DirectoryDisabled directory;
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t port = 39138;
  SessionRegistry registry;

  SECTION("private admission commits and consumes") {
    auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 1, 1);
    auto grants = std::make_shared<HostAdmissionGrantStore>();
    NatFixture nat;
    LegacyLanDiagnosticsScope legacy_lan_diagnostics_1;
    LanDiscoveryService host(title_id, port, grants);
    REQUIRE(host.Advertise(session));
    nat.Add(kAttemptA);
    Install(*grants, Clock::now(), PrivateAttempt(kAttemptA, 1, 60000));
    SocketFixture peer;
    REQUIRE(peer.socket != kBadSocket);
    const auto peer_address = BindLoopback(peer.socket);
    AcknowledgeHostAttempt(peer.socket, port, kAttemptA, peer_address);

    REQUIRE(TransferDiscovery(peer.socket, port, JoinPacket(*session, title_id, 2, true)));
    REQUIRE(session->members.size() == 2);
    CHECK(session->members.back().private_slot);
    CHECK(grants->available_grant_count() == 0);
    CHECK(Reserve(*grants, 3, Clock::now(), "session-a").status ==
          HostAdmissionReservationStatus::kNoMatch);
  }

  SECTION("explicit grant-backed public request commits and consumes") {
    auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 3, 1);
    session->members.push_back(Member(2, true));
    auto grants = std::make_shared<HostAdmissionGrantStore>();
    NatFixture nat;
    LegacyLanDiagnosticsScope legacy_lan_diagnostics_2;
    LanDiscoveryService host(title_id, port, grants);
    REQUIRE(host.Advertise(session));
    nat.Add(kAttemptA);
    Install(*grants, Clock::now(), PrivateAttempt(kAttemptA, 1, 60000));
    SocketFixture peer;
    REQUIRE(peer.socket != kBadSocket);
    const auto peer_address = BindLoopback(peer.socket);
    AcknowledgeHostAttempt(peer.socket, port, kAttemptA, peer_address);

    REQUIRE(TransferDiscovery(peer.socket, port, JoinPacket(*session, title_id, 3, false)));
    REQUIRE(session->members.size() == 3);
    CHECK_FALSE(session->members.back().private_slot);
    CHECK(session->FilledPrivateSlots() == 1);
    CHECK(grants->available_grant_count() == 0);
  }

  SECTION("private eligibility commits to witnessed public-only host capacity") {
    auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 0x42f, 6, 0);
    auto grants = std::make_shared<HostAdmissionGrantStore>();
    NatFixture nat;
    LegacyLanDiagnosticsScope legacy_lan_diagnostics_public_capacity;
    LanDiscoveryService host(title_id, port, grants);
    REQUIRE(host.Advertise(session));
    nat.Add(kAttemptA);
    Install(*grants, Clock::now(), PrivateAttempt(kAttemptA, 1, 60000));
    SocketFixture peer;
    REQUIRE(peer.socket != kBadSocket);
    const auto peer_address = BindLoopback(peer.socket);
    AcknowledgeHostAttempt(peer.socket, port, kAttemptA, peer_address);
    const auto requested_private = JoinPacket(*session, title_id, 2, true);
    REQUIRE(TransferDiscovery(peer.socket, port, requested_private));
    REQUIRE(session->members.size() == 2);
    CHECK_FALSE(session->members.back().private_slot);
    CHECK(session->FilledPublicSlots() == 2);
    CHECK(session->FilledPrivateSlots() == 0);
    CHECK(grants->available_grant_count() == 0);
    REQUIRE(TransferDiscovery(peer.socket, port, requested_private));
    CHECK(session->members.size() == 2);
    CHECK_FALSE(session->members.back().private_slot);
    CHECK(Reserve(*grants, 3, Clock::now(), "session-a").status ==
          HostAdmissionReservationStatus::kNoMatch);
  }

  SECTION("capacity rejection releases the reservation for retry") {
    auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 1, 0);
    auto grants = std::make_shared<HostAdmissionGrantStore>();
    NatFixture nat;
    LegacyLanDiagnosticsScope legacy_lan_diagnostics_3;
    LanDiscoveryService host(title_id, port, grants);
    REQUIRE(host.Advertise(session));
    nat.Add(kAttemptA);
    Install(*grants, Clock::now(), PrivateAttempt(kAttemptA, 1, 60000));
    SocketFixture peer;
    REQUIRE(peer.socket != kBadSocket);
    const auto peer_address = BindLoopback(peer.socket);
    AcknowledgeHostAttempt(peer.socket, port, kAttemptA, peer_address);
    const auto join = JoinPacket(*session, title_id, 2, true);

    CHECK_FALSE(TransferDiscovery(peer.socket, port, join));
    CHECK(session->members.size() == 1);
    CHECK(grants->available_grant_count() == 1);
    REQUIRE(registry.Modify(session->info.id, 1, 2, 0));
    REQUIRE(TransferDiscovery(peer.socket, port, join));
    CHECK(session->members.size() == 2);
    CHECK_FALSE(session->members.back().private_slot);
    CHECK(session->FilledPrivateSlots() == 0);
    CHECK(grants->available_grant_count() == 0);
  }

  SECTION("ambiguous exact endpoint cannot select an invite grant") {
    auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 1, 2);
    auto grants = std::make_shared<HostAdmissionGrantStore>();
    NatFixture nat;
    LegacyLanDiagnosticsScope legacy_lan_diagnostics_4;
    LanDiscoveryService host(title_id, port, grants);
    REQUIRE(host.Advertise(session));
    nat.Add(kAttemptA);
    nat.Add(kAttemptB);
    std::array attempts{PrivateAttempt(kAttemptA, 1, 60000), PrivateAttempt(kAttemptB, 1, 60000)};
    grants->ApplyAuthenticatedPoll("session-a", attempts, Clock::now());
    SocketFixture peer;
    REQUIRE(peer.socket != kBadSocket);
    const auto peer_address = BindLoopback(peer.socket);
    AcknowledgeHostAttempt(peer.socket, port, kAttemptA, peer_address);
    AcknowledgeHostAttempt(peer.socket, port, kAttemptB, peer_address);

    CHECK_FALSE(TransferDiscovery(peer.socket, port, JoinPacket(*session, title_id, 2, true)));
    CHECK(session->members.size() == 1);
    CHECK(grants->available_grant_count() == 2);
  }
}

TEST_CASE("authoritative discovery admission preserves public and invite pools",
          "[session][invite-grant][admission]") {
  SessionRegistry registry;
  auto session = registry.Create(1, "Host", {}, 1, 4, 2);
  DiscoveryAdmissionContext public_context;
  DiscoveryAdmissionContext invite_context{DiscoveryAdmissionSource::kInviteGrant};
  auto apply = [&](SessionMember member, DiscoveryAdmissionContext context) {
    return ApplyDiscoveryMemberBatch(*session, std::span<const SessionMember>(&member, 1), context);
  };

  REQUIRE(apply(Member(2, true), public_context));
  CHECK_FALSE(session->members.back().private_slot);
  REQUIRE(apply(Member(3), public_context));
  REQUIRE(apply(Member(4), public_context));
  CHECK(session->FilledPublicSlots() == 4);
  CHECK_FALSE(apply(Member(5, true), public_context));

  REQUIRE(apply(Member(6, true), invite_context));
  REQUIRE(apply(Member(7, true), invite_context));
  CHECK(session->FilledPrivateSlots() == 2);
  CHECK_FALSE(apply(Member(8, true), invite_context));

  const auto before_size = session->members.size();
  const auto before_private = session->members[4].private_slot;
  REQUIRE(apply(Member(6, false), public_context));
  CHECK(session->members.size() == before_size);
  CHECK(session->members[4].private_slot == before_private);
}

TEST_CASE("grant-backed public request is transactional with private pool full",
          "[session][invite-grant][admission]") {
  SessionRecord session;
  session.host_xuid = 1;
  session.max_public_slots = 3;
  session.max_private_slots = 1;
  session.members = {Member(1), Member(2, true)};
  DiscoveryAdmissionContext invite{DiscoveryAdmissionSource::kInviteGrant};
  auto fallback = Member(3, false);
  REQUIRE(ApplyDiscoveryMemberBatch(session, std::span<const SessionMember>(&fallback, 1), invite));
  CHECK(session.FilledPublicSlots() == 2);
  CHECK(session.FilledPrivateSlots() == 1);

  auto private_eligible = Member(4, true);
  REQUIRE(ApplyDiscoveryMemberBatch(
      session, std::span<const SessionMember>(&private_eligible, 1), invite));
  CHECK_FALSE(session.members.back().private_slot);
  CHECK(session.FilledPublicSlots() == 3);
  CHECK(session.FilledPrivateSlots() == 1);
  auto no_capacity = Member(5, true);
  CHECK_FALSE(ApplyDiscoveryMemberBatch(
      session, std::span<const SessionMember>(&no_capacity, 1), invite));
  std::array invalid_share{Member(5), Member(6)};
  CHECK_FALSE(ApplyDiscoveryMemberBatch(session, invalid_share, invite));
  CHECK(session.members.size() == 4);
}

TEST_CASE("authenticated private eligibility uses witnessed public-only host capacity",
          "[session][invite-grant][admission][private-fallback]") {
#if REX_PLATFORM_LINUX
  Dl_info loaded{};
  REQUIRE(dladdr(reinterpret_cast<const void*>(&ApplyDiscoveryMemberBatch), &loaded));
  REQUIRE(loaded.dli_fname);
  const nlohmann::json loaded_row{{"kind", "loaded_runtime"}, {"path", loaded.dli_fname}};
  std::printf("%s\n", loaded_row.dump().c_str());
#endif
  SessionRegistry registry;
  auto session = registry.Create(1, "LocalHost", {htonl(INADDR_LOOPBACK), 3074},
                                 0x42f, 6, 0);
  REQUIRE(session->members.size() == 1);
  REQUIRE(session->members.front().local);
  REQUIRE_FALSE(session->members.front().private_slot);
  const DiscoveryAdmissionContext invite{DiscoveryAdmissionSource::kInviteGrant};
  auto requested = Member(2, true);
  requested.gameplay_admission = std::make_shared<const GameplayAdmissionBinding>(
      GameplayAdmissionBinding{"session-a", std::string(kAttemptA), std::string(kGeneration)});
  REQUIRE(ApplyDiscoveryMemberBatch(*session, std::span(&requested, 1), invite));
  REQUIRE(session->members.size() == 2);
  CHECK_FALSE(session->members.back().private_slot);
  CHECK_FALSE(session->members.back().local);
  CHECK(session->members.back().gameplay_admission == requested.gameplay_admission);
  CHECK(session->FilledPublicSlots() == 2);
  CHECK(session->FilledPrivateSlots() == 0);
  CHECK(session->OpenPublicSlots() == 4);
  CHECK(session->OpenPrivateSlots() == 0);
  // The authenticated confirmation/retry preserves the allocated public pool,
  // its admission instance and metadata even though private eligibility repeats.
  const auto admission = session->members.back().gameplay_admission;
  requested.name = "Replacement";
  REQUIRE(ApplyDiscoveryMemberBatch(*session, std::span(&requested, 1), invite));
  CHECK(session->members.size() == 2);
  CHECK_FALSE(session->members.back().private_slot);
  CHECK(session->members.back().name == "Player2");
  CHECK(session->members.back().gameplay_admission == admission);
}

TEST_CASE("authenticated private preference preserves pool constraints and rollback",
          "[session][invite-grant][admission][private-fallback]") {
  const DiscoveryAdmissionContext invite{DiscoveryAdmissionSource::kInviteGrant};
  SessionRecord session;
  session.host_xuid = 1;
  session.max_public_slots = 2;
  session.max_private_slots = 1;
  session.members = {Member(1)};
  auto first = Member(2, true);
  REQUIRE(ApplyDiscoveryMemberBatch(session, std::span(&first, 1), invite));
  CHECK(session.members.back().private_slot);
  auto second = Member(3, true);
  REQUIRE(ApplyDiscoveryMemberBatch(session, std::span(&second, 1), invite));
  CHECK_FALSE(session.members.back().private_slot);
  CHECK(session.FilledPublicSlots() == 2);
  CHECK(session.FilledPrivateSlots() == 1);
  const auto before = session.members;
  auto reject_unchanged = [&](std::span<const SessionMember> batch) {
    CHECK_FALSE(ApplyDiscoveryMemberBatch(session, batch, invite));
    REQUIRE(session.members.size() == before.size());
    for (size_t i = 0; i < before.size(); ++i) {
      CHECK(session.members[i].xuid == before[i].xuid);
      CHECK(session.members[i].name == before[i].name);
      CHECK(session.members[i].private_slot == before[i].private_slot);
      CHECK(session.members[i].gameplay_admission == before[i].gameplay_admission);
    }
  };
  auto full = Member(4, true);
  reject_unchanged(std::span(&full, 1));
  auto invalid = Member(0, true);
  reject_unchanged(std::span(&invalid, 1));
  auto host = Member(1, true);
  reject_unchanged(std::span(&host, 1));
  std::array repeated{Member(4, true), Member(4)};
  reject_unchanged(repeated);
  std::array mixed{Member(2), Member(4, true)};
  reject_unchanged(mixed);
  // Existing membership is idempotent even with both pools full, and never
  // reclassifies a private member into the full public pool.
  auto retry = Member(2, false);
  REQUIRE(ApplyDiscoveryMemberBatch(session, std::span(&retry, 1), invite));
  CHECK(session.members[1].private_slot);
}

TEST_CASE("private eligibility never expands public or ordinary title authority",
          "[session][invite-grant][admission][private-fallback][security]") {
  SessionRegistry registry;
  auto session = registry.Create(1, "Host", {}, 1, 1, 1);
  const DiscoveryAdmissionContext invite{DiscoveryAdmissionSource::kInviteGrant};
  auto private_claim = Member(2, true);
  CHECK_FALSE(ApplyDiscoveryMemberBatch(*session, std::span(&private_claim, 1), {}));
  CHECK(session->members.size() == 1);
  auto public_request = Member(2);
  CHECK_FALSE(ApplyDiscoveryMemberBatch(*session, std::span(&public_request, 1), invite));
  REQUIRE(ApplyDiscoveryMemberBatch(*session, std::span(&private_claim, 1), invite));
  CHECK(session->members.back().private_slot);
  CHECK_FALSE(registry.Join(session->info.id, Member(2, false)));
  CHECK(session->members.back().private_slot);

  auto public_only = registry.Create(3, "Host", {}, 1, 6, 0);
  CHECK_FALSE(registry.Join(public_only->info.id, Member(4, true)));
  CHECK(public_only->members.size() == 1);
}

TEST_CASE("zero public capacity and zero total capacity stay bounded for invite allocation",
          "[session][invite-grant][admission][private-fallback]") {
  SessionRecord session;
  session.host_xuid = 1;
  const DiscoveryAdmissionContext invite{DiscoveryAdmissionSource::kInviteGrant};
  auto requested = Member(2, true);
  CHECK_FALSE(ApplyDiscoveryMemberBatch(session, std::span(&requested, 1), invite));
  CHECK(session.members.empty());
  session.max_private_slots = 1;
  REQUIRE(ApplyDiscoveryMemberBatch(session, std::span(&requested, 1), invite));
  CHECK(session.members.back().private_slot);
  auto next = Member(3, true);
  CHECK_FALSE(ApplyDiscoveryMemberBatch(session, std::span(&next, 1), invite));
  CHECK(session.members.size() == 1);
}

TEST_CASE("invite fallback final public slot has one atomic winner",
          "[session][invite-grant][admission][private-fallback][concurrency]") {
  for (unsigned iteration = 0; iteration < 16; ++iteration) {
    SessionRegistry registry;
    auto session = registry.Create(1, "Host", {}, 1, 2, 0);
    const DiscoveryAdmissionContext invite{DiscoveryAdmissionSource::kInviteGrant};
    std::barrier start(3);
    std::array<bool, 2> admitted{};
    std::thread first([&] {
      auto member = Member(2, true);
      start.arrive_and_wait();
      admitted[0] = ApplyDiscoveryMemberBatch(*session, std::span(&member, 1), invite);
    });
    std::thread second([&] {
      auto member = Member(3, true);
      start.arrive_and_wait();
      admitted[1] = ApplyDiscoveryMemberBatch(*session, std::span(&member, 1), invite);
    });
    start.arrive_and_wait();
    first.join(); second.join();
    CHECK(unsigned(admitted[0]) + unsigned(admitted[1]) == 1);
    CHECK(session->FilledPublicSlots() == 2);
    CHECK(session->FilledPrivateSlots() == 0);
  }
}

TEST_CASE("successful grant-backed public request consumes its exact grant",
          "[session][invite-grant][admission][security]") {
  const auto now = Clock::time_point{} + std::chrono::seconds(35);
  HostAdmissionGrantStore store;
  Install(store, now);
  auto reservation = Reserve(store, 3, now);
  REQUIRE(reservation.reservation);

  SessionRecord session;
  session.host_xuid = 1;
  session.max_public_slots = 3;
  session.max_private_slots = 1;
  session.members = {Member(1), Member(2, true)};
  auto fallback = Member(3, false);
  const bool committed =
      ApplyDiscoveryMemberBatch(session, std::span<const SessionMember>(&fallback, 1),
                                {DiscoveryAdmissionSource::kInviteGrant});
  REQUIRE(committed);
  store.Finish(reservation.reservation, committed, now);
  CHECK(Reserve(store, 4, now).status == HostAdmissionReservationStatus::kNoMatch);
}

TEST_CASE("membership final-slot race has one transactional winner",
          "[session][invite-grant][admission][concurrency]") {
  for (unsigned iteration = 0; iteration < 16; ++iteration) {
    SessionRecord session;
    session.host_xuid = 1;
    session.max_public_slots = 2;
    session.members = {Member(1)};
    DiscoveryAdmissionContext public_context;
    std::barrier start(3);
    std::array<bool, 2> admitted{};
    std::thread first([&] {
      auto member = Member(2);
      start.arrive_and_wait();
      admitted[0] = ApplyDiscoveryMemberBatch(session, std::span<const SessionMember>(&member, 1),
                                              public_context);
    });
    std::thread second([&] {
      auto member = Member(3);
      start.arrive_and_wait();
      admitted[1] = ApplyDiscoveryMemberBatch(session, std::span<const SessionMember>(&member, 1),
                                              public_context);
    });
    start.arrive_and_wait();
    first.join();
    second.join();
    CHECK(unsigned(admitted[0]) + unsigned(admitted[1]) == 1);
  }
}

TEST_CASE("poll invalidation racing a reservation never creates reusable authority",
          "[session][invite-grant][concurrency]") {
  const auto now = Clock::time_point{} + std::chrono::seconds(40);
  HostAdmissionGrantStore store;
  Install(store, now);
  std::barrier start(3);
  HostAdmissionReservationResult reserved;
  std::thread reserver([&] {
    start.arrive_and_wait();
    reserved = Reserve(store, 10, now);
  });
  std::thread revoker([&] {
    start.arrive_and_wait();
    store.ApplyAuthenticatedPoll("session-a", std::span<const HostAdmissionPollAttempt>{}, now);
  });
  start.arrive_and_wait();
  reserver.join();
  revoker.join();
  if (reserved.reservation)
    store.Finish(reserved.reservation, true, now);
  CHECK(Reserve(store, 11, now).status == HostAdmissionReservationStatus::kNoMatch);
}

}  // namespace rex::system::xam

namespace rex::system::xam {
TEST_CASE("Directory configuration alone grants no public discovery or host membership", "[session][invite-grant][network][security]") {
  struct ProtectedDirectoryConfiguration {
    std::string url=REXCVAR_GET(session_directory_url),build=REXCVAR_GET(session_directory_build_id),
      invite=REXCVAR_GET(private_lan_invitation_file),listener=REXCVAR_GET(lan_discovery_listen_address);
    bool legacy=REXCVAR_GET(private_lan_allow_legacy_diagnostics);
    ProtectedDirectoryConfiguration(){REXCVAR_SET(session_directory_url,std::string("http://127.0.0.1:1"));
      REXCVAR_SET(session_directory_build_id,std::string{});REXCVAR_SET(private_lan_invitation_file,std::string{});
      REXCVAR_SET(lan_discovery_listen_address,std::string("127.0.0.1"));REXCVAR_SET(private_lan_allow_legacy_diagnostics,false);}
    ~ProtectedDirectoryConfiguration(){REXCVAR_SET(session_directory_url,url);REXCVAR_SET(session_directory_build_id,build);
      REXCVAR_SET(private_lan_invitation_file,invite);REXCVAR_SET(lan_discovery_listen_address,listener);REXCVAR_SET(private_lan_allow_legacy_diagnostics,legacy);}
  } configuration;
  // Empty build ID prevents any HTTP worker/request. Only the test-owned UDP
  // listener operates; the URL tests selection, not an external service.
  constexpr uint32_t title=0x58410a7a;uint16_t port;
  {SocketFixture probe;REQUIRE(probe.socket!=kBadSocket);port=BindLoopback(probe.socket).port;}
  SessionRegistry registry;auto session=registry.Create(1,"PrivateMetadata",{htonl(INADDR_LOOPBACK),3074},1,3,3);REQUIRE(session);
  auto grants=std::make_shared<HostAdmissionGrantStore>();NatFixture nat;LanDiscoveryService host(title,port,grants);
  REQUIRE(host.Advertise(session));SocketFixture peer,other;REQUIRE(peer.socket!=kBadSocket);REQUIRE(other.socket!=kBadSocket);
  const auto address=BindLoopback(peer.socket);BindLoopback(other.socket);
  DiscoveryWirePacket query{};PutBigEndian(query,0,0x5245584c);PutBigEndian(query,4,2,2);query[6]=1;PutBigEndian(query,8,title);
  CHECK_FALSE(TransferDiscovery(peer.socket,port,query));
  CHECK_FALSE(TransferDiscovery(peer.socket,port,JoinPacket(*session,title,2,false)));
  CHECK_FALSE(TransferDiscovery(peer.socket,port,JoinPacket(*session,title,2,true)));
  {std::lock_guard lock(*session->mutex);CHECK(session->members.size()==1);}
  LanDiscoveryService ungranted_client(title,port);CHECK(ungranted_client.Search(50,1).empty());
  SessionRecord copy=*session;SessionMember member{3,"Ungrant",0,true,false,false};
  CHECK_FALSE(ungranted_client.Join(copy,member,50));CHECK_FALSE(copy.arbitration_client);
  Install(*grants,Clock::now(),PrivateAttempt(kAttemptA,1,60000));
  CHECK_FALSE(TransferDiscovery(peer.socket,port,query));
  nat.Add(kAttemptA);AcknowledgeHostAttempt(peer.socket,port,kAttemptA,address);
  REQUIRE(TransferDiscovery(peer.socket,port,query));CHECK(grants->available_grant_count()==1);
  CHECK_FALSE(TransferDiscovery(other.socket,port,query));
  CHECK_FALSE(TransferDiscovery(other.socket,port,JoinPacket(*session,title,3,false)));
  {std::lock_guard lock(*session->mutex);CHECK(session->members.size()==1);}
  const auto join=JoinPacket(*session,title,2,false);REQUIRE(TransferDiscovery(peer.socket,port,join));
  {std::lock_guard lock(*session->mutex);REQUIRE(session->members.size()==2);CHECK(session->members.back().gameplay_admission);}
  CHECK(grants->available_grant_count()==0);CHECK_FALSE(TransferDiscovery(peer.socket,port,query));
  REQUIRE(TransferDiscovery(peer.socket,port,join));
  CHECK_FALSE(TransferDiscovery(other.socket,port,JoinPacket(*session,title,4,false)));
  host.StopAdvertising();
}

TEST_CASE("Discovery grant checks are read-only current unique and invalidation-aware", "[session][invite-grant][security]") {
  HostAdmissionGrantStore grants;const auto now=Clock::time_point{}+std::chrono::seconds(10);
  const std::array one{std::string(kAttemptA)},wrong{std::string(kAttemptB)};
  CHECK_FALSE(grants.HasCurrentPrivateDiscoveryGrant("session-a",one,now));Install(grants,now);
  CHECK(grants.HasCurrentPrivateDiscoveryGrant("session-a",one,now));CHECK(grants.available_grant_count(now)==1);
  CHECK_FALSE(grants.HasCurrentPrivateDiscoveryGrant("session-b",one,now));CHECK_FALSE(grants.HasCurrentPrivateDiscoveryGrant("session-a",wrong,now));
  CHECK_FALSE(grants.HasCurrentPrivateDiscoveryGrant("session-a",one,now+std::chrono::seconds(1)));
  const auto reserved=Reserve(grants,2,now);REQUIRE(reserved.status==HostAdmissionReservationStatus::kReserved);
  CHECK(grants.HasCurrentPrivateDiscoveryGrant("session-a",one,now));grants.InvalidateSession("session-a");
  CHECK_FALSE(grants.HasCurrentPrivateDiscoveryGrant("session-a",one,now));grants.Finish(reserved.reservation,false,now);
  Install(grants,now);const auto second=Reserve(grants,2,now);REQUIRE(second.status==HostAdmissionReservationStatus::kReserved);
  grants.Finish(second.reservation,true,now);CHECK_FALSE(grants.HasCurrentPrivateDiscoveryGrant("session-a",one,now));
  HostAdmissionGrantStore ambiguous;const std::array attempts{PrivateAttempt(kAttemptA),PrivateAttempt(kAttemptB)};
  ambiguous.ApplyAuthenticatedPoll("session-a",attempts,now);const std::array both{std::string(kAttemptA),std::string(kAttemptB)};
  CHECK_FALSE(ambiguous.HasCurrentPrivateDiscoveryGrant("session-a",both,now));CHECK(ambiguous.HasCurrentPrivateDiscoveryGrant("session-a",one,now));
}


TEST_CASE("Gameplay traversal moves to the home network behind one shared router",
          "[session][nat]") {
  constexpr std::string_view kSameHouse = "3142536475869708a9bacbdcedfe0f10";
  constexpr std::string_view kOtherHouse = "4152637485960718a9bacbdcedfe0f10";
  const LanAddress logical{htonl(0xF0000002u), 1000};
  const LanAddress lan_peer{htonl(0x0A00003Cu), 30742};
  const auto expires = std::chrono::steady_clock::now() + std::chrono::seconds(30);
  NatFixture fixture;

  SECTION("same public address") {
    const uint64_t socket = 0x6101;
    fixture.Attach(socket, NatProbeRole::kGameplay);
    REQUIRE(NatProbeInstallGameplayIdentity(
        {std::string(kSameHouse), std::string(kCapability), "127.0.0.1", 30740, 0}, socket,
        logical, expires));
    // The joiner's public mapping shares the host's observed public address.
    auto registered = Registered(kSameHouse, {htonl(0xCB007109u), 40000}, NatProbeRole::kGameplay);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                            sizeof(registered), htonl(0x7F000001u), 30740));
    auto punch = Punch(kSameHouse, NatProbeRole::kGameplay);
    REQUIRE(NatProbeIsControlPacket(socket, reinterpret_cast<const uint8_t*>(&punch),
                                    sizeof(punch), lan_peer.ipv4, lan_peer.port));
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&punch), sizeof(punch),
                            lan_peer.ipv4, lan_peer.port));
    CHECK_FALSE(NatProbeGameplayDestination(socket, logical).has_value());
    auto ack = Ack(kSameHouse, NatProbeRole::kGameplay);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack), sizeof(ack),
                            lan_peer.ipv4, lan_peer.port));
    REQUIRE(NatProbeGameplayDestination(socket, logical) == lan_peer);
    // Later rendezvous refreshes keep reporting the public mapping; the
    // working home-network route must survive them.
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                            sizeof(registered), htonl(0x7F000001u), 30740));
    CHECK(NatProbeGameplayDestination(socket, logical) == lan_peer);
    CHECK(NatProbeNormalizeGameplaySource(socket, lan_peer) == logical);
    NatProbeRemoveGameplayIdentity(socket, kSameHouse);
  }

  SECTION("joiner learns the host from its acknowledgement") {
    const uint64_t socket = 0x6102;
    fixture.Attach(socket, NatProbeRole::kGameplay);
    REQUIRE(NatProbeInstallGameplayIdentity(
        {std::string(kSameHouse), std::string(kCapability), "127.0.0.1", 30740, 0}, socket,
        logical, expires));
    auto registered = Registered(kSameHouse, {htonl(0xCB007109u), 40000}, NatProbeRole::kGameplay);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                            sizeof(registered), htonl(0x7F000001u), 30740));
    auto ack = Ack(kSameHouse, NatProbeRole::kGameplay);
    REQUIRE(NatProbeIsControlPacket(socket, reinterpret_cast<const uint8_t*>(&ack), sizeof(ack),
                                    lan_peer.ipv4, lan_peer.port));
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack), sizeof(ack),
                            lan_peer.ipv4, lan_peer.port));
    CHECK(NatProbeGameplayDestination(socket, logical) == lan_peer);
    NatProbeRemoveGameplayIdentity(socket, kSameHouse);
  }

  SECTION("different houses never accept a private source") {
    const uint64_t socket = 0x6103;
    fixture.Attach(socket, NatProbeRole::kGameplay);
    REQUIRE(NatProbeInstallGameplayIdentity(
        {std::string(kOtherHouse), std::string(kCapability), "127.0.0.1", 30740, 0}, socket,
        logical, expires));
    auto registered = Registered(kOtherHouse, {htonl(0x5DB8D822u), 40000}, NatProbeRole::kGameplay);
    REQUIRE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&registered),
                            sizeof(registered), htonl(0x7F000001u), 30740));
    auto punch = Punch(kOtherHouse, NatProbeRole::kGameplay);
    CHECK_FALSE(NatProbeIsControlPacket(socket, reinterpret_cast<const uint8_t*>(&punch),
                                        sizeof(punch), lan_peer.ipv4, lan_peer.port));
    NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&punch), sizeof(punch),
                    lan_peer.ipv4, lan_peer.port);
    auto ack = Ack(kOtherHouse, NatProbeRole::kGameplay);
    CHECK_FALSE(NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&ack), sizeof(ack),
                                lan_peer.ipv4, lan_peer.port));
    CHECK_FALSE(NatProbeGameplayDestination(socket, logical).has_value());
    NatProbeRemoveGameplayIdentity(socket, kOtherHouse);
  }
}
} // namespace rex::system::xam
