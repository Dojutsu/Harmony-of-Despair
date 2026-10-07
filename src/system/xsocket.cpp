/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

#include <array>
#include <climits>
#include <cstring>

#include <rex/kernel/xam/module.h>
#include <rex/logging.h>
#include <rex/platform.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xsocket.h>
#include <rex/system/xam/nat_probe.h>
#include <rex/system/xam/gameplay_traversal.h>
// #include <rex/system/xnet.h>

#include <rex/net/socket.h>

// Standard socket types used by Xbox API emulation
#if REX_PLATFORM_WIN32
#include <WinSock2.h>

#include <WS2tcpip.h>
#else
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#endif

namespace rex::system {

XSocket::XSocket(KernelState* kernel_state) : XObject(kernel_state, kObjectType) {}

XSocket::XSocket(KernelState* kernel_state, uint64_t native_handle)
    : XObject(kernel_state, kObjectType), native_handle_(native_handle) {}

XSocket::~XSocket() {
  Close();
}

X_STATUS XSocket::Initialize(AddressFamily af, Type type, Protocol proto) {
  af_ = af;
  type_ = type;
  proto_ = proto;

  if (proto == Protocol::X_IPPROTO_VDP) {
    // VDP is a layer on top of UDP.
    proto = Protocol::X_IPPROTO_UDP;
  }

  native_handle_.store(socket(af, type, proto), std::memory_order_release);
  if (native_handle() == -1) {
    return X_STATUS_UNSUCCESSFUL;
  }

  REXSYS_INFO("XSocket::Initialize: native={} af={} type={} proto={}", native_handle(),
              uint32_t(af), uint32_t(type), uint32_t(proto));

  return X_STATUS_SUCCESS;
}

X_STATUS XSocket::Close() {
  // Explicit guest close and XObject destruction must retire the native socket
  // exactly once. POSIX may immediately reuse this descriptor for another file.
  const auto handle = native_handle_.exchange(uint64_t(-1), std::memory_order_acq_rel);
  if (handle == uint64_t(-1))
    return X_STATUS_SUCCESS;
  REXSYS_INFO("XSocket::Close: native={}", handle);
  xam::CloseGameplaySocket(handle);
  xam::NatProbeDetach(handle);
  return rex::net::socket_close(handle) == 0 ? X_STATUS_SUCCESS : X_STATUS_UNSUCCESSFUL;
}

X_STATUS XSocket::SetOption(uint32_t level, uint32_t optname, void* optval_ptr, uint32_t optlen) {
  if (level == 0xFFFF && (optname == 0x5801 || optname == 0x5802)) {
    // Disable socket encryption
    secure_ = false;
    return X_STATUS_SUCCESS;
  }

#if REX_PLATFORM_WIN32
  int ret = setsockopt(native_handle(), level, optname, (char*)optval_ptr, optlen);
#else
  // The title always supplies Xbox/Winsock constants and big-endian values,
  // regardless of the native platform. Never forward guest option numbers to
  // Linux, where even SOL_SOCKET has a different value.
  if (!optval_ptr) {
    errno = EFAULT;
    return X_STATUS_UNSUCCESSFUL;
  }
  int native_level = SOL_SOCKET;
  int native_option = 0;
  bool boolean = false;
  if (level == 0xFFFF) {
    switch (optname) {
      case 0x0001: native_option = SO_DEBUG; boolean = true; break;
      case 0x0004: native_option = SO_REUSEADDR; boolean = true; break;
      case 0x0008: native_option = SO_KEEPALIVE; boolean = true; break;
      case 0x0010: native_option = SO_DONTROUTE; boolean = true; break;
      case 0x0020: native_option = SO_BROADCAST; boolean = true; break;
      case 0x0080: native_option = SO_LINGER; break;
      case 0x0100: native_option = SO_OOBINLINE; boolean = true; break;
      case 0x1001: native_option = SO_SNDBUF; break;
      case 0x1002: native_option = SO_RCVBUF; break;
      case 0x1005: native_option = SO_SNDTIMEO; break;
      case 0x1006: native_option = SO_RCVTIMEO; break;
      default: errno = ENOPROTOOPT; return X_STATUS_UNSUCCESSFUL;
    }
  } else if (level == 6 && optname == 1) {
    native_level = IPPROTO_TCP;
    native_option = TCP_NODELAY;
    boolean = true;
  } else {
    errno = ENOPROTOOPT;
    return X_STATUS_UNSUCCESSFUL;
  }
  if (optlen != 4) {
    errno = EINVAL;
    return X_STATUS_UNSUCCESSFUL;
  }
  rex::be<uint32_t> encoded_value;
  std::memcpy(&encoded_value, optval_ptr, sizeof(encoded_value));
  uint32_t value = encoded_value;
  int ret;
  if (native_option == SO_LINGER) {
    std::array<rex::be<uint16_t>, 2> encoded_linger;
    std::memcpy(encoded_linger.data(), optval_ptr, sizeof(encoded_linger));
    linger native_linger{int(uint16_t(encoded_linger[0]) != 0),
                         int(uint16_t(encoded_linger[1]))};
    ret = setsockopt(native_handle(), native_level, native_option, &native_linger,
                     sizeof(native_linger));
  } else if (native_option == SO_SNDTIMEO || native_option == SO_RCVTIMEO) {
    timeval native_timeout{static_cast<time_t>(value / 1000),
                           static_cast<suseconds_t>((value % 1000) * 1000)};
    ret = setsockopt(native_handle(), native_level, native_option, &native_timeout,
                     sizeof(native_timeout));
  } else {
    if (!boolean && value > INT_MAX) {
      errno = EINVAL;
      return X_STATUS_UNSUCCESSFUL;
    }
    int native_value = boolean ? int(value != 0) : int(value);
    ret = setsockopt(native_handle(), native_level, native_option, &native_value,
                     sizeof(native_value));
  }
#endif
  REXSYS_INFO("XSocket::SetOption: native={} level={:#x} option={:#x} length={} result={}",
              native_handle(), level, optname, optlen, ret);
  if (ret < 0) {
    // TODO: WSAGetLastError()
    return X_STATUS_UNSUCCESSFUL;
  }

  // SO_BROADCAST
  if (level == 0xFFFF && optname == 0x0020) {
    broadcast_socket_ = true;
  }

  return X_STATUS_SUCCESS;
}

X_STATUS XSocket::IOControl(uint32_t cmd, uint8_t* arg_ptr) {
#if REX_PLATFORM_WIN32
  int ret = rex::net::socket_ioctl(native_handle(), cmd, arg_ptr);
#else
  if (!arg_ptr) {
    errno = EFAULT;
    return X_STATUS_UNSUCCESSFUL;
  }
  if (cmd == 0x8004667E) {  // Xbox FIONBIO, BE32 input.
    rex::be<uint32_t> value;
    std::memcpy(&value, arg_ptr, sizeof(value));
    return SetNonBlocking(uint32_t(value) != 0);
  }
  if (cmd != 0x4004667F) {  // Xbox FIONREAD, BE32 output.
    errno = EINVAL;
    return X_STATUS_UNSUCCESSFUL;
  }
  int available = 0;
  int ret = ioctl(native_handle(), FIONREAD, &available);
  if (ret == 0) {
    rex::be<uint32_t> value = uint32_t(available);
    std::memcpy(arg_ptr, &value, sizeof(value));
  }
#endif
  if (ret < 0) {
    // TODO: Get last error
    return X_STATUS_UNSUCCESSFUL;
  }

  return X_STATUS_SUCCESS;
}

X_STATUS XSocket::SetNonBlocking(bool enabled) {
#if REX_PLATFORM_WIN32
  u_long value = enabled ? 1 : 0;
  return ioctlsocket(static_cast<SOCKET>(native_handle()), FIONBIO, &value) == 0
             ? X_STATUS_SUCCESS
             : X_STATUS_UNSUCCESSFUL;
#else
  int flags = fcntl(static_cast<int>(native_handle()), F_GETFL, 0);
  if (flags < 0)
    return X_STATUS_UNSUCCESSFUL;
  int updated = enabled ? (flags | O_NONBLOCK) : (flags & ~O_NONBLOCK);
  return fcntl(static_cast<int>(native_handle()), F_SETFL, updated) == 0 ? X_STATUS_SUCCESS
                                                                       : X_STATUS_UNSUCCESSFUL;
#endif
}

X_STATUS XSocket::Connect(N_XSOCKADDR* name, int name_len) {
  int ret = connect(native_handle(), (sockaddr*)name, name_len);
  REXSYS_INFO("XSocket::Connect: native={} family={} length={} result={}", native_handle(),
              name ? name->address_family : 0, name_len, ret);
  if (ret < 0) {
    return X_STATUS_UNSUCCESSFUL;
  }

  return X_STATUS_SUCCESS;
}

X_STATUS XSocket::Bind(N_XSOCKADDR_IN* name, int name_len) {
  int ret = bind(native_handle(), (sockaddr*)name, name_len);
  if (ret < 0) {
    return X_STATUS_UNSUCCESSFUL;
  }

  bound_ = true;
  sockaddr_in actual_address{};
  socklen_t actual_length = sizeof(actual_address);
  if (getsockname(native_handle(), reinterpret_cast<sockaddr*>(&actual_address), &actual_length) ==
      0) {
    // Keep the native/network-order value used by sockaddr. This is especially
    // important for port 0, where the OS selects the real guest transport port.
    bound_port_ = actual_address.sin_port;
    REXSYS_INFO("XSocket::Bind: native={} local={:08X}:{}", native_handle(),
                ntohl(actual_address.sin_addr.s_addr), ntohs(actual_address.sin_port));
    if (type_ == Type::X_SOCK_DGRAM &&
        xam::NatProbeIsGameplayPort(ntohs(actual_address.sin_port))) {
      xam::NatProbeAttach(native_handle(), xam::NatProbeRole::kGameplay,
                          {actual_address.sin_addr.s_addr, ntohs(actual_address.sin_port)}, this);
      if (auto* manager = kernel_state() ? kernel_state()->session_manager() : nullptr) {
        const auto local_xuid = kernel_state()->user_profile()->xuid();
        xam::RegisterGameplaySocketCandidate(local_xuid, native_handle(),
            guest_port_ ? guest_port_ : ntohs(actual_address.sin_port));
        std::shared_ptr<xam::SessionRecord> exact;
        for (const auto& record : manager->registry().List()) {
          std::lock_guard lock(*record->mutex);
          if (record->state == xam::SessionState::kDeleted ||
              std::none_of(record->members.begin(), record->members.end(), [&](const auto& member) {
                return member.xuid == local_xuid && member.local;
              })) continue;
          if (exact) { exact.reset(); break; }  // Never guess between sessions.
          exact = record;
        }
        if (exact)
          xam::BindGameplaySocket(exact, local_xuid, native_handle(),
                                  guest_port_ ? guest_port_ : ntohs(actual_address.sin_port));
      }
    }
  } else {
    bound_port_ = name->sin_port;
    REXSYS_ERROR("XSocket::Bind: getsockname failed native={} error={}", native_handle(),
#if REX_PLATFORM_WIN32
                 WSAGetLastError()
#else
                 errno
#endif
    );
  }

  return X_STATUS_SUCCESS;
}

X_STATUS XSocket::Listen(int backlog) {
  int ret = listen(native_handle(), backlog);
  if (ret < 0) {
    return X_STATUS_UNSUCCESSFUL;
  }

  return X_STATUS_SUCCESS;
}

object_ref<XSocket> XSocket::Accept(N_XSOCKADDR* name, int* name_len) {
  sockaddr n_sockaddr;
  socklen_t n_name_len = sizeof(sockaddr);
  uintptr_t ret = accept(native_handle(), &n_sockaddr, &n_name_len);
  if (ret == -1) {
    std::memset(name, 0, *name_len);
    *name_len = 0;
    return nullptr;
  }

  std::memcpy(name, &n_sockaddr, n_name_len);
  *name_len = n_name_len;

  // Create a kernel object to represent the new socket, and copy parameters
  // over.
  auto socket = object_ref<XSocket>(new XSocket(kernel_state_, ret));
  socket->af_ = af_;
  socket->type_ = type_;
  socket->proto_ = proto_;

  return socket;
}

int XSocket::Shutdown(int how) {
  return shutdown(native_handle(), how);
}

int XSocket::Recv(uint8_t* buf, uint32_t buf_len, uint32_t flags) {
#if REX_PLATFORM_GNU_LINUX
  const int result = recv(native_handle(), reinterpret_cast<char*>(buf), buf_len,
                           flags | (type_ == X_SOCK_DGRAM ? MSG_TRUNC : 0));
  if (result > 0 && uint32_t(result) > buf_len) {
    errno = EMSGSIZE;
    return -1;
  }
  return result;
#else
  return recv(native_handle(), reinterpret_cast<char*>(buf), buf_len, flags);
#endif
}

int XSocket::RecvFrom(uint8_t* buf, uint32_t buf_len, uint32_t flags, N_XSOCKADDR_IN* from,
                      uint32_t* from_len) {
  std::lock_guard receive_lock(native_receive_mutex_);
  // Pop from secure packets first
  // TODO(DrChat): Enable when I commit XNet
  /*
  {
    std::lock_guard<std::mutex> lock(incoming_packet_mutex_);
    if (incoming_packets_.size()) {
      packet* pkt = (packet*)incoming_packets_.front();
      int data_len = pkt->data_len;
      std::memcpy(buf, pkt->data, std::min((uint32_t)pkt->data_len, buf_len));

      from->sin_family = 2;
      from->sin_addr = pkt->src_ip;
      from->sin_port = pkt->src_port;

      incoming_packets_.pop();
      uint8_t* pkt_ui8 = (uint8_t*)pkt;
      delete[] pkt_ui8;

      return data_len;
    }
  }
  */

retry_native_receive:
  xam::NatProbeTick(native_handle());
  sockaddr_in nfrom;
  socklen_t nfromlen = sizeof(sockaddr_in);
  int ret = recvfrom(native_handle(), reinterpret_cast<char*>(buf), buf_len,
#if REX_PLATFORM_GNU_LINUX
                     flags | (type_ == X_SOCK_DGRAM ? MSG_TRUNC : 0),
#else
                     flags,
#endif
                     (sockaddr*)&nfrom, &nfromlen);
#if REX_PLATFORM_GNU_LINUX
  // Winsock rejects oversized UDP after copying the available prefix. Never
  // authorize NAT/control state from that prefix or report it as game payload.
  if (ret > 0 && uint32_t(ret) > buf_len) {
    errno = EMSGSIZE;
    return -1;
  }
#endif
  if (ret > 0 && xam::NatProbeConsume(native_handle(), buf, ret, nfrom.sin_addr.s_addr,
                                      ntohs(nfrom.sin_port))) {
    goto retry_native_receive;
  }
  if (ret > 0 && xam::NatProbeIsPendingGameplaySource(native_handle(),
          {nfrom.sin_addr.s_addr, ntohs(nfrom.sin_port)}))
    goto retry_native_receive;
  if (ret >= 0 && from) {
    from->sin_family = nfrom.sin_family;
    const uint16_t source_port = ntohs(nfrom.sin_port);
    const xam::LanAddress native_source{nfrom.sin_addr.s_addr, source_port};
    if (auto logical = xam::NatProbeNormalizeGameplaySource(native_handle(), native_source)) {
      xam::NatProbeRecordGameplayTraffic(native_handle(), native_source, size_t(ret), false);
      from->sin_addr = ntohl(logical->ipv4);
      from->sin_port = logical->port;
      if (last_normalized_source_ipv4_ != native_source.ipv4 ||
          last_normalized_source_port_ != native_source.port) {
        REXSYS_INFO(
            "NAT traversal: inbound gameplay source normalized native={:08X}:{} guest={:08X}:{}",
            native_source.ipv4, native_source.port, logical->ipv4, logical->port);
        last_normalized_source_ipv4_ = native_source.ipv4;
        last_normalized_source_port_ = native_source.port;
      }
    } else {
      // Ordinary LAN peers retain their original source-address behavior.
      from->sin_addr = ntohl(nfrom.sin_addr.s_addr);  // BE <- BE
      from->sin_port = native_port_ != 0 && source_port == native_port_ ? guest_port_ : source_port;
    }
    std::memset(from->x_sin_zero, 0, sizeof(from->x_sin_zero));
  }

  if (ret >= 0 && from_len) {
    *from_len = nfromlen;
  }

  return ret;
}

bool XSocket::PumpNatControl() {
  std::lock_guard receive_lock(native_receive_mutex_);
  if (!WaitReadable(0)) return false;

  // One extra byte distinguishes an exact control frame from a valid-looking
  // prefix of an oversized datagram on both POSIX and Winsock peek paths.
  std::array<uint8_t, 57> packet{};
  sockaddr_in source{};
  socklen_t source_length = sizeof(source);
  const int peeked = recvfrom(native_handle(), reinterpret_cast<char*>(packet.data()),
                              int(packet.size()), MSG_PEEK,
                              reinterpret_cast<sockaddr*>(&source), &source_length);
  if (peeked <= 0 ||
      !xam::NatProbeIsControlPacket(native_handle(), packet.data(), size_t(peeked),
                                    source.sin_addr.s_addr, ntohs(source.sin_port)))
    return false;

  source_length = sizeof(source);
  const int received = recvfrom(native_handle(), reinterpret_cast<char*>(packet.data()),
                                int(packet.size()), 0,
                                reinterpret_cast<sockaddr*>(&source), &source_length);
  const bool consumed =
      received > 0 && xam::NatProbeConsume(native_handle(), packet.data(), size_t(received),
                                           source.sin_addr.s_addr, ntohs(source.sin_port));
  if (consumed)
    REXSYS_INFO("NAT traversal: independent gameplay control receive socket={} type={} "
                "source={:08X}:{}",
                native_handle(), packet[5], source.sin_addr.s_addr, ntohs(source.sin_port));
  return consumed;
}

bool XSocket::WaitReadable(uint32_t timeout_ms, bool infinite) const {
  const auto handle = native_handle();
  if (handle == uint64_t(-1))
    return false;
#if !REX_PLATFORM_WIN32
  pollfd pending{static_cast<int>(handle), POLLIN, 0};
  // poll has a signed millisecond timeout. Split unusually long finite waits
  // without turning them into an infinite wait or overflowing an int.
  uint32_t remaining = timeout_ms;
  for (;;) {
    const int interval = infinite ? -1 : static_cast<int>(std::min<uint32_t>(remaining, INT_MAX));
    const int result = poll(&pending, 1, interval);
    if (result != 0 || infinite || remaining <= uint32_t(INT_MAX))
      return result > 0 && (pending.revents & (POLLIN | POLLHUP | POLLERR));
    remaining -= uint32_t(INT_MAX);
  }
#else
  fd_set read_set;
  FD_ZERO(&read_set);
#if REX_PLATFORM_WIN32
  auto native_socket = static_cast<SOCKET>(native_handle());
#else
  auto native_socket = static_cast<int>(native_handle());
#endif
  FD_SET(native_socket, &read_set);
  timeval timeout{static_cast<long>(timeout_ms / 1000),
                  static_cast<long>((timeout_ms % 1000) * 1000)};
  int result = select(
#if REX_PLATFORM_WIN32
      0,
#else
      native_socket + 1,
#endif
      &read_set, nullptr, nullptr, infinite ? nullptr : &timeout);
#if REX_PLATFORM_WIN32
  if (result == 0) {
    u_long available = 0;
    if (ioctlsocket(native_socket, FIONREAD, &available) == 0 && available != 0) {
      REXSYS_ERROR(
          "XSocket::WaitReadable: select reported no data but FIONREAD reports {} bytes "
          "native={}",
          available, native_handle());
    }
  }
#endif
  if (result < 0) {
    REXSYS_ERROR("XSocket::WaitReadable: select failed native={} error={}", native_handle(),
#if REX_PLATFORM_WIN32
                 WSAGetLastError()
#else
                 errno
#endif
    );
  }
  return result > 0 && FD_ISSET(native_socket, &read_set);
#endif
}

int XSocket::Send(const uint8_t* buf, uint32_t buf_len, uint32_t flags) {
  return send(native_handle(), reinterpret_cast<const char*>(buf), buf_len, flags);
}

int XSocket::SendTo(uint8_t* buf, uint32_t buf_len, uint32_t flags, N_XSOCKADDR_IN* to,
                    uint32_t to_len) {
  // Send 2 copies of the packet: One to XNet (for network security) and an
  // unencrypted copy for other Xenia hosts.
  // TODO(DrChat): Enable when I commit XNet.
  /*
  auto xam = kernel_state()->GetKernelModule<xam::XamModule>("xam.xex");
  auto xnet = xam->xnet();
  if (xnet) {
    xnet->SendPacket(this, to, buf, buf_len);
  }
  */

  xam::NatProbeTick(native_handle());
  sockaddr_in nto;
  if (to) {
    // N_XSOCKADDR_IN exposes logical host-order values through endian_store,
    // while sockaddr_in requires network-order integer storage.
    nto.sin_addr.s_addr = htonl(uint32_t(to->sin_addr));
    nto.sin_family = to->sin_family;
    const uint16_t destination_port =
        native_port_ != 0 && uint16_t(to->sin_port) == guest_port_ ? native_port_
                                                                   : uint16_t(to->sin_port);
    nto.sin_port = htons(destination_port);
    if (xam::IsAuthorizedGameplaySocket(native_handle())) {
      auto logical = xam::GameplayLogicalDestination(native_handle(),
          {nto.sin_addr.s_addr, uint16_t(to->sin_port)});
      auto peer = logical ? xam::NatProbeGameplayDestination(native_handle(), *logical) : std::nullopt;
      if (!peer && (logical || xam::IsGameplayLogicalAddress(nto.sin_addr.s_addr))) {
#if REX_PLATFORM_WIN32
        WSASetLastError(WSAEWOULDBLOCK);
#else
        errno = EWOULDBLOCK;
#endif
        return -1;
      }
      if (peer) {
        nto.sin_addr.s_addr = peer->ipv4;
        nto.sin_port = htons(peer->port);
      }
    } else if (xam::IsGameplayLogicalAddress(nto.sin_addr.s_addr)) {
#if REX_PLATFORM_WIN32
      WSASetLastError(WSAEHOSTUNREACH);
#else
      errno = EHOSTUNREACH;
#endif
      return -1;
    } else if (auto peer = xam::NatProbePeer(native_handle())) {
      nto.sin_addr.s_addr = peer->ipv4;
      nto.sin_port = htons(peer->port);
      if (xam::NatProbeIsClient()) {
        auto* profile = kernel_state()->user_profile();
        auto* sessions = kernel_state()->session_manager();
        if (profile && sessions &&
            sessions->registry().UpdateRemoteGameplayEndpoint(profile->xuid(), *peer)) {
          REXSYS_INFO("NAT traversal: mapped gameplay endpoint placed in SessionInfo {:08X}:{}",
                      peer->ipv4, peer->port);
        }
      }
    }
  }

  const int result = sendto(native_handle(), reinterpret_cast<char*>(buf), buf_len, flags,
                to ? (sockaddr*)&nto : nullptr, to_len);
  if (result > 0 && to)
    xam::NatProbeRecordGameplayTraffic(native_handle(),
        {nto.sin_addr.s_addr, ntohs(nto.sin_port)}, size_t(result), true);
  return result;
}

bool XSocket::QueuePacket(uint32_t src_ip, uint16_t src_port, const uint8_t* buf, size_t len) {
  packet* pkt = reinterpret_cast<packet*>(new uint8_t[sizeof(packet) + len]);
  pkt->src_ip = src_ip;
  pkt->src_port = src_port;

  pkt->data_len = (uint16_t)len;
  std::memcpy(pkt->data, buf, len);

  std::lock_guard<std::mutex> lock(incoming_packet_mutex_);
  incoming_packets_.push((uint8_t*)pkt);

  // TODO: Limit on number of incoming packets?
  return true;
}

}  // namespace rex::system
