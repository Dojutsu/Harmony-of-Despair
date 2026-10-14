// harmonyrecomp - ReXGlue Recompiled Project
//
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>
#include <rex/system.h>
#include <rex/system/xam/session_directory.h>
#include <cstdlib>
#include <filesystem>

#include <functional>
#include <optional>
#include <string>

#include "game_data.h"
#if defined(__linux__)
#include "linux_user_paths.h"
#include "linux_title_capture.h"
#if !defined(__ANDROID__)
#include "linux_first_run.h"
#endif
REXCVAR_DECLARE(std::string, harmony_config_root);
REXCVAR_DECLARE(bool, harmony_start_screen);
#elif defined(__APPLE__)
#include "linux_first_run.h"
REXCVAR_DECLARE(std::string, harmony_config_root);
REXCVAR_DECLARE(bool, harmony_start_screen);
#endif

class HarmonyrecompApp : public rex::ReXApp {
#if defined(__linux__)
  std::jthread title_capture_;
#endif
 public:
  using rex::ReXApp::ReXApp;

#if defined(__linux__)
  void OnPostLaunchModule(rex::system::XThread*) override {
    if (runtime() && runtime()->graphics_system()) {
      title_capture_ = harmony::StartLinuxTitleCapture(runtime()->graphics_system()->presenter());
    }
  }

