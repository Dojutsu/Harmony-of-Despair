// Compile the real adapter in this isolated process to control its existing
// pump state without exposing test controls in the production runtime.
#include "kernel/xam/xam_net.cpp"
#include <rex/runtime.h>
#include <iostream>
#include <stdexcept>
#include <array>
#include <future>
#if REX_PLATFORM_GNU_LINUX
#include <fcntl.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#endif

using namespace rex;
using namespace rex::system;
using namespace rex::kernel::xam;

static void Check(bool value, const char* what) {
  if (!value)
    throw std::runtime_error(what);
}

static void Run(KernelState* kernel, bool expect_stale, bool cancel_ready = false,
                bool waiting_query = false) {
  // Suppress only background scheduling: every operation still traverses the
  // unmodified real API entry and completion code, with real loopback UDP.
  pending_recv_pump_running = true;
  auto* mem = kernel->memory();
  const auto guest = mem->SystemHeapAlloc(4096);
  Check(guest != 0, "guest allocation");
  auto ptr = [&]<typename T>(uint32_t offset) {
    return ppc_ptr_t<T>(mem->TranslateVirtual<T*>(guest + offset), guest + offset);
  };
  auto buf = ptr.operator()<XWSABUF>(0);
  auto ov = ptr.operator()<XWSAOVERLAPPED>(32);
  auto bytes = ptr.operator()<be_u32>(96);
  auto flags = ptr.operator()<be_u32>(100);
  auto query_bytes = ptr.operator()<be_u32>(112);
  auto query_flags = ptr.operator()<be_u32>(116);
  auto from = ptr.operator()<XSOCKADDR_IN>(128);
  auto fromlen = ptr.operator()<be_u32>(148);
  auto to = ptr.operator()<XSOCKADDR_IN>(160);
  buf->len = 64;
  buf->buf_ptr = guest + 256;
  auto* slot = mem->TranslateVirtual(guest + 96);
  constexpr uint64_t sentinel = 0x0000000044175530ull;
  const std::array<uint8_t, 16> payload{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  auto receiver = make_object<XSocket>(kernel);
  auto sender = make_object<XSocket>(kernel);
  Check(XSUCCEEDED(receiver->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                                        XSocket::X_IPPROTO_UDP)),
        "receiver init");
  Check(XSUCCEEDED(
            sender->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP)),
        "sender init");
  N_XSOCKADDR_IN addr{};
  addr.sin_family = 2;
  addr.sin_addr = 0x7f000001;
  addr.sin_port = 0;
  Check(XSUCCEEDED(receiver->Bind(&addr, sizeof(addr))), "bind loopback");
  sockaddr_in native{};
#if REX_PLATFORM_WIN32
  int native_size = sizeof(native);
  const auto native_receiver = static_cast<SOCKET>(receiver->native_handle());
#else
  socklen_t native_size = sizeof(native);
  const auto native_receiver = static_cast<int>(receiver->native_handle());
