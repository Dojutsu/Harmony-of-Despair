#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <ranges>
#include <span>

#include <catch2/catch_test_macros.hpp>

#include <rex/system/xsocket.h>
#include <rex/system/xam/nat_probe.h>

#if REX_PLATFORM_WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

namespace rex::kernel::xam {
struct XNADDR;
u32 NetDll_XNetXnAddrToInAddr_entry(u32 caller, ppc_ptr_t<XNADDR> xn_addr, mapped_void xid,
                                    mapped_void in_addr);
u32 NetDll_XNetInAddrToXnAddr_entry(u32 caller, u32 address, ppc_ptr_t<XNADDR> xn_addr,
                                    mapped_void xid);
u32 NetDll_XNetUnregisterInAddr_entry(u32 caller, u32 address);
u32 NetDll_XNetConnect_entry(u32 caller, u32 address);
u32 NetDll_XNetGetConnectStatus_entry(u32 caller, u32 address);
}  // namespace rex::kernel::xam

namespace rex::system {
namespace {

constexpr std::array<uint8_t, 16> kAttempt{
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
constexpr std::array<uint8_t, 16> kCapability{
    0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88,
    0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};

std::array<uint8_t, 56> RegisteredPacket(uint32_t observed_ipv4, uint16_t observed_port,
                                         uint32_t peer_ipv4, uint16_t peer_port) {
  std::array<uint8_t, 56> packet{};
  std::memcpy(packet.data(), "HNAT", 4);
  packet[4] = 1;
  packet[5] = 2;
  packet[6] = 0;
  packet[7] = 1;
  std::memcpy(packet.data() + 8, kAttempt.data(), kAttempt.size());
  std::memcpy(packet.data() + 24, kCapability.data(), kCapability.size());
  std::memcpy(packet.data() + 40, &observed_ipv4, sizeof(observed_ipv4));
  const uint16_t observed_network_port = htons(observed_port);
  std::memcpy(packet.data() + 44, &observed_network_port, sizeof(observed_network_port));
  std::memcpy(packet.data() + 46, &peer_ipv4, sizeof(peer_ipv4));
  const uint16_t peer_network_port = htons(peer_port);
  std::memcpy(packet.data() + 50, &peer_network_port, sizeof(peer_network_port));
  return packet;
}

std::string Hex(const std::array<uint8_t, 16>& bytes) {
  constexpr char digits[] = "0123456789abcdef";
  std::string result;
  result.reserve(32);
  for (uint8_t value : bytes) {
    result.push_back(digits[value >> 4]);
    result.push_back(digits[value & 15]);
  }
  return result;
}

void CloseNativeSocket(uintptr_t socket) {
#if REX_PLATFORM_WIN32
  closesocket(static_cast<SOCKET>(socket));
#else
  close(static_cast<int>(socket));
#endif
}

std::array<uint8_t, 36> XnAddr(uint32_t guest_ipv4, uint16_t port,
                               uint64_t online_id) {
  std::array<uint8_t, 36> address{};
  const uint32_t network_ipv4 = htonl(guest_ipv4);
  std::memcpy(address.data(), &network_ipv4, sizeof(network_ipv4));
  std::memcpy(address.data() + 4, &network_ipv4, sizeof(network_ipv4));
  const uint16_t network_port = htons(port);
  std::memcpy(address.data() + 8, &network_port, sizeof(network_port));
  std::memcpy(address.data() + 16, &online_id, sizeof(online_id));
  return address;
}

bool Selector7DescriptorIdentityIsValid(const std::array<uint8_t, 38>& descriptor) {
  const bool all_zero = std::all_of(descriptor.begin() + 10, descriptor.begin() + 16,
                                    [](uint8_t value) { return value == 0; });
  const bool all_ff = std::all_of(descriptor.begin() + 10, descriptor.begin() + 16,
                                  [](uint8_t value) { return value == 0xFF; });
  return !all_zero && !all_ff;
}

struct Selector7IntroductionResult {
  bool identifier_resolved;
  bool descriptor_accepted;
  bool handler_succeeded;
  bool common_rejection;
};

Selector7IntroductionResult ModelSelector7Introduction(
    uint32_t identifier, std::span<const uint32_t> known_identifiers,
    const std::array<uint8_t, 38>& descriptor) {
  const bool identifier_resolved =
      std::ranges::find(known_identifiers, identifier) != known_identifiers.end();
  const bool descriptor_accepted = Selector7DescriptorIdentityIsValid(descriptor);
  const bool handler_succeeded = identifier_resolved && descriptor_accepted;
  return {identifier_resolved, descriptor_accepted, handler_succeeded, !handler_succeeded};
}

}  // namespace

TEST_CASE("XNet address handles preserve distinct peer mappings and network byte order",
          "[network][xnet]") {
  using namespace rex::kernel::xam;
  constexpr uint32_t kHost = 0x0A0000D5u;
  constexpr uint32_t kGuestA = 0x0A00001Cu;
  constexpr uint32_t kUnknown = 0x0A00009Fu;
  auto host = XnAddr(kHost, 30742, 0xE812BE180C2286BDu);
  auto guest_a = XnAddr(kGuestA, 30742, 0x59260F9AAF14B646u);
  std::array<uint8_t, 4> host_handle_bytes{};
  std::array<uint8_t, 4> guest_a_handle_bytes{};

  REQUIRE(NetDll_XNetXnAddrToInAddr_entry(
              1, ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(host.data())), nullptr,
              mapped_void::from_host(host_handle_bytes.data())) == 0);
  REQUIRE(NetDll_XNetXnAddrToInAddr_entry(
              1, ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(guest_a.data())), nullptr,
              mapped_void::from_host(guest_a_handle_bytes.data())) == 0);

