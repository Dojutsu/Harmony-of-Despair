#pragma once

#include <condition_variable>
#include <cstdint>
#include <filesystem>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <rex/cvar.h>

namespace rex::system::xam {
struct SessionRecord;
REXCVAR_DECLARE(std::string, online_status_directory);

// Notifications contain no roster and retain no network/session owner.
struct OnlineStatusSignal {
  std::mutex mutex;
  std::condition_variable wake;
  bool pending = true;
  bool stopping = false;
  void Notify();
};

// An observational attachment index, never a membership store. Record pointers
// follow XSession::set_record, not discovery cache replacement.
class OnlineStatus {
 public:
  OnlineStatus(uint64_t local_xuid, std::string local_name,
               std::filesystem::path directory = {});
  ~OnlineStatus();
  void Attach(const void* owner, std::shared_ptr<SessionRecord> record);
  void Detach(const void* owner);
  std::string Capture() const;
  const std::filesystem::path& path() const { return path_; }

 private:
  void Run();
  struct Attachment {
    uint64_t sequence;
    std::shared_ptr<SessionRecord> record;
  };
  uint64_t local_xuid_;
  std::string local_name_;
  mutable std::mutex mutex_;
  std::map<const void*, Attachment> attachments_;
  uint64_t sequence_ = 0;
  std::shared_ptr<OnlineStatusSignal> signal_ = std::make_shared<OnlineStatusSignal>();
  std::filesystem::path path_;
  uint32_t process_id_ = 0;
  std::string process_start_time_;
  std::thread worker_;
};
}  // namespace rex::system::xam
