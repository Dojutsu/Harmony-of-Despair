#include "legacy_lan_diagnostics_scope.h"
#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <array>
#include <atomic>
#include <mutex>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <string>
#include <thread>
#include <vector>

#include <rex/platform.h>

#if REX_PLATFORM_WIN32
#include <WinSock2.h>
#elif REX_PLATFORM_GNU_LINUX
#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>
#include <sys/socket.h>
#include <unistd.h>
#else
#include <arpa/inet.h>
#endif

#include <rex/system/xam/session.h>
#include <rex/system/xam/session_directory.h>
#include <rex/system/xam/nat_probe.h>
#include <rex/system/xam/user_profile.h>
#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/logging/sink.h>
#include <memory>

namespace rex::system::xam {

TEST_CASE("NAT registration polls quickly only while awaiting a peer", "[session][network][nat]") {
  CHECK(NatProbeRegistrationIntervalMs(false) == 100);
  CHECK(NatProbeRegistrationIntervalMs(true) == 1000);
  CHECK(NatProbeAutomaticAttemptActive(0, false));
  CHECK(NatProbeAutomaticAttemptActive(19999, false));
  CHECK_FALSE(NatProbeAutomaticAttemptActive(20000, false));
  CHECK_FALSE(NatProbeAutomaticAttemptActive(100, true));
}

TEST_CASE("invite LAN proof binds attempt, domain, source and hosted tuple",
          "[session][configured-invite][lan][security]") {
#if REX_PLATFORM_WIN32 || REX_PLATFORM_GNU_LINUX
  constexpr std::string_view attempt = "a5a17e71f6de46b63843e54034b24c78";
  constexpr std::string_view other = "4f9d04f830ee9dbc80e72dcea3d674e4";
  const std::array<uint8_t, 6> source_a{10, 0, 0, 217, 0xD2, 0x5E};
  auto source_b = source_a;
  source_b[3] = 218;
  const auto selector = InviteLanAuthenticationTag(attempt, "invite-lan-selector-v1");
  const auto request = InviteLanAuthenticationTag(attempt, "invite-lan-request-v1", source_a);
  REQUIRE(selector);
  REQUIRE(request);
  CHECK(*selector != *request);
  CHECK(InviteLanAuthenticationTag(attempt, "invite-lan-request-v1", source_b) != request);
  CHECK(InviteLanAuthenticationTag(other, "invite-lan-request-v1", source_a) != request);
  CHECK_FALSE(InviteLanAuthenticationTag("invalid", "invite-lan-selector-v1"));
  CHECK_FALSE(InviteLanAuthenticationTag("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz",
                                         "invite-lan-selector-v1"));

  std::array<uint8_t, 74> tuple{};
  tuple[0] = 0x58; // title
  tuple[4] = 1;    // Xbox session ID
  tuple[12] = 2;   // exchange key
  tuple[28] = 3;   // host XUID
  tuple[36] = 10;  // hosted address
  tuple[40] = 0x78; // gameplay port
  tuple[42]=1; // registration nonce
  tuple[50]=2; // host machine
  tuple[58]=3; // incarnation
  const auto proof = InviteLanAuthenticationTag(attempt, "invite-lan-response-v1", tuple);
  REQUIRE(proof);
  CHECK(InviteLanAuthenticationTag(other, "invite-lan-response-v1", tuple) != proof);
  for (const size_t field : std::array<size_t, 9>{0, 4, 12, 28, 36, 40, 42, 50, 58}) {
    auto altered = tuple;
    altered[field] ^= 1;
    CHECK(InviteLanAuthenticationTag(attempt, "invite-lan-response-v1", altered) != proof);
  }
#endif
}

#if REX_PLATFORM_GNU_LINUX
TEST_CASE("Linux directory hosting retries hostile registration and heartbeat responses",
          "[session][directory][linux][security]") {
  auto logs = std::make_shared<rex::LogCaptureSink>();
  rex::AddSink(logs);
  struct LogCleanup {
    std::shared_ptr<rex::LogCaptureSink> sink;
    ~LogCleanup() { rex::RemoveSink(sink); }
  } log_cleanup{logs};
  const int listener = ::socket(AF_INET, SOCK_STREAM, 0);
  REQUIRE(listener >= 0);
  struct ListenerCleanup { int fd; ~ListenerCleanup() { ::close(fd); } } cleanup{listener};
  sockaddr_in address{};
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  REQUIRE(::bind(listener, reinterpret_cast<const sockaddr*>(&address), sizeof(address)) == 0);
  REQUIRE(::listen(listener, 4) == 0);
  socklen_t address_size = sizeof(address);
  REQUIRE(::getsockname(listener, reinterpret_cast<sockaddr*>(&address), &address_size) == 0);
  std::atomic<unsigned> registrations{0}, heartbeats{0}, polls{0}, deletions{0};
  std::vector<std::string> registration_bodies;
  std::mutex requests_mutex;
  std::jthread server([&](std::stop_token stop) {
    while (!stop.stop_requested()) {
      pollfd pending{listener, POLLIN, 0};
      if (::poll(&pending, 1, 25) <= 0) continue;
      const int connection = ::accept(listener, nullptr, nullptr);
      if (connection < 0) continue;
      timeval bounded_wait{0, 500000};
      ::setsockopt(connection, SOL_SOCKET, SO_RCVTIMEO, &bounded_wait, sizeof(bounded_wait));
      std::string request;
      std::array<char, 2048> buffer{};
      size_t header_end = std::string::npos;
      size_t content_length = 0;
      while (request.size() < 8192 && (header_end == std::string::npos ||
             request.size() < header_end + 4 + content_length)) {
        const ssize_t count = ::recv(connection, buffer.data(), buffer.size(), 0);
        if (count <= 0) break;
        request.append(buffer.data(), static_cast<size_t>(count));
        if (header_end == std::string::npos) {
          header_end = request.find("\r\n\r\n");
          if (header_end != std::string::npos) {
            const auto length_header = request.find("Content-Length:");
            if (length_header != std::string::npos && length_header < header_end) {
              const auto value_start = request.find_first_not_of(' ', length_header + 15);
              if (value_start != std::string::npos && value_start < header_end) {
                try { content_length = std::stoul(request.substr(value_start)); }
                catch (...) { break; }
                if (content_length > 4096) break;
              }
            }
          }
        }
      }
      std::string status = "503 Service Unavailable";
      std::string body = "{}";
      if (request.starts_with("POST /sessions ")) {
        const auto registration_number = ++registrations;
        {
          std::lock_guard lock(requests_mutex);
          registration_bodies.push_back(header_end == std::string::npos ? "" :
                                         request.substr(header_end + 4));
        }
        status = "201 Created";
        body = registration_number == 1
            ? R"({"session_id":42,"registration_token":{},"invite_code":[]})"
            : R"({"session_id":"linux-host-session","registration_token":"host-test-token","invite_code":"ABC234"})";
      } else if (request.starts_with("POST /sessions/linux-host-session/heartbeat ")) {
        ++heartbeats;
        status = "200 OK";
        body = R"({"session_id":{"wrong":"type"}})";
      } else if (request.starts_with("POST /sessions/linux-host-session/join-attempts/poll ")) {
        ++polls;
        status = "200 OK";
        body = R"({"attempts":[]})";
      } else if (request.starts_with("DELETE /sessions/linux-host-session ")) {
        ++deletions;
        status = "204 No Content";
        body.clear();
      }
      const std::string response = "HTTP/1.1 " + status +
          "\r\nContent-Type: application/json\r\nContent-Length: " + std::to_string(body.size()) +
          "\r\nConnection: close\r\n\r\n" + body;
      size_t sent = 0;
      while (sent < response.size()) {
        const ssize_t count = ::send(connection, response.data() + sent, response.size() - sent,
                                     MSG_NOSIGNAL);
        if (count <= 0) break;
        sent += static_cast<size_t>(count);
      }
      ::close(connection);
    }
  });
  struct CvarRestore {
    std::string url = REXCVAR_GET(session_directory_url);
    std::string build = REXCVAR_GET(session_directory_build_id);
    std::string candidate = REXCVAR_GET(session_directory_candidate_type);
    std::string publish = REXCVAR_GET(session_directory_publish_address);
    ~CvarRestore() {
      REXCVAR_SET(session_directory_url, url);
      REXCVAR_SET(session_directory_build_id, build);
      REXCVAR_SET(session_directory_candidate_type, candidate);
      REXCVAR_SET(session_directory_publish_address, publish);
    }
  } restore;
  REXCVAR_SET(session_directory_url, "http://127.0.0.1:" + std::to_string(ntohs(address.sin_port)));
  REXCVAR_SET(session_directory_build_id, "harmony-test");
  REXCVAR_SET(session_directory_candidate_type, "public");
  REXCVAR_SET(session_directory_publish_address, "");
  SessionRegistry registry;
  auto hosted = registry.Create(0x1001, "LinuxHost", {htonl(INADDR_LOOPBACK), 30742}, 1, 6, 0);
  SessionDirectoryClient directory;
  directory.StartHosting(hosted, 0x58410A7A, 30741);
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(20);
  while (heartbeats.load() == 0 && std::chrono::steady_clock::now() < deadline)
    std::this_thread::sleep_for(std::chrono::milliseconds(25));
  // A wrong-type heartbeat must preserve the established lobby and retry it.
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  {
    std::lock_guard lock(*hosted->mutex);
    CHECK(hosted->status_invite_code == "ABC234");
  }
  directory.StopHosting();
  server.request_stop();
  server.join();
  std::vector<rex::LogEntry> entries;
  logs->CopyEntries(entries);
  bool invitation_ready_logged = false;
  for (const auto& entry : entries) {
    CHECK(entry.text.find("ABC234") == std::string::npos);
    CHECK(entry.text.find("host-test-token") == std::string::npos);
    invitation_ready_logged |= entry.text.find("invitation ready in lobby and private launcher state") != std::string::npos;
  }
  CHECK(invitation_ready_logged);

  CHECK(registrations.load() == 2);
  CHECK(heartbeats.load() >= 1);
  CHECK(polls.load() >= 1);
  CHECK(deletions.load() == 1);
  REQUIRE(registration_bodies.size() == 2);
  CHECK(registration_bodies[0] == registration_bodies[1]);
  CHECK(registration_bodies[0].find("\"host_instance_token\":\"") != std::string::npos);
  // An open lobby is published as findable by in-game team search.
  CHECK(registration_bodies[0].find("\"listing\":{") != std::string::npos);
  CHECK(registration_bodies[0].find("\"searchable\":true") != std::string::npos);
  CHECK(registration_bodies[0].find("\"host_xuid\":\"0000000000001001\"") != std::string::npos);
  {
    std::lock_guard lock(*hosted->mutex);
    CHECK(hosted->status_invite_code.empty());
  }
}

TEST_CASE("Linux session directory resolves and claims an invite over loopback HTTP",
          "[session][directory][linux]") {
  constexpr std::string_view session_json =
      R"({"session_id":"session-token","server_name":"Alice","player_count":1,"max_players":6,"title_id":"58410A7A","protocol_version":1,"build_id":"harmony-test","connectivity_candidates":[{"type":"public","address":"203.0.113.7","discovery_port":30741,"gameplay_port":30742}]})";
  constexpr std::string_view attempt_json =
      R"({"attempt_id":"0123456789abcdef0123456789abcdef","capability":"fedcba9876543210fedcba9876543210","rendezvous_host":"127.0.0.1","rendezvous_port":30740,"participant":"client","purpose":"invite_code_private_eligible"})";

  const int listener = ::socket(AF_INET, SOCK_STREAM, 0);
  REQUIRE(listener >= 0);
  int reuse_address = 1;
  REQUIRE(::setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &reuse_address,
                       sizeof(reuse_address)) == 0);
  sockaddr_in address{};
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  address.sin_port = 0;
  REQUIRE(::bind(listener, reinterpret_cast<const sockaddr*>(&address), sizeof(address)) == 0);
  REQUIRE(::listen(listener, 4) == 0);
  socklen_t address_size = sizeof(address);
  REQUIRE(::getsockname(listener, reinterpret_cast<sockaddr*>(&address), &address_size) == 0);

