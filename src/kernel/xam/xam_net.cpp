/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2022 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

// Disable warnings about unused parameters for kernel functions
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <mutex>
#include <new>
#include <span>
#include <thread>
#include <unordered_map>
#include "pending_socket_sends_lifetime.h"

#if REX_PLATFORM_MAC
#include <sys/select.h>
#endif

#include <rex/chrono/clock.h>
#include <rex/kernel/xam/module.h>
#include <rex/kernel/xam/private.h>
#include <rex/kernel/xboxkrnl/error.h>
#include <rex/kernel/xboxkrnl/threading.h>
#include <rex/logging.h>
#include <rex/hook.h>
#include <rex/types.h>
#include <rex/string.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xevent.h>
#include <rex/system/xam/session.h>
#include <rex/system/xam/session_arbitration_guest.h>
#include <rex/memory/mapping_lease.h>
#include <rex/system/xam/gameplay_traversal.h>
#include <rex/system/xsocket.h>
#include <rex/system/xthread.h>
#include <rex/system/xtypes.h>

#if REX_PLATFORM_WIN32
// NOTE: must be included last as it expects windows.h to already be included.
#define _WINSOCK_DEPRECATED_NO_WARNINGS  // inet_addr
#include <winsock2.h>                    // NOLINT(build/include_order)
#elif REX_PLATFORM_LINUX || REX_PLATFORM_MAC
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <poll.h>
#include <sys/socket.h>
#if REX_PLATFORM_LINUX
#include <sys/uio.h>
#include <unistd.h>
#endif
#endif

