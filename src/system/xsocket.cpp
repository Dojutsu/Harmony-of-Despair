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
#include <chrono>
#include <cstring>
#include <vector>

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
#if REX_PLATFORM_GNU_LINUX
#include <sys/uio.h>
#include <sys/eventfd.h>
#include <unistd.h>
#elif REX_PLATFORM_MAC
#include <optional>
#include <unistd.h>
#include "net_posix_compat.h"
#endif
#endif

namespace rex::system {

namespace {
int ClosedNativeSocket() {
#if REX_PLATFORM_WIN32
  WSASetLastError(WSAENOTSOCK);
#else
  errno = ENOTSOCK;
#endif
  return -1;
}
// Report a POSIX-style failure through the platform's socket error channel.
void FailSocket(int posix_error) {
#if REX_PLATFORM_WIN32
  int code = WSAEINVAL;
  switch (posix_error) {
    case EMSGSIZE: code = WSAEMSGSIZE; break;
    case EWOULDBLOCK: code = WSAEWOULDBLOCK; break;
    case EDESTADDRREQ: code = WSAEDESTADDRREQ; break;
    case EFAULT: code = WSAEFAULT; break;
    case EAFNOSUPPORT: code = WSAEAFNOSUPPORT; break;
    default: break;
  }
  // Tests and POSIX-style callers read errno; Winsock callers read the WSA code.
  errno = posix_error;
  WSASetLastError(code);
#else
  errno = posix_error;
#endif
}
#if REX_PLATFORM_GNU_LINUX
constexpr int kNoSignal = MSG_NOSIGNAL;
#else
// macOS: every online socket carries SO_NOSIGPIPE instead (see Initialize/Accept).
constexpr int kNoSignal = 0;
#endif
#if REX_PLATFORM_MAC
// Guest N_XSOCKADDR stores a 16-bit host-order family where BSD sockaddr has
// sa_len followed by an 8-bit sa_family. Linux/Windows pass the guest layout
// straight through; Darwin needs the header rewritten in a native copy.
bool StageNativeSockaddr(const void* guest, int length, sockaddr_storage& native,
                         socklen_t& native_length) {
  if (!guest || length < 2 || size_t(length) > sizeof(native)) { errno = EINVAL; return false; }
  std::memset(&native, 0, sizeof(native));
  std::memcpy(&native, guest, size_t(length));
  uint16_t family = 0;
  std::memcpy(&family, guest, sizeof(family));
  native.ss_len = uint8_t(length);
  native.ss_family = sa_family_t(family);
  native_length = socklen_t(length);
  return true;
}
// Inverse of StageNativeSockaddr for addresses returned to the guest.
void PublishNativeSockaddr(const sockaddr& native, void* guest) {
  const uint16_t family = native.sa_family;
  std::memcpy(guest, &family, sizeof(family));
}
// Darwin's shutdown() fails with ENOTCONN on an unconnected UDP socket and on
// a listening socket, so unlike Linux it does not interrupt a blocked
// recvfrom/accept there, and Close relies on that wake. Blocking receives and
// accepts on macOS therefore wait in poll on the socket and its cancellation
// pipe first, honouring SO_RCVTIMEO like the native call (EAGAIN on expiry).
using MacDeadline = std::optional<std::chrono::steady_clock::time_point>;
// True when the call should block (blocking descriptor, no per-call
// MSG_DONTWAIT and a cancellation pipe to watch).
bool MacShouldEmulateBlocking(int handle, int cancellation, int flags) {
  const int mode = fcntl(handle, F_GETFL, 0);
  return mode >= 0 && !(mode & O_NONBLOCK) && !(flags & MSG_DONTWAIT) && cancellation >= 0;
}
bool MacReceiveDeadline(int handle, MacDeadline& deadline) {
  timeval timeout{};
  socklen_t length = sizeof(timeout);
  if (getsockopt(handle, SOL_SOCKET, SO_RCVTIMEO, &timeout, &length) < 0) return false;
  deadline.reset();
  if (timeout.tv_sec || timeout.tv_usec)
    deadline = std::chrono::steady_clock::now() + std::chrono::seconds(timeout.tv_sec) +
               std::chrono::microseconds(timeout.tv_usec);
  return true;
}
// Returns true once the socket is readable; false with errno set on
// cancellation (ENOTSOCK), timeout (EAGAIN) or a poll failure.
template <class Retired>
bool MacWaitReadable(int handle, int cancellation, Retired retired, const MacDeadline& deadline) {
  for (;;) {
    std::array<pollfd, 2> descriptors{{{handle, POLLIN, 0}, {cancellation, POLLIN, 0}}};
    timespec remaining{};
    const timespec* wait = nullptr;
    if (deadline) {
      const auto left = *deadline - std::chrono::steady_clock::now();
      if (left <= decltype(left)::zero()) { errno = EAGAIN; return false; }
      const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(left);
      remaining.tv_sec = seconds.count();
      remaining.tv_nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(left - seconds).count();
      wait = &remaining;
    }
    const int ready = rex::net::mac::PollTimespec(descriptors.data(), descriptors.size(), wait);
    if (retired() || (ready > 0 && descriptors[1].revents)) { errno = ENOTSOCK; return false; }
    if (ready < 0) {
      if (errno == EINTR) continue;  // The native blocking call restarts (SA_RESTART).
      return false;
    }
    if (!ready) { errno = EAGAIN; return false; }
    return true;
  }
}
template <class Retired>
int MacDatagramReceive(int handle, int cancellation, Retired retired, uint8_t* data,
                       uint32_t capacity, int flags, sockaddr* from, socklen_t* from_length) {
  if (!MacShouldEmulateBlocking(handle, cancellation, flags))
    return int(recvfrom(handle, data, capacity, flags, from, from_length));
  MacDeadline deadline;
  if (!MacReceiveDeadline(handle, deadline)) return -1;
  for (;;) {
    if (!MacWaitReadable(handle, cancellation, retired, deadline)) return -1;
    const auto received = recvfrom(handle, data, capacity, flags | MSG_DONTWAIT, from, from_length);
    if (received >= 0 || (errno != EAGAIN && errno != EWOULDBLOCK)) return int(received);
    // Another receiver consumed the datagram first; wait again.
  }
}
template <class Retired>
int MacAccept(int handle, int cancellation, Retired retired, sockaddr* address,
              socklen_t* address_length) {
  if (MacShouldEmulateBlocking(handle, cancellation, 0)) {
    MacDeadline deadline;
    if (!MacReceiveDeadline(handle, deadline) ||
        !MacWaitReadable(handle, cancellation, retired, deadline))
      return -1;
  }
  // A connection taken by a concurrent accept between poll and here makes
  // this block like the native call; Close then wakes it only on Linux.
  return accept(handle, address, address_length);
}
#endif
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
std::optional<std::vector<uint8_t>> ProtectedGameplayWire(uint64_t socket,
    xam::LanAddress logical, const uint8_t* guest_data, uint32_t length) {
  if (length > xam::kGameplayMaximumPlaintextBytes) { FailSocket(EMSGSIZE); return std::nullopt; }
  std::vector<uint8_t> staged(length);
  if (length) {
#if REX_PLATFORM_GNU_LINUX
    // Preserve a bad guest pointer as EFAULT; never dereference it in userspace.
    iovec local{staged.data(), length}, remote{const_cast<uint8_t*>(guest_data), length};
    if (process_vm_readv(getpid(), &local, 1, &remote, 1, 0) != ssize_t(length)) {
      FailSocket(EFAULT); return std::nullopt;
    }
#elif REX_PLATFORM_MAC
    // Mirror process_vm_readv: a bad guest pointer fails as EFAULT, never faults.
    if (!rex::net::mac::ReadSelf(staged.data(), guest_data, length)) {
      FailSocket(EFAULT); return std::nullopt;
    }
#else
    // Mirror process_vm_readv: a bad guest pointer fails as EFAULT, never faults.
    SIZE_T copied = 0;
    if (!ReadProcessMemory(GetCurrentProcess(), guest_data, staged.data(), length, &copied) ||
        copied != length) {
      FailSocket(EFAULT); return std::nullopt;
    }
#endif
  }
  auto wire = xam::SealGameplayDatagram(socket, logical, staged);
  if (!wire) FailSocket(EWOULDBLOCK);
  return wire;
}
#endif
}  // namespace

struct XSocket::NativeSocketState {
  explicit NativeSocketState(uint64_t value) : handle(value) {
#if REX_PLATFORM_GNU_LINUX
    cancellation = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK);
#elif REX_PLATFORM_MAC
    // No eventfd: a nonblocking close-on-exec pipe. Waiters poll the read end
    // (cancellation); Close writes one never-drained byte to the write end.
    if (!rex::net::mac::CreateWakePipe(cancellation, cancellation_write))
      REXSYS_ERROR("XSocket: cancellation pipe unavailable socket={} error={}", handle, errno);
#endif
#if REX_PLATFORM_WIN32
    // Winsock shutdown does not wake a select blocked on an unconnected UDP
    // socket, and closesocket is deferred while a lease is held. Mirror the
    // Linux eventfd with a loopback datagram socket that Close pokes.
    const SOCKET pipe = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (pipe != INVALID_SOCKET) {
      sockaddr_in local{};
      local.sin_family = AF_INET;
      local.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
      int length = sizeof(local);
      u_long nonblocking = 1;
      if (::bind(pipe, reinterpret_cast<const sockaddr*>(&local), sizeof(local)) == 0 &&
          ::getsockname(pipe, reinterpret_cast<sockaddr*>(&local), &length) == 0 &&
          ::ioctlsocket(pipe, FIONBIO, &nonblocking) == 0) {
        wake = pipe;
        wake_address = local;
      } else {
        ::closesocket(pipe);
      }
    }
    if (wake == uint64_t(-1))
      REXSYS_ERROR("XSocket: wake socket unavailable socket={} error={}", handle, WSAGetLastError());
#endif
  }
  ~NativeSocketState() {
#if REX_PLATFORM_WIN32
    const int error = WSAGetLastError();
#else
    const int error = errno;
#endif
    Finalize();
#if REX_PLATFORM_GNU_LINUX
    if (cancellation >= 0) ::close(cancellation);
#elif REX_PLATFORM_MAC
    if (cancellation >= 0) ::close(cancellation);
    if (cancellation_write >= 0) ::close(cancellation_write);
#endif
#if REX_PLATFORM_WIN32
    if (wake != uint64_t(-1)) ::closesocket(static_cast<SOCKET>(wake));
    WSASetLastError(error);
#else
    errno = error;
#endif
  }
  bool valid() const {
#if REX_PLATFORM_POSIX_ONLINE
    return cancellation >= 0;
#else
    return true;
#endif
  }
  int Finalize() {
    if (finalized.exchange(true, std::memory_order_acq_rel)) return 0;
    // Admission tombstones and descriptor identity survive every native lease.
    // Close detaches the NAT worker before dropping its own final reference.
    xam::CloseGameplaySocket(handle);
    const int result = rex::net::socket_close(handle);
    if (result != 0) REXSYS_ERROR("XSocket: native retirement failed socket={}", handle);
    return result;
  }
  const uint64_t handle;
  std::atomic<bool> retired{false};
  std::atomic<bool> finalized{false};
  int cancellation = -1;
#if REX_PLATFORM_MAC
  int cancellation_write = -1;
#endif
#if REX_PLATFORM_WIN32
  uint64_t wake = uint64_t(-1);
  sockaddr_in wake_address{};
#endif
};

