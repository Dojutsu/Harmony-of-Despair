#include <catch2/catch_test_macros.hpp>

#include <rex/platform.h>

#if REX_PLATFORM_WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#endif

#include <rex/system/xam/session.h>
#include <rex/system/xam/nat_probe.h>
#include <rex/system/xam/user_profile.h>
#include <rex/cvar.h>

namespace rex::system::xam {

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

TEST_CASE("late acknowledgement query obeys the NAT extended deadline",
          "[session][network][nat]") {
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

TEST_CASE("explicit LAN bind address is the network identity source of truth", "[session][network]") {
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

TEST_CASE("abandoned local host records are deleted without touching remote sessions", "[session]") {
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
  LanDiscoveryService host(0, discovery_port);
  host.SetTitleId(title_id);
  REQUIRE(host.Advertise(hosted));

  LanDiscoveryService client(title_id, discovery_port);
  auto results = client.Search(500, 4);
  REQUIRE(results.size() == 1);
  CHECK(results[0].info.id == hosted->info.id);
  CHECK(results[0].host_xuid == hosted->host_xuid);
  CHECK(results[0].host_name == "DesktopHost");
  CHECK(results[0].info.host_address.port == 3074);
}

TEST_CASE("direct connect discovers and joins a host without LAN broadcast",
          "[session][network]") {
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
  auto hosted = host_registry.Create(0x1001, "DesktopHost",
                                     {htonl(0xC0A8320Au), 30742}, 1, 6, 0);
  LanDiscoveryService host(title_id, discovery_port);
  REQUIRE(host.Advertise(hosted));

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
  LanDiscoveryService joining_client(title_id, discovery_port + 1);
  auto joined = joining_client.Join(results[0], client_member, 500);
  REQUIRE(joined);
  CHECK(joined->info.host_address.ipv4 == htonl(INADDR_LOOPBACK));
  CHECK(joined->members.size() == 2);
  CHECK(joined->members[1].xuid == client_member.xuid);
}

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
  LanDiscoveryService host(title_id, discovery_port);
  REQUIRE(host.Advertise(hosted));

  LanDiscoveryService client(title_id, discovery_port);
  auto results = client.Search(500, 4);
  REQUIRE(results.size() == 1);
  CHECK(results[0].info.id == hosted->info.id);
  CHECK(results[0].host_xuid == hosted->host_xuid);
}

TEST_CASE("stopping a LAN advertisement removes the hosted session", "[session][network]") {
  constexpr uint32_t title_id = 0x58410A7A;
  constexpr uint16_t discovery_port = 39042;
  SessionRegistry registry;
  auto hosted = registry.Create(0x1001, "DesktopHost",
                                {LanDiscoveryService::DetermineLanIpv4(), 3074}, 1, 6, 0);
  LanDiscoveryService host(title_id, discovery_port);
  REQUIRE(host.Advertise(hosted));
  CHECK(host.IsAdvertising());

  host.StopAdvertising();
  CHECK_FALSE(host.IsAdvertising());

  LanDiscoveryService client(title_id, discovery_port);
  CHECK(client.Search(100, 4).empty());
}

}  // namespace rex::system::xam