namespace rex {
namespace kernel {
namespace xam {
using namespace rex::system;
using namespace rex::system::xam;

namespace {
// Bounded diagnostics for one owned guest socket incarnation. These retain no
// object, native descriptor, guest buffer, payload or credentials.
enum BootstrapResultBit : uint8_t {
  kBootstrapSendFailure = 1,
  kBootstrapReceiveFailure = 2,
  kBootstrapReceivePending = 4,
};
struct BootstrapSocketResults { uint32_t handle = 0; uint8_t reported = 0; };
std::mutex bootstrap_result_mutex;
std::array<BootstrapSocketResults, 128> bootstrap_socket_results{};

uint32_t BootstrapGuestLinkRegister() {
  if (!XThread::IsInThread()) return 0;
  auto* thread = XThread::GetCurrentThread();
  auto* state = thread ? thread->thread_state() : nullptr;
  const auto* context = state ? state->context() : nullptr;
  return context ? static_cast<uint32_t>(context->lr) : 0;
}

void ReportBootstrapSocketResult(const char* api, uint32_t caller, uint32_t handle,
                                uint32_t error, const char* stage, uint8_t bit) {
  bool report = false;
  {
    std::lock_guard lock(bootstrap_result_mutex);
    auto found = std::find_if(bootstrap_socket_results.begin(), bootstrap_socket_results.end(),
                              [handle](const auto& value) { return value.handle == handle; });
    if (found == bootstrap_socket_results.end()) {
      found = std::find_if(bootstrap_socket_results.begin(), bootstrap_socket_results.end(),
                           [](const auto& value) { return value.handle == 0; });
      if (found == bootstrap_socket_results.end()) return;
      found->handle = handle;
    }
    report = !(found->reported & bit);
    found->reported |= bit;
  }
  if (report)
    REXKRNL_INFO("GAMEPLAY_BOOTSTRAP_RESULT api={} caller={:08X} guest_socket={:08X} "
                 "guest_lr={:08X} result=-1 last_error={} stage={}",
                 api, caller, handle, BootstrapGuestLinkRegister(), error, stage);
}

void RetireBootstrapSocketResults(uint32_t handle) {
  std::lock_guard lock(bootstrap_result_mutex);
  for (auto& value : bootstrap_socket_results)
    if (value.handle == handle) value = {};
}

void ReportBootstrapAddressFailure(uint32_t caller, uint32_t result) {
  // Direct host-side callers have no guest error state or link register.
  if (!XThread::IsInThread()) return;
  // XNet conversion has no socket identity. Report only its first failure on
  // each invoking native thread, with an additional fixed process-wide bound.
  static std::atomic<uint32_t> reports{0};
  static thread_local bool reported = false;
  if (reported) return;
  reported = true;
  if (reports.fetch_add(1, std::memory_order_relaxed) >= 32) return;
  const auto error = XThread::GetLastError();
  REXKRNL_INFO("GAMEPLAY_BOOTSTRAP_RESULT api=XNetXnAddrToInAddr caller={:08X} "
               "guest_lr={:08X} result={} last_error={} stage=address_conversion",
               caller, BootstrapGuestLinkRegister(), result, error);
  // Direct-return XNet APIs do not change Winsock's last-error contract.
  XThread::SetLastError(error);
}
}  // namespace

// https://github.com/G91/TitanOffLine/blob/1e692d9bb9dfac386d08045ccdadf4ae3227bb5e/xkelib/xam/xamNet.h
enum {
  XNCALLER_INVALID = 0x0,
  XNCALLER_TITLE = 0x1,
  XNCALLER_SYSAPP = 0x2,
  XNCALLER_XBDM = 0x3,
  XNCALLER_TEST = 0x4,
  NUM_XNCALLER_TYPES = 0x4,
};

// https://github.com/pmrowla/hl2sdk-csgo/blob/master/common/xbox/xboxstubs.h
struct XNADDR {
  // FYI: IN_ADDR should be in network-byte order.
  in_addr ina;                    // IP address (zero if not static/DHCP)
  in_addr inaOnline;              // Online IP address (zero if not online)
  rex::be<uint16_t> wPortOnline;  // Online port
  uint8_t abEnet[6];              // Ethernet MAC address
  uint8_t abOnline[20];           // Online identification
};

typedef struct {
  rex::be<int32_t> status;
  rex::be<uint32_t> cina;
  in_addr aina[8];
} XNDNS;

typedef struct {
  uint8_t flags;
  uint8_t reserved;
  rex::be<uint16_t> probes_xmit;
  rex::be<uint16_t> probes_recv;
  rex::be<uint16_t> data_len;
  rex::be<uint32_t> data_ptr;
  rex::be<uint16_t> rtt_min_in_msecs;
  rex::be<uint16_t> rtt_med_in_msecs;
  rex::be<uint32_t> up_bits_per_sec;
  rex::be<uint32_t> down_bits_per_sec;
} XNQOSINFO;

typedef struct {
  rex::be<uint32_t> count;
  rex::be<uint32_t> count_pending;
  XNQOSINFO info[1];
} XNQOS;

struct Xsockaddr_t {
  rex::be<uint16_t> sa_family;
  char sa_data[14];
};

struct X_WSADATA {
  rex::be<uint16_t> version;
  rex::be<uint16_t> version_high;
  char description[256 + 1];
  char system_status[128 + 1];
  rex::be<uint16_t> max_sockets;
  rex::be<uint16_t> max_udpdg;
  rex::be<uint32_t> vendor_info_ptr;
};

struct XWSABUF {
  rex::be<uint32_t> len;
  rex::be<uint32_t> buf_ptr;
};

struct XWSAOVERLAPPED {
  rex::be<uint32_t> internal;
  rex::be<uint32_t> internal_high;
  union {
    struct {
      rex::be<uint32_t> low;
      rex::be<uint32_t> high;
    } offset;  // must be named to avoid GCC error
    rex::be<uint32_t> pointer;
  };
  rex::be<uint32_t> event_handle;
};

void LoadSockaddr(const uint8_t* ptr, sockaddr* out_addr) {
  out_addr->sa_family = memory::load_and_swap<uint16_t>(ptr + 0);
  switch (out_addr->sa_family) {
    case AF_INET: {
      auto in_addr = reinterpret_cast<sockaddr_in*>(out_addr);
      in_addr->sin_port = memory::load_and_swap<uint16_t>(ptr + 2);
      // Maybe? Depends on type.
      in_addr->sin_addr.s_addr = *(uint32_t*)(ptr + 4);
      break;
    }
    default:
      assert_unhandled_case(out_addr->sa_family);
      break;
  }
}

void StoreSockaddr(const sockaddr& addr, uint8_t* ptr) {
  switch (addr.sa_family) {
    case AF_UNSPEC:
      std::memset(ptr, 0, sizeof(addr));
      break;
    case AF_INET: {
      auto& in_addr = reinterpret_cast<const sockaddr_in&>(addr);
      memory::store_and_swap<uint16_t>(ptr + 0, in_addr.sin_family);
      memory::store_and_swap<uint16_t>(ptr + 2, in_addr.sin_port);
      // Maybe? Depends on type.
      memory::store_and_swap<uint32_t>(ptr + 4, in_addr.sin_addr.s_addr);
      break;
    }
    default:
      assert_unhandled_case(addr.sa_family);
      break;
  }
}

// https://github.com/joolswills/mameox/blob/master/MAMEoX/Sources/xbox_Network.cpp#L136
struct XNetStartupParams {
  uint8_t cfgSizeOfStruct;
  uint8_t cfgFlags;
  uint8_t cfgSockMaxDgramSockets;
  uint8_t cfgSockMaxStreamSockets;
  uint8_t cfgSockDefaultRecvBufsizeInK;
  uint8_t cfgSockDefaultSendBufsizeInK;
  uint8_t cfgKeyRegMax;
  uint8_t cfgSecRegMax;
  uint8_t cfgQosDataLimitDiv4;
  uint8_t cfgQosProbeTimeoutInSeconds;
  uint8_t cfgQosProbeRetries;
  uint8_t cfgQosSrvMaxSimultaneousResponses;
  uint8_t cfgQosPairWaitTimeInSeconds;
};

static XNetStartupParams xnet_startup_params = {};
static std::mutex xnet_registry_mutex;
static std::unordered_map<uint32_t, XNADDR> xnet_address_registry;
// The XID a title associated with a directory-assigned gameplay peer. Titles
// key other members by their own session XID, which need not equal the
// runtime's peer session id; echo theirs back so a later XNetInAddrToXnAddr
// doesn't look like a different session. Keyed by logical address and checked
// against the peer's xuid and session so a reused logical address can't inherit it.
struct GameplayTitleXid { uint64_t xuid = 0; std::array<uint8_t, 8> session{}, xid{}; };
static std::unordered_map<uint32_t, GameplayTitleXid> gameplay_title_xids;
// The XID a title uses for the other members of a runtime session, for members
// it has not looked up itself yet (a newcomer that reaches it first). Keyed by
// the runtime session id.
static std::unordered_map<uint64_t, std::array<uint8_t, 8>> gameplay_session_title_xids;
uint64_t GameplaySessionKey(const std::array<uint8_t, 8>& id) {
  uint64_t key = 0;
  for (auto byte : id) key = (key << 8) | byte;
  return key;
}
void RecordGameplayTitleXid(const GameplayXnAddr& peer, const void* xid) {
  GameplayTitleXid recorded{peer.xuid, peer.session_id};
  std::memcpy(recorded.xid.data(), xid, recorded.xid.size());
  std::lock_guard lock(xnet_registry_mutex);
  if (gameplay_title_xids.size() > 64) gameplay_title_xids.clear();
  gameplay_title_xids[peer.logical.ipv4] = recorded;
  if (recorded.xid != peer.session_id) {
    if (gameplay_session_title_xids.size() > 16) gameplay_session_title_xids.clear();
    gameplay_session_title_xids[GameplaySessionKey(peer.session_id)] = recorded.xid;
  }
}
static std::unordered_map<uint64_t, std::array<uint8_t, 16>> xnet_key_registry;
// The key id the title registered last, as its raw guest bytes: titles name
// their session members by it.
static std::optional<std::array<uint8_t, 8>> xnet_last_registered_key_id;

std::array<uint8_t, 6> SyntheticEthernetAddress(uint32_t address) {
  // The XNet address is the stable peer key available to this API. Preserve
  // all 32 bits so distinct address handles cannot collide, and mark the
  // result as a locally administered unicast address. The final byte is a
  // stable check byte rather than an ephemeral socket or port value.
  const uint32_t network_address = htonl(address);
  const auto* bytes = reinterpret_cast<const uint8_t*>(&network_address);
  return {0x02, bytes[0], bytes[1], bytes[2], bytes[3],
          uint8_t(bytes[0] ^ bytes[1] ^ bytes[2] ^ bytes[3] ^ 0xA5)};
}

struct PendingRecvFrom {
  uint32_t socket_handle = 0;
  uint32_t buffer_ptr = 0;
  uint32_t buffer_length = 0;
  // Initiation bytes/flags outputs may be automatic storage. Delayed results
  // belong to this operation and are published by WSAGetOverlappedResult.
  uint32_t flags = 0;
  uint32_t from_ptr = 0;
  uint32_t from_length_ptr = 0;
  uint32_t overlapped_ptr = 0;
  uint32_t completion_routine = 0;
  uint32_t transferred = 0;
  uint32_t completion_flags = 0;
  uint32_t error = 0;
  bool complete = false;
  bool readiness_logged = false;
  bool native_call_logged = false;
};

static std::mutex pending_recv_mutex;
static std::condition_variable pending_recv_changed;
static std::unordered_map<uint32_t, PendingRecvFrom> pending_recvs;
static std::atomic<bool> pending_recv_pump_running{false};
static object_ref<XHostThread> pending_recv_pump_thread;

uint32_t LastSocketError() {
#if REX_PLATFORM_WIN32
  return WSAGetLastError();
#else
  // Preserve the guest Winsock ABI. Linux errno values are not WSA errors.
  switch (errno) {
    case 0: return 0;
    case EINTR: return 10004;
    case EACCES: return 10013;
    case EFAULT: return 10014;
    case EINVAL: return 10022;
    case EMFILE: return 10024;
    case EAGAIN: return 10035;
#if EWOULDBLOCK != EAGAIN
    case EWOULDBLOCK: return 10035;
#endif
    case EINPROGRESS: return 10036;
    case EALREADY: return 10037;
    case EBADF:
    case ENOTSOCK: return 10038;
    case EDESTADDRREQ: return 10039;
    case EMSGSIZE: return 10040;
    case EPROTOTYPE: return 10041;
    case ENOPROTOOPT: return 10042;
    case EPROTONOSUPPORT: return 10043;
    case EOPNOTSUPP: return 10045;
    case EAFNOSUPPORT: return 10047;
    case EADDRINUSE: return 10048;
    case EADDRNOTAVAIL: return 10049;
    case ENETDOWN: return 10050;
    case ENETUNREACH: return 10051;
    case ENETRESET: return 10052;
    case ECONNABORTED: return 10053;
    case ECONNRESET: return 10054;
    case ENOBUFS: return 10055;
    case EISCONN: return 10056;
    case ENOTCONN: return 10057;
    case EPIPE: return 10058;
    case ETIMEDOUT: return 10060;
    case ECONNREFUSED: return 10061;
    case EHOSTUNREACH: return 10065;
    default: return 10022;
  }
#endif
}

void CompleteRecvFromError(PendingRecvFrom& pending, uint32_t error) {
  pending.error = error;
  pending.transferred = 0;
  pending.completion_flags = 0;
  auto* overlapped = REX_KERNEL_MEMORY()->TranslateVirtual<XWSAOVERLAPPED*>(pending.overlapped_ptr);
  overlapped->internal = X_STATUS_UNSUCCESSFUL;
  overlapped->internal_high = 0;
  if (overlapped->event_handle) {
    auto event = REX_KERNEL_OBJECTS()->LookupObject<XEvent>(overlapped->event_handle);
    if (event) event->Set(0, false);
  }
  pending.complete = true;
  pending_recv_changed.notify_all();
}

bool TryCompleteRecvFrom(PendingRecvFrom& pending, bool wait) {
  constexpr uint32_t kWsaNotSocket = 0x2736;
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(pending.socket_handle);
  if (!socket) {
    CompleteRecvFromError(pending, kWsaNotSocket);
    return true;
  }

  if (wait && !socket->WaitReadable(0, true))
    return false;

#if REX_PLATFORM_WIN32
  u_long available = 0;
  const auto diagnostic_operation = socket->AcquireNativeLease();
  if (diagnostic_operation &&
      ioctlsocket(static_cast<SOCKET>(diagnostic_operation.handle()), FIONREAD, &available) == 0 &&
      available != 0 && !pending.readiness_logged) {
    pending.readiness_logged = true;
    if (REXCVAR_GET(net_packet_trace)) REXKRNL_INFO(
        "NetDll_WSARecvFrom: native datagram ready socket={:08X} native={} bytes={} "
        "overlapped={:08X}",
        pending.socket_handle, socket->native_handle(), available, pending.overlapped_ptr);
  }
#endif

  auto* memory = REX_KERNEL_MEMORY();
  N_XSOCKADDR_IN native_from{};
  uint32_t native_from_length = sizeof(XSOCKADDR_IN);
  if (!pending.native_call_logged) {
    pending.native_call_logged = true;
    if (REXCVAR_GET(net_packet_trace)) REXKRNL_INFO(
        "NetDll_WSARecvFrom: native receive socket={:08X} native={} flags={:#x} "
        "buffer_count=1 buffer_length={} from_length={} overlapped={:08X}",
        pending.socket_handle, socket->native_handle(), pending.flags, pending.buffer_length,
        pending.from_ptr ? native_from_length : 0, pending.overlapped_ptr);
  }
  int result = socket->RecvFrom(memory->TranslateVirtual(pending.buffer_ptr), pending.buffer_length,
                                pending.flags, pending.from_ptr ? &native_from : nullptr,
                                pending.from_ptr ? &native_from_length : nullptr);
  if (result < 0) {
    const uint32_t error = LastSocketError();
    if (error == 10035 || error == 10004)  // WSAEWOULDBLOCK / WSAEINTR
      return false;
    REXKRNL_ERROR(
        "NetDll_WSARecvFrom: native receive failed socket={:08X} native={} error={} "
        "flags={:#x} overlapped={:08X}",
        pending.socket_handle, socket->native_handle(), error, pending.flags,
        pending.overlapped_ptr);
    CompleteRecvFromError(pending, error);
    return true;
  }

  pending.transferred = uint32_t(result);
  pending.completion_flags = 0;
  if (pending.from_ptr) {
    auto* from = memory->TranslateVirtual<XSOCKADDR_IN*>(pending.from_ptr);
    from->sin_family = native_from.sin_family;
    from->sin_port = native_from.sin_port;
    from->sin_addr = native_from.sin_addr;
    std::memset(from->x_sin_zero, 0, sizeof(from->x_sin_zero));
  }
  if (pending.from_length_ptr)
    memory::store_and_swap<uint32_t>(memory->TranslateVirtual(pending.from_length_ptr),
                                     native_from_length);

  auto* overlapped = memory->TranslateVirtual<XWSAOVERLAPPED*>(pending.overlapped_ptr);
  overlapped->internal = 0;
  overlapped->internal_high = pending.transferred;
  if (overlapped->event_handle) {
    auto event = REX_KERNEL_OBJECTS()->LookupObject<XEvent>(overlapped->event_handle);
    if (event)
      event->Set(0, false);
  }
  pending.complete = true;
  const auto* payload = memory->TranslateVirtual(pending.buffer_ptr);
  if (REXCVAR_GET(net_packet_trace)) REXKRNL_INFO(
      "NetDll_WSARecvFrom: completed overlapped receive socket={:08X} overlapped={:08X} "
      "bytes={} source={:08X}:{} from_length={} flags=0 event={:08X} "
      "prefix={:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}",
      pending.socket_handle, pending.overlapped_ptr, pending.transferred,
      uint32_t(native_from.sin_addr), uint16_t(native_from.sin_port), native_from_length,
      uint32_t(overlapped->event_handle), pending.transferred > 0 ? payload[0] : 0,
      pending.transferred > 1 ? payload[1] : 0, pending.transferred > 2 ? payload[2] : 0,
      pending.transferred > 3 ? payload[3] : 0, pending.transferred > 4 ? payload[4] : 0,
      pending.transferred > 5 ? payload[5] : 0, pending.transferred > 6 ? payload[6] : 0,
      pending.transferred > 7 ? payload[7] : 0);
  return true;
}

void PumpPendingRecvFrom() {
  std::lock_guard lock(pending_recv_mutex);
  for (auto& [_, pending] : pending_recvs) {
    if (!pending.complete)
      TryCompleteRecvFrom(pending, false);
  }
}

void EnsurePendingRecvPump() {
  bool expected = false;
  if (!pending_recv_pump_running.compare_exchange_strong(expected, true))
    return;

  auto* state = REX_KERNEL_STATE();
  pending_recv_pump_thread = object_ref<XHostThread>(new XHostThread(
      state, 64 * 1024, 0, []() {
        REXKRNL_INFO("NetDll_WSARecvFrom: receive pump running");
        while (pending_recv_pump_running.load(std::memory_order_acquire)) {
          PumpPendingRecvFrom();
          rex::thread::Sleep(std::chrono::milliseconds(1));
        }
        REXKRNL_INFO("NetDll_WSARecvFrom: receive pump stopped");
        return 0;
      }));
  pending_recv_pump_thread->set_name("Winsock Receive Pump");
  X_STATUS status = pending_recv_pump_thread->Create();
  if (XFAILED(status)) {
    pending_recv_pump_running.store(false, std::memory_order_release);
    pending_recv_pump_thread.reset();
    REXKRNL_ERROR("NetDll_WSARecvFrom: failed to start receive pump ({:#x})", status);
  } else {
    REXKRNL_INFO("NetDll_WSARecvFrom: receive pump created");
  }
}

uint64_t LoadKeyId(mapped_void key_id) {
  uint64_t value = 0;
  if (key_id)
    std::memcpy(&value, key_id.host_address(), sizeof(value));
  return value;
}

u32 NetDll_XNetStartup_entry(u32 caller, ppc_ptr_t<XNetStartupParams> params) {
  if (params) {
    assert_true(params->cfgSizeOfStruct == sizeof(XNetStartupParams));
    std::memcpy(&xnet_startup_params, params, sizeof(XNetStartupParams));
  }

  auto xam = REX_KERNEL_STATE()->GetKernelModule<XamModule>("xam.xex");

  /*
  if (!xam->xnet()) {
    auto xnet = new XNet(REX_KERNEL_STATE());
    xnet->Initialize();

    xam->set_xnet(xnet);
  }
  */

  return 0;
}

u32 NetDll_XNetCleanup_entry(u32 caller, mapped_void params) {
  auto xam = REX_KERNEL_STATE()->GetKernelModule<XamModule>("xam.xex");
  // auto xnet = xam->xnet();
  // xam->set_xnet(nullptr);

  // TODO: Shut down and delete.
  // delete xnet;

  return 0;
}

u32 NetDll_XNetGetOpt_entry(u32 one, u32 option_id, mapped_void buffer_ptr,
                            mapped_u32 buffer_size) {
  assert_true(one == 1);
  switch (option_id) {
    case 1:
      if (*buffer_size < sizeof(XNetStartupParams)) {
        *buffer_size = sizeof(XNetStartupParams);
        return 0x2738;  // WSAEMSGSIZE
      }
      std::memcpy(buffer_ptr, &xnet_startup_params, sizeof(XNetStartupParams));
      return 0;
    default:
      REXKRNL_ERROR("NetDll_XNetGetOpt: option {} unimplemented", option_id);
      return 0x2726;  // WSAEINVAL
  }
}

u32 NetDll_XNetRandom_entry(u32 caller, mapped_void buffer_ptr, u32 length) {
  // For now, constant values.
  // This makes replicating things easier.
  std::memset(buffer_ptr, 0xBB, length);

  return 0;
}

u32 NetDll_WSAStartup_entry(u32 caller, u16 version, ppc_ptr_t<X_WSADATA> data_ptr) {
// TODO(benvanik): abstraction layer needed.
#if REX_PLATFORM_WIN32
  WSADATA wsaData;
  ZeroMemory(&wsaData, sizeof(WSADATA));
  int ret = WSAStartup(version, &wsaData);

  auto data_out = REX_KERNEL_MEMORY()->TranslateVirtual(data_ptr.guest_address());

  if (data_ptr) {
    data_ptr->version = wsaData.wVersion;
    data_ptr->version_high = wsaData.wHighVersion;
    std::memcpy(&data_ptr->description, wsaData.szDescription, 0x100);
    std::memcpy(&data_ptr->system_status, wsaData.szSystemStatus, 0x80);
    data_ptr->max_sockets = wsaData.iMaxSockets;
    data_ptr->max_udpdg = wsaData.iMaxUdpDg;

    // Some games (5841099F) want this value round-tripped - they'll compare if
    // it changes and bugcheck if it does.
    uint32_t vendor_ptr = memory::load_and_swap<uint32_t>(data_out + 0x190);
    memory::store_and_swap<uint32_t>(data_out + 0x190, vendor_ptr);
  }
#else
  int ret = 0;
  if (data_ptr) {
    // Guess these values!
    data_ptr->version = version;
    data_ptr->description[0] = '\0';
    data_ptr->system_status[0] = '\0';
    data_ptr->max_sockets = 100;
    data_ptr->max_udpdg = 1024;
  }
#endif

  // DEBUG
  /*
  auto xam = REX_KERNEL_STATE()->GetKernelModule<XamModule>("xam.xex");
  if (!xam->xnet()) {
    auto xnet = new XNet(REX_KERNEL_STATE());
    xnet->Initialize();

    xam->set_xnet(xnet);
  }
  */

  return ret;
}

u32 NetDll_WSACleanup_entry(u32 caller) {
  // This does nothing. Xenia needs WSA running.
  return 0;
}

u32 NetDll_WSAGetLastError_entry() {
  return XThread::GetLastError();
}

namespace { bool PendingSendExists(KernelState*, uint32_t); }

u32 NetDll_WSARecvFrom_entry(u32 caller, u32 socket, ppc_ptr_t<XWSABUF> buffers_ptr,
                             u32 buffer_count, mapped_u32 num_bytes_recv, mapped_u32 flags_ptr,
                             ppc_ptr_t<XSOCKADDR_IN> from_addr,
                             mapped_u32 from_length,
                             ppc_ptr_t<XWSAOVERLAPPED> overlapped_ptr,
                             mapped_void completion_routine_ptr) {
  constexpr uint32_t kWsaInvalidArgument = 0x2726;
  constexpr uint32_t kWsaNotSocket = 0x2736;
  constexpr uint32_t kWsaIoPending = 997;
  constexpr uint32_t kStatusPending = 0x00000103;

  auto socket_object = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket);
  auto failed = [&](uint32_t error, const char* stage, uint8_t bit = kBootstrapReceiveFailure) {
    if (socket_object)
      ReportBootstrapSocketResult("WSARecvFrom", caller, socket, error, stage, bit);
    XThread::SetLastError(error);
    return uint32_t(-1);
  };
  if (!socket_object) {
    return failed(kWsaNotSocket, "socket_lookup");
  }
  if (!buffers_ptr || buffer_count != 1 || !buffers_ptr[0].buf_ptr || !buffers_ptr[0].len) {
    return failed(kWsaInvalidArgument, "receive_arguments");
  }