  CHECK(host_handle_bytes == std::array<uint8_t, 4>{0x0A, 0x00, 0x00, 0xD5});
  CHECK(guest_a_handle_bytes == std::array<uint8_t, 4>{0x0A, 0x00, 0x00, 0x1C});
  CHECK(NetDll_XNetConnect_entry(1, kHost) == 0);
  CHECK(NetDll_XNetGetConnectStatus_entry(1, kHost) == 2);
  CHECK(NetDll_XNetConnect_entry(1, kGuestA) == 0);
  CHECK(NetDll_XNetGetConnectStatus_entry(1, kGuestA) == 2);

  std::array<uint8_t, 36> host_round_trip{};
  std::array<uint8_t, 36> guest_a_round_trip{};
  REQUIRE(NetDll_XNetInAddrToXnAddr_entry(
              1, kHost,
              ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(host_round_trip.data())),
              nullptr) == 0);
  REQUIRE(NetDll_XNetInAddrToXnAddr_entry(
              1, kGuestA,
              ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(guest_a_round_trip.data())),
              nullptr) == 0);
  CHECK(host_round_trip == host);
  CHECK(guest_a_round_trip == guest_a);
  CHECK(NetDll_XNetGetConnectStatus_entry(1, kHost) == 2);

  std::array<uint8_t, 36> unknown{};
  REQUIRE(NetDll_XNetInAddrToXnAddr_entry(
              1, kUnknown,
              ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(unknown.data())), nullptr) ==
          0);
  CHECK(std::equal(unknown.begin(), unknown.begin() + 4,
                   std::array<uint8_t, 4>{0x0A, 0x00, 0x00, 0x9F}.begin()));
  CHECK(std::equal(unknown.begin() + 4, unknown.begin() + 8,
                   std::array<uint8_t, 4>{0x0A, 0x00, 0x00, 0x9F}.begin()));

  constexpr uint32_t kUnknownB = 0x0A0000A0u;
  std::array<uint8_t, 36> unknown_again{};
  std::array<uint8_t, 36> unknown_b{};
  REQUIRE(NetDll_XNetInAddrToXnAddr_entry(
              1, kUnknown,
              ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(unknown_again.data())),
              nullptr) == 0);
  REQUIRE(NetDll_XNetInAddrToXnAddr_entry(
              1, kUnknownB,
              ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(unknown_b.data())), nullptr) ==
          0);
  const auto unknown_enet = std::span(unknown).subspan(10, 6);
  const auto unknown_again_enet = std::span(unknown_again).subspan(10, 6);
  const auto unknown_b_enet = std::span(unknown_b).subspan(10, 6);
  CHECK(std::ranges::any_of(unknown_enet, [](uint8_t value) { return value != 0; }));
  CHECK(std::ranges::any_of(unknown_enet, [](uint8_t value) { return value != 0xFF; }));
  CHECK(std::ranges::equal(unknown_enet, unknown_again_enet));
  CHECK_FALSE(std::ranges::equal(unknown_enet, unknown_b_enet));
  CHECK(unknown[10] == 0x02);
  CHECK((unknown[10] & 0x01) == 0);
  CHECK((unknown[10] & 0x02) != 0);

  std::array<uint8_t, 38> selector7_descriptor{};
  std::copy(unknown.begin(), unknown.end(), selector7_descriptor.begin());
  selector7_descriptor[36] = 0x03;
  selector7_descriptor[37] = 0xE8;
  CHECK(Selector7DescriptorIdentityIsValid(selector7_descriptor));
  const std::array<uint32_t, 2> established_identifiers{kHost, kUnknown};
  const auto selector7_result =
      ModelSelector7Introduction(kUnknown, established_identifiers, selector7_descriptor);
  CHECK(selector7_result.identifier_resolved);
  CHECK(selector7_result.descriptor_accepted);
  CHECK(selector7_result.handler_succeeded);
  CHECK_FALSE(selector7_result.common_rejection);

  std::array<uint8_t, 36> zero_address{};
  std::array<uint8_t, 36> maximum_address{};
  REQUIRE(NetDll_XNetInAddrToXnAddr_entry(
              1, 0,
              ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(zero_address.data())),
              nullptr) == 0);
  REQUIRE(NetDll_XNetInAddrToXnAddr_entry(
              1, UINT32_MAX,
              ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(maximum_address.data())),
              nullptr) == 0);
  CHECK(std::ranges::any_of(std::span(zero_address).subspan(10, 6),
                            [](uint8_t value) { return value != 0; }));
  CHECK_FALSE(std::ranges::equal(std::span(zero_address).subspan(10, 6),
                                std::span(maximum_address).subspan(10, 6)));

  // A registered descriptor remains byte-for-byte authoritative.
  CHECK(host_round_trip == host);
  CHECK(guest_a_round_trip == guest_a);

  CHECK(NetDll_XNetUnregisterInAddr_entry(1, kHost) == 0);
  CHECK(NetDll_XNetUnregisterInAddr_entry(1, kGuestA) == 0);
  CHECK(NetDll_XNetGetConnectStatus_entry(1, kHost) == 0);
  CHECK(NetDll_XNetGetConnectStatus_entry(1, kGuestA) == 0);
}