uint64_t XSocket::NativeLease::handle() const noexcept {
  return state_ ? state_->handle : uint64_t(-1);
}
int XSocket::NativeLease::cancellation_handle() const noexcept {
  return state_ ? state_->cancellation : -1;
}
uint64_t XSocket::NativeLease::wake_handle() const noexcept {
#if REX_PLATFORM_WIN32
  return state_ ? state_->wake : uint64_t(-1);
#else
  return uint64_t(-1);
#endif
}
bool XSocket::NativeLease::retired() const noexcept {
  return !state_ || state_->retired.load(std::memory_order_acquire);
}
XSocket::NativeLease XSocket::AcquireNativeLease() const {
  std::lock_guard lock(native_lifetime_mutex_);
  if (!native_state_ || native_state_->retired.load(std::memory_order_acquire)) {
    ClosedNativeSocket();
    return {};
  }
  return NativeLease(native_state_);
}

XSocket::XSocket(KernelState* kernel_state) : XObject(kernel_state, kObjectType) {}

XSocket::XSocket(KernelState* kernel_state, std::shared_ptr<NativeSocketState> state)
    : XObject(kernel_state, kObjectType), native_state_(std::move(state)) {
  native_handle_.store(native_state_->handle, std::memory_order_release);
}

XSocket::~XSocket() {
  Close();
}

