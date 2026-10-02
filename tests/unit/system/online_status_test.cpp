#include <catch2/catch_test_macros.hpp>
#include <rex/system/xam/online_status.h>
#include <rex/system/xam/session.h>
#include <inja/third_party/include/nlohmann/json.hpp>
#include <chrono>
#include <fstream>
#include <thread>
#if REX_PLATFORM_WIN32
#include <winsock2.h>
#include <windows.h>
#endif

namespace rex::system::xam {
using nlohmann::json;

TEST_CASE("online status preserves known names without changing member semantics", "[online-status]") {
  SessionRegistry registry;
  auto record = registry.Create(1, "Host", {}, 1, 5, 1);
  REQUIRE(registry.Join(record->info.id, {2, "Alice", 3, false, false, false}));
  REQUIRE(registry.Join(record->info.id, {2, "", 4, true, true, true}));
  const auto& member = record->members.back();
  CHECK(member.name == "Alice"); CHECK(member.user_index == 4);
  CHECK(member.local); CHECK(member.private_slot); CHECK(member.ready);
  CHECK(member.xuid == 2); CHECK(record->host_xuid == 1);
  CHECK(record->members.size() == 2); CHECK(record->FilledPublicSlots() == 1);
  CHECK(record->FilledPrivateSlots() == 1);
  REQUIRE(registry.Join(record->info.id, {2, "Bob", 0, false, false, false}));
  CHECK(record->members.back().name == "Bob");
  CHECK(record->members.size() == 2); CHECK(record->FilledPrivateSlots() == 0);
}

TEST_CASE("online status follows attached membership and uses an explicit allowlist", "[online-status]") {
  OnlineStatus status(1, "Host");
  SessionRegistry registry;
  auto record = registry.Create(1, "Host", {}, 1, 5, 1);
  CHECK(json::parse(status.Capture())["mode"] == "offline");
  status.Attach(&status, record);
  record->traversal_capability = "SECRET_CAPABILITY";
  record->traversal_attempt_id = "SECRET_ATTEMPT";
  record->traversal_session_id = "PRIVATE_DIRECTORY_ID";
  record->info.key.fill(0x42);
  record->members[0].name.clear();
  record->SetStatusInviteCode("AB7K2Q");
  for (uint64_t count = 1; count <= 6; ++count) {
    if (count > 1) REQUIRE(registry.Join(record->info.id,
        {count, count == 2 ? "Alice" : "", 0, false, count == 6, false}));
    auto document = json::parse(status.Capture());
    CHECK(document["player_count"] == count); CHECK(document["max_players"] == 6);
    CHECK(document["mode"] == "hosting"); CHECK(document["invite_code"] == "AB7K2Q");
    CHECK(document["members"][0]["is_host"] == true);
    CHECK(document["members"][0]["name"] == "Host");
    if (count > 1) CHECK(document["members"][1]["name"] == "Alice");
    if (count > 2) CHECK(document["members"][2]["name"] == "Player ...0003");
    CHECK(document.size() == 8);
    CHECK(document["members"][0].size() == 3);
    CHECK(document["local_player"].size() == 2);
    CHECK(status.Capture().find("SECRET") == std::string::npos);
    CHECK(status.Capture().find("PRIVATE_DIRECTORY") == std::string::npos);
  }
  REQUIRE(registry.Leave(record->info.id, 3));
  auto document = json::parse(status.Capture());
  CHECK(document["player_count"] == 5);
  for (auto& member : document["members"]) CHECK(member["xuid"] != "0000000000000003");
  record->SetStatusInviteCode({});
  CHECK_FALSE(json::parse(status.Capture()).contains("invite_code"));
  REQUIRE(registry.Modify(record->info.id, 1, 7, 2));
  CHECK(json::parse(status.Capture())["max_players"] == 9);
  REQUIRE(registry.Start(record->info.id));
  CHECK(json::parse(status.Capture())["session_state"] == "in_game");
  REQUIRE(registry.End(record->info.id));
  CHECK(json::parse(status.Capture())["session_state"] == "reporting");
  size_t remaining = 5;
  for (uint64_t xuid : {2, 4, 5, 6, 1}) {
    REQUIRE(registry.Leave(record->info.id, xuid));
    CHECK(json::parse(status.Capture())["player_count"] == --remaining);
  }
  REQUIRE(registry.Delete(record->info.id));
  CHECK(json::parse(status.Capture())["mode"] == "offline");
  status.Detach(&status);
  CHECK(json::parse(status.Capture())["player_count"] == 0);
}

TEST_CASE("online status ignores discovery replacements until XSession reattaches", "[online-status]") {
  OnlineStatus status(2, "Guest");
  SessionRegistry registry;
  SessionRecord discovered;
  discovered.info.id[0] = 7;
  discovered.host_xuid = 1; discovered.host_name = "Host";
  discovered.max_public_slots = 6;
  discovered.members = {{1, "Host"}, {2, "Guest"}};
  registry.UpsertDiscovered(discovered);
  auto attached = registry.Find(discovered.info.id);
  status.Attach(&status, attached);
  CHECK(json::parse(status.Capture())["mode"] == "joined");
  discovered.members.push_back({3, "Later"});
  registry.UpsertDiscovered(discovered);
  CHECK(json::parse(status.Capture())["player_count"] == 2);
  status.Attach(&status, registry.Find(discovered.info.id));
  CHECK(json::parse(status.Capture())["player_count"] == 3);
  REQUIRE(registry.Leave(discovered.info.id, 2));
  CHECK(json::parse(status.Capture())["mode"] == "offline");
}

#if REX_PLATFORM_WIN32
TEST_CASE("discovery join and leave notify the attached online projection", "[online-status][network]") {
  auto old_bind = REXCVAR_GET(lan_bind_address);
  auto old_direct = REXCVAR_GET(direct_connect_address);
  auto old_directory = REXCVAR_GET(session_directory_url);
  struct Restore {
    std::string bind, direct, directory;
    ~Restore() {
      REXCVAR_SET(lan_bind_address, bind);
      REXCVAR_SET(direct_connect_address, direct);
      REXCVAR_SET(session_directory_url, directory);
    }
  } restore{old_bind, old_direct, old_directory};
  REXCVAR_SET(lan_bind_address, "127.0.0.1");
  REXCVAR_SET(direct_connect_address, "127.0.0.1");
  REXCVAR_SET(session_directory_url, "");
  SessionRegistry registry;
  auto hosted = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 30742}, 1, 6, 0);
  OnlineStatus status(1, "Host");
  status.Attach(&status, hosted);
  auto signal = hosted->status_signal.lock();
  REQUIRE(signal);
  LanDiscoveryService host(0x58410A7A, 39049), client(0x58410A7A, 39049);
  REQUIRE(host.Advertise(hosted));
  auto results = client.Search(200, 4);
  REQUIRE(results.size() == 1);
  { std::lock_guard lock(signal->mutex); signal->pending = false; }
  REQUIRE(client.Join(results[0], {2, "Alice"}, 500));
  { std::lock_guard lock(signal->mutex); CHECK(signal->pending); signal->pending = false; }
  CHECK(json::parse(status.Capture())["player_count"] == 2);
  CHECK(json::parse(status.Capture())["members"][1]["name"] == "Alice");
  REQUIRE(client.Leave(results[0], 2, 500));
  { std::lock_guard lock(signal->mutex); CHECK(signal->pending); }
  CHECK(json::parse(status.Capture())["player_count"] == 1);
  hosted->SetStatusInviteCode("AB7K2Q");
  host.StopAdvertising();
  // Directory may be disabled: StopHosting must still clear public invite state
  // associated with its hosted record when it owns one. Session deletion clears
  // the projection independently of directory availability.
  REQUIRE(registry.Delete(hosted->info.id));
  CHECK(json::parse(status.Capture())["mode"] == "offline");
}