  std::vector<std::string> requests;
  std::jthread server([&] {
    for (size_t index = 0; index < 4; ++index) {
      pollfd pending{listener, POLLIN, 0};
      if (::poll(&pending, 1, 1000) <= 0)
        break;
      const int connection = ::accept(listener, nullptr, nullptr);
      if (connection < 0)
        break;

      std::string request;
      std::array<char, 2048> buffer{};
      size_t header_end = std::string::npos;
      size_t content_length = 0;
      while (header_end == std::string::npos ||
             request.size() < header_end + 4 + content_length) {
        const ssize_t count = ::recv(connection, buffer.data(), buffer.size(), 0);
        if (count <= 0)
          break;
        request.append(buffer.data(), static_cast<size_t>(count));
        if (header_end == std::string::npos) {
          header_end = request.find("\r\n\r\n");
          if (header_end != std::string::npos) {
            const auto length_header = request.find("Content-Length:");
            if (length_header != std::string::npos && length_header < header_end) {
              const auto value_start = request.find_first_not_of(' ', length_header + 15);
              if (value_start != std::string::npos && value_start < header_end)
                content_length = static_cast<size_t>(std::stoul(request.substr(value_start)));
            }
          }
        }
      }
      requests.push_back(request);

      std::string status = "404 Not Found";
      std::string body;
      if (request.starts_with("GET /sessions/by-code/ABC234 ")) {
        status = "200 OK";
        body = "{\"session\":" + std::string(session_json) + "}";
      } else if (request.starts_with("POST /sessions/by-code/ABC234/join-attempts ")) {
        status = "201 Created";
        body = "{\"session\":" + std::string(session_json) + ",\"attempt\":" +
               std::string(attempt_json) + "}";
      } else if (request.starts_with(
                     "DELETE /sessions/session-token/join-attempts/0123456789abcdef0123456789abcdef ")) {
        status = "204 No Content";
      }
      const std::string response =
          "HTTP/1.1 " + status + "\r\nContent-Type: application/json\r\nContent-Length: " +
          std::to_string(body.size()) + "\r\nConnection: close\r\n\r\n" + body;
      size_t sent = 0;
      while (sent < response.size()) {
        const ssize_t count = ::send(connection, response.data() + sent, response.size() - sent,
                                     MSG_NOSIGNAL);
        if (count <= 0)
          break;
        sent += static_cast<size_t>(count);
      }
      ::close(connection);
    }
  });

