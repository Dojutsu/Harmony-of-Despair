#include <rex/input/scripted/scripted_input_driver.h>

#include <fstream>
#include <algorithm>
#include <cerrno>
#include <rex/platform.h>
#if REX_PLATFORM_GNU_LINUX
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#elif REX_PLATFORM_WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <aclapi.h>
#include <array>
#include <vector>
#endif
#include <rex/logging.h>

namespace rex::input::scripted {
namespace {
constexpr DeviceId kDevice = static_cast<DeviceId>(0x53435250);
#if REX_PLATFORM_GNU_LINUX
bool ReadOwnedScript(const std::filesystem::path& path, std::string& text,
                     uint64_t& device, uint64_t& inode, std::string& error) {
  const int fd = ::open(path.c_str(), O_RDONLY | O_CLOEXEC | O_NOFOLLOW | O_NONBLOCK);
  if (fd < 0) { error = "input script cannot be opened safely"; return false; }
  struct Close { int fd; ~Close() { ::close(fd); } } close{fd};
  struct stat before{}, after{};
  if (::fstat(fd, &before) || !S_ISREG(before.st_mode) || before.st_uid != ::geteuid() ||
      (before.st_mode & (S_IRWXG | S_IRWXO)) || before.st_size < 0 ||
      uint64_t(before.st_size) > Timeline::kMaximumBytes) {
    error = "input script is not a bounded private owned regular file"; return false;
  }
  text.assign(Timeline::kMaximumBytes + 1, '\0');
  size_t offset = 0;
  while (offset < text.size()) {
    const auto count = ::read(fd, text.data() + offset, text.size() - offset);
    if (count < 0) { if (errno == EINTR) continue; error = "input script read failed"; return false; }
    if (!count) break;
    offset += static_cast<size_t>(count);
  }
  text.resize(offset);
  if (text.size() > Timeline::kMaximumBytes || ::fstat(fd, &after) ||
      before.st_dev != after.st_dev || before.st_ino != after.st_ino ||
      before.st_uid != after.st_uid || before.st_mode != after.st_mode ||
      before.st_size != after.st_size || uint64_t(after.st_size) != text.size() ||
      before.st_mtim.tv_sec != after.st_mtim.tv_sec || before.st_mtim.tv_nsec != after.st_mtim.tv_nsec) {
    error = "input script changed during bounded read"; return false;
  }
  device = static_cast<uint64_t>(before.st_dev); inode = static_cast<uint64_t>(before.st_ino);
  error.clear(); return true;
}
#elif REX_PLATFORM_WIN32
// Windows equivalent of the owned-file check: the script must be owned by this
// user (or the elevated default owner, Administrators) and not be a reparse point.
bool OwnedByCaller(HANDLE handle) {
  PSID owner = nullptr; PSECURITY_DESCRIPTOR descriptor = nullptr;
  if (GetSecurityInfo(handle, SE_FILE_OBJECT, OWNER_SECURITY_INFORMATION, &owner, nullptr, nullptr,
                      nullptr, &descriptor) != ERROR_SUCCESS || !owner) return false;
  struct Free { PSECURITY_DESCRIPTOR value; ~Free() { LocalFree(value); } } free_descriptor{descriptor};
  HANDLE token = nullptr;
  if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token)) return false;
  struct CloseToken { HANDLE value; ~CloseToken() { CloseHandle(value); } } close_token{token};
  DWORD size = 0; GetTokenInformation(token, TokenUser, nullptr, 0, &size);
  if (!size || size > 4096) return false;
  std::vector<uint8_t> user(size);
  if (!GetTokenInformation(token, TokenUser, user.data(), size, &size)) return false;
  std::array<uint8_t, SECURITY_MAX_SID_SIZE> admins{}; DWORD admins_size = DWORD(admins.size());
  const bool administrators = CreateWellKnownSid(WinBuiltinAdministratorsSid, nullptr, admins.data(),
                                                 &admins_size) && EqualSid(owner, admins.data());
  return EqualSid(owner, reinterpret_cast<TOKEN_USER*>(user.data())->User.Sid) || administrators;
}
bool ReadOwnedScript(const std::filesystem::path& path, std::string& text,
                     uint64_t& device, uint64_t& inode, std::string& error) {
  // The appending writer opens the file between rows, so share read and write.
  HANDLE handle = CreateFileW(path.c_str(), GENERIC_READ | READ_CONTROL, FILE_SHARE_READ | FILE_SHARE_WRITE,
                              nullptr, OPEN_EXISTING, FILE_FLAG_OPEN_REPARSE_POINT, nullptr);
  if (handle == INVALID_HANDLE_VALUE) { error = "input script cannot be opened safely"; return false; }
  struct Close { HANDLE value; ~Close() { CloseHandle(value); } } close{handle};
  BY_HANDLE_FILE_INFORMATION before{}, after{};
  auto size_of = [](const BY_HANDLE_FILE_INFORMATION& info) {
    return (uint64_t(info.nFileSizeHigh) << 32) | info.nFileSizeLow;
  };
  if (!GetFileInformationByHandle(handle, &before) ||
      (before.dwFileAttributes & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_REPARSE_POINT)) ||
      !OwnedByCaller(handle) || size_of(before) > Timeline::kMaximumBytes) {
    error = "input script is not a bounded private owned regular file"; return false;
  }
  text.assign(Timeline::kMaximumBytes + 1, '\0');
  size_t offset = 0;
  while (offset < text.size()) {
    DWORD count = 0;
    if (!ReadFile(handle, text.data() + offset, DWORD(text.size() - offset), &count, nullptr)) {
      error = "input script read failed"; return false;
    }
    if (!count) break;
    offset += count;
  }
  text.resize(offset);
  if (text.size() > Timeline::kMaximumBytes || !GetFileInformationByHandle(handle, &after) ||
      after.dwVolumeSerialNumber != before.dwVolumeSerialNumber ||
      after.nFileIndexHigh != before.nFileIndexHigh || after.nFileIndexLow != before.nFileIndexLow ||
      size_of(after) != size_of(before) || size_of(after) != text.size() ||
      after.ftLastWriteTime.dwLowDateTime != before.ftLastWriteTime.dwLowDateTime ||
      after.ftLastWriteTime.dwHighDateTime != before.ftLastWriteTime.dwHighDateTime) {
    error = "input script changed during bounded read"; return false;
  }
  device = before.dwVolumeSerialNumber;
  inode = (uint64_t(before.nFileIndexHigh) << 32) | before.nFileIndexLow;
  error.clear(); return true;
}
#endif
}