  // Harmony posts a completion-routine receive before any peer has connected.
  // A real Winsock overlapped receive returns SOCKET_ERROR/WSA_IO_PENDING here;
  // returning SOCKET_ERROR with a zero last-error makes the title treat normal
  // pending I/O as a hard network failure.
  if (overlapped_ptr) {
    if (XFAILED(socket_object->SetNonBlocking(true))) {
      return failed(kWsaInvalidArgument, "nonblocking_mode");
    }
    if (PendingSendExists(REX_KERNEL_STATE(), overlapped_ptr.guest_address()))
      return failed(kWsaInvalidArgument, "overlapped_in_use");
    overlapped_ptr->internal = kStatusPending;
    overlapped_ptr->internal_high = 0;
    if (num_bytes_recv)
      *num_bytes_recv = 0;
    PendingRecvFrom pending{
        socket,
        buffers_ptr[0].buf_ptr,
        buffers_ptr[0].len,
        flags_ptr ? uint32_t(*flags_ptr) : 0,
        from_addr.guest_address(),
        from_length.guest_address(),
        overlapped_ptr.guest_address(),
        completion_routine_ptr.guest_address(),
    };
    {
      std::lock_guard lock(pending_recv_mutex);
      pending_recvs[pending.overlapped_ptr] = pending;
    }
    EnsurePendingRecvPump();
    if (REXCVAR_GET(net_packet_trace)) REXKRNL_INFO(
        "NetDll_WSARecvFrom: queued overlapped receive socket={:08X} overlapped={:08X} "
        "buffer={:08X} length={} flags_ptr={:08X} flags_initial={:#x} from={:08X} "
        "from_length={:08X} "
        "event={:08X} completion={:08X}",
        socket, pending.overlapped_ptr, pending.buffer_ptr, pending.buffer_length,
        flags_ptr.guest_address(), pending.flags, pending.from_ptr, pending.from_length_ptr,
        uint32_t(overlapped_ptr->event_handle), pending.completion_routine);
    return failed(kWsaIoPending, "overlapped_pending", kBootstrapReceivePending);
  }

  uint32_t flags = flags_ptr ? uint32_t(*flags_ptr) : 0;
  N_XSOCKADDR_IN native_from{};
  uint32_t native_from_length = sizeof(XSOCKADDR_IN);
  int result = socket_object->RecvFrom(
      REX_KERNEL_MEMORY()->TranslateVirtual(buffers_ptr[0].buf_ptr), buffers_ptr[0].len, flags,
      from_addr ? &native_from : nullptr, from_addr ? &native_from_length : nullptr);
  if (result < 0) {
    return failed(LastSocketError(), "native_receive");
  }
  if (num_bytes_recv)
    *num_bytes_recv = uint32_t(result);
  if (from_addr) {
    from_addr->sin_family = native_from.sin_family;
    from_addr->sin_port = native_from.sin_port;
    from_addr->sin_addr = native_from.sin_addr;
    std::memset(from_addr->x_sin_zero, 0, sizeof(from_addr->x_sin_zero));
  }
  if (flags_ptr)
    *flags_ptr = 0;
  XThread::SetLastError(0);
  return 0;
}

namespace {
bool PendingSendExists(KernelState*, uint32_t);
bool QueryPendingSend(KernelState*, uint32_t, uint32_t, mapped_u32, bool, mapped_u32, uint32_t*);
}

u32 NetDll_WSAGetOverlappedResult_entry(u32 caller, u32 socket_handle,
                                        ppc_ptr_t<XWSAOVERLAPPED> overlapped_ptr,
                                        mapped_u32 bytes_transferred, u32 wait,
                                        mapped_u32 flags_ptr) {
  constexpr uint32_t kWsaInvalidArgument = 0x2726;
  constexpr uint32_t kWsaIoIncomplete = 996;
  if (!overlapped_ptr || !bytes_transferred) {
    XThread::SetLastError(kWsaInvalidArgument);
    return 0;
  }

  uint32_t send_result = 0;
  if (QueryPendingSend(REX_KERNEL_STATE(), socket_handle, overlapped_ptr.guest_address(),
                       bytes_transferred, wait != 0, flags_ptr, &send_result))
    return send_result;
  std::unique_lock lock(pending_recv_mutex);
  auto it = pending_recvs.find(overlapped_ptr.guest_address());
  // Never wait for network readiness while holding the cancellation lock.
  // Re-find after every unlock: a competing query may have consumed the record.
  while (wait && it != pending_recvs.end() && it->second.socket_handle == socket_handle &&
         !it->second.complete && !TryCompleteRecvFrom(it->second, false)) {
    pending_recv_changed.wait_for(lock, std::chrono::milliseconds(1));
    it = pending_recvs.find(overlapped_ptr.guest_address());
  }
  if (it == pending_recvs.end() || it->second.socket_handle != socket_handle) {
    XThread::SetLastError(kWsaInvalidArgument);
    return 0;
  }
  auto& pending = it->second;
  if (!pending.complete && !TryCompleteRecvFrom(pending, false)) {
    REXKRNL_DEBUG(
        "NetDll_WSAGetOverlappedResult: incomplete socket={:08X} overlapped={:08X} wait={}",
        socket_handle, overlapped_ptr.guest_address(), wait != 0);
    XThread::SetLastError(kWsaIoIncomplete);
    return 0;
  }
  if (pending.error) {
    XThread::SetLastError(pending.error);
    pending_recvs.erase(it);
    return 0;
  }
  *bytes_transferred = pending.transferred;
  if (flags_ptr)
    *flags_ptr = pending.completion_flags;
  if (REXCVAR_GET(net_packet_trace)) REXKRNL_INFO(
      "NetDll_WSAGetOverlappedResult: completed socket={:08X} overlapped={:08X} bytes={}",
      socket_handle, overlapped_ptr.guest_address(), pending.transferred);
  XThread::SetLastError(0);
  pending_recvs.erase(it);
  return 1;
}

namespace {
constexpr uint32_t kMaximumSendBuffers = 64;
constexpr uint32_t kMaximumStreamSendBytes = 16 * 1024 * 1024;
constexpr uint32_t kMaximumUdpSendBytes = 65507;
constexpr uint32_t kWsaFault = 10014;
constexpr uint32_t kWsaInvalidArgument = 10022;
constexpr uint32_t kWsaMessageSize = 10040;
constexpr uint32_t kWsaNoBuffers = 10055;

// Validate the complete guest interval before interpreting any bytes. Guest
// address wrap and transitions to a different host mapping are not contiguous
// buffers. Callers hold the cooperative mapping lease only while staging or
// publishing, never while waiting on a socket.
bool SendGuestRange(memory::Memory* memory, uint32_t address, size_t length,
                    const void* host, bool writable = false) {
  if (!length) return true;
  if (!address || uint64_t(address) + length > (uint64_t{1} << 32) ||
      host != memory->TranslateVirtual(address)) return false;
  const auto host_start = reinterpret_cast<uintptr_t>(host);
  uint64_t position = address, end = uint64_t(address) + length;
  while (position < end) {
    auto* heap = memory->LookupHeap(uint32_t(position));
    if (!heap) return false;
    const uint64_t heap_end = uint64_t(heap->heap_base()) + heap->heap_size();
    const uint64_t step_end = std::min(end, heap_end);
    if (step_end <= position ||
        reinterpret_cast<uintptr_t>(memory->TranslateVirtual(uint32_t(position))) !=
            host_start + size_t(position - address)) return false;
    const auto access = heap->QueryRangeAccess(
        uint32_t(position), uint32_t(step_end - 1));
    const auto required = writable ? memory::PageAccess::kReadWrite : memory::PageAccess::kReadOnly;
    if ((uint32_t(access) & uint32_t(required)) != uint32_t(required)) return false;
    position = step_end;
  }
  return true;
}

bool ReadSendGuest(memory::Memory* memory, uint32_t address, const void* host,
                   void* staged, size_t length) {
  if (!SendGuestRange(memory, address, length, host)) return false;
  if (!length) return true;
#if REX_PLATFORM_LINUX
  iovec local{staged, length}, remote{const_cast<void*>(host), length};
  return process_vm_readv(getpid(), &local, 1, &remote, 1, 0) == ssize_t(length);
#elif REX_PLATFORM_WIN32
  // Mirror process_vm_readv: a page unmapped after the range check fails
  // closed instead of faulting the host (Windows has no mapping gate here).
  SIZE_T copied = 0;
  return ReadProcessMemory(GetCurrentProcess(), host, staged, length, &copied) &&
         copied == length;
#else
  std::memcpy(staged, host, length);
  return true;
#endif
}

bool WriteSendGuest(memory::Memory* memory, uint32_t address, void* host,
                    const void* staged, size_t length) {
  if (!SendGuestRange(memory, address, length, host, true)) return false;
  if (!length) return true;
#if REX_PLATFORM_LINUX
  iovec local{const_cast<void*>(staged), length}, remote{host, length};
  return process_vm_writev(getpid(), &local, 1, &remote, 1, 0) == ssize_t(length);
#elif REX_PLATFORM_WIN32
  // Mirror process_vm_writev for the same reason as ReadSendGuest.
  SIZE_T written = 0;
  return WriteProcessMemory(GetCurrentProcess(), host, staged, length, &written) &&
         written == length;
#else
  std::memcpy(host, staged, length);
  return true;
#endif
}

bool SendLimit(const XSocket::NativeLease& operation, uint32_t* limit) {
  int type = 0;
#if REX_PLATFORM_WIN32
  int length = sizeof(type);
  const int result = getsockopt(static_cast<SOCKET>(operation.handle()), SOL_SOCKET, SO_TYPE,
                               reinterpret_cast<char*>(&type), &length);
#else
  socklen_t length = sizeof(type);
  const int result = getsockopt(static_cast<int>(operation.handle()), SOL_SOCKET, SO_TYPE,
                               &type, &length);
#endif
  if (result < 0 || operation.retired()) {
    XThread::SetLastError(operation.retired() ? 10038 : LastSocketError());
    return false;
  }
  *limit = type == SOCK_DGRAM ? kMaximumUdpSendBytes : kMaximumStreamSendBytes;
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32 || REX_PLATFORM_ANDROID
  if (type == SOCK_DGRAM && IsAuthorizedGameplaySocket(operation.handle()))
    *limit = kGameplayMaximumPlaintextBytes;
#endif
  return true;
}

bool StageSendDestination(memory::Memory* memory, ppc_ptr_t<XSOCKADDR_IN> to,
                          uint32_t length, N_XSOCKADDR_IN* native) {
  if (!to) {
    if (!length) return true;  // Connected socket: no destination supplied.
    XThread::SetLastError(kWsaInvalidArgument);
    return false;
  }
  // Exactly the supported IPv4 structure; never read a short or oversized
  // destination or silently accept an unsupported address family.
  if (length != sizeof(XSOCKADDR_IN)) {
    XThread::SetLastError(kWsaInvalidArgument);
    return false;
  }
  XSOCKADDR_IN staged{};
  if (!ReadSendGuest(memory, to.guest_address(), to.host_address(), &staged, sizeof(staged))) {
    XThread::SetLastError(kWsaFault);
    return false;
  }
  if (uint16_t(staged.sin_family) != XSocket::X_AF_INET) {
    XThread::SetLastError(10047);  // WSAEAFNOSUPPORT
    return false;
  }
  *native = staged;
  return true;
}
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32 || REX_PLATFORM_ANDROID
#include "pending_socket_sends.h"
#else
bool PendingSendExists(KernelState*, uint32_t) { return false; }
bool QueryPendingSend(KernelState*, uint32_t, uint32_t, mapped_u32, bool,
                      mapped_u32, uint32_t*) { return false; }
#endif
}  // namespace

#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32 || REX_PLATFORM_ANDROID
void CancelPendingSocketSends(KernelState* state, XSocket* socket) {
  auto service = FindPendingSendService(state); if (!service) return;
  std::array<std::shared_ptr<PendingSocketSend>, PendingSocketSendService::kMaximumOperations> work{};
  size_t count = 0;
  { std::lock_guard lock(service->mutex);
    for (auto& [_, op] : service->operations) if (op->socket.get() == socket) work[count++] = op; }
  for (auto& op : std::span(work).first(count)) { std::lock_guard lock(op->mutex); CompletePendingSend(*op,995,0); }
  service->changed.notify_all();
}
void CancelPendingSocketSendsForThread(KernelState* state, XThread* thread) {
  auto service = FindPendingSendService(state); if (!service) return;
  std::array<std::shared_ptr<PendingSocketSend>, PendingSocketSendService::kMaximumOperations> work{};
  size_t count = 0;
  { std::lock_guard lock(service->mutex); for (auto& [_, op] : service->operations) work[count++] = op; }
  for (auto& op : std::span(work).first(count)) {
    std::lock_guard lock(op->mutex); if (op->owner.get() == thread) CompletePendingSend(*op,995,0);
  }
  service->changed.notify_all();
}
void StopPendingSocketSends(KernelState* state) {
  std::shared_ptr<PendingSocketSendService> service;
  { std::lock_guard lock(pending_send_services_mutex);
    auto it=pending_send_services.find(state); if (it==pending_send_services.end()) return;
    service=it->second;
    { std::lock_guard gate(service->mutex); service->accepting=false; service->stopping=true; }
    pending_send_services.erase(it);
  }
  service->changed.notify_all();
  if (service->worker.joinable()) service->worker.join();
  std::array<std::shared_ptr<PendingSocketSend>, PendingSocketSendService::kMaximumOperations> work{};
  size_t count = 0;
  { std::lock_guard lock(service->mutex); for (auto& [_, op] : service->operations) work[count++] = op; }
  for (auto& op : std::span(work).first(count)) { std::lock_guard lock(op->mutex); CompletePendingSend(*op,995,0,true); }
  { std::lock_guard lock(service->mutex); service->operations.clear(); }
}

#else
void CancelPendingSocketSends(KernelState*, XSocket*) {}
void CancelPendingSocketSendsForThread(KernelState*, XThread*) {}
void StopPendingSocketSends(KernelState*) {}
#endif

// If the socket is a VDP socket, buffer 0 is the game data length, and buffer 1
// is the unencrypted game data.
u32 NetDll_WSASendTo_entry(u32 caller, u32 socket_handle, ppc_ptr_t<XWSABUF> buffers,
                           u32 num_buffers, mapped_u32 num_bytes_sent, u32 flags,
                           ppc_ptr_t<XSOCKADDR_IN> to_ptr, u32 to_len,
                           ppc_ptr_t<XWSAOVERLAPPED> overlapped, mapped_void completion_routine) {
  // Preserve the title handshake's existing pending-receive progress point.
  PumpPendingRecvFrom();
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    XThread::SetLastError(10038);
    return -1;
  }
  auto failed = [&](uint32_t error, const char* stage) {
    ReportBootstrapSocketResult("WSASendTo", caller, socket_handle, error, stage,
                                kBootstrapSendFailure);
    XThread::SetLastError(error);
    return uint32_t(-1);
  };
  const auto operation = socket->AcquireNativeLease();
  if (!operation) return failed(10038, "native_lease");
  uint32_t maximum = 0;
  if (!SendLimit(operation, &maximum)) return failed(XThread::GetLastError(), "native_limit");
  if (!buffers || !num_buffers || num_buffers > kMaximumSendBuffers) {
    return failed(kWsaInvalidArgument, "send_arguments");
  }