  const auto previous_url = REXCVAR_GET(session_directory_url);
  const auto previous_build_id = REXCVAR_GET(session_directory_build_id);
  struct CvarRestore {
    std::string url;
    std::string build_id;
    ~CvarRestore() {
      REXCVAR_SET(session_directory_build_id, build_id);
      REXCVAR_SET(session_directory_url, url);
    }
  } restore{previous_url, previous_build_id};
  REXCVAR_SET(session_directory_url,
              "http://127.0.0.1:" + std::to_string(ntohs(address.sin_port)));
  REXCVAR_SET(session_directory_build_id, "harmony-test");

  SessionDirectoryClient directory;
  const auto resolved = directory.ResolveInviteCode("abc234", 0x58410A7A);
  const auto joined = directory.CreateInviteCodeJoinAttempt("ABC234", 0x58410A7A);
  DirectoryTraversalAttempt completion = joined ? joined->attempt : DirectoryTraversalAttempt{};
  if (!joined) {
    completion.session_id = "session-token";
    completion.attempt_id = "0123456789abcdef0123456789abcdef";
    completion.capability = "fedcba9876543210fedcba9876543210";
  }
  directory.CompleteJoinAttempt(completion);
  server.join();
  ::close(listener);

  REQUIRE(resolved);
  CHECK(resolved->session_id == "session-token");
  REQUIRE(joined);
  CHECK(joined->attempt.purpose == "invite_code_private_eligible");
  REQUIRE(requests.size() == 3);
  CHECK(requests[0].starts_with("GET /sessions/by-code/ABC234 "));
  CHECK(requests[1].starts_with("POST /sessions/by-code/ABC234/join-attempts "));
  const auto request_id = requests[1].find("\"request_id\":\"");
  REQUIRE(request_id != std::string::npos);
  const auto token_start = request_id + std::string_view("\"request_id\":\"").size();
  const auto token_end = requests[1].find('"', token_start);
  REQUIRE(token_end != std::string::npos);
  CHECK(token_end - token_start == 32);
  CHECK(std::all_of(requests[1].begin() + token_start, requests[1].begin() + token_end,
                    [](char value) {
                      return (value >= '0' && value <= '9') ||
                             (value >= 'a' && value <= 'f');
                    }));
  CHECK(requests[2].starts_with(
      "DELETE /sessions/session-token/join-attempts/0123456789abcdef0123456789abcdef "));
  CHECK(requests[2].find("Authorization: Bearer fedcba9876543210fedcba9876543210\r\n") !=
        std::string::npos);
}
#endif

TEST_CASE("configured invite LAN peer is attempt-owned and route selection is immutable",
          "[session][configured-invite][lan][race]") {
  constexpr uint64_t socket = 0xF1234;
  constexpr std::string_view attempt = "a5a17e71f6de46b63843e54034b24c78";
  constexpr std::string_view capability = "00112233445566778899aabbccddeeff";
  const LanAddress local{htonl(0x0A0000D9u), 53854};
  const LanAddress host{htonl(0x0A0000D5u), 30741};
  const LanAddress unrelated{htonl(0x0A0000D4u), 30741};
  struct Cleanup {
    uint64_t socket;
    std::string_view attempt;
    ~Cleanup() {
      NatProbeRetireIdentity(attempt);
      NatProbeDetach(socket);
    }
  } cleanup{socket, attempt};
  NatProbeAttach(socket, NatProbeRole::kDiscovery, local);
  REQUIRE(NatProbeInstallIdentityForSocket(
      {std::string(attempt), std::string(capability), "127.0.0.1", 30740, 1, true},
      socket));
  CHECK_FALSE(NatProbeRegisterInviteLanPeer(socket, "00000000000000000000000000000000",
                                             host));
  CHECK_FALSE(NatProbeSelectInviteDiscoveryPeer(socket, attempt, host));
  REQUIRE(NatProbeRegisterInviteLanPeer(socket, attempt, host));
  CHECK_FALSE(NatProbeRegisterInviteLanPeer(socket, attempt, unrelated));
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, host) ==
        std::vector<std::string>{std::string(attempt)});
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, unrelated).empty());
  REQUIRE(NatProbeSelectInviteDiscoveryPeer(socket, attempt, host));
  CHECK(NatProbePeer(socket) == host);
  CHECK_FALSE(NatProbeSelectInviteDiscoveryPeer(socket, attempt, unrelated));
  CHECK(NatProbeSelectInviteDiscoveryPeer(socket, attempt, host));
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, unrelated).empty());
  NatProbeRetireIdentity(attempt);
  CHECK_FALSE(NatProbePeer(socket));
  CHECK(NatProbeMatchAcknowledgedDiscoveryAttempts(socket, host).empty());
}

