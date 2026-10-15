// harmonyrecomp - Linux/SteamOS first-run game-file setup.

#include "linux_first_run.h"

#include "dlc_manifest.h"
#include "game_data.h"

#include <rex/filesystem/devices/stfs_container_device.h>
#include <rex/input/input.h>
#include <rex/ui/imgui_controller.h>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/imgui_drawer.h>

#include <SDL3/SDL.h>
#include <imgui.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pwd.h>
#include <sys/socket.h>
#include <unistd.h>

#include <algorithm>
#include <atomic>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <random>
#include <mutex>
#include <set>
#include <string>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

namespace harmony::first_run {
namespace {

constexpr char kSharedXuid[] = "0000000000000000";
constexpr char kTitleFolder[] = "58410A7A";

fs::path RealHome() {
  // The launcher points HOME at the profile; game files live in the player's
  // real home, on an SD card or on a USB drive. HARMONY_SETUP_HOME overrides
  // the starting folder (containers and automated tests).
  if (const char* override_home = std::getenv("HARMONY_SETUP_HOME"); override_home && *override_home)
    return override_home;
  if (const passwd* entry = getpwuid(getuid()); entry && entry->pw_dir && *entry->pw_dir)
    return entry->pw_dir;
  if (const char* home = std::getenv("HOME")) return home;
  return "/";
}

std::string Display(const fs::path& path) {
  const std::string home = RealHome().string();
  std::string text = path.string();
  if (!home.empty() && home != "/" && text.rfind(home, 0) == 0) text = "~" + text.substr(home.size());
  return text.empty() ? "/" : text;
}

// ---------------------------------------------------------------------------
// Controller before the runtime exists: the runtime's input system is created
// later, so the setup screen samples the first SDL gamepad itself.

SDL_Gamepad* gamepad = nullptr;
bool gamepad_subsystem = false;

bool SampleGamepad(rex::input::X_INPUT_GAMEPAD& pad) {
  if (!gamepad_subsystem) gamepad_subsystem = SDL_InitSubSystem(SDL_INIT_GAMEPAD);
  if (!gamepad_subsystem) return false;
  if (gamepad && !SDL_GamepadConnected(gamepad)) {
    SDL_CloseGamepad(gamepad);
    gamepad = nullptr;
  }
  if (!gamepad) {
    int count = 0;
    SDL_JoystickID* ids = SDL_GetGamepads(&count);
    if (ids && count > 0) gamepad = SDL_OpenGamepad(ids[0]);
    SDL_free(ids);
    if (!gamepad) return false;
  }
  SDL_UpdateGamepads();
  uint16_t buttons = 0;
  auto map = [&](SDL_GamepadButton button, uint16_t mask) {
    if (SDL_GetGamepadButton(gamepad, button)) buttons |= mask;
  };
  map(SDL_GAMEPAD_BUTTON_SOUTH, rex::input::X_INPUT_GAMEPAD_A);
  map(SDL_GAMEPAD_BUTTON_EAST, rex::input::X_INPUT_GAMEPAD_B);
  map(SDL_GAMEPAD_BUTTON_DPAD_UP, rex::input::X_INPUT_GAMEPAD_DPAD_UP);
  map(SDL_GAMEPAD_BUTTON_DPAD_DOWN, rex::input::X_INPUT_GAMEPAD_DPAD_DOWN);
  map(SDL_GAMEPAD_BUTTON_DPAD_LEFT, rex::input::X_INPUT_GAMEPAD_DPAD_LEFT);
  map(SDL_GAMEPAD_BUTTON_DPAD_RIGHT, rex::input::X_INPUT_GAMEPAD_DPAD_RIGHT);
  pad = {};
  pad.buttons = buttons;
  const int lx = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTX);
  const int ly = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTY);
  pad.thumb_lx = int16_t(std::clamp(lx, -32767, 32767));
  pad.thumb_ly = int16_t(std::clamp(-ly, -32767, 32767));  // XInput: up is positive
  return true;
}

void ReleaseGamepad() {
  if (gamepad) SDL_CloseGamepad(gamepad);
  gamepad = nullptr;
  // Shut the subsystem down again so the game's own input driver starts it
  // fresh and receives the "controller added" events; otherwise they were
  // already consumed here and the game sees no controller.
  if (gamepad_subsystem) SDL_QuitSubSystem(SDL_INIT_GAMEPAD);
  gamepad_subsystem = false;
}

// ---------------------------------------------------------------------------
// Finding game files.

