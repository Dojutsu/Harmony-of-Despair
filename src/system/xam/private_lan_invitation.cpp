#include <rex/system/xam/private_lan_invitation.h>
#include <rex/platform.h>
#include <algorithm>
#include <cstring>
#include <limits>
#include <string>
#include <unordered_set>
#include "private_lan_crypto.h"
#if REX_PLATFORM_GNU_LINUX
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#elif REX_PLATFORM_WIN32
#include <windows.h>
#include <aclapi.h>
#include <sddl.h>
#endif

namespace rex::system::xam {
namespace {
namespace crypto = lan_crypto;
uint64_t Decode64(const uint8_t* bytes) {
  uint64_t result = 0;
  for (unsigned i = 0; i < 8; ++i) result = (result << 8) | bytes[i];
  return result;
}
void Append64(std::vector<uint8_t>& bytes, uint64_t value) {
  for (int shift = 56; shift >= 0; shift -= 8) bytes.push_back(uint8_t(value >> shift));
}
bool Nonzero(std::span<const uint8_t> bytes) {
  uint8_t result = 0;
  for (uint8_t byte : bytes) result |= byte;
  return result != 0;
}
struct SecretFileBytes {
  std::array<uint8_t, PrivateLanInvitation::kMaximumFileBytes + 1> bytes{};
  ~SecretFileBytes() { crypto::Cleanse(bytes.data(), bytes.size()); }
};
#if REX_PLATFORM_GNU_LINUX
struct Descriptor {
  int value = -1;
  ~Descriptor() { if (value >= 0) ::close(value); }
};
// Walk each component with openat and O_NOFOLLOW. A final-only check would
// still allow an invitation path through a substituted symlink directory.
bool ReadPrivateFile(std::string_view path, SecretFileBytes& output, size_t& size) {
  if (path.empty() || path.size() > 4096 || path.front() != '/' || path.back() == '/' ||
      path.find('\0') != std::string_view::npos) return false;
  Descriptor directory{::open("/", O_RDONLY | O_DIRECTORY | O_CLOEXEC)};
  if (directory.value < 0) return false;
  size_t position = 1;
  while (position < path.size()) {
    const auto separator = path.find('/', position);
    const auto end = separator == std::string_view::npos ? path.size() : separator;
    const auto component = path.substr(position, end - position);
    if (component.empty() || component == "." || component == ".." || component.size() > 255)
      return false;
    const std::string name(component);
    if (end < path.size()) {
      const int next = ::openat(directory.value, name.c_str(),
                                O_RDONLY | O_DIRECTORY | O_NOFOLLOW | O_CLOEXEC);
      if (next < 0) return false;
      ::close(directory.value); directory.value = next;
      position = end + 1;
      continue;
    }
    struct stat parent{};
    if (::fstat(directory.value, &parent) < 0 || parent.st_uid != geteuid() ||
        (parent.st_mode & 0777) != 0700) return false;
    Descriptor file{::openat(directory.value, name.c_str(),
                             O_RDONLY | O_NOFOLLOW | O_CLOEXEC | O_NONBLOCK)};
    struct stat before{}, after{};
    if (file.value < 0 || ::fstat(file.value, &before) < 0 || !S_ISREG(before.st_mode) ||
        before.st_uid != geteuid() || before.st_nlink != 1 || (before.st_mode & 077) != 0 ||
        !(before.st_mode & S_IRUSR) || (before.st_mode & (S_IXUSR | S_ISUID | S_ISGID | S_ISVTX)) ||
        before.st_size < 24 || before.st_size > off_t(PrivateLanInvitation::kMaximumFileBytes))
      return false;
    size = 0;
    while (size < output.bytes.size()) {
      const auto count = ::read(file.value, output.bytes.data() + size, output.bytes.size() - size);
      if (count < 0) { if (errno == EINTR) continue; return false; }
      if (!count) break;
      size += size_t(count);
    }
    if (::fstat(file.value, &after) < 0 || size != size_t(before.st_size) ||
        after.st_dev != before.st_dev || after.st_ino != before.st_ino ||
        after.st_size != before.st_size || after.st_mtim.tv_sec != before.st_mtim.tv_sec ||
        after.st_mtim.tv_nsec != before.st_mtim.tv_nsec ||
        after.st_ctim.tv_sec != before.st_ctim.tv_sec || after.st_ctim.tv_nsec != before.st_ctim.tv_nsec)
      return false;
    return true;
  }
  return false;
}
#elif REX_PLATFORM_WIN32
struct Handle {
  HANDLE value = INVALID_HANDLE_VALUE;
  ~Handle() { if (value != INVALID_HANDLE_VALUE) CloseHandle(value); }
  Handle() = default;
  Handle(Handle&& other) noexcept : value(other.value) { other.value = INVALID_HANDLE_VALUE; }
  Handle(const Handle&) = delete;
  Handle& operator=(const Handle&) = delete;
};
struct TokenSids {
  std::vector<uint8_t> user, owner;
  PSID User() { return reinterpret_cast<TOKEN_USER*>(user.data())->User.Sid; }
  PSID Owner() { return reinterpret_cast<TOKEN_OWNER*>(owner.data())->Owner; }
};
bool TokenInfo(HANDLE token, TOKEN_INFORMATION_CLASS type, std::vector<uint8_t>& output) {
  DWORD size = 0;
  GetTokenInformation(token, type, nullptr, 0, &size);
  if (!size || size > 4096) return false;
  output.resize(size);
  return GetTokenInformation(token, type, output.data(), size, &size) != 0;
}
bool CurrentSids(TokenSids& sids) {
  Handle token;
  return OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token.value) &&
         TokenInfo(token.value, TokenUser, sids.user) && TokenInfo(token.value, TokenOwner, sids.owner);
}
bool WellKnown(PSID sid, WELL_KNOWN_SID_TYPE type) {
  std::array<uint8_t, SECURITY_MAX_SID_SIZE> buffer{};
  DWORD size = DWORD(buffer.size());
  return CreateWellKnownSid(type, nullptr, buffer.data(), &size) && EqualSid(sid, buffer.data());
}
// Windows equivalent of an owner-only 0700/0600 entry: owned by this user (or
// the elevated default owner), and every allow ACE names only this user, the
// default owner, LocalSystem or the local Administrators group.
bool PrivateObject(HANDLE object, TokenSids& sids) {
  PSID owner = nullptr;
  PACL dacl = nullptr;
  PSECURITY_DESCRIPTOR descriptor = nullptr;
  if (GetSecurityInfo(object, SE_FILE_OBJECT, OWNER_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION,
                      &owner, nullptr, &dacl, nullptr, &descriptor) != ERROR_SUCCESS)
    return false;
  struct Free { PSECURITY_DESCRIPTOR value; ~Free() { LocalFree(value); } } free_descriptor{descriptor};
  if (!owner || !dacl || !(EqualSid(owner, sids.User()) || EqualSid(owner, sids.Owner()))) return false;
  ACL_SIZE_INFORMATION information{};
  if (!GetAclInformation(dacl, &information, sizeof(information), AclSizeInformation)) return false;
  for (DWORD i = 0; i < information.AceCount; ++i) {
    void* entry = nullptr;
    if (!GetAce(dacl, i, &entry)) return false;
    const auto* header = static_cast<ACE_HEADER*>(entry);
    if (header->AceType == ACCESS_DENIED_ACE_TYPE) continue;
    if (header->AceType != ACCESS_ALLOWED_ACE_TYPE) return false;
    if (header->AceFlags & INHERIT_ONLY_ACE) continue;
    auto* sid = reinterpret_cast<PSID>(&static_cast<ACCESS_ALLOWED_ACE*>(entry)->SidStart);
    if (!(EqualSid(sid, sids.User()) || EqualSid(sid, sids.Owner()) ||
          WellKnown(sid, WinLocalSystemSid) || WellKnown(sid, WinBuiltinAdministratorsSid)))
      return false;
  }
  return true;
}
// Hold every component open without delete sharing so no directory can be
// renamed or replaced by a reparse point while the invitation is read.
bool ReadPrivateFile(std::string_view path, SecretFileBytes& output, size_t& size) {
  if (path.size() < 4 || path.size() > 4096 || path.find('\0') != std::string_view::npos ||
      !((path[0] >= 'A' && path[0] <= 'Z') || (path[0] >= 'a' && path[0] <= 'z')) ||
      path[1] != ':' || (path[2] != '\\' && path[2] != '/') ||
      path.back() == '\\' || path.back() == '/' ||
      path.find(':', 2) != std::string_view::npos)
    return false;
  const int wide_size = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path.data(), int(path.size()), nullptr, 0);
  if (wide_size <= 0) return false;
  std::wstring wide(size_t(wide_size), L'\0');
  if (MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path.data(), int(path.size()), wide.data(), wide_size) != wide_size)
    return false;
  for (auto& character : wide) if (character == L'/') character = L'\\';
  TokenSids sids;
  if (!CurrentSids(sids)) return false;
  std::vector<Handle> held;
  size_t position = 3;
  while (position < wide.size()) {
    const auto separator = wide.find(L'\\', position);
    const auto end = separator == std::wstring::npos ? wide.size() : separator;
    const auto component = std::wstring_view(wide).substr(position, end - position);
    if (component.empty() || component == L"." || component == L".." || component.size() > 255) return false;
    const bool last = end == wide.size();
    Handle handle;
    handle.value = CreateFileW(wide.substr(0, end).c_str(), GENERIC_READ | READ_CONTROL,
                               last ? FILE_SHARE_READ : (FILE_SHARE_READ | FILE_SHARE_WRITE), nullptr,
                               OPEN_EXISTING,
                               FILE_FLAG_OPEN_REPARSE_POINT | (last ? 0 : FILE_FLAG_BACKUP_SEMANTICS), nullptr);
    BY_HANDLE_FILE_INFORMATION information{};
    if (handle.value == INVALID_HANDLE_VALUE || !GetFileInformationByHandle(handle.value, &information) ||
        (information.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT))
      return false;
    if (!last) {
      if (!(information.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) return false;
      held.push_back(std::move(handle));
      position = end + 1;
      continue;
    }
    const uint64_t bytes = (uint64_t(information.nFileSizeHigh) << 32) | information.nFileSizeLow;
    if (held.empty() || !PrivateObject(held.back().value, sids) || !PrivateObject(handle.value, sids) ||
        (information.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || information.nNumberOfLinks != 1 ||
        bytes < 24 || bytes > PrivateLanInvitation::kMaximumFileBytes)
      return false;
    size = 0;
    while (size < output.bytes.size()) {
      DWORD count = 0;
      if (!ReadFile(handle.value, output.bytes.data() + size, DWORD(output.bytes.size() - size), &count, nullptr))
        return false;
      if (!count) break;
      size += count;
    }
    BY_HANDLE_FILE_INFORMATION after{};
    return GetFileInformationByHandle(handle.value, &after) && size == bytes &&
        after.dwVolumeSerialNumber == information.dwVolumeSerialNumber &&
        after.nFileIndexHigh == information.nFileIndexHigh && after.nFileIndexLow == information.nFileIndexLow &&
        after.nFileSizeHigh == information.nFileSizeHigh && after.nFileSizeLow == information.nFileSizeLow &&
        after.ftLastWriteTime.dwLowDateTime == information.ftLastWriteTime.dwLowDateTime &&
        after.ftLastWriteTime.dwHighDateTime == information.ftLastWriteTime.dwHighDateTime &&
        after.nNumberOfLinks == 1;
  }
  return false;
}
#endif
}  // namespace