#endif
  Check(getsockname(native_receiver, reinterpret_cast<sockaddr*>(&native),
                    &native_size) == 0,
        "getsockname");
  addr.sin_port = ntohs(native.sin_port);
  auto event = make_object<XEvent>(kernel);
  event->Initialize(true, false);
  auto queue = [&] {
    std::memset(ov.host_address(), 0, sizeof(XWSAOVERLAPPED));
    ov->event_handle = event->handle();
    event->Reset();
    *bytes = 0;
    *flags = 0;
    *fromlen = 16;
    Check(NetDll_WSARecvFrom_entry(1, receiver->handle(), buf, 1, bytes, flags, from, fromlen, ov,
                                   nullptr) == uint32_t(-1),
          "pending return");
    Check(XThread::GetCurrentThread()->last_error() == 997, "pending status");
    memory::store_and_swap<uint64_t>(slot, sentinel);
    Check(NetDll_WSAGetOverlappedResult_entry(1, receiver->handle(), ov, query_bytes, 0,
                                              query_flags) == 0,
          "query before readiness is incomplete");
    Check(XThread::GetCurrentThread()->last_error() == 996, "incomplete error");
  };
  auto send = [&] {
    Check(sender->SendTo(const_cast<uint8_t*>(payload.data()), payload.size(), 0, &addr,
                         sizeof(addr)) == 16,
          "send 16");
    Check(receiver->WaitReadable(1000, false), "datagram readiness");
  };
  auto untouched = [&] {
    Check(memory::load_and_swap<uint64_t>(slot) == sentinel, "saved register unchanged");
  };
  auto completed = [&] {
    *query_bytes = 99;
    *query_flags = 99;
    Check(NetDll_WSAGetOverlappedResult_entry(1, receiver->handle(), ov, query_bytes, 0,
                                              query_flags) == 1,
          "completion query");
    Check(uint32_t(ov->internal) == 0 && uint32_t(ov->internal_high) == 16, "overlapped result");
    Check(std::memcmp(mem->TranslateVirtual(guest + 256), payload.data(), 16) == 0, "payload");
    Check(uint32_t(*fromlen) == 16 && uint16_t(from->sin_family) == 2, "source outputs");
    uint32_t type = 0, state = 0;
    event->Query(&type, &state);
    Check(state == 1, "completion event");
    Check(uint32_t(*query_bytes) == 16 && uint32_t(*query_flags) == 0, "query bytes and flags");
    Check(pending_recvs.empty(), "query releases operation");
  };
  queue();
  send();
  // The same pump runs synchronously during the title's disband send.
  PumpPendingRecvFrom();
  if (expect_stale) {
    Check(memory::load_and_swap<uint64_t>(slot) == 0x0000001000000000ull,
          "unfixed real adapter reproduces exact corruption");
    completed();
    std::cout << "BEFORE FIX: real adapter produced 0000001000000000\n";
  } else {
    untouched();
    completed();
    event->Reset();
    PumpPendingRecvFrom();
    uint32_t type = 0, state = 0;
    event->Query(&type, &state);
    Check(state == 0, "no duplicate event");
    queue();
    send();
    completed();
    untouched();  // query itself completes receive
    queue();
    send();
    // Session release must not invent socket cancellation. The disband's send
    // still pumps the outstanding receive on the same thread.
    auto session = make_object<rex::system::xam::XSession>(kernel);
    Check(session->Initialize(), "session init");
    auto record = kernel->session_manager()->registry().Create(1, "Fixture", {}, 1, 6, 0);
    session->set_record(record);
    session->set_record(nullptr);
    to->sin_family = addr.sin_family;
    to->sin_addr = addr.sin_addr;
    to->sin_port = addr.sin_port;
    Check(NetDll_WSASendTo_entry(1, sender->handle(), buf, 1, query_bytes, 0, to,
                                 sizeof(XSOCKADDR_IN), nullptr, nullptr) == 0,
          "disband-style send pumps receive");
    untouched();
    completed();
    // Drain the additional send from the preceding case before synchronous check.
    std::array<uint8_t, 64> drain{};
    Check(receiver->WaitReadable(1000, false), "drain ready");
    Check(receiver->RecvFrom(drain.data(), drain.size(), 0, nullptr, nullptr) == 64, "drain send");
    // Synchronous path keeps its initiation outputs valid.
    send();
    *bytes = 99;
    *flags = 0;
    Check(NetDll_WSARecvFrom_entry(1, receiver->handle(), buf, 1, bytes, flags, from, fromlen,
                                   nullptr, nullptr) == 0,
          "synchronous receive");
    Check(uint32_t(*bytes) == 16 && uint32_t(*flags) == 0, "synchronous outputs");
    // Cancellation is socket close in this adapter; no separate cancel API.
    queue();
    if (cancel_ready)
      send();  // Cancel queued native data before any completion pump.
    const auto handle = receiver->handle();
    std::promise<void> querying;
    object_ref<XHostThread> waiter;
    uint32_t wait_result = 1, wait_error = 0;
    *query_bytes = 99;
    *query_flags = 99;
    if (waiting_query) {
      waiter = object_ref<XHostThread>(new XHostThread(kernel, 128 * 1024, 0, [&] {
        querying.set_value();
        wait_result =
            NetDll_WSAGetOverlappedResult_entry(1, handle, ov, query_bytes, 1, query_flags);
        wait_error = XThread::GetCurrentThread()->last_error();
        return 0;
      }));
      Check(XSUCCEEDED(waiter->Create()), "query thread");
      querying.get_future().wait();
    }
    std::array<uint8_t, 64> before_payload{};
    std::memcpy(before_payload.data(), mem->TranslateVirtual(guest + 256), 64);
    Check(NetDll_closesocket_entry(1, handle) == 0, "close cancels pending receive");
    untouched();
    Check(uint32_t(ov->internal) == 0xC0000120 && uint32_t(ov->internal_high) == 0,
          "cancel status");
    event->Query(&type, &state);
    Check(state == 1, "cancel event");
    event->Reset();
    PumpPendingRecvFrom();
    PumpPendingRecvFrom();
    event->Query(&type, &state);
    Check(state == 0, "no duplicate cancel event");
    Check(std::memcmp(before_payload.data(), mem->TranslateVirtual(guest + 256), 64) == 0,
          "cancel payload unchanged");
    if (waiting_query) {
      uint64_t timeout = static_cast<uint64_t>(-100000000ll);
      Check(waiter->Wait(0, 0, 0, &timeout) == 0, "waiting query unblocked by close");
      Check(wait_result == 0 && wait_error == 995, "waiting cancel result");
    } else {
      Check(NetDll_WSAGetOverlappedResult_entry(1, handle, ov, query_bytes, 0, query_flags) == 0,
            "query cancellation");
      Check(XThread::GetCurrentThread()->last_error() == 995, "cancel result error");
    }
    Check(uint32_t(*query_bytes) == 99 && uint32_t(*query_flags) == 99,
          "error query outputs unchanged");
    Check(pending_recvs.empty(), "cancel query releases record");
    untouched();
    std::cout << "AFTER FIX: pump/query/send/session-release lifetime, payload, source, event, "
                 "synchronous and cancellation checks passed; cancel_ready="
              << cancel_ready << '\n';
  }
  if (expect_stale) {
    receiver->Close();
    receiver->ReleaseHandle();
  }
  sender->Close();
  event->ReleaseHandle();
  sender->ReleaseHandle();
  mem->SystemHeapFree(guest);
  pending_recv_pump_running = false;
}