struct Candidate {
  fs::path folder;
  size_t base = 0, update = 0, dlc = 0;
};

enum class Kind { kNone, kBase, kUpdate, kDlc };

Kind Classify(const fs::path& file) {
  std::error_code ec;
  const auto size = fs::file_size(file, ec);
  if (ec || size < 0xA000) return Kind::kNone;  // smaller than any STFS package
  auto header = rex::filesystem::StfsContainerDevice::ReadPackageHeader(file);
  if (!header || header->metadata.execution_info.title_id != game_data::kTitleId) return Kind::kNone;
  using rex::system::XContentType;
  switch (header->metadata.content_type) {
    case XContentType::kArcadeTitle: return Kind::kBase;
    case XContentType::kInstaller: return Kind::kUpdate;
    case XContentType::kMarketplaceContent: return Kind::kDlc;
    default: return Kind::kNone;
  }
}

fs::path CommonAncestor(const fs::path& a, const fs::path& b) {
  fs::path result;
  for (auto ia = a.begin(), ib = b.begin(); ia != a.end() && ib != b.end() && *ia == *ib; ++ia, ++ib)
    result /= *ia;
  return result;
}

std::vector<fs::path> ScanRoots() {
  std::vector<fs::path> roots;
  const fs::path home = RealHome();
  for (const char* name : {"Downloads", "Desktop", "Documents", "Games", "Harmony"})
    roots.push_back(home / name);
  roots.push_back(home);
  std::error_code ec;
  // SD cards and USB drives on SteamOS and most desktops.
  for (const fs::path base : {fs::path("/run/media"), fs::path("/media")}) {
    for (fs::directory_iterator it(base, ec), end; !ec && it != end; it.increment(ec)) {
      if (!it->is_directory(ec)) continue;
      roots.push_back(it->path());
      std::error_code inner;
      for (fs::directory_iterator sub(it->path(), inner), stop; !inner && sub != stop; sub.increment(inner))
        if (sub->is_directory(inner)) roots.push_back(sub->path());
    }
  }
  return roots;
}

// Bounded walk: hidden folders, symlinks and very deep trees are skipped so a
// large home folder or Steam library cannot stall the screen.
void ScanFolder(const fs::path& root, int max_depth, std::set<fs::path>& visited,
                std::vector<std::pair<fs::path, Kind>>& found, std::atomic<size_t>& files,
                const std::atomic<bool>& stop) {
  std::error_code ec;
  if (!fs::is_directory(root, ec) || !visited.insert(fs::weakly_canonical(root, ec)).second) return;
  fs::recursive_directory_iterator it(root, fs::directory_options::skip_permission_denied, ec), end;
  for (; !ec && it != end && !stop; it.increment(ec)) {
    const auto name = it->path().filename().string();
    if (it->is_symlink(ec) || (!name.empty() && name[0] == '.') || name == "steamapps" ||
        name == "compatdata" || name == "shadercache") {
      if (it->is_directory(ec)) it.disable_recursion_pending();
      continue;
    }
    if (it->is_directory(ec)) {
      if (it.depth() >= max_depth) it.disable_recursion_pending();
      continue;
    }
    if (!it->is_regular_file(ec) || ++files > 200000) continue;
    if (Kind kind = Classify(it->path()); kind != Kind::kNone) found.emplace_back(it->path(), kind);
  }
}

std::vector<Candidate> Group(const std::vector<std::pair<fs::path, Kind>>& found) {
  std::vector<Candidate> candidates;
  for (const auto& [base, kind] : found) {
    if (kind != Kind::kBase) continue;
    // Nearest TU2 update: the folder holding both is what gets imported.
    fs::path best;
    for (const auto& [update, other] : found) {
      if (other != Kind::kUpdate) continue;
      fs::path common = CommonAncestor(base.parent_path(), update.parent_path());
      if (common.empty() || common == common.root_path()) continue;
      if (best.empty() || std::distance(common.begin(), common.end()) > std::distance(best.begin(), best.end()))
        best = common;
    }
    Candidate candidate{best.empty() ? base.parent_path() : best};
    if (std::any_of(candidates.begin(), candidates.end(),
                    [&](const Candidate& c) { return c.folder == candidate.folder; }))
      continue;
    for (const auto& [file, k] : found) {
      const auto relative = file.lexically_relative(candidate.folder);
      if (relative.empty() || *relative.begin() == "..") continue;
      candidate.base += k == Kind::kBase;
      candidate.update += k == Kind::kUpdate;
      candidate.dlc += k == Kind::kDlc;
    }
    candidates.push_back(candidate);
  }
  return candidates;
}

