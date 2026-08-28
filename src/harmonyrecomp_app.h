// harmonyrecomp - ReXGlue Recompiled Project
//
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>
#include <rex/system.h>

#include <functional>
#include <optional>
#include <string>

#include "game_data.h"

class HarmonyrecompApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<HarmonyrecompApp>(new HarmonyrecompApp(ctx, "harmonyrecomp",
        PPCImageConfig));
  }

  void OnConfigurePaths(rex::PathConfig& paths) override {
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
  // void OnPostInitLogging() override {}
  // void OnPreSetup(rex::RuntimeConfig& config) override {}
  // void OnLoadXexImage(std::string& xex_image) override {}
  // void OnPostLoadXexImage() override {}
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // std::unique_ptr<rex::ui::ImGuiDialog> CreateAchievementsOverlay() override;
  // std::unique_ptr<rex::ui::AchievementNotificationDialog>
  // CreateAchievementNotificationDialog() override;
  // void OnShutdown() override {}
  // void OnConfigurePaths(rex::PathConfig& paths) override {}

 private:
  bool using_imported_game_data_ = false;
};
