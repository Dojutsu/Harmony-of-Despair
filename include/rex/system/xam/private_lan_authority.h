#pragma once
#include <rex/system/xam/private_lan_invitation.h>
#include <rex/system/xam/gameplay_traversal.h>
#include <rex/system/xam/session_arbitration_crypto.h>
#include <type_traits>
#include <functional>
namespace rex::system::xam {
struct PrivateLanJoinClaim {
  uint64_t xuid = 0;
  uint64_t machine_id = 0;
  LanAddress endpoint;
  ArbitrationToken challenge{};
  ArbitrationToken request_id{};
  ArbitrationPublicKey client_public_key{};
};
// Exact semantic transcript for invitation bootstrap; the discovery adapter
// also authenticates every outer public packet byte before interpreting it.
std::vector<uint8_t> PrivateLanJoinTranscript(uint32_t title,
    const ArbitrationIdentity& identity, const PrivateLanJoinClaim& claim);
class PrivateLanAuthority final {
 public:
  using Clock = std::chrono::steady_clock;
  class Admission final {
   public:
    ~Admission();
    Admission(const Admission&) = delete;
    Admission& operator=(const Admission&) = delete;
    // Provisional secret tickets may be sealed/preflighted, but never sent or
    // installed before Commit succeeds. Destruction discards every staged key.
    std::optional<std::vector<uint8_t>> Ticket(uint64_t member,uint32_t lease_ms=30000) const;
    // No network or record locks are held by a prepared admission. Commit
    // publishes atomically only if no intervening authority mutation occurred.
    bool Commit() noexcept;
    const std::vector<uint64_t>& RemovedMembers() const noexcept;
    // Combine the final bounded, nonthrowing roster/arbitration commit with
    // authority publication. The callback runs after revision validation and
    // must not perform network operations or reenter this authority.
    template<class Commit> requires std::is_nothrow_invocable_r_v<bool,Commit>
    bool CommitIf(Commit&& publish) noexcept {
      struct Invocation {std::remove_reference_t<Commit>* callback;};
      Invocation invocation{std::addressof(publish)};
      return CommitIfRaw([](void* context) noexcept {
        return std::invoke(*static_cast<Invocation*>(context)->callback);
      },std::addressof(invocation));
    }
   private:
    friend class PrivateLanAuthority;
    struct Draft;
    explicit Admission(std::unique_ptr<Draft> draft);
    bool CommitIfRaw(bool (*publish)(void*) noexcept,void* context) noexcept;
    std::unique_ptr<Draft> draft_;
  };
  std::unique_ptr<Admission> Prepare(const PrivateLanJoinClaim& claim,
      std::span<const uint8_t> proof,Clock::time_point now=Clock::now());
  std::unique_ptr<Admission> PrepareDeparture(const PrivateLanJoinClaim& claim,
      std::span<const uint8_t> proof,Clock::time_point now=Clock::now());
  std::unique_ptr<Admission> PrepareExpiration(Clock::time_point now=Clock::now());
  static std::unique_ptr<PrivateLanAuthority> Create(uint32_t title,
      ArbitrationIdentity identity, LanAddress host_endpoint,
      std::shared_ptr<const PrivateLanInvitation> invitation);
  ~PrivateLanAuthority();
  PrivateLanAuthority(const PrivateLanAuthority&) = delete;
  PrivateLanAuthority& operator=(const PrivateLanAuthority&) = delete;
  // Verifies the per-client possession proof before creating immutable member
  // generations and fresh pair links. Exact initial retries retain their keys.
  // Private request IDs consist of a stable random 64-bit prefix and a strictly
  // increasing nonzero big-endian 64-bit sequence. Exact lost-reply retries
  // succeed without extending host liveness; earlier requests cannot renew it.
  bool Admit(const PrivateLanJoinClaim& claim, std::span<const uint8_t> proof,
             Clock::time_point now = Clock::now());
  // Atomically retire members without a fresh authenticated RPC for 60 seconds.
  std::vector<uint64_t> Expire(Clock::time_point now = Clock::now());
  bool Remove(uint64_t client);
  // Private encoded ticket, delivered only inside the authenticated ephemeral
  // envelope. Callers must cleanse this temporary buffer after sealing.
  std::optional<std::vector<uint8_t>> Ticket(uint64_t member, uint32_t lease_ms = 30000) const;
 private:
  std::unique_ptr<Admission> PrepareImpl(const PrivateLanJoinClaim&,
      std::span<const uint8_t>,Clock::time_point,bool departure);
  struct State;
  explicit PrivateLanAuthority(std::shared_ptr<State> state);
  std::shared_ptr<State> state_;
};
struct PrivateLanGameplayTicket {
  GameplayAuthorization authorization;
  std::vector<LanAddress> peer_endpoints;
};
// Strict exact-size parser; output is published only after all bounds, IDs,
// generations, keys, routes and full session fingerprint validate.
std::optional<PrivateLanGameplayTicket> ParsePrivateLanGameplayTicket(
    uint32_t title, const ArbitrationIdentity& expected, uint64_t local_xuid,
    std::span<const uint8_t> bytes, uint16_t guest_port = 3074);
}  // namespace rex::system::xam
