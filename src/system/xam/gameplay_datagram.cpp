#include <rex/system/xam/gameplay_datagram.h>
#include <rex/platform.h>
#include <algorithm>
#include <cstring>
#include <limits>
#include <mutex>
#if REX_PLATFORM_LINUX
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#endif

namespace rex::system::xam {
namespace {
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
#if REX_PLATFORM_LINUX
template<class T, void (*Free)(T*)> using CryptoOwner = std::unique_ptr<T, decltype(Free)>;
using KeyContext = CryptoOwner<EVP_PKEY_CTX, EVP_PKEY_CTX_free>;
using CipherContext = CryptoOwner<EVP_CIPHER_CTX, EVP_CIPHER_CTX_free>;
bool DeriveDirection(const GameplayTrafficKey& key, const GameplayLinkId& link,
                     uint8_t direction, GameplayTrafficKey& derived) {
  static constexpr char domain[] = "ReXGlue admitted gameplay datagram v1";
  KeyContext context(EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr), EVP_PKEY_CTX_free);
  size_t length = derived.size();
  return context && EVP_PKEY_derive_init(context.get()) == 1 &&
      EVP_PKEY_CTX_set_hkdf_md(context.get(), EVP_sha256()) == 1 &&
      EVP_PKEY_CTX_set1_hkdf_salt(context.get(), link.data(), int(link.size())) == 1 &&
      EVP_PKEY_CTX_set1_hkdf_key(context.get(), key.data(), int(key.size())) == 1 &&
      EVP_PKEY_CTX_add1_hkdf_info(context.get(),
          reinterpret_cast<const uint8_t*>(domain), int(sizeof(domain) - 1)) == 1 &&
      EVP_PKEY_CTX_add1_hkdf_info(context.get(), &direction, 1) == 1 &&
      EVP_PKEY_derive(context.get(), derived.data(), &length) == 1 && length == derived.size();
}
struct SensitiveVector {
  std::vector<uint8_t> bytes;
  explicit SensitiveVector(size_t size) : bytes(size) {}
  ~SensitiveVector() { if (!bytes.empty()) OPENSSL_cleanse(bytes.data(), bytes.size()); }
};
#endif
} // namespace

struct GameplayDatagramCipher::State {
  GameplayLinkId link{};
  GameplayTrafficKey send_key{}, receive_key{};
  uint8_t participant = 0;
  uint64_t next_sequence = 0;
  ReplayWindow replay;
  std::mutex mutex;
  ~State() {
#if REX_PLATFORM_LINUX
    OPENSSL_cleanse(send_key.data(), send_key.size());
    OPENSSL_cleanse(receive_key.data(), receive_key.size());
#endif
  }
};
GameplayDatagramCipher::GameplayDatagramCipher() = default;
GameplayDatagramCipher::~GameplayDatagramCipher() = default;
std::unique_ptr<GameplayDatagramCipher> GameplayDatagramCipher::Create(
    const GameplayTrafficKey& key, const GameplayLinkId& link, uint8_t participant) {
#if REX_PLATFORM_LINUX
  if (!Nonzero(key) || !Nonzero(link) || participant > 1) return nullptr;
  auto result = std::unique_ptr<GameplayDatagramCipher>(new GameplayDatagramCipher);
  result->state_ = std::make_unique<State>();
  auto& state = *result->state_;
  state.link = link;
  state.participant = participant;
  if (!DeriveDirection(key, link, participant, state.send_key) ||
      !DeriveDirection(key, link, participant ^ 1, state.receive_key)) return nullptr;
  return result;
#else
  (void)key; (void)link; (void)participant;
  return nullptr;
#endif
}
std::optional<std::vector<uint8_t>> GameplayDatagramCipher::Seal(
    std::span<const uint8_t> plaintext) {
#if REX_PLATFORM_LINUX
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
  CipherContext cipher(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free);
  int written = 0, final_size = 0;
  std::array<uint8_t, 16> final{};
  if (!cipher || EVP_EncryptInit_ex(cipher.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1 ||
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_IVLEN, int(nonce.size()), nullptr) != 1 ||
      EVP_EncryptInit_ex(cipher.get(), nullptr, nullptr, state.send_key.data(), nonce.data()) != 1 ||
      EVP_EncryptUpdate(cipher.get(), nullptr, &written, wire.data(), kGameplayDatagramHeaderBytes) != 1 ||
      EVP_EncryptUpdate(cipher.get(), wire.data() + kGameplayDatagramHeaderBytes, &written,
          plaintext.data(), int(plaintext.size())) != 1 || written != int(plaintext.size()) ||
      EVP_EncryptFinal_ex(cipher.get(), final.data(), &final_size) != 1 || final_size != 0 ||
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_GET_TAG, kGameplayDatagramTagBytes,
          wire.data() + kGameplayDatagramHeaderBytes + plaintext.size()) != 1) return std::nullopt;
  return wire;
#else
  (void)plaintext;
  return std::nullopt;
#endif
}
bool GameplayDatagramCipher::Open(std::span<const uint8_t> wire,
                                  std::vector<uint8_t>& plaintext, bool consume) {
#if REX_PLATFORM_LINUX
  if (!state_ || wire.size() < kGameplayDatagramHeaderBytes + kGameplayDatagramTagBytes ||
      wire.size() > kGameplayMaximumWireBytes) return false;
  auto& state = *state_;
  std::lock_guard lock(state.mutex);
  if (std::memcmp(wire.data(), "HGDP", 4) || wire[4] != 1 || wire[5] != (state.participant ^ 1) ||
      wire[6] != 0 || wire[7] != kGameplayDatagramHeaderBytes ||
      CRYPTO_memcmp(wire.data() + 8, state.link.data(), state.link.size())) return false;
  uint64_t sequence = 0;
  for (unsigned i = 0; i < 8; ++i) sequence = (sequence << 8) | wire[24 + i];
  if (!state.replay.Admits(sequence)) return false;
  const size_t length = wire.size() - kGameplayDatagramHeaderBytes - kGameplayDatagramTagBytes;
  SensitiveVector staged(length + 16);
  std::array<uint8_t, 12> nonce{};
  std::memcpy(nonce.data() + 4, wire.data() + 24, 8);
  std::array<uint8_t, 16> tag{};
  std::memcpy(tag.data(), wire.data() + kGameplayDatagramHeaderBytes + length, tag.size());
  CipherContext cipher(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free);
  int written = 0, final_size = 0;
  if (!cipher || EVP_DecryptInit_ex(cipher.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1 ||
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_IVLEN, int(nonce.size()), nullptr) != 1 ||
      EVP_DecryptInit_ex(cipher.get(), nullptr, nullptr, state.receive_key.data(), nonce.data()) != 1 ||
      EVP_DecryptUpdate(cipher.get(), nullptr, &written, wire.data(), kGameplayDatagramHeaderBytes) != 1 ||
      EVP_DecryptUpdate(cipher.get(), staged.bytes.data(), &written,
          wire.data() + kGameplayDatagramHeaderBytes, int(length)) != 1 || written != int(length) ||
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_TAG, int(tag.size()), tag.data()) != 1 ||
      EVP_DecryptFinal_ex(cipher.get(), staged.bytes.data() + written, &final_size) != 1 ||
      final_size != 0) return false;
  // Allocate/copy only after tag verification, then commit anti-replay state.
  std::vector<uint8_t> verified(staged.bytes.begin(), staged.bytes.begin() + length);
  if (consume) state.replay.Mark(sequence);
  plaintext = std::move(verified);
  return true;
#else
  (void)wire; (void)plaintext; (void)consume;
  return false;
#endif
}
} // namespace rex::system::xam