TEST_CASE("gameplay NAT control drain preserves queued guest datagrams",
          "[network][socket][nat]") {
#if REX_PLATFORM_WIN32
  WSADATA data{};
  REQUIRE(WSAStartup(MAKEWORD(2, 2), &data) == 0);
#endif
  XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                              XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);
  N_XSOCKADDR_IN bind_address{};
  bind_address.sin_family = AF_INET;
  bind_address.sin_port = 0;
  bind_address.sin_addr = INADDR_ANY;
  REQUIRE(receiver.Bind(&bind_address, sizeof(bind_address)) == X_STATUS_SUCCESS);
  REQUIRE(receiver.SetNonBlocking(true) == X_STATUS_SUCCESS);

  sockaddr_in receiver_address{};
#if REX_PLATFORM_WIN32
  int receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<SOCKET>(receiver.native_handle());
#else
  socklen_t receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<int>(receiver.native_handle());
#endif
  REQUIRE(getsockname(receiver_socket, reinterpret_cast<sockaddr*>(&receiver_address),
                      &receiver_length) == 0);
  receiver_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

  auto sender = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
#if REX_PLATFORM_WIN32
  REQUIRE(sender != INVALID_SOCKET);
#else
  REQUIRE(sender >= 0);
#endif
  sockaddr_in sender_address{};
  sender_address.sin_family = AF_INET;
  sender_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  sender_address.sin_port = 0;
  REQUIRE(bind(sender, reinterpret_cast<const sockaddr*>(&sender_address),
               sizeof(sender_address)) == 0);
#if REX_PLATFORM_WIN32
  int sender_length = sizeof(sender_address);
#else
  socklen_t sender_length = sizeof(sender_address);