  std::array<XWSABUF, kMaximumSendBuffers> descriptors{};
  std::vector<uint8_t> combined;
  N_XSOCKADDR_IN native_to{};
  XWSAOVERLAPPED staged_overlapped{};
  uint64_t size = 0;
  try {
#if REX_PLATFORM_GNU_LINUX
    memory::MappingAccessLease lease;
#endif
    auto* memory = REX_KERNEL_MEMORY();
    if (!StageSendDestination(memory, to_ptr, to_len, &native_to))
      return failed(XThread::GetLastError(), "send_destination");
    if (!ReadSendGuest(memory, buffers.guest_address(), buffers.host_address(),
                       descriptors.data(), num_buffers * sizeof(XWSABUF)) ||
        (num_bytes_sent && !SendGuestRange(memory, num_bytes_sent.guest_address(),
                                           sizeof(be_u32), num_bytes_sent.host_address(), true)) ||
        (overlapped &&
         (!ReadSendGuest(memory, overlapped.guest_address(), overlapped.host_address(),
                         &staged_overlapped, sizeof(staged_overlapped)) ||
          !SendGuestRange(memory, overlapped.guest_address(), 2 * sizeof(be_u32),
                          overlapped.host_address(), true)))) {
      return failed(kWsaFault, "send_guest_range");
    }
    for (uint32_t i = 0; i < num_buffers; ++i) {
      size += uint32_t(descriptors[i].len);
      if (size > maximum) return failed(kWsaMessageSize, "send_size");
    }
    combined.resize(size_t(size));
    size_t offset = 0;
    for (uint32_t i = 0; i < num_buffers; ++i) {
      const auto length = uint32_t(descriptors[i].len);
      const auto address = uint32_t(descriptors[i].buf_ptr);
      if (length && !ReadSendGuest(memory, address, memory->TranslateVirtual(address),
                                    combined.data() + offset, length)) {
        return failed(kWsaFault, "send_guest_buffer");
      }
      offset += length;
    }
  } catch (const std::bad_alloc&) {
    return failed(kWsaNoBuffers, "send_allocation");
  }

  if (overlapped) {
    std::lock_guard lock(pending_recv_mutex);
    auto previous = pending_recvs.find(overlapped.guest_address());
    if ((previous != pending_recvs.end() && !previous->second.complete) ||
        PendingSendExists(REX_KERNEL_STATE(), overlapped.guest_address()))
      return failed(kWsaInvalidArgument, "overlapped_in_use");
    // Completed OVERLAPPED operations may be reused without querying their
    // cached results. Only the host's terminal state permits this; guest writes
    // cannot make an in-flight operation reusable. Keep all argument/mapping
    // validation above, and retire the old cache before initiating new I/O.
    if (previous != pending_recvs.end()) pending_recvs.erase(previous);
  }
  const int result = socket->SendTo(combined.data(), uint32_t(size), flags,
                                    to_ptr ? &native_to : nullptr, to_len);
  const uint32_t send_error = result < 0 ? LastSocketError() : 0;
  PumpPendingRecvFrom();
  if (result < 0) {
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32 || REX_PLATFORM_ANDROID
    // WSA_IO_PENDING means this exact operation is retained, not merely that
    // authorization is outstanding. Ordinary synchronous sends still fail closed.
    if (send_error == 10035 && overlapped &&
        IsAuthorizedGameplaySocket(operation.handle()) && maximum == kGameplayMaximumPlaintextBytes) {
      if (completion_routine) return failed(10045, "pending_callback_unsupported");
      uint32_t queued = kWsaNoBuffers;
      try {
        queued = QueuePendingSend(REX_KERNEL_STATE(), socket_handle, socket, operation,
            std::move(combined), flags, to_ptr ? &native_to : nullptr,
            overlapped.guest_address(), staged_overlapped);
      } catch (const std::bad_alloc&) { queued = kWsaNoBuffers; }
        catch (const std::system_error&) { queued = kWsaNoBuffers; }
      return failed(queued ? queued : 997, queued ? "pending_send_rejected" : "overlapped_pending");
    }
#endif
    return failed(send_error, "native_send");
  }
  // Recheck mapping ownership after the network call, then publish only the
  // result fields. Never copy the descriptor's event/offset bytes back over a
  // concurrent title update and never hold a mapping lease across native I/O.
  {
#if REX_PLATFORM_GNU_LINUX
    memory::MappingAccessLease lease;
#endif
    auto* memory = REX_KERNEL_MEMORY();
    if ((num_bytes_sent && !SendGuestRange(memory, num_bytes_sent.guest_address(),
                                           sizeof(be_u32), num_bytes_sent.host_address(), true)) ||
        (overlapped && !SendGuestRange(memory, overlapped.guest_address(), 2 * sizeof(be_u32),
                                       overlapped.host_address(), true))) {
      return failed(kWsaFault, "send_guest_range");
    }
    const be_u32 sent{uint32_t(result)};
    const std::array<be_u32, 2> status{be_u32(0), sent};
    if ((num_bytes_sent && !WriteSendGuest(memory, num_bytes_sent.guest_address(),
                                          num_bytes_sent.host_address(), &sent, sizeof(sent))) ||
        (overlapped && !WriteSendGuest(memory, overlapped.guest_address(),
                                       overlapped.host_address(), status.data(), sizeof(status)))) {
      return failed(kWsaFault, "send_guest_range");
    }
  }
  if (REXCVAR_GET(net_packet_trace)) REXKRNL_INFO(
      "NetDll_WSASendTo: socket={:08X} destination={:08X}:{} bytes={} overlapped={:08X}",
      socket_handle, uint32_t(native_to.sin_addr), uint16_t(native_to.sin_port), result,
      overlapped.guest_address());