TEST_CASE("NAT acknowledgement follows the peer endpoint", "[session][network][nat]") {
  const LanAddress discovery_a{htonl(0xCB007101u), 8006};
  const LanAddress discovery_b{htonl(0xCB007101u), 8019};
  const LanAddress discovery_c{htonl(0xCB007101u), 8021};
  const LanAddress gameplay{htonl(0xCB007101u), 30742};
  NatProbeEndpointState discovery;
  NatProbeEndpointState gameplay_state;

  CHECK(discovery.UpdatePeer(discovery_a));
  CHECK(discovery.Acknowledge(discovery_a));
  CHECK(discovery.acknowledged());
  CHECK_FALSE(discovery.UpdatePeer(discovery_a));
  CHECK(discovery.acknowledged());

  CHECK(gameplay_state.UpdatePeer(gameplay));
  CHECK(gameplay_state.Acknowledge(gameplay));
  CHECK(discovery.UpdatePeer(discovery_b));
  CHECK_FALSE(discovery.acknowledged());
  CHECK(discovery.peer() == discovery_b);
  CHECK(gameplay_state.acknowledged());

  CHECK_FALSE(discovery.Acknowledge(discovery_a));
  CHECK_FALSE(discovery.acknowledged());
  CHECK(discovery.Acknowledge(discovery_b));
  CHECK(discovery.acknowledged());
  CHECK(discovery.UpdatePeer(discovery_c));
  CHECK_FALSE(discovery.acknowledged());
  CHECK_FALSE(discovery.UpdatePeer({}));
  CHECK(discovery.peer() == discovery_c);
  CHECK_FALSE(discovery.UpdatePeer(discovery_c));

  const LanAddress gameplay_new{htonl(0xCB007101u), 49153};
  CHECK(gameplay_state.UpdatePeer(gameplay_new));
  CHECK_FALSE(gameplay_state.acknowledged());
  CHECK(discovery.peer() == discovery_c);
}

TEST_CASE("NAT gameplay inverse translation requires the exact acknowledged endpoint",
          "[session][network][nat]") {
  NatProbeEndpointState endpoint;
  const LanAddress logical{htonl(0xAC140A04u), 30742};
  const LanAddress public_peer{htonl(0x46F34B41u), 7535};
  const LanAddress replacement{htonl(0x46F34B41u), 7536};

  CHECK_FALSE(endpoint.NormalizeAcknowledgedPeer(public_peer, logical));
  REQUIRE(endpoint.UpdatePeer(public_peer));
  CHECK_FALSE(endpoint.NormalizeAcknowledgedPeer(public_peer, logical));
  REQUIRE(endpoint.Acknowledge(public_peer));
  CHECK(endpoint.NormalizeAcknowledgedPeer(public_peer, logical) == logical);
  CHECK_FALSE(endpoint.NormalizeAcknowledgedPeer({public_peer.ipv4, 9999}, logical));
  CHECK_FALSE(endpoint.NormalizeAcknowledgedPeer({htonl(0x46F34B42u), public_peer.port}, logical));

  REQUIRE(endpoint.UpdatePeer(replacement));
  CHECK_FALSE(endpoint.NormalizeAcknowledgedPeer(public_peer, logical));
  CHECK_FALSE(endpoint.NormalizeAcknowledgedPeer(replacement, logical));
  REQUIRE(endpoint.Acknowledge(replacement));
  CHECK(endpoint.NormalizeAcknowledgedPeer(replacement, logical) == logical);
  CHECK_FALSE(endpoint.NormalizeAcknowledgedPeer(public_peer, logical));
}

TEST_CASE("independent NAT gameplay peers normalize only their own acknowledged endpoint",
          "[session][network][nat]") {
  NatProbeEndpointState first;
  NatProbeEndpointState second;
  const LanAddress first_public{htonl(0xCB007101u), 40001};
  const LanAddress second_public{htonl(0xCB007102u), 40002};
  const LanAddress first_logical{htonl(0x0A000002u), 30742};
  const LanAddress second_logical{htonl(0x0A000003u), 30742};
  REQUIRE(first.UpdatePeer(first_public));
  REQUIRE(second.UpdatePeer(second_public));
  REQUIRE(first.Acknowledge(first_public));
  REQUIRE(second.Acknowledge(second_public));

  CHECK(first.NormalizeAcknowledgedPeer(first_public, first_logical) == first_logical);
  CHECK(second.NormalizeAcknowledgedPeer(second_public, second_logical) == second_logical);
  CHECK_FALSE(first.NormalizeAcknowledgedPeer(second_public, first_logical));
  CHECK_FALSE(second.NormalizeAcknowledgedPeer(first_public, second_logical));
}

TEST_CASE("repeated NAT search uses acknowledgement for the newest mapping",
          "[session][network][nat]") {
  constexpr uint32_t original_window_ms = 250;
  const LanAddress client_a{htonl(0xCB007171u), 8006};
  const LanAddress client_b{htonl(0xCB007171u), 8019};
  const LanAddress host{htonl(0xC6336401u), 30741};
  NatProbeEndpointState host_discovery;

  REQUIRE(host_discovery.UpdatePeer(client_a));
  REQUIRE(host_discovery.Acknowledge(client_a));
  REQUIRE(host_discovery.acknowledged());

  REQUIRE(host_discovery.UpdatePeer(client_b));
  CHECK_FALSE(host_discovery.acknowledged());
  CHECK_FALSE(host_discovery.Acknowledge(client_a));
  REQUIRE(host_discovery.Acknowledge(client_b));
  REQUIRE(host_discovery.acknowledged());

  SearchTimingBudget search_two(original_window_ms, true);
  LateTraversalQueryState late_query(true);
  REQUIRE(search_two.InNatExtension(962));
  CHECK(late_query.TakeAcknowledgedPeer(search_two.IsActive(962), host) == host);
  CHECK_FALSE(late_query.TakeAcknowledgedPeer(search_two.IsActive(963), host));
}

TEST_CASE("a replacement search retires only the previous discovery generation",
          "[session][network][nat]") {
  RetainedDiscoverySearchState discovery;
  RetainedDiscoverySearchState gameplay;

  discovery.Retain(2);
  gameplay.Retain(100);
  REQUIRE(discovery.IsRetained(2));

  CHECK(discovery.Retire() == 2);
  CHECK_FALSE(discovery.generation());
  CHECK(gameplay.IsRetained(100));

  discovery.Retain(3);
  CHECK(discovery.IsRetained(3));
  CHECK_FALSE(discovery.IsRetained(2));
  CHECK_FALSE(discovery.Retire() == 2);
  CHECK_FALSE(discovery.generation());
  CHECK(gameplay.IsRetained(100));
}

TEST_CASE("late traversal acknowledgement triggers one bounded discovery query",
          "[session][network][nat]") {
  const LanAddress peer{htonl(0xCB007171u), 49152};
  LateTraversalQueryState state(true);

  CHECK_FALSE(state.TakeAcknowledgedPeer(true, std::nullopt));
  CHECK(state.TakeAcknowledgedPeer(true, peer) == peer);
  CHECK_FALSE(state.TakeAcknowledgedPeer(true, peer));
}

