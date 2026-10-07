#pragma once

#include <algorithm>
#include <cmath>
#include <imgui.h>
#include <rex/input/input.h>

namespace rex::ui {

// Feed host ImGui from native driver state. Neither script rows nor guest
// memory are consumed here; ImGui owns press/release and repeat behavior.
inline void ConfigureControllerNavigation(ImGuiIO& io) {
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad;
}

class ControllerNavigation {
 public:
  void SetCaptured(bool captured) {
    if (captured && !captured_) await_release_ = true;
    captured_ = captured;
  }

  void Update(ImGuiIO& io, const input::X_INPUT_GAMEPAD& state, bool connected) {
    const bool neutral = !state.buttons && state.left_trigger <= 30 && state.right_trigger <= 30 &&
        std::abs(int(int16_t(state.thumb_lx))) < 8000 &&
        std::abs(int(int16_t(state.thumb_ly))) < 8000;
    if (!connected && captured_) await_release_ = true;
    if (connected && neutral) await_release_ = false;
    const bool enabled = connected && captured_ && !await_release_;
    if (connected) io.BackendFlags |= ImGuiBackendFlags_HasGamepad;
    else io.BackendFlags &= ~ImGuiBackendFlags_HasGamepad;
    auto button = [&](ImGuiKey key, uint16_t mask) {
      io.AddKeyEvent(key, enabled && (uint16_t(state.buttons) & mask));
    };
    button(ImGuiKey_GamepadFaceDown, input::X_INPUT_GAMEPAD_A);
    button(ImGuiKey_GamepadFaceRight, input::X_INPUT_GAMEPAD_B);
    auto direction = [&](ImGuiKey key, uint16_t mask, int value) {
      // ImGui treats stick axes as scrolling. Modal Xbox dialogs also accept
      // a deliberate stick direction for choosing buttons.
      io.AddKeyEvent(key, enabled && ((uint16_t(state.buttons) & mask) ||
                                     (captured_ && value > 16000)));
    };
    direction(ImGuiKey_GamepadDpadLeft, input::X_INPUT_GAMEPAD_DPAD_LEFT, -int(int16_t(state.thumb_lx)));
    direction(ImGuiKey_GamepadDpadRight, input::X_INPUT_GAMEPAD_DPAD_RIGHT, int(int16_t(state.thumb_lx)));
    direction(ImGuiKey_GamepadDpadUp, input::X_INPUT_GAMEPAD_DPAD_UP, int(int16_t(state.thumb_ly)));
    direction(ImGuiKey_GamepadDpadDown, input::X_INPUT_GAMEPAD_DPAD_DOWN, -int(int16_t(state.thumb_ly)));
    auto axis = [&](ImGuiKey key, int value) {
      const float level = enabled ? std::clamp((float(value) - 8000.0f) / 24767.0f, 0.0f, 1.0f) : 0.0f;
      io.AddKeyAnalogEvent(key, level > 0.1f, level);
    };
    axis(ImGuiKey_GamepadLStickLeft, -int(int16_t(state.thumb_lx)));
    axis(ImGuiKey_GamepadLStickRight, int(int16_t(state.thumb_lx)));
    axis(ImGuiKey_GamepadLStickUp, int(int16_t(state.thumb_ly)));
    axis(ImGuiKey_GamepadLStickDown, -int(int16_t(state.thumb_ly)));
  }

 private:
  bool captured_ = false;
  bool await_release_ = false;
};

inline bool DrawDialogButton(const char* label, ImVec2 size, bool default_focus) {
  const bool activated = ImGui::Button(label, size);
  if (default_focus) {
    ImGui::SetItemDefaultFocus();
    ImGui::SetKeyboardFocusHere(-1);
    ImGui::SetNavCursorVisible(true);
  }
  return activated;
}

inline bool DialogCancelPressed() {
  return ImGui::IsKeyPressed(ImGuiKey_GamepadFaceRight) || ImGui::IsKeyPressed(ImGuiKey_Escape);
}

}  // namespace rex::ui