// ---------------------------------------------------------------------------
// The setup screen.

class GameFilesSetupDialog final : public rex::ui::ImGuiDialog {
 public:
  GameFilesSetupDialog(rex::ui::ImGuiDrawer* drawer, fs::path game_data_root,
                       std::function<void()> on_ready, std::function<void()> on_quit)
      : ImGuiDialog(drawer), game_data_root_(std::move(game_data_root)),
        on_ready_(std::move(on_ready)), on_quit_(std::move(on_quit)) {
    StartScan();
  }
  ~GameFilesSetupDialog() override {
    stop_ = true;
    if (worker_.joinable()) worker_.join();
  }

  bool CapturesControllerInput() const override { return true; }

 protected:
  void OnDraw(ImGuiIO& io) override {
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("##harmony-setup", nullptr,
                 ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus);
    ImGui::SetWindowFontScale(std::clamp(io.DisplaySize.y / 400.0f, 1.25f, 3.0f));
    ImGui::TextUnformatted("Castlevania: Harmony of Despair - set up your game files");
    ImGui::Separator();
    ImGui::Spacing();
    const State state = state_.load();
    if (state != drawn_state_) {
      drawn_state_ = state;
      focus_first_ = true;
      state_since_ = ImGui::GetTime();
    }
    // HARMONY_SETUP_AUTO=1 (automated tests only): take the first found folder
    // and confirm each step after a pause so every screen can be captured.
    const bool automatic = [] {
      const char* value = std::getenv("HARMONY_SETUP_AUTO");
      return value && std::string(value) == "1";
    }();
    const bool advance = automatic && ImGui::GetTime() - state_since_ > 4.0;
    if (advance && state == State::kChoose) {
      fs::path folder;
      {
        std::lock_guard lock(mutex_);
        if (!candidates_.empty()) folder = candidates_.front().folder;
      }
      if (!folder.empty()) StartInspect(folder);
    } else if (advance && state == State::kConfirm) {
      StartImport();
    } else if (advance && state == State::kDone) {
      state_since_ = 1e9;
      Join();
      auto ready = std::move(on_ready_);
      Close();
      if (ready) ready();
      ImGui::End();
      return;
    }
    switch (state_.load()) {
      case State::kScanning: DrawScanning(); break;
      case State::kChoose: DrawChoose(); break;
      case State::kBrowse: DrawBrowse(); break;
      case State::kInspecting: DrawBusy("Checking the selected folder..."); break;
      case State::kConfirm: DrawConfirm(); break;
      case State::kImporting: DrawBusy(Progress()); break;
      case State::kDone: DrawDone(); break;
      case State::kError: DrawError(); break;
    }
    ImGui::End();
  }

 private:
  enum class State { kScanning, kChoose, kBrowse, kInspecting, kConfirm, kImporting, kDone, kError };

  bool Button(const char* label) {
    const bool pressed = ImGui::Button(label, ImVec2(-FLT_MIN, 0));
    if (focus_first_) {
      ImGui::SetItemDefaultFocus();
      ImGui::SetKeyboardFocusHere(-1);
      ImGui::SetNavCursorVisible(true);
      focus_first_ = false;
    }
    return pressed;
  }

  void Join() {
    if (worker_.joinable()) worker_.join();
  }

  void StartScan() {
    Join();
    stop_ = false;
    files_ = 0;
    state_ = State::kScanning;
    worker_ = std::jthread([this] {
      std::vector<std::pair<fs::path, Kind>> found;
      std::set<fs::path> visited;
      for (const auto& root : ScanRoots()) {
        if (stop_) return;
        // The home folder itself only gets a shallow look; named folders and
        // removable drives are searched deeper.
        ScanFolder(root, root == RealHome() ? 1 : 5, visited, found, files_, stop_);
      }
      auto candidates = Group(found);
      std::lock_guard lock(mutex_);
      candidates_ = std::move(candidates);
      state_ = State::kChoose;
    });
  }

  void StartInspect(fs::path folder) {
    Join();
    selected_ = std::move(folder);
    state_ = State::kInspecting;
    worker_ = std::jthread([this] {
      auto inventory = game_data::DiscoverPackages(selected_);
      std::lock_guard lock(mutex_);
      inventory_ = std::move(inventory);
      state_ = State::kConfirm;
    });
  }

