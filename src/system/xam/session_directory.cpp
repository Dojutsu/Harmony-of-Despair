#include <rex/system/xam/session_directory.h>

#include <algorithm>
#include <cctype>
#include <chrono>
#include <condition_variable>
#include <future>
#include <iomanip>
#include <mutex>
#include <optional>
#include <sstream>
#include <thread>
#include <unordered_set>

#include <inja/third_party/include/nlohmann/json.hpp>

#include <rex/logging.h>
#include <rex/system/xam/session.h>
#include <rex/system/xam/nat_probe.h>

#if REX_PLATFORM_WIN32
#include <windows.h>

#include <bcrypt.h>
#include <winhttp.h>
#include <ws2tcpip.h>
#endif

namespace rex::system::xam {

namespace {
constexpr uint32_t kDirectoryProtocolVersion = 1;
constexpr uint32_t kNoSessionIndex = 0xFFFFFFFFu;
constexpr size_t kMaxResponseBytes = 64 * 1024;
constexpr auto kHeartbeatInterval = std::chrono::seconds(15);
constexpr auto kHeartbeatRetryInitial = std::chrono::seconds(1);
constexpr auto kTraversalPollInterval = std::chrono::milliseconds(250);
constexpr auto kListCacheLifetime = std::chrono::seconds(5);
constexpr std::string_view kInviteCodeAlphabet = "ABCDEFGHJKMNPQRSTUVWXYZ23456789";
constexpr size_t kInviteCodeLength = 6;

bool IsSafeDirectoryUrl(std::string_view value) {
  if (value.empty())
    return true;
  if (value.size() > 512)
    return false;
  if (value.starts_with("https://"))
    return true;
  for (std::string_view prefix : {"http://127.0.0.1", "http://localhost"}) {
    if (!value.starts_with(prefix))
      continue;
    auto suffix = value.substr(prefix.size());
    return suffix.empty() || suffix.front() == ':' || suffix.front() == '/';
  }
  return false;
}

bool IsIpv4(std::string_view value) {
  if (value.empty())
    return true;
#if REX_PLATFORM_WIN32
  in_addr address{};
  std::string text(value);
  return inet_pton(AF_INET, text.c_str(), &address) == 1 && address.s_addr != htonl(INADDR_ANY) &&
         address.s_addr != htonl(INADDR_BROADCAST) && address.s_addr != htonl(INADDR_LOOPBACK);
#else
  return value.size() <= 45;
#endif
}

std::string TitleIdString(uint32_t title_id) {
  std::ostringstream stream;
  stream << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << title_id;
  return stream.str();
}

bool IsUrlToken(std::string_view value, size_t max_length) {
  return !value.empty() && value.size() <= max_length &&
         std::all_of(value.begin(), value.end(),
                     [](unsigned char ch) { return std::isalnum(ch) || ch == '-' || ch == '_'; });
}

bool IsPrintableName(std::string_view value) {
  return !value.empty() && value.size() <= 48 &&
         std::all_of(value.begin(), value.end(),
                     [](unsigned char ch) { return ch >= 0x20 && ch != 0x7F; });
}

std::optional<std::string> NormalizeInviteCode(std::string_view value) {
  if (value.size() != kInviteCodeLength)
    return std::nullopt;
  std::string normalized(value);
  for (char& ch : normalized) {
    ch = char(std::toupper(static_cast<unsigned char>(ch)));
    if (kInviteCodeAlphabet.find(ch) == std::string_view::npos)
      return std::nullopt;
  }
  return normalized;
}

bool IsInviteCodeSetting(std::string_view value) {
  return value.empty() || NormalizeInviteCode(value).has_value();
}

std::optional<DirectorySession> ParseDirectorySession(const nlohmann::json& item,
                                                      uint32_t title_id,
                                                      std::string_view build_id) {
  try {
    if (!item.is_object())
      return std::nullopt;
    auto session_id = item.find("session_id");
    auto server_name = item.find("server_name");
    auto item_title_id = item.find("title_id");
    auto protocol = item.find("protocol_version");
    auto item_build = item.find("build_id");
    auto player_count = item.find("player_count");
    auto max_players = item.find("max_players");
    if (session_id == item.end() || !session_id->is_string() ||
        !IsUrlToken(session_id->get_ref<const std::string&>(), 64) ||
        server_name == item.end() || !server_name->is_string() ||
        !IsPrintableName(server_name->get_ref<const std::string&>()) ||
        item_title_id == item.end() || !item_title_id->is_string() ||
        item_title_id->get<std::string>() != TitleIdString(title_id) ||
        protocol == item.end() || !protocol->is_number_unsigned() ||
        protocol->get<uint64_t>() != kDirectoryProtocolVersion || item_build == item.end() ||
        !item_build->is_string() || item_build->get<std::string>() != build_id ||
        player_count == item.end() || !player_count->is_number_unsigned() ||
        max_players == item.end() || !max_players->is_number_unsigned())
      return std::nullopt;
    uint64_t players = player_count->get<uint64_t>();
    uint64_t capacity = max_players->get<uint64_t>();
    if (!capacity || capacity > 64 || players > capacity)
      return std::nullopt;
    DirectorySession session;
    session.session_id = session_id->get<std::string>();
    session.server_name = server_name->get<std::string>().substr(0, 48);
    session.player_count = uint32_t(players);
    session.max_players = uint32_t(capacity);
    session.title_id = title_id;
    session.protocol_version = kDirectoryProtocolVersion;
    session.build_id = std::string(build_id);
    auto candidates = item.find("connectivity_candidates");
    if (candidates != item.end() && candidates->is_array()) {
      for (const auto& candidate : *candidates) {
        if (!candidate.is_object())
          continue;
        DirectoryCandidate parsed;
        auto type = candidate.find("type");
        auto address = candidate.find("address");
        auto discovery = candidate.find("discovery_port");
        auto gameplay = candidate.find("gameplay_port");
        if (type == candidate.end() || !type->is_string() || address == candidate.end() ||
            !address->is_string() || discovery == candidate.end() ||
            !discovery->is_number_unsigned() || gameplay == candidate.end() ||
            !gameplay->is_number_unsigned())
          continue;
        uint64_t discovery_value = discovery->get<uint64_t>();
        uint64_t gameplay_value = gameplay->get<uint64_t>();
        if (!discovery_value || discovery_value > 65535 || !gameplay_value ||
            gameplay_value > 65535)
          continue;
        parsed.type = type->get<std::string>();
        parsed.address = address->get<std::string>();
        parsed.discovery_port = uint16_t(discovery_value);
        parsed.gameplay_port = uint16_t(gameplay_value);
        if ((parsed.type == "direct" || parsed.type == "tailscale" ||
             parsed.type == "public") &&
            !parsed.address.empty() && IsIpv4(parsed.address))
          session.connectivity_candidates.push_back(std::move(parsed));
      }
    }
    return session.connectivity_candidates.empty()
               ? std::nullopt
               : std::optional<DirectorySession>(std::move(session));
  } catch (const nlohmann::json::exception&) {
    return std::nullopt;
  }
}

std::optional<DirectoryTraversalAttempt> ParseTraversalAttempt(const nlohmann::json& document,
                                                               std::string session_id,
                                                               uint8_t participant) {
  if (!document.is_object())
    return std::nullopt;
  auto attempt = document.value("attempt_id", "");
  auto capability = document.value("capability", "");
  auto host = document.value("rendezvous_host", "");
  auto port = document.value("rendezvous_port", 0u);
  auto role = document.value("participant", "");
  auto hex = [](std::string_view text) {
    return text.size() == 32 && std::all_of(text.begin(), text.end(), [](unsigned char ch) {
             return std::isxdigit(ch) != 0;
           });
  };
  if (!hex(attempt) || !hex(capability) || host.empty() || host.size() > 255 || !port ||
      port > 65535 || role != (participant ? "client" : "host"))
    return std::nullopt;
  return DirectoryTraversalAttempt{std::move(session_id), std::move(attempt), std::move(capability),
                                   std::move(host),       uint16_t(port),     participant};
}

std::optional<std::string> RandomUrlToken(size_t byte_count) {
#if REX_PLATFORM_WIN32
  std::vector<uint8_t> bytes(byte_count);
  if (BCryptGenRandom(nullptr, bytes.data(), ULONG(bytes.size()), BCRYPT_USE_SYSTEM_PREFERRED_RNG) <
      0)
    return std::nullopt;
  constexpr char kHex[] = "0123456789abcdef";
  std::string result(bytes.size() * 2, '0');
  for (size_t index = 0; index < bytes.size(); ++index) {
    result[index * 2] = kHex[bytes[index] >> 4];
    result[index * 2 + 1] = kHex[bytes[index] & 0x0F];
  }
  return result;
#else
  return std::nullopt;
#endif
}

struct HttpResult {
  uint32_t status = 0;
  std::string body;
};

#if REX_PLATFORM_WIN32
std::wstring WidenAscii(std::string_view value) {
  return std::wstring(value.begin(), value.end());
}

std::optional<HttpResult> Request(std::string_view base_url, std::wstring_view method,
                                  std::string_view relative_path, std::string_view body,
                                  std::string_view bearer = {}) {
  auto full_url = std::string(base_url);
  while (full_url.ends_with('/'))
    full_url.pop_back();
  if (!relative_path.starts_with('/'))
    full_url.push_back('/');
  full_url.append(relative_path);
  auto wide_url = WidenAscii(full_url);
  URL_COMPONENTS parts{};
  parts.dwStructSize = sizeof(parts);
  parts.dwSchemeLength = DWORD(-1);
  parts.dwHostNameLength = DWORD(-1);
  parts.dwUrlPathLength = DWORD(-1);
  parts.dwExtraInfoLength = DWORD(-1);
  if (!WinHttpCrackUrl(wide_url.c_str(), DWORD(wide_url.size()), 0, &parts))
    return std::nullopt;
  std::wstring host(parts.lpszHostName, parts.dwHostNameLength);
  std::wstring path(parts.lpszUrlPath, parts.dwUrlPathLength);
  if (parts.dwExtraInfoLength)
    path.append(parts.lpszExtraInfo, parts.dwExtraInfoLength);
  HINTERNET session = WinHttpOpen(L"HarmonyRecomp/1", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY,
                                  WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
  if (!session)
    return std::nullopt;
  // Directory failure must not stall the guest's existing LAN search or
  // session teardown. These are per-stage bounds; gameplay never uses HTTP.
  WinHttpSetTimeouts(session, 500, 500, 500, 1000);
  DWORD connect_retries = 0;
  WinHttpSetOption(session, WINHTTP_OPTION_CONNECT_RETRIES, &connect_retries,
                   sizeof(connect_retries));
  HINTERNET connection = WinHttpConnect(session, host.c_str(), parts.nPort, 0);
  if (!connection) {
    WinHttpCloseHandle(session);
    return std::nullopt;
  }
  DWORD flags = parts.nScheme == INTERNET_SCHEME_HTTPS ? WINHTTP_FLAG_SECURE : 0;
  HINTERNET request = WinHttpOpenRequest(connection, method.data(), path.c_str(), nullptr,
                                         WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, flags);
  if (!request) {
    WinHttpCloseHandle(connection);
    WinHttpCloseHandle(session);
    return std::nullopt;
  }
  std::wstring headers = L"Accept: application/json\r\nContent-Type: application/json\r\n";
  if (!bearer.empty()) {
    headers += L"Authorization: Bearer ";
    headers += WidenAscii(bearer);
    headers += L"\r\n";
  }
  BOOL sent =
      WinHttpSendRequest(request, headers.c_str(), DWORD(headers.size()),
                         body.empty() ? WINHTTP_NO_REQUEST_DATA : const_cast<char*>(body.data()),
                         DWORD(body.size()), DWORD(body.size()), 0);
  BOOL received = sent && WinHttpReceiveResponse(request, nullptr);
  HttpResult result;
  DWORD status_size = sizeof(result.status);
  if (received)
    WinHttpQueryHeaders(request, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                        WINHTTP_HEADER_NAME_BY_INDEX, &result.status, &status_size,
                        WINHTTP_NO_HEADER_INDEX);
  while (received && result.body.size() < kMaxResponseBytes) {
    DWORD available = 0;
    if (!WinHttpQueryDataAvailable(request, &available) || !available)
      break;
    available = std::min<DWORD>(available, DWORD(kMaxResponseBytes - result.body.size()));
    size_t offset = result.body.size();
    result.body.resize(offset + available);
    DWORD read = 0;
    if (!WinHttpReadData(request, result.body.data() + offset, available, &read)) {
      received = false;
      break;
    }
    result.body.resize(offset + read);
  }
  WinHttpCloseHandle(request);
  WinHttpCloseHandle(connection);
  WinHttpCloseHandle(session);
  return received ? std::optional<HttpResult>(std::move(result)) : std::nullopt;
}
#else
std::optional<HttpResult> Request(std::string_view, std::wstring_view, std::string_view,
                                  std::string_view, std::string_view = {}) {
  return std::nullopt;
}
#endif

nlohmann::json RegistrationPayload(const SessionRecord& session, uint32_t title_id,
                                   uint16_t discovery_port) {
  std::lock_guard lock(*session.mutex);
  uint32_t max_players = session.max_public_slots + session.max_private_slots;
  uint32_t gameplay_port = REXCVAR_GET(lan_gameplay_port);
  if (!gameplay_port)
    gameplay_port = session.info.host_address.port;
  return {
      {"server_name", session.host_name.substr(0, 48)},
      {"player_count", session.members.size()},
      {"max_players", max_players},
      {"title_id", TitleIdString(title_id)},
      {"protocol_version", kDirectoryProtocolVersion},
      {"build_id", REXCVAR_GET(session_directory_build_id)},
      {"connectivity_candidates",
       nlohmann::json::array({{{"type", REXCVAR_GET(session_directory_candidate_type)},
                               {"address", REXCVAR_GET(session_directory_publish_address)},
                               {"discovery_port", discovery_port},
                               {"gameplay_port", gameplay_port}}})},
  };
}
}  // namespace

std::optional<std::string> NormalizeDirectoryInviteCode(std::string_view value) {
  return NormalizeInviteCode(value);
}

std::optional<DirectorySession> ParseInviteCodeSessionResponse(std::string_view body,
                                                               uint32_t title_id,
                                                               std::string_view build_id) {
  auto document = nlohmann::json::parse(body, nullptr, false);
  if (!document.is_object() || !document.contains("session"))
    return std::nullopt;
  return ParseDirectorySession(document["session"], title_id, build_id);
}

REXCVAR_DEFINE_STRING(session_directory_url, "", "Network",
                      "HTTPS Harmony session-directory URL (empty disables directory access)")
    .validator(IsSafeDirectoryUrl)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_build_id, "", "Network",
                      "Session-directory compatibility identifier")
    .validator([](std::string_view value) {
      return value.size() <= 64 && std::all_of(value.begin(), value.end(), [](unsigned char ch) {
               return std::isalnum(ch) || ch == '.' || ch == '_' || ch == '-';
             });
    })
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_publish_address, "", "Network",
                      "Explicit IPv4 address published by a directory host")
    .validator(IsIpv4)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_candidate_type, "tailscale", "Network",
                      "Published directory candidate type: direct, tailscale, or public")
    .validator([](std::string_view value) {
      return value == "direct" || value == "tailscale" || value == "public";
    })
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_UINT32(session_directory_session_index, kNoSessionIndex, "Network",
                      "Directory result index to resolve through Direct Connect")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(session_directory_invite_code, "", "Network",
                      "Resolve one directory lobby by its six-character invite code")
    .validator(IsInviteCodeSetting)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

