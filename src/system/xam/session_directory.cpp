#include <rex/system/xam/session_directory.h>

#include <algorithm>
#include <cctype>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <future>
#include <iomanip>
#include <iterator>
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
bool IsLowerHex128(std::string_view value) {
  return value.size() == 32 &&
         std::all_of(value.begin(), value.end(), [](char ch) {
           return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f');
         });
}

std::optional<HostAdmissionGrantStore::Clock::time_point> AdmissionDeadline(
    HostAdmissionGrantStore::Clock::time_point poll_started_at,
    uint32_t admission_expires_in_ms) {
  if (!admission_expires_in_ms || admission_expires_in_ms == UINT32_MAX)
    return std::nullopt;
  const auto remaining = std::chrono::duration_cast<HostAdmissionGrantStore::Clock::duration>(
      std::chrono::milliseconds(admission_expires_in_ms));
  if (remaining <= HostAdmissionGrantStore::Clock::duration::zero() ||
      poll_started_at > HostAdmissionGrantStore::Clock::time_point::max() - remaining)
    return std::nullopt;
  return poll_started_at + remaining;
}
}  // namespace

void HostAdmissionGrantStore::InvalidateGrantLocked(Grant& grant) {
  if (grant.reservation_id) {
    grant.invalidated_while_reserved = true;
  } else if (!grant.consumed_xuid) {
    grant.expires_at = {};
  }
}

void HostAdmissionGrantStore::ApplyAuthenticatedPoll(
    std::string_view directory_session_id, std::span<const HostAdmissionPollAttempt> attempts,
    Clock::time_point poll_started_at) {
  std::lock_guard lock(mutex_);
  hosted_directory_session_ = std::string(directory_session_id);
  std::unordered_set<std::string> seen;
  for (const auto& attempt : attempts) {
    if (!seen.insert(attempt.attempt_id).second)
      continue;
    auto found = grants_.find(attempt.attempt_id);
    const bool installable = attempt.purpose == "invite_code_private_eligible" &&
                             attempt.host_ready && IsLowerHex128(attempt.attempt_id) &&
                             IsLowerHex128(attempt.admission_generation) &&
                             attempt.lease_revision && attempt.admission_expires_in_ms;
    const auto returned_expiry =
        installable ? AdmissionDeadline(poll_started_at, attempt.admission_expires_in_ms)
                    : std::nullopt;
    if (!installable || !returned_expiry) {
      if (found != grants_.end())
        InvalidateGrantLocked(found->second);
      continue;
    }
    // The server computed its remaining lifetime before transmitting the
    // response. Anchor to the earlier local request time so response transit
    // can only shorten, never extend, private authority.
    if (found == grants_.end()) {
      Grant grant;
      grant.directory_session_id = directory_session_id;
      grant.attempt_id = attempt.attempt_id;
      grant.capability = attempt.capability;
      grant.admission_generation = attempt.admission_generation;
      grant.lease_revision = attempt.lease_revision;
      grant.expires_at = *returned_expiry;
      grants_.emplace(grant.attempt_id, std::move(grant));
      continue;
    }
    auto& grant = found->second;
    if (grant.directory_session_id != directory_session_id ||
        grant.admission_generation != attempt.admission_generation ||
        attempt.lease_revision < grant.lease_revision ||
        attempt.lease_revision > grant.lease_revision + 1 || grant.consumed_xuid)
      continue;
    if (grant.reservation_id) {
      if (attempt.lease_revision != grant.lease_revision)
        grant.invalidated_while_reserved = true;
      continue;
    }
    grant.capability = attempt.capability;
    if (attempt.lease_revision == grant.lease_revision) {
      grant.expires_at = std::min(grant.expires_at, *returned_expiry);
    } else {
      grant.lease_revision = attempt.lease_revision;
      grant.expires_at = *returned_expiry;
      grant.reserved_socket = 0;
      grant.reserved_ipv4 = 0;
      grant.reserved_port = 0;
      grant.reserved_xuid = 0;
      grant.invalidated_while_reserved = false;
    }
  }
  for (auto& [attempt_id, grant] : grants_) {
    if (grant.directory_session_id == directory_session_id && !seen.contains(attempt_id))
      InvalidateGrantLocked(grant);
  }
  std::erase_if(grants_, [](const auto& item) {
    const auto& grant = item.second;
    return !grant.reservation_id && !grant.consumed_xuid && grant.expires_at == Clock::time_point{};
  });
}