#endif
  REQUIRE(getsockname(sender, reinterpret_cast<sockaddr*>(&sender_address), &sender_length) == 0);

  xam::NatProbeAttach(receiver.native_handle(), xam::NatProbeRole::kGameplay,
                      {INADDR_ANY, ntohs(receiver_address.sin_port)});
  REQUIRE(xam::NatProbeInstallIdentity(
      {Hex(kAttempt), Hex(kCapability), "127.0.0.1", ntohs(sender_address.sin_port), 0}));
  const uint32_t loopback = htonl(INADDR_LOOPBACK);
  const auto control = RegisteredPacket(loopback, 40000, loopback,
                                        ntohs(sender_address.sin_port));
  constexpr std::array<uint8_t, 5> guest{'G', 'U', 'E', 'S', 'T'};

  // Control is processed without a guest receive and disappears from its view.
  REQUIRE(sendto(sender, reinterpret_cast<const char*>(control.data()), int(control.size()), 0,
                 reinterpret_cast<const sockaddr*>(&receiver_address), sizeof(receiver_address)) ==
          int(control.size()));
  REQUIRE(receiver.WaitReadable(500));
  CHECK(receiver.PumpNatControl());
  CHECK_FALSE(receiver.WaitReadable(0));
  REQUIRE(xam::NatProbePeer(receiver.native_handle(), false).has_value());

  // Guest data at the head is never consumed by the NAT pump.
  REQUIRE(sendto(sender, reinterpret_cast<const char*>(guest.data()), int(guest.size()), 0,
                 reinterpret_cast<const sockaddr*>(&receiver_address), sizeof(receiver_address)) ==
          int(guest.size()));
  REQUIRE(sendto(sender, reinterpret_cast<const char*>(control.data()), int(control.size()), 0,
                 reinterpret_cast<const sockaddr*>(&receiver_address), sizeof(receiver_address)) ==
          int(control.size()));
  REQUIRE(receiver.WaitReadable(500));
  CHECK_FALSE(receiver.PumpNatControl());
  std::array<uint8_t, 64> received{};
  N_XSOCKADDR_IN source{};
  uint32_t source_length = sizeof(source);
  REQUIRE(receiver.RecvFrom(received.data(), uint32_t(received.size()), 0, &source,
                            &source_length) == int(guest.size()));
  CHECK(std::memcmp(received.data(), guest.data(), guest.size()) == 0);
  CHECK(receiver.PumpNatControl());
  CHECK_FALSE(receiver.WaitReadable(0));

  // Control followed by gameplay is demultiplexed without reordering gameplay.
  REQUIRE(sendto(sender, reinterpret_cast<const char*>(control.data()), int(control.size()), 0,
                 reinterpret_cast<const sockaddr*>(&receiver_address), sizeof(receiver_address)) ==
          int(control.size()));
  REQUIRE(sendto(sender, reinterpret_cast<const char*>(guest.data()), int(guest.size()), 0,
                 reinterpret_cast<const sockaddr*>(&receiver_address), sizeof(receiver_address)) ==
          int(guest.size()));
  REQUIRE(receiver.WaitReadable(500));
  CHECK(receiver.PumpNatControl());
  source_length = sizeof(source);
  REQUIRE(receiver.RecvFrom(received.data(), uint32_t(received.size()), 0, &source,
                            &source_length) == int(guest.size()));
  CHECK(std::memcmp(received.data(), guest.data(), guest.size()) == 0);

  xam::NatProbeRetireIdentity(Hex(kAttempt));
  xam::NatProbeDetach(receiver.native_handle());
  CloseNativeSocket(sender);
}

TEST_CASE("UDP socket readability and synchronous receive preserve payload and source",
          "[network][overlapped]") {
#if REX_PLATFORM_WIN32
  WSADATA data{};
  REQUIRE(WSAStartup(MAKEWORD(2, 2), &data) == 0);
#endif
  XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                              XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);

  N_XSOCKADDR_IN bind_address{};
  bind_address.sin_family = AF_INET;
  bind_address.sin_port = 0;
  bind_address.sin_addr = INADDR_ANY;
  REQUIRE(receiver.Bind(&bind_address, sizeof(bind_address)) == X_STATUS_SUCCESS);
  CHECK_FALSE(receiver.WaitReadable(0));

  sockaddr_in receiver_address{};
#if REX_PLATFORM_WIN32
  int receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<SOCKET>(receiver.native_handle());
#else
  socklen_t receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<int>(receiver.native_handle());
#endif
  REQUIRE(getsockname(receiver_socket, reinterpret_cast<sockaddr*>(&receiver_address),
                      &receiver_length) == 0);
  receiver_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

  auto sender = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