DirectoryHeartbeatDisposition ClassifyDirectoryHeartbeatResponse(std::optional<uint32_t> status,
                                                                 bool valid_session_id) {
  if (!status)
    return DirectoryHeartbeatDisposition::kRetrySameRegistration;
  if (*status == 404)
    return DirectoryHeartbeatDisposition::kRecoverRegistration;
  if (*status == 400 || *status == 401 || *status == 403)
    return DirectoryHeartbeatDisposition::kRejected;
  if (*status == 200 && valid_session_id)
    return DirectoryHeartbeatDisposition::kAccepted;
  return DirectoryHeartbeatDisposition::kRetrySameRegistration;
}

class SessionDirectoryClient::Impl {
 public:
  ~Impl() {
    StopHosting();
    std::future<std::vector<DirectorySession>> pending;
    {
      std::lock_guard lock(list_mutex);
      pending = std::move(list_future);
    }
    if (pending.valid())
      pending.wait();
  }

  void StartHosting(std::shared_ptr<SessionRecord> value, uint32_t value_title_id,
                    uint16_t value_discovery_port) {
    StopHosting();
    if (REXCVAR_GET(session_directory_url).empty())
      return;
    if (REXCVAR_GET(session_directory_build_id).empty() ||
        (REXCVAR_GET(session_directory_candidate_type) != "public" &&
         REXCVAR_GET(session_directory_publish_address).empty())) {
      REXSYS_WARN(
          "Session directory: hosting disabled; build ID and a publish address for non-public "
          "candidates are required");
      return;
    }
#if !REX_PLATFORM_WIN32
    REXSYS_WARN("Session directory: HTTPS client is not available on this platform");
    return;
#endif
    hosted = std::move(value);
    title_id = value_title_id;
    discovery_port = value_discovery_port;
    worker = std::jthread([this](std::stop_token stop) { HostLoop(stop); });
  }

