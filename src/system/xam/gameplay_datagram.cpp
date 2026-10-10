#include <rex/system/xam/gameplay_datagram.h>
#include <rex/platform.h>
#include "private_lan_crypto.h"
#include <algorithm>
#include <cstring>
#include <limits>
#include <mutex>

namespace rex::system::xam {
namespace {
namespace crypto = lan_crypto;
template<class T> bool Nonzero(const T& value) {
  uint8_t result = 0;
  for (uint8_t byte : value) result |= byte;
  return result != 0;
}
struct ReplayWindow {
  uint64_t highest = 0;
  std::array<uint64_t, 4> seen{};
  bool Admits(uint64_t sequence) const {
    if (!sequence) return false;
    if (sequence > highest) return true;
    const auto age = highest - sequence;
    return age < 256 && !(seen[age / 64] & (uint64_t(1) << (age % 64)));
  }
  void Mark(uint64_t sequence) {
    if (sequence > highest) {
      const uint64_t distance = sequence - highest;
      std::array<uint64_t, 4> shifted{};
      if (distance < 256) {
        const auto words = size_t(distance / 64);
        const auto bits = unsigned(distance % 64);
        for (size_t i = words; i < shifted.size(); ++i) {
          shifted[i] = seen[i - words] << bits;
          if (bits && i > words) shifted[i] |= seen[i - words - 1] >> (64 - bits);
        }
      }
      seen = shifted;
      highest = sequence;
    }
    const auto age = highest - sequence;
    seen[age / 64] |= uint64_t(1) << (age % 64);
  }
};
bool DeriveDirection(const GameplayTrafficKey& key, const GameplayLinkId& link,
                     uint8_t direction, GameplayTrafficKey& derived) {
  static constexpr char domain[] = "ReXGlue admitted gameplay datagram v1";
  return crypto::HkdfSha256(link, key,
      {{reinterpret_cast<const uint8_t*>(domain), sizeof(domain) - 1}, {&direction, 1}}, derived);
}
struct SensitiveVector {
  std::vector<uint8_t> bytes;
  explicit SensitiveVector(size_t size) : bytes(size) {}
  ~SensitiveVector() { crypto::Cleanse(bytes.data(), bytes.size()); }
};
} // namespace

struct GameplayDatagramCipher::State {
  GameplayLinkId link{};
  GameplayTrafficKey send_key{}, receive_key{};
  uint8_t participant = 0;
  uint64_t next_sequence = 0;
  ReplayWindow replay;
  std::mutex mutex;
  ~State() {
    crypto::Cleanse(send_key.data(), send_key.size());
    crypto::Cleanse(receive_key.data(), receive_key.size());
  }
};
GameplayDatagramCipher::GameplayDatagramCipher() = default;
GameplayDatagramCipher::~GameplayDatagramCipher() = default;
std::unique_ptr<GameplayDatagramCipher> GameplayDatagramCipher::Create(
    const GameplayTrafficKey& key, const GameplayLinkId& link, uint8_t participant) {
  if (!crypto::Available() || !Nonzero(key) || !Nonzero(link) || participant > 1) return nullptr;
  auto result = std::unique_ptr<GameplayDatagramCipher>(new GameplayDatagramCipher);
  result->state_ = std::make_unique<State>();
  auto& state = *result->state_;
  state.link = link;
  state.participant = participant;
  if (!DeriveDirection(key, link, participant, state.send_key) ||
      !DeriveDirection(key, link, participant ^ 1, state.receive_key)) return nullptr;
  return result;
}
std::optional<std::vector<uint8_t>> GameplayDatagramCipher::Seal(
    std::span<const uint8_t> plaintext) {
  if (plaintext.size() > kGameplayMaximumPlaintextBytes || !state_) return std::nullopt;
  auto& state = *state_;
  std::lock_guard lock(state.mutex);
  if (state.next_sequence == std::numeric_limits<uint64_t>::max()) return std::nullopt;
  // Burn the nonce even when a provider call fails. Never wrap or reuse it.
  const uint64_t sequence = ++state.next_sequence;
  std::vector<uint8_t> wire(kGameplayDatagramHeaderBytes + plaintext.size() + kGameplayDatagramTagBytes);
  std::memcpy(wire.data(), "HGDP", 4);
  wire[4] = 1; wire[5] = state.participant; wire[6] = 0; wire[7] = kGameplayDatagramHeaderBytes;
  std::memcpy(wire.data() + 8, state.link.data(), state.link.size());
  for (unsigned i = 0; i < 8; ++i) wire[24 + i] = uint8_t(sequence >> (56 - 8 * i));
  std::array<uint8_t, 12> nonce{};
  std::memcpy(nonce.data() + 4, wire.data() + 24, 8);
  std::array<uint8_t, 16> tag{};
  if (!crypto::AesGcmSeal(state.send_key, nonce,
          std::span<const uint8_t>(wire.data(), kGameplayDatagramHeaderBytes), plaintext,
          wire.data() + kGameplayDatagramHeaderBytes, tag)) return std::nullopt;
  std::copy(tag.begin(), tag.end(), wire.begin() + kGameplayDatagramHeaderBytes + plaintext.size());
  return wire;
}
bool GameplayDatagramCipher::Open(std::span<const uint8_t> wire,
                                  std::vector<uint8_t>& plaintext, bool consume) {
  if (!state_ || wire.size() < kGameplayDatagramHeaderBytes + kGameplayDatagramTagBytes ||
      wire.size() > kGameplayMaximumWireBytes) return false;
  auto& state = *state_;
  std::lock_guard lock(state.mutex);
  if (std::memcmp(wire.data(), "HGDP", 4) || wire[4] != 1 || wire[5] != (state.participant ^ 1) ||
      wire[6] != 0 || wire[7] != kGameplayDatagramHeaderBytes ||
      !crypto::Equal(wire.data() + 8, state.link.data(), state.link.size())) return false;
  uint64_t sequence = 0;
  for (unsigned i = 0; i < 8; ++i) sequence = (sequence << 8) | wire[24 + i];
  if (!state.replay.Admits(sequence)) return false;
  const size_t length = wire.size() - kGameplayDatagramHeaderBytes - kGameplayDatagramTagBytes;
  SensitiveVector staged(length + 16);
  std::array<uint8_t, 12> nonce{};
  std::memcpy(nonce.data() + 4, wire.data() + 24, 8);
  std::array<uint8_t, 16> tag{};
  std::memcpy(tag.data(), wire.data() + kGameplayDatagramHeaderBytes + length, tag.size());
  if (!crypto::AesGcmOpen(state.receive_key, nonce, wire.first(kGameplayDatagramHeaderBytes),
          wire.subspan(kGameplayDatagramHeaderBytes, length), tag, staged.bytes.data())) return false;
  // Allocate/copy only after tag verification, then commit anti-replay state.
  std::vector<uint8_t> verified(staged.bytes.begin(), staged.bytes.begin() + length);
  if (consume) state.replay.Mark(sequence);
  plaintext = std::move(verified);
  return true;
}
} // namespace rex::system::xam