HostAdmissionReservationResult HostAdmissionGrantStore::Reserve(
    std::string_view directory_session_id, uint64_t discovery_socket,
    uint32_t peer_ipv4, uint16_t peer_port,
    std::span<const std::string> acknowledged_attempt_ids, uint64_t xuid,
    Clock::time_point now) {
  HostAdmissionReservationResult result;
  if (!xuid || !discovery_socket || !peer_ipv4 || !peer_port)
    return result;
  std::lock_guard lock(mutex_);
  std::unordered_set<std::string> acknowledged(acknowledged_attempt_ids.begin(),
                                                acknowledged_attempt_ids.end());
  std::vector<Grant*> candidates;
  Grant* consumed_duplicate = nullptr;
  size_t consumed_duplicate_count = 0;
  for (auto& [attempt_id, grant] : grants_) {
    if (!acknowledged.contains(attempt_id) ||
        grant.directory_session_id != directory_session_id)
      continue;
    if (grant.consumed_xuid) {
      if (grant.consumed_xuid == xuid) {
        consumed_duplicate = &grant;
        ++consumed_duplicate_count;
      }
      continue;
    }
    if (!grant.reservation_id && now >= grant.expires_at)
      continue;
    if (grant.reservation_id &&
        (grant.reserved_socket != discovery_socket || grant.reserved_ipv4 != peer_ipv4 ||
         grant.reserved_port != peer_port || grant.reserved_xuid != xuid))
      continue;
    candidates.push_back(&grant);
  }
  if (candidates.size() > 1) {
    result.status = HostAdmissionReservationStatus::kAmbiguous;
    return result;
  }
  if (candidates.empty()) {
    if (consumed_duplicate_count > 1)
      result.status = HostAdmissionReservationStatus::kAmbiguous;
    else if (consumed_duplicate)
      result.status = HostAdmissionReservationStatus::kConsumedDuplicate;
    return result;
  }
  auto& grant = *candidates.front();
  if (grant.reservation_id) {
    result.status = HostAdmissionReservationStatus::kDuplicateReservation;
  } else {
    grant.reservation_id = next_reservation_id_++;
    if (!grant.reservation_id)
      grant.reservation_id = next_reservation_id_++;
    grant.reserved_socket = discovery_socket;
    grant.reserved_ipv4 = peer_ipv4;
    grant.reserved_port = peer_port;
    grant.reserved_xuid = xuid;
    result.status = HostAdmissionReservationStatus::kReserved;
  }
  result.reservation = {grant.directory_session_id, grant.attempt_id,
                        grant.admission_generation, grant.lease_revision,
                        discovery_socket, peer_ipv4, peer_port, xuid,
                        grant.reservation_id};
  return result;
}

void HostAdmissionGrantStore::Finish(const HostAdmissionReservation& reservation,
                                     bool committed, Clock::time_point now) {
  if (!reservation)
    return;
  std::lock_guard lock(mutex_);
  auto found = grants_.find(reservation.attempt_id);
  if (found == grants_.end())
    return;
  auto& grant = found->second;
  if (grant.directory_session_id != reservation.directory_session_id ||
      grant.admission_generation != reservation.admission_generation ||
      grant.lease_revision != reservation.lease_revision ||
      grant.reservation_id != reservation.reservation_id ||
      grant.reserved_socket != reservation.discovery_socket ||
      grant.reserved_ipv4 != reservation.peer_ipv4 ||
      grant.reserved_port != reservation.peer_port ||
      grant.reserved_xuid != reservation.xuid)
    return;
  if (committed) {
    grant.consumed_xuid = reservation.xuid;
    grant.reservation_id = 0;
    completions_.push_back(
        {grant.directory_session_id, grant.attempt_id, grant.capability});
    return;
  }
  if (grant.invalidated_while_reserved || now >= grant.expires_at) {
    grants_.erase(found);
    return;
  }
  grant.reservation_id = 0;
  grant.reserved_socket = 0;
  grant.reserved_ipv4 = 0;
  grant.reserved_port = 0;
  grant.reserved_xuid = 0;
}

void HostAdmissionGrantStore::InvalidateSession(std::string_view directory_session_id) {
  std::lock_guard lock(mutex_);
  for (auto& [_, grant] : grants_)
    if (grant.directory_session_id == directory_session_id)
      InvalidateGrantLocked(grant);
  std::erase_if(grants_, [](const auto& item) {
    const auto& grant = item.second;
    return !grant.reservation_id && !grant.consumed_xuid && grant.expires_at == Clock::time_point{};
  });
  std::erase_if(completions_, [&](const auto& completion) {
    return completion.directory_session_id == directory_session_id;
  });
  if (hosted_directory_session_ == directory_session_id)
    hosted_directory_session_.clear();
}