#if REX_PLATFORM_WIN32
  REQUIRE(sender != INVALID_SOCKET);
#else
  REQUIRE(sender >= 0);
#endif
  constexpr std::array<uint8_t, 6> payload{'H', 'a', 'r', 'm', 'o', 'n'};
  REQUIRE(sendto(sender, reinterpret_cast<const char*>(payload.data()), int(payload.size()), 0,
                 reinterpret_cast<const sockaddr*>(&receiver_address), sizeof(receiver_address)) ==
          int(payload.size()));

  REQUIRE(receiver.WaitReadable(500));
  std::array<uint8_t, 32> received{};
  N_XSOCKADDR_IN source{};
  uint32_t source_length = sizeof(source);
  int count = receiver.RecvFrom(received.data(), uint32_t(received.size()), 0, &source,
                                &source_length);
  CHECK(count == int(payload.size()));
  CHECK(std::memcmp(received.data(), payload.data(), payload.size()) == 0);
  CHECK(source.sin_family == AF_INET);
  CHECK(source_length == sizeof(XSOCKADDR_IN));
  CHECK_FALSE(receiver.WaitReadable(0));

  CloseNativeSocket(sender);
}

TEST_CASE("XSocket SendTo preserves guest IPv4 endpoint byte order", "[network][socket]") {
#if REX_PLATFORM_WIN32
  WSADATA data{};
  REQUIRE(WSAStartup(MAKEWORD(2, 2), &data) == 0);
#endif
  XSocket receiver(nullptr);
  XSocket sender(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                              XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);
  REQUIRE(sender.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                            XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);

  N_XSOCKADDR_IN bind_address{};
  bind_address.sin_family = AF_INET;
  bind_address.sin_port = 0;
  bind_address.sin_addr = INADDR_ANY;
  REQUIRE(receiver.Bind(&bind_address, sizeof(bind_address)) == X_STATUS_SUCCESS);

  sockaddr_in receiver_address{};
#if REX_PLATFORM_WIN32
  int receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<SOCKET>(receiver.native_handle());
#else
  socklen_t receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<int>(receiver.native_handle());
#endif
  REQUIRE(getsockname(receiver_socket, reinterpret_cast<sockaddr*>(&receiver_address),
                      &receiver_length) == 0);

  N_XSOCKADDR_IN destination{};
  destination.sin_family = AF_INET;
  destination.sin_port = ntohs(receiver_address.sin_port);
  destination.sin_addr = ntohl(inet_addr("127.0.0.1"));
  constexpr std::array<uint8_t, 4> payload{'L', 'A', 'N', '!'};
  REQUIRE(sender.SendTo(const_cast<uint8_t*>(payload.data()), uint32_t(payload.size()), 0,
                        &destination, sizeof(destination)) == int(payload.size()));

  REQUIRE(receiver.WaitReadable(500));
  std::array<uint8_t, 16> received{};
  N_XSOCKADDR_IN source{};
  uint32_t source_length = sizeof(source);
  REQUIRE(receiver.RecvFrom(received.data(), uint32_t(received.size()), 0, &source,
                            &source_length) == int(payload.size()));
  CHECK(std::memcmp(received.data(), payload.data(), payload.size()) == 0);
  CHECK(uint32_t(source.sin_addr) == 0x7F000001u);
  CHECK(uint16_t(source.sin_port) != 0);
}

TEST_CASE("XSocket translates an opt-in guest gameplay port to its native LAN port",
          "[network][socket]") {
#if REX_PLATFORM_WIN32
  WSADATA data{};
  REQUIRE(WSAStartup(MAKEWORD(2, 2), &data) == 0);
#endif
  XSocket receiver(nullptr);
  XSocket sender(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                              XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);
  REQUIRE(sender.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                            XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);

  N_XSOCKADDR_IN bind_address{};
  bind_address.sin_family = AF_INET;
  bind_address.sin_port = 0;
  bind_address.sin_addr = INADDR_ANY;
  REQUIRE(receiver.Bind(&bind_address, sizeof(bind_address)) == X_STATUS_SUCCESS);

  sockaddr_in receiver_address{};
#if REX_PLATFORM_WIN32
  int receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<SOCKET>(receiver.native_handle());
#else
  socklen_t receiver_length = sizeof(receiver_address);
  auto receiver_socket = static_cast<int>(receiver.native_handle());
#endif
  REQUIRE(getsockname(receiver_socket, reinterpret_cast<sockaddr*>(&receiver_address),
                      &receiver_length) == 0);
  const uint16_t native_port = ntohs(receiver_address.sin_port);
  sender.ConfigurePortTranslation(1000, native_port);

  N_XSOCKADDR_IN destination{};
  destination.sin_family = AF_INET;
  destination.sin_port = 1000;
  destination.sin_addr = ntohl(inet_addr("127.0.0.1"));
  constexpr std::array<uint8_t, 4> payload{'P', 'O', 'R', 'T'};
  REQUIRE(sender.SendTo(const_cast<uint8_t*>(payload.data()), uint32_t(payload.size()), 0,
                        &destination, sizeof(destination)) == int(payload.size()));
  REQUIRE(receiver.WaitReadable(500));
}

