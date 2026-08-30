#include <catch2/catch_test_macros.hpp>

#include <rex/platform.h>

#if REX_PLATFORM_WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#endif

#include <rex/system/xam/session.h>
#include <rex/system/xam/user_profile.h>
#include <rex/cvar.h>

namespace rex::system::xam {

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

  SessionMember client_member{0x1002, "ROGAlly", 0, true, false, false};
  auto joined = client.Join(results[0], client_member, 500);
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
