#pragma once
// TU2's XGI packet carries capacity by value, not a writable size pointer.
#include <rex/system/xam/session_arbitration.h>
#include <array>
#include <cstdint>
#include <optional>
#include <span>
#include <vector>
namespace rex::memory { class Memory; }
namespace rex::system::xam {
inline constexpr uint32_t kArbitrationGuestHeaderSize = 8;
inline constexpr uint32_t kArbitrationGuestRegistrantSize = 24;
// Current direct-session authority supports eight machines and one profile per
// machine. Preflight this bound before any accepted registration request.
inline constexpr uint32_t kArbitrationGuestPreflightSize =
    kArbitrationGuestHeaderSize +
    uint32_t(SessionArbitrationAuthority::kMaxMembers) * (kArbitrationGuestRegistrantSize + 8);
static_assert(kArbitrationGuestPreflightSize == 264);
struct GuestArbitrationRequest {
  uint32_t session_object = 0;
  uint32_t flags = 0;
  uint64_t nonce = 0;
  uint32_t duration_seconds = 0;
  uint32_t result_capacity = 0;
  uint32_t result_address = 0;
};
// Ordinary committed guest RAM only; each copy holds the Linux mapping lease.
// The caller owns Memory or holds its access pin for these synchronous calls.
bool CopyArbitrationGuestInput(memory::Memory* memory, uint32_t address,
                               std::span<uint8_t> output);
bool CopyArbitrationGuestOutput(memory::Memory* memory, uint32_t address,
                                std::span<const uint8_t> input);
std::optional<GuestArbitrationRequest> ReadArbitrationGuestRequest(
    memory::Memory* memory, uint32_t address, uint32_t length);
bool PreflightArbitrationGuestOutput(memory::Memory* memory, uint32_t address,
                                     uint32_t capacity);
// Stages a private, complete BE result. Empty or malformed authority output
// fails explicitly; this serializer does not invent registrants or identities.
std::optional<std::vector<uint8_t>> SerializeArbitrationGuestResults(
    const ArbitrationSnapshot& snapshot, uint32_t guest_address);
} // namespace rex::system::xam
