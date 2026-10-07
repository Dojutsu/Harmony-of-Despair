// Pause real libc entries at causal retirement boundaries.
// Only this test executable interposes syscalls; production has no test seam.
#include <rex/system/xsocket.h>
#include <rex/logging.h>
#include <rex/net/socket.h>
#include <dlfcn.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/eventfd.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <thread>
namespace {
std::mutex gate_mutex;
std::condition_variable gate_changed;
int owned_descriptor = -1;
bool pause_receive = false, pause_connect = false, pause_accept = false, pause_child_state = false;
bool entered = false, continue_receive = false;
int accepted_descriptor = -1;
void Check(bool good, const char* message) {
  std::printf("socket-retirement-race %s %s\n", good ? "PASS" : "FAIL", message);
  std::fflush(stdout);
  if (!good) _exit(1);
}
void WaitForGate() {
  std::unique_lock lock(gate_mutex);
  Check(gate_changed.wait_for(lock, std::chrono::seconds(3), [] { return entered; }),
        "observed-real-syscall-boundary");
}
void ReleaseGate() {
  { std::lock_guard lock(gate_mutex); continue_receive = true; }
  gate_changed.notify_all();
}
void ConnectRetirement(bool datagram) {
  { std::lock_guard lock(gate_mutex); entered = false; continue_receive = false; }
  using namespace rex::system;
  XSocket client(nullptr);
  Check(client.Initialize(XSocket::X_AF_INET, datagram ? XSocket::X_SOCK_DGRAM : XSocket::X_SOCK_STREAM,
                          datagram ? XSocket::X_IPPROTO_UDP : XSocket::X_IPPROTO_TCP) == 0,
        "initialize-connecting-client");
  const int listener = socket(AF_INET, (datagram ? SOCK_DGRAM : SOCK_STREAM) | SOCK_CLOEXEC,
                              datagram ? IPPROTO_UDP : IPPROTO_TCP);
  sockaddr_in endpoint{}; endpoint.sin_family = AF_INET;
  endpoint.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  Check(listener >= 0 && bind(listener, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) == 0 &&
        (datagram || listen(listener, 1) == 0), "local-connect-listener");
  socklen_t bytes = sizeof(endpoint);
  Check(getsockname(listener, reinterpret_cast<sockaddr*>(&endpoint), &bytes) == 0, "connect-endpoint");
  N_XSOCKADDR target{}; std::memcpy(&target, &endpoint, sizeof(target));
  owned_descriptor = client.native_handle(); pause_connect = true;
  int result = 0, error = 0;
  std::thread worker([&] { result = client.Connect(&target, sizeof(target)); error = errno; });
  WaitForGate();
  Check(datagram ? !(fcntl(owned_descriptor, F_GETFL) & O_NONBLOCK) :
                   bool(fcntl(owned_descriptor, F_GETFL) & O_NONBLOCK),
        "tcp-connect-cancellable-and-udp-mode-unchanged");
  Check(client.Close() == 0, "close-before-kernel-connect");
  Check(fcntl(owned_descriptor, F_GETFD) >= 0, "connect-descriptor-pinned");
  ReleaseGate(); worker.join();
  Check(result != 0 && error == ENOTSOCK, "connect-refuses-success-after-retirement");
  Check(fcntl(owned_descriptor, F_GETFD) == -1 && errno == EBADF, "connect-final-lease-retires-descriptor");
  close(listener);
}
void AcceptRetirement(bool preparing_child) {
  { std::lock_guard lock(gate_mutex); entered = false; continue_receive = false;
    pause_accept = false; pause_child_state = false; }
  using namespace rex::system;
  XSocket listener(nullptr);
  Check(listener.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_STREAM, XSocket::X_IPPROTO_TCP) == 0,
        "initialize-accepting-listener");
  N_XSOCKADDR_IN local{}; local.sin_port = 0; local.sin_family = AF_INET; local.sin_addr = INADDR_LOOPBACK;
  Check(listener.Bind(&local, sizeof(local)) == 0 && listener.Listen(1) == 0, "accept-local-listener");
  sockaddr_in endpoint{}; socklen_t bytes = sizeof(endpoint);
  owned_descriptor = listener.native_handle();
  Check(getsockname(owned_descriptor, reinterpret_cast<sockaddr*>(&endpoint), &bytes) == 0, "accept-endpoint");
  const int client = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP);
  Check(client >= 0 && ::connect(client, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) == 0,
        "queue-legitimate-local-client");
  N_XSOCKADDR output{}; std::memset(&output, 0xCB, sizeof(output)); const auto before = output;
  int length = sizeof(output), error = 0; bool returned_child = true;
  pause_accept = !preparing_child; pause_child_state = preparing_child;
  std::thread worker([&] { auto child = listener.Accept(&output, &length);
                           returned_child = bool(child); error = errno; });
  WaitForGate();
  Check(accepted_descriptor >= 0 && fcntl(accepted_descriptor, F_GETFD) >= 0,
        "real-accepted-child-held-before-return");
  Check(listener.Close() == 0, "retire-listener-after-kernel-accept");
  ReleaseGate(); worker.join();
  Check(!returned_child && error == ENOTSOCK, "retired-listener-does-not-publish-child");
  Check(fcntl(accepted_descriptor, F_GETFD) == -1 && errno == EBADF, "unpublished-child-descriptor-closed");
  Check(length == sizeof(output) && std::memcmp(&output, &before, sizeof(output)) == 0,
        "retired-accept-source-outputs-unchanged");
  close(client);
}
}
extern "C" ssize_t recvfrom(int fd, void* data, size_t count, int flags,
                             sockaddr* source, socklen_t* source_size) {
  {
    std::unique_lock lock(gate_mutex);
    if (fd == owned_descriptor && pause_receive) {
      pause_receive = false; entered = true; gate_changed.notify_all();
      gate_changed.wait(lock, [] { return continue_receive; });
    }
  }
  return syscall(SYS_recvfrom, fd, data, count, flags, source, source_size);
}
extern "C" int connect(int fd, const sockaddr* address, socklen_t bytes) {
  {
    std::unique_lock lock(gate_mutex);
    if (fd == owned_descriptor && pause_connect) {
      pause_connect = false; entered = true; gate_changed.notify_all();
      gate_changed.wait(lock, [] { return continue_receive; });
    }
  }
  return syscall(SYS_connect, fd, address, bytes);
}
extern "C" int accept4(int fd, sockaddr* address, socklen_t* bytes, int flags) {
  const int child = syscall(SYS_accept4, fd, address, bytes, flags);
  std::unique_lock lock(gate_mutex);
  if (fd == owned_descriptor) accepted_descriptor = child;
  if (fd == owned_descriptor && pause_accept) {
    pause_accept = false; entered = true; gate_changed.notify_all();
    gate_changed.wait(lock, [] { return continue_receive; });
  }
  return child;
}
extern "C" int eventfd(unsigned int initial, int flags) noexcept {
  const int cancellation = syscall(SYS_eventfd2, initial, flags);
  std::unique_lock lock(gate_mutex);
  if (pause_child_state) {
    pause_child_state = false; entered = true; gate_changed.notify_all();
    gate_changed.wait(lock, [] { return continue_receive; });
  }
  return cancellation;
}
int main(int argc, char** argv) {
  alarm(10); rex::InitLogging();
  Dl_info runtime{};
  Check(dladdr(reinterpret_cast<void*>(&rex::net::socket_close), &runtime) && runtime.dli_fname,
        "resolved-actual-runtime");
  std::printf("{\"kind\":\"loaded_runtime\",\"path\":\"%s\"}\n", runtime.dli_fname);
  if (argc == 2 && std::strcmp(argv[1], "--connect-close") == 0) { ConnectRetirement(false); ConnectRetirement(true); std::puts(R"({"fixture":"socket_retirement_race","mode":"connect-close","failures":0,"outputs_preserved":true})"); return 0; }
  if (argc == 2 && std::strcmp(argv[1], "--accept-close") == 0) { AcceptRetirement(false); AcceptRetirement(true); std::puts(R"({"fixture":"socket_retirement_race","mode":"accept-close","failures":0,"outputs_preserved":true})"); return 0; }
  const bool expect_reuse = argc == 2 && std::strcmp(argv[1], "--expect-reuse") == 0;
  using namespace rex::system;
  XSocket receiver(nullptr);
  Check(receiver.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) == 0,
        "initialize");
  N_XSOCKADDR_IN local{}; local.sin_port = 0; local.sin_family = AF_INET; local.sin_addr = INADDR_LOOPBACK;
  Check(receiver.Bind(&local, sizeof(local)) == 0, "bind-owned-loopback");
  owned_descriptor = static_cast<int>(receiver.native_handle());
  std::array<uint8_t, 16> output{}; output.fill(0xCB); const auto before = output;
  N_XSOCKADDR_IN source{}; std::memset(&source, 0xDD, sizeof(source)); const auto source_before = source;
  uint32_t source_length = 123; int result = 777, error = 0;
  {
    std::lock_guard lock(gate_mutex); pause_receive = true;
  }
  std::thread worker([&] {
    result = receiver.RecvFrom(output.data(), output.size(), 0, &source, &source_length);
    error = errno;
  });
  {
    std::unique_lock lock(gate_mutex);
    Check(gate_changed.wait_for(lock, std::chrono::seconds(3), [] { return entered; }),
          "real-receive-sampled-owned-descriptor");
  }
  Check(receiver.Close() == 0 && receiver.native_handle() == uint64_t(-1), "close-after-snapshot");
  const int replacement = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
  Check(replacement >= 0, "replacement-native-socket");
  sockaddr_in endpoint{}; endpoint.sin_family = AF_INET; endpoint.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  Check(bind(replacement, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) == 0,
        "replacement-loopback-bind");
  socklen_t bytes = sizeof(endpoint);
  Check(getsockname(replacement, reinterpret_cast<sockaddr*>(&endpoint), &bytes) == 0,
        "replacement-endpoint");
  const std::array<uint8_t, 4> foreign{0xBA, 0xDF, 0x00, 0x0D};
  Check(sendto(replacement, foreign.data(), foreign.size(), 0,
                reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) == 4,
        "queue-replacement-owned-payload");
  {
    std::lock_guard lock(gate_mutex); continue_receive = true;
  }
  gate_changed.notify_all(); worker.join();
  if (expect_reuse) {
    Check(replacement == owned_descriptor && result == 4 &&
              std::memcmp(output.data(), foreign.data(), foreign.size()) == 0 && source_length == 16,
          "original-reused-descriptor-leaked-foreign-bytes");
    std::puts("CAUSAL BEFORE FIX: paused real receive consumed replacement descriptor bytes");
  } else {
    Check(replacement != owned_descriptor, "original-descriptor-not-reused-before-operation-return");
    Check(result == -1 && error == ENOTSOCK, "retired-operation-cancelled");
    Check(output == before && source_length == 123 &&
              std::memcmp(&source, &source_before, sizeof(source)) == 0,
          "guest-buffer-and-source-unchanged");
    std::array<uint8_t, 16> remaining{};
    Check(::recvfrom(replacement, remaining.data(), remaining.size(), MSG_DONTWAIT, nullptr, nullptr) == 4 &&
              std::memcmp(remaining.data(), foreign.data(), foreign.size()) == 0,
          "replacement-payload-was-never-consumed");
    std::puts("PASS socket retirement real descriptor-snapshot/reuse race");
    std::puts(R"({"fixture":"socket_retirement_race","mode":"receive-close","failures":0,"outputs_preserved":true})");
  }
  close(replacement);
}
