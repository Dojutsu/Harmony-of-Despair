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
REXCVAR_DECLARE(std::string, harmony_config_root);
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
#endif
    // An explicit --game_data_root remains authoritative for developers and
    // advanced users. Normal launches use the private per-user import.
    using_imported_game_data_ = paths.game_data_root.empty();
    if (paths.game_data_root.empty()) {
      paths.game_data_root = harmony::game_data::DefaultRoot();
    }
  }

  std::optional<rex::PathConfig> OnFinalizePaths(
      const rex::PathConfig& defaults,
      std::function<void(rex::PathConfig)> resume) override {
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