X_STATUS XSocket::Initialize(AddressFamily af, Type type, Protocol proto) {
  std::lock_guard lock(native_lifetime_mutex_);
  if (native_state_ || !retired_state_.expired()) {
    ClosedNativeSocket();
    return X_STATUS_UNSUCCESSFUL;
  }
  const auto handle = socket(af, type
#if REX_PLATFORM_GNU_LINUX
      | SOCK_CLOEXEC
#endif
      , proto == Protocol::X_IPPROTO_VDP ? Protocol::X_IPPROTO_UDP : proto);
  if (handle == decltype(handle)(-1)) return X_STATUS_UNSUCCESSFUL;
#if REX_PLATFORM_MAC
  // SOCK_CLOEXEC and MSG_NOSIGNAL stand-ins, applied before first use.
  if (!rex::net::mac::ConfigureSocketDescriptor(int(handle))) {
    const int error = errno;
    rex::net::socket_close(handle);
    errno = error;
    return X_STATUS_UNSUCCESSFUL;
  }
#endif
  std::shared_ptr<NativeSocketState> state;
  try { state = std::make_shared<NativeSocketState>(handle); }
  catch (const std::bad_alloc&) {
    rex::net::socket_close(handle);
#if REX_PLATFORM_WIN32
    WSASetLastError(WSAENOBUFS);
#else
    errno = ENOMEM;
#endif
    return X_STATUS_UNSUCCESSFUL;
  }
  if (!state->valid()) return X_STATUS_UNSUCCESSFUL;
  af_ = af;
  type_ = type;
  proto_ = proto;
  native_state_ = std::move(state);
  native_handle_.store(handle, std::memory_order_release);
  REXSYS_INFO("XSocket::Initialize: native={} af={} type={} proto={}", handle,
              uint32_t(af), uint32_t(type), uint32_t(proto));
  return X_STATUS_SUCCESS;
}

X_STATUS XSocket::Close() {
  std::shared_ptr<NativeSocketState> state;
  {
    std::lock_guard lock(native_lifetime_mutex_);
    if (!native_state_) return X_STATUS_SUCCESS;
    state = std::move(native_state_);
    retired_state_ = state;
    native_handle_.store(uint64_t(-1), std::memory_order_release);
    state->retired.store(true, std::memory_order_release);
  }
  REXSYS_INFO("XSocket::Close: native={}", state->handle);
#if REX_PLATFORM_GNU_LINUX
  const uint64_t wake = 1;
  ssize_t written;
  do { written = ::write(state->cancellation, &wake, sizeof(wake)); }
  while (written < 0 && errno == EINTR);
  if (written != static_cast<ssize_t>(sizeof(wake)) && errno != EAGAIN)
    REXSYS_ERROR("XSocket: cancellation wake failed socket={}", state->handle);
#elif REX_PLATFORM_MAC
  // One byte that is never drained: the pipe stays readable (sticky wake),
  // like the Linux eventfd counter.
  const uint8_t wake = 1;
  ssize_t written;
  do { written = ::write(state->cancellation_write, &wake, sizeof(wake)); }
  while (written < 0 && errno == EINTR);
  if (written != static_cast<ssize_t>(sizeof(wake)) && errno != EAGAIN)
    REXSYS_ERROR("XSocket: cancellation wake failed socket={}", state->handle);
#endif
#if REX_PLATFORM_WIN32
  // One datagram to itself; it is never drained, so the wake stays sticky
  // for any later wait on this retired state, like the Linux eventfd.
  if (state->wake != uint64_t(-1) &&
      ::sendto(static_cast<SOCKET>(state->wake), "", 1, 0,
               reinterpret_cast<const sockaddr*>(&state->wake_address),
               sizeof(state->wake_address)) != 1)
    REXSYS_ERROR("XSocket: wake socket poke failed socket={} error={}", state->handle,
                 WSAGetLastError());
#endif
  // Never acquire native_receive_mutex_: a blocking receive may own it.
  // Linux shutdown wakes even an unconnected UDP receive (ENOTCONN is benign).
  // The cancellation descriptor independently wakes poll/select waiters.
  shutdown(state->handle,
#if REX_PLATFORM_WIN32
           SD_BOTH
#else
           SHUT_RDWR
#endif
  );
  // NAT's raw XSocket pump references must drain while this object is live.
  // Doing this in the last operation's destructor would wait for that very pump.
  xam::NatProbeDetach(state->handle);
  if (state.use_count() == 1)
    return state->Finalize() == 0 ? X_STATUS_SUCCESS : X_STATUS_UNSUCCESSFUL;
  return X_STATUS_SUCCESS;  // Last lease retires the descriptor and scope.
}

X_STATUS XSocket::SetOption(uint32_t level, uint32_t optname, void* optval_ptr, uint32_t optlen) {
  const auto operation = AcquireNativeLease();
  if (!operation) return X_STATUS_UNSUCCESSFUL;
  const auto handle = operation.handle();
  if (level == 0xFFFF && (optname == 0x5801 || optname == 0x5802)) {
    // Disable socket encryption
    secure_ = false;
    return X_STATUS_SUCCESS;
  }

#if REX_PLATFORM_WIN32
  int ret = setsockopt(handle, level, optname, (char*)optval_ptr, optlen);
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
    ret = setsockopt(handle, native_level, native_option, &native_linger,
                     sizeof(native_linger));
  } else if (native_option == SO_SNDTIMEO || native_option == SO_RCVTIMEO) {
    timeval native_timeout{static_cast<time_t>(value / 1000),
                           static_cast<suseconds_t>((value % 1000) * 1000)};
    ret = setsockopt(handle, native_level, native_option, &native_timeout,
                     sizeof(native_timeout));
  } else {
    if (!boolean && value > INT_MAX) {
      errno = EINVAL;
      return X_STATUS_UNSUCCESSFUL;
    }
    int native_value = boolean ? int(value != 0) : int(value);
    ret = setsockopt(handle, native_level, native_option, &native_value,
                     sizeof(native_value));
#if REX_PLATFORM_MAC
    // Linux (and Winsock) let SO_REUSEADDR datagram sockets share a bound
    // port; BSD requires SO_REUSEPORT for that. Mirror the option.
    if (ret == 0 && native_level == SOL_SOCKET && native_option == SO_REUSEADDR &&
        type_ == X_SOCK_DGRAM)
      ret = setsockopt(handle, SOL_SOCKET, SO_REUSEPORT, &native_value, sizeof(native_value));
#endif
  }
#endif
  REXSYS_INFO("XSocket::SetOption: native={} level={:#x} option={:#x} length={} result={}",
              handle, level, optname, optlen, ret);
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
  const auto operation = AcquireNativeLease();
  if (!operation) return X_STATUS_UNSUCCESSFUL;
  const auto handle = operation.handle();
#if REX_PLATFORM_WIN32
  int ret = rex::net::socket_ioctl(handle, cmd, arg_ptr);
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
#if REX_PLATFORM_MAC
  // Linux FIONREAD on a datagram socket reports the next datagram's size;
  // Darwin's reports every queued byte. SO_NREAD gives the Linux value.
  int ret;
  if (type_ == X_SOCK_DGRAM) {
    socklen_t available_length = sizeof(available);
    ret = getsockopt(handle, SOL_SOCKET, SO_NREAD, &available, &available_length);
  } else {
    ret = ioctl(handle, FIONREAD, &available);
  }