  // Keep synchronous OVERLAPPED/event completion semantics, using the event
  // identity staged before sending rather than dereferencing guest memory.
  if (overlapped) {
    PendingRecvFrom completed{};
    completed.socket_handle = socket_handle;
    completed.overlapped_ptr = overlapped.guest_address();
    completed.transferred = uint32_t(result);
    completed.complete = true;
    {
      std::lock_guard lock(pending_recv_mutex);
      pending_recvs[completed.overlapped_ptr] = completed;
    }
    if (staged_overlapped.event_handle) {
      auto event = REX_KERNEL_OBJECTS()->LookupObject<XEvent>(staged_overlapped.event_handle);
      if (event) event->Set(0, false);
    }
    if (completion_routine)
      REXKRNL_WARN("NetDll_WSASendTo: completion routine {:08X} retained as immediate event completion",
                  completion_routine.guest_address());
  }
  XThread::SetLastError(0);
  return 0;
}

u32 NetDll_WSAWaitForMultipleEvents_entry(u32 num_events, mapped_u32 events, u32 wait_all,
                                          u32 timeout, u32 alertable) {
  if (num_events > 64) {
    XThread::SetLastError(87);  // ERROR_INVALID_PARAMETER
    return ~0u;
  }

  constexpr uint32_t kWsaWaitTimeout = 258;
  const bool infinite = timeout == 0xFFFFFFFFu;
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(timeout);
  // XObject uses 0 ticks as an immediate wait. Polling in short host-side
  // slices lets socket readiness complete and signal guest WSA events without
  // introducing a platform-specific background I/O thread.
  uint64_t immediate_timeout = 0;
  const uint32_t wait_type = wait_all ? 0 : 1;
  for (;;) {
    PumpPendingRecvFrom();
    X_STATUS result = xboxkrnl::xeNtWaitForMultipleObjectsEx(
        num_events, events, wait_type, 1, alertable, &immediate_timeout);
    if (result != X_STATUS_TIMEOUT && result != X_STATUS_ALERTED) {
      if (XFAILED(result)) {
        uint32_t error = xboxkrnl::xeRtlNtStatusToDosError(result);
        XThread::SetLastError(error);
        return ~0u;
      }
      XThread::SetLastError(0);
      return result;
    }
    if (!infinite && (timeout == 0 || std::chrono::steady_clock::now() >= deadline)) {
      XThread::SetLastError(0);
      return kWsaWaitTimeout;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

u32 NetDll_WSACreateEvent_entry() {
  XEvent* ev = new XEvent(REX_KERNEL_STATE());
  ev->Initialize(true, false);
  return ev->handle();
}

u32 NetDll_WSACloseEvent_entry(u32 event_handle) {
  X_STATUS result = REX_KERNEL_OBJECTS()->ReleaseHandle(event_handle);
  if (XFAILED(result)) {
    uint32_t error = xboxkrnl::xeRtlNtStatusToDosError(result);
    XThread::SetLastError(error);
    return 0;
  }
  return 1;
}

u32 NetDll_WSAResetEvent_entry(u32 event_handle) {
  X_STATUS result = xboxkrnl::xeNtClearEvent(event_handle);
  if (XFAILED(result)) {
    uint32_t error = xboxkrnl::xeRtlNtStatusToDosError(result);
    XThread::SetLastError(error);
    return 0;
  }
  return 1;
}

u32 NetDll_WSASetEvent_entry(u32 event_handle) {
  X_STATUS result = xboxkrnl::xeNtSetEvent(event_handle, nullptr);
  if (XFAILED(result)) {
    uint32_t error = xboxkrnl::xeRtlNtStatusToDosError(result);
    XThread::SetLastError(error);
    return 0;
  }
  return 1;
}

struct XnAddrStatus {
  // Address acquisition is not yet complete
  static const uint32_t XNET_GET_XNADDR_PENDING = 0x00000000;
  // XNet is uninitialized or no debugger found
  static const uint32_t XNET_GET_XNADDR_NONE = 0x00000001;
  // Host has ethernet address (no IP address)
  static const uint32_t XNET_GET_XNADDR_ETHERNET = 0x00000002;
  // Host has statically assigned IP address
  static const uint32_t XNET_GET_XNADDR_STATIC = 0x00000004;
  // Host has DHCP assigned IP address
  static const uint32_t XNET_GET_XNADDR_DHCP = 0x00000008;
  // Host has PPPoE assigned IP address
  static const uint32_t XNET_GET_XNADDR_PPPOE = 0x00000010;
  // Host has one or more gateways configured
  static const uint32_t XNET_GET_XNADDR_GATEWAY = 0x00000020;
  // Host has one or more DNS servers configured
  static const uint32_t XNET_GET_XNADDR_DNS = 0x00000040;
  // Host is currently connected to online service
  static const uint32_t XNET_GET_XNADDR_ONLINE = 0x00000080;
  // Network configuration requires troubleshooting
  static const uint32_t XNET_GET_XNADDR_TROUBLESHOOT = 0x00008000;
};

u32 NetDll_XNetGetTitleXnAddr_entry(u32 caller, ppc_ptr_t<XNADDR> addr_ptr) {
  if (!addr_ptr) {
    return XnAddrStatus::XNET_GET_XNADDR_NONE;
  }
  uint64_t xuid = REX_KERNEL_STATE()->user_profile()->xuid();
  const uint32_t lan = LanDiscoveryService::DetermineLanIpv4();
  addr_ptr->ina.s_addr = lan;
  addr_ptr->inaOnline.s_addr = addr_ptr->ina.s_addr;
  addr_ptr->wPortOnline = 3074;
  // A joiner that reaches its host over a public route is known to every other
  // member by its directory-assigned logical address, not its home-network one.
  const auto self = rex::system::xam::GameplaySelfLogicalAddress(xuid);
  if (self) {
    addr_ptr->ina.s_addr = self->ipv4;
    addr_ptr->inaOnline.s_addr = self->ipv4;
    addr_ptr->wPortOnline = self->port;
  }
  {
    // Diagnostics: when the title asks, and which address it was given.
    static std::mutex logged_mutex;
    static uint32_t logged_address = 0;
    static uint32_t calls = 0;
    std::lock_guard lock(logged_mutex);
    ++calls;
    if (logged_address != addr_ptr->ina.s_addr) {
      logged_address = addr_ptr->ina.s_addr;
      REXKRNL_INFO("XNetGetTitleXnAddr: caller={:08X} reported {:08X}{} (lan {:08X}) call={}",
                   uint32_t(caller), ntohl(addr_ptr->ina.s_addr),
                   self ? " gameplay logical" : "", ntohl(lan), calls);
    }
  }

  // TODO(gibbed): A proper mac address.
  // RakNet's 360 version appears to depend on abEnet to create "random" 64-bit
  // numbers. A zero value will cause RakPeer::Startup to fail. This causes
  // 58411436 to crash on startup.
  // The 360-specific code is scrubbed from the RakNet repo, but there's still
  // traces of what it's doing which match the game code.
  // https://github.com/facebookarchive/RakNet/blob/master/Source/RakPeer.cpp#L382
  // https://github.com/facebookarchive/RakNet/blob/master/Source/RakPeer.cpp#L4527
  // https://github.com/facebookarchive/RakNet/blob/master/Source/RakPeer.cpp#L4467
  // "Mac address is a poor solution because you can't have multiple connections
  // from the same system"
  const auto identity = rex::system::xam::ReconstructXnAddrIdentity(xuid);
  std::memcpy(addr_ptr->abEnet, identity.ethernet_address.data(),
              identity.ethernet_address.size());
  std::memcpy(addr_ptr->abOnline, identity.online_address.data(),
              identity.online_address.size());

  uint32_t status =
      XnAddrStatus::XNET_GET_XNADDR_DHCP | XnAddrStatus::XNET_GET_XNADDR_ETHERNET;
  return status;
}

u32 NetDll_XNetGetDebugXnAddr_entry(u32 caller, ppc_ptr_t<XNADDR> addr_ptr) {
  addr_ptr.Zero();

  // XNET_GET_XNADDR_NONE causes caller to gracefully return.
  return XnAddrStatus::XNET_GET_XNADDR_NONE;
}

u32 NetDll_XNetXnAddrToMachineId_entry(u32 caller, u32 addr_address, u32 id_address) {
  // The ABI output is ULONGLONG, not DWORD. Read/write the exact guest ranges
  // before dereferencing either pointer; unknown or ambiguous identities fail.
  auto* memory = REX_KERNEL_STATE()->memory();
#if REX_PLATFORM_GNU_LINUX
  memory::GuestMemoryAccessPin pin(memory->access_control());
  if (!pin.memory()) return 0x2726; // WSAEFAULT
  memory = pin.memory();
#endif
  std::array<uint8_t, 36> address{};
  if (!CopyArbitrationGuestInput(memory, addr_address, address)) return 0x2726;
  XnAddrIdentity identity;
  std::copy_n(address.begin() + 10, identity.ethernet_address.size(), identity.ethernet_address.begin());
  std::copy_n(address.begin() + 16, identity.online_address.size(), identity.online_address.begin());
  uint32_t ipv4 = 0, online_ipv4 = 0;
  std::memcpy(&ipv4, address.data(), sizeof(ipv4));
  std::memcpy(&online_ipv4, address.data() + 4, sizeof(online_ipv4));
  if (!ipv4) ipv4 = online_ipv4;
  const uint16_t port = uint16_t((uint16_t(address[8]) << 8) | address[9]);
  const auto machine_id = REX_KERNEL_STATE()->session_manager()->registry().FindArbitrationMachineId(
      identity, ipv4, port, REX_KERNEL_STATE()->user_profile()->xuid());
  if (!machine_id || !*machine_id) return 0x2741; // WSAEHOSTUNREACH
  std::array<uint8_t, 8> result{};
  auto value = *machine_id;
  for (size_t i = 0; i < result.size(); ++i) {
    result[result.size() - i - 1] = uint8_t(value); value >>= 8;
  }
  return CopyArbitrationGuestOutput(memory, id_address, result) ? 0 : 0x2726;
}

void NetDll_XNetInAddrToString_entry(u32 caller, u32 address, mapped_string string_out,
                                     u32 string_size) {
  in_addr native{};
  native.s_addr = htonl(address);
  const char* buffer = inet_ntoa(native);
  rex::string::copy_truncating(string_out, buffer ? buffer : "0.0.0.0", string_size);
}

// This converts a XNet address to an IN_ADDR. The IN_ADDR is used for
// subsequent socket calls (like a handle to a XNet address)
u32 NetDll_XNetXnAddrToInAddr_entry(u32 caller, ppc_ptr_t<XNADDR> xn_addr, mapped_void xid,
                                    mapped_void in_addr) {
  auto failed = [&](uint32_t result) {
    ReportBootstrapAddressFailure(caller, result);
    return result;
  };
  if (!xn_addr || !in_addr)
    return failed(0x2726);
  if (xid) {
    std::array<uint8_t, 8> session_id{};
    std::memcpy(session_id.data(), xid.host_address(), session_id.size());
    XnAddrIdentity identity;
    std::memcpy(identity.ethernet_address.data(), xn_addr->abEnet, identity.ethernet_address.size());
    std::memcpy(identity.online_address.data(), xn_addr->abOnline, identity.online_address.size());
    if (auto peer = GameplayXnAddrToLogical(session_id, identity)) {
      RecordGameplayTitleXid(*peer, xid.host_address());
      std::memcpy(in_addr.host_address(), &peer->logical.ipv4, sizeof(uint32_t));
      return 0;
    }
  }
  uint32_t address = xn_addr->ina.s_addr ? xn_addr->ina.s_addr : xn_addr->inaOnline.s_addr;
  if (IsGameplayLogicalAddress(address)) {
    // A third player's XNADDR arrives from the host already carrying the
    // directory-assigned logical address; GameplayLogicalToXnAddr refuses
    // ambiguous matches. The title's XID for other members need not equal the
    // runtime's peer session id, so a unique current logical match resolves
    // whatever the XID says; a mismatch is only logged.
    auto peer = GameplayLogicalToXnAddr(address);
    if (peer && xid && std::memcmp(xid.host_address(), peer->session_id.data(),
                                   peer->session_id.size()) != 0) {
      const auto expected = ReconstructXnAddrIdentity(peer->xuid);
      const bool own_identity =
          std::memcmp(xn_addr->abEnet, expected.ethernet_address.data(), expected.ethernet_address.size()) == 0 &&
          std::memcmp(xn_addr->abOnline, expected.online_address.data(), expected.online_address.size()) == 0;
      uint64_t title_xid = 0, peer_session = 0;
      for (size_t i = 0; i < 8; ++i) {
        title_xid = (title_xid << 8) | static_cast<const uint8_t*>(xid.host_address())[i];
        peer_session = (peer_session << 8) | peer->session_id[i];
      }
      REXKRNL_WARN("XNetXnAddrToInAddr: logical {:08X} title xid {:016X} differs from peer session {:016X} ({})",
                   ntohl(address), title_xid, peer_session,
                   own_identity ? "accepted, runtime-built address" : "accepted, host-built address");
    }
    if (peer) {
      if (xid) RecordGameplayTitleXid(*peer, xid.host_address());
      std::memcpy(in_addr.host_address(), &peer->logical.ipv4, sizeof(uint32_t));
      return 0;
    }
    REXKRNL_WARN("XNetXnAddrToInAddr: no current gameplay peer for logical {:08X} (xid={}) {}",
                 ntohl(address), bool(xid), DescribeGameplayLogical(address));
    return failed(0x2741);
  }
  if (!address)
    return failed(0x2741);
  std::memcpy(in_addr.host_address(), &address, sizeof(address));
  const uint32_t guest_address = ntohl(address);
  std::lock_guard lock(xnet_registry_mutex);
  xnet_address_registry[guest_address] = *xn_addr;
  return 0;
}

// Does the reverse of the above. IN_ADDR is a 32-bit value in the Xbox API,
// not a pointer to guest memory.
u32 NetDll_XNetInAddrToXnAddr_entry(u32 caller, u32 address, ppc_ptr_t<XNADDR> xn_addr,
                                    mapped_void xid) {
  if (!xn_addr)
    return 0x2726;
  if (auto peer = GameplayLogicalToXnAddr(htonl(address))) {
    xn_addr.Zero();
    xn_addr->ina.s_addr = peer->logical.ipv4;
    xn_addr->inaOnline.s_addr = peer->logical.ipv4;
    xn_addr->wPortOnline = peer->logical.port;
    const auto identity = ReconstructXnAddrIdentity(peer->xuid);
    std::memcpy(xn_addr->abEnet, identity.ethernet_address.data(), identity.ethernet_address.size());
    std::memcpy(xn_addr->abOnline, identity.online_address.data(), identity.online_address.size());
    if (xid) {
      auto session = peer->session_id;
      {
        std::lock_guard lock(xnet_registry_mutex);
        auto found = gameplay_title_xids.find(peer->logical.ipv4);
        if (found != gameplay_title_xids.end() && found->second.xuid == peer->xuid &&
            found->second.session == peer->session_id) {
          session = found->second.xid;
        } else if (auto title = gameplay_session_title_xids.find(GameplaySessionKey(peer->session_id));
                   title != gameplay_session_title_xids.end()) {
          session = title->second;
        } else if (peer->xuid != peer->host_xuid && xnet_last_registered_key_id) {
          // A member the title has not named yet (a newcomer that reached it
          // first): titles key other members by their registered session key.
          session = *xnet_last_registered_key_id;
        }
      }
      if (session != peer->session_id) {
        static std::unordered_map<uint32_t, uint64_t> logged;
        std::lock_guard lock(xnet_registry_mutex);
        if (logged.size() > 64) logged.clear();
        if (logged[peer->logical.ipv4] != GameplaySessionKey(session)) {
          logged[peer->logical.ipv4] = GameplaySessionKey(session);
          REXKRNL_INFO("XNetInAddrToXnAddr: logical {:08X} reported with title xid {:016X} "
                       "instead of peer session {:016X}",
                       ntohl(peer->logical.ipv4), GameplaySessionKey(session),
                       GameplaySessionKey(peer->session_id));
        }
      }
      std::memcpy(xid.host_address(), session.data(), session.size());
    }
    return 0;
  }
  if (IsGameplayLogicalAddress(htonl(address))) return 0x2741;
  std::lock_guard lock(xnet_registry_mutex);
  auto it = xnet_address_registry.find(address);
  if (it != xnet_address_registry.end()) {
    *xn_addr = it->second;
  } else {
    xn_addr.Zero();
    xn_addr->ina.s_addr = htonl(address);
    xn_addr->inaOnline.s_addr = htonl(address);
    const auto ethernet_address = SyntheticEthernetAddress(address);
    std::memcpy(xn_addr->abEnet, ethernet_address.data(), ethernet_address.size());
  }
  return 0;
}

u32 NetDll_XNetRegisterKey_entry(u32 caller, mapped_void key_id, mapped_void key) {
  if (!key_id || !key)
    return 0x2726;
  std::array<uint8_t, 16> value{};
  std::memcpy(value.data(), key.host_address(), value.size());
  std::lock_guard lock(xnet_registry_mutex);
  xnet_key_registry[LoadKeyId(key_id)] = value;
  std::array<uint8_t, 8> raw_key_id{};
  std::memcpy(raw_key_id.data(), key_id.host_address(), raw_key_id.size());
  xnet_last_registered_key_id = raw_key_id;
  return 0;
}
u32 NetDll_XNetReplaceKey_entry(u32 caller, mapped_void key_id, mapped_void key) {
  return NetDll_XNetRegisterKey_entry(caller, key_id, key);
}
u32 NetDll_XNetUnregisterInAddr_entry(u32 caller, u32 address) {
  std::lock_guard lock(xnet_registry_mutex);
  xnet_address_registry.erase(address);
  return 0;
}
u32 NetDll_XNetConnect_entry(u32 caller, u32 address) {
  if (GameplayLogicalToXnAddr(htonl(address))) return 0;
  std::lock_guard lock(xnet_registry_mutex);
  return xnet_address_registry.contains(address) ? 0 : 0x2741;
}
u32 NetDll_XNetGetConnectStatus_entry(u32 caller, u32 address) {
  if (GameplayLogicalToXnAddr(htonl(address))) return 2;
  std::lock_guard lock(xnet_registry_mutex);
  // XNET_CONNECT_STATUS_CONNECTED.
  return xnet_address_registry.contains(address) ? 2 : 0;
}

// https://www.google.com/patents/WO2008112448A1?cl=en
// Reserves a port for use by system link
u32 NetDll_XNetSetSystemLinkPort_entry(u32 caller, u32 port) {
  return 1;
}

// https://github.com/ILOVEPIE/Cxbx-Reloaded/blob/master/src/CxbxKrnl/EmuXOnline.h#L39
struct XEthernetStatus {
  static const uint32_t XNET_ETHERNET_LINK_ACTIVE = 0x01;
  static const uint32_t XNET_ETHERNET_LINK_100MBPS = 0x02;
  static const uint32_t XNET_ETHERNET_LINK_10MBPS = 0x04;
  static const uint32_t XNET_ETHERNET_LINK_FULL_DUPLEX = 0x08;
  static const uint32_t XNET_ETHERNET_LINK_HALF_DUPLEX = 0x10;
};

u32 NetDll_XNetGetEthernetLinkStatus_entry(u32 caller) {
  return XEthernetStatus::XNET_ETHERNET_LINK_ACTIVE | XEthernetStatus::XNET_ETHERNET_LINK_100MBPS |
         XEthernetStatus::XNET_ETHERNET_LINK_FULL_DUPLEX;
}

u32 NetDll_XNetDnsLookup_entry(u32 caller, mapped_string host, u32 event_handle, mapped_u32 pdns) {
  // TODO(gibbed): actually implement this
  if (pdns) {
    auto dns_guest = REX_KERNEL_MEMORY()->SystemHeapAlloc(sizeof(XNDNS));
    auto dns = REX_KERNEL_MEMORY()->TranslateVirtual<XNDNS*>(dns_guest);
    dns->status = 1;  // non-zero = error
    *pdns = dns_guest;
  }
  if (event_handle) {
    auto ev = REX_KERNEL_OBJECTS()->LookupObject<XEvent>(event_handle);
    assert_not_null(ev);
    ev->Set(0, false);
  }
  return 0;
}

u32 NetDll_XNetDnsRelease_entry(u32 caller, ppc_ptr_t<XNDNS> dns) {
  if (!dns) {
    return X_STATUS_INVALID_PARAMETER;
  }
  REX_KERNEL_MEMORY()->SystemHeapFree(dns.guest_address());
  return 0;
}

u32 NetDll_XNetQosServiceLookup_entry(u32 caller, u32 flags, u32 event_handle, mapped_u32 pqos) {
  // Set pqos as some games will try accessing it despite non-successful result
  if (pqos) {
    auto qos_guest = REX_KERNEL_MEMORY()->SystemHeapAlloc(sizeof(XNQOS));
    auto qos = REX_KERNEL_MEMORY()->TranslateVirtual<XNQOS*>(qos_guest);
    qos->count = qos->count_pending = 0;
    *pqos = qos_guest;
  }
  if (event_handle) {
    auto ev = REX_KERNEL_OBJECTS()->LookupObject<XEvent>(event_handle);
    assert_not_null(ev);
    ev->Set(0, false);
  }
  return 0;
}

u32 NetDll_XNetQosLookup_entry(u32 caller, u32 xnaddr_count, mapped_void xnaddr_array,
                               mapped_void key_id_array, mapped_void key_array, u32 in_addr_count,
                               mapped_void in_addr_array, mapped_void service_id_array,
                               u32 probe_count, u32 bits_per_second, u32 flags, u32 event_handle,
                               mapped_u32 qos_out) {
  if (!qos_out)
    return 0x2726;
  uint32_t result_count = xnaddr_count + in_addr_count;
  size_t allocation_size = sizeof(XNQOS);
  if (result_count > 1)
    allocation_size += (result_count - 1) * sizeof(XNQOSINFO);
  auto qos_guest = REX_KERNEL_MEMORY()->SystemHeapAlloc(allocation_size);
  auto* qos = REX_KERNEL_MEMORY()->TranslateVirtual<XNQOS*>(qos_guest);
  std::memset(qos, 0, allocation_size);
  qos->count = result_count;
  qos->count_pending = 0;
  for (uint32_t i = 0; i < result_count; ++i) {
    auto& info = qos->info[i];
    // LAN peers discovered by the session service are immediately usable by
    // the title's UDP transport. Report a completed, contacted result without
    // pretending to perform Xbox Live security or bandwidth probing.
    info.flags = 0x01 | 0x02;
    info.probes_xmit = uint16_t(std::min(probe_count, 0xFFFFu));
    info.probes_recv = info.probes_xmit;
    info.rtt_min_in_msecs = 1;
    info.rtt_med_in_msecs = 1;
    info.up_bits_per_sec = bits_per_second ? bits_per_second : 100000000;
    info.down_bits_per_sec = bits_per_second ? bits_per_second : 100000000;
  }
  *qos_out = qos_guest;
  if (event_handle) {
    auto ev = REX_KERNEL_OBJECTS()->LookupObject<XEvent>(event_handle);
    if (ev)
      ev->Set(0, false);
  }
  return 0;
}

u32 NetDll_XNetQosRelease_entry(u32 caller, ppc_ptr_t<XNQOS> qos) {
  if (!qos) {
    return X_STATUS_INVALID_PARAMETER;
  }
  REX_KERNEL_MEMORY()->SystemHeapFree(qos.guest_address());
  return 0;
}

u32 NetDll_XNetQosListen_entry(u32 caller, mapped_void id, mapped_void data, u32 data_size, u32 r7,
                               u32 flags) {
  // The first LAN milestone does not probe the payload. Accept enable/disable,
  // data, bandwidth and release updates so the title can proceed to lookup.
  return 0;
}

u32 NetDll_inet_addr_entry(mapped_string addr_ptr) {
  if (!addr_ptr) {
    return -1;
  }

  uint32_t addr = inet_addr(addr_ptr);
  // https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-inet_addr#return-value
  // Based on console research it seems like x360 uses old version of inet_addr
  // In case of empty string it return 0 instead of -1
  if (addr == -1 && !addr_ptr.value().length()) {
    return 0;
  }

  return rex::byte_swap(addr);
}

u32 NetDll_socket_entry(u32 caller, u32 af, u32 type, u32 protocol) {
  XSocket* socket = new XSocket(REX_KERNEL_STATE());
  X_STATUS result =
      socket->Initialize(XSocket::AddressFamily((uint32_t)af), XSocket::Type((uint32_t)type),
                         XSocket::Protocol((uint32_t)protocol));

  if (XFAILED(result)) {
    socket->Release();

    uint32_t error = xboxkrnl::xeRtlNtStatusToDosError(result);
    XThread::SetLastError(error);
    return -1;
  }
  RetireBootstrapSocketResults(socket->handle());
  return socket->handle();
}

u32 NetDll_closesocket_entry(u32 caller, u32 socket_handle) {
  // Serialize close with receive completion so no receive can touch its guest
  // buffers after cancellation has been published. Keep the result until query.
  std::lock_guard lock(pending_recv_mutex);
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    REXKRNL_WARN("GAMEPLAY_SOCKET_CLOSE_REQUEST caller={:08X} guest_socket={} found=0",
                 caller, socket_handle);
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  REXKRNL_INFO(
      "GAMEPLAY_SOCKET_CLOSE_REQUEST caller={:08X} guest_socket={} native={} found=1",
      caller, socket_handle, socket->native_handle());

  RetireBootstrapSocketResults(socket_handle);

  // TODO: Absolutely delete this object. It is no longer valid after calling
  // closesocket.
  socket->Close();
  CancelPendingSocketSends(REX_KERNEL_STATE(), socket.get());
  for (auto& [_, pending] : pending_recvs) {
    if (pending.socket_handle != socket_handle || pending.complete)
      continue;
    pending.error = 995;  // WSA_OPERATION_ABORTED
    auto* overlapped = REX_KERNEL_MEMORY()->TranslateVirtual<XWSAOVERLAPPED*>(pending.overlapped_ptr);
    overlapped->internal = 0xC0000120;  // STATUS_CANCELLED
    overlapped->internal_high = 0;
    if (overlapped->event_handle) {
      auto event = REX_KERNEL_OBJECTS()->LookupObject<XEvent>(overlapped->event_handle);
      if (event)
        event->Set(0, false);
    }
    pending.complete = true;
  }
  socket->ReleaseHandle();
  pending_recv_changed.notify_all();
  return 0;
}

i32 NetDll_shutdown_entry(u32 caller, u32 socket_handle, i32 how) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  auto ret = socket->Shutdown(how);
  if (ret == -1) {
    XThread::SetLastError(LastSocketError());
  }
  return ret;
}

u32 NetDll_setsockopt_entry(u32 caller, u32 socket_handle, u32 level, u32 optname,
                            mapped_void optval_ptr, u32 optlen) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  X_STATUS status = socket->SetOption(level, optname, optval_ptr, optlen);
  if (XFAILED(status)) {
    XThread::SetLastError(LastSocketError());
    return -1;
  }
  return 0;
}

u32 NetDll_ioctlsocket_entry(u32 caller, u32 socket_handle, u32 cmd, mapped_void arg_ptr) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  X_STATUS status = socket->IOControl(cmd, arg_ptr);
  if (XFAILED(status)) {
    XThread::SetLastError(LastSocketError());
    return -1;
  }
  return 0;
}

u32 NetDll_bind_entry(u32 caller, u32 socket_handle, ppc_ptr_t<XSOCKADDR_IN> name, u32 namelen) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  N_XSOCKADDR_IN native_name(name);
  if (uint32_t(native_name.sin_addr) == INADDR_ANY) {
    native_name.sin_addr = ntohl(LanDiscoveryService::DetermineLanIpv4());
  }
  const uint32_t configured_gameplay_port = REXCVAR_GET(lan_gameplay_port);
  if (configured_gameplay_port != 0) {
    socket->ConfigurePortTranslation(uint16_t(native_name.sin_port),
                                     uint16_t(configured_gameplay_port));
    native_name.sin_port = uint16_t(configured_gameplay_port);
  }
  X_STATUS status = socket->Bind(&native_name, namelen);
  if (XFAILED(status)) {
    XThread::SetLastError(LastSocketError());
    return -1;
  }
  uint16_t bound_port = ntohs(socket->bound_port());
  auto* state = REX_KERNEL_STATE();
  auto* profile = state->user_profile();
  size_t updated_sessions =
      profile ? state->session_manager()->registry().UpdateHostedPort(profile->xuid(), bound_port)
              : 0;
  REXKRNL_INFO(
      "NetDll_bind: socket={:08X} address={:08X}:{} updated_host_sessions={}", socket_handle,
      htonl(uint32_t(native_name.sin_addr)), bound_port, updated_sessions);
  return 0;
}