#if REX_PLATFORM_GNU_LINUX
static void RunLinuxFatalReceive(KernelState* kernel) {
  pending_recv_pump_running = true;
  auto* mem = kernel->memory();
  const auto guest = mem->SystemHeapAlloc(4096);
  Check(guest != 0, "fatal receive allocation");
  auto ptr = [&]<typename T>(uint32_t offset) {
    return ppc_ptr_t<T>(mem->TranslateVirtual<T*>(guest + offset), guest + offset);
  };
  auto buffer = ptr.operator()<XWSABUF>(0);
  auto overlapped = ptr.operator()<XWSAOVERLAPPED>(32);
  auto bytes = ptr.operator()<be_u32>(96);
  auto flags = ptr.operator()<be_u32>(100);
  auto query_bytes = ptr.operator()<be_u32>(112);
  auto query_flags = ptr.operator()<be_u32>(116);
  buffer->len = 64; buffer->buf_ptr = guest + 256;
  auto receiver = make_object<XSocket>(kernel);
  Check(XSUCCEEDED(receiver->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                                         XSocket::X_IPPROTO_UDP)), "fatal receiver");
  auto event = make_object<XEvent>(kernel); event->Initialize(true, false);
  std::memset(overlapped.host_address(), 0, sizeof(XWSAOVERLAPPED));
  overlapped->event_handle = event->handle();
  *bytes = 0; *flags = 0;
  Check(NetDll_WSARecvFrom_entry(1, receiver->handle(), buffer, 1, bytes, flags, nullptr,
                                 nullptr, overlapped, nullptr) == uint32_t(-1), "fatal pending return");
  Check(XThread::GetLastError() == 997, "fatal initially pending");
  // Simulate underlying transport loss while the guest object and operation
  // remain live. Explicit guest closesocket has a separate cancellation path.
  Check(XSUCCEEDED(receiver->Close()), "retire native transport");
  PumpPendingRecvFrom();
  Check(uint32_t(overlapped->internal) == X_STATUS_UNSUCCESSFUL &&
        uint32_t(overlapped->internal_high) == 0, "fatal overlapped state");
  uint32_t type = 0, state = 0;
  event->Query(&type, &state); Check(state == 1, "fatal completion event");
  event->Reset(); PumpPendingRecvFrom(); event->Query(&type, &state);
  Check(state == 0, "fatal event not signaled twice");
  *query_bytes = 99; *query_flags = 99;
  Check(NetDll_WSAGetOverlappedResult_entry(1, receiver->handle(), overlapped, query_bytes,
                                           0, query_flags) == 0, "fatal query fails");
  Check(XThread::GetLastError() == 10038, "fatal guest WSAENOTSOCK");
  Check(uint32_t(*query_bytes) == 99 && uint32_t(*query_flags) == 99, "fatal query outputs unchanged");
  Check(pending_recvs.empty(), "fatal query consumes completion");
  receiver->Close(); receiver->ReleaseHandle(); event->ReleaseHandle();
  mem->SystemHeapFree(guest); pending_recv_pump_running = false;
  std::cout << "Linux terminal receive-error completion/event checks passed\n";
}

