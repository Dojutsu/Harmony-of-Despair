// Real Linux blocking syscalls and descriptor reuse; no transport test hooks.
#include <rex/system/xsocket.h>
#include <rex/logging.h>
#include <rex/net/socket.h>
#include <dlfcn.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <unistd.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <future>
#include <new>
#include <thread>
#include <vector>

using rex::system::XSocket;
using rex::system::N_XSOCKADDR;
using rex::system::N_XSOCKADDR_IN;
namespace {
void Check(bool good, const char* name) {
  std::printf("socket-retirement %s %s\n", good ? "PASS" : "FAIL", name);
  std::fflush(stdout);
  if (!good) _exit(1);
}
void Initialize(XSocket& socket, bool stream = false) {
  Check(socket.Initialize(XSocket::X_AF_INET, stream ? XSocket::X_SOCK_STREAM : XSocket::X_SOCK_DGRAM,
                          stream ? XSocket::X_IPPROTO_TCP : XSocket::X_IPPROTO_UDP) == 0, "initialize");
}
sockaddr_in Bind(XSocket& socket) {
  N_XSOCKADDR_IN local{};
  local.sin_port = 0; local.sin_family = AF_INET;
  local.sin_addr = INADDR_LOOPBACK;
  Check(socket.Bind(&local, sizeof(local)) == 0, "bind-loopback");
  sockaddr_in endpoint{};
  socklen_t bytes = sizeof(endpoint);
  Check(getsockname(socket.native_handle(), reinterpret_cast<sockaddr*>(&endpoint), &bytes) == 0,
        "bound-endpoint");
  return endpoint;
}
void Blocking(pid_t tid, long syscall, uint64_t descriptor, bool check_descriptor = true) {
  const auto until = std::chrono::steady_clock::now() + std::chrono::seconds(3);
  const std::string path = "/proc/self/task/" + std::to_string(tid) + "/syscall";
  while (std::chrono::steady_clock::now() < until) {
    if (auto* input = std::fopen(path.c_str(), "r")) {
      long observed = -1; unsigned long long first = 0;
      const bool match = std::fscanf(input, "%ld %llx", &observed, &first) == 2 &&
          observed == syscall && (!check_descriptor || first == descriptor);
      std::fclose(input);
      if (match) { Check(true, "observed-owned-blocking-syscall"); return; }
    }
    std::this_thread::yield();
  }
  Check(false, "observed-owned-blocking-syscall");
}
void Retained(XSocket& socket, const XSocket::NativeLease& lease) {
  const auto before = std::chrono::steady_clock::now();
  Check(socket.Close() == 0, "logical-close");
  Check(std::chrono::steady_clock::now() - before < std::chrono::seconds(2), "close-bounded");
  Check(socket.native_handle() == uint64_t(-1) && lease.retired(), "retired-identity");
  Check(!socket.AcquireNativeLease(), "new-operation-refused");
  Check(socket.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) != 0,
        "reinitialize-refused-during-retirement");
  Check(fcntl(lease.handle(), F_GETFD) >= 0, "original-descriptor-pinned");
  const int replacement = ::socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
  Check(replacement >= 0 && uint64_t(replacement) != lease.handle(), "descriptor-not-reused-in-flight");
  ::close(replacement);
}
void Reused(uint64_t descriptor, XSocket::NativeLease& lease, XSocket& socket) {
  lease = {};
  Check(fcntl(descriptor, F_GETFD) == -1 && errno == EBADF, "descriptor-retired-after-last-lease");
  const int replacement = ::socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
  Check(replacement >= 0 && uint64_t(replacement) == descriptor, "descriptor-reused-after-retirement");
  Check(socket.Close() == 0 && fcntl(replacement, F_GETFD) >= 0, "repeat-close-preserves-replacement");
  std::array<uint8_t, 4> data{}; data.fill(0xCB);
  Check(socket.Recv(data.data(), data.size(), MSG_DONTWAIT) == -1 && errno == ENOTSOCK,
        "retired-recv-does-not-use-replacement");
  Check(!socket.PumpNatControl() && !socket.WaitReadable(0), "retired-control-and-wait-refused");
  Check(socket.Send(data.data(), data.size(), 0) == -1 && errno == ENOTSOCK,
        "retired-send-does-not-use-replacement");
  Check(fcntl(replacement, F_GETFD) >= 0, "replacement-still-valid");
  ::close(replacement);
}
void Udp(bool wait, bool queue_pump) {
  XSocket socket(nullptr); Initialize(socket); Bind(socket);
  auto lease = socket.AcquireNativeLease(); const auto descriptor = lease.handle();
  std::promise<pid_t> begun;
  std::array<uint8_t, 16> output{}; output.fill(0xCB);
  N_XSOCKADDR_IN source{}; std::memset(&source, 0xDD, sizeof(source));
  const auto source_before = source; uint32_t source_length = 123;
  int result = 777, error = 0;
  std::thread worker([&] {
    begun.set_value(static_cast<pid_t>(syscall(SYS_gettid)));
    result = wait ? int(socket.WaitReadable(0, true))
                  : socket.RecvFrom(output.data(), output.size(), 0, &source, &source_length);
    error = errno;
  });
  Blocking(begun.get_future().get(), wait ? SYS_poll : SYS_recvfrom, descriptor, !wait);
  std::promise<pid_t> pump_begun;
  bool pumped = true;
  std::thread pump;
  if (queue_pump) {
    pump = std::thread([&] { pump_begun.set_value(static_cast<pid_t>(syscall(SYS_gettid)));
                            pumped = socket.PumpNatControl(); });
    // The receive owns its mutex; the control pump must not prevent retirement.
    Blocking(pump_begun.get_future().get(), SYS_futex, 0, false);
  }
  Retained(socket, lease);
  worker.join();
  if (pump.joinable()) { pump.join(); Check(!pumped, "queued-control-pump-cancelled"); }
  Check(wait ? result == 0 : result == -1 && error == ENOTSOCK, "blocking-operation-cancelled");
  Check(std::all_of(output.begin(), output.end(), [](auto value) { return value == 0xCB; }),
        "cancelled-guest-bytes-unchanged");
  Check(std::memcmp(&source, &source_before, sizeof(source)) == 0 && source_length == 123,
        "cancelled-source-outputs-unchanged");
  Reused(descriptor, lease, socket);
}
void Accept() {
  XSocket listener(nullptr); Initialize(listener, true); Bind(listener);
  Check(listener.Listen(1) == 0, "listen");
  auto lease = listener.AcquireNativeLease(); const auto descriptor = lease.handle();
  std::promise<pid_t> begun; bool accepted = true;
  std::thread worker([&] {
    N_XSOCKADDR source{}; int length = sizeof(source);
    begun.set_value(static_cast<pid_t>(syscall(SYS_gettid)));
    accepted = bool(listener.Accept(&source, &length));
  });
  Blocking(begun.get_future().get(), SYS_accept4, descriptor);
  Retained(listener, lease); worker.join(); Check(!accepted, "blocked-accept-cancelled");
  Reused(descriptor, lease, listener);
}
void Tcp(bool send) {
  XSocket listener(nullptr), client(nullptr); Initialize(listener, true); Initialize(client, true);
  const auto endpoint = Bind(listener); Check(listener.Listen(1) == 0, "listen");
  N_XSOCKADDR target{}; std::memcpy(&target, &endpoint, sizeof(target));
  Check(client.Connect(&target, sizeof(target)) == 0, "connect-loopback");
  N_XSOCKADDR remote{}; int size = sizeof(remote);
  auto peer = listener.Accept(&remote, &size); Check(bool(peer), "accept-loopback");
  listener.Close();
  auto lease = client.AcquireNativeLease(); const auto descriptor = lease.handle();
  std::vector<uint8_t> data(1024 * 1024, 0xAB);
  if (send) {
    rex::be<uint32_t> small = 4096;
    Check(client.SetOption(0xFFFF, 0x1001, &small, 4) == 0, "small-send-buffer");
    Check(client.SetNonBlocking(true) == 0, "nonblocking-fill");
    bool full = false;
    for (unsigned attempts = 0; attempts < 1024; ++attempts) {
      if (client.Send(data.data(), data.size(), 0) < 0) {
        Check(errno == EAGAIN || errno == EWOULDBLOCK, "fill-would-block"); full = true; break;
      }
    }
    Check(full, "send-buffer-filled");
    Check(client.SetNonBlocking(false) == 0, "blocking-send");
  }
  std::promise<pid_t> begun; int result = 777;
  std::thread worker([&] {
    begun.set_value(static_cast<pid_t>(syscall(SYS_gettid)));
    result = send ? client.Send(data.data(), data.size(), 0) : client.Recv(data.data(), data.size(), 0);
  });
  Blocking(begun.get_future().get(), send ? SYS_sendto : SYS_recvfrom, descriptor);
  Retained(client, lease); worker.join();
  Check(send ? result == -1 || (result >= 0 && result < int(data.size())) : result == -1,
        "blocked-tcp-operation-returned");
  peer->Close(); peer.reset();
  // The listener's lower descriptor was released earlier; hold other free
  // slots so the reuse assertion selects the exact retired client descriptor.
  std::vector<int> fillers;
  while (true) { const int fd = ::open("/dev/null", O_RDONLY | O_CLOEXEC);
    Check(fd >= 0, "fill-lower-descriptor");
    if (uint64_t(fd) > descriptor) { ::close(fd); break; }
    fillers.push_back(fd);
  }
  Reused(descriptor, lease, client);
  for (int fd : fillers) ::close(fd);
}
void ConnectBacklog(bool timed = false) {
  XSocket listener(nullptr), client(nullptr); Initialize(listener, true); Initialize(client, true);
  const auto endpoint = Bind(listener); Check(listener.Listen(1) == 0, "saturated-listen");
  std::array<int, 2> queued{};
  for (auto& fd : queued) {
    fd = ::socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, IPPROTO_TCP);
    Check(fd >= 0 && ::connect(fd, reinterpret_cast<const sockaddr*>(&endpoint), sizeof(endpoint)) == 0,
          "fill-loopback-accept-backlog");
  }
  N_XSOCKADDR target{}; std::memcpy(&target, &endpoint, sizeof(target));
  auto lease = client.AcquireNativeLease(); const auto descriptor = lease.handle();
  if (timed) {
    rex::be<uint32_t> timeout = 50;
    Check(client.SetOption(0xFFFF, 0x1005, &timeout, sizeof(timeout)) == 0, "finite-connect-send-timeout");
    const auto before = std::chrono::steady_clock::now();
    Check(client.Connect(&target, sizeof(target)) != 0 && errno == EINPROGRESS, "connect-timeout-preserved");
    const auto elapsed = std::chrono::steady_clock::now() - before;
    Check(elapsed >= std::chrono::milliseconds(25) && elapsed < std::chrono::seconds(2), "connect-timeout-bounded");
    Check(!(fcntl(descriptor, F_GETFL) & O_NONBLOCK), "timeout-restores-native-mode");
    client.Close(); lease = {}; for (auto fd : queued) close(fd); return;
  }
  std::promise<pid_t> begun; rex::X_STATUS result = 0; int error = 0;
  std::thread worker([&] {
    begun.set_value(static_cast<pid_t>(syscall(SYS_gettid)));
    result = client.Connect(&target, sizeof(target)); error = errno;
  });
  Blocking(begun.get_future().get(), SYS_ppoll, 0, false);
  Check(!(fcntl(descriptor, F_GETFL) & O_NONBLOCK), "blocking-mode-restored-before-connect-poll");
  const auto changed = std::chrono::steady_clock::now();
  Check(client.SetNonBlocking(true) == 0 && std::chrono::steady_clock::now() - changed < std::chrono::seconds(1),
        "mode-update-prompt-during-connect-poll");
  Retained(client, lease); worker.join();
  Check(result != 0 && error == ENOTSOCK, "blocked-loopback-connect-cancelled");
  Check(fcntl(descriptor, F_GETFL) & O_NONBLOCK, "concurrent-guest-mode-update-preserved");
  lease = {}; client.Close();
  for (auto fd : queued) close(fd);
}
void ConcurrentMode(bool stream) {
  XSocket socket(nullptr), listener(nullptr); Initialize(socket, stream);
  sockaddr_in endpoint{}; int remote = -1; rex::system::object_ref<XSocket> peer;
  N_XSOCKADDR target{};
  if (stream) {
    Initialize(listener, true); endpoint = Bind(listener); Check(listener.Listen(1) == 0, "mode-listen");
    std::memcpy(&target, &endpoint, sizeof(target));
    Check(socket.Connect(&target, sizeof(target)) == 0, "mode-tcp-connect");
    N_XSOCKADDR source{}; int bytes = sizeof(source); peer = listener.Accept(&source, &bytes);
    Check(bool(peer), "mode-tcp-accept"); listener.Close();
  } else {
    endpoint = Bind(socket);
    remote = ::socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, IPPROTO_UDP);
    sockaddr_in sender{}; sender.sin_family = AF_INET; sender.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    Check(remote >= 0 && ::bind(remote, reinterpret_cast<sockaddr*>(&sender), sizeof(sender)) == 0,
          "mode-udp-peer");
    socklen_t bytes = sizeof(sender); Check(getsockname(remote, reinterpret_cast<sockaddr*>(&sender), &bytes) == 0,
                                            "mode-udp-peer-endpoint");
    std::memcpy(&target, &sender, sizeof(target));
  }
  std::promise<pid_t> begun; std::array<uint8_t, 4> data{}; int received = -1;
  std::thread receive([&] { begun.set_value(static_cast<pid_t>(syscall(SYS_gettid)));
                           received = socket.Recv(data.data(), data.size(), 0); });
  const auto tid = begun.get_future().get(); Blocking(tid, SYS_recvfrom, socket.native_handle());
  auto before = std::chrono::steady_clock::now();
  Check(socket.SetNonBlocking(true) == 0 && std::chrono::steady_clock::now() - before < std::chrono::seconds(1),
        "nonblocking-update-prompt-during-blocked-receive");
  Check(socket.SetNonBlocking(false) == 0, "blocking-update-prompt-during-blocked-receive");
  before = std::chrono::steady_clock::now(); errno = 0;
  const auto connected = socket.Connect(&target, sizeof(target)); const int connect_error = errno;
  Check(std::chrono::steady_clock::now() - before < std::chrono::seconds(1),
        "connect-prompt-during-blocked-receive");
  Check(stream ? connected == 0 || connect_error == EISCONN : connected == 0,
        "existing-tcp-or-udp-association-preserved");
  Check(!(fcntl(socket.native_handle(), F_GETFL) & O_NONBLOCK), "blocking-mode-preserved-during-association");
  Blocking(tid, SYS_recvfrom, socket.native_handle());
  const std::array<uint8_t, 4> payload{0xAB, 0xCD, 0xEF, 0x12};
  Check(stream ? peer->Send(payload.data(), payload.size(), 0) == 4 :
        sendto(remote, payload.data(), payload.size(), 0, reinterpret_cast<sockaddr*>(&endpoint), sizeof(endpoint)) == 4,
        "deliver-original-blocking-receive");
  receive.join(); Check(received == 4 && data == payload, "blocked-receive-does-not-return-spurious-would-block");
  if (remote >= 0) close(remote);
}
void ExecInheritance(const char* executable) {
  XSocket listener(nullptr), client(nullptr); Initialize(listener, true); Initialize(client, true);
  const auto endpoint = Bind(listener); Check(listener.Listen(1) == 0, "exec-listen");
  N_XSOCKADDR target{}; std::memcpy(&target, &endpoint, sizeof(target));
  Check(client.Connect(&target, sizeof(target)) == 0, "exec-connect");
  N_XSOCKADDR remote{}; int bytes = sizeof(remote);
  auto peer = listener.Accept(&remote, &bytes); Check(bool(peer), "exec-accepted-child");
  std::array<XSocket::NativeLease, 3> owned{listener.AcquireNativeLease(), client.AcquireNativeLease(), peer->AcquireNativeLease()};
  std::array<std::string, 6> descriptors{};
  for (size_t i = 0; i < owned.size(); ++i) {
    Check((fcntl(owned[i].handle(), F_GETFD) & FD_CLOEXEC) &&
              (fcntl(owned[i].cancellation_handle(), F_GETFD) & FD_CLOEXEC),
          "owned-and-accepted-descriptors-close-on-exec");
    descriptors[i * 2] = std::to_string(owned[i].handle());
    descriptors[i * 2 + 1] = std::to_string(owned[i].cancellation_handle());
  }
  const auto child = fork();
  if (!child) {
    const auto* loader = std::getenv("HARMONY_TEST_ELF_LOADER");
    const auto* library = std::getenv("HARMONY_TEST_LIBRARY_PATH");
    if (bool(loader) != bool(library)) _exit(2);
    if (loader) execl(loader, loader, "--library-path", library, executable, "--exec-check",
                      descriptors[0].c_str(), descriptors[1].c_str(), descriptors[2].c_str(),
                      descriptors[3].c_str(), descriptors[4].c_str(), descriptors[5].c_str(), nullptr);
    else execl(executable, executable, "--exec-check", descriptors[0].c_str(), descriptors[1].c_str(),
                descriptors[2].c_str(), descriptors[3].c_str(), descriptors[4].c_str(), descriptors[5].c_str(), nullptr);
    _exit(2);
  }
  int status = 0;
  Check(child > 0 && waitpid(child, &status, 0) == child && WIFEXITED(status) && WEXITSTATUS(status) == 0,
        "actual-exec-inherits-no-owned-session-descriptors");
}
}  // namespace
int main(int argc, char** argv) {
  if (argc == 8 && std::strcmp(argv[1], "--exec-check") == 0) {
    for (int i = 2; i < argc; ++i)
      Check(fcntl(std::stoi(argv[i]), F_GETFD) == -1 && errno == EBADF, "exec-closed-owned-descriptor");
    return 0;
  }
  alignas(N_XSOCKADDR) std::array<uint8_t, sizeof(N_XSOCKADDR)> generic_storage;
  alignas(N_XSOCKADDR_IN) std::array<uint8_t, sizeof(N_XSOCKADDR_IN)> ipv4_storage;
  generic_storage.fill(0xA5); ipv4_storage.fill(0xA5);
  new (generic_storage.data()) N_XSOCKADDR(); new (ipv4_storage.data()) N_XSOCKADDR_IN();
  Check(std::all_of(generic_storage.begin(), generic_storage.end(), [](auto value) { return value == 0; }) &&
        std::all_of(ipv4_storage.begin(), ipv4_storage.end(), [](auto value) { return value == 0; }),
        "native-address-defaults-zero-dirty-storage");
  Dl_info runtime{};
  Check(dladdr(reinterpret_cast<void*>(&rex::net::socket_close), &runtime) && runtime.dli_fname,
        "resolved-actual-runtime");
  std::printf("{\"kind\":\"loaded_runtime\",\"path\":\"%s\"}\n", runtime.dli_fname);
  char executable[4096];
  if (std::getenv("HARMONY_TEST_ELF_LOADER")) {
    if (argv[0][0] != '/' || !realpath(argv[0], executable) || access(executable, X_OK) != 0) return 2;
  } else {
    const auto length = readlink("/proc/self/exe", executable, sizeof(executable) - 1);
    if (length <= 0) return 2;
    executable[length] = 0;
  }
  for (int mode = 0; mode < 11; ++mode) {
    std::fflush(nullptr); const pid_t child = fork();
    if (!child) {
      alarm(10); rex::InitLogging();
      if (mode < 3) Udp(mode == 1, mode == 2);
      else if (mode == 3) Accept();
      else if (mode < 6) Tcp(mode == 5);
      else if (mode == 6) ConnectBacklog();
      else if (mode == 7) ExecInheritance(executable);
      else if (mode < 10) ConcurrentMode(mode == 9);
      else ConnectBacklog(true);
      _exit(0);
    }
    int status = 0;
    if (child <= 0 || waitpid(child, &status, 0) != child || !WIFEXITED(status) || WEXITSTATUS(status)) {
      std::fprintf(stderr, "FAIL socket retirement child mode=%d status=%d\n", mode, status);
      return 1;
    }
  }
  std::puts("PASS socket retirement 11 bounded real syscall/exec cases");
  std::puts(R"({"fixture":"socket_retirement","cases":11,"failures":0,"blocked_io_cancelled":true,"descriptor_reuse_preserved":true,"exec_inheritance_closed":true,"mode_updates_prompt":true,"udp_connect_overlap_preserved":true,"connected_tcp_overlap_preserved":true,"finite_connect_timeout_preserved":true})");
}
