// harmonyrecomp - Linux/SteamOS first-run game-file setup.
//
// When the game-data folder is empty, the game shows an on-screen setup that
// works with a controller (Gaming Mode), keyboard or mouse: it finds or lets
// the player browse to their Xbox 360 content files and runs the same
// aggregate import as the Windows launcher and the Android shell (base game,
// required TU2 update, optional DLC). Saves are never read or written.

#pragma once

#include <cstdint>
#include <filesystem>
#include <functional>
#include <string>

namespace rex::ui {
class ImGuiDrawer;
}

namespace harmony::first_run {

// Shared DLC store beside the game-data folder. DLC is installed here once
// and linked into each profile's content root, so every Steam tile sees it.
std::filesystem::path SharedDlcRoot(const std::filesystem::path& game_data_root);

// Links shared DLC packages that a profile's content root is missing. Only
// creates entries under <user_data_root>/0000000000000000/<title>; existing
// files are never replaced and player save folders are never touched.
void MirrorSharedDlc(const std::filesystem::path& game_data_root,
                     const std::filesystem::path& user_data_root);

// True when `root` may be filled by the setup screen: missing or empty.
bool CanImportInto(const std::filesystem::path& root);

// Shows the setup screen. `on_ready` runs on the UI thread after a successful
// import; `on_quit` runs when the player leaves without importing.
void ShowGameFilesSetup(rex::ui::ImGuiDrawer* drawer, std::filesystem::path game_data_root,
                        std::function<void()> on_ready, std::function<void()> on_quit);

struct StartChoice {
  std::string name;
  uint64_t xuid = 0;
  std::string invite_code;  // empty: Play; six characters: join that game
};

// Start screen (player name, Play, join by invite code). Name and player id
// are remembered in `settings_file`. The player id is the one that already
// owns saves in `user_data_root`, else `current_xuid` (an explicit launch
// setting), else a new random one, so existing saves stay visible.
void ShowStartScreen(rex::ui::ImGuiDrawer* drawer, std::filesystem::path settings_file,
                     std::string default_name, const std::filesystem::path& user_data_root,
                     uint64_t current_xuid, std::function<void(StartChoice)> on_play,
                     std::function<void()> on_quit);

// Shows the host's invite code (read from the online status files) in a corner.
void ShowInviteCodeOverlay(rex::ui::ImGuiDrawer* drawer, std::filesystem::path status_directory);

// The local IPv4 address that carries internet traffic right now (Wi-Fi,
// Ethernet or a hotspot); empty when offline.
std::string OutboundIpv4();

}  // namespace harmony::first_run