  void StopHosting() {
    if (worker.joinable()) {
      worker.request_stop();
      wake.notify_all();
      worker.join();
    }
    hosted.reset();
  }

  std::vector<DirectorySession> List(uint32_t value_title_id) const {
    std::vector<DirectorySession> result;
    const auto& url = REXCVAR_GET(session_directory_url);
    const auto& build_id = REXCVAR_GET(session_directory_build_id);
    if (url.empty() || build_id.empty())
      return result;
    std::string path = "/sessions?title_id=" + TitleIdString(value_title_id) +
                       "&protocol_version=1&build_id=" + build_id;
    auto response = Request(url, L"GET", path, "");
    if (!response || response->status != 200) {
      REXSYS_WARN("Session directory: list request unavailable");
      return result;
    }
    auto document = nlohmann::json::parse(response->body, nullptr, false);
    if (document.is_discarded() || !document.is_object() || !document.contains("sessions") ||
        !document["sessions"].is_array()) {
      REXSYS_WARN("Session directory: invalid list response");
      return result;
    }
    for (const auto& item : document["sessions"]) {
      if (auto session = ParseDirectorySession(item, value_title_id, build_id))
        result.push_back(std::move(*session));
    }
    REXSYS_INFO("Session directory: query returned {} compatible session(s)", result.size());
    return result;
  }

