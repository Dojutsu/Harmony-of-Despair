#include <rex/system/xam/private_lan_invitation.h>
#include <rex/platform.h>
#include <algorithm>
#include <cstring>
#include <limits>
#include <string>
#include <unordered_set>
#if REX_PLATFORM_GNU_LINUX
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <openssl/crypto.h>
#include <openssl/hmac.h>
#endif

namespace rex::system::xam {
namespace {
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
#if REX_PLATFORM_GNU_LINUX
struct Descriptor {
  int value = -1;
  ~Descriptor() { if (value >= 0) ::close(value); }
};
struct SecretFileBytes {
  std::array<uint8_t, PrivateLanInvitation::kMaximumFileBytes + 1> bytes{};
  ~SecretFileBytes() { OPENSSL_cleanse(bytes.data(), bytes.size()); }
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
#endif
}  // namespace

std::shared_ptr<const PrivateLanInvitation> PrivateLanInvitation::Load(
    std::string_view path, std::chrono::system_clock::time_point now) {
#if REX_PLATFORM_GNU_LINUX
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
            return CRYPTO_memcmp(old.secret.data(), grant.secret.data(), grant.secret.size()) == 0;
          }) ||
          !selectors.emplace(reinterpret_cast<const char*>(grant.selector.data()), grant.selector.size()).second) {
        OPENSSL_cleanse(grant.secret.data(), grant.secret.size());
        return {};
      }
      result->grants_.push_back(grant);
      OPENSSL_cleanse(grant.secret.data(), grant.secret.size());
    }
    return result;
  } catch (...) { return {}; }
#else
  (void)path; (void)now;
  return {};
#endif
}

PrivateLanInvitation::Grant::~Grant() {
#if REX_PLATFORM_GNU_LINUX
  OPENSSL_cleanse(secret.data(), secret.size());
#endif
}
PrivateLanInvitation::~PrivateLanInvitation() {
#if REX_PLATFORM_GNU_LINUX
  for (auto& grant : grants_) OPENSSL_cleanse(grant.secret.data(), grant.secret.size());
#endif
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
#if REX_PLATFORM_GNU_LINUX
  if (!Current() || domain.empty() || domain.size() > 128 || domain.find('\0') != std::string_view::npos ||
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
    std::array<uint8_t, EVP_MAX_MD_SIZE> digest{};
    unsigned length = 0;
    if (!HMAC(EVP_sha256(), grant->secret.data(), int(grant->secret.size()),
              bytes.data(), bytes.size(), digest.data(), &length) || length != 32) return std::nullopt;
    Tag result{}; std::copy_n(digest.begin(), result.size(), result.begin());
    OPENSSL_cleanse(digest.data(), digest.size());
    return result;
  } catch (...) { return std::nullopt; }
#else
  (void)client; (void)domain; (void)transcript;
  return std::nullopt;
#endif
}
bool PrivateLanInvitation::Verify(uint64_t client, std::string_view domain,
                                  std::span<const uint8_t> transcript,
                                  std::span<const uint8_t> tag) const {
  if (tag.size() != Tag{}.size()) return false;
  const auto expected = Proof(client, domain, transcript);
#if REX_PLATFORM_GNU_LINUX
  return expected && CRYPTO_memcmp(expected->data(), tag.data(), tag.size()) == 0;
#else
  return false;
#endif
}
}  // namespace rex::system::xam
