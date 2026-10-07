/**
 * @file        rex/ui/overlay/settings_overlay.h
 *
 * @brief       ImGui settings overlay dialog for cvar editing with save-to-config.
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 *              All rights reserved.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */
#pragma once
#include <filesystem>
#include <string>
#include <rex/ui/imgui_dialog.h>
#include <rex/ui/overlay/invitation_update_task.h>

namespace rex::ui {

class SettingsDialog : public ImGuiDialog {
 public:
  // config_path: where "Save to config" writes (e.g. exe_dir / "app.toml")
  SettingsDialog(ImGuiDrawer* imgui_drawer, std::filesystem::path config_path,
                 InvitationUpdateTask::SubmitCallback invitation_submit = {},
                 std::string initial_invitation_code = {});
  bool CapturesControllerInput() const override { return true; }
  ~SettingsDialog();

 protected:
  void OnDraw(ImGuiIO& io) override;

 private:
  std::filesystem::path config_path_;
  InvitationUpdateTask invitation_task_;
  bool invitation_available_ = false;
  bool invitation_focus_pending_ = true;
  char invitation_code_[7] = {};
  std::string invitation_status_;
  char search_buf_[128] = {};
  std::string selected_category_;
  std::string capturing_bind_name_;
};

}  // namespace rex::ui
