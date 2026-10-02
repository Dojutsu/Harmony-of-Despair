#include <catch2/catch_test_macros.hpp>

#include <chrono>
#include <cstring>
#include <deque>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
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
#pragma pack(pop)
static_assert(sizeof(ClientNatPacket) == 56);

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

}  // namespace
}  // namespace rex::system::xam
