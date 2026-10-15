/**
 * @file        input/touch/touch_input_driver.cpp
 * @brief       On-screen touch controls mapped to an Xbox 360 controller.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#include <rex/input/touch/touch_input_driver.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <mutex>

#include <SDL3/SDL.h>

#include <rex/cvar.h>
#include <rex/logging.h>

REXCVAR_DEFINE_BOOL(touch_haptics, true, "Input",
                    "Tap feedback when an on-screen touch button is pressed");

namespace rex::input::touch {

// A light tap through the platform's haptics (touch_haptics_ios.mm).
void HapticTap();

namespace {

constexpr DeviceId kTouchDevice = static_cast<DeviceId>(0x544F5543);  // "TOUC"

enum class Kind { kButton, kLeftTrigger, kRightTrigger };

// Layout in window-height units, measured from the nearer side edge so it
// holds on any aspect ratio. Sized for thumbs on an 11-13" landscape iPad.
struct ButtonDef {
  bool from_right;
  float edge_x;
  float y;
  float radius;
  const char* label;
  Kind kind;
  uint16_t mask;
};

constexpr float kFace = 0.085f;
constexpr float kFaceX = 0.24f;
constexpr float kFaceY = 0.68f;
constexpr float kFaceGap = 0.13f;

constexpr ButtonDef kButtons[] = {
    {true, kFaceX, kFaceY + kFaceGap, kFace, "A", Kind::kButton, X_INPUT_GAMEPAD_A},
    {true, kFaceX - kFaceGap, kFaceY, kFace, "B", Kind::kButton, X_INPUT_GAMEPAD_B},
    {true, kFaceX + kFaceGap, kFaceY, kFace, "X", Kind::kButton, X_INPUT_GAMEPAD_X},
    {true, kFaceX, kFaceY - kFaceGap, kFace, "Y", Kind::kButton, X_INPUT_GAMEPAD_Y},
    {false, 0.10f, 0.11f, 0.07f, "LT", Kind::kLeftTrigger, 0},
    {false, 0.27f, 0.11f, 0.07f, "LB", Kind::kButton, X_INPUT_GAMEPAD_LEFT_SHOULDER},
    {true, 0.10f, 0.11f, 0.07f, "RT", Kind::kRightTrigger, 0},
    {true, 0.27f, 0.11f, 0.07f, "RB", Kind::kButton, X_INPUT_GAMEPAD_RIGHT_SHOULDER},
    // Right-stick click (the camera zoom in Harmony of Despair), at the top-left
    // of the face buttons so it stays out of the left thumb's movement zone.
    {true, kFaceX + kFaceGap + 0.03f, kFaceY - kFaceGap - 0.05f, 0.06f, "R3", Kind::kButton,
     X_INPUT_GAMEPAD_RIGHT_THUMB},
};
// Back and Start sit side by side at the top centre.
constexpr float kMenuRadius = 0.05f;
constexpr float kMenuOffset = 0.09f;
constexpr float kMenuY = 0.08f;

constexpr float kStickRadius = 0.16f;
constexpr float kStickHomeX = 0.25f;
constexpr float kStickHomeY = 0.68f;
// Thumbs landing in the lower-left area (below the shoulder row, left of
// centre) take the stick; the base moves to where they land.
constexpr float kStickZoneTop = 0.22f;
// Slightly bigger than drawn, since a thumb covers part of what it presses.
constexpr float kHitSlop = 1.25f;
constexpr int kMaxFingers = 10;
// The menu D-pad: fixed at the stick's home position; a press is read as one
// of eight directions, with a small dead centre.
constexpr float kDpadRadius = 0.15f;
constexpr float kDpadDeadZone = 0.25f;  // of the radius

struct Finger {
  SDL_FingerID id = 0;
  bool active = false;
  bool on_stick = false;
  int button = -1;  // index into the layout, -1 for none
  bool on_dpad = false;
  uint16_t dpad = 0;  // directions held, in D-pad mode
};

struct State {
  std::mutex mutex;
  float aspect = 16.0f / 9.0f;
  // Safe area insets in height units (iPhone notch / Dynamic Island, home
  // indicator); the controls are laid out inside them.
  float inset_left = 0.0f;
  float inset_right = 0.0f;
  float inset_top = 0.0f;
  float inset_bottom = 0.0f;
  Finger fingers[kMaxFingers];
  bool dpad_mode = true;  // until the title reports a stage being played
  bool stick_active = false;
  float stick_x = 0.0f;  // base, height units
  float stick_y = 0.0f;
  float knob_dx = 0.0f;  // -1..1
  float knob_dy = 0.0f;
};

State& state() {
  static State s;
  return s;
}

struct Placed {
  float x;  // height units from the left edge
  float y;
  float radius;
  const char* label;
  Kind kind;
  uint16_t mask;
};

// Window aspect and safe area, read from the first SDL window. Callers hold
// the state lock.
void UpdateGeometry(State& s, SDL_Window* window) {
  if (!window) {
    int count = 0;
    SDL_Window** windows = SDL_GetWindows(&count);
    window = windows && count > 0 ? windows[0] : nullptr;
    SDL_free(windows);
  }
  int w = 0, h = 0;
  if (!window || !SDL_GetWindowSize(window, &w, &h) || w <= 0 || h <= 0) return;
  s.aspect = float(w) / float(h);
  SDL_Rect safe{};
  if (SDL_GetWindowSafeArea(window, &safe) && safe.w > 0 && safe.h > 0) {
    s.inset_left = float(safe.x) / float(h);
    s.inset_top = float(safe.y) / float(h);
    s.inset_right = float(w - safe.x - safe.w) / float(h);
    s.inset_bottom = float(h - safe.y - safe.h) / float(h);
  }
}

// Buttons first (kButtons order), then Back, Start. The layout's vertical
// positions are fractions of the safe height, offset by the top inset.
std::vector<Placed> PlaceButtons(const State& s) {
  const float aspect = s.aspect;
  const float safe_h = 1.0f - s.inset_top - s.inset_bottom;
  const auto y_of = [&](float y) { return s.inset_top + y * safe_h; };
  std::vector<Placed> placed;
  for (const auto& def : kButtons) {
    placed.push_back({def.from_right ? aspect - s.inset_right - def.edge_x
                                     : s.inset_left + def.edge_x,
                      y_of(def.y), def.radius, def.label, def.kind, def.mask});
  }
  const float centre = s.inset_left + (aspect - s.inset_left - s.inset_right) * 0.5f;
  placed.push_back({centre - kMenuOffset, y_of(kMenuY), kMenuRadius, "Back", Kind::kButton,
                    X_INPUT_GAMEPAD_BACK});
  placed.push_back({centre + kMenuOffset, y_of(kMenuY), kMenuRadius, "Start", Kind::kButton,
                    X_INPUT_GAMEPAD_START});
  return placed;
}

int HitButton(const std::vector<Placed>& placed, float x, float y) {
  int best = -1;
  float best_d2 = 0.0f;
  for (size_t i = 0; i < placed.size(); ++i) {
    const float dx = x - placed[i].x, dy = y - placed[i].y;
    const float d2 = dx * dx + dy * dy;
    const float reach = placed[i].radius * kHitSlop;
    if (d2 <= reach * reach && (best < 0 || d2 < best_d2)) {
      best = static_cast<int>(i);
      best_d2 = d2;
    }
  }
  return best;
}

bool GamepadConnected() {
  int count = 0;
  SDL_JoystickID* pads = SDL_GetGamepads(&count);
  SDL_free(pads);
  return count > 0;
}

// D-pad directions (X_INPUT_GAMEPAD_DPAD_* bits) for a press at (x, y), with
// the centre at the stick's home position. Callers hold the state lock.
float DpadCentreX(const State& s) { return s.inset_left + kStickHomeX; }
float DpadCentreY(const State& s) {
  return s.inset_top + kStickHomeY * (1.0f - s.inset_top - s.inset_bottom);
}
uint16_t DpadDirections(const State& s, float x, float y) {
  const float dx = (x - DpadCentreX(s)) / kDpadRadius;
  const float dy = (y - DpadCentreY(s)) / kDpadRadius;
  if (dx * dx + dy * dy < kDpadDeadZone * kDpadDeadZone) return 0;
  // Eight sectors of 45 degrees: a diagonal press holds both directions.
  const float angle = std::atan2(-dy, dx);  // screen y grows downwards
  const int sector = static_cast<int>(std::lround(angle / (3.14159265f / 4.0f))) & 7;
  static constexpr uint16_t kSectors[8] = {
      X_INPUT_GAMEPAD_DPAD_RIGHT,
      X_INPUT_GAMEPAD_DPAD_RIGHT | X_INPUT_GAMEPAD_DPAD_UP,
      X_INPUT_GAMEPAD_DPAD_UP,
      X_INPUT_GAMEPAD_DPAD_UP | X_INPUT_GAMEPAD_DPAD_LEFT,
      X_INPUT_GAMEPAD_DPAD_LEFT,
      X_INPUT_GAMEPAD_DPAD_LEFT | X_INPUT_GAMEPAD_DPAD_DOWN,
      X_INPUT_GAMEPAD_DPAD_DOWN,
      X_INPUT_GAMEPAD_DPAD_DOWN | X_INPUT_GAMEPAD_DPAD_RIGHT,
  };
  return kSectors[sector];
}

void UpdateKnob(State& s, float x, float y) {
  float dx = (x - s.stick_x) / kStickRadius;
  float dy = (y - s.stick_y) / kStickRadius;
  const float len = std::sqrt(dx * dx + dy * dy);
  if (len > 1.0f) {
    dx /= len;
    dy /= len;
  }
  s.knob_dx = dx;
  s.knob_dy = dy;
}

bool SDLCALL OnSdlEvent(void*, SDL_Event* event) {
  const bool down = event->type == SDL_EVENT_FINGER_DOWN;
  const bool up = event->type == SDL_EVENT_FINGER_UP || event->type == SDL_EVENT_FINGER_CANCELED;
  const bool motion = event->type == SDL_EVENT_FINGER_MOTION;
  if (!down && !up && !motion) return true;

  State& s = state();
  std::lock_guard lock(s.mutex);
  if (SDL_Window* window = SDL_GetWindowFromID(event->tfinger.windowID))
    UpdateGeometry(s, window);
  const float x = event->tfinger.x * s.aspect;
  const float y = event->tfinger.y;
  const SDL_FingerID id = event->tfinger.fingerID;

  Finger* finger = nullptr;
  for (auto& f : s.fingers) {
    if (f.active && f.id == id) finger = &f;
  }

  if (down) {
    if (!finger) {
      for (auto& f : s.fingers) {
        if (!f.active) {
          finger = &f;
          break;
        }
      }
    }
    if (!finger) return true;
    *finger = Finger{id, true, false, -1};
    const auto placed = PlaceButtons(s);
    finger->button = HitButton(placed, x, y);
    const bool left_zone =
        x < s.aspect * 0.5f &&
        y > s.inset_top + kStickZoneTop * (1.0f - s.inset_top - s.inset_bottom);
    if (finger->button >= 0) {
      if (REXCVAR_GET(touch_haptics)) HapticTap();
    } else if (left_zone && s.dpad_mode) {
      finger->on_dpad = true;
      finger->dpad = DpadDirections(s, x, y);
      if (finger->dpad && REXCVAR_GET(touch_haptics)) HapticTap();
    } else if (left_zone && !s.stick_active) {
      finger->on_stick = true;
      s.stick_active = true;
      s.stick_x = x;
      s.stick_y = y;
      s.knob_dx = s.knob_dy = 0.0f;
    }
  } else if (motion && finger) {
    if (finger->on_stick) {
      UpdateKnob(s, x, y);
    } else if (finger->on_dpad) {
      const uint16_t dpad = DpadDirections(s, x, y);
      if (dpad && dpad != finger->dpad && REXCVAR_GET(touch_haptics)) HapticTap();
      finger->dpad = dpad;
    } else {
      // Sliding a thumb across the face buttons moves the press with it.
      const int button = HitButton(PlaceButtons(s), x, y);
      if (button >= 0 && button != finger->button && REXCVAR_GET(touch_haptics)) HapticTap();
      finger->button = button;
    }
  } else if (up && finger) {
    if (finger->on_stick) {
      s.stick_active = false;
      s.knob_dx = s.knob_dy = 0.0f;
    }
    *finger = Finger{};
  }
  return true;
}

int16_t AxisValue(float v) {
  return static_cast<int16_t>(std::clamp(v, -1.0f, 1.0f) * 32767.0f);
}

}  // namespace

void SetTitlePresence(uint32_t value) {
  const bool playing = value == 4 || value == 5;
  State& s = state();
  std::lock_guard lock(s.mutex);
  if (s.dpad_mode != playing) return;
  s.dpad_mode = !playing;
  // Fingers already down keep what they were doing until they lift, except
  // that a held stick or D-pad stops so nothing stays pressed across the switch.
  for (auto& f : s.fingers) {
    if (f.on_stick || f.on_dpad) f = Finger{};
  }
  s.stick_active = false;
  s.knob_dx = s.knob_dy = 0.0f;
  REXLOG_INFO("Touch controls: {} (title presence {})", playing ? "analog stick" : "D-pad",
              value);
}

OverlaySnapshot GetOverlaySnapshot(float aspect) {
  OverlaySnapshot snapshot;
  if (GamepadConnected() || aspect <= 0.0f) return snapshot;
  State& s = state();
  std::lock_guard lock(s.mutex);
  UpdateGeometry(s, nullptr);
  aspect = s.aspect;
  snapshot.visible = true;
  const auto placed = PlaceButtons(s);
  for (size_t i = 0; i < placed.size(); ++i) {
    OverlayControl control;
    control.x = placed[i].x / aspect;
    control.y = placed[i].y;
    control.radius = placed[i].radius;
    control.label = placed[i].label;
    for (const auto& f : s.fingers) {
      if (f.active && f.button == static_cast<int>(i)) control.pressed = true;
    }
    snapshot.buttons.push_back(control);
  }
  if (s.dpad_mode) {
    snapshot.dpad = true;
    snapshot.stick_base.x = DpadCentreX(s) / aspect;
    snapshot.stick_base.y = DpadCentreY(s);
    snapshot.stick_base.radius = kDpadRadius;
    uint16_t held = 0;
    for (const auto& f : s.fingers) {
      if (f.active && f.on_dpad) held |= f.dpad;
    }
    snapshot.stick_base.pressed = held != 0;
    snapshot.dpad_up = held & X_INPUT_GAMEPAD_DPAD_UP;
    snapshot.dpad_down = held & X_INPUT_GAMEPAD_DPAD_DOWN;
    snapshot.dpad_left = held & X_INPUT_GAMEPAD_DPAD_LEFT;
    snapshot.dpad_right = held & X_INPUT_GAMEPAD_DPAD_RIGHT;
    return snapshot;
  }
  snapshot.stick_base.x = (s.stick_active ? s.stick_x : s.inset_left + kStickHomeX) / aspect;
  snapshot.stick_base.y =
      s.stick_active ? s.stick_y
                     : s.inset_top + kStickHomeY * (1.0f - s.inset_top - s.inset_bottom);
  snapshot.stick_base.radius = kStickRadius;
  snapshot.stick_base.pressed = s.stick_active;
  snapshot.knob_x = s.knob_dx;
  snapshot.knob_y = s.knob_dy;
  return snapshot;
}

TouchInputDriver::TouchInputDriver(rex::ui::Window* window, size_t window_z_order)
    : InputDriver(window, window_z_order) {}

TouchInputDriver::~TouchInputDriver() {
  if (event_watch_added_) SDL_RemoveEventWatch(OnSdlEvent, nullptr);
  if (events_initialized_) SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

X_STATUS TouchInputDriver::Setup() {
  if (!SDL_InitSubSystem(SDL_INIT_EVENTS)) {
    REXLOG_ERROR("Touch controls: SDL events unavailable: {}", SDL_GetError());
    return X_STATUS_UNSUCCESSFUL;
  }
  events_initialized_ = true;
  if (!SDL_AddEventWatch(OnSdlEvent, nullptr)) {
    REXLOG_ERROR("Touch controls: cannot watch SDL events: {}", SDL_GetError());
    return X_STATUS_UNSUCCESSFUL;
  }
  event_watch_added_ = true;
  REXLOG_INFO("Touch controls enabled (hidden while a gamepad is connected)");
  return X_STATUS_SUCCESS;
}

void TouchInputDriver::EnumerateDevices(std::vector<DeviceInfo>& out) {
  DeviceInfo info;
  info.id = kTouchDevice;
  info.name = "Touch Controls";
  info.synthetic = true;
  out.push_back(info);
}

X_RESULT TouchInputDriver::GetDeviceState(DeviceId id, X_INPUT_STATE* out_state) {
  if (id != kTouchDevice) return X_ERROR_DEVICE_NOT_CONNECTED;
  X_INPUT_GAMEPAD pad{};
  if (!GamepadConnected() && is_active()) {
    State& s = state();
    std::lock_guard lock(s.mutex);
    const auto placed = PlaceButtons(s);
    uint16_t buttons = 0;
    for (const auto& f : s.fingers) {
      if (f.active && f.on_dpad) buttons |= f.dpad;
      if (!f.active || f.button < 0) continue;
      const auto& b = placed[f.button];
      if (b.kind == Kind::kLeftTrigger) pad.left_trigger = 0xFF;
      else if (b.kind == Kind::kRightTrigger) pad.right_trigger = 0xFF;
      else buttons |= b.mask;
    }
    if (s.stick_active) {
      // Menus that only read the d-pad still follow a firm push.
      constexpr float kDpad = 0.5f;
      if (s.knob_dy < -kDpad) buttons |= X_INPUT_GAMEPAD_DPAD_UP;
      if (s.knob_dy > kDpad) buttons |= X_INPUT_GAMEPAD_DPAD_DOWN;
      if (s.knob_dx < -kDpad) buttons |= X_INPUT_GAMEPAD_DPAD_LEFT;
      if (s.knob_dx > kDpad) buttons |= X_INPUT_GAMEPAD_DPAD_RIGHT;
      pad.thumb_lx = AxisValue(s.knob_dx);
      pad.thumb_ly = AxisValue(-s.knob_dy);  // screen y grows downwards
    }
    pad.buttons = buttons;
  }
  if (std::memcmp(&pad, &last_gamepad_, sizeof(pad)) != 0) {
    last_gamepad_ = pad;
    ++packet_number_;
  }
  if (out_state) {
    out_state->packet_number = packet_number_;
    out_state->gamepad = pad;
  }
  return X_ERROR_SUCCESS;
}

X_RESULT TouchInputDriver::GetDeviceCapabilities(DeviceId id, uint32_t,
                                                 X_INPUT_CAPABILITIES* out_caps) {
  if (id != kTouchDevice) return X_ERROR_DEVICE_NOT_CONNECTED;
  if (out_caps) {
    std::memset(out_caps, 0, sizeof(*out_caps));
    out_caps->type = 0x01;
    out_caps->sub_type = 0x01;
    out_caps->gamepad.buttons = 0xFFFF;
    out_caps->gamepad.left_trigger = 0xFF;
    out_caps->gamepad.right_trigger = 0xFF;
    out_caps->gamepad.thumb_lx = static_cast<int16_t>(0x7FFF);
    out_caps->gamepad.thumb_ly = static_cast<int16_t>(0x7FFF);
  }
  return X_ERROR_SUCCESS;
}

X_RESULT TouchInputDriver::SetDeviceVibration(DeviceId id, X_INPUT_VIBRATION*) {
  return id == kTouchDevice ? X_ERROR_SUCCESS : X_ERROR_DEVICE_NOT_CONNECTED;
}

X_RESULT TouchInputDriver::GetDeviceKeystroke(DeviceId id, uint32_t, X_INPUT_KEYSTROKE*) {
  return id == kTouchDevice ? X_ERROR_EMPTY : X_ERROR_DEVICE_NOT_CONNECTED;
}

}  // namespace rex::input::touch
