// Separate process: Runtime owns its own guest mapping, so this must not share
// the unit_tests process-wide GetTestMemory mapping.
#include <rex/runtime.h>
#include <rex/logging.h>
#include <rex/system/xam/session.h>
#include <rex/system/xam/user_profile.h>
#include <inja/third_party/include/nlohmann/json.hpp>
#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char** argv) {
  using namespace rex::system::xam;
  if (argc != 2) return 2;
  rex::InitLogging();
  rex::cvar::SetFlagByName("online_status_directory", argv[1]);
  rex::cvar::SetFlagByName("user_name", "FixtureHost");
  rex::Runtime runtime("");
  rex::RuntimeConfig config;
  config.tool_mode = true;
  if (runtime.Setup(std::move(config)) != 0) return 3;
  auto* kernel = runtime.kernel_state();
  auto& manager = *kernel->session_manager();
  const auto xuid = kernel->user_profile()->xuid();
  const auto path = manager.online_status().path();
  auto session = rex::system::make_object<XSession>(kernel);
  if (!session->Initialize()) return 4;
  auto record = manager.registry().Create(xuid, "FixtureHost", {}, 1, 6, 0);
  session->set_record(record);
  auto capture = [&] { return nlohmann::json::parse(manager.online_status().Capture()); };
  if (capture()["mode"] != "hosting") return 5;
  session->set_record(nullptr);
  if (capture()["mode"] != "offline") return 6;
  SessionRecord remote;
  remote.info.id[0] = 8; remote.host_xuid = 1; remote.host_name = "RemoteHost";
  remote.max_public_slots = 6; remote.members = {{1, "RemoteHost"}, {xuid, "FixtureHost"}};
  manager.registry().UpsertDiscovered(remote);
  session->set_record(manager.registry().Find(remote.info.id));
  if (capture()["mode"] != "joined") return 7;
  remote.members.push_back({2, "Later"});
  manager.registry().UpsertDiscovered(remote);
  if (capture()["player_count"] != 2) return 8;
  session->set_record(manager.registry().Find(remote.info.id));
  if (capture()["player_count"] != 3) return 9;
  session->set_record(nullptr);
  if (capture()["mode"] != "offline") return 10;
  record = manager.registry().Create(xuid, "FixtureHost", {}, 1, 6, 0);
  session->set_record(record);
  record->SetStatusInviteCode("AB7K2Q");
  auto stop = path; stop += ".stop";
  // Test harness can inspect two independent live publishers, then request a
  // clean fixture exit. No game input, guest UI, or network traffic is needed.
  for (int i = 0; i < 1000 && !std::filesystem::exists(stop); ++i)
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  session.reset();
  runtime.Shutdown();
  if (std::filesystem::exists(path)) return 11;
  std::error_code error;
  std::filesystem::remove(stop, error);
  std::cout << "XSession attachment, replacement, release and shutdown passed\n";
  return 0;
}