u32 NetDll_connect_entry(u32 caller, u32 socket_handle, ppc_ptr_t<XSOCKADDR> name, u32 namelen) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  N_XSOCKADDR native_name(name);
  X_STATUS status = socket->Connect(&native_name, namelen);
  if (XFAILED(status)) {
    XThread::SetLastError(LastSocketError());
    return -1;
  }

  return 0;
}

u32 NetDll_listen_entry(u32 caller, u32 socket_handle, i32 backlog) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  X_STATUS status = socket->Listen(backlog);
  if (XFAILED(status)) {
    XThread::SetLastError(LastSocketError());
    return -1;
  }

  return 0;
}

u32 NetDll_accept_entry(u32 caller, u32 socket_handle, ppc_ptr_t<XSOCKADDR> addr_ptr,
                        mapped_u32 addrlen_ptr) {
  if (!addr_ptr) {
    // WSAEFAULT
    XThread::SetLastError(0x271E);
    return -1;
  }

  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  N_XSOCKADDR native_addr(addr_ptr);
  int native_len = *addrlen_ptr;
  auto new_socket = socket->Accept(&native_addr, &native_len);
  if (new_socket) {
    addr_ptr->address_family = native_addr.address_family;
    std::memcpy(addr_ptr->sa_data, native_addr.sa_data, *addrlen_ptr - 2);
    *addrlen_ptr = native_len;

    RetireBootstrapSocketResults(new_socket->handle());
    return new_socket->handle();
  } else {
    return -1;
  }
}

struct x_fd_set {
  rex::be<uint32_t> fd_count;
  rex::be<uint32_t> fd_array[64];
};

struct host_set {
  uint32_t count;
  object_ref<XSocket> sockets[64];
  X_HANDLE guest_handles[64];
  XSocket::NativeLease operations[64];

  bool Retired() const {
    for (uint32_t i = 0; i < count; ++i) if (operations[i].retired()) return true;
    return false;
  }

  bool Load(const x_fd_set* guest_set) {
    const uint32_t supplied = guest_set->fd_count;
    if (supplied > 64) {
      XThread::SetLastError(10022);
      return false;
    }
    this->count = 0;
    for (uint32_t i = 0; i < supplied; ++i) {
      const auto socket_handle = static_cast<X_HANDLE>(guest_set->fd_array[i]);
      auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
      auto operation = socket ? socket->AcquireNativeLease() : XSocket::NativeLease{};
      if (!operation) {
        XThread::SetLastError(10038);
        return false;
      }
      bool duplicate = false;
      for (uint32_t j = 0; j < this->count; ++j)
        duplicate |= this->guest_handles[j] == socket_handle;
      if (!duplicate) {
        this->guest_handles[this->count] = socket_handle;
        this->sockets[this->count] = socket;
        this->operations[this->count++] = std::move(operation);
      }
    }
    return true;
  }

  void Store(x_fd_set* guest_set) {
    guest_set->fd_count = 0;
    for (uint32_t i = 0; i < this->count; ++i) {
      guest_set->fd_array[guest_set->fd_count++] = this->guest_handles[i];
    }
  }

  void Store(fd_set* native_set) {
    FD_ZERO(native_set);
    for (uint32_t i = 0; i < this->count; ++i) {
      FD_SET(this->operations[i].handle(), native_set);
    }
  }

  void UpdateFrom(fd_set* native_set) {
    uint32_t new_count = 0;
    for (uint32_t i = 0; i < this->count; ++i) {
      auto socket = this->sockets[i];
      if (FD_ISSET(this->operations[i].handle(), native_set)) {
        this->operations[new_count] = this->operations[i];
        this->guest_handles[new_count] = this->guest_handles[i];
        this->sockets[new_count++] = socket;
      }
    }
    this->count = new_count;
  }
};