  std::optional<DirectorySession> ResolveInviteCode(std::string_view code,
                                                    uint32_t value_title_id) const {
    auto normalized = NormalizeInviteCode(code);
    const auto& url = REXCVAR_GET(session_directory_url);
    const auto& build_id = REXCVAR_GET(session_directory_build_id);
    if (!normalized || url.empty() || build_id.empty())
      return std::nullopt;
    auto response = Request(url, L"GET", "/sessions/by-code/" + *normalized, "");
    if (!response || response->status != 200)
      return std::nullopt;
    return ParseInviteCodeSessionResponse(response->body, value_title_id, build_id);
  }

  void RequestList(uint32_t value_title_id) const {
    std::lock_guard lock(list_mutex);
    HarvestListLocked();
    auto now = std::chrono::steady_clock::now();
    if (list_cache && list_cache_title_id == value_title_id &&
        now - list_cache_time < kListCacheLifetime)
      return;
    if (list_future.valid())
      return;
    list_future_title_id = value_title_id;
    list_future =
        std::async(std::launch::async, [this, value_title_id] { return List(value_title_id); });
  }

  std::optional<std::vector<DirectorySession>> CachedList(uint32_t value_title_id) const {
    std::lock_guard lock(list_mutex);
    HarvestListLocked();
    if (!list_cache || list_cache_title_id != value_title_id ||
        std::chrono::steady_clock::now() - list_cache_time >= kListCacheLifetime)
      return std::nullopt;
    return list_cache;
  }