TEST_CASE("late traversal query is suppressed outside the active search window",
          "[session][network][nat]") {
  const LanAddress peer{htonl(0xCB007171u), 49152};
  LateTraversalQueryState expired(true);
  LateTraversalQueryState lan(false);
  LateTraversalQueryState initially_ready(true, peer);

  CHECK_FALSE(expired.TakeAcknowledgedPeer(false, peer));
  CHECK_FALSE(lan.TakeAcknowledgedPeer(true, peer));
  CHECK_FALSE(initially_ready.TakeAcknowledgedPeer(true, peer));
}

TEST_CASE("NAT search timing adds a bounded traversal-only grace window",
          "[session][network][nat]") {
  constexpr uint32_t original_window_ms = 250;
  SearchTimingBudget lan(original_window_ms, false);
  SearchTimingBudget nat(original_window_ms, true);

  CHECK(lan.original_window_ms() == original_window_ms);
  CHECK(lan.total_window_ms() == original_window_ms);
  CHECK(lan.IsActive(249));
  CHECK_FALSE(lan.IsActive(250));
  CHECK_FALSE(lan.InNatExtension(249));

  CHECK(nat.original_window_ms() == original_window_ms);
  CHECK(nat.total_window_ms() == original_window_ms + SearchTimingBudget::kNatGraceMs);
  CHECK(nat.IsActive(249));
  CHECK(nat.InNatExtension(250));
  CHECK(nat.InNatExtension(nat.total_window_ms() - 1));
  CHECK_FALSE(nat.IsActive(nat.total_window_ms()));
  CHECK_FALSE(nat.InNatExtension(nat.total_window_ms()));
}

TEST_CASE("late acknowledgement query obeys the NAT extended deadline", "[session][network][nat]") {
  constexpr uint32_t original_window_ms = 250;
  const LanAddress peer{htonl(0xCB007171u), 49152};
  SearchTimingBudget nat(original_window_ms, true);

  SECTION("acknowledgement before original deadline behaves normally") {
    LateTraversalQueryState query(true);
    CHECK(query.TakeAcknowledgedPeer(nat.IsActive(200), peer) == peer);
    CHECK_FALSE(query.TakeAcknowledgedPeer(nat.IsActive(201), peer));
  }

  SECTION("acknowledgement inside extension triggers exactly once") {
    LateTraversalQueryState query(true);
    CHECK(nat.InNatExtension(962));
    CHECK(query.TakeAcknowledgedPeer(nat.IsActive(962), peer) == peer);
    CHECK_FALSE(query.TakeAcknowledgedPeer(nat.IsActive(963), peer));
  }

  SECTION("invalid or post-deadline acknowledgement does not trigger") {
    LateTraversalQueryState invalid(true);
    LateTraversalQueryState expired(true);
    CHECK_FALSE(invalid.TakeAcknowledgedPeer(nat.IsActive(962), std::nullopt));
    CHECK_FALSE(expired.TakeAcknowledgedPeer(nat.IsActive(nat.total_window_ms()), peer));
  }
}

TEST_CASE("explicit LAN bind address is the network identity source of truth",
          "[session][network]") {
  auto previous = REXCVAR_GET(lan_bind_address);
  REXCVAR_SET(lan_bind_address, "192.168.50.213");
  CHECK(ntohl(LanDiscoveryService::DetermineLanIpv4()) == 0x0A0000D5u);
  REXCVAR_SET(lan_bind_address, previous);
}

TEST_CASE("user profiles can expose distinct multiplayer identities", "[session][identity]") {
  UserProfile desktop(0xB13E000000000001ull, "DesktopHost");
  UserProfile ally(0xB13E000000000002ull, "AllyClient");

  CHECK(desktop.xuid() != ally.xuid());
  CHECK(desktop.name() == "DesktopHost");
  CHECK(ally.name() == "AllyClient");
}

TEST_CASE("LAN-online profile satisfies Harmony online preflight", "[session][identity]") {
  UserProfile offline(0x1001, "Offline", false);
  UserProfile desktop(0x1001, "DesktopHost", true);
  UserProfile ally(0x1002, "ROGAlly", true);

  CHECK(offline.signin_state() == 1);
  CHECK_FALSE(offline.HasPrivilege(251));
  CHECK_FALSE(offline.HasPrivilege(252));
  CHECK_FALSE(offline.HasPrivilege(254));

  CHECK(desktop.signin_state() == 2);
  CHECK_FALSE(desktop.HasPrivilege(251));
  CHECK_FALSE(desktop.HasPrivilege(252));
  CHECK(desktop.HasPrivilege(254));
  CHECK(desktop.GetSetting(0x1004000C));
  CHECK(desktop.GetSetting(0x1004000D));
  CHECK(desktop.GetSetting(0x1004000E));

  CHECK(ally.signin_state() == 2);
  CHECK(ally.xuid() != desktop.xuid());
  CHECK(ally.name() != desktop.name());
}

TEST_CASE("session registry tracks create join details leave and delete", "[session]") {
  SessionRegistry registry;
  auto session = registry.Create(0x1001, "Desktop", {0x01020304, 3074}, 1, 4, 2);

  REQUIRE(session);
  CHECK(registry.List().size() == 1);
  CHECK(session->members.size() == 1);
  CHECK(session->OpenPublicSlots() == 3);

  REQUIRE(registry.Join(session->info.id, {0x1002, "Ally", 0, false, false, false}));
  auto details = registry.Find(session->info.id);
  REQUIRE(details);
  CHECK(details->members.size() == 2);
  CHECK(details->FilledPublicSlots() == 2);
  CHECK(details->OpenPublicSlots() == 2);

  REQUIRE(registry.Modify(session->info.id, 3, 6, 1));
  CHECK(details->flags == 3);
  CHECK(details->max_public_slots == 6);
  REQUIRE(registry.Start(session->info.id));
  CHECK(details->state == SessionState::kInGame);
  REQUIRE(registry.End(session->info.id));
  CHECK(details->state == SessionState::kReporting);

  REQUIRE(registry.Leave(session->info.id, 0x1002));
  CHECK(details->members.size() == 1);
  REQUIRE(registry.Delete(session->info.id));
  CHECK_FALSE(registry.Find(session->info.id));
}

TEST_CASE("distinct sessions are not conflated", "[session]") {
  SessionRegistry registry;
  auto first = registry.Create(1, "One", {0x0100007F, 3074}, 1, 2, 0);
  auto second = registry.Create(2, "Two", {0x0200007F, 3074}, 1, 2, 0);
  REQUIRE(first->info.id != second->info.id);
  CHECK(registry.Find(first->info.id)->host_xuid == 1);
  CHECK(registry.Find(second->info.id)->host_xuid == 2);
  CHECK(registry.List().size() == 2);
}

