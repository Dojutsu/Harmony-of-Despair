#pragma once
#include <array>
#include <chrono>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <string_view>
#include <vector>

namespace rex::system::xam {
// A local private capability file, not a secret cvar value or discovery field.
// Host grants are distinct per expected client; each client owns one grant.
// Possession authorizes a local invitation identity, not Xbox Live ownership.
class PrivateLanInvitation final {
 public:
  using Tag = std::array<uint8_t, 16>;
  static constexpr size_t kMaximumGrants = 5;
  static constexpr size_t kMaximumFileBytes = 24 + kMaximumGrants * 56;
  static constexpr size_t kMaximumProofPayload = 4096;
  static std::shared_ptr<const PrivateLanInvitation> Load(
      std::string_view path, std::chrono::system_clock::time_point now =
                                 std::chrono::system_clock::now());
  ~PrivateLanInvitation();
  PrivateLanInvitation(const PrivateLanInvitation&) = delete;
  PrivateLanInvitation& operator=(const PrivateLanInvitation&) = delete;
  bool host() const noexcept { return host_; }
  uint64_t host_xuid() const noexcept { return host_xuid_; }
  std::vector<uint64_t> clients() const;
  bool Current(std::chrono::system_clock::time_point now =
                   std::chrono::system_clock::now()) const noexcept;
  std::optional<Tag> Proof(uint64_t client, std::string_view domain,
                           std::span<const uint8_t> transcript) const;
  // Opaque selector routes to one of at most five private per-client grants;
  // neither host nor client XUID is exposed by the private discovery header.
  std::optional<Tag> Selector(uint64_t client) const;
  std::optional<uint64_t> ClientForSelector(std::span<const uint8_t> selector) const;
  // HKDF-SHA256 from the private grant, with distinct request/reply domains and
  // explicit host/client/expiry/selector context. Caller cleanses the key.
  std::optional<std::array<uint8_t,32>> DiscoveryKey(uint64_t client,bool reply) const;
  bool Verify(uint64_t client, std::string_view domain,
              std::span<const uint8_t> transcript, std::span<const uint8_t> tag) const;
 private:
  struct Grant {
    ~Grant();
    uint64_t client = 0;
    std::array<uint8_t, 16> selector{};
    std::array<uint8_t, 32> secret{};
  };
  PrivateLanInvitation() = default;
  bool host_ = false;
  uint64_t host_xuid_ = 0;
  uint64_t expires_ = 0;
  std::vector<Grant> grants_;
};
}  // namespace rex::system::xam
