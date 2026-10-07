#include <rex/system/xam/online_status.h>
#include <rex/system/xam/session.h>

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <inja/third_party/include/nlohmann/json.hpp>
#if REX_PLATFORM_WIN32
#include <windows.h>
#elif REX_PLATFORM_GNU_LINUX
#include <unistd.h>
#endif

namespace rex::system::xam {
REXCVAR_DEFINE_STRING(online_status_directory, "", "General",
                     "Optional directory for read-only process status snapshots")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

namespace {
std::string Xuid(uint64_t value) {
  std::ostringstream out;
  out << std::uppercase << std::hex << std::setfill('0') << std::setw(16) << value;
  return out.str();
}
std::string Name(std::string value) {
  value.resize(std::min<size_t>(value.size(), 48));
  for (char& ch : value)
    if (static_cast<unsigned char>(ch) < 32 || ch == 127) ch = ' ';
  return value;
}
bool ValidCode(const std::string& code) {
  return code.size() == 6 &&
         code.find_first_not_of("ABCDEFGHJKMNPQRSTUVWXYZ23456789") == std::string::npos;
}
const char* State(SessionState state) {
  switch (state) {
    case SessionState::kLobby: return "lobby";
    case SessionState::kRegistration: return "registration";
    case SessionState::kInGame: return "in_game";
    case SessionState::kReporting: return "reporting";
    default: return "offline";
  }
}
bool Write(const std::filesystem::path& path, const std::string& bytes) {
  if (bytes.size() > 64 * 1024) return false;
  std::error_code error;
  std::filesystem::create_directories(path.parent_path(), error);
  if (error) return false;
  auto temporary = path;
  temporary += ".tmp";
  {
    std::ofstream out(temporary, std::ios::binary | std::ios::trunc);
    if (!out.write(bytes.data(), bytes.size())) return false;
    out.close();
    if (!out) return false;
  }
#if REX_PLATFORM_WIN32
  return MoveFileExW(temporary.c_str(), path.c_str(),
                     MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0;
#else
  std::filesystem::rename(temporary, path, error);
  return !error;
#endif
}
}  // namespace

void OnlineStatusSignal::Notify() {
  std::lock_guard lock(mutex);
  pending = true;
  wake.notify_one();
}

OnlineStatus::OnlineStatus(uint64_t xuid, std::string name, std::filesystem::path directory)
    : local_xuid_(xuid), local_name_(Name(std::move(name))) {
#if REX_PLATFORM_WIN32
  FILETIME created{}, exited{}, kernel{}, user{};
  if (!directory.empty() && GetProcessTimes(GetCurrentProcess(), &created, &exited, &kernel, &user)) {
    process_id_ = GetCurrentProcessId();
    // Decimal Windows FILETIME string, compared exactly by PowerShell. No JSON
    // floating-point loss and no wall-clock/idle-lobby expiry heuristic.
    process_start_time_ = std::to_string((uint64_t(created.dwHighDateTime) << 32) |
                                       created.dwLowDateTime);
    path_ = directory / ("online-status-" + std::to_string(process_id_) + ".json");
    worker_ = std::thread([this] { Run(); });
  }
#elif REX_PLATFORM_GNU_LINUX
  if (!directory.empty()) {
    // Linux field 22 is the process start time in boot-relative clock ticks.
    // Parse after the final ')' because the process name may contain spaces
    // or parentheses. Keep the integer as text, with no JSON precision loss.
    std::ifstream stat("/proc/self/stat");
    std::string line;
    if (std::getline(stat, line)) {
      const auto close = line.rfind(')');
      if (close != std::string::npos) {
        std::istringstream fields(line.substr(close + 1));
        std::string value;
        for (unsigned field = 3; field <= 22 && fields >> value; ++field) {
          if (field == 22 && !value.empty() &&
              value.find_first_not_of("0123456789") == std::string::npos)
            process_start_time_ = value;
        }
      }
    }
    if (!process_start_time_.empty()) {
      process_id_ = static_cast<uint32_t>(::getpid());
      path_ = directory / ("online-status-" + std::to_string(process_id_) + ".json");
      worker_ = std::thread([this] { Run(); });
    }
  }
#endif
}
OnlineStatus::~OnlineStatus() {
  {
    std::lock_guard lock(signal_->mutex);
    signal_->stopping = true;
    signal_->wake.notify_one();
  }
  if (worker_.joinable()) worker_.join();
  if (!path_.empty()) {
    std::error_code error;
    std::filesystem::remove(path_, error);
    auto temporary = path_;
    temporary += ".tmp";
    std::filesystem::remove(temporary, error);
  }
}
void OnlineStatus::Attach(const void* owner, std::shared_ptr<SessionRecord> record) {
  if (!record) { Detach(owner); return; }
  {
    std::lock_guard lock(*record->mutex);
    record->status_signal = signal_;
  }
  {
    std::lock_guard lock(mutex_);
    attachments_[owner] = {++sequence_, std::move(record)};
  }
  signal_->Notify();
}
void OnlineStatus::Detach(const void* owner) {
  {
    std::lock_guard lock(mutex_);
    attachments_.erase(owner);
  }
  signal_->Notify();
}
std::string OnlineStatus::Capture() const {
  using nlohmann::json;
  json result = {{"mode", "offline"}, {"local_player", {{"xuid", Xuid(local_xuid_)},
                 {"name", local_name_}}}, {"session_state", "offline"},
                 {"player_count", 0}, {"max_players", 0}, {"host_xuid", ""},
                 {"members", json::array()}};
  std::vector<Attachment> attachments;
  {
    std::lock_guard lock(mutex_);
    for (const auto& [owner, attachment] : attachments_) attachments.push_back(attachment);
  }
  std::sort(attachments.begin(), attachments.end(),
            [](const auto& a, const auto& b) { return a.sequence > b.sequence; });
  for (const auto& attachment : attachments) {
    const auto& record = *attachment.record;
    std::lock_guard lock(*record.mutex);
    // Bound the publication without changing membership. Invalid/oversized
    // records are not presented as a usable party.
    if (record.state == SessionState::kDeleted || record.members.size() > 64 ||
        std::none_of(record.members.begin(), record.members.end(),
                     [&](const auto& m) { return m.xuid == local_xuid_; })) continue;
    result["mode"] = record.host_xuid == local_xuid_ ? "hosting" : "joined";
    result["session_state"] = State(record.state);
    result["player_count"] = record.members.size();
    result["max_players"] = uint64_t(record.max_public_slots) + record.max_private_slots;
    result["host_xuid"] = Xuid(record.host_xuid);
    if (record.host_xuid == local_xuid_ && ValidCode(record.status_invite_code))
      result["invite_code"] = record.status_invite_code;
    for (const auto& member : record.members) {
      auto name = Name(member.name);
      if (name.empty() && member.xuid == record.host_xuid) name = Name(record.host_name);
      if (name.empty()) name = "Player ..." + Xuid(member.xuid).substr(12);
      result["members"].push_back({{"xuid", Xuid(member.xuid)}, {"name", name},
                                   {"is_host", member.xuid == record.host_xuid}});
    }
    break;
  }
  return result.dump(-1, ' ', false, json::error_handler_t::replace);
}
void OnlineStatus::Run() {
  std::string previous;
  uint64_t revision = 0;
  bool retry = false;
  for (;;) {
    {
      std::unique_lock lock(signal_->mutex);
      auto ready = [&] { return signal_->pending || signal_->stopping; };
      if (retry) signal_->wake.wait_for(lock, std::chrono::seconds(1), ready);
      else signal_->wake.wait(lock, ready);
      if (signal_->stopping) return;
      signal_->pending = false;
    }
    try {
      auto projection = Capture();
      retry = false;
      if (projection == previous) continue;
      auto document = nlohmann::json::parse(projection);
      document["schema_version"] = 1;
      document["process_id"] = process_id_;
      document["process_start_time"] = process_start_time_;
      document["revision"] = revision + 1;
      if (Write(path_, document.dump())) { previous = std::move(projection); ++revision; }
      else retry = true;
    } catch (...) {
      // Optional observability must not terminate the runtime on filesystem or
      // serialization failure. Retry is bounded to one pending current state.
      retry = true;
    }
  }
}
}  // namespace rex::system::xam