i32 NetDll_select_entry(i32 caller, i32 nfds, ppc_ptr_t<x_fd_set> readfds,
                        ppc_ptr_t<x_fd_set> writefds, ppc_ptr_t<x_fd_set> exceptfds,
                        mapped_void timeout_ptr) {
  host_set host_readfds = {}, host_writefds = {}, host_exceptfds = {};
  if ((readfds && !host_readfds.Load(readfds)) ||
      (writefds && !host_writefds.Load(writefds)) ||
      (exceptfds && !host_exceptfds.Load(exceptfds)))
    return -1;
  if (!host_readfds.count && !host_writefds.count && !host_exceptfds.count) {
    XThread::SetLastError(10022);
    return -1;
  }
  // Guest timeval fields are BE32 even where native long is 64 bits. Scale
  // actual int32 locals; casting native timeval fields to int32* corrupts them.
  int32_t seconds = 0, microseconds = 0;
  if (timeout_ptr) {
    seconds = timeout_ptr.as_array<int32_t>()[0];
    microseconds = timeout_ptr.as_array<int32_t>()[1];
    if (seconds < 0 || microseconds < 0 || microseconds >= 1000000) {
      XThread::SetLastError(10022);
      return -1;
    }
    chrono::Clock::ScaleGuestDurationTimeval(&seconds, &microseconds);
  }
#if REX_PLATFORM_LINUX
  // poll preserves Winsock's ignored nfds argument and guest handle arrays,
  // while avoiding Linux select's FD_SETSIZE stack-overflow limit.
  std::vector<pollfd> descriptors;
  auto append = [&](const host_set& set, short events) {
    for (uint32_t i = 0; i < set.count; ++i) {
      const int descriptor = static_cast<int>(set.operations[i].handle());
      auto found = std::find_if(descriptors.begin(), descriptors.end(),
                               [&](const auto& value) { return value.fd == descriptor; });
      if (found == descriptors.end()) descriptors.push_back({descriptor, events, 0});
      else found->events |= events;
    }
  };
  append(host_readfds, POLLIN);
  append(host_writefds, POLLOUT);
  append(host_exceptfds, POLLPRI);
  auto append_cancellation = [&](const host_set& set) {
    for (uint32_t i = 0; i < set.count; ++i) {
      const int descriptor = set.operations[i].cancellation_handle();
      if (descriptor < 0) continue;
      if (std::none_of(descriptors.begin(), descriptors.end(),
                      [&](const auto& value) { return value.fd == descriptor; }))
        descriptors.push_back({descriptor, POLLIN, 0});
    }
  };
  append_cancellation(host_readfds);
  append_cancellation(host_writefds);
  append_cancellation(host_exceptfds);
  timespec timeout{seconds, static_cast<long>(microseconds) * 1000};
  const int result = ppoll(descriptors.data(), descriptors.size(),
                           timeout_ptr ? &timeout : nullptr, nullptr);
  if (result < 0) {
    XThread::SetLastError(LastSocketError());
    return -1;
  }
  if (host_readfds.Retired() || host_writefds.Retired() || host_exceptfds.Retired() ||
      std::any_of(descriptors.begin(), descriptors.end(),
                  [](const auto& value) { return value.revents & POLLNVAL; })) {
    XThread::SetLastError(10038);
    return -1;
  }
  auto update = [&](host_set& set, short ready) {
    uint32_t new_count = 0;
    for (uint32_t i = 0; i < set.count; ++i) {
      const int descriptor = static_cast<int>(set.operations[i].handle());
      const auto found = std::find_if(descriptors.begin(), descriptors.end(),
                               [&](const auto& value) { return value.fd == descriptor; });
      if (found != descriptors.end() && (found->revents & ready)) {
        set.operations[new_count] = set.operations[i];
        set.guest_handles[new_count] = set.guest_handles[i];
        set.sockets[new_count++] = set.sockets[i];
      }
    }
    set.count = new_count;
  };
  update(host_readfds, POLLIN | POLLHUP | POLLERR);
  update(host_writefds, POLLOUT | POLLERR);
  update(host_exceptfds, POLLPRI);
  if (readfds) host_readfds.Store(readfds);
  if (writefds) host_writefds.Store(writefds);
  if (exceptfds) host_exceptfds.Store(exceptfds);
  return host_readfds.count + host_writefds.count + host_exceptfds.count;
#else
  fd_set native_readfds{}, native_writefds{}, native_exceptfds{};
  if (readfds) host_readfds.Store(&native_readfds);
  if (writefds) host_writefds.Store(&native_writefds);
  if (exceptfds) host_exceptfds.Store(&native_exceptfds);
  timeval timeout{seconds, microseconds};
#if REX_PLATFORM_WIN32
  // Winsock shutdown does not wake a select blocked on an unconnected UDP
  // socket, so Close pokes a per-socket loopback wake socket; watch those too.
  bool wake_watched = false;
  auto append_wake = [&](const host_set& set) {
    for (uint32_t i = 0; i < set.count; ++i) {
      const auto wake = static_cast<SOCKET>(set.operations[i].wake_handle());
      if (wake == INVALID_SOCKET || FD_ISSET(wake, &native_readfds)) continue;
      if (native_readfds.fd_count >= FD_SETSIZE) {
        REXKRNL_ERROR("NetDll_select: no room for wake socket of native={}", set.operations[i].handle());
        continue;
      }
      FD_SET(wake, &native_readfds);
      wake_watched = true;
    }
  };
  append_wake(host_readfds);
  append_wake(host_writefds);
  append_wake(host_exceptfds);
  int ret = select(nfds, (readfds || wake_watched) ? &native_readfds : nullptr,
                   writefds ? &native_writefds : nullptr,
#else
  int ret = select(nfds, readfds ? &native_readfds : nullptr, writefds ? &native_writefds : nullptr,
#endif
                   exceptfds ? &native_exceptfds : nullptr, timeout_ptr ? &timeout : nullptr);
  if (ret < 0) {
    XThread::SetLastError(LastSocketError());
    return -1;
  }
#if REX_PLATFORM_WIN32
  auto wake_ready = [&](const host_set& set) {
    for (uint32_t i = 0; i < set.count; ++i) {
      const auto wake = static_cast<SOCKET>(set.operations[i].wake_handle());
      if (wake != INVALID_SOCKET && FD_ISSET(wake, &native_readfds)) return true;
    }
    return false;
  };
  if (ret > 0 && (wake_ready(host_readfds) || wake_ready(host_writefds) || wake_ready(host_exceptfds))) {
    XThread::SetLastError(10038);
    return -1;
  }
#endif
  if (host_readfds.Retired() || host_writefds.Retired() || host_exceptfds.Retired()) {
    XThread::SetLastError(10038);
    return -1;
  }
  if (readfds) { host_readfds.UpdateFrom(&native_readfds); host_readfds.Store(readfds); }
  if (writefds) { host_writefds.UpdateFrom(&native_writefds); host_writefds.Store(writefds); }
  if (exceptfds) { host_exceptfds.UpdateFrom(&native_exceptfds); host_exceptfds.Store(exceptfds); }
  return ret;
#endif
}

u32 NetDll_recv_entry(u32 caller, u32 socket_handle, mapped_void buf_ptr, u32 buf_len, u32 flags) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  const int result = socket->Recv(buf_ptr, buf_len, flags);
  if (result < 0) XThread::SetLastError(LastSocketError());
  return result;
}

u32 NetDll_recvfrom_entry(u32 caller, u32 socket_handle, mapped_void buf_ptr, u32 buf_len,
                          u32 flags, ppc_ptr_t<XSOCKADDR_IN> from_ptr, mapped_u32 fromlen_ptr) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) {
    // WSAENOTSOCK
    XThread::SetLastError(0x2736);
    return -1;
  }

  N_XSOCKADDR_IN native_from{};
  if (from_ptr) {
    native_from = *from_ptr;
  }
  uint32_t native_fromlen = fromlen_ptr ? fromlen_ptr.value() : 0;
  int ret =
      socket->RecvFrom(buf_ptr, buf_len, flags, &native_from, fromlen_ptr ? &native_fromlen : 0);

  if (ret >= 0 && from_ptr) {
    from_ptr->sin_family = native_from.sin_family;
    from_ptr->sin_port = native_from.sin_port;
    from_ptr->sin_addr = native_from.sin_addr;
    std::memset(from_ptr->x_sin_zero, 0, sizeof(from_ptr->x_sin_zero));
  }
  if (ret >= 0 && fromlen_ptr) {
    *fromlen_ptr = native_fromlen;
  }

  if (ret == -1) {
// TODO: Better way of getting the error code
    XThread::SetLastError(LastSocketError());
  }

  return ret;
}

u32 NetDll_send_entry(u32 caller, u32 socket_handle, mapped_void buf_ptr, u32 buf_len, u32 flags) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) { XThread::SetLastError(10038); return -1; }
  const auto operation = socket->AcquireNativeLease();
  if (!operation) { XThread::SetLastError(10038); return -1; }
  uint32_t maximum = 0;
  if (!SendLimit(operation, &maximum)) return -1;
  if (buf_len > maximum) { XThread::SetLastError(kWsaMessageSize); return -1; }
  std::vector<uint8_t> staged;
  try {
#if REX_PLATFORM_GNU_LINUX
    memory::MappingAccessLease lease;
#endif
    staged.resize(buf_len);
    if (!ReadSendGuest(REX_KERNEL_MEMORY(), buf_ptr.guest_address(), buf_ptr.host_address(),
                       staged.data(), buf_len)) {
      XThread::SetLastError(kWsaFault);
      return -1;
    }
  } catch (const std::bad_alloc&) {
    XThread::SetLastError(kWsaNoBuffers);
    return -1;
  }
  const int result = socket->Send(staged.data(), buf_len, flags);
  if (result < 0) XThread::SetLastError(LastSocketError());
  return result;
}

u32 NetDll_sendto_entry(u32 caller, u32 socket_handle, mapped_void buf_ptr, u32 buf_len, u32 flags,
                        ppc_ptr_t<XSOCKADDR_IN> to_ptr, u32 to_len) {
  auto socket = REX_KERNEL_OBJECTS()->LookupObject<XSocket>(socket_handle);
  if (!socket) { XThread::SetLastError(10038); return -1; }
  const auto operation = socket->AcquireNativeLease();
  if (!operation) { XThread::SetLastError(10038); return -1; }
  uint32_t maximum = 0;
  if (!SendLimit(operation, &maximum)) return -1;
  if (buf_len > maximum) { XThread::SetLastError(kWsaMessageSize); return -1; }
  N_XSOCKADDR_IN native_to{};
  std::vector<uint8_t> staged;
  try {
#if REX_PLATFORM_GNU_LINUX
    memory::MappingAccessLease lease;
#endif
    auto* memory = REX_KERNEL_MEMORY();
    if (!StageSendDestination(memory, to_ptr, to_len, &native_to)) return -1;
    staged.resize(buf_len);
    if (!ReadSendGuest(memory, buf_ptr.guest_address(), buf_ptr.host_address(),
                       staged.data(), buf_len)) {
      XThread::SetLastError(kWsaFault);
      return -1;
    }
  } catch (const std::bad_alloc&) {
    XThread::SetLastError(kWsaNoBuffers);
    return -1;
  }
  const int result = socket->SendTo(staged.data(), buf_len, flags,
                                    to_ptr ? &native_to : nullptr, to_len);
  if (result < 0) XThread::SetLastError(LastSocketError());
  return result;
}

u32 NetDll___WSAFDIsSet_entry(u32 socket_handle, ppc_ptr_t<x_fd_set> fd_set) {
  const uint8_t max_fd_count = std::min((uint32_t)fd_set->fd_count, uint32_t(64));
  for (uint8_t i = 0; i < max_fd_count; i++) {
    if (fd_set->fd_array[i] == socket_handle) {
      return 1;
    }
  }
  return 0;
}

void NetDll_WSASetLastError_entry(u32 error_code) {
  XThread::SetLastError(error_code);
}

}  // namespace xam
}  // namespace kernel
}  // namespace rex

REX_EXPORT(__imp__NetDll_XNetStartup, rex::kernel::xam::NetDll_XNetStartup_entry)
REX_EXPORT(__imp__NetDll_XNetCleanup, rex::kernel::xam::NetDll_XNetCleanup_entry)
REX_EXPORT(__imp__NetDll_XNetGetOpt, rex::kernel::xam::NetDll_XNetGetOpt_entry)
REX_EXPORT(__imp__NetDll_XNetRandom, rex::kernel::xam::NetDll_XNetRandom_entry)
REX_EXPORT(__imp__NetDll_WSAStartup, rex::kernel::xam::NetDll_WSAStartup_entry)
REX_EXPORT(__imp__NetDll_WSACleanup, rex::kernel::xam::NetDll_WSACleanup_entry)
REX_EXPORT(__imp__NetDll_WSAGetLastError, rex::kernel::xam::NetDll_WSAGetLastError_entry)
REX_EXPORT(__imp__NetDll_WSAGetOverlappedResult,
           rex::kernel::xam::NetDll_WSAGetOverlappedResult_entry)
REX_EXPORT(__imp__NetDll_WSARecvFrom, rex::kernel::xam::NetDll_WSARecvFrom_entry)
REX_EXPORT(__imp__NetDll_WSASendTo, rex::kernel::xam::NetDll_WSASendTo_entry)
REX_EXPORT(__imp__NetDll_WSAWaitForMultipleEvents,
           rex::kernel::xam::NetDll_WSAWaitForMultipleEvents_entry)