static void RunLinuxSocketAbi(KernelState* kernel) {
  // Enter real guest APIs with Xbox constants, BE fields and kernel handles.
  auto* mem = kernel->memory();
  const auto guest = mem->SystemHeapAlloc(4096);
  Check(guest != 0, "ABI guest allocation");
  auto ptr = [&]<typename T>(uint32_t offset) {
    return ppc_ptr_t<T>(mem->TranslateVirtual<T*>(guest + offset), guest + offset);
  };
  auto raw = [&](uint32_t offset) { return mapped_void(mem->TranslateVirtual(guest + offset), guest + offset); };
  auto reads = ptr.operator()<x_fd_set>(0);
  auto writes = ptr.operator()<x_fd_set>(288);
  auto exceptions = ptr.operator()<x_fd_set>(576);
  auto option = ptr.operator()<be_u32>(864);
  auto timeout = raw(872);
  auto source = ptr.operator()<XSOCKADDR_IN>(896);
  auto source_length = ptr.operator()<be_u32>(916);
  struct DescriptorPool {
    std::vector<int> handles;
    ~DescriptorPool() { for (int fd : handles) ::close(fd); }
  } pool;
  rlimit limits{};
  Check(getrlimit(RLIMIT_NOFILE, &limits) == 0, "descriptor limit");
  if (limits.rlim_cur > FD_SETSIZE + 16) {
    for (;;) {
      const int fd = ::open("/dev/null", O_RDONLY | O_CLOEXEC);
      Check(fd >= 0, "allocate high socket descriptor");
      pool.handles.push_back(fd);
      if (fd >= FD_SETSIZE) break;
    }
  }
  auto receiver = make_object<XSocket>(kernel);
  auto sender = make_object<XSocket>(kernel);
  Check(XSUCCEEDED(receiver->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                                         XSocket::X_IPPROTO_UDP)), "ABI receiver");
  Check(XSUCCEEDED(sender->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                                       XSocket::X_IPPROTO_UDP)), "ABI sender");
  if (!pool.handles.empty()) Check(receiver->native_handle() > FD_SETSIZE, "high guest fd");
  N_XSOCKADDR_IN address{};
  address.sin_family = AF_INET;
  address.sin_addr = INADDR_LOOPBACK;
  Check(XSUCCEEDED(receiver->Bind(&address, sizeof(address))), "ABI loopback bind");
  sockaddr_in native{};
  socklen_t native_length = sizeof(native);
  Check(getsockname(receiver->native_handle(), reinterpret_cast<sockaddr*>(&native),
                    &native_length) == 0, "ABI getsockname");
  address.sin_port = ntohs(native.sin_port);
  *option = 1;
  Check(NetDll_setsockopt_entry(1, receiver->handle(), 0xFFFF, 0x0020, raw(864), 4) == 0,
        "guest SO_BROADCAST");
  int broadcast = 0;
  native_length = sizeof(broadcast);
  Check(getsockopt(receiver->native_handle(), SOL_SOCKET, SO_BROADCAST,
                    &broadcast, &native_length) == 0 && broadcast == 1, "native SO_BROADCAST");
  Check(NetDll_ioctlsocket_entry(1, receiver->handle(), 0x8004667E, raw(864)) == 0,
        "guest FIONBIO");
  Check(fcntl(receiver->native_handle(), F_GETFL) & O_NONBLOCK, "native nonblocking");
  Check(NetDll_setsockopt_entry(1, receiver->handle(), 0xFFFF, 0xFFFF, raw(864), 4) == uint32_t(-1),
        "unsupported option");
  Check(XThread::GetLastError() == 10042, "guest WSAENOPROTOOPT");
  Check(NetDll_setsockopt_entry(1, receiver->handle(), 0xFFFF, 0x0020, raw(864), 3) == uint32_t(-1),
        "option size validation");
  Check(XThread::GetLastError() == 10022, "guest WSAEINVAL");
  timeout.as_array<int32_t>()[0] = 0;
  timeout.as_array<int32_t>()[1] = 50000;
  const std::array<uint8_t, 8> timeout_before = [] (mapped_void value) {
    std::array<uint8_t, 8> copy{}; std::memcpy(copy.data(), value.host_address(), copy.size()); return copy;
  }(timeout);
  reads->fd_count = 1;
  reads->fd_array[0] = receiver->handle();
  const auto began = std::chrono::steady_clock::now();
  Check(NetDll_select_entry(1, 0, reads, nullptr, nullptr, timeout) == 0, "guest select timeout");
  Check(std::chrono::steady_clock::now() - began >= std::chrono::milliseconds(20), "BE timeout respected");
  Check(reads->fd_count == 0 && std::memcmp(timeout_before.data(), timeout.host_address(), 8) == 0,
        "select timeout outputs and untouched input");
  std::array<uint8_t, 4> payload{1, 2, 3, 4};
  Check(sender->SendTo(payload.data(), payload.size(), 0, &address, sizeof(address)) == 4, "ABI send");
  reads->fd_count = 1; reads->fd_array[0] = receiver->handle();
  writes->fd_count = 1; writes->fd_array[0] = sender->handle();
  exceptions->fd_count = 1; exceptions->fd_array[0] = receiver->handle();
  Check(NetDll_select_entry(1, 0, reads, writes, exceptions, timeout) == 2, "guest select read/write count");
  Check(reads->fd_count == 1 && reads->fd_array[0] == receiver->handle() &&
        writes->fd_count == 1 && writes->fd_array[0] == sender->handle() && exceptions->fd_count == 0,
        "guest selected handle arrays");
  *option = 99;
  Check(NetDll_ioctlsocket_entry(1, receiver->handle(), 0x4004667F, raw(864)) == 0 && uint32_t(*option) == 4,
        "guest FIONREAD BE output");
  *source_length = 16;
  Check(NetDll_recvfrom_entry(1, receiver->handle(), raw(1200), 64, 0, source, source_length) == 4,
        "guest synchronous receive");
  std::array<uint8_t, sizeof(XSOCKADDR_IN)> source_before{};
  std::memcpy(source_before.data(), source.host_address(), source_before.size());
  Check(NetDll_recvfrom_entry(1, receiver->handle(), raw(1200), 64, 0, source, source_length) == uint32_t(-1),
        "empty nonblocking receive");
  Check(XThread::GetLastError() == 10035, "guest WSAEWOULDBLOCK");
  Check(uint32_t(*source_length) == 16 && std::memcmp(source_before.data(), source.host_address(), 16) == 0,
        "receive error output unchanged");
  Check(sender->SendTo(payload.data(), payload.size(), 0, &address, sizeof(address)) == 4,
        "send oversized guest datagram");
  Check(receiver->WaitReadable(500), "oversized guest readiness");
  Check(NetDll_recvfrom_entry(1, receiver->handle(), raw(1200), 3, 0, source, source_length) == uint32_t(-1),
        "oversized guest datagram rejected");
  Check(XThread::GetLastError() == 10040, "guest WSAEMSGSIZE");
  Check(uint32_t(*source_length) == 16 && std::memcmp(source_before.data(), source.host_address(), 16) == 0,
        "oversized guest source outputs unchanged");
  Check(!receiver->WaitReadable(0), "oversized datagram retired");
  reads->fd_count = 65;
  Check(NetDll_select_entry(1, 0, reads, nullptr, nullptr, timeout) == -1 &&
        XThread::GetLastError() == 10022 && reads->fd_count == 65, "oversized fd set rejected");
  reads->fd_count = 1; reads->fd_array[0] = 0xFFFFFFFF;
  Check(NetDll_select_entry(1, 0, reads, nullptr, nullptr, timeout) == -1 &&
        XThread::GetLastError() == 10038, "invalid socket set rejected");
  writes->fd_count = 64;
  for (auto& handle : writes->fd_array) handle = sender->handle();
  Check(NetDll_select_entry(1, 0, nullptr, writes, nullptr, timeout) == 1 && writes->fd_count == 1,
        "full fd set and duplicate semantics");
  receiver->Close(); receiver->ReleaseHandle();
  sender->Close(); sender->ReleaseHandle();
  mem->SystemHeapFree(guest);
  std::cout << "Linux guest options/ioctl/error/select ABI checks passed\n";
}
static void RunLinuxSendBounds(KernelState* kernel) {
  pending_recv_pump_running = true;
  auto* memory = kernel->memory();
  const auto guest = memory->SystemHeapAlloc(128 * 1024);
  Check(guest != 0, "send bound allocation");
  auto ptr = [&]<typename T>(uint32_t offset) {
    return ppc_ptr_t<T>(memory->TranslateVirtual<T*>(guest + offset), guest + offset);
  };
  auto bad = [&]<typename T>(uint32_t address) {
    return ppc_ptr_t<T>(memory->TranslateVirtual<T*>(address), address);
  };
  auto raw = [&](uint32_t offset) {
    return mapped_void(memory->TranslateVirtual(guest + offset), guest + offset);
  };
  auto descriptors = ptr.operator()<XWSABUF>(0);
  auto bytes = ptr.operator()<be_u32>(1024);
  auto overlapped = ptr.operator()<XWSAOVERLAPPED>(1056);
  auto query = ptr.operator()<be_u32>(1088);
  auto flags = ptr.operator()<be_u32>(1092);
  auto destination = ptr.operator()<XSOCKADDR_IN>(1120);
  auto sender = make_object<XSocket>(kernel), receiver = make_object<XSocket>(kernel);
  Check(sender->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) ==
            X_STATUS_SUCCESS &&
        receiver->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) ==
            X_STATUS_SUCCESS, "send bounds sockets");
  N_XSOCKADDR_IN address{};
  address.sin_family = AF_INET; address.sin_addr = INADDR_LOOPBACK;
  Check(receiver->Bind(&address, sizeof(address)) == X_STATUS_SUCCESS, "send bounds bind");
  sockaddr_in native{}; socklen_t native_size = sizeof(native);
  Check(getsockname(receiver->native_handle(), reinterpret_cast<sockaddr*>(&native),
                    &native_size) == 0, "send bounds getsockname");
  address.sin_port = ntohs(native.sin_port);
  destination->sin_family = address.sin_family;
  destination->sin_addr = address.sin_addr;
  destination->sin_port = address.sin_port;
  auto event = make_object<XEvent>(kernel); event->Initialize(true, false);
  const std::array<uint8_t, 7> payload{19, 31, 47, 59, 73, 89, 101};
  std::memcpy(memory->TranslateVirtual(guest + 2048), payload.data(), payload.size());
  descriptors[0].len = 3; descriptors[0].buf_ptr = guest + 2048;
  descriptors[1].len = 4; descriptors[1].buf_ptr = guest + 2051;
  auto reset_outputs = [&] {
    *bytes = 0x51515151;
    std::memset(overlapped.host_address(), 0xA7, sizeof(XWSAOVERLAPPED));
    overlapped->event_handle = event->handle();
    event->Reset();
  };
  auto send = [&](uint32_t count = 2, ppc_ptr_t<XSOCKADDR_IN> to = nullptr,
                  uint32_t to_length = sizeof(XSOCKADDR_IN)) {
    return NetDll_WSASendTo_entry(1, sender->handle(), descriptors, count, bytes, 0,
                                   to ? to : destination, to_length, overlapped, nullptr);
  };
  auto receive = [&](const uint8_t* expected, uint32_t length) {
    Check(receiver->WaitReadable(1000, false), "send bounds packet readiness");
    std::vector<uint8_t> output(length + 1, 0xEE);
    Check(receiver->RecvFrom(output.data(), output.size(), 0, nullptr, nullptr) == int(length),
          "send bounds actual datagram length");
    Check(!length || std::memcmp(output.data(), expected, length) == 0,
          "send bounds actual datagram payload");
    Check(output.back() == 0xEE, "send bounds exact payload extent");
  };
  auto unchanged = [&] {
    Check(uint32_t(*bytes) == 0x51515151 &&
          uint32_t(overlapped->internal) == 0xA7A7A7A7 &&
          uint32_t(overlapped->internal_high) == 0xA7A7A7A7 &&
          uint32_t(overlapped->offset.low) == 0xA7A7A7A7 &&
          uint32_t(overlapped->offset.high) == 0xA7A7A7A7 &&
          uint32_t(overlapped->event_handle) == event->handle(),
          "failed send completion fields unchanged");
    uint32_t type = 0, state = 0; event->Query(&type, &state);
    Check(state == 0 && pending_recvs.empty(), "failed send event and pending state unchanged");
    Check(!receiver->WaitReadable(0, false), "failed send emitted no packet");
  };
  auto failure = [&](uint32_t result, uint32_t error) {
    Check(result == uint32_t(-1) && XThread::GetLastError() == error,
          "send bounds expected API error");
    unchanged();
  };
  reset_outputs();
  Check(send() == 0 && uint32_t(*bytes) == payload.size(), "scatter send succeeds");
  Check(uint32_t(overlapped->internal) == 0 &&
        uint32_t(overlapped->internal_high) == payload.size() &&
        uint32_t(overlapped->offset.low) == 0xA7A7A7A7,
        "scatter send exact completion fields");
  uint32_t type = 0, state = 0; event->Query(&type, &state);
  Check(state == 1, "scatter send completion event");
  *query = 99; *flags = 99;
  Check(NetDll_WSAGetOverlappedResult_entry(1, sender->handle(), overlapped, query, 0, flags) == 1 &&
        uint32_t(*query) == payload.size() && uint32_t(*flags) == 0 && pending_recvs.empty(),
        "scatter send query preserves completion semantics");
  receive(payload.data(), payload.size());
  reset_outputs(); failure(send(0), 10022);
  failure(send(65), 10022); failure(send(0xFFFFFFFF), 10022);
  failure(NetDll_WSASendTo_entry(1, sender->handle(), bad.operator()<XWSABUF>(0xFFFFFFFC),
                                  2, bytes, 0, destination, 16, overlapped, nullptr), 10014);
  failure(NetDll_WSASendTo_entry(1, sender->handle(),
                                  ppc_ptr_t<XWSABUF>(descriptors.host_address() + 1,
                                                     descriptors.guest_address()),
                                  2, bytes, 0, destination, 16, overlapped, nullptr), 10014);
  descriptors[0].len = 0xFFFFFFFF; descriptors[1].len = 2;
  failure(send(), 10040);  // Old uint32 aggregation wrapped this pair to one byte.
  descriptors[0].len = 65508; descriptors[1].len = 0;
  failure(send(), 10040);
  descriptors[0].len = 8; descriptors[0].buf_ptr = 0xFFFFFFFC;
  failure(send(), 10014);
  descriptors[0].len = 3; descriptors[0].buf_ptr = guest + 2048;
  descriptors[1].len = 4; descriptors[1].buf_ptr = 0xFFFFF000;
  failure(send(), 10014);
  descriptors[1].buf_ptr = guest + 2051;
  failure(send(2, destination, 15), 10022); failure(send(2, destination, 17), 10022);
  destination->sin_family = 23; failure(send(), 10047); destination->sin_family = AF_INET;
  failure(send(2, bad.operator()<XSOCKADDR_IN>(0xFFFFFFFC)), 10014);
  failure(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 2, bytes, 0,
                                  nullptr, 16, overlapped, nullptr), 10022);
  failure(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 2,
                                  bad.operator()<be_u32>(0xFFFFFFFE), 0,
                                  destination, 16, overlapped, nullptr), 10014);
  failure(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 2, bytes, 0,
                                  destination, 16, bad.operator()<XWSAOVERLAPPED>(0xFFFFFFFC),
                                  nullptr), 10014);
  // Read-only output and input page revocation must fail before socket effects.
  const auto protected_page = memory->SystemHeapAlloc(4096);
  Check(protected_page != 0, "send bounds protected allocation");
  auto* heap = memory->LookupHeap(protected_page);
  Check(heap->Protect(protected_page, 4096, memory::kMemoryProtectRead), "protect send output");
  failure(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 2,
                                  bad.operator()<be_u32>(protected_page), 0,
                                  destination, 16, overlapped, nullptr), 10014);
  Check(heap->Protect(protected_page, 4096, memory::kMemoryProtectNoAccess), "revoke send input");
  descriptors[0].buf_ptr = protected_page; failure(send(), 10014);
  Check(heap->Protect(protected_page, 4096,
                       memory::kMemoryProtectRead | memory::kMemoryProtectWrite),
        "restore send input");
  memory->SystemHeapFree(protected_page);
  descriptors[0].buf_ptr = guest + 2048;
  // A native send failure must survive the required post-send receive pump:
  // its nonblocking receive overwrites errno with EAGAIN. Keep the original
  // WSAEDESTADDRREQ and leave both operations' completion outputs intact.
  auto receive_buffer = ptr.operator()<XWSABUF>(1200);
  auto receive_overlapped = ptr.operator()<XWSAOVERLAPPED>(1232);
  auto receive_bytes = ptr.operator()<be_u32>(1264);
  auto receive_flags = ptr.operator()<be_u32>(1268);
  receive_buffer->len = 16; receive_buffer->buf_ptr = guest + 3000;
  std::memset(receive_overlapped.host_address(), 0, sizeof(XWSAOVERLAPPED));
  *receive_bytes = 99; *receive_flags = 0;
  Check(NetDll_WSARecvFrom_entry(1, receiver->handle(), receive_buffer, 1,
                                  receive_bytes, receive_flags, nullptr, nullptr,
                                  receive_overlapped, nullptr) == uint32_t(-1) &&
        XThread::GetLastError() == 997 && pending_recvs.size() == 1,
        "send failure fixture pending receive");
  Check(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 2, bytes, 0,
                                nullptr, 0, overlapped, nullptr) == uint32_t(-1) &&
        XThread::GetLastError() == 10039,
        "native send error preserved across pending receive pump");
  event->Query(&type, &state);
  Check(uint32_t(*bytes) == 0x51515151 &&
        uint32_t(overlapped->internal) == 0xA7A7A7A7 &&
        uint32_t(overlapped->internal_high) == 0xA7A7A7A7 && state == 0 &&
        uint32_t(receive_overlapped->internal) == X_STATUS_PENDING &&
        uint32_t(*receive_bytes) == 0 && pending_recvs.size() == 1 &&
        !receiver->WaitReadable(0, false), "native send failure completion state unchanged");
  Check(sender->SendTo(const_cast<uint8_t*>(payload.data()), payload.size(), 0,
                        &address, sizeof(address)) == 7 && receiver->WaitReadable(1000, false),
        "complete failure fixture outstanding receive");
  PumpPendingRecvFrom();
  Check(NetDll_WSAGetOverlappedResult_entry(1, receiver->handle(), receive_overlapped,
                                            query, 0, flags) == 1 &&
        uint32_t(*query) == 7 && pending_recvs.empty(),
        "failure fixture pending receive remains usable");
  unchanged();
  // Direct sendto enters the same validated staging path.
  failure(NetDll_sendto_entry(1, sender->handle(),
                               mapped_void(memory->TranslateVirtual(0xFFFFFFFC), 0xFFFFFFFC),
                               8, 0, destination, 16), 10014);
  failure(NetDll_sendto_entry(1, sender->handle(), raw(2048), 65508, 0, destination, 16), 10040);
  failure(NetDll_sendto_entry(1, sender->handle(), raw(2048), 7, 0, nullptr, 16), 10022);
  failure(NetDll_sendto_entry(1, sender->handle(), raw(2048), 7, 0, destination, 15), 10022);
  Check(NetDll_sendto_entry(1, sender->handle(), raw(2048), 7, 0, destination, 16) == 7,
        "direct staged sendto succeeds");
  receive(payload.data(), payload.size()); unchanged();
  Check(NetDll_connect_entry(1, sender->handle(),
                              ppc_ptr_t<XSOCKADDR>(reinterpret_cast<XSOCKADDR*>(destination.host_address()),
                                                  destination.guest_address()), 16) == 0,
        "guest connected UDP");
  Check(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 2, bytes, 0,
                                nullptr, 0, nullptr, nullptr) == 0 && uint32_t(*bytes) == 7,
        "connected scatter send with null destination");
  receive(payload.data(), payload.size());
  Check(NetDll_sendto_entry(1, sender->handle(), raw(2048), 7, 0, nullptr, 0) == 7,
        "connected direct sendto with null destination");
  receive(payload.data(), payload.size());
  reset_outputs();
  failure(NetDll_send_entry(1, sender->handle(),
                             mapped_void(memory->TranslateVirtual(0xFFFFFFFC), 0xFFFFFFFC),
                             8, 0), 10014);
  failure(NetDll_send_entry(1, sender->handle(), raw(2048), 65508, 0), 10040);
  Check(NetDll_send_entry(1, sender->handle(), raw(2048), 7, 0) == 7,
        "connected checked send succeeds");
  receive(payload.data(), payload.size()); unchanged();
  descriptors[0].len = 0; descriptors[0].buf_ptr = 0xFFFFFFFF;
  descriptors[1].len = 0; descriptors[1].buf_ptr = 0;
  Check(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 2, bytes, 0,
                                nullptr, 0, nullptr, nullptr) == 0 && uint32_t(*bytes) == 0,
        "zero-length scatter datagram ignores unused pointers");
  receive(nullptr, 0);
  auto* maximum_payload = memory->TranslateVirtual(guest + 4096);
  for (uint32_t i = 0; i < 65507; ++i) maximum_payload[i] = uint8_t(i * 73 + 11);
  descriptors[0].len = 65507; descriptors[0].buf_ptr = guest + 4096;
  Check(NetDll_WSASendTo_entry(1, sender->handle(), descriptors, 1, bytes, 0,
                                nullptr, 0, nullptr, nullptr) == 0 && uint32_t(*bytes) == 65507,
        "maximum ordinary UDP datagram");
  receive(maximum_payload, 65507);
  sender->Close(); receiver->Close(); event->ReleaseHandle();
  sender->ReleaseHandle(); receiver->ReleaseHandle(); memory->SystemHeapFree(guest);
  pending_recv_pump_running = false;
  std::cout << "Linux real guest send descriptor, overflow, affine range, destination, output, "
               "event, scatter, null-connected and maximum UDP checks passed\n";
}

