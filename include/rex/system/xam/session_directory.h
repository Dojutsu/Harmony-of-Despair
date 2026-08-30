#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include <rex/cvar.h>

namespace rex::system::xam {

struct SessionRecord;

REXCVAR_DECLARE(std::string, session_directory_url);
REXCVAR_DECLARE(std::string, session_directory_build_id);
REXCVAR_DECLARE(std::string, session_directory_publish_address);
REXCVAR_DECLARE(std::string, session_directory_candidate_type);
REXCVAR_DECLARE(uint32_t, session_directory_session_index);

struct DirectoryCandidate {
  std::string type;
  std::string address;
  uint16_t discovery_port = 0;
  uint16_t gameplay_port = 0;
};

struct DirectorySession {
  std::string session_id;
  std::string server_name;
  uint32_t player_count = 0;
  uint32_t max_players = 0;
  uint32_t title_id = 0;
  uint32_t protocol_version = 0;
  std::string build_id;
  std::vector<DirectoryCandidate> connectivity_candidates;
};

class SessionDirectoryClient {
 public:
  SessionDirectoryClient();
  ~SessionDirectoryClient();
  SessionDirectoryClient(const SessionDirectoryClient&) = delete;
  SessionDirectoryClient& operator=(const SessionDirectoryClient&) = delete;

  void StartHosting(const std::shared_ptr<SessionRecord>& session, uint32_t title_id,
                    uint16_t discovery_port);
  void StopHosting();
  std::vector<DirectorySession> List(uint32_t title_id) const;
  void RequestList(uint32_t title_id) const;
  std::optional<std::vector<DirectorySession>> CachedList(uint32_t title_id) const;

 private:
  class Impl;
  std::unique_ptr<Impl> impl_;
};

}  // namespace rex::system::xam