TEST_CASE("session search excludes only the configured local host identity", "[session]") {
  SessionRegistry registry;
  auto local = registry.Create(0x1001, "DesktopHost", {0xD500000A, 3074}, 1, 6, 0);
  SessionRecord remote_record;
  remote_record.info.id = {1, 2, 3, 4, 5, 6, 7, 8};
  remote_record.info.host_address = {0x1301000A, 3074};
  remote_record.host_xuid = 0x1002;
  remote_record.host_name = "ROGAlly";
  remote_record.max_public_slots = 6;
  remote_record.members.push_back({0x1002, "ROGAlly", 0, false, false, false});
  auto remote_id = remote_record.info.id;
  registry.UpsertDiscovered(std::move(remote_record));

  auto visible = registry.ListRemote(0x1001);
  REQUIRE(visible.size() == 1);
  CHECK(visible[0]->info.id == remote_id);
  CHECK(visible[0]->host_xuid == 0x1002);
  CHECK(visible[0]->info.id != local->info.id);
}

TEST_CASE("abandoned local host records are deleted without touching remote sessions",
          "[session]") {
  SessionRegistry registry;
  registry.Create(0x1001, "DesktopHost", {0xD500000A, 3074}, 1, 6, 0);
  auto remote = registry.Create(0x1002, "ROGAlly", {0x1301000A, 3074}, 1, 6, 0);

  CHECK(registry.DeleteHostedBy(0x1001) == 1);
  CHECK(registry.List().size() == 1);
  REQUIRE(registry.Find(remote->info.id));
  CHECK(registry.Find(remote->info.id)->host_xuid == 0x1002);
}

TEST_CASE("host advertisement follows the actual guest UDP socket port", "[session]") {
  SessionRegistry registry;
  auto hosted = registry.Create(0x1001, "DesktopHost", {0xD500000A, 3074}, 1, 6, 0);

  CHECK(registry.UpdateHostedPort(0x1001, 59395) == 1);
  CHECK(hosted->info.host_address.port == 59395);
  CHECK(registry.UpdateHostedPort(0x1002, 60000) == 0);
  CHECK(hosted->info.host_address.port == 59395);
}

TEST_CASE("public traversal updates only a discovered remote gameplay endpoint",
          "[session][network]") {
  SessionRegistry registry;
  auto local = registry.Create(0x1001, "DesktopHost", {0xD500000A, 30742}, 1, 6, 0);
  SessionRecord remote_record;
  remote_record.info.id = {1, 2, 3, 4, 5, 6, 7, 8};
  remote_record.info.host_address = {0x1301000A, 30742};
  remote_record.host_xuid = 0x1002;
  remote_record.max_public_slots = 6;
  auto remote_id = remote_record.info.id;
  registry.UpsertDiscovered(std::move(remote_record));

  const LanAddress mapped{0x710000CB, 49152};
  CHECK(registry.UpdateRemoteGameplayEndpoint(0x1001, mapped) == 1);
  CHECK(registry.Find(remote_id)->info.host_address == mapped);
  CHECK(local->info.host_address == LanAddress{0xD500000A, 30742});
  CHECK(registry.UpdateRemoteGameplayEndpoint(0x1001, mapped) == 0);
}

TEST_CASE("abandoned local session ID cannot be rediscovered through another address",
          "[session]") {
  SessionRegistry registry;
  auto local = registry.Create(0x1001, "DesktopHost", {0xD500000A, 3074}, 1, 6, 0);
  SessionRecord delayed_advertisement = *local;
  delayed_advertisement.host_xuid = 0xDEADBEEF;
  delayed_advertisement.info.host_address = {0x1301000A, 3074};

  REQUIRE(registry.Delete(local->info.id));
  registry.UpsertDiscovered(std::move(delayed_advertisement));

  CHECK_FALSE(registry.Find(local->info.id));
  CHECK(registry.ListRemote(0x1001).empty());
}

TEST_CASE("discovered session preserves LAN address identity", "[session][network]") {
  SessionRegistry registry;
  SessionRecord discovered;
  discovered.info.id = {1, 2, 3, 4, 5, 6, 7, 8};
  discovered.info.host_address = {0x0101A8C0u, 3074};
  discovered.host_xuid = 0x2002;
  discovered.host_name = "Ally";
  discovered.max_public_slots = 4;
  discovered.members.push_back({0x2002, "Ally", 0, false, false, false});
  registry.UpsertDiscovered(discovered);

  auto round_trip = registry.Find(discovered.info.id);
  REQUIRE(round_trip);
  CHECK(round_trip->info.host_address == discovered.info.host_address);
  CHECK(round_trip->host_xuid == discovered.host_xuid);
}

TEST_CASE("LAN discovery advertises and returns a created session", "[session][network]") {
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t discovery_port = 39041;
  SessionRegistry host_registry;
  auto hosted = host_registry.Create(0xB13E000000000001ull, "DesktopHost",
                                     {LanDiscoveryService::DetermineLanIpv4(), 3074}, 1, 4, 0);
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_0;
  LanDiscoveryService host(0, discovery_port);
  host.SetTitleId(title_id);
  REQUIRE(host.Advertise(hosted));

  LegacyLanDiagnosticsScope legacy_lan_diagnostics_1;
  LanDiscoveryService client(title_id, discovery_port);
  auto results = client.Search(500, 4);
  REQUIRE(results.size() == 1);
  CHECK(results[0].info.id == hosted->info.id);
  CHECK(results[0].host_xuid == hosted->host_xuid);
  CHECK(results[0].host_name == "DesktopHost");
  CHECK(results[0].info.host_address.port == 3074);
}