TEST_CASE("translated nonblocking peer sockets exchange Harmony handshake-sized datagrams",
          "[network][socket][overlapped]") {
#if REX_PLATFORM_WIN32
  WSADATA data{};
  REQUIRE(WSAStartup(MAKEWORD(2, 2), &data) == 0);
#endif
  XSocket desktop(nullptr);
  XSocket ally(nullptr);
  REQUIRE(desktop.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                             XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);
  REQUIRE(ally.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                          XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);

  N_XSOCKADDR_IN desktop_bind{};
  desktop_bind.sin_family = AF_INET;
  desktop_bind.sin_port = 0;
  desktop_bind.sin_addr = 0x7F000001u;
  REQUIRE(desktop.Bind(&desktop_bind, sizeof(desktop_bind)) == X_STATUS_SUCCESS);
  const uint16_t native_port = ntohs(desktop.bound_port());

  N_XSOCKADDR_IN ally_bind{};
  ally_bind.sin_family = AF_INET;
  ally_bind.sin_port = native_port;
  ally_bind.sin_addr = 0x7F000002u;
  REQUIRE(ally.Bind(&ally_bind, sizeof(ally_bind)) == X_STATUS_SUCCESS);
  desktop.ConfigurePortTranslation(1000, native_port);
  ally.ConfigurePortTranslation(1000, native_port);
  REQUIRE(desktop.SetNonBlocking(true) == X_STATUS_SUCCESS);
  REQUIRE(ally.SetNonBlocking(true) == X_STATUS_SUCCESS);

  N_XSOCKADDR_IN ally_destination{};
  ally_destination.sin_family = AF_INET;
  ally_destination.sin_port = 1000;
  ally_destination.sin_addr = 0x7F000002u;
  std::array<uint8_t, 39> request{};
  request[0] = 0x39;
  REQUIRE(desktop.SendTo(request.data(), uint32_t(request.size()), 0, &ally_destination,
                         sizeof(ally_destination)) == int(request.size()));
  REQUIRE(ally.WaitReadable(500));

  std::array<uint8_t, 1264> receive_buffer{};
  N_XSOCKADDR_IN request_source{};
  uint32_t source_length = sizeof(request_source);
  REQUIRE(ally.RecvFrom(receive_buffer.data(), uint32_t(receive_buffer.size()), 0,
                        &request_source, &source_length) == int(request.size()));
  CHECK(uint32_t(request_source.sin_addr) == 0x7F000001u);
  CHECK(uint16_t(request_source.sin_port) == 1000);

  N_XSOCKADDR_IN desktop_destination{};
  desktop_destination.sin_family = AF_INET;
  desktop_destination.sin_port = 1000;
  desktop_destination.sin_addr = 0x7F000001u;
  std::array<uint8_t, 60> response{};
  response[0] = 0x60;
  REQUIRE(ally.SendTo(response.data(), uint32_t(response.size()), 0, &desktop_destination,
                      sizeof(desktop_destination)) == int(response.size()));
  REQUIRE(desktop.WaitReadable(500));

  N_XSOCKADDR_IN response_source{};
  source_length = sizeof(response_source);
  REQUIRE(desktop.RecvFrom(receive_buffer.data(), uint32_t(receive_buffer.size()), 0,
                           &response_source, &source_length) == int(response.size()));
  CHECK(receive_buffer[0] == 0x60);
  CHECK(uint32_t(response_source.sin_addr) == 0x7F000002u);
  CHECK(uint16_t(response_source.sin_port) == 1000);
}

}  // namespace rex::system