REX_EXPORT(__imp__NetDll_WSACreateEvent, rex::kernel::xam::NetDll_WSACreateEvent_entry)
REX_EXPORT(__imp__NetDll_WSACloseEvent, rex::kernel::xam::NetDll_WSACloseEvent_entry)
REX_EXPORT(__imp__NetDll_WSAResetEvent, rex::kernel::xam::NetDll_WSAResetEvent_entry)
REX_EXPORT(__imp__NetDll_WSASetEvent, rex::kernel::xam::NetDll_WSASetEvent_entry)
REX_EXPORT(__imp__NetDll_XNetGetTitleXnAddr, rex::kernel::xam::NetDll_XNetGetTitleXnAddr_entry)
REX_EXPORT(__imp__NetDll_XNetGetDebugXnAddr, rex::kernel::xam::NetDll_XNetGetDebugXnAddr_entry)
REX_EXPORT(__imp__NetDll_XNetXnAddrToMachineId,
           rex::kernel::xam::NetDll_XNetXnAddrToMachineId_entry)
REX_EXPORT(__imp__NetDll_XNetInAddrToString, rex::kernel::xam::NetDll_XNetInAddrToString_entry)
REX_EXPORT(__imp__NetDll_XNetXnAddrToInAddr, rex::kernel::xam::NetDll_XNetXnAddrToInAddr_entry)
REX_EXPORT(__imp__NetDll_XNetInAddrToXnAddr, rex::kernel::xam::NetDll_XNetInAddrToXnAddr_entry)
REX_EXPORT(__imp__NetDll_XNetSetSystemLinkPort,
           rex::kernel::xam::NetDll_XNetSetSystemLinkPort_entry)
REX_EXPORT(__imp__NetDll_XNetGetEthernetLinkStatus,
           rex::kernel::xam::NetDll_XNetGetEthernetLinkStatus_entry)
REX_EXPORT(__imp__NetDll_XNetDnsLookup, rex::kernel::xam::NetDll_XNetDnsLookup_entry)
REX_EXPORT(__imp__NetDll_XNetDnsRelease, rex::kernel::xam::NetDll_XNetDnsRelease_entry)
REX_EXPORT(__imp__NetDll_XNetQosServiceLookup, rex::kernel::xam::NetDll_XNetQosServiceLookup_entry)
REX_EXPORT(__imp__NetDll_XNetQosRelease, rex::kernel::xam::NetDll_XNetQosRelease_entry)
REX_EXPORT(__imp__NetDll_XNetQosListen, rex::kernel::xam::NetDll_XNetQosListen_entry)
REX_EXPORT(__imp__NetDll_inet_addr, rex::kernel::xam::NetDll_inet_addr_entry)
REX_EXPORT(__imp__NetDll_socket, rex::kernel::xam::NetDll_socket_entry)
REX_EXPORT(__imp__NetDll_closesocket, rex::kernel::xam::NetDll_closesocket_entry)
REX_EXPORT(__imp__NetDll_shutdown, rex::kernel::xam::NetDll_shutdown_entry)
REX_EXPORT(__imp__NetDll_setsockopt, rex::kernel::xam::NetDll_setsockopt_entry)
REX_EXPORT(__imp__NetDll_ioctlsocket, rex::kernel::xam::NetDll_ioctlsocket_entry)
REX_EXPORT(__imp__NetDll_bind, rex::kernel::xam::NetDll_bind_entry)
REX_EXPORT(__imp__NetDll_connect, rex::kernel::xam::NetDll_connect_entry)
REX_EXPORT(__imp__NetDll_listen, rex::kernel::xam::NetDll_listen_entry)
REX_EXPORT(__imp__NetDll_accept, rex::kernel::xam::NetDll_accept_entry)
REX_EXPORT(__imp__NetDll_select, rex::kernel::xam::NetDll_select_entry)
REX_EXPORT(__imp__NetDll_recv, rex::kernel::xam::NetDll_recv_entry)
REX_EXPORT(__imp__NetDll_recvfrom, rex::kernel::xam::NetDll_recvfrom_entry)
REX_EXPORT(__imp__NetDll_send, rex::kernel::xam::NetDll_send_entry)
REX_EXPORT(__imp__NetDll_sendto, rex::kernel::xam::NetDll_sendto_entry)
REX_EXPORT(__imp__NetDll___WSAFDIsSet, rex::kernel::xam::NetDll___WSAFDIsSet_entry)
REX_EXPORT(__imp__NetDll_WSASetLastError, rex::kernel::xam::NetDll_WSASetLastError_entry)

REX_EXPORT_STUB(__imp__NetDll_UpnpActionCalculateWorkBufferSize);
REX_EXPORT_STUB(__imp__NetDll_UpnpActionCreate);
REX_EXPORT_STUB(__imp__NetDll_UpnpActionGetResults);
REX_EXPORT_STUB(__imp__NetDll_UpnpCleanup);
REX_EXPORT_STUB(__imp__NetDll_UpnpCloseHandle);
REX_EXPORT_STUB(__imp__NetDll_UpnpDescribeCreate);
REX_EXPORT_STUB(__imp__NetDll_UpnpDescribeGetResults);
REX_EXPORT_STUB(__imp__NetDll_UpnpDoWork);
REX_EXPORT_STUB(__imp__NetDll_UpnpEventCreate);
REX_EXPORT_STUB(__imp__NetDll_UpnpEventGetCurrentState);
REX_EXPORT_STUB(__imp__NetDll_UpnpEventUnsubscribe);
REX_EXPORT_STUB(__imp__NetDll_UpnpSearchCreate);
REX_EXPORT_STUB(__imp__NetDll_UpnpSearchGetDevices);
REX_EXPORT_STUB(__imp__NetDll_UpnpStartup);
REX_EXPORT_STUB(__imp__NetDll_WSACancelOverlappedIO);
REX_EXPORT_STUB(__imp__NetDll_WSAEventSelect);
REX_EXPORT_STUB(__imp__NetDll_WSARecv);
REX_EXPORT_STUB(__imp__NetDll_WSASend);
REX_EXPORT_STUB(__imp__NetDll_WSAStartupEx);
REX_EXPORT_STUB(__imp__NetDll_XHttpCloseHandle);
REX_EXPORT_STUB(__imp__NetDll_XHttpConnect);
REX_EXPORT_STUB(__imp__NetDll_XHttpCrackUrl);
REX_EXPORT_STUB(__imp__NetDll_XHttpCrackUrlW);
REX_EXPORT_STUB(__imp__NetDll_XHttpCreateUrl);
REX_EXPORT_STUB(__imp__NetDll_XHttpCreateUrlW);
REX_EXPORT_STUB(__imp__NetDll_XHttpDoWork);
REX_EXPORT_STUB(__imp__NetDll_XHttpGetPerfCounters);
REX_EXPORT_STUB(__imp__NetDll_XHttpOpen);
REX_EXPORT_STUB(__imp__NetDll_XHttpOpenRequest);
REX_EXPORT_STUB(__imp__NetDll_XHttpOpenRequestUsingMemory);
REX_EXPORT_STUB(__imp__NetDll_XHttpQueryAuthSchemes);
REX_EXPORT_STUB(__imp__NetDll_XHttpQueryHeaders);
REX_EXPORT_STUB(__imp__NetDll_XHttpQueryOption);
REX_EXPORT_STUB(__imp__NetDll_XHttpReadData);
REX_EXPORT_STUB(__imp__NetDll_XHttpReceiveResponse);
REX_EXPORT_STUB(__imp__NetDll_XHttpResetPerfCounters);
REX_EXPORT_STUB(__imp__NetDll_XHttpSendRequest);
REX_EXPORT_STUB(__imp__NetDll_XHttpSetCredentials);
REX_EXPORT_STUB(__imp__NetDll_XHttpSetOption);
REX_EXPORT_STUB(__imp__NetDll_XHttpSetStatusCallback);
REX_EXPORT_STUB(__imp__NetDll_XHttpShutdown);
REX_EXPORT_STUB(__imp__NetDll_XHttpStartup);
REX_EXPORT_STUB(__imp__NetDll_XHttpWriteData);
REX_EXPORT(__imp__NetDll_XNetConnect, rex::kernel::xam::NetDll_XNetConnect_entry)
REX_EXPORT_STUB(__imp__NetDll_XNetCreateKey);
REX_EXPORT_STUB(__imp__NetDll_XNetDnsReverseLookup);
REX_EXPORT_STUB(__imp__NetDll_XNetDnsReverseRelease);
REX_EXPORT_STUB(__imp__NetDll_XNetGetBroadcastVersionStatus);
REX_EXPORT(__imp__NetDll_XNetGetConnectStatus, rex::kernel::xam::NetDll_XNetGetConnectStatus_entry)
REX_EXPORT_STUB(__imp__NetDll_XNetGetSystemLinkPort);
REX_EXPORT_STUB(__imp__NetDll_XNetGetXnAddrPlatform);
REX_EXPORT_STUB(__imp__NetDll_XNetInAddrToServer);
REX_EXPORT_STUB(__imp__NetDll_XNetQosGetListenStats);
REX_EXPORT(__imp__NetDll_XNetQosLookup, rex::kernel::xam::NetDll_XNetQosLookup_entry)
REX_EXPORT(__imp__NetDll_XNetRegisterKey, rex::kernel::xam::NetDll_XNetRegisterKey_entry)
REX_EXPORT(__imp__NetDll_XNetReplaceKey, rex::kernel::xam::NetDll_XNetReplaceKey_entry)
REX_EXPORT_STUB(__imp__NetDll_XNetServerToInAddr);
REX_EXPORT_STUB(__imp__NetDll_XNetSetOpt);
REX_EXPORT_STUB(__imp__NetDll_XNetStartupEx);
REX_EXPORT_STUB(__imp__NetDll_XNetTsAddrToInAddr);
REX_EXPORT(__imp__NetDll_XNetUnregisterInAddr, rex::kernel::xam::NetDll_XNetUnregisterInAddr_entry)
REX_EXPORT_STUB(__imp__NetDll_XNetUnregisterKey);
REX_EXPORT_STUB(__imp__NetDll_XmlDownloadContinue);
REX_EXPORT_STUB(__imp__NetDll_XmlDownloadGetParseTime);
REX_EXPORT_STUB(__imp__NetDll_XmlDownloadGetReceivedDataSize);
REX_EXPORT_STUB(__imp__NetDll_XmlDownloadStart);
REX_EXPORT_STUB(__imp__NetDll_XmlDownloadStop);
REX_EXPORT_STUB(__imp__NetDll_XnpCapture);
REX_EXPORT_STUB(__imp__NetDll_XnpConfig);
REX_EXPORT_STUB(__imp__NetDll_XnpConfigUPnP);
REX_EXPORT_STUB(__imp__NetDll_XnpConfigUPnPPortAndExternalAddr);
REX_EXPORT_STUB(__imp__NetDll_XnpEthernetInterceptRecv);
REX_EXPORT_STUB(__imp__NetDll_XnpEthernetInterceptSetCallbacks);
REX_EXPORT_STUB(__imp__NetDll_XnpEthernetInterceptSetExtendedReceiveCallback);
REX_EXPORT_STUB(__imp__NetDll_XnpEthernetInterceptXmit);
REX_EXPORT_STUB(__imp__NetDll_XnpEthernetInterceptXmitAsIp);
REX_EXPORT_STUB(__imp__NetDll_XnpGetActiveSocketList);
REX_EXPORT_STUB(__imp__NetDll_XnpGetConfigStatus);
REX_EXPORT_STUB(__imp__NetDll_XnpGetKeyList);
REX_EXPORT_STUB(__imp__NetDll_XnpGetQosLookupList);
REX_EXPORT_STUB(__imp__NetDll_XnpGetSecAssocList);
REX_EXPORT_STUB(__imp__NetDll_XnpGetVlanXboxName);
REX_EXPORT_STUB(__imp__NetDll_XnpLoadConfigParams);
REX_EXPORT_STUB(__imp__NetDll_XnpLoadMachineAccount);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonClearChallenge);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonClearQEvent);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonGetChallenge);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonGetQFlags);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonGetQVals);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonGetStatus);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonSetChallengeResponse);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonSetPState);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonSetQEvent);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonSetQFlags);
REX_EXPORT_STUB(__imp__NetDll_XnpLogonSetQVals);
REX_EXPORT_STUB(__imp__NetDll_XnpNoteSystemTime);
REX_EXPORT_STUB(__imp__NetDll_XnpPersistTitleState);
REX_EXPORT_STUB(__imp__NetDll_XnpQosHistoryGetAggregateMeasurement);
REX_EXPORT_STUB(__imp__NetDll_XnpQosHistoryGetEntries);
REX_EXPORT_STUB(__imp__NetDll_XnpQosHistoryLoad);
REX_EXPORT_STUB(__imp__NetDll_XnpQosHistorySaveMeasurements);
REX_EXPORT_STUB(__imp__NetDll_XnpRegisterKeyForCallerType);
REX_EXPORT_STUB(__imp__NetDll_XnpReplaceKeyForCallerType);
REX_EXPORT_STUB(__imp__NetDll_XnpSaveConfigParams);
REX_EXPORT_STUB(__imp__NetDll_XnpSaveMachineAccount);
REX_EXPORT_STUB(__imp__NetDll_XnpSetVlanXboxName);
REX_EXPORT_STUB(__imp__NetDll_XnpToolIpProxyInject);
REX_EXPORT_STUB(__imp__NetDll_XnpToolSetCallbacks);
REX_EXPORT_STUB(__imp__NetDll_XnpUnregisterKeyForCallerType);
REX_EXPORT_STUB(__imp__NetDll_XnpUpdateConfigParams);
REX_EXPORT_STUB(__imp__NetDll_getpeername);
REX_EXPORT_STUB(__imp__NetDll_getsockname);
REX_EXPORT_STUB(__imp__NetDll_getsockopt);
