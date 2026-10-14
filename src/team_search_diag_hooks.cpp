// Logging-only hooks around the title's Quick Search candidate filter.
//
// Each hook replaces the generated weak symbol, runs the original body through
// its __imp__ entry unchanged and logs what it saw (first calls only):
//   sub_82410388  quick-match candidate filter / join step
//   sub_82441E60  candidate ping from the QoS results (-1 = not usable)
//   sub_825926B0  chapter catalog lookup by host chapter id (-1 = not found)
//   sub_82441710  join the chosen candidate
//   sub_824108E8  show a team-search error (0x100046 = "unable to find team")

#include <atomic>
#include <string>

#include <fmt/format.h>
#include <rex/logging.h>
#include <rex/ppc/context.h>
#include <rex/ppc/func.h>

namespace {

constexpr uint32_t kMatchmakingManager = 0x829034E0;
constexpr uint32_t kChapterCatalogPointer = 0x8291D9C8;

uint32_t Load32(uint8_t* base, uint32_t address) {
  return __builtin_bswap32(*reinterpret_cast<volatile uint32_t*>(base + address));
}

bool ShouldLog(std::atomic<uint32_t>& counter, uint32_t limit = 60) {
  return counter.fetch_add(1) < limit;
}

}  // namespace

REX_EXTERN(__imp__sub_82410388);
REX_EXTERN(__imp__sub_82441E60);
REX_EXTERN(__imp__sub_825926B0);
REX_EXTERN(__imp__sub_82441710);
REX_EXTERN(__imp__sub_824108E8);

extern "C" REX_FUNC(sub_82410388) {
  static std::atomic<uint32_t> logged{0};
  bool log = ShouldLog(logged);
  uint32_t self = ctx.r3.u32;
  if (log)
    REXLOG_INFO("QUICK_DIAG filter enter self={:08X} r4={:08X} r5={:08X} mm_count={} mm_task={:08X}",
                self, ctx.r4.u32, ctx.r5.u32, Load32(base, kMatchmakingManager + 80),
                Load32(base, kMatchmakingManager + 36));
  __imp__sub_82410388(ctx, base);
  if (log) REXLOG_INFO("QUICK_DIAG filter exit self={:08X} result={:08X}", self, ctx.r3.u32);
}

extern "C" REX_FUNC(sub_82441E60) {
  static std::atomic<uint32_t> logged{0};
  bool log = ShouldLog(logged);
  uint32_t index = ctx.r3.u32;
  __imp__sub_82441E60(ctx, base);
  if (log) REXLOG_INFO("QUICK_DIAG ping index={} rtt={}", index, ctx.r3.s32);
}

extern "C" REX_FUNC(sub_825926B0) {
  static std::atomic<uint32_t> logged{0};
  bool log = ShouldLog(logged);
  uint32_t chapter = ctx.r3.u32;
  std::string ids;
  uint32_t count = 0;
  uint32_t catalog = Load32(base, kChapterCatalogPointer);
  if (log && catalog) {
    uint32_t begin = Load32(base, catalog + 204);
    uint32_t end = Load32(base, catalog + 208);
    if (end >= begin) count = (end - begin) / 4;
    for (uint32_t i = 0; i < count && i < 32; ++i) {
      uint32_t entry = Load32(base, begin + i * 4);
      ids += fmt::format("{}{}", i ? "," : "", entry ? Load32(base, entry) : 0xFFFFFFFFu);
    }
  }
  __imp__sub_825926B0(ctx, base);
  if (log)
    REXLOG_INFO("QUICK_DIAG chapter lookup id={} catalog={:08X} count={} ids=[{}] result={}",
                chapter, catalog, count, ids, ctx.r3.s32);
}

extern "C" REX_FUNC(sub_82441710) {
  static std::atomic<uint32_t> logged{0};
  if (ShouldLog(logged))
    REXLOG_INFO("QUICK_DIAG join candidate r3={:08X} r4={:08X}", ctx.r3.u32, ctx.r4.u32);
  __imp__sub_82441710(ctx, base);
}

extern "C" REX_FUNC(sub_824108E8) {
  static std::atomic<uint32_t> logged{0};
  if (ShouldLog(logged))
    REXLOG_INFO("QUICK_DIAG error self={:08X} message={:08X} kind={} lr={:08X}", ctx.r3.u32,
                ctx.r4.u32, ctx.r5.u32, static_cast<uint32_t>(ctx.lr));
  __imp__sub_824108E8(ctx, base);
}