#else
  int ret = ioctl(handle, FIONREAD, &available);
#endif
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
  const auto operation = AcquireNativeLease();
  if (!operation) return X_STATUS_UNSUCCESSFUL;
  const auto handle = operation.handle();
  std::lock_guard configuration_lock(native_configuration_mutex_);
  if (operation.retired()) { ClosedNativeSocket(); return X_STATUS_UNSUCCESSFUL; }
#if REX_PLATFORM_WIN32
  u_long value = enabled ? 1 : 0;
  return ioctlsocket(static_cast<SOCKET>(handle), FIONBIO, &value) == 0
             ? X_STATUS_SUCCESS
             : X_STATUS_UNSUCCESSFUL;
#else
  int flags = fcntl(static_cast<int>(handle), F_GETFL, 0);
  if (flags < 0)
    return X_STATUS_UNSUCCESSFUL;
  int updated = enabled ? (flags | O_NONBLOCK) : (flags & ~O_NONBLOCK);
  return fcntl(static_cast<int>(handle), F_SETFL, updated) == 0 ? X_STATUS_SUCCESS
                                                                       : X_STATUS_UNSUCCESSFUL;
#endif
}

X_STATUS XSocket::Connect(N_XSOCKADDR* name, int name_len) {
  const auto operation = AcquireNativeLease();
  if (!operation) return X_STATUS_UNSUCCESSFUL;
  const auto handle = operation.handle();
  int ret;
#if REX_PLATFORM_MAC
  sockaddr_storage native_name{};
  socklen_t native_name_length = 0;
  if (!StageNativeSockaddr(name, name_len, native_name, native_name_length))
    return X_STATUS_UNSUCCESSFUL;
#endif
#if REX_PLATFORM_POSIX_ONLINE
  // UDP only associates an address: no handshake or blocking connect wait,
  // and no native mode change. Connected/listening TCP also needs no handshake.
  sockaddr_storage peer{}; socklen_t peer_length = sizeof(peer);
  int listening = 0; socklen_t listening_length = sizeof(listening);
  const bool association_only = type_ == X_SOCK_DGRAM ||
      getpeername(handle, reinterpret_cast<sockaddr*>(&peer), &peer_length) == 0 ||
      (getsockopt(handle, SOL_SOCKET, SO_ACCEPTCONN, &listening, &listening_length) == 0 && listening);
  bool blocking = false;
  int error;
  if (association_only) {
    if (operation.retired()) { ClosedNativeSocket(); return X_STATUS_UNSUCCESSFUL; }
#if REX_PLATFORM_MAC
    ret = connect(handle, reinterpret_cast<sockaddr*>(&native_name), native_name_length);
#else
    ret = connect(handle, reinterpret_cast<sockaddr*>(name), name_len);
#endif
    error = errno;
  } else {
    // connect has no per-call MSG_DONTWAIT. Exclude native send/receive entry
    // only for the short forced-nonblocking syscall, restoring flags BEFORE
    // waiting. Ordinary FIONBIO remains prompt during a blocked receive.
    // Never wait indefinitely behind a concurrent operation on a pending TCP
    // connection: the caller may retry after this EALREADY completion.
    std::unique_lock connect_window(native_connect_window_mutex_, std::try_to_lock);
    if (!connect_window.owns_lock()) {
      if (operation.retired()) ClosedNativeSocket(); else errno = EALREADY;
      return X_STATUS_UNSUCCESSFUL;
    }
    std::lock_guard configuration_lock(native_configuration_mutex_);
    if (operation.retired()) { ClosedNativeSocket(); return X_STATUS_UNSUCCESSFUL; }
    const int original_flags = fcntl(handle, F_GETFL, 0);
    if (original_flags < 0) return X_STATUS_UNSUCCESSFUL;
    blocking = !(original_flags & O_NONBLOCK);
    if (blocking && fcntl(handle, F_SETFL, original_flags | O_NONBLOCK) < 0)
      return X_STATUS_UNSUCCESSFUL;
#if REX_PLATFORM_MAC
    ret = connect(handle, reinterpret_cast<sockaddr*>(&native_name), native_name_length);
#else
    ret = connect(handle, reinterpret_cast<sockaddr*>(name), name_len);
#endif
    error = errno;
    if (blocking && fcntl(handle, F_SETFL, original_flags) < 0) {
      error = errno; ret = -1; blocking = false;
    }
  }
  if (blocking && ret < 0 && error == EINPROGRESS && !operation.retired()) {
    std::array<pollfd, 2> descriptors{{{static_cast<int>(handle), POLLOUT, 0},
                                    {operation.cancellation_handle(), POLLIN, 0}}};
    // Linux connect's socket send timeout must remain a finite guest contract.
    timeval send_timeout{}; socklen_t length = sizeof(send_timeout);
    if (getsockopt(handle, SOL_SOCKET, SO_SNDTIMEO, &send_timeout, &length) < 0) {
      error = errno;
    } else {
      const bool timed = send_timeout.tv_sec || send_timeout.tv_usec;
      const auto duration = std::chrono::seconds(send_timeout.tv_sec) +
                            std::chrono::microseconds(send_timeout.tv_usec);
      const auto deadline = std::chrono::steady_clock::now() + duration;
      for (;;) {
        timespec remaining{}; const timespec* wait = nullptr;
        if (timed) {
          const auto left = deadline - std::chrono::steady_clock::now();
          if (left <= decltype(left)::zero()) { error = EINPROGRESS; break; }
          const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(left);
          remaining.tv_sec = seconds.count();
          remaining.tv_nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(left - seconds).count();
          wait = &remaining;
        }
#if REX_PLATFORM_MAC
        const int ready = rex::net::mac::PollTimespec(descriptors.data(), descriptors.size(), wait);
#else
        const int ready = ppoll(descriptors.data(), descriptors.size(), wait, nullptr);
#endif
        if (operation.retired()) { error = ENOTSOCK; break; }
        if (ready < 0) { error = errno; break; }
        if (!ready) { error = EINPROGRESS; break; }
        int connected_error = 0; length = sizeof(connected_error);
        if (getsockopt(handle, SOL_SOCKET, SO_ERROR, &connected_error, &length) < 0)
          error = errno;
        else { error = connected_error; ret = connected_error ? -1 : 0; }
        break;
      }
    }
  }
  if (operation.retired()) { error = ENOTSOCK; ret = -1; }
  errno = error;
#else
  ret = connect(handle, reinterpret_cast<sockaddr*>(name), name_len);
  if (operation.retired()) { ClosedNativeSocket(); ret = -1; }
#endif
  REXSYS_INFO("XSocket::Connect: native={} family={} length={} result={}", handle,
              name ? name->address_family : 0, name_len, ret);
  return ret < 0 ? X_STATUS_UNSUCCESSFUL : X_STATUS_SUCCESS;
}

