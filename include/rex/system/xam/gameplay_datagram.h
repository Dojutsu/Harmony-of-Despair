#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>

namespace rex::system::xam {
using GameplayTrafficKey = std::array<uint8_t, 32>;
using GameplayLinkId = std::array<uint8_t, 16>;
inline constexpr size_t kGameplayDatagramHeaderBytes = 32;
inline constexpr size_t kGameplayDatagramTagBytes = 16;
inline constexpr size_t kGameplayMaximumWireBytes = 65507; // IPv4 UDP payload.
inline constexpr size_t kGameplayMaximumPlaintextBytes =
    kGameplayMaximumWireBytes - kGameplayDatagramHeaderBytes - kGameplayDatagramTagBytes;

// One noncopyable state per admitted link/socket incarnation. Keep it across
// ticket renewals; destroying/recreating it with the same key would reuse nonces.
// The authenticated admission channel supplies a new random key for each link.
// No plaintext leaves Open before authentication. Peek verifies without marking
// replay state; the socket receive lock must serialize peek and queue consumption.
class GameplayDatagramCipher final {
 public:
  static std::unique_ptr<GameplayDatagramCipher> Create(
      const GameplayTrafficKey& key, const GameplayLinkId& link, uint8_t participant);
  ~GameplayDatagramCipher();
  GameplayDatagramCipher(const GameplayDatagramCipher&) = delete;
  GameplayDatagramCipher& operator=(const GameplayDatagramCipher&) = delete;
  GameplayDatagramCipher(GameplayDatagramCipher&&) = delete;
  GameplayDatagramCipher& operator=(GameplayDatagramCipher&&) = delete;
  std::optional<std::vector<uint8_t>> Seal(std::span<const uint8_t> plaintext);
  bool Open(std::span<const uint8_t> packet, std::vector<uint8_t>& plaintext,
            bool consume = true);
 private:
  GameplayDatagramCipher();
  struct State;
  std::unique_ptr<State> state_;
};
} // namespace rex::system::xam