TEST_CASE("direct connect discovers and joins a host without LAN broadcast", "[session][network]") {
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t discovery_port = 39043;
  auto previous_bind = REXCVAR_GET(lan_bind_address);
  auto previous_direct = REXCVAR_GET(direct_connect_address);
  auto previous_directory_url = REXCVAR_GET(session_directory_url);
  auto previous_build_id = REXCVAR_GET(session_directory_build_id);
  struct CvarRestore {
    std::string bind;
    std::string direct;
    std::string directory_url;
    std::string build_id;
    ~CvarRestore() {
      REXCVAR_SET(session_directory_build_id, build_id);
      REXCVAR_SET(session_directory_url, directory_url);
      REXCVAR_SET(direct_connect_address, direct);
      REXCVAR_SET(lan_bind_address, bind);
    }
  } restore{previous_bind, previous_direct, previous_directory_url, previous_build_id};
  REXCVAR_SET(lan_bind_address, "127.0.0.1");
  REXCVAR_SET(direct_connect_address, "127.0.0.1");
  // Manual Direct Connect remains authoritative even when a directory is
  // configured but unavailable.
  REXCVAR_SET(session_directory_url, "http://127.0.0.1:1");
  REXCVAR_SET(session_directory_build_id, "test-build");

  SessionRegistry host_registry;
  auto hosted = host_registry.Create(0x1001, "DesktopHost", {htonl(0xC0A8320Au), 30742}, 1, 6, 0);
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_2;
  LanDiscoveryService host(title_id, discovery_port);
  REQUIRE(host.Advertise(hosted));

  LegacyLanDiagnosticsScope legacy_lan_diagnostics_3;
  LanDiscoveryService client(title_id, discovery_port);
  auto results = client.Search(500, 4);
  REQUIRE(results.size() == 1);
  CHECK(results[0].info.id == hosted->info.id);
  CHECK(results[0].info.host_address.ipv4 == htonl(INADDR_LOOPBACK));
  CHECK(results[0].info.host_address.port == 30742);
  CHECK(results[0].discovery_address.ipv4 == htonl(INADDR_LOOPBACK));
  CHECK(results[0].discovery_address.port == discovery_port);

  SessionMember client_member{0x1002, "ROGAlly", 0, true, false, false};
  // Deliberately use a service configured with a different fallback port.
  // Join must retain the endpoint that actually answered search.
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_4;
  LanDiscoveryService joining_client(title_id, discovery_port + 1);
  auto joined = joining_client.Join(results[0], client_member, 500);
  REQUIRE(joined);
  CHECK(joined->info.host_address.ipv4 == htonl(INADDR_LOOPBACK));
  CHECK(joined->members.size() == 2);
  CHECK(joined->members[1].xuid == client_member.xuid);
}