  std::optional<DirectoryTraversalAttempt> CreateJoinAttempt(const std::string& session_id) const {
    const auto& url = REXCVAR_GET(session_directory_url);
    if (url.empty() || !IsUrlToken(session_id, 64))
      return std::nullopt;
    auto response = Request(url, L"POST", "/sessions/" + session_id + "/join-attempts", "{}");
    if (!response || response->status != 201)
      return std::nullopt;
    auto document = nlohmann::json::parse(response->body, nullptr, false);
    return ParseTraversalAttempt(document, session_id, 1);
  }

  void CompleteJoinAttempt(const DirectoryTraversalAttempt& attempt) const {
    const auto& url = REXCVAR_GET(session_directory_url);
    if (url.empty() || !IsUrlToken(attempt.session_id, 64) || !IsUrlToken(attempt.attempt_id, 64) ||
        attempt.capability.empty())
      return;
    Request(url, L"DELETE",
            "/sessions/" + attempt.session_id + "/join-attempts/" + attempt.attempt_id, "",
            attempt.capability);
    NatProbeRetireIdentity(attempt.attempt_id);
  }

 private:
  void HarvestListLocked() const {
    if (!list_future.valid() ||
        list_future.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
      return;
    try {
      list_cache = list_future.get();
    } catch (const std::exception& exception) {
      REXSYS_WARN("Session directory: asynchronous list request failed: {}", exception.what());
      list_cache = std::vector<DirectorySession>{};
    }
    list_cache_title_id = list_future_title_id;
    list_cache_time = std::chrono::steady_clock::now();
  }

  void HostLoop(std::stop_token stop) {
    auto host_instance_id = RandomUrlToken(16);
    auto host_instance_token = RandomUrlToken(32);
    if (!host_instance_id || !host_instance_token) {
      REXSYS_WARN("Session directory: secure host registration identity unavailable");
      return;
    }
    std::string session_id;
    std::string token;
    std::unordered_set<std::string> host_attempts;
    bool recovering = false;
    auto next_heartbeat = std::chrono::steady_clock::time_point{};
    auto next_registration = std::chrono::steady_clock::time_point{};
    auto retry_delay = kHeartbeatRetryInitial;
    auto schedule_retry = [&] {
      next_registration = std::chrono::steady_clock::now() + retry_delay;
      retry_delay = std::min(retry_delay * 2, kHeartbeatInterval);
    };
    auto schedule_heartbeat = [&] {
      retry_delay = kHeartbeatRetryInitial;
      next_heartbeat = std::chrono::steady_clock::now() + kHeartbeatInterval;
    };
    while (!stop.stop_requested()) {
      auto registration = RegistrationPayload(*hosted, title_id, discovery_port);
      auto heartbeat_body = registration.dump();
      registration["host_instance_id"] = *host_instance_id;
      registration["host_instance_token"] = *host_instance_token;
      auto registration_body = registration.dump();
      std::optional<HttpResult> response;
      auto now = std::chrono::steady_clock::now();
      if ((session_id.empty() || recovering) && now >= next_registration) {
        response =
            Request(REXCVAR_GET(session_directory_url), L"POST", "/sessions", registration_body);
        bool accepted = false;
        if (response && (response->status == 200 || response->status == 201)) {
          auto document = nlohmann::json::parse(response->body, nullptr, false);
          if (document.is_object()) {
            auto candidate_session_id = document.value("session_id", "");
            auto candidate_token = document.value("registration_token", "");
            auto candidate_invite_code = document.value("invite_code", "");
            if (IsUrlToken(candidate_session_id, 64) && IsUrlToken(candidate_token, 128) &&
                NormalizeInviteCode(candidate_invite_code)) {
              bool changed = !session_id.empty() && candidate_session_id != session_id;
              session_id = std::move(candidate_session_id);
              token = std::move(candidate_token);
              accepted = true;
              if (recovering && changed)
                REXSYS_INFO("Session directory: recovered '{}' with replacement {}",
                            hosted->host_name, session_id);
              else if (recovering)
                REXSYS_INFO("Session directory: recovered '{}' as {}", hosted->host_name,
                            session_id);
              else
                REXSYS_INFO("Session directory: registered '{}' as {}", hosted->host_name,
                            session_id);
              REXSYS_INFO("Harmony invite code: {}", candidate_invite_code);
            }
          }
        }
        if (accepted) {
          recovering = false;
          schedule_heartbeat();
        } else {
          if (response &&
              (response->status == 400 || response->status == 401 || response->status == 403))
            REXSYS_WARN("Session directory: host registration rejected with HTTP {}",
                        response->status);
          else if (response)
            REXSYS_WARN("Session directory: host registration HTTP {}; retrying same identity",
                        response->status);
          else
            REXSYS_WARN(
                "Session directory: host registration transport failure; retrying same identity");
          schedule_retry();
        }
      } else if (!recovering && !session_id.empty() && now >= next_heartbeat) {
        response = Request(REXCVAR_GET(session_directory_url), L"POST",
                           "/sessions/" + session_id + "/heartbeat", heartbeat_body, token);
        bool valid_session_id = false;
        if (response && response->status == 200) {
          auto document = nlohmann::json::parse(response->body, nullptr, false);
          valid_session_id = document.is_object() && document.value("session_id", "") == session_id;
        }
        auto disposition = ClassifyDirectoryHeartbeatResponse(
            response ? std::optional<uint32_t>(response->status) : std::nullopt, valid_session_id);
        switch (disposition) {
          case DirectoryHeartbeatDisposition::kAccepted:
            schedule_heartbeat();
            break;
          case DirectoryHeartbeatDisposition::kRetrySameRegistration:
            if (response)
              REXSYS_WARN("Session directory: heartbeat HTTP {}; retrying same registration",
                          response->status);
            else
              REXSYS_WARN(
                  "Session directory: heartbeat transport failure; retrying same registration");
            next_heartbeat = std::chrono::steady_clock::now() + retry_delay;
            retry_delay = std::min(retry_delay * 2, kHeartbeatInterval);
            break;
          case DirectoryHeartbeatDisposition::kRecoverRegistration:
            REXSYS_WARN("Session directory: heartbeat returned 404; recovering logical lobby");
            for (const auto& attempt : host_attempts)
              NatProbeRetireIdentity(attempt);
            host_attempts.clear();
            recovering = true;
            next_registration = std::chrono::steady_clock::now();
            retry_delay = kHeartbeatRetryInitial;
            break;
          case DirectoryHeartbeatDisposition::kRejected:
            REXSYS_WARN("Session directory: heartbeat rejected with HTTP {}", response->status);
            next_heartbeat = std::chrono::steady_clock::now() + kHeartbeatInterval;
            break;
        }
      }
      if (!session_id.empty() && !recovering) {
        auto pending = Request(REXCVAR_GET(session_directory_url), L"GET",
                               "/sessions/" + session_id + "/join-attempts", "", token);
        if (pending && pending->status == 200) {
          auto document = nlohmann::json::parse(pending->body, nullptr, false);
          if (document.is_object() && document.contains("attempts") &&
              document["attempts"].is_array()) {
            std::unordered_set<std::string> pending_attempts;
            for (const auto& item : document["attempts"]) {
              auto attempt = ParseTraversalAttempt(item, session_id, 0);
              if (attempt) {
                pending_attempts.insert(attempt->attempt_id);
                NatProbeInstallIdentity({attempt->attempt_id, attempt->capability,
                                         attempt->rendezvous_host, attempt->rendezvous_port, 0});
              }
            }
            for (const auto& attempt : host_attempts)
              if (!pending_attempts.contains(attempt))
                NatProbeRetireIdentity(attempt);
            host_attempts = std::move(pending_attempts);
          }
        }
      }
      std::unique_lock lock(wait_mutex);
      wake.wait_for(lock, kTraversalPollInterval, [&] { return stop.stop_requested(); });
    }
    for (const auto& attempt : host_attempts)
      NatProbeRetireIdentity(attempt);
    if (!session_id.empty())
      Request(REXCVAR_GET(session_directory_url), L"DELETE", "/sessions/" + session_id, "", token);
  }

  std::shared_ptr<SessionRecord> hosted;
  uint32_t title_id = 0;
  uint16_t discovery_port = 0;
  std::jthread worker;
  std::condition_variable wake;
  std::mutex wait_mutex;
  mutable std::mutex list_mutex;
  mutable std::future<std::vector<DirectorySession>> list_future;
  mutable std::optional<std::vector<DirectorySession>> list_cache;
  mutable uint32_t list_future_title_id = 0;
  mutable uint32_t list_cache_title_id = 0;
  mutable std::chrono::steady_clock::time_point list_cache_time{};
};

SessionDirectoryClient::SessionDirectoryClient() : impl_(std::make_unique<Impl>()) {}
SessionDirectoryClient::~SessionDirectoryClient() = default;
void SessionDirectoryClient::StartHosting(const std::shared_ptr<SessionRecord>& session,
                                          uint32_t title_id, uint16_t discovery_port) {
  impl_->StartHosting(session, title_id, discovery_port);
}
void SessionDirectoryClient::StopHosting() {
  impl_->StopHosting();
}
std::vector<DirectorySession> SessionDirectoryClient::List(uint32_t title_id) const {
  return impl_->List(title_id);
}
void SessionDirectoryClient::RequestList(uint32_t title_id) const {
  impl_->RequestList(title_id);
}
std::optional<std::vector<DirectorySession>> SessionDirectoryClient::CachedList(
    uint32_t title_id) const {
  return impl_->CachedList(title_id);
}
std::optional<DirectorySession> SessionDirectoryClient::ResolveInviteCode(
    std::string_view code, uint32_t title_id) const {
  return impl_->ResolveInviteCode(code, title_id);
}
std::optional<DirectoryTraversalAttempt> SessionDirectoryClient::CreateJoinAttempt(
    const std::string& session_id) const {
  return impl_->CreateJoinAttempt(session_id);
}
void SessionDirectoryClient::CompleteJoinAttempt(const DirectoryTraversalAttempt& attempt) const {
  impl_->CompleteJoinAttempt(attempt);
}

}  // namespace rex::system::xam
