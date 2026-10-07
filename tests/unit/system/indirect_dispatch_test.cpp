// Use the actual generator template and runtime registry, never a copied macro.
#include <rex/logging.h>
#include <rex/ppc/context.h>
#include <rex/runtime.h>
#include <rex/system/function_dispatcher.h>
#include <rex/system/xmemory.h>

#include <cerrno>
#include <chrono>
#include <array>
#include <algorithm>
#include <fcntl.h>
#include <string>
#include <csignal>
#include <cstring>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <thread>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

// Keep historical module identities available to the generated macro. The
// hardened template must not dereference the guest table even when it exists.
#define REX_CODE_BASE 0x82220000u
#define REX_CODE_SIZE 0x10000u
#define REX_THUNK_RESERVE_SIZE 0x10000u
#define REX_FUNCTION_TABLE_BASE 0x8C000000u
#include "indirect_call_test.inc"

namespace {
constexpr uint32_t code = REX_CODE_BASE, table = REX_FUNCTION_TABLE_BASE;
constexpr uint32_t target = code + 0x10, other_code = 0x83000000;
constexpr uint32_t other_table = 0x8D000000, other_target = other_code + 0x10;
unsigned checks = 0, legitimate_calls = 0, replacement_calls = 0, hostile_calls = 0;
std::string child_loader, child_library_path, child_program;
void Check(bool condition, const char* message) {
  ++checks;
  if (!condition) throw std::runtime_error(message);
}
void Legitimate(PPCContext& ctx, uint8_t*) { ++legitimate_calls; ctx.r3.u64 = 0x12345678; }
void Replacement(PPCContext& ctx, uint8_t*) { ++replacement_calls; ctx.r3.u64 = 0x87654321; }
void HostileMirror(PPCContext& ctx, uint8_t*) { ++hostile_calls; ctx.r3.u64 = 0xDEAD; }
void RegisterA(rex::runtime::IModuleRegistrar* registry) {
  Check(registry->SetFunction(target, Legitimate), "register aligned function A");
}
void RegisterB(rex::runtime::IModuleRegistrar* registry) {
  Check(registry->SetFunction(other_target, Legitimate), "register aligned function B");
}
void RegisterReplacement(rex::runtime::IModuleRegistrar* registry) {
  Check(registry->SetFunction(target, Replacement), "register replacement at the reused guest address");
}
void Invoke(PPCContext& ctx, uint8_t* base, uint32_t address) {
  REX_CALL_INDIRECT_FUNC(address);
}
void Poison(rex::memory::Memory& memory, uint32_t code_base, uint32_t table_base,
            uint32_t address) {
  auto* slot = memory.TranslateVirtual<PPCFunc**>(table_base + (address - code_base) * 2);
  *slot = HostileMirror;
  Check(*slot == HostileMirror, "guest mirror is actually corrupted");
}
void InitializeA(rex::runtime::FunctionDispatcher& registry) {
  Check(registry.InitializeFunctionTable(code, REX_CODE_SIZE, 0x82000000, 0x980000,
      table, true), "register historical explicit table identity A");
  registry.RegisterModule("dispatch-boundary-a", code, RegisterA);
}
void Run(rex::Runtime& runtime, std::string_view mode) {
  auto& memory = *runtime.memory();
  auto& registry = *runtime.function_dispatcher();
  InitializeA(registry);
  PPCContext ctx{};
  uint8_t* base = memory.virtual_membase();
  auto invalid = rex::runtime::ResolveIndirectFunction(0);
  Check(invalid != nullptr && invalid != Legitimate, "existing invalid-function trap available");
  Poison(memory, code, table, target);
  if (!mode.empty()) {
    uint32_t rejected = 0;
    if (mode == "--unaligned") rejected = target + 1;
    else if (mode == "--unregistered") {
      rejected = code + 0x100;
      Poison(memory, code, table, rejected);
    } else if (mode == "--out-of-range") rejected = 0xFFFFFFFC;
    else if (mode == "--unloaded") {
      Check(registry.UnregisterModule("dispatch-boundary-a").has_value(), "unregister module before invalid call");
      rejected = target;
    } else throw std::runtime_error("unknown fixture mode");
    Check(registry.GetFunction(rejected) == nullptr, "invalid target absent from trusted map");
    Check(rex::runtime::ResolveIndirectFunction(rejected) == invalid, "invalid target resolves to existing trap");
    const std::string marker = "dispatch-invalid-call-ready:" + std::string(mode) + "\n";
    Check(write(STDOUT_FILENO, marker.data(), marker.size()) == static_cast<ssize_t>(marker.size()),
        "invalid-call progress marker published");
    Invoke(ctx, base, rejected);
    throw std::runtime_error("invalid target returned instead of trapping");
  }
  Check(registry.GetFunction(target) == Legitimate, "guest corruption does not modify host registry");
  Invoke(ctx, base, target);
  Check(legitimate_calls == 1 && hostile_calls == 0 && ctx.r3.u64 == 0x12345678,
      "actual generated macro calls only registered target despite hostile mirror");
  Check(ctx.last_indirect_target == target, "last indirect target records admitted guest address");
  for (uint32_t delta = 1; delta < 4; ++delta) {
    Check(!registry.SetFunction(target + delta, HostileMirror), "registry rejects unaligned registration");
    Check(!memory.SetFunction(target + delta, HostileMirror), "mirror writer rejects unaligned registration");
    Check(registry.GetFunction(target + delta) == nullptr, "unaligned lookup is absent");
    Check(rex::runtime::ResolveIndirectFunction(target + delta) == invalid, "unaligned target uses invalid trap");
  }
  Check(registry.GetFunction(target) == Legitimate, "unaligned writes preserve aligned registration");
  Check(registry.InitializeFunctionTable(other_code, 0x10000, other_code, 0x100000,
      other_table), "register cross-module explicit identity B");
  registry.RegisterModule("dispatch-boundary-b", other_code, RegisterB);
  Poison(memory, other_code, other_table, other_target);
  Invoke(ctx, base, other_target);
  Check(legitimate_calls == 2 && hostile_calls == 0, "cross-module call also ignores guest mirror");
  const uint32_t thunk = registry.AllocateThunk(Legitimate, target);
  Check(thunk != 0, "registered module thunk allocated");
  Poison(memory, code, table, thunk);
  Invoke(ctx, base, thunk);
  Check(legitimate_calls == 3 && hostile_calls == 0, "thunk dispatch uses trusted registration");
  Check(registry.UnregisterModule("dispatch-boundary-a").has_value(), "module lifecycle removes table A");
  Check(registry.GetFunction(target) == nullptr && registry.GetFunction(thunk) == nullptr,
      "unload removes function and thunk registrations");
  Check(rex::runtime::ResolveIndirectFunction(target) == invalid &&
      rex::runtime::ResolveIndirectFunction(thunk) == invalid, "unloaded targets no longer resolve");
  Invoke(ctx, base, other_target);
  Check(legitimate_calls == 4 && hostile_calls == 0, "unload preserves another module");
  Check(registry.InitializeFunctionTable(code, REX_CODE_SIZE, 0x82000000, 0x980000,
      table, true), "reused module keeps historical table base");
  registry.RegisterModule("dispatch-boundary-a", code, RegisterReplacement);
  Poison(memory, code, table, target);
  Invoke(ctx, base, target);
  Check(replacement_calls == 1 && legitimate_calls == 4 && hostile_calls == 0 &&
      ctx.r3.u64 == 0x87654321, "reload invokes fresh host mapping despite corrupted mirror");
}
void ExpectAbort(const char* executable, const char* mode) {
  int output[2];
  Check(pipe2(output, O_CLOEXEC) == 0, "private invalid-target output pipe");
  const auto child = fork();
  if (child < 0) { close(output[0]); close(output[1]); }
  Check(child >= 0, "spawn isolated invalid-target process");
  if (!child) {
    close(output[0]);
    if (dup2(output[1], STDOUT_FILENO) < 0 || dup2(output[1], STDERR_FILENO) < 0) _exit(126);
    close(output[1]);
    if (child_loader.empty()) {
      execl(executable, executable, mode, static_cast<char*>(nullptr));
    } else {
      execl(child_loader.c_str(), child_loader.c_str(), "--library-path",
            child_library_path.c_str(), child_program.c_str(), mode, static_cast<char*>(nullptr));
    }
    _exit(127);
  }
  close(output[1]);
  const int flags = fcntl(output[0], F_GETFL);
  if (flags < 0 || fcntl(output[0], F_SETFL, flags | O_NONBLOCK) < 0) {
    kill(child, SIGKILL);
    while (waitpid(child, nullptr, 0) < 0 && errno == EINTR) {}
    close(output[0]);
    throw std::runtime_error("cannot collect bounded child diagnostics");
  }
  std::string diagnostic;
  auto drain = [&] {
    std::array<char, 512> bytes;
    for (;;) {
      const auto count = read(output[0], bytes.data(), bytes.size());
      if (count < 0 && errno == EINTR) continue;
      if (count <= 0) break;
      // Keep bounded evidence while draining every byte to avoid pipe backpressure.
      if (diagnostic.size() < 65536)
        diagnostic.append(bytes.data(), std::min<size_t>(count, 65536 - diagnostic.size()));
    }
  };
  int status = 0;
  bool finished = false;
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(10);
  while (std::chrono::steady_clock::now() < deadline) {
    drain();
    const auto result = waitpid(child, &status, WNOHANG);
    if (result == child) { finished = true; break; }
    if (result < 0 && errno != EINTR) break;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  if (!finished) {
    kill(child, SIGKILL);
    while (waitpid(child, &status, 0) < 0 && errno == EINTR) {}
  }
  drain();
  close(output[0]);
  Check(finished, "invalid target must finish within bounded timeout");
  Check(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT,
      "invalid generated call must reach existing abort trap, never SIGSEGV or hostile callback");
  Check(diagnostic.find(std::string("dispatch-invalid-call-ready:") + mode + "\n") != std::string::npos,
      "child reached the exact invalid call after all setup assertions");
  Check(diagnostic.find("Call to invalid or unregistered function at guest address") != std::string::npos,
      "child reported the existing invalid-function trap, not an unrelated abort");
}
}  // namespace
int main(int argc, char** argv) {
  try {
    rlimit core_limit{0, 0};
    Check(setrlimit(RLIMIT_CORE, &core_limit) == 0, "fixture disables only its own core dumps");
    const char* loader = std::getenv("HARMONY_TEST_ELF_LOADER");
    const char* library_path = std::getenv("HARMONY_TEST_LIBRARY_PATH");
    Check(bool(loader) == bool(library_path),
        "fixture child loader and library path must be configured together");
    if (loader) {
      Check(loader[0] == '/' && argv[0][0] == '/' && library_path[0],
          "explicit child loader requires absolute loader/program and nonempty library path");
      child_loader = loader;
      child_library_path = library_path;
      child_program = argv[0];
    }
    if (argc == 1)
      std::cout << "Indirect dispatch child launch: "
          << (child_loader.empty() ? "direct" : "explicit-loader") << std::endl;
    // The existing fatal trap logs synchronously; expose its message in the
    // private child pipe so an unrelated SIGABRT cannot satisfy this fixture.
    rex::LogConfig log_config;
    log_config.log_to_console = true;
    log_config.default_level = spdlog::level::critical;
    rex::InitLogging(log_config);
    {
      rex::Runtime runtime("");
      rex::RuntimeConfig config;
      config.tool_mode = true;
      Check(runtime.Setup(std::move(config)) == 0, "native isolated runtime setup");
      Check(runtime.memory() && runtime.function_dispatcher(), "runtime dispatch available");
      Run(runtime, argc == 2 ? std::string_view(argv[1]) : std::string_view{});
      runtime.Shutdown();
    }
    const auto executable = std::filesystem::canonical("/proc/self/exe").string();
    for (auto mode : {"--unaligned", "--unregistered", "--out-of-range", "--unloaded"})
      ExpectAbort(executable.c_str(), mode);
    std::cout << "Indirect dispatch actual generator template: hostile guest mirrors, "
        "unaligned/unregistered/out-of-range targets, cross-module thunks and reload PASS ("
        << checks << " checks)\n";
    return 0;
  } catch (const std::exception& exception) {
    std::cerr << "Indirect dispatch regression: " << exception.what() << '\n';
    return 1;
  }
}