  void StartImport() {
    Join();
    state_ = State::kImporting;
    worker_ = std::jthread([this] {
      SetProgress("Copying the game and its update. This can take a few minutes...");
      game_data::ImportOptions options;
      options.source = selected_;
      options.destination = game_data_root_;
      options.replace_existing = true;  // only ever reached for a missing or empty folder
      game_data::AggregateInventory inventory;
      auto result = game_data::ImportAggregate(options, &inventory);
      if (!result.valid) {
        Fail("The game files could not be copied.", result.errors);
        return;
      }
      size_t installed = 0;
      std::vector<std::string> warnings;
      if (!inventory.dlc_packages.empty()) {
        dlc::DlcManager manager(SharedDlcRoot(game_data_root_), game_data::kTitleId);
        const fs::path staging = game_data_root_.parent_path() / "dlc.importing";
        for (const auto& package : inventory.dlc_packages) {
          SetProgress("Adding extra content " + std::to_string(installed + 1) + " of " +
                      std::to_string(inventory.dlc_packages.size()) + "...");
          auto dlc_result = manager.install(package, staging, true);
          if (dlc_result.success) ++installed;
          else warnings.push_back("Skipped " + package.filename().string());
        }
        std::error_code cleanup;
        fs::remove_all(staging, cleanup);
      }
      std::lock_guard lock(mutex_);
      done_text_ = "The game is ready.";
      if (!inventory.dlc_packages.empty())
        done_text_ += "\nExtra content added: " + std::to_string(installed) + " of " +
                      std::to_string(inventory.dlc_packages.size()) + ".";
      for (const auto& warning : warnings) done_text_ += "\n" + warning;
      state_ = State::kDone;
    });
  }

  void SetProgress(std::string text) {
    std::lock_guard lock(mutex_);
    progress_ = std::move(text);
  }
  std::string Progress() {
    std::lock_guard lock(mutex_);
    return progress_;
  }
  void Fail(std::string summary, const std::vector<std::string>& details) {
    std::lock_guard lock(mutex_);
    error_ = std::move(summary);
    for (const auto& line : details) error_ += "\n- " + line;
    state_ = State::kError;
  }

  void DrawBusy(const std::string& text) {
    ImGui::TextWrapped("%s", text.c_str());
    ImGui::Spacing();
    static const char spinner[] = "|/-\\";
    ImGui::Text("%c", spinner[int(ImGui::GetTime() * 8) % 4]);
  }

  void DrawScanning() {
    DrawBusy("Looking for your game files in your home folder, Downloads, and any SD card or "
             "USB drive... (" + std::to_string(files_.load()) + " files checked)");
    if (Button("Skip and choose a folder myself")) {
      stop_ = true;
      Join();
      OpenBrowser(RealHome());
    }
  }

  void DrawChoose() {
    std::vector<Candidate> candidates;
    {
      std::lock_guard lock(mutex_);
      candidates = candidates_;
    }
    ImGui::TextWrapped(
        "This game needs your own Castlevania: Harmony of Despair files from an Xbox 360: the "
        "game, its title update, and any extra content you own. Put them in a folder on this "
        "device, an SD card or a USB drive, then pick that folder here. Your saves are not "
        "touched.");
    ImGui::Spacing();
    if (candidates.empty()) {
      ImGui::TextWrapped("No game files were found automatically.");
    } else {
      ImGui::TextUnformatted("Found:");
    }
    for (const auto& candidate : candidates) {
      std::string label = Display(candidate.folder) + "   (game " + (candidate.base ? "yes" : "no") +
                          ", update " + (candidate.update ? "yes" : "no") + ", extra content " +
                          std::to_string(candidate.dlc) + ")##" + candidate.folder.string();
      if (Button(label.c_str())) StartInspect(candidate.folder);
    }
    ImGui::Spacing();
    if (Button("Choose a folder myself")) OpenBrowser(RealHome());
    if (Button("Search again")) StartScan();
    if (Button("Quit")) Quit();
  }

  void OpenBrowser(fs::path folder) {
    browse_ = std::move(folder);
    browse_entries_.clear();
    std::error_code ec;
    for (fs::directory_iterator it(browse_, fs::directory_options::skip_permission_denied, ec), end;
         !ec && it != end; it.increment(ec)) {
      const auto name = it->path().filename().string();
      if (!name.empty() && name[0] != '.' && it->is_directory(ec)) browse_entries_.push_back(it->path());
    }
    std::sort(browse_entries_.begin(), browse_entries_.end());
    focus_first_ = true;
    state_ = State::kBrowse;
  }

