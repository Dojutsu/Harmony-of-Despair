#include <rex/input/scripted/scripted_input_driver.h>

#include <fstream>
#include <rex/logging.h>

namespace rex::input::scripted {
namespace {
constexpr DeviceId kDevice = static_cast<DeviceId>(0x53435250);
}

ScriptedInputDriver::ScriptedInputDriver(std::filesystem::path script, Clock clock)
    : InputDriver(nullptr, 0),
      clock_(clock ? std::move(clock) : [] { return std::chrono::steady_clock::now(); }),
      script_(std::move(script)) {}

X_STATUS ScriptedInputDriver::Setup() {
  std::error_code ec;
  if (!std::filesystem::is_regular_file(script_, ec) || ec) {
    REXLOG_ERROR("Scripted input requires a regular local file");
    return X_STATUS_INVALID_PARAMETER;
  }
  const auto size = std::filesystem::file_size(script_, ec);
  if (ec || size > Timeline::kMaximumBytes) return X_STATUS_INVALID_PARAMETER;
  std::ifstream stream(script_, std::ios::binary);
  if (!stream) return X_STATUS_INVALID_PARAMETER;
  // Limit the read even if the file changes after the size check.
  std::string text(Timeline::kMaximumBytes + 1, '\0');
  stream.read(text.data(), static_cast<std::streamsize>(text.size()));
  text.resize(static_cast<size_t>(stream.gcount()));
  std::string error;
  if (!timeline_.Parse(text, error)) {
    REXLOG_ERROR("Scripted input rejected: {}", error);
    return X_STATUS_INVALID_PARAMETER;
  }
  REXLOG_INFO("Offline scripted controller enabled; schedule starts at first guest state poll");
  return X_STATUS_SUCCESS;
}

void ScriptedInputDriver::EnumerateDevices(std::vector<DeviceInfo>& out) {
  DeviceInfo info;
  info.id = kDevice;
  info.name = "Offline test controller";
  info.synthetic = true;
  out.push_back(info);
}

X_RESULT ScriptedInputDriver::GetDeviceState(DeviceId id, X_INPUT_STATE* out) {
  return Sample(id, out, true);
}
X_RESULT ScriptedInputDriver::GetDeviceStateForUI(DeviceId id, X_INPUT_STATE* out) {
  return Sample(id, out, false);
}
X_RESULT ScriptedInputDriver::Sample(DeviceId id, X_INPUT_STATE* out, bool start_clock) {
  if (id != kDevice) return X_ERROR_DEVICE_NOT_CONNECTED;
  if (!out) return X_ERROR_BAD_ARGUMENTS;
  std::lock_guard lock(mutex_);
  if (!started_ && !start_clock) { *out = {}; return X_ERROR_SUCCESS; }
  const auto now = clock_();
  if (!started_) { started_at_ = now; started_ = true; }
  const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - started_at_).count();
  uint32_t packet;
  const auto state = timeline_.Sample(static_cast<uint64_t>(elapsed), &packet);
  if (start_clock) {
    guest_source_packet_ = packet;
    guest_elapsed_ms_ = elapsed;
  } else if (packet != logged_ui_packet_) {
    REXLOG_DEBUG("Offline UI controller transition: elapsed_ms={} packet={} buttons={:04X}",
                 elapsed, packet, state.buttons);
    logged_ui_packet_ = packet;
  }
  *out = {};
  out->packet_number = packet;
  out->gamepad.buttons = state.buttons;
  out->gamepad.left_trigger = state.left_trigger;
  out->gamepad.right_trigger = state.right_trigger;
  out->gamepad.thumb_lx = state.left_x;
  out->gamepad.thumb_ly = state.left_y;
  out->gamepad.thumb_rx = state.right_x;
  out->gamepad.thumb_ry = state.right_y;
  return X_ERROR_SUCCESS;
}

void ScriptedInputDriver::OnGuestStateDelivered(DeviceId id, const X_INPUT_STATE& state,
                                               bool ui_consumed) {
  if (id != kDevice) return;
  std::lock_guard lock(mutex_);
  if (!started_ || (guest_source_packet_ == logged_guest_packet_ &&
                   ui_consumed == logged_guest_consumed_)) return;
  // Guest-delivery evidence must describe the effective state, not a raw UI
  // poll. A consumed row has a separate label so correlation cannot count it
  // as a guest press. Packet remains the source schedule row for correlation.
  if (ui_consumed) {
    REXLOG_DEBUG("Offline controller UI-consumed: elapsed_ms={} packet={} buttons={:04X}",
                 guest_elapsed_ms_, guest_source_packet_, uint16_t(state.gamepad.buttons));
  } else {
    REXLOG_DEBUG("Offline controller transition: elapsed_ms={} packet={} buttons={:04X}",
                 guest_elapsed_ms_, guest_source_packet_, uint16_t(state.gamepad.buttons));
  }
  logged_guest_packet_ = guest_source_packet_;
  logged_guest_consumed_ = ui_consumed;
}

X_RESULT ScriptedInputDriver::GetDeviceCapabilities(DeviceId id, uint32_t, X_INPUT_CAPABILITIES* out) {
  if (id != kDevice) return X_ERROR_DEVICE_NOT_CONNECTED;
  if (!out) return X_ERROR_BAD_ARGUMENTS;
  *out = {};
  out->type = XINPUT_DEVTYPE_GAMEPAD;
  out->sub_type = 1;
  out->gamepad.buttons = 0xFFFF;
  out->gamepad.left_trigger = out->gamepad.right_trigger = 0xFF;
  out->gamepad.thumb_lx = out->gamepad.thumb_ly = out->gamepad.thumb_rx = out->gamepad.thumb_ry = 0x7FFF;
  return X_ERROR_SUCCESS;
}

X_RESULT ScriptedInputDriver::SetDeviceVibration(DeviceId id, X_INPUT_VIBRATION*) {
  return id == kDevice ? X_ERROR_SUCCESS : X_ERROR_DEVICE_NOT_CONNECTED;
}
X_RESULT ScriptedInputDriver::GetDeviceKeystroke(DeviceId id, uint32_t, X_INPUT_KEYSTROKE*) {
  return id == kDevice ? X_ERROR_EMPTY : X_ERROR_DEVICE_NOT_CONNECTED;
}
}  // namespace rex::input::scripted