ScriptedInputDriver::ScriptedInputDriver(std::filesystem::path script, Clock clock)
    : ScriptedInputDriver(std::move(script), std::move(clock), false) {}
ScriptedInputDriver::ScriptedInputDriver(std::filesystem::path script, Clock clock, bool append_only)
    : InputDriver(nullptr, 0), external_clock_(bool(clock)),
      clock_(clock ? std::move(clock) : [] { return std::chrono::steady_clock::now(); }),
      script_(std::move(script)), append_only_(append_only) {}

X_STATUS ScriptedInputDriver::Setup() {
  if (append_only_) {
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32
    std::string text, error;
    if (!ReadOwnedScript(script_, text, script_device_, script_inode_, error)) {
      REXLOG_ERROR("Offline controller append setup rejected: {}", error); return X_STATUS_INVALID_PARAMETER;
    }
    const auto completed = text.rfind('\n');
    if (completed == std::string::npos) return X_STATUS_INVALID_PARAMETER;
    text.resize(completed + 1);
    if (!timeline_.Parse(text, error)) {
      REXLOG_ERROR("Offline controller append setup rejected: {}", error); return X_STATUS_INVALID_PARAMETER;
    }
    if (!timeline_.ends_neutral()) {
      REXLOG_ERROR("Offline controller append setup rejected: initial schedule needs a final fully neutral release");
      return X_STATUS_INVALID_PARAMETER;
    }
    accepted_text_ = std::move(text);
    REXLOG_INFO("Offline controller append-only reload enabled; 250ms cadence, private owned file");
    return X_STATUS_SUCCESS;
#else
    REXLOG_ERROR("Offline controller append-only reload requires Linux or Windows"); return X_STATUS_INVALID_PARAMETER;
#endif
  }
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

void ScriptedInputDriver::ReportReloadError(const std::string& error) {
  if (last_reload_error_ != error) {
    REXLOG_WARN("Offline controller append rejected; accepted schedule retained: {}", error);
    last_reload_error_ = error;
  }
}
void ScriptedInputDriver::Reload(std::chrono::steady_clock::time_point now, uint64_t elapsed_ms) {
  if (!append_only_ || (reload_clock_set_ && now - reloaded_at_ < std::chrono::milliseconds(250))) return;
  reloaded_at_ = now; reload_clock_set_ = true;
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32
  std::string text, error; uint64_t device = 0, inode = 0;
  if (!ReadOwnedScript(script_, text, device, inode, error)) { ReportReloadError(error); return; }
  if (device != script_device_ || inode != script_inode_) {
    ReportReloadError("input script file identity changed"); return;
  }
  if (text.size() < accepted_text_.size() || text.compare(0, accepted_text_.size(), accepted_text_) != 0) {
    ReportReloadError("input script accepted byte prefix changed"); return;
  }
  // A newline is the writer's commit boundary. Pending bytes cannot turn a
  // partially written last integer into an accepted row.
  const auto completed = text.rfind('\n');
  if (completed == std::string::npos) { ReportReloadError("input script has no completed rows"); return; }
  text.resize(completed + 1);
  if (text.size() == accepted_text_.size()) return;
  const auto previous = timeline_.frame_count();
  if (!timeline_.Extend(text, elapsed_ms, error)) { ReportReloadError(error); return; }
  accepted_text_ = std::move(text); last_reload_error_.clear();
  REXLOG_INFO("Offline controller append accepted: elapsed_ms={} previous_rows={} rows={}",
              elapsed_ms, previous, timeline_.frame_count());
#else
  (void)elapsed_ms;
#endif
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
  if (!started_ && !start_clock) {
    if (append_only_) Reload(clock_(), 0);
    *out = {}; return X_ERROR_SUCCESS;
  }
  const auto now = clock_();
  if (!started_) {
    started_at_ = now; started_ = true;
#if REX_PLATFORM_GNU_LINUX
    if (append_only_) {
      timespec monotonic{};
      if (::clock_gettime(CLOCK_MONOTONIC, &monotonic) == 0)
        REXLOG_INFO("Offline controller append clock: monotonic_ms={} pid={} device={} inode={} external_clock={}",
                    uint64_t(monotonic.tv_sec) * 1000 + uint64_t(monotonic.tv_nsec) / 1000000,
                    ::getpid(), script_device_, script_inode_, external_clock_);
    }
#elif REX_PLATFORM_WIN32
    if (append_only_) {
      REXLOG_INFO("Offline controller append clock: monotonic_ms={} pid={} device={} inode={} external_clock={}",
                  uint64_t(GetTickCount64()), uint32_t(GetCurrentProcessId()), script_device_, script_inode_,
                  external_clock_);
    }
#endif
  }
  const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - started_at_).count();
  Reload(now, static_cast<uint64_t>(std::max<int64_t>(0, elapsed)));
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
