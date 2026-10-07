#include "legacy_lan_diagnostics_scope.h"
#include <catch2/catch_test_macros.hpp>
#include <rex/system/xam/session.h>
#include <rex/system/xam/session_directory.h>
#include <rex/platform.h>
#include <array>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <cstring>
#include <thread>
#if REX_PLATFORM_GNU_LINUX
#include <poll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

using namespace rex::system::xam;
#if REX_PLATFORM_GNU_LINUX
namespace {
struct LocalConfig {
  std::string bind = REXCVAR_GET(lan_bind_address);
  std::string listen = REXCVAR_GET(lan_discovery_listen_address);
  std::string directory = REXCVAR_GET(session_directory_url);
  LocalConfig() {
    REXCVAR_SET(lan_bind_address, "127.0.0.1");
    REXCVAR_SET(lan_discovery_listen_address, "127.0.0.1");
    REXCVAR_SET(session_directory_url, "");
  }
  ~LocalConfig() {
    REXCVAR_SET(lan_bind_address, bind);
    REXCVAR_SET(lan_discovery_listen_address, listen);
    REXCVAR_SET(session_directory_url, directory);
  }
};
// An owned loopback relay retains one genuine authenticated reply, then
// delivers it ahead of the next RPC's fresh reply. It never decrypts, modifies
// or logs credentials. This reproduces delayed UDP replay across API retries.
struct DelayedReplyRelay {
  int frontend = -1, upstream = -1;
  uint16_t port = 0;
  sockaddr_in host{}, client{};
  std::atomic<bool> inject_old_reply = false, injected = false, drop_join_replies = false;
  std::atomic<bool> drop_confirmation = false, replayed_initial_reply = false;
  std::jthread thread;
  explicit DelayedReplyRelay(uint16_t host_port) {
    frontend = ::socket(AF_INET,SOCK_DGRAM|SOCK_NONBLOCK|SOCK_CLOEXEC,0);
    upstream = ::socket(AF_INET,SOCK_DGRAM|SOCK_NONBLOCK|SOCK_CLOEXEC,0);
    REQUIRE(frontend >= 0); REQUIRE(upstream >= 0);
    sockaddr_in address{}; address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    REQUIRE(::bind(frontend,reinterpret_cast<sockaddr*>(&address),sizeof(address)) == 0);
    REQUIRE(::bind(upstream,reinterpret_cast<sockaddr*>(&address),sizeof(address)) == 0);
    socklen_t length = sizeof(address);
    REQUIRE(::getsockname(frontend,reinterpret_cast<sockaddr*>(&address),&length) == 0);
    port = ntohs(address.sin_port);
    host.sin_family = AF_INET; host.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    host.sin_port = htons(host_port);
    thread = std::jthread([this](std::stop_token stop) {
      std::array<uint8_t,640> first_registration_reply{}, initial_join_reply{}, packet{};
      std::array<uint8_t,16> initial_request{};
      bool initial_captured = false;
      bool captured = false;
      while (!stop.stop_requested()) {
        pollfd ready[2]{{frontend,POLLIN,0},{upstream,POLLIN,0}};
        if (::poll(ready,2,5) <= 0) continue;
        sockaddr_in source{}; socklen_t size = sizeof(source);
        if (ready[0].revents & POLLIN) {
          const auto count = ::recvfrom(frontend,packet.data(),packet.size(),MSG_TRUNC,
              reinterpret_cast<sockaddr*>(&source),&size);
          if (count == static_cast<ssize_t>(packet.size())) {
            client = source;
            if (packet[6] == 3) {
              const bool authenticated = std::any_of(packet.begin()+500,packet.begin()+516,[](uint8_t value) { return value != 0; });
              if (!authenticated) std::copy_n(packet.begin()+624,16,initial_request.begin());
              else if (drop_confirmation && initial_captured) {
                ::sendto(frontend,initial_join_reply.data(),initial_join_reply.size(),0,
                    reinterpret_cast<sockaddr*>(&client),sizeof(client));
                replayed_initial_reply = true;
                continue;
              }
            }
            if (packet[6] == 5 && captured && inject_old_reply.exchange(false)) {
              ::sendto(frontend,first_registration_reply.data(),first_registration_reply.size(),0,
                  reinterpret_cast<sockaddr*>(&client),sizeof(client));
              injected = true;
              std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
            ::sendto(upstream,packet.data(),packet.size(),0,reinterpret_cast<sockaddr*>(&host),sizeof(host));
          }
        }
        if (ready[1].revents & POLLIN) {
          size = sizeof(source);
          const auto count = ::recvfrom(upstream,packet.data(),packet.size(),MSG_TRUNC,
              reinterpret_cast<sockaddr*>(&source),&size);
          if (count == static_cast<ssize_t>(packet.size()) && source.sin_port == host.sin_port &&
              source.sin_addr.s_addr == host.sin_addr.s_addr) {
            if (packet[6] == 2 && std::equal(initial_request.begin(),initial_request.end(),packet.begin()+624)) {
              initial_join_reply = packet; initial_captured = true;
            }
            if (packet[6] == 2 && drop_join_replies) continue;
            if (packet[6] == 6 && !captured) { first_registration_reply = packet; captured = true; }
            ::sendto(frontend,packet.data(),packet.size(),0,reinterpret_cast<sockaddr*>(&client),sizeof(client));
          }
        }
      }
    });
  }
  ~DelayedReplyRelay() {
    thread.request_stop(); if (thread.joinable()) thread.join();
    if (frontend >= 0) ::close(frontend); if (upstream >= 0) ::close(upstream);
  }
};
uint16_t UnusedPort() {
  const int socket = ::socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
  REQUIRE(socket >= 0);
  sockaddr_in address{}; address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  REQUIRE(::bind(socket, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0);
  socklen_t length = sizeof(address);
  REQUIRE(::getsockname(socket, reinterpret_cast<sockaddr*>(&address), &length) == 0);
  const auto port = ntohs(address.sin_port); ::close(socket); return port;
}
}
TEST_CASE("real LAN registration collects only peers that registered and revokes departed peers",
          "[session][arbitration][network][lan]") {
  LocalConfig config;
  constexpr uint32_t title = 0x58410A7A;
  SessionRegistry host_registry, client_registry;
  const auto port = UnusedPort();
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_0;
  LanDiscoveryService host(title, port), client(title, port);
  host.SetArbitrationMachineId(host_registry.local_machine_id());
  client.SetArbitrationMachineId(client_registry.local_machine_id());
  auto hosted = host_registry.Create(10001, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 4, 0);
  REQUIRE(hosted);
  REQUIRE(host.Advertise(hosted));
  REQUIRE(hosted->arbitration->Snapshot()->registrants.empty());
  DelayedReplyRelay relay(port);
  SessionRecord discovered = *hosted;
  discovered.arbitration.reset();
  discovered.discovery_address = {htonl(INADDR_LOOPBACK), relay.port};
  auto before_join = std::make_shared<SessionRecord>(discovered);
  CHECK_FALSE(client.RegisterArbitration(before_join, 10002, hosted->nonce));
  SessionMember player{10002, "Client", 0, true, false, false};
  auto actual = client_registry.UpsertDiscovered(discovered);
  REQUIRE(actual);
  relay.drop_join_replies = true;
  CHECK_FALSE(client.Join(*actual,player,300));
  CHECK(actual->arbitration_client);
  CHECK(hosted->members.size() == 2);
  CHECK(hosted->arbitration->Snapshot()->registrants.empty());
  relay.drop_join_replies = false;
  relay.drop_confirmation = true;
  CHECK_FALSE(client.Join(*actual,player,500));
  CHECK(relay.replayed_initial_reply);
  CHECK_FALSE(client.RegisterArbitration(actual,10002,hosted->nonce));
  CHECK(hosted->arbitration->Snapshot()->registrants.empty());
  relay.drop_confirmation = false;
  // A later title retry retains the original socket/challenge/ephemeral key.
  auto joined = client.Join(*actual, player, 500);
  REQUIRE(joined);
  REQUIRE(joined->arbitration_client);
  CHECK(joined->nonce == hosted->nonce);
  CHECK(joined->host_machine_id == hosted->host_machine_id);
  CHECK(joined->arbitration_incarnation == hosted->arbitration_incarnation);
  CHECK(hosted->arbitration->Snapshot()->registrants.empty());
  CHECK_FALSE(client_registry.CommitJoinedRecord(actual,*joined,[] { return false; }));
  CHECK(actual->members.size() == 1);
  REQUIRE(client_registry.CommitJoinedRecord(actual,std::move(*joined),[] { return true; }));
  CHECK(actual->members.size() == 2);
  CHECK_FALSE(client.RegisterArbitration(actual, 10002, hosted->nonce ^ 1));
  auto first = client.RegisterArbitration(actual, 10002, hosted->nonce);
  REQUIRE(first);
  REQUIRE(first->registrants.size() == 1);
  CHECK(first->registrants[0].xuids == std::vector<uint64_t>{10002});
  CHECK(first->registrants[0].machine_id == client_registry.local_machine_id());
  CHECK(first->registrants[0].trustworthiness == 0);
  auto replay = client.RegisterArbitration(actual, 10002, hosted->nonce);
  REQUIRE(replay);
  CHECK(replay->revision == first->revision);
  CHECK(hosted->arbitration->Snapshot()->registrants.size() == 1);
  auto final = host.RegisterArbitration(hosted, 10001, hosted->nonce);
  REQUIRE(final);
  REQUIRE(final->registrants.size() == 2);
  CHECK(final->revision > first->revision);
  relay.inject_old_reply = true;
  auto refreshed = client.RegisterArbitration(actual, 10002, hosted->nonce);
  REQUIRE(refreshed);
  CHECK(relay.injected);
  CHECK(refreshed->registrants.size() == 2);
  CHECK(refreshed->revision == final->revision);
  CHECK(client_registry.CommitArbitration(actual, refreshed->identity, refreshed->revision, [] { return true; }));
  SessionMember title_member{10003,"Title metadata",0,false,false,false};
  REQUIRE(client_registry.JoinBatch(actual,std::span<const SessionMember>(&title_member,1)));
  CHECK_FALSE(client_registry.CommitArbitration(actual,refreshed->identity,refreshed->revision,[] { return true; }));
  auto latest = client.RegisterArbitration(actual,10002,hosted->nonce);
  REQUIRE(latest);
  auto left = client.Leave(*actual, 10002, 500);
  REQUIRE(left);
  REQUIRE(hosted->arbitration->Snapshot()->registrants.size() == 1);
  CHECK_FALSE(client.RegisterArbitration(actual, 10002, hosted->nonce));
  SessionRecord delayed_record = *actual;
  REQUIRE(client_registry.Leave(actual->info.id,10002));
  CHECK_FALSE(actual->arbitration_client);
  auto rejoined = client.Join(*actual,player,500);
  REQUIRE(rejoined);
  REQUIRE(client_registry.CommitJoinedRecord(actual,std::move(*rejoined),[] { return true; }));
  auto re_registered = client.RegisterArbitration(actual,10002,hosted->nonce);
  REQUIRE(re_registered);
  CHECK(re_registered->registrants.size()==2);
  REQUIRE(client.Leave(*actual,10002,500));
  REQUIRE(client_registry.Leave(actual->info.id,10002));
  REQUIRE(client_registry.Delete(actual->info.id));
  CHECK_FALSE(client_registry.UpsertDiscovered(std::move(delayed_record)));
  CHECK_FALSE(client_registry.CommitArbitration(actual, refreshed->identity, refreshed->revision, [] { return true; }));
  SessionRecord fresh_observation=*hosted; fresh_observation.arbitration.reset();
  auto fresh = client_registry.UpsertDiscovered(std::move(fresh_observation));
  REQUIRE(fresh);
  CHECK(fresh != actual);
  CHECK_FALSE(client_registry.CommitArbitration(actual,refreshed->identity,refreshed->revision,[] { return true; }));
  REQUIRE(host_registry.Delete(hosted->info.id));
  CHECK_FALSE(host.RegisterArbitration(hosted, 10001, hosted->nonce));
  host.StopAdvertising();
}

namespace {
// Real owned loopback transport; it neither opens envelopes nor records token
// bytes. Only reply correlation/MAC failures are introduced locally.
struct ExpiredJoinRelay {
  enum class Mode { kDropConfirmation, kTamperExpiry, kOldExpiry, kPass };
  int frontend = -1, upstream = -1;
  uint16_t port = 0;
  sockaddr_in host{}, client{};
  std::atomic<Mode> mode = Mode::kDropConfirmation;
  std::atomic<unsigned> expired_replies = 0;
  std::atomic<bool> tampered = false, injected_old = false, empty_receipt = true;
  std::jthread thread;
  explicit ExpiredJoinRelay(uint16_t host_port) {
    frontend = ::socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    upstream = ::socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
    REQUIRE(frontend >= 0); REQUIRE(upstream >= 0);
    sockaddr_in address{}; address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    REQUIRE(::bind(frontend, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0);
    REQUIRE(::bind(upstream, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0);
    socklen_t size = sizeof(address);
    REQUIRE(::getsockname(frontend, reinterpret_cast<sockaddr*>(&address), &size) == 0);
    port = ntohs(address.sin_port);
    host.sin_family = AF_INET; host.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    host.sin_port = htons(host_port);
    thread = std::jthread([this](std::stop_token stop) {
      std::array<uint8_t, 640> packet{}, old_expiry{};
      bool captured = false;
      while (!stop.stop_requested()) {
        pollfd ready[2]{{frontend, POLLIN, 0}, {upstream, POLLIN, 0}};
        if (::poll(ready, 2, 5) <= 0) continue;
        sockaddr_in source{}; socklen_t length = sizeof(source);
        if (ready[0].revents & POLLIN) {
          const auto count = ::recvfrom(frontend, packet.data(), packet.size(), MSG_TRUNC,
              reinterpret_cast<sockaddr*>(&source), &length);
          if (count == static_cast<ssize_t>(packet.size())) {
            client = source;
            const bool signed_join = packet[6] == 3 &&
                std::any_of(packet.begin() + 500, packet.begin() + 516,
                            [](uint8_t value) { return value != 0; });
            const auto action = mode.load();
            if (signed_join && action == Mode::kDropConfirmation) continue;
            if (signed_join && captured && action == Mode::kOldExpiry) {
              ::sendto(frontend, old_expiry.data(), old_expiry.size(), 0,
                       reinterpret_cast<sockaddr*>(&client), sizeof(client));
              injected_old = true;
            }
            ::sendto(upstream, packet.data(), packet.size(), 0,
                     reinterpret_cast<sockaddr*>(&host), sizeof(host));
          }
        }
        if (ready[1].revents & POLLIN) {
          length = sizeof(source);
          const auto count = ::recvfrom(upstream, packet.data(), packet.size(), MSG_TRUNC,
              reinterpret_cast<sockaddr*>(&source), &length);
          if (count != static_cast<ssize_t>(packet.size()) ||
              source.sin_addr.s_addr != host.sin_addr.s_addr || source.sin_port != host.sin_port)
            continue;
          if (packet[6] == 7) {
            ++expired_replies;
            if (!captured) { old_expiry = packet; captured = true; }
            // Fixed wire v2: count@64, encrypted token@484, server key/IV/tag@564.
            if (std::any_of(packet.begin() + 64, packet.begin() + 68,
                            [](uint8_t value) { return value != 0; }) ||
                std::any_of(packet.begin() + 484, packet.begin() + 500,
                            [](uint8_t value) { return value != 0; }) ||
                std::any_of(packet.begin() + 564, packet.begin() + 624,
                            [](uint8_t value) { return value != 0; })) empty_receipt = false;
            const auto action = mode.load();
            if (action == Mode::kOldExpiry) continue;
            if (action == Mode::kTamperExpiry) { packet[500] ^= 1; tampered = true; }
          }
          ::sendto(frontend, packet.data(), packet.size(), 0,
                   reinterpret_cast<sockaddr*>(&client), sizeof(client));
        }
      }
    });
  }
  ~ExpiredJoinRelay() {
    thread.request_stop(); if (thread.joinable()) thread.join();
    if (frontend >= 0) ::close(frontend);
    if (upstream >= 0) ::close(upstream);
  }
};
struct ExpiryTransportFixture {
  LocalConfig config;
  SessionRegistry host_registry, client_registry;
  uint16_t port = UnusedPort();
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_1;
  LanDiscoveryService host{0x58410A7A, port}, client{0x58410A7A, port};
  std::shared_ptr<SessionRecord> hosted, actual;
  ExpiredJoinRelay relay{port};
  SessionMember player{10002, "Client", 0, true, false, false};
  ExpiryTransportFixture() {
    host.SetArbitrationMachineId(host_registry.local_machine_id());
    client.SetArbitrationMachineId(client_registry.local_machine_id());
    hosted = host_registry.Create(10001, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 4, 0);
    REQUIRE(hosted); REQUIRE(host.Advertise(hosted));
    SessionRecord discovered = *hosted; discovered.arbitration.reset();
    discovered.discovery_address = {htonl(INADDR_LOOPBACK), relay.port};
    actual = client_registry.UpsertDiscovered(std::move(discovered)); REQUIRE(actual);
  }
  void LoseConfirmation() {
    CHECK_FALSE(client.Join(*actual, player, 500));
    REQUIRE(actual->arbitration_client);
    CHECK_FALSE(client.RegisterArbitration(actual, player.xuid, hosted->nonce));
    std::lock_guard lock(*hosted->mutex);
    REQUIRE(hosted->members.size() == 2);
    REQUIRE(hosted->arbitration->Snapshot());
    CHECK(hosted->arbitration->Snapshot()->registrants.empty());
  }
  void Retire(bool expire) {
    std::lock_guard lock(*hosted->mutex);
    if (expire) {
      // Controlled host clock exercises the same actual authority expiry and
      // roster removal transaction as the listener, without a 30s wall sleep.
      const auto expired = hosted->arbitration->ExpireUnconfirmed(
          SessionArbitrationAuthority::Clock::now() + std::chrono::seconds(31));
      REQUIRE(expired == std::vector<uint64_t>{player.xuid});
    } else REQUIRE(hosted->arbitration->Remove(player.xuid));
    std::erase_if(hosted->members, [&](const auto& member) { return member.xuid == player.xuid; });
    hosted->NotifyStatus();
    CHECK(hosted->members.size() == 1);
  }
};
} // namespace

TEST_CASE("authenticated expired join receipt rotates only the exact pending client binding",
          "[session][arbitration][network][lan][expiry]") {
  ExpiryTransportFixture fixture; fixture.LoseConfirmation();
  const auto old_binding = fixture.actual->arbitration_client;
  fixture.Retire(true);
  fixture.relay.mode = ExpiredJoinRelay::Mode::kTamperExpiry;
  CHECK_FALSE(fixture.client.Join(*fixture.actual, fixture.player, 250));
  CHECK(fixture.relay.tampered);
  CHECK(fixture.actual->arbitration_client == old_binding);
  CHECK_FALSE(fixture.client.RegisterArbitration(fixture.actual, fixture.player.xuid, fixture.hosted->nonce));
  fixture.relay.mode = ExpiredJoinRelay::Mode::kOldExpiry;
  CHECK_FALSE(fixture.client.Join(*fixture.actual, fixture.player, 250));
  CHECK(fixture.relay.injected_old);
  CHECK(fixture.actual->arbitration_client == old_binding);
  fixture.relay.mode = ExpiredJoinRelay::Mode::kPass;
  CHECK_FALSE(fixture.client.Join(*fixture.actual, fixture.player, 500));
  CHECK_FALSE(fixture.actual->arbitration_client);
  CHECK(fixture.relay.empty_receipt);
  CHECK(fixture.relay.expired_replies >= 3);
  {
    std::lock_guard lock(*fixture.hosted->mutex);
    CHECK(fixture.hosted->members.size() == 1);
    CHECK(fixture.hosted->arbitration->Snapshot()->registrants.empty());
  }
  // Only a subsequent ordinary Join creates a new key/challenge/admission.
  auto joined = fixture.client.Join(*fixture.actual, fixture.player, 500);
  REQUIRE(joined); REQUIRE(joined->arbitration_client);
  CHECK(joined->arbitration_client != old_binding);
  REQUIRE(fixture.client_registry.CommitJoinedRecord(fixture.actual, std::move(*joined), [] { return true; }));
  auto registration = fixture.client.RegisterArbitration(fixture.actual, fixture.player.xuid, fixture.hosted->nonce);
  REQUIRE(registration); REQUIRE(registration->registrants.size() == 1);
  CHECK(registration->registrants[0].xuids == std::vector<uint64_t>{fixture.player.xuid});
}

TEST_CASE("explicit leave and confirmed joins never produce expired join recovery",
          "[session][arbitration][network][lan][expiry]") {
  ExpiryTransportFixture fixture;
  SECTION("explicit removal stays fail closed without a receipt") {
    fixture.LoseConfirmation();
    const auto binding = fixture.actual->arbitration_client;
    fixture.Retire(false);
    fixture.relay.mode = ExpiredJoinRelay::Mode::kPass;
    CHECK_FALSE(fixture.client.Join(*fixture.actual, fixture.player, 300));
    CHECK(fixture.actual->arbitration_client == binding);
    CHECK(fixture.relay.expired_replies == 0);
  }
  SECTION("confirmed lobby admission survives the unconfirmed deadline") {
    fixture.relay.mode = ExpiredJoinRelay::Mode::kPass;
    auto joined = fixture.client.Join(*fixture.actual, fixture.player, 500);
    REQUIRE(joined);
    REQUIRE(fixture.client_registry.CommitJoinedRecord(fixture.actual, std::move(*joined), [] { return true; }));
    const auto binding = fixture.actual->arbitration_client;
    {
      std::lock_guard lock(*fixture.hosted->mutex);
      CHECK(fixture.hosted->arbitration->ExpireUnconfirmed(
          SessionArbitrationAuthority::Clock::now() + std::chrono::seconds(31)).empty());
    }
    auto retried = fixture.client.Join(*fixture.actual, fixture.player, 500);
    REQUIRE(retried); CHECK(retried->arbitration_client == binding);
    CHECK(fixture.relay.expired_replies == 0);
  }
}
#endif