  void DrawBrowse() {
    ImGui::TextWrapped("Choose the folder that holds your game files. Folders inside it are "
                       "included.");
    ImGui::Text("Current folder: %s", Display(browse_).c_str());
    ImGui::Spacing();
    if (Button("Use this folder")) {
      StartInspect(browse_);
      return;
    }
    if (browse_.has_parent_path() && browse_ != browse_.root_path() &&
        ImGui::Button("Up one folder", ImVec2(-FLT_MIN, 0))) {
      OpenBrowser(browse_.parent_path());
      return;
    }
    if (ImGui::Button("Home folder", ImVec2(-FLT_MIN, 0))) {
      OpenBrowser(RealHome());
      return;
    }
    if (fs::is_directory("/run/media") && ImGui::Button("SD cards and USB drives", ImVec2(-FLT_MIN, 0))) {
      OpenBrowser("/run/media");
      return;
    }
    if (ImGui::Button("Back", ImVec2(-FLT_MIN, 0)) || rex::ui::DialogCancelPressed()) {
      state_ = State::kChoose;
      return;
    }
    ImGui::Separator();
    for (const auto& entry : browse_entries_) {
      std::string label = entry.filename().string() + "/##" + entry.string();
      if (ImGui::Button(label.c_str(), ImVec2(-FLT_MIN, 0))) {
        OpenBrowser(entry);
        return;
      }
    }
  }

  void DrawConfirm() {
    game_data::AggregateInventory inventory;
    {
      std::lock_guard lock(mutex_);
      inventory = inventory_;
    }
    ImGui::Text("Folder: %s", Display(selected_).c_str());
    ImGui::Spacing();
    const bool base_ok = inventory.base_packages.size() == 1;
    const bool update_ok = inventory.update_packages.size() == 1;
    ImGui::Text("Game: %s", inventory.base_packages.empty() ? "not found"
                            : base_ok ? "found" : "more than one copy found");
    ImGui::Text("Title update (required): %s", inventory.update_packages.empty() ? "not found"
                            : update_ok ? "found" : "more than one copy found");
    ImGui::Text("Extra content: %zu", inventory.dlc_packages.size());
    for (const auto& error : inventory.errors) ImGui::TextWrapped("Problem: %s", error.c_str());
    ImGui::Spacing();
    if (base_ok && update_ok && inventory.errors.empty()) {
      if (Button("Set up the game with these files")) StartImport();
    } else {
      ImGui::TextWrapped("This folder needs exactly one copy of the game and one copy of its "
                         "title update. Pick a different folder.");
    }
    if (Button("Choose a different folder") || rex::ui::DialogCancelPressed()) OpenBrowser(selected_);
    if (ImGui::Button("Quit", ImVec2(-FLT_MIN, 0))) Quit();
  }

  void DrawDone() {
    std::string text;
    {
      std::lock_guard lock(mutex_);
      text = done_text_;
    }
    ImGui::TextWrapped("%s", text.c_str());
    ImGui::Spacing();
    if (Button("Start the game")) {
      Join();
      auto ready = std::move(on_ready_);
      Close();
      if (ready) ready();
    }
  }

  void DrawError() {
    std::string text;
    {
      std::lock_guard lock(mutex_);
      text = error_;
    }
    ImGui::TextWrapped("%s", text.c_str());
    ImGui::TextWrapped("Nothing was changed. Your saves are untouched.");
    ImGui::Spacing();
    if (Button("Try a different folder")) OpenBrowser(selected_.empty() ? RealHome() : selected_);
    if (ImGui::Button("Quit", ImVec2(-FLT_MIN, 0))) Quit();
  }

  void Quit() {
    stop_ = true;
    auto quit = std::move(on_quit_);
    Close();
    if (quit) quit();
  }

  fs::path game_data_root_;
  std::function<void()> on_ready_, on_quit_;
  std::atomic<State> state_{State::kScanning};
  State drawn_state_ = State::kScanning;
  double state_since_ = 0.0;
  bool focus_first_ = true;
  std::atomic<bool> stop_{false};
  std::atomic<size_t> files_{0};
  std::jthread worker_;
  std::mutex mutex_;
  std::vector<Candidate> candidates_;
  game_data::AggregateInventory inventory_;
  fs::path selected_, browse_;
  std::vector<fs::path> browse_entries_;
  std::string progress_, done_text_, error_;
};

// ---------------------------------------------------------------------------
// Start screen: player name, Play, and join by invite code (same layout as
// the Android shell; single player or online is chosen inside the game).

