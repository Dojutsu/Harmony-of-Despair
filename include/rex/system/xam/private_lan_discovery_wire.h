#pragma once
#include <rex/system/xam/private_lan_payload.h>
namespace rex::system::xam {
inline constexpr size_t kPrivateLanDiscoveryPublicBytes=640;
inline constexpr size_t kPrivateLanDiscoveryHeaderBytes=40;
inline constexpr size_t kPrivateLanDiscoveryMaximumPayload=708;
inline constexpr size_t kPrivateLanDiscoveryWireBytes=1440;
using PrivateLanDiscoveryPublic=std::array<uint8_t,kPrivateLanDiscoveryPublicBytes>;
using PrivateLanDiscoveryWire=std::array<uint8_t,kPrivateLanDiscoveryWireBytes>;
enum class PrivateLanDiscoveryDirection {kRequest,kReply};
struct PrivateLanDiscoveryFrame {
  PrivateLanDiscoveryPublic public_packet{};
  PrivateLanInvitation::Tag join_claim_proof{};
  std::optional<PrivateLanPayloadEnvelope> payload;
};
// The original 640-byte session layout is inside a fixed encrypted body.
// The opaque header exposes only protocol version/direction, a random grant
// selector, nonce and fixed length. Every header/body byte is authenticated
// before the caller may decode or use any metadata or private ticket field.
std::optional<PrivateLanDiscoveryWire> SealPrivateLanDiscoveryFrame(
    const PrivateLanInvitation& invitation,uint64_t client,uint32_t title,
    PrivateLanDiscoveryDirection direction,const PrivateLanDiscoveryFrame& frame);
// Host requests may pass client=0 to resolve the opaque grant selector.
// A reply requires the exact outstanding fresh RPC ID. Request freshness and
// semantic claim proof are checked by the authority before membership effects.
std::optional<PrivateLanDiscoveryFrame> OpenPrivateLanDiscoveryFrame(
    const PrivateLanInvitation& invitation,uint64_t client,uint32_t title,
    PrivateLanDiscoveryDirection direction,std::span<const uint8_t> wire,
    std::optional<ArbitrationToken> outstanding_request=std::nullopt);
} // namespace rex::system::xam