static void RunLinuxSelectGuestIdentity(KernelState* kernel) {
  auto first = make_object<XSocket>(kernel), second = make_object<XSocket>(kernel);
  Check(first->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) ==
            X_STATUS_SUCCESS &&
        second->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) ==
            X_STATUS_SUCCESS, "select identity sockets");
  const X_HANDLE primary = first->handle(), other = second->handle(); X_HANDLE alias = 0;
  Check(kernel->object_table()->AddHandle(first.get(), &alias) == X_STATUS_SUCCESS && alias != primary,
        "select identity real guest alias");
  x_fd_set supplied{}; supplied.fd_count = 3;
  supplied.fd_array[0] = alias; supplied.fd_array[1] = other; supplied.fd_array[2] = alias;
  host_set captured{}; Check(captured.Load(&supplied) && captured.count == 2,
                            "select identity duplicate supplied handle");
  x_fd_set output{}; captured.Store(&output);
  Check(output.fd_count == 2 && output.fd_array[0] == alias && output.fd_array[1] == other,
        "select preserves supplied alias instead of primary handle");
  first->Close(); second->Close();
  Check(kernel->object_table()->ReleaseHandle(primary) == X_STATUS_SUCCESS &&
        kernel->object_table()->ReleaseHandle(alias) == X_STATUS_SUCCESS &&
        kernel->object_table()->ReleaseHandle(other) == X_STATUS_SUCCESS,
        "select identity real guest handle removal");
  Check(first->handles().empty() && second->handles().empty(), "removed guest vectors are empty");
  captured.Store(&output);
  Check(output.fd_count == 2 && output.fd_array[0] == alias && output.fd_array[1] == other,
        "select output never consults emptied handle vector");
  fd_set ready; FD_ZERO(&ready); FD_SET(captured.operations[1].handle(), &ready);
  captured.UpdateFrom(&ready); captured.Store(&output);
  Check(output.fd_count == 1 && output.fd_array[0] == other,
        "select compaction preserves captured guest identity");
  std::cout << "Linux select captured guest alias/removal/compaction checks passed\n";
}

