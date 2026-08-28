#include <array>
#include <cstring>

#include <catch2/catch_test_macros.hpp>

#include <rex/system/xsocket.h>

#if REX_PLATFORM_WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

namespace rex::system {
namespace {

void CloseNativeSocket(uintptr_t socket) {
#if REX_PLATFORM_WIN32
  closesocket(static_cast<SOCKET>(socket));
#else
  close(static_cast<int>(socket));
#endif
}

}  // namespace

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
