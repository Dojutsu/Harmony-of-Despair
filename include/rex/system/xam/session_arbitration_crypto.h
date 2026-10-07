#pragma once
#include <rex/system/xam/session_arbitration.h>
#include <array>
#include <memory>
#include <optional>
#include <span>

namespace rex::system::xam {
using ArbitrationPublicKey = std::array<uint8_t, 32>;
struct ArbitrationCredentialEnvelope {
  ArbitrationPublicKey server_public_key{};
  std::array<uint8_t, 12> iv{};
  ArbitrationToken ciphertext{};
  ArbitrationToken tag{};
};
// Session-local ephemeral secret, owned by the established crypto provider.
// Public bytes may enter the LAN packet; private bytes have no export API.
class EphemeralArbitrationKey final {
 public:
  EphemeralArbitrationKey() noexcept;
  ~EphemeralArbitrationKey();
  EphemeralArbitrationKey(EphemeralArbitrationKey&&) noexcept;
  EphemeralArbitrationKey& operator=(EphemeralArbitrationKey&&) noexcept;
  EphemeralArbitrationKey(const EphemeralArbitrationKey&) = delete;
  EphemeralArbitrationKey& operator=(const EphemeralArbitrationKey&) = delete;
  bool valid() const noexcept;
  const ArbitrationPublicKey& public_key() const noexcept;
 private:
  struct State;
  std::unique_ptr<State> state_;
  friend std::optional<EphemeralArbitrationKey> NewArbitrationKey();
  friend std::optional<ArbitrationCredentialEnvelope> SealArbitrationCredential(
      const ArbitrationPublicKey&, const ArbitrationToken&, std::span<const uint8_t>);
  friend std::optional<ArbitrationToken> OpenArbitrationCredential(
      const EphemeralArbitrationKey&, const ArbitrationCredentialEnvelope&, std::span<const uint8_t>);
};
inline constexpr size_t kMaximumArbitrationAAD = 4096;
std::optional<EphemeralArbitrationKey> NewArbitrationKey();
// Caller binds title/full session identity, member/machine, join challenge and
// client public key in AAD. These envelopes prevent passive credential exposure;
// they do not authenticate Xbox ownership or defend an unauthenticated initial
// exchange against an active on-path peer. Registrant trust remains zero.
std::optional<ArbitrationCredentialEnvelope> SealArbitrationCredential(
    const ArbitrationPublicKey& peer_public_key, const ArbitrationToken& credential,
    std::span<const uint8_t> aad);
std::optional<ArbitrationToken> OpenArbitrationCredential(
    const EphemeralArbitrationKey& client_key, const ArbitrationCredentialEnvelope& envelope,
    std::span<const uint8_t> aad);
} // namespace rex::system::xam