constexpr char kCodeAlphabet[] = "ABCDEFGHJKMNPQRSTUVWXYZ23456789";

bool ValidName(const std::string& name) {
  if (name.empty() || name.size() > 15) return false;
  return std::all_of(name.begin(), name.end(), [](char c) { return c >= 0x20 && c <= 0x7E; });
}

std::string Trim(std::string value) {
  const auto first = value.find_first_not_of(' ');
  if (first == std::string::npos) return {};
  return value.substr(first, value.find_last_not_of(' ') - first + 1);
}

std::string NormalizeCode(const char* text) {
  std::string code;
  for (const char* c = text; *c; ++c) {
    const char upper = char(std::toupper(static_cast<unsigned char>(*c)));
    if (std::strchr(kCodeAlphabet, upper) && upper) code.push_back(upper);
  }
  return code;
}

// A profile that already has saves keeps using that player id, so the saves
// stay visible: the most recently used player folder that holds this game.
uint64_t ExistingSaveXuid(const fs::path& user_data_root) {
  std::error_code ec;
  uint64_t best = 0;
  fs::file_time_type best_time{};
  for (fs::directory_iterator it(user_data_root, ec), end; !ec && it != end; it.increment(ec)) {
    const auto name = it->path().filename().string();
    if (name.size() != 16 || name == kSharedXuid ||
        !std::all_of(name.begin(), name.end(), [](char c) { return std::isxdigit(static_cast<unsigned char>(c)); }))
      continue;
    std::error_code inner;
    const fs::path game = it->path() / kTitleFolder;
    if (!fs::is_directory(game, inner)) continue;
    const auto time = fs::last_write_time(game, inner);
    if (!best || time > best_time) {
      best = std::strtoull(name.c_str(), nullptr, 16);
      best_time = time;
    }
  }
  return best;
}

uint64_t NewXuid() {
  uint64_t value = 0;
  while (!value) {
    std::random_device device;
    value = (uint64_t(device()) << 32) | device();
    value &= ~((uint64_t(1) << 54) | (uint64_t(1) << 55));  // Harmony rejects bits 54/55
  }
  return value;
}

// One small file per profile: the player's chosen name and a random, stable
// player id so two players never collide online.
struct StartSettings {
  std::string name;
  uint64_t xuid = 0;
};

StartSettings LoadSettings(const fs::path& file) {
  StartSettings settings;
  std::ifstream in(file);
  std::string line;
  while (std::getline(in, line)) {
    const auto eq = line.find('=');
    if (eq == std::string::npos) continue;
    const auto key = line.substr(0, eq), value = line.substr(eq + 1);
    if (key == "name" && ValidName(value)) settings.name = value;
    if (key == "xuid") settings.xuid = std::strtoull(value.c_str(), nullptr, 16);
  }
  return settings;
}

void SaveSettings(const fs::path& file, const StartSettings& settings) {
  std::error_code ec;
  fs::create_directories(file.parent_path(), ec);
  const fs::path temporary = fs::path(file) += ".tmp";
  {
    std::ofstream out(temporary, std::ios::trunc);
    out << "name=" << settings.name << "\nxuid=" << std::hex << settings.xuid << "\n";
  }
  fs::rename(temporary, file, ec);
}

class StartScreenDialog final : public rex::ui::ImGuiDialog {
 public:
  StartScreenDialog(rex::ui::ImGuiDrawer* drawer, fs::path settings_file, std::string default_name,
                    const fs::path& user_data_root, uint64_t current_xuid,
                    std::function<void(StartChoice)> on_play, std::function<void()> on_quit)
      : ImGuiDialog(drawer), settings_file_(std::move(settings_file)),
        on_play_(std::move(on_play)), on_quit_(std::move(on_quit)) {
    settings_ = LoadSettings(settings_file_);
    if (!settings_.xuid) settings_.xuid = ExistingSaveXuid(user_data_root);
    if (!settings_.xuid) settings_.xuid = current_xuid;
    if (!settings_.xuid) settings_.xuid = NewXuid();
    std::string name = settings_.name.empty() ? Trim(default_name) : settings_.name;
    if (!ValidName(name)) name = "Player";
    std::snprintf(name_, sizeof(name_), "%s", name.c_str());
  }

  bool CapturesControllerInput() const override { return true; }