X_STATUS XSocket::Bind(N_XSOCKADDR_IN* name, int name_len) {
  const auto operation = AcquireNativeLease();
  if (!operation) return X_STATUS_UNSUCCESSFUL;
  const auto handle = operation.handle();
#if REX_PLATFORM_MAC
  sockaddr_storage native_name{};
  socklen_t native_name_length = 0;
  if (!StageNativeSockaddr(name, name_len, native_name, native_name_length))
    return X_STATUS_UNSUCCESSFUL;
  int ret = bind(handle, reinterpret_cast<sockaddr*>(&native_name), native_name_length);
#else
  int ret = bind(handle, (sockaddr*)name, name_len);
#endif
  if (ret < 0) {
    return X_STATUS_UNSUCCESSFUL;
  }

  std::lock_guard lifetime_lock(native_lifetime_mutex_);
  if (operation.retired()) { ClosedNativeSocket(); return X_STATUS_UNSUCCESSFUL; }
  bound_ = true;
  sockaddr_in actual_address{};
  socklen_t actual_length = sizeof(actual_address);
  if (getsockname(handle, reinterpret_cast<sockaddr*>(&actual_address), &actual_length) ==
      0) {
    // Keep the native/network-order value used by sockaddr. This is especially
    // important for port 0, where the OS selects the real guest transport port.
    bound_port_ = actual_address.sin_port;
    REXSYS_INFO("XSocket::Bind: native={} local={:08X}:{}", handle,
                ntohl(actual_address.sin_addr.s_addr), ntohs(actual_address.sin_port));
    if (type_ == Type::X_SOCK_DGRAM &&
        xam::NatProbeIsGameplayPort(ntohs(actual_address.sin_port))) {
      xam::NatProbeAttach(handle, xam::NatProbeRole::kGameplay,
                          {actual_address.sin_addr.s_addr, ntohs(actual_address.sin_port)}, this);
      if (auto* manager = kernel_state() ? kernel_state()->session_manager() : nullptr) {
        const auto local_xuid = kernel_state()->user_profile()->xuid();
        xam::RegisterGameplaySocketCandidate(local_xuid, handle,
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
          xam::BindGameplaySocket(exact, local_xuid, handle,
                                  guest_port_ ? guest_port_ : ntohs(actual_address.sin_port));
      }
    }
  } else {
    bound_port_ = name->sin_port;
    REXSYS_ERROR("XSocket::Bind: getsockname failed native={} error={}", handle,
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
  const auto operation = AcquireNativeLease();
  if (!operation) return X_STATUS_UNSUCCESSFUL;
  const auto handle = operation.handle();
  int ret = listen(handle, backlog);
  if (ret < 0) {
    return X_STATUS_UNSUCCESSFUL;
  }

  return X_STATUS_SUCCESS;
}

object_ref<XSocket> XSocket::Accept(N_XSOCKADDR* name, int* name_len) {
  const auto operation = AcquireNativeLease();
  if (!operation) return nullptr;
  const auto handle = operation.handle();
  std::shared_lock connect_window(native_connect_window_mutex_);
  if (operation.retired()) { ClosedNativeSocket(); return nullptr; }
  sockaddr n_sockaddr;
  socklen_t n_name_len = sizeof(sockaddr);
#if REX_PLATFORM_MAC
  uintptr_t ret = MacAccept(int(handle), operation.cancellation_handle(),
                            [&] { return operation.retired(); }, &n_sockaddr, &n_name_len);
#else
  uintptr_t ret =
#if REX_PLATFORM_GNU_LINUX
      accept4(handle, &n_sockaddr, &n_name_len, SOCK_CLOEXEC);
#else
      accept(handle, &n_sockaddr, &n_name_len);
#endif
#endif
#if REX_PLATFORM_MAC
  // accept4(SOCK_CLOEXEC) and MSG_NOSIGNAL stand-ins for the accepted socket.
  if (ret != uintptr_t(-1) && !rex::net::mac::ConfigureSocketDescriptor(int(ret))) {
    const int error = errno;
    rex::net::socket_close(ret);
    errno = error;
    ret = uintptr_t(-1);
  }
#endif
  if (operation.retired()) {
    if (ret != uintptr_t(-1)) rex::net::socket_close(ret);
    ClosedNativeSocket();
    return nullptr;
  }
  if (ret == uintptr_t(-1)) {
    std::memset(name, 0, *name_len);
    *name_len = 0;
    return nullptr;
  }

  // Prepare ownership before allocating the guest object: even a throwing
  // XObject base constructor cannot leak an accepted native descriptor.
  std::shared_ptr<NativeSocketState> child_state;
  try { child_state = std::make_shared<NativeSocketState>(ret); }
  catch (const std::bad_alloc&) {
    rex::net::socket_close(ret);
#if REX_PLATFORM_WIN32
    WSASetLastError(WSAENOBUFS);
#else
    errno = ENOMEM;
#endif
    return nullptr;
  }
  if (!child_state->valid()) return nullptr;
  object_ref<XSocket> child;
  try { child = object_ref<XSocket>(new XSocket(kernel_state_, std::move(child_state))); }
  catch (const std::bad_alloc&) {
#if REX_PLATFORM_WIN32
    WSASetLastError(WSAENOBUFS);
#else
    errno = ENOMEM;
#endif
    return nullptr;
  }
  child->af_ = af_; child->type_ = type_; child->proto_ = proto_;
  {
    // Linearize accepted-child publication against Close, without holding the
    // parent's lifetime lock during child construction/object-table access.
    std::lock_guard lifetime_lock(native_lifetime_mutex_);
    if (!operation.retired()) {
      std::memcpy(name, &n_sockaddr, n_name_len);
#if REX_PLATFORM_MAC
      PublishNativeSockaddr(n_sockaddr, name);
#endif
      *name_len = n_name_len;
      return child;
    }
  }
  child->Close();
  if (kernel_state_) child->ReleaseHandle();
  ClosedNativeSocket();
  return nullptr;
}

int XSocket::Shutdown(int how) {
  const auto operation = AcquireNativeLease();
  if (!operation) return -1;
  const auto handle = operation.handle();
  return shutdown(handle, how);
}

int XSocket::Recv(uint8_t* buf, uint32_t buf_len, uint32_t flags) {
  const auto operation = AcquireNativeLease();
  if (!operation) return -1;
  if (type_ == X_SOCK_DGRAM)
    return RecvFromNative(operation, buf, buf_len, flags, nullptr, nullptr);
  const auto handle = operation.handle();
  std::shared_lock connect_window(native_connect_window_mutex_);
  if (operation.retired()) return ClosedNativeSocket();
#if REX_PLATFORM_GNU_LINUX
  const int result = recv(handle, reinterpret_cast<char*>(buf), buf_len,
                           flags | (type_ == X_SOCK_DGRAM ? MSG_TRUNC : 0));
  if (operation.retired()) return ClosedNativeSocket();
  if (result > 0 && uint32_t(result) > buf_len) {
    errno = EMSGSIZE;
    return -1;
  }
  return result;
#else
  return recv(handle, reinterpret_cast<char*>(buf), buf_len, flags);
#endif
}

int XSocket::RecvFrom(uint8_t* buf, uint32_t buf_len, uint32_t flags, N_XSOCKADDR_IN* from,
                      uint32_t* from_len) {
  const auto operation = AcquireNativeLease();
  if (!operation) return -1;
  return RecvFromNative(operation, buf, buf_len, flags, from, from_len);
}

int XSocket::RecvFromNative(const NativeLease& operation, uint8_t* buf, uint32_t buf_len,
                            uint32_t flags, N_XSOCKADDR_IN* from, uint32_t* from_len) {
  const auto handle = operation.handle();
  std::lock_guard receive_lock(native_receive_mutex_);
  std::shared_lock connect_window(native_connect_window_mutex_);
  if (operation.retired()) return ClosedNativeSocket();
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

  // Native IPv4 UDP cannot exceed 65535 bytes. Stage datagrams on the host
  // so control, pending, unknown and revoked peers never write guest memory.
  // Stage ordinary UDP too: membership may become scoped during this receive.
  // Keep a complete56-byte NAT control frame plus one oversize byte, even
  // when the guest requests fewer bytes or only polls with a zero-length buffer.
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  // Membership may become scoped while a receive is blocked. Always retain
  // the complete bounded wire datagram so that a fitting plaintext is not lost.
  const uint32_t receive_capacity = type_ == X_SOCK_DGRAM ? 65536u : buf_len;
  std::vector<uint8_t> receive_storage(type_ == X_SOCK_DGRAM ? receive_capacity : 0);
  uint8_t* receive_data = type_ == X_SOCK_DGRAM ? receive_storage.data() : buf;
#else
  // Other platforms retain their native direct-buffer contract until qualified.
  const uint32_t receive_capacity = buf_len;
  uint8_t* receive_data = buf;
#endif
  std::vector<uint8_t> authenticated_plaintext;
  auto copy_received = [&](size_t count) {
    if (!count || type_ != X_SOCK_DGRAM) return true;
#if REX_PLATFORM_GNU_LINUX
    // A userspace memcpy would turn a native EFAULT into a host crash or bypass
    // kernel partial-write semantics. Copy only within this exact process.
    iovec local{receive_data, count}, remote{buf, count};
    const auto written = process_vm_writev(getpid(), &local, 1, &remote, 1, 0);
    if (written == static_cast<ssize_t>(count)) return true;
    FailSocket(EFAULT);
    return false;
#elif REX_PLATFORM_MAC
    // Mirror process_vm_writev: a bad guest pointer fails as EFAULT, never faults.
    if (rex::net::mac::WriteSelf(buf, receive_data, count)) return true;
    FailSocket(EFAULT);
    return false;
#elif REX_PLATFORM_WIN32
    // Mirror process_vm_writev: a bad guest pointer fails as EFAULT, never faults.
    SIZE_T written = 0;
    if (WriteProcessMemory(GetCurrentProcess(), buf, receive_data, count, &written) && written == count)
      return true;
    FailSocket(EFAULT);
    return false;
#else
    return true;
#endif
  };
  uint32_t filtered_datagrams = 0;
  auto reject_datagram = [&] {
    // Protocol/control or unadmitted bytes are invisible to guest MSG_PEEK.
    // Consume the already inspected datagram rather than peeking it forever.
    if (flags & MSG_PEEK) {
      const int discarded = recvfrom(handle, reinterpret_cast<char*>(receive_data), receive_capacity,
                                    flags & ~MSG_PEEK, nullptr, nullptr);
      if (discarded < 0) {
#if REX_PLATFORM_WIN32
        if (WSAGetLastError() != WSAEMSGSIZE) return false;
#else
        if (errno != EMSGSIZE) return false;
#endif
      }
    }
    // A sustained control/hostile queue must not monopolize the receive lock.
    if (++filtered_datagrams < 32) return true;
#if REX_PLATFORM_WIN32
    WSASetLastError(WSAEWOULDBLOCK);
#else
    errno = EWOULDBLOCK;
#endif
    return false;
  };

retry_native_receive:
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  if (type_ == X_SOCK_DGRAM) receive_data = receive_storage.data();
#endif
  if (operation.retired()) return ClosedNativeSocket();
  xam::NatProbeTick(handle);
  sockaddr_in nfrom{};
  socklen_t nfromlen = sizeof(sockaddr_in);
#if REX_PLATFORM_MAC
  // The 64 KiB staging buffer holds any IPv4 datagram, so no MSG_TRUNC probe
  // is needed. A blocking datagram receive must still observe Close.
  int ret = type_ == X_SOCK_DGRAM
      ? MacDatagramReceive(int(handle), operation.cancellation_handle(),
                           [&] { return operation.retired(); }, receive_data, receive_capacity,
                           int(flags), (sockaddr*)&nfrom, &nfromlen)
      : int(recvfrom(handle, reinterpret_cast<char*>(receive_data), receive_capacity, flags,
                     (sockaddr*)&nfrom, &nfromlen));
#else
  int ret = recvfrom(handle, reinterpret_cast<char*>(receive_data), receive_capacity,
#if REX_PLATFORM_GNU_LINUX
                     flags | (type_ == X_SOCK_DGRAM ? MSG_TRUNC : 0),
#else
                     flags,
#endif
                     (sockaddr*)&nfrom, &nfromlen);
#endif
  if (operation.retired()) return ClosedNativeSocket();
  if (ret < 0) return ret;
  if (ret > 0 && uint32_t(ret) <= receive_capacity &&
      xam::NatProbeConsume(handle, receive_data, ret, nfrom.sin_addr.s_addr,
                                      ntohs(nfrom.sin_port))) {
    if (!reject_datagram()) return -1;
    goto retry_native_receive;
  }
  if (ret >= 0 && xam::NatProbeIsPendingGameplaySource(handle,
          {nfrom.sin_addr.s_addr, ntohs(nfrom.sin_port)})) {
    if (!reject_datagram()) return -1;
    goto retry_native_receive;
  }
  const uint16_t source_port = ret >= 0 ? ntohs(nfrom.sin_port) : 0;
  const xam::LanAddress native_source{ret >= 0 ? nfrom.sin_addr.s_addr : 0, source_port};
  // Reap expired/revoked membership before consulting its native route.
  const bool scoped = xam::IsAuthorizedGameplaySocket(handle);
  std::optional<xam::LanAddress> logical;
  if (ret >= 0) {
    logical = xam::NatProbeNormalizeGameplaySource(handle, native_source);
    if (scoped && !logical) {
      if (!reject_datagram()) return -1;
      goto retry_native_receive;
    }
  }
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  if (scoped && type_ == X_SOCK_DGRAM) {
    if (!logical || uint32_t(ret) > receive_capacity ||
        !xam::OpenGameplayDatagram(handle, *logical,
            std::span<const uint8_t>(receive_data, size_t(ret)), authenticated_plaintext,
            !(flags & MSG_PEEK))) {
      if (!reject_datagram()) return -1;
      goto retry_native_receive;
    }
    // Authentication and replay admission precede any guest-visible bytes.
    ret = int(authenticated_plaintext.size());
    receive_data = authenticated_plaintext.data();
  }
  if (ret > 0 && uint32_t(ret) > buf_len) {
    // Preserve ordinary Winsock-style truncation, but scoped errors expose no bytes.
    if (type_ == X_SOCK_DGRAM && !scoped && buf_len &&
        !copy_received(std::min<uint32_t>(buf_len, uint32_t(ret)))) return -1;
    FailSocket(EMSGSIZE);
    return -1;
  }
#endif
  if (operation.retired()) return ClosedNativeSocket();
  if (ret > 0 && !copy_received(size_t(ret))) return -1;
  if (ret >= 0 && from) {
    from->sin_family = nfrom.sin_family;
    if (logical) {
      xam::NatProbeRecordGameplayTraffic(handle, native_source, size_t(ret), false);
      // Present the peer by the address the guest addressed it with, so a
      // title that keyed the host by its session endpoint accepts the reply.
      const auto alias = xam::GameplayGuestSourceAlias(handle, *logical);
      from->sin_addr = ntohl(alias.value_or(logical->ipv4));
      from->sin_port = logical->port;
      if (last_normalized_source_ipv4_ != native_source.ipv4 ||
          last_normalized_source_port_ != native_source.port) {
        REXSYS_INFO(
            "NAT traversal: inbound gameplay source normalized native={:08X}:{} guest={:08X}:{} alias={:08X}",
            native_source.ipv4, native_source.port, logical->ipv4, logical->port, alias.value_or(0));
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
  const auto operation = AcquireNativeLease();
  if (!operation) return false;
  const auto handle = operation.handle();
  std::lock_guard receive_lock(native_receive_mutex_);
  if (!WaitReadableNative(operation, 0, false)) return false;

  // One extra byte distinguishes an exact control frame from a valid-looking
  // prefix of an oversized datagram on both POSIX and Winsock peek paths.
  std::array<uint8_t, 57> packet{};
  sockaddr_in source{};
  socklen_t source_length = sizeof(source);
  const int peeked = recvfrom(handle, reinterpret_cast<char*>(packet.data()),
                              int(packet.size()), MSG_PEEK
#if REX_PLATFORM_POSIX_ONLINE
                              | MSG_DONTWAIT
#endif
                              ,
                              reinterpret_cast<sockaddr*>(&source), &source_length);
  if (operation.retired() || peeked <= 0 ||
      !xam::NatProbeIsControlPacket(handle, packet.data(), size_t(peeked),
                                    source.sin_addr.s_addr, ntohs(source.sin_port)))
    return false;

  source_length = sizeof(source);
  const int received = recvfrom(handle, reinterpret_cast<char*>(packet.data()),
                                int(packet.size()),
#if REX_PLATFORM_POSIX_ONLINE
                                MSG_DONTWAIT,
#else
                                0,
#endif
                                reinterpret_cast<sockaddr*>(&source), &source_length);
  const bool consumed =
      !operation.retired() && received > 0 && xam::NatProbeConsume(handle, packet.data(), size_t(received),
                                           source.sin_addr.s_addr, ntohs(source.sin_port));
  if (consumed)
    REXSYS_INFO("NAT traversal: independent gameplay control receive socket={} type={} "
                "source={:08X}:{}",
                handle, packet[5], source.sin_addr.s_addr, ntohs(source.sin_port));
  return consumed;
}

bool XSocket::WaitReadable(uint32_t timeout_ms, bool infinite) const {
  const auto operation = AcquireNativeLease();
  return operation && WaitReadableNative(operation, timeout_ms, infinite);
}

bool XSocket::WaitReadableNative(const NativeLease& operation, uint32_t timeout_ms, bool infinite) const {
  if (operation.retired()) return false;
  const auto handle = operation.handle();
#if !REX_PLATFORM_WIN32
  std::array<pollfd, 2> pending{{{static_cast<int>(handle), POLLIN, 0},
                               {operation.cancellation_handle(), POLLIN, 0}}};
  // poll has a signed millisecond timeout. Split unusually long finite waits
  // without turning them into an infinite wait or overflowing an int.
  uint32_t remaining = timeout_ms;
  for (;;) {
    const int interval = infinite ? -1 : static_cast<int>(std::min<uint32_t>(remaining, INT_MAX));
    const int result = poll(pending.data(), pending.size(), interval);
    if (result != 0 || infinite || remaining <= uint32_t(INT_MAX))
      return !operation.retired() && result > 0 &&
             !(pending[1].revents & (POLLIN | POLLHUP | POLLERR | POLLNVAL)) &&
             (pending[0].revents & (POLLIN | POLLHUP | POLLERR));
    remaining -= uint32_t(INT_MAX);
  }
#else
  fd_set read_set;
  FD_ZERO(&read_set);
#if REX_PLATFORM_WIN32
  auto native_socket = static_cast<SOCKET>(handle);
#else
  auto native_socket = static_cast<int>(handle);
#endif
  FD_SET(native_socket, &read_set);
#if REX_PLATFORM_WIN32
  const auto wake_socket = static_cast<SOCKET>(operation.wake_handle());
  if (wake_socket != INVALID_SOCKET) FD_SET(wake_socket, &read_set);
#endif
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
          available, handle);
    }
  }
#endif
  if (result < 0) {
    REXSYS_ERROR("XSocket::WaitReadable: select failed native={} error={}", handle,
#if REX_PLATFORM_WIN32
                 WSAGetLastError()
#else
                 errno
#endif
    );
  }
#if REX_PLATFORM_WIN32
  if (wake_socket != INVALID_SOCKET && result > 0 && FD_ISSET(wake_socket, &read_set)) return false;
#endif
  return !operation.retired() && result > 0 && FD_ISSET(native_socket, &read_set);
#endif
}

int XSocket::Send(const uint8_t* buf, uint32_t buf_len, uint32_t flags) {
  const auto operation = AcquireNativeLease();
  if (!operation) return -1;
  const auto handle = operation.handle();
  std::shared_lock connect_window(native_connect_window_mutex_);
  if (operation.retired()) return ClosedNativeSocket();
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  if (type_ == X_SOCK_DGRAM && xam::IsAuthorizedGameplaySocket(handle)) {
    sockaddr_in native{}; socklen_t length = sizeof(native);
    if (getpeername(handle, reinterpret_cast<sockaddr*>(&native), &length) < 0) { FailSocket(EDESTADDRREQ); return -1; }
    const auto logical = xam::NatProbeNormalizeGameplaySource(handle,
        {native.sin_addr.s_addr, ntohs(native.sin_port)});
    if (!logical) { FailSocket(EWOULDBLOCK); return -1; }
    auto wire = ProtectedGameplayWire(handle, *logical, buf, buf_len);
    if (!wire) return -1;
    if (operation.retired()) return ClosedNativeSocket();
    const int sent = send(handle, reinterpret_cast<const char*>(wire->data()), int(wire->size()), flags | kNoSignal);
    if (sent < 0) return -1;
    if (size_t(sent) != wire->size()) { FailSocket(EMSGSIZE); return -1; }
    return int(buf_len);
  }
#endif
  return send(handle, reinterpret_cast<const char*>(buf), buf_len, flags
#if REX_PLATFORM_GNU_LINUX
              | MSG_NOSIGNAL
#endif
              );
}

int XSocket::SendTo(uint8_t* buf, uint32_t buf_len, uint32_t flags, N_XSOCKADDR_IN* to,
                    uint32_t to_len) {
  const auto operation = AcquireNativeLease();
  if (!operation) return -1;
  const auto handle = operation.handle();
  std::shared_lock connect_window(native_connect_window_mutex_);
  if (operation.retired()) return ClosedNativeSocket();
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  // Validate the complete IPv4 destination before routing or burning a nonce.
  // Never pass an untrusted length for our fixed-size native stack object.
  N_XSOCKADDR_IN staged_to{};
  if ((!to && to_len != 0) || (to && to_len != sizeof(staged_to))) {
    FailSocket(EINVAL);
    return -1;
  }
  if (to) {
#if REX_PLATFORM_GNU_LINUX
    iovec local{&staged_to, sizeof(staged_to)}, remote{to, sizeof(staged_to)};
    if (process_vm_readv(getpid(), &local, 1, &remote, 1, 0) != ssize_t(sizeof(staged_to))) {
      FailSocket(EFAULT);
      return -1;
    }
#elif REX_PLATFORM_MAC
    if (!rex::net::mac::ReadSelf(&staged_to, to, sizeof(staged_to))) {
      FailSocket(EFAULT);
      return -1;
    }
#else
    SIZE_T copied = 0;
    if (!ReadProcessMemory(GetCurrentProcess(), to, &staged_to, sizeof(staged_to), &copied) ||
        copied != sizeof(staged_to)) {
      FailSocket(EFAULT);
      return -1;
    }
#endif
    if (uint16_t(staged_to.sin_family) != AF_INET) {
      FailSocket(EAFNOSUPPORT);
      return -1;
    }
    to = &staged_to;
  }
#endif

  xam::NatProbeTick(handle);
  sockaddr_in nto{};
  std::optional<xam::LanAddress> protected_logical;
  if (to) {
    // N_XSOCKADDR_IN exposes logical host-order values through endian_store,
    // while sockaddr_in requires network-order integer storage.
    nto.sin_addr.s_addr = htonl(uint32_t(to->sin_addr));
    nto.sin_family = to->sin_family;
    const uint16_t destination_port =
        native_port_ != 0 && uint16_t(to->sin_port) == guest_port_ ? native_port_
                                                                   : uint16_t(to->sin_port);
    nto.sin_port = htons(destination_port);
    if (xam::IsAuthorizedGameplaySocket(handle)) {
      auto logical = xam::GameplayLogicalDestination(handle,
          {nto.sin_addr.s_addr, uint16_t(to->sin_port)});
      auto peer = logical ? xam::NatProbeGameplayDestination(handle, *logical) : std::nullopt;
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
        protected_logical = logical;
      }
    } else if (xam::IsGameplayLogicalAddress(nto.sin_addr.s_addr)) {
#if REX_PLATFORM_WIN32
      WSASetLastError(WSAEHOSTUNREACH);
#else
      errno = EHOSTUNREACH;
#endif
      return -1;
    } else if (auto peer = xam::NatProbePeer(handle)) {
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

#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  if (type_ == X_SOCK_DGRAM && xam::IsAuthorizedGameplaySocket(handle)) {
    if (!to) {
      socklen_t length = sizeof(nto);
      if (getpeername(handle, reinterpret_cast<sockaddr*>(&nto), &length) < 0) { FailSocket(EDESTADDRREQ); return -1; }
      protected_logical = xam::NatProbeNormalizeGameplaySource(handle,
          {nto.sin_addr.s_addr, ntohs(nto.sin_port)});
    }
    if (!protected_logical) { FailSocket(EWOULDBLOCK); return -1; }
    auto wire = ProtectedGameplayWire(handle, *protected_logical, buf, buf_len);
    if (!wire) return -1;
    if (operation.retired()) return ClosedNativeSocket();
    const int sent = sendto(handle, reinterpret_cast<const char*>(wire->data()), int(wire->size()), flags | kNoSignal,
                           to ? reinterpret_cast<sockaddr*>(&nto) : nullptr,
                           to ? int(sizeof(nto)) : 0);
    if (sent < 0) return -1;
    if (size_t(sent) != wire->size()) { FailSocket(EMSGSIZE); return -1; }
    xam::NatProbeRecordGameplayTraffic(handle,
        {nto.sin_addr.s_addr, ntohs(nto.sin_port)}, buf_len, true);
    return int(buf_len);
  }
#endif
  const int result = sendto(handle, reinterpret_cast<char*>(buf), buf_len, flags
#if REX_PLATFORM_GNU_LINUX
                | MSG_NOSIGNAL
#endif
                , to ? (sockaddr*)&nto : nullptr,
#if REX_PLATFORM_POSIX_ONLINE
                  to ? sizeof(nto) : 0);
#else
                  to_len);
#endif
  if (result > 0 && to)
    xam::NatProbeRecordGameplayTraffic(handle,
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