std::shared_ptr<const PrivateLanInvitation> PrivateLanInvitation::Load(
    std::string_view path, std::chrono::system_clock::time_point now) {
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32
  try {
    SecretFileBytes input;
    size_t size = 0;
    if (!ReadPrivateFile(path, input, size)) return {};
    const auto& bytes = input.bytes;
    const size_t count = bytes[6];
    if (std::memcmp(bytes.data(), "HPLI", 4) || bytes[4] != 1 || bytes[5] > 1 || bytes[7] ||
        !count || count > kMaximumGrants || (bytes[5] == 1 && count != 1) ||
        size != 24 + count * 56) return {};
    std::shared_ptr<PrivateLanInvitation> result(new PrivateLanInvitation);
    result->host_ = bytes[5] == 0;
    result->host_xuid_ = Decode64(bytes.data() + 8);
    result->expires_ = Decode64(bytes.data() + 16);
    const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
    if (seconds < 0 || !result->host_xuid_ || result->expires_ <= uint64_t(seconds) ||
        result->expires_ - uint64_t(seconds) > 7 * 24 * 60 * 60) return {};
    std::unordered_set<uint64_t> clients;
    std::unordered_set<std::string> selectors;
    for (size_t i = 0; i < count; ++i) {
      const auto* record = bytes.data() + 24 + i * 56;
      Grant grant;
      grant.client = Decode64(record);
      std::copy_n(record + 8, grant.selector.size(), grant.selector.begin());
      std::copy_n(record + 24, grant.secret.size(), grant.secret.begin());
      if (!grant.client || grant.client == result->host_xuid_ || !clients.insert(grant.client).second ||
          !Nonzero(grant.selector) || !Nonzero(grant.secret) ||
          std::any_of(result->grants_.begin(), result->grants_.end(), [&](const auto& old) {
            return crypto::Equal(old.secret.data(), grant.secret.data(), grant.secret.size());
          }) ||
          !selectors.emplace(reinterpret_cast<const char*>(grant.selector.data()), grant.selector.size()).second) {
        crypto::Cleanse(grant.secret.data(), grant.secret.size());
        return {};
      }
      result->grants_.push_back(grant);
      crypto::Cleanse(grant.secret.data(), grant.secret.size());
    }
    return result;
  } catch (...) { return {}; }
#else
  (void)path; (void)now;
  return {};
#endif
}