 protected:
  void OnDraw(ImGuiIO& io) override {
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("##harmony-start", nullptr,
                 ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus);
    ImGui::SetWindowFontScale(std::clamp(io.DisplaySize.y / 400.0f, 1.25f, 3.0f));
    ImGui::TextUnformatted("Castlevania: Harmony of Despair");
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::TextUnformatted("Player name");
    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::InputText("##name", name_, sizeof(name_));
    const std::string name = Trim(name_);
    const bool name_ok = ValidName(name);
    if (!name_ok) ImGui::TextWrapped("Use 1 to 15 letters, numbers or symbols.");
    ImGui::Spacing();

    ImGui::BeginDisabled(!name_ok);
    bool play = ImGui::Button("Play", ImVec2(-FLT_MIN, 0));
    if (first_) {
      ImGui::SetItemDefaultFocus();
      ImGui::SetKeyboardFocusHere(-1);
      ImGui::SetNavCursorVisible(true);
      first_ = false;
    }
    ImGui::EndDisabled();
    ImGui::TextWrapped("Choose single player or online inside the game.");
    ImGui::Spacing();
    ImGui::Separator();

    ImGui::TextUnformatted("Join a friend: invite code");
    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::InputText("##code", code_, sizeof(code_), ImGuiInputTextFlags_CharsUppercase);
    const std::string code = NormalizeCode(code_);
    ImGui::BeginDisabled(!name_ok || code.size() != 6);
    const bool join = ImGui::Button("Join", ImVec2(-FLT_MIN, 0));
    ImGui::EndDisabled();
    ImGui::Spacing();
    ImGui::TextDisabled("Text boxes: press A, then Steam + X for the on-screen keyboard.");
    const bool quit = ImGui::Button("Quit", ImVec2(-FLT_MIN, 0));
    ImGui::End();
    // HARMONY_SETUP_AUTO=1 (automated tests only): press Play after a pause.
    if (const char* automatic = std::getenv("HARMONY_SETUP_AUTO");
        automatic && std::string(automatic) == "1" && !play && !join) {
      if (shown_at_ < 0) shown_at_ = ImGui::GetTime();
      play = ImGui::GetTime() - shown_at_ > 6.0;
    }

    if ((play || join) && name_ok) {
      settings_.name = name;
      SaveSettings(settings_file_, settings_);
      auto next = std::move(on_play_);
      Close();
      if (next) next(StartChoice{name, settings_.xuid, join ? code : std::string()});
    } else if (quit) {
      auto next = std::move(on_quit_);
      Close();
      if (next) next();
    }
  }

 private:
  fs::path settings_file_;
  std::function<void(StartChoice)> on_play_;
  std::function<void()> on_quit_;
  StartSettings settings_;
  char name_[64] = {};
  char code_[16] = {};
  bool first_ = true;
  double shown_at_ = -1;
};

// Only while hosting a lobby, the invite code alone is shown small in the
// lower left so friends can be told it (matches the Android overlay).
class InviteCodeOverlay final : public rex::ui::ImGuiDialog {
 public:
  InviteCodeOverlay(rex::ui::ImGuiDrawer* drawer, fs::path status_directory)
      : ImGuiDialog(drawer), status_directory_(std::move(status_directory)) {}

 protected:
  void OnDraw(ImGuiIO& io) override {
    if (ImGui::GetTime() >= next_poll_) {
      next_poll_ = ImGui::GetTime() + 2.0;
      code_ = ReadCode();
    }
    if (code_.empty()) return;
    ImGui::SetNextWindowPos(ImVec2(12, io.DisplaySize.y - 12), ImGuiCond_Always, ImVec2(0, 1));
    ImGui::SetNextWindowBgAlpha(0.6f);
    ImGui::Begin("##harmony-invite", nullptr,
                 ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
                     ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoNav |
                     ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing);
    ImGui::SetWindowFontScale(std::clamp(io.DisplaySize.y / 540.0f, 1.0f, 2.5f));
    ImGui::Text("Invite code: %s", code_.c_str());
    ImGui::End();
  }

 private:
  std::string ReadCode() const {
    std::error_code ec;
    std::string newest;
    fs::file_time_type newest_time{};
    for (fs::directory_iterator it(status_directory_, ec), end; !ec && it != end; it.increment(ec)) {
      const auto name = it->path().filename().string();
      if (name.rfind("online-status-", 0) != 0 || it->path().extension() != ".json") continue;
      const auto time = it->last_write_time(ec);
      if (!newest.empty() && time < newest_time) continue;
      std::ifstream in(it->path());
      std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
      std::string code;
      if (const auto key = text.find("\"invite_code\""); key != std::string::npos) {
        const auto open = text.find('"', text.find(':', key) + 1);
        const auto close = open == std::string::npos ? open : text.find('"', open + 1);
        if (close != std::string::npos) code = NormalizeCode(text.substr(open + 1, close - open - 1).c_str());
      }
      newest = code.size() == 6 ? code : std::string(" ");
      newest_time = time;
    }
    return newest == " " ? std::string() : newest;
  }