namespace {
json ReadStatus(const std::filesystem::path& path) {
  auto file = CreateFileW(path.c_str(), GENERIC_READ,
      FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr, OPEN_EXISTING,
      FILE_ATTRIBUTE_NORMAL, nullptr);
  if (file == INVALID_HANDLE_VALUE) return {};
  LARGE_INTEGER size{};
  if (!GetFileSizeEx(file, &size) || size.QuadPart > 65536) { CloseHandle(file); return {}; }
  std::string bytes(static_cast<size_t>(size.QuadPart), '\0');
  DWORD read = 0;
  auto ok = ReadFile(file, bytes.data(), static_cast<DWORD>(bytes.size()), &read, nullptr);
  CloseHandle(file);
  if (!ok || read != bytes.size()) return {};
  return json::parse(bytes, nullptr, false);
}
template<class F> bool Eventually(F test) {
  for (int i = 0; i < 200; ++i) {
    try { if (test()) return true; } catch (const json::exception&) {}
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  return false;
}
}
TEST_CASE("online writer coalesces mutations atomically and removes only its own file", "[online-status]") {
  auto root = std::filesystem::temp_directory_path() /
      ("rex-status-" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()));
  std::filesystem::create_directories(root);
  const auto other = root / "online-status-other.json";
  { std::ofstream file(other); file << "other process"; }
  std::filesystem::path owned;
  {
    OnlineStatus status(1, "Host", root);
    owned = status.path();
    REQUIRE(Eventually([&] { return ReadStatus(owned).is_object(); }));
    SessionRegistry registry;
    auto record = registry.Create(1, "Host", {}, 1, 6, 0);
    status.Attach(&status, record);
    REQUIRE(Eventually([&] { return ReadStatus(owned).value("mode", "") == "hosting"; }));
    auto first = ReadStatus(owned);
    auto modified = std::filesystem::last_write_time(owned);
    auto signal = record->status_signal.lock();
    REQUIRE(signal);
    for (int i = 0; i < 10000; ++i) signal->Notify();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    CHECK(ReadStatus(owned)["revision"] == first["revision"]);
    CHECK(std::filesystem::last_write_time(owned) == modified);
    for (int i = 0; i < 100; ++i) {
      record->SetStatusInviteCode(i % 2 ? "AB7K2Q" : "CD8M3R");
      auto document = ReadStatus(owned);
      REQUIRE(document.is_object());
      CHECK(document["schema_version"] == 1);
      CHECK(document["process_start_time"].is_string());
    }
    record->SetStatusInviteCode("AB7K2Q");
    REQUIRE(Eventually([&] { return ReadStatus(owned).value("invite_code", "") == "AB7K2Q"; }));
    // Same locked mutation seam used by the discovery listener.
    {
      std::lock_guard lock(*record->mutex);
      record->members.push_back({2, "Alice"});
      record->NotifyStatus();
    }
    REQUIRE(Eventually([&] { return ReadStatus(owned).value("player_count", 0) == 2; }));
    status.Detach(&status);
    REQUIRE(Eventually([&] { return ReadStatus(owned).value("mode", "") == "offline"; }));
  }
  CHECK_FALSE(std::filesystem::exists(owned));
  CHECK(std::filesystem::exists(other));
  std::filesystem::remove(other); std::filesystem::remove(root);
}
#endif
}  // namespace rex::system::xam