PrivateLanInvitation::Grant::~Grant() {
  crypto::Cleanse(secret.data(), secret.size());
}
PrivateLanInvitation::~PrivateLanInvitation() {
  for (auto& grant : grants_) crypto::Cleanse(grant.secret.data(), grant.secret.size());
}
std::vector<uint64_t> PrivateLanInvitation::clients() const {
  std::vector<uint64_t> result;
  for (const auto& grant : grants_) result.push_back(grant.client);
  return result;
}
bool PrivateLanInvitation::Current(std::chrono::system_clock::time_point now) const noexcept {
  const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
  return seconds >= 0 && uint64_t(seconds) < expires_;
}
std::optional<PrivateLanInvitation::Tag> PrivateLanInvitation::Proof(
    uint64_t client, std::string_view domain, std::span<const uint8_t> transcript) const {
  if (!crypto::Available() || !Current() || domain.empty() || domain.size() > 128 || domain.find('\0') != std::string_view::npos ||
      transcript.empty() || transcript.size() > kMaximumProofPayload) return std::nullopt;
  const auto grant = std::find_if(grants_.begin(), grants_.end(),
                                 [&](const auto& value) { return value.client == client; });
  if (grant == grants_.end()) return std::nullopt;
  try {
    constexpr std::string_view prefix = "ReXGlue private LAN invitation proof v1";
    std::vector<uint8_t> bytes(prefix.begin(), prefix.end());
    Append64(bytes, host_xuid_); Append64(bytes, client); Append64(bytes, expires_);
    bytes.insert(bytes.end(), grant->selector.begin(), grant->selector.end());
    bytes.push_back(uint8_t(domain.size() >> 8)); bytes.push_back(uint8_t(domain.size()));
    bytes.insert(bytes.end(), domain.begin(), domain.end());
    const auto size = uint32_t(transcript.size());
    for (int shift = 24; shift >= 0; shift -= 8) bytes.push_back(uint8_t(size >> shift));
    bytes.insert(bytes.end(), transcript.begin(), transcript.end());
    crypto::SensitiveArray<32> digest;
    if (!crypto::HmacSha256(grant->secret, {bytes}, digest.bytes)) return std::nullopt;
    Tag result{}; std::copy_n(digest.bytes.begin(), result.size(), result.begin());
    return result;
  } catch (...) { return std::nullopt; }
}
std::optional<PrivateLanInvitation::Tag> PrivateLanInvitation::Selector(uint64_t client) const {
  if(!Current())return std::nullopt;
  for(const auto& grant:grants_)if(grant.client==client)return grant.selector;
  return std::nullopt;
}
std::optional<uint64_t> PrivateLanInvitation::ClientForSelector(std::span<const uint8_t> selector) const {
  if(!Current()||selector.size()!=16)return std::nullopt;
  std::optional<uint64_t> result;
  for(const auto& grant:grants_)if(crypto::Equal(grant.selector.data(),selector.data(),16))result=grant.client;
  return result;
}
std::optional<std::array<uint8_t,32>> PrivateLanInvitation::DiscoveryKey(uint64_t client,bool reply) const {
  if(!crypto::Available()||!Current())return std::nullopt;
  const auto grant=std::find_if(grants_.begin(),grants_.end(),[&](const auto& value){return value.client==client;});
  if(grant==grants_.end())return std::nullopt;
  try {
    constexpr std::string_view domain="ReXGlue private LAN discovery encryption v1";
    std::vector<uint8_t> info(domain.begin(),domain.end());info.push_back(reply?1:0);
    Append64(info,host_xuid_);Append64(info,client);Append64(info,expires_);
    info.insert(info.end(),grant->selector.begin(),grant->selector.end());
    crypto::SensitiveArray<32> key;
    if(!crypto::HkdfSha256(grant->selector,grant->secret,{info},key.bytes)||!Nonzero(key.bytes))return std::nullopt;
    return key.bytes;
  }catch(...){return std::nullopt;}
}
bool PrivateLanInvitation::Verify(uint64_t client, std::string_view domain,
                                  std::span<const uint8_t> transcript,
                                  std::span<const uint8_t> tag) const {
  if (tag.size() != Tag{}.size()) return false;
  const auto expected = Proof(client, domain, transcript);
  return expected && crypto::Equal(expected->data(), tag.data(), tag.size());
}
}  // namespace rex::system::xam