  void OnShutdown() override {
    if (title_capture_.joinable()) {
      title_capture_.request_stop();
      title_capture_.join();
    }
  }
#endif

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<HarmonyrecompApp>(new HarmonyrecompApp(ctx, "harmonyrecomp",
        PPCImageConfig));
  }

  void OnConfigurePaths(rex::PathConfig& paths) override {
#if defined(__linux__)
    const char* xdg = std::getenv("XDG_CONFIG_HOME");
    const char* home = std::getenv("HOME");
    paths.config_path = harmony::LinuxConfigPath(REXCVAR_GET(harmony_config_root),
        xdg ? xdg : "", home ? home : "");
    std::filesystem::create_directories(paths.config_path.parent_path());
#elif defined(__APPLE__)
    std::filesystem::path root(REXCVAR_GET(harmony_config_root));
    if (root.empty() || !root.is_absolute()) {
      const char* home = std::getenv("HOME");
      root = std::filesystem::path(home ? home : "/tmp") / "Library" / "Application Support";
    }
    paths.config_path = root / "HarmonyRecomp" / "harmonyrecomp.toml";
    std::filesystem::create_directories(paths.config_path.parent_path());
#endif
    // An explicit --game_data_root remains authoritative for developers and
    // advanced users. Normal launches use the private per-user import.
    using_imported_game_data_ = paths.game_data_root.empty();
    if (paths.game_data_root.empty()) {
      paths.game_data_root = harmony::game_data::DefaultRoot();
    }
#if defined(__APPLE__)
    // The Mac app has no launcher script to pass --update_data_root; the
    // imported TU2 files live in the same folder as the base game.
    if (paths.update_data_root.empty()) paths.update_data_root = paths.game_data_root;
#endif
  }

  std::optional<rex::PathConfig> OnFinalizePaths(
      const rex::PathConfig& defaults,
      std::function<void(rex::PathConfig)> resume) override {
#if (defined(__linux__) && !defined(__ANDROID__)) || defined(__APPLE__)
    // Shared DLC installed by the setup screen is linked into this profile.
    harmony::first_run::MirrorSharedDlc(defaults.game_data_root, defaults.user_data_root);
    const bool needs_setup = imgui_drawer() &&
        !harmony::game_data::ValidateRoot(defaults.game_data_root).valid &&
        harmony::first_run::CanImportInto(defaults.game_data_root);
    const bool start_screen = imgui_drawer() && REXCVAR_GET(harmony_start_screen);
    if (needs_setup || start_screen) {
      auto launch = [this, defaults, resume] {
        app_context().CallInUIThreadDeferred([defaults, resume] {
          auto paths = defaults;
          harmony::first_run::MirrorSharedDlc(paths.game_data_root, paths.user_data_root);
          resume(paths);
        });
      };
      auto quit = [this] {
        app_context().CallInUIThreadDeferred([this] { app_context().QuitFromUIThread(); });
      };
      auto show_start = [this, defaults, launch, quit] {
        const auto config_dir = defaults.config_path.parent_path();
        harmony::first_run::ShowStartScreen(imgui_drawer(), config_dir / "start-screen.txt",
            rex::cvar::GetFlagByName("user_name"), defaults.user_data_root,
            rex::cvar::GetFlagSource("user_xuid") == rex::cvar::Source::kDefault
                ? 0 : std::strtoull(rex::cvar::GetFlagByName("user_xuid").c_str(), nullptr, 0),
            [this, config_dir, launch](harmony::first_run::StartChoice choice) {
              // Same online settings as the Windows launcher; single player or
              // online is then chosen in the game's own menus.
              rex::cvar::SetFlagByName("user_name", choice.name);
              rex::cvar::SetFlagByName("user_xuid", std::to_string(choice.xuid));
              rex::cvar::SetFlagByName("lan_online", "true");
              // Linux and macOS cannot bind the title's guest port 1000 without root;
              // use the same fixed ports as the Windows launcher unless the
              // launch settings chose others (several devices behind one router).
              if (rex::cvar::GetFlagSource("lan_discovery_port") == rex::cvar::Source::kDefault)
                rex::cvar::SetFlagByName("lan_discovery_port", "30741");
              if (rex::cvar::GetFlagSource("lan_gameplay_port") == rex::cvar::Source::kDefault)
                rex::cvar::SetFlagByName("lan_gameplay_port", "30742");
              if (auto address = harmony::first_run::OutboundIpv4(); !address.empty())
                rex::cvar::SetFlagByName("lan_bind_address", address);
              rex::cvar::SetFlagByName("session_directory_url", "https://hod.dojutsu.net");
              rex::cvar::SetFlagByName("session_directory_candidate_type", "public");
              rex::cvar::SetFlagByName("session_directory_invite_code", choice.invite_code);
              rex::cvar::SetFlagByName("online_status_directory", config_dir.string());
              harmony::first_run::ShowInviteCodeOverlay(imgui_drawer(), config_dir);
              launch();
            },
            quit);
      };
      if (needs_setup) {
        // First run: find and import the game files, then continue.
        harmony::first_run::ShowGameFilesSetup(imgui_drawer(), defaults.game_data_root,
            start_screen ? std::function<void()>(show_start) : std::function<void()>(launch), quit);
      } else {
        show_start();
      }
      return std::nullopt;
    }
#endif
    (void)resume;
    if (!using_imported_game_data_) return defaults;

    const auto validation = harmony::game_data::ValidateRoot(defaults.game_data_root);
    if (validation.valid) return defaults;

    std::string message =
        "Original Castlevania: Harmony of Despair game data is required.\n\n"
        "Run harmonyrecomp-import with your legally obtained Xbox 360 package "
        "or complete extracted directory, then launch HarmonyRecomp again.";
    if (!validation.errors.empty()) {
      message += "\n\nDetails: " + validation.errors.front();
    }
    rex::ShowSimpleMessageBox(rex::SimpleMessageBoxType::Error, message);
    if (window()) window()->RequestClose();
    return std::nullopt;
  }

  // Override virtual hooks for customization:
  void OnPreSetup(rex::RuntimeConfig& config) override {
#if defined(_WIN32)
    if (rex::cvar::GetFlagSource("online_status_directory") == rex::cvar::Source::kDefault) {
      if (const char* local = std::getenv("LOCALAPPDATA"); local && *local) {
        rex::cvar::SetFlagByName("online_status_directory",
            (std::filesystem::path(local) / "HarmonyRecomp").string());
      }
    }
#endif
    // Default to the Xenos GPU emulation plugin when no explicit
    // gpu_plugin was provided via command line / cvar.
    // An explicit --gpu_plugin overrides this default; an empty value
    // keeps GPU emulation disabled. When Xenos cannot be loaded the
    // ReXGlue runtime fails loudly (dialog + non-zero exit), which is
    // the intended behavior — there is no silent fallback to "no GPU".
    if (config.gpu_plugin.empty()) {
      config.gpu_plugin = "xenos";
    }

#if defined(__APPLE__)
    // Fullscreen at launch currently leaves a blank green surface on macOS;
    // start windowed unless the player chose fullscreen explicitly.
    if (rex::cvar::GetFlagSource("fullscreen") == rex::cvar::Source::kDefault) {
      rex::cvar::SetFlagByName("fullscreen", "false");
    }
#endif

    // Harmony of Despair checks bit 0 to expose the licensed full game. Match
    // --license_mask=1 only when no config, environment, or CLI value won.
    if (rex::cvar::GetFlagSource("license_mask") == rex::cvar::Source::kDefault) {
      rex::cvar::SetFlagByName("license_mask", "1");
    }

    // Directory compatibility is title-specific. ReXGlue owns the generic
    // discovery client, while Harmony pins the guest/network contract it can
    // safely join. Explicit configuration remains authoritative.
    if (rex::cvar::GetFlagSource("session_directory_build_id") ==
        rex::cvar::Source::kDefault) {
      rex::cvar::SetFlagByName("session_directory_build_id",
                              "harmony-0.0.2.4-p1");
    }
  }
  // void OnPostInitLogging() override {}
  // void OnLoadXexImage(std::string& xex_image) override {}
  // void OnPostLoadXexImage() override {}
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // std::unique_ptr<rex::ui::ImGuiDialog> CreateAchievementsOverlay() override;
  // std::unique_ptr<rex::ui::AchievementNotificationDialog>
  // CreateAchievementNotificationDialog() override;
  // void OnShutdown() override {}

 private:
  bool using_imported_game_data_ = false;
};