void HostAdmissionGrantStore::Clear() {
  std::lock_guard lock(mutex_);
  grants_.clear();
  completions_.clear();
  hosted_directory_session_.clear();
}

std::vector<HostAdmissionCompletion> HostAdmissionGrantStore::TakeCompletions() {
  std::lock_guard lock(mutex_);
  auto result = std::move(completions_);
  completions_.clear();
  return result;
}

std::optional<std::string> HostAdmissionGrantStore::hosted_directory_session() const {
  std::lock_guard lock(mutex_);
  if (hosted_directory_session_.empty())
    return std::nullopt;
  return hosted_directory_session_;
}

size_t HostAdmissionGrantStore::available_grant_count(Clock::time_point now) const {
  std::lock_guard lock(mutex_);
  return std::count_if(grants_.begin(), grants_.end(), [&](const auto& item) {
    const auto& grant = item.second;
    return !grant.reservation_id && !grant.consumed_xuid && now < grant.expires_at;
  });
}

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

std::optional<std::filesystem::path> ActiveInviteCodePath() {
#if REX_PLATFORM_WIN32
  const char* local_app_data = std::getenv("LOCALAPPDATA");
  if (local_app_data && *local_app_data)
    return std::filesystem::path(local_app_data) / "HarmonyRecomp" / "active-invite-code.txt";
#endif
  return std::nullopt;
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
  try {
    auto attempt = document.value("attempt_id", "");
    auto capability = document.value("capability", "");
    auto host = document.value("rendezvous_host", "");
    auto port = document.value("rendezvous_port", 0u);
    auto role = document.value("participant", "");
    auto purpose = document.value("purpose", "");
    if (!IsLowerHex128(attempt) || !IsLowerHex128(capability) || host.empty() ||
        host.size() > 255 || !port || port > 65535 ||
        role != (participant ? "client" : "host") ||
        (purpose != "public" && purpose != "invite_code_private_eligible"))
      return std::nullopt;
    DirectoryTraversalAttempt result;
    result.session_id = std::move(session_id);
    result.attempt_id = std::move(attempt);
    result.capability = std::move(capability);
    result.rendezvous_host = std::move(host);
    result.rendezvous_port = uint16_t(port);
    result.participant = participant;
    result.purpose = std::move(purpose);
    auto generation = document.find("admission_generation");
    auto revision = document.find("lease_revision");
    auto expires = document.find("admission_expires_in_ms");
    auto ready = document.find("host_ready");
    if (generation != document.end() && !generation->is_null()) {
      if (!generation->is_string() ||
          !IsLowerHex128(generation->get_ref<const std::string&>()) ||
          revision == document.end() || !revision->is_number_unsigned() ||
          !revision->get<uint64_t>() || expires == document.end() ||
          !expires->is_number_unsigned() ||
          !expires->get<uint64_t>() || expires->get<uint64_t>() >= UINT32_MAX ||
          ready == document.end() ||
          !ready->is_boolean())
        return std::nullopt;
      result.admission_generation = generation->get<std::string>();
      result.lease_revision = revision->get<uint64_t>();
      result.admission_expires_in_ms = uint32_t(expires->get<uint64_t>());
      result.host_ready = ready->get<bool>();
    }
    return result;
  } catch (const nlohmann::json::exception&) {
    return std::nullopt;
  }
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

std::optional<std::vector<DirectoryTraversalAttempt>> ParseDirectoryHostPollSnapshot(
    std::string_view body, std::string_view directory_session_id) {
  auto document = nlohmann::json::parse(body, nullptr, false);
  if (!document.is_object() || !document.contains("attempts") ||
      !document["attempts"].is_array())
    return std::nullopt;
  std::vector<DirectoryTraversalAttempt> attempts;
  attempts.reserve(document["attempts"].size());
  for (const auto& item : document["attempts"]) {
    auto attempt = ParseTraversalAttempt(item, std::string(directory_session_id), 0);
    if (!attempt)
      return std::nullopt;
    attempts.push_back(std::move(*attempt));
  }
  return attempts;
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

DirectoryHostPollDisposition ClassifyDirectoryHostPollResponse(std::optional<uint32_t> status,
                                                               bool valid_snapshot) {
  if (!status)
    return DirectoryHostPollDisposition::kRetainUntilExpiry;
  if (*status == 404)
    return DirectoryHostPollDisposition::kRecoverRegistration;
  if (*status != 200)
    return DirectoryHostPollDisposition::kRetainUntilExpiry;
  return valid_snapshot ? DirectoryHostPollDisposition::kAccepted
                        : DirectoryHostPollDisposition::kRejectSnapshot;
}

DirectoryHostPollTransition ApplyDirectoryHostPollResult(
    DirectoryHostPollDisposition disposition,
    std::span<const DirectoryTraversalAttempt> attempts,
    DirectoryHostPollRuntimeState& state,
    HostAdmissionGrantStore* admission_grants, SessionRecord& hosted,
    HostAdmissionGrantStore::Clock::time_point poll_started_at) {
  DirectoryHostPollTransition transition;
  switch (disposition) {
    case DirectoryHostPollDisposition::kAccepted: {
      std::unordered_set<std::string> next_host_attempts;
      std::unordered_map<std::string, HostAdmissionPollAttempt> next_private_attempts;
      std::vector<HostAdmissionPollAttempt> grant_snapshot;
      for (const auto& attempt : attempts) {
        next_host_attempts.insert(attempt.attempt_id);
        NatProbeInstallIdentity({attempt.attempt_id, attempt.capability,
                                 attempt.rendezvous_host, attempt.rendezvous_port, 0});
        HostAdmissionPollAttempt host_attempt{
            attempt.attempt_id,     attempt.capability,
            attempt.purpose,        attempt.admission_generation,
            attempt.lease_revision, attempt.admission_expires_in_ms,
            attempt.host_ready};
        grant_snapshot.push_back(host_attempt);
        if (attempt.purpose == "invite_code_private_eligible" &&
            !attempt.admission_generation.empty())
          next_private_attempts.emplace(attempt.attempt_id, std::move(host_attempt));
      }
      for (const auto& attempt : state.host_attempts)
        if (!next_host_attempts.contains(attempt))
          NatProbeRetireIdentity(attempt);
      state.host_attempts = std::move(next_host_attempts);
      state.private_attempts = std::move(next_private_attempts);
      if (admission_grants)
        admission_grants->ApplyAuthenticatedPoll(
            state.directory_session_id, grant_snapshot, poll_started_at);
      break;
    }
    case DirectoryHostPollDisposition::kRejectSnapshot:
      if (admission_grants)
        admission_grants->ApplyAuthenticatedPoll(
            state.directory_session_id,
            std::span<const HostAdmissionPollAttempt>{}, poll_started_at);
      state.private_attempts.clear();
      break;
    case DirectoryHostPollDisposition::kRecoverRegistration: {
      if (auto path = ActiveInviteCodePath())
        RemoveActiveInviteCodeFile(*path);
      const auto invalidated_session = state.directory_session_id;
      if (admission_grants)
        admission_grants->InvalidateSession(invalidated_session);
      for (const auto& attempt : state.host_attempts)
        NatProbeRetireIdentity(attempt);
      state.host_attempts.clear();
      state.private_attempts.clear();
      state.pending_completions.clear();
      state.directory_session_id.clear();
      state.registration_token.clear();
      state.public_invite_code.clear();
      state.recovering = true;
      transition.recover_now = true;
      break;
    }
    case DirectoryHostPollDisposition::kRetainUntilExpiry:
      break;
  }
  return transition;
}

bool WriteActiveInviteCodeFile(const std::filesystem::path& path, std::string_view code) {
  auto normalized = NormalizeInviteCode(code);
  if (!normalized)
    return false;
  std::error_code error;
  std::filesystem::create_directories(path.parent_path(), error);
  if (error)
    return false;
  auto temporary = path;
  temporary += ".tmp";
  {
    std::ofstream output(temporary, std::ios::binary | std::ios::trunc);
    if (!output || !output.write(normalized->data(), normalized->size()))
      return false;
  }
#if REX_PLATFORM_WIN32
  if (!MoveFileExW(temporary.c_str(), path.c_str(),
                   MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
    std::filesystem::remove(temporary, error);
    return false;
  }
#else
  std::filesystem::rename(temporary, path, error);
  if (error) {
    std::filesystem::remove(temporary, error);
    return false;
  }
#endif
  return true;
}

void RemoveActiveInviteCodeFile(const std::filesystem::path& path) {
  std::error_code error;
  std::filesystem::remove(path, error);
  auto temporary = path;
  temporary += ".tmp";
  std::filesystem::remove(temporary, error);
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
                    uint16_t value_discovery_port,
                    std::shared_ptr<HostAdmissionGrantStore> value_admission_grants) {
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
    admission_grants = std::move(value_admission_grants);
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
    if (admission_grants) admission_grants->Clear();
    hosted.reset();
    admission_grants.reset();
    if (auto path = ActiveInviteCodePath())
      RemoveActiveInviteCodeFile(*path);
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
    DirectoryHostPollRuntimeState poll_state;
    auto& session_id = poll_state.directory_session_id;
    auto& host_attempts = poll_state.host_attempts;
    auto& polled_private_attempts = poll_state.private_attempts;
    auto& pending_completions = poll_state.pending_completions;
    auto& recovering = poll_state.recovering;
    auto& token = poll_state.registration_token;
    auto& public_invite_code = poll_state.public_invite_code;
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
              if (auto path = ActiveInviteCodePath();
                  path && !WriteActiveInviteCodeFile(*path, candidate_invite_code))
                REXSYS_WARN("Harmony invite code: could not publish launcher state");
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
            if (admission_grants)
              admission_grants->InvalidateSession(session_id);
            for (const auto& attempt : host_attempts)
              NatProbeRetireIdentity(attempt);
            host_attempts.clear();
            polled_private_attempts.clear();
            pending_completions.clear();
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
        if (admission_grants) {
          auto completed = admission_grants->TakeCompletions();
          pending_completions.insert(pending_completions.end(),
                                     std::make_move_iterator(completed.begin()),
                                     std::make_move_iterator(completed.end()));
          std::erase_if(pending_completions, [&](const auto& completion) {
            if (completion.directory_session_id != session_id)
              return true;
            auto response = Request(
                REXCVAR_GET(session_directory_url), L"DELETE",
                "/sessions/" + session_id + "/join-attempts/" +
                    completion.attempt_id,
                "", completion.capability);
            return response &&
                   (response->status == 204 || response->status == 404);
          });
        }
        nlohmann::json acknowledgements = nlohmann::json::array();
        std::unordered_set<std::string> acknowledged_ids;
        for (const auto& acknowledged : NatProbeAcknowledgedDiscoveryAttempts()) {
          auto found = polled_private_attempts.find(acknowledged.attempt_id);
          if (found == polled_private_attempts.end() ||
              !acknowledged_ids.insert(acknowledged.attempt_id).second)
            continue;
          const auto& attempt = found->second;
          acknowledgements.push_back({{"attempt_id", attempt.attempt_id},
                                      {"admission_generation", attempt.admission_generation},
                                      {"lease_revision", attempt.lease_revision}});
        }
        const auto poll_started_at = std::chrono::steady_clock::now();
        auto pending =
            Request(REXCVAR_GET(session_directory_url), L"POST",
                    "/sessions/" + session_id + "/join-attempts/poll",
                    nlohmann::json{{"acknowledged", std::move(acknowledgements)}}.dump(), token);
        auto snapshot = pending && pending->status == 200
                            ? ParseDirectoryHostPollSnapshot(pending->body, session_id)
                            : std::nullopt;
        const auto disposition = ClassifyDirectoryHostPollResponse(
            pending ? std::optional<uint32_t>(pending->status) : std::nullopt,
            snapshot.has_value());
        const auto attempts = snapshot
                                  ? std::span<const DirectoryTraversalAttempt>(*snapshot)
                                  : std::span<const DirectoryTraversalAttempt>{};
        auto transition = ApplyDirectoryHostPollResult(
            disposition, attempts, poll_state, admission_grants.get(), *hosted,
            poll_started_at);
        if (transition.recover_now) {
          REXSYS_WARN("Session directory: host poll returned 404; recovering logical lobby");
          next_registration = std::chrono::steady_clock::now();
          retry_delay = kHeartbeatRetryInitial;
        }
      }
      std::unique_lock lock(wait_mutex);
      wake.wait_for(lock, kTraversalPollInterval, [&] { return stop.stop_requested(); });
    }
    for (const auto& attempt : host_attempts)
      NatProbeRetireIdentity(attempt);
    if (admission_grants)
      admission_grants->InvalidateSession(session_id);
    if (!session_id.empty())
      Request(REXCVAR_GET(session_directory_url), L"DELETE", "/sessions/" + session_id, "", token);
    if (auto path = ActiveInviteCodePath())
      RemoveActiveInviteCodeFile(*path);
  }

  std::shared_ptr<SessionRecord> hosted;
  std::shared_ptr<HostAdmissionGrantStore> admission_grants;
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
                                          uint32_t title_id, uint16_t discovery_port,
                                          std::shared_ptr<HostAdmissionGrantStore> admission_grants) {
  impl_->StartHosting(session, title_id, discovery_port, std::move(admission_grants));
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
