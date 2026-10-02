// Compile the real adapter in this isolated process to control its existing
// pump state without exposing test controls in the production runtime.
#include "kernel/xam/xam_net.cpp"
#include <rex/runtime.h>
#include <iostream>
#include <stdexcept>
#include <array>
#include <future>

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
  int native_size = sizeof(native);
  Check(getsockname(SOCKET(receiver->native_handle()), reinterpret_cast<sockaddr*>(&native),
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

int main(int argc, char** argv) {
  WSADATA wsa{};
  if (WSAStartup(MAKEWORD(2, 2), &wsa))
    return 4;
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