  fs::path status_directory_;
  double next_poll_ = 0;
  std::string code_;
};

}  // namespace

fs::path SharedDlcRoot(const fs::path& game_data_root) {
  return game_data_root.parent_path() / "dlc";
}

void MirrorSharedDlc(const fs::path& game_data_root, const fs::path& user_data_root) {
  if (user_data_root.empty()) return;
  const fs::path source = SharedDlcRoot(game_data_root) / kSharedXuid / kTitleFolder;
  const fs::path target = user_data_root / kSharedXuid / kTitleFolder;
  std::error_code ec;
  if (!fs::is_directory(source, ec)) return;
  for (fs::recursive_directory_iterator it(source, ec), end; !ec && it != end; it.increment(ec)) {
    const fs::path destination = target / it->path().lexically_relative(source);
    std::error_code step;
    if (it->is_symlink(step)) continue;
    if (it->is_directory(step)) {
      fs::create_directories(destination, step);
    } else if (it->is_regular_file(step) && !fs::exists(destination, step)) {
      fs::create_directories(destination.parent_path(), step);
      // Hard links share the bytes; a different filesystem falls back to a copy.
      fs::create_hard_link(it->path(), destination, step);
      if (step) fs::copy_file(it->path(), destination, fs::copy_options::skip_existing, step);
    }
  }
}

bool CanImportInto(const fs::path& root) {
  std::error_code ec;
  if (!fs::exists(root, ec)) return !ec;
  return fs::is_directory(root, ec) && fs::is_empty(root, ec);
}

void ShowGameFilesSetup(rex::ui::ImGuiDrawer* drawer, fs::path game_data_root,
                        std::function<void()> on_ready, std::function<void()> on_quit) {
  drawer->SetControllerInput(SampleGamepad, [](bool) {});
  auto finish = [drawer](std::function<void()> next) {
    return [drawer, next = std::move(next)] {
      drawer->SetControllerInput(nullptr, nullptr);
      ReleaseGamepad();
      if (next) next();
    };
  };
  new GameFilesSetupDialog(drawer, std::move(game_data_root), finish(std::move(on_ready)),
                           finish(std::move(on_quit)));
}

void ShowStartScreen(rex::ui::ImGuiDrawer* drawer, fs::path settings_file, std::string default_name,
                     const fs::path& user_data_root, uint64_t current_xuid,
                     std::function<void(StartChoice)> on_play, std::function<void()> on_quit) {
  drawer->SetControllerInput(SampleGamepad, [](bool) {});
  auto release = [drawer] {
    drawer->SetControllerInput(nullptr, nullptr);
    ReleaseGamepad();
  };
  new StartScreenDialog(drawer, std::move(settings_file), std::move(default_name), user_data_root,
      current_xuid,
      [release, next = std::move(on_play)](StartChoice choice) {
        release();
        if (next) next(std::move(choice));
      },
      [release, next = std::move(on_quit)] {
        release();
        if (next) next();
      });
}

void ShowInviteCodeOverlay(rex::ui::ImGuiDrawer* drawer, fs::path status_directory) {
  new InviteCodeOverlay(drawer, std::move(status_directory));
}

std::string OutboundIpv4() {
  // A UDP "connect" sends nothing; it only asks the kernel which local address
  // would carry internet traffic, i.e. the network the device is on right now.
  const int fd = ::socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
  if (fd < 0) return {};
  sockaddr_in remote{};
  remote.sin_family = AF_INET;
  remote.sin_port = htons(53);
  inet_pton(AF_INET, "1.1.1.1", &remote.sin_addr);
  std::string result;
  sockaddr_in local{};
  socklen_t length = sizeof(local);
  char text[INET_ADDRSTRLEN] = {};
  if (::connect(fd, reinterpret_cast<sockaddr*>(&remote), sizeof(remote)) == 0 &&
      ::getsockname(fd, reinterpret_cast<sockaddr*>(&local), &length) == 0 &&
      local.sin_addr.s_addr != htonl(INADDR_ANY) &&
      inet_ntop(AF_INET, &local.sin_addr, text, sizeof(text)))
    result = text;
  ::close(fd);
  return result;
}

}  // namespace harmony::first_run