#if REX_PLATFORM_GNU_LINUX
TEST_CASE("explicit loopback discovery listener stays on its selected interface",
          "[session][network][linux][private-loopback]") {
  struct Restore {
    std::string bind = REXCVAR_GET(lan_bind_address);
    std::string listen = REXCVAR_GET(lan_discovery_listen_address);
    std::string direct = REXCVAR_GET(direct_connect_address);
    std::string url = REXCVAR_GET(session_directory_url);
    ~Restore() {
      REXCVAR_SET(lan_bind_address, bind);
      REXCVAR_SET(lan_discovery_listen_address, listen);
      REXCVAR_SET(direct_connect_address, direct);
      REXCVAR_SET(session_directory_url, url);
    }
  } restore;
  REXCVAR_SET(lan_bind_address, "127.0.0.1");
  REXCVAR_SET(lan_discovery_listen_address, "127.0.0.1");
  REXCVAR_SET(direct_connect_address, "127.0.0.1");
  REXCVAR_SET(session_directory_url, "");

  const int other = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  REQUIRE(other >= 0);
  struct SocketCleanup { int fd; ~SocketCleanup() { ::close(fd); } } cleanup{other};
  sockaddr_in address{};
  address.sin_family = AF_INET;
  REQUIRE(::inet_pton(AF_INET, "127.0.0.2", &address.sin_addr) == 1);
  REQUIRE(::bind(other, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0);
  socklen_t size = sizeof(address);
  REQUIRE(::getsockname(other, reinterpret_cast<sockaddr*>(&address), &size) == 0);
  const uint16_t port = ntohs(address.sin_port);
  constexpr uint32_t title_id = 0x58410A7A;
  SessionRegistry registry;
  auto hosted = registry.Create(1001, "LoopbackHost", {htonl(INADDR_LOOPBACK), 30742}, 1, 6, 0);
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_5;
  LanDiscoveryService host(title_id, port);
  // The existing socket on 127.0.0.2 has no SO_REUSEADDR. A wildcard listener
  // would conflict with it, so successful binding proves address isolation.
  REQUIRE(host.Advertise(hosted));
  REXCVAR_SET(lan_bind_address, "127.0.0.2");
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_6;
  LanDiscoveryService client(title_id, port);
  auto results = client.Search(500, 4);
  REQUIRE(results.size() == 1);
  CHECK(results[0].discovery_address.ipv4 == htonl(INADDR_LOOPBACK));
  CHECK(results[0].discovery_address.port == port);
  const SessionMember member{1002, "LoopbackClient", 0, true, false, false};
  auto joined = client.Join(results[0], member, 500);
  REQUIRE(joined);
  CHECK(joined->members.size() == 2);
  CHECK(registry.Find(hosted->info.id)->members.size() == 2);
}
#endif

TEST_CASE("unreachable session directory preserves LAN discovery", "[session][network]") {
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t discovery_port = 39044;
  auto previous_url = REXCVAR_GET(session_directory_url);
  auto previous_build_id = REXCVAR_GET(session_directory_build_id);
  auto previous_publish = REXCVAR_GET(session_directory_publish_address);
  auto previous_direct = REXCVAR_GET(direct_connect_address);
  struct CvarRestore {
    std::string url;
    std::string build_id;
    std::string publish;
    std::string direct;
    ~CvarRestore() {
      REXCVAR_SET(direct_connect_address, direct);
      REXCVAR_SET(session_directory_publish_address, publish);
      REXCVAR_SET(session_directory_build_id, build_id);
      REXCVAR_SET(session_directory_url, url);
    }
  } restore{previous_url, previous_build_id, previous_publish, previous_direct};
  REXCVAR_SET(direct_connect_address, "");
  REXCVAR_SET(session_directory_url, "http://127.0.0.1:1");
  REXCVAR_SET(session_directory_build_id, "test-build");
  REXCVAR_SET(session_directory_publish_address, "");

  SessionRegistry registry;
  auto hosted = registry.Create(0x1001, "DesktopHost",
                                {LanDiscoveryService::DetermineLanIpv4(), 30742}, 1, 6, 0);
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_7;
  LanDiscoveryService host(title_id, discovery_port);
  REQUIRE(host.Advertise(hosted));

  LegacyLanDiagnosticsScope legacy_lan_diagnostics_8;
  LanDiscoveryService client(title_id, discovery_port);
  auto results = client.Search(500, 4);
  REQUIRE(results.size() == 1);
  CHECK(results[0].info.id == hosted->info.id);
  CHECK(results[0].host_xuid == hosted->host_xuid);
}

TEST_CASE("pending NAT traversal preserves LAN broadcast discovery", "[session][network][nat]") {
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t discovery_port = 39045;
  constexpr std::string_view attempt = "00112233445566778899aabbccddeeff";
  struct AttemptRestore {
    std::string_view attempt;
    ~AttemptRestore() { NatProbeRetireIdentity(attempt); }
  } restore{attempt};

  SessionRegistry registry;
  auto hosted = registry.Create(0x1001, "DesktopHost",
                                {LanDiscoveryService::DetermineLanIpv4(), 30742}, 1, 6, 0);
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_9;
  LanDiscoveryService host(title_id, discovery_port);
  REQUIRE(host.Advertise(hosted));
  REQUIRE(NatProbeInstallIdentity({std::string(attempt),
                                   "ffeeddccbbaa99887766554433221100",
                                   "127.0.0.1", 39046, 1}));

  LegacyLanDiagnosticsScope legacy_lan_diagnostics_10;
  LanDiscoveryService client(title_id, discovery_port);
  auto results = client.Search(250, 4);
  REQUIRE(results.size() == 1);
  CHECK(results[0].info.id == hosted->info.id);
  CHECK(results[0].host_xuid == hosted->host_xuid);
}

TEST_CASE("directory heartbeat failures preserve one logical host registration",
          "[session][network]") {
  using Disposition = DirectoryHeartbeatDisposition;
  CHECK(ClassifyDirectoryHeartbeatResponse(std::nullopt, false) ==
        Disposition::kRetrySameRegistration);
  CHECK(ClassifyDirectoryHeartbeatResponse(500, false) == Disposition::kRetrySameRegistration);
  CHECK(ClassifyDirectoryHeartbeatResponse(503, false) == Disposition::kRetrySameRegistration);
  CHECK(ClassifyDirectoryHeartbeatResponse(200, false) == Disposition::kRetrySameRegistration);
  CHECK(ClassifyDirectoryHeartbeatResponse(404, false) == Disposition::kRecoverRegistration);
  CHECK(ClassifyDirectoryHeartbeatResponse(403, false) == Disposition::kRejected);
  CHECK(ClassifyDirectoryHeartbeatResponse(200, true) == Disposition::kAccepted);
}

TEST_CASE("invite-code directory responses use normal compatibility validation",
          "[session][directory]") {
  REQUIRE(NormalizeDirectoryInviteCode("ab7k2q"));
  CHECK(*NormalizeDirectoryInviteCode("ab7k2q") == "AB7K2Q");
  CHECK_FALSE(NormalizeDirectoryInviteCode("BAD"));
  CHECK_FALSE(NormalizeDirectoryInviteCode("ABC10O"));

  constexpr uint32_t title_id = 0x58410A7A;
  constexpr std::string_view build_id = "harmony-test";
  constexpr std::string_view valid = R"({"session":{"session_id":"session-token","server_name":"Alice","player_count":1,"max_players":6,"title_id":"58410A7A","protocol_version":1,"build_id":"harmony-test","connectivity_candidates":[{"type":"public","address":"203.0.113.7","discovery_port":30741,"gameplay_port":30742}]}})";
  auto parsed = ParseInviteCodeSessionResponse(valid, title_id, build_id);
  REQUIRE(parsed);
  CHECK(parsed->session_id == "session-token");
  CHECK(parsed->server_name == "Alice");
  REQUIRE(parsed->connectivity_candidates.size() == 1);
  CHECK(parsed->connectivity_candidates[0].type == "public");

  std::string wrong_title(valid);
  wrong_title.replace(wrong_title.find("58410A7A"), 8, "58410A7B");
  CHECK_FALSE(ParseInviteCodeSessionResponse(wrong_title, title_id, build_id));
  CHECK_FALSE(ParseInviteCodeSessionResponse(valid, title_id, "other-build"));

  std::string unsafe_candidate(valid);
  unsafe_candidate.replace(unsafe_candidate.find("203.0.113.7"), 11, "127.0.0.1");
  CHECK_FALSE(ParseInviteCodeSessionResponse(unsafe_candidate, title_id, build_id));
  CHECK_FALSE(ParseInviteCodeSessionResponse("{}", title_id, build_id));
  CHECK_FALSE(ParseInviteCodeSessionResponse("not-json", title_id, build_id));
}

TEST_CASE("active invite code launcher state is bounded and follows hosting lifecycle",
          "[session][directory]") {
  auto root = std::filesystem::temp_directory_path() /
              ("harmony-invite-state-" +
               std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
  auto path = root / "active-invite-code.txt";
  struct Cleanup {
    std::filesystem::path root;
    ~Cleanup() {
      std::error_code error;
      std::filesystem::remove_all(root, error);
    }
  } cleanup{root};

  REQUIRE(WriteActiveInviteCodeFile(path, "ab7k2q"));
  {
    std::ifstream input(path, std::ios::binary);
    std::string value((std::istreambuf_iterator<char>(input)), {});
    CHECK(value == "AB7K2Q");
  }
  REQUIRE(WriteActiveInviteCodeFile(path, "CD8M3R"));
  {
    std::ifstream input(path, std::ios::binary);
    std::string value((std::istreambuf_iterator<char>(input)), {});
    CHECK(value == "CD8M3R");
  }
  CHECK_FALSE(WriteActiveInviteCodeFile(path, "BAD"));
  CHECK_FALSE(std::filesystem::exists(path.string() + ".tmp"));
  RemoveActiveInviteCodeFile(path);
  CHECK_FALSE(std::filesystem::exists(path));
}

TEST_CASE("stopping a LAN advertisement removes the hosted session", "[session][network]") {
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t discovery_port = 39042;
  SessionRegistry registry;
  auto hosted = registry.Create(0x1001, "DesktopHost",
                                {LanDiscoveryService::DetermineLanIpv4(), 3074}, 1, 6, 0);
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_11;
  LanDiscoveryService host(title_id, discovery_port);
  REQUIRE(host.Advertise(hosted));
  CHECK(host.IsAdvertising());

  host.StopAdvertising();
  CHECK_FALSE(host.IsAdvertising());

  LegacyLanDiagnosticsScope legacy_lan_diagnostics_12;
  LanDiscoveryService client(title_id, discovery_port);
  CHECK(client.Search(100, 4).empty());
}

TEST_CASE("discovered XNADDR reconstruction is byte-identical to host generation",
          "[session][xnaddr]") {
  constexpr uint64_t host_xuid = 0xB13E102030405060ull;
  SessionRegistry registry;
  auto hosted = registry.Create(host_xuid, "Host",
                                {htonl(INADDR_LOOPBACK), 30742}, 1, 4, 2);
  const auto discovered = ReconstructXnAddrIdentity(host_xuid);
  REQUIRE(hosted);
  CHECK(std::memcmp(hosted->info.ethernet_address.data(),
                    discovered.ethernet_address.data(),
                    discovered.ethernet_address.size()) == 0);
  CHECK(std::memcmp(hosted->info.online_address.data(),
                    discovered.online_address.data(),
                    discovered.online_address.size()) == 0);
  CHECK(hosted->info.ethernet_address ==
        std::array<uint8_t, 6>{0x60, 0x50, 0x40, 0x30, 0x20, 0x10});
  CHECK(hosted->info.online_address ==
        std::array<uint8_t, 20>{0x60, 0x50, 0x40, 0x30, 0x20, 0x10, 0x3E,
                                0xB1});
}

}  // namespace rex::system::xam