static void RunLinuxSelectRetirement(KernelState* kernel) {
  auto receiver = make_object<XSocket>(kernel);
  Check(receiver->Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM,
                             XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS, "select retire receiver");
  N_XSOCKADDR_IN address{}; address.sin_port = 0; address.sin_family = AF_INET; address.sin_addr = INADDR_LOOPBACK;
  Check(receiver->Bind(&address, sizeof(address)) == X_STATUS_SUCCESS, "select retire loopback");
  auto operation = receiver->AcquireNativeLease();
  const auto descriptor = operation.handle();
  const auto handle = receiver->handle();
  x_fd_set reads{}; reads.fd_count = 1; reads.fd_array[0] = handle;
  const auto before = reads;
  std::promise<pid_t> started;
  int result = 777; uint32_t error = 0;
  auto waiter = object_ref<XHostThread>(new XHostThread(kernel, 128 * 1024, 0, [&] {
    started.set_value(static_cast<pid_t>(syscall(SYS_gettid)));
    result = NetDll_select_entry(1, 0, ppc_ptr_t<x_fd_set>::from_host(&reads),
                                 nullptr, nullptr, nullptr);
    error = XThread::GetLastError();
    return 0;
  }));
  Check(XSUCCEEDED(waiter->Create()), "select retire thread");
  const auto path = "/proc/self/task/" + std::to_string(started.get_future().get()) + "/syscall";
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
  bool blocked = false;
  while (std::chrono::steady_clock::now() < deadline) {
    if (auto* input = std::fopen(path.c_str(), "r")) {
      long number = -1;
      blocked = std::fscanf(input, "%ld", &number) == 1 && number == SYS_ppoll;
      std::fclose(input);
      if (blocked) break;
    }
    std::this_thread::yield();
  }
  // Close even if the observation failed so this regression never strands an
  // owned waiter. The descriptor remains pinned throughout result translation.
  Check(NetDll_closesocket_entry(1, handle) == 0, "guest close wakes select");
  uint64_t timeout = static_cast<uint64_t>(-100000000ll);
  Check(waiter->Wait(0, 0, 0, &timeout) == 0, "select waiter drained after close");
  Check(blocked, "actual guest select was blocked in ppoll");
  Check(result == -1 && error == 10038, "retired select returns WSAENOTSOCK");
  Check(std::memcmp(&reads, &before, sizeof(reads)) == 0, "retired select guest set unchanged");
  Check(operation.retired() && fcntl(static_cast<int>(descriptor), F_GETFD) >= 0,
        "select original native descriptor retained");
  operation = {};
  Check(fcntl(static_cast<int>(descriptor), F_GETFD) == -1 && errno == EBADF,
        "select native descriptor retired after last lease");
  waiter.reset(); receiver.reset();
  std::cout << "Linux blocked guest select retirement checks passed\n";
}

