// Execute the actual emitted guest block with the production Linux access path.
#include "harmonyrecomp_pch.h"
#include "scene_cache_hook.h"

#include <rex/platform/exceptions.h>
#include <rex/platform/guest_fault_state.h>
#include <sys/mman.h>
#include <unistd.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace {
unsigned checks = 0;
unsigned failures = 0;
void Check(bool condition, const char* name) {
  ++checks;
  if (!condition) { ++failures; std::cerr << "FAIL " << name << '\n'; }
}

void GeneratedBlock(PPCContext& ctx, uint8_t* base) {
  goto loc_8247A4C8;
#include "scene_cache_hook_generated.inc"
}
void OriginalBlock(PPCContext& ctx, uint8_t* base) {
  goto loc_8247A4C8;
#include "scene_cache_hook_original.inc"
}
using Block = void (*)(PPCContext&, uint8_t*);

struct Mapping {
  uint8_t* base;
  size_t page;
  Mapping() {
    const long native_page = sysconf(_SC_PAGESIZE);
    if (native_page < 1024) throw std::runtime_error("unsupported native page size");
    page = static_cast<size_t>(native_page);
    base = static_cast<uint8_t*>(mmap(nullptr, page * 3, PROT_READ | PROT_WRITE,
                                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
    if (base == MAP_FAILED) throw std::runtime_error("mmap failed");
    if (mprotect(base, page, PROT_NONE)) {
      munmap(base, page * 3); throw std::runtime_error("guard-page mprotect failed");
    }
  }
  ~Mapping() { munmap(base, page * 3); }
  void Reset() { std::memset(base + page, 0xA5, page * 2); }
  std::vector<uint8_t> Snapshot() const { return {base + page, base + page * 3}; }
  void Put32(size_t offset, uint32_t value) {
    value = __builtin_bswap32(value); std::memcpy(base + offset, &value, sizeof(value));
  }
};
struct Outcome {
  bool returned = false;
  bool fault = false;
  rex::SehException::Code code = rex::SehException::UNKNOWN;
  uintptr_t address = 0;
  uintptr_t intent = 99;
};
Outcome Execute(Block block, PPCContext& ctx, uint8_t* base) {
  rex::guest::ExecutionActivation activation;
  rex::SehGuard guard;
  Outcome outcome;
  try { block(ctx, base); outcome.returned = true; }
  catch (const rex::SehException& exception) {
    outcome.fault = true; outcome.code = exception.code(); outcome.address = exception.address();
    outcome.intent = rex::platform::seh_thread_state().info[0];
  }
  Check(!activation.HasPendingFault(), "emitted block leaves no pending fault");
  Check(!rex::guest::HasArmedAccessFrame(), "emitted block disarms native access leaf");
  Check(activation.published_faults() == (outcome.fault ? 1u : 0u) &&
        activation.consumed_faults() == (outcome.fault ? 1u : 0u),
        "emitted block delivers each hardware fault exactly once");
  return outcome;
}
PPCContext Context(uint64_t scene) {
  PPCContext ctx{};
  ctx.r9.u64 = scene;
  ctx.r11.u64 = 0xDEADBEEF12345678ULL;
  ctx.r20.u64 = 0x123456789ABC007AULL;
  ctx.r3.u64 = 0xFEEDFACE;
  ctx.cr6.set_raw(0xA);
  return ctx;
}
void CheckFault(const Outcome& outcome, uintptr_t address, uintptr_t intent) {
  Check(outcome.fault && !outcome.returned, "original nonzero invalid access remains a fault");
  Check(outcome.code == rex::SehException::ACCESS_VIOLATION, "actual guest access-violation code");
  Check(outcome.address == address, "actual exact hardware fault address");
  Check(outcome.intent == intent, "actual hardware read/write intent");
}
void HelperContract() {
  for (uint64_t bits : {0ULL, 0xFFFFFFFF00000000ULL, 1ULL,
                        0xFFFFFFFF00000001ULL, 0xFFFFFFFFFFFFFFFFULL}) {
    PPCRegister scene{}; scene.u64 = bits;
    const bool absent = HarmonySkipAbsentSceneNotification(scene);
    Check(absent == (static_cast<uint32_t>(bits) == 0), "helper uses low32 guest address only");
    Check(scene.u64 == bits, "helper preserves all64 register bits");
  }
}
void NullContract(Mapping& ram) {
  for (uint64_t scene : {0ULL, 0xA5A5A5A500000000ULL}) {
    ram.Reset(); const auto before = ram.Snapshot();
    auto ctx = Context(scene);
    const auto expected_r11 = ctx.r11.u64;
    const auto expected_cr6 = ctx.cr6.raw();
    auto outcome = Execute(GeneratedBlock, ctx, ram.base);
    Check(outcome.returned && !outcome.fault, "guarded absent scene returns without access");
    Check(ctx.r3.u64 == ctx.r20.u64, "guarded absent scene keeps actual common guest return value");
    Check(ctx.r9.u64 == scene, "guarded absent scene preserves scene register");
    Check(ctx.r11.u64 == expected_r11 && ctx.cr6.raw() == expected_cr6,
          "guarded absent scene skips original read and comparison");
    Check(ram.Snapshot() == before, "guarded absent scene performs no writes");
    ctx = Context(scene);
    outcome = Execute(OriginalBlock, ctx, ram.base);
    CheckFault(outcome, reinterpret_cast<uintptr_t>(ram.base + 0x80), 0);
    Check(ctx.r3.u64 == 0xFEEDFACE, "faulting original null path does not reach guest return");
    Check(ctx.r9.u64 == scene, "faulting original null path preserves scene register");
    Check(ram.Snapshot() == before, "faulting original null path performs no writes");
  }
}
void ValidContract(Mapping& ram) {
  const auto object = static_cast<uint32_t>(ram.page);
  const auto payload = static_cast<uint32_t>(ram.page * 2);
  for (uint32_t type : {34u, 35u, 0u, 33u, 36u, 0xFFFFFFFFu}) {
    for (uint64_t scene : {static_cast<uint64_t>(object), static_cast<uint64_t>(0xABCDEF1200000000ULL | object)}) {
      for (Block block : {GeneratedBlock, OriginalBlock}) {
        ram.Reset(); ram.Put32(object + 128, type); ram.Put32(object + 156, payload);
        auto expected = ram.Snapshot();
        if (type == 34 || type == 35) expected[ram.page + 972] = 0x7A;
        auto ctx = Context(scene);
        const auto outcome = Execute(block, ctx, ram.base);
        Check(outcome.returned && !outcome.fault, "valid emitted scene path completes");
        Check(ctx.r3.u64 == ctx.r20.u64, "valid emitted path preserves actual common return value");
        Check(ctx.r9.u64 == scene, "valid emitted path preserves all64 scene register bits");
        Check(ram.Snapshot() == expected,
              "only screen types34and35 write exactly payload972 with r20 lowbyte");
      }
    }
  }
}
void InvalidContract(Mapping& ram) {
  const uint64_t invalid_scene = 64;
  for (Block block : {GeneratedBlock, OriginalBlock}) {
    ram.Reset(); const auto before = ram.Snapshot(); auto ctx = Context(invalid_scene);
    const auto outcome = Execute(block, ctx, ram.base);
    CheckFault(outcome, reinterpret_cast<uintptr_t>(ram.base + invalid_scene + 128), 0);
    Check(ctx.r9.u64 == invalid_scene, "nonzero invalid scene retains register");
    Check(ram.Snapshot() == before, "nonzero invalid scene fault does not write");
  }
  // A valid screen with an invalid payload must still fault at the original store.
  for (Block block : {GeneratedBlock, OriginalBlock}) {
    ram.Reset(); ram.Put32(ram.page + 128, 34); ram.Put32(ram.page + 156, 0);
    const auto before = ram.Snapshot(); auto ctx = Context(ram.page);
    const auto outcome = Execute(block, ctx, ram.base);
    CheckFault(outcome, reinterpret_cast<uintptr_t>(ram.base + 972), 1);
    Check(ram.Snapshot() == before, "invalid payload retains original fault with no committed write");
  }
}
}  // namespace
int main() {
  try {
    rex::initialize_seh(); Mapping ram;
    HelperContract(); NullContract(ram); ValidContract(ram); InvalidContract(ram);
  } catch (const std::exception& exception) {
    std::cerr << "FAIL scene hook fixture setup: " << exception.what() << '\n'; return 1;
  }
  std::cout << (failures ? "FAIL " : "PASS ") << "scene_cache_hook " << checks
            << " checks, " << failures << " failures\n";
  return failures ? 1 : 0;
}