#endif

int main(int argc, char** argv) {
#if REX_PLATFORM_WIN32
  WSADATA wsa{};
  if (WSAStartup(MAKEWORD(2, 2), &wsa))
    return 4;
#endif
  InitLogging();
  Runtime runtime("");
  RuntimeConfig config;
  config.tool_mode = true;
  if (runtime.Setup(std::move(config)))
    return 2;
  int result = 0;
  auto thread = object_ref<XHostThread>(new XHostThread(runtime.kernel_state(), 128 * 1024, 0, [&] {
    try {
      const bool stale = argc == 2 && std::string(argv[1]) == "--expect-stale";
      Run(runtime.kernel_state(), stale);
      if (!stale)
        Run(runtime.kernel_state(), false, true);
      if (!stale)
        Run(runtime.kernel_state(), false, false, true);
#if REX_PLATFORM_GNU_LINUX
      if (!stale) {
        RunLinuxSocketAbi(runtime.kernel_state());
        RunLinuxSendBounds(runtime.kernel_state());
        RunLinuxFatalReceive(runtime.kernel_state());
        RunLinuxSelectGuestIdentity(runtime.kernel_state());
        RunLinuxSelectRetirement(runtime.kernel_state());
      }
#endif
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
      result = 1;
    }
    return result;
  }));
  if (XFAILED(thread->Create()))
    return 3;
  thread->Wait(0, 0, 0, nullptr);
  thread.reset();
  runtime.Shutdown();
  return result;
}
