// Chain the DLC chapters after Chapter 6 (see chapter_unlock_hooks.h).
//
// Each hook replaces the generated weak symbol of a title function, runs the
// original body through its __imp__ entry where the original behavior is kept,
// and only changes the answers for installed chapters above 6.
//   sub_82225238  is-chapter-unlocked(save, chapter, hard, team_flags)
//   sub_822252D0  packed unlock mask advertised to the team
//   sub_8240A058  single-player chapter select setup (fills lobby flags)
//   sub_8240B550  online lobby setup (fills lobby flags)
// The lobby flag array keeps its original meaning for DLC chapters ("open"),
// so the title's own team checks continue to read it unchanged.

#include "chapter_unlock_hooks.h"

#include <rex/ppc/context.h>
#include <rex/ppc/func.h>
#include <rex/logging.h>

namespace {

struct GuestMemory {
  uint8_t* base;
  uint32_t Load32(uint32_t address) const {
    return __builtin_bswap32(*reinterpret_cast<volatile uint32_t*>(base + address));
  }
  uint8_t Load8(uint32_t address) const {
    return *reinterpret_cast<volatile uint8_t*>(base + address);
  }
  void Store8(uint32_t address, uint8_t value) {
    *reinterpret_cast<volatile uint8_t*>(base + address) = value;
  }
};

void LogOnce(const char* what) {
  static bool logged = false;
  if (!logged) {
    logged = true;
    REXLOG_INFO("Harmony chapter unlock: DLC chapters follow Chapter 6 ({})", what);
  }
}

void RefreshTeamFlags(uint8_t* base) {
  using namespace harmony::chapters;
  GuestMemory mem{base};
  uint32_t flags = mem.Load32(kGameStateAddress + kTeamFlagsPointerOffset);
  if (!flags) return;
  ApplyDlcUnlocksToTeamFlags(mem, kGameStateAddress + kSaveBlockOffset,
                             flags + kTeamFlagArrayOffset);
  LogOnce("lobby");
}

}  // namespace

REX_EXTERN(__imp__sub_82225238);
REX_EXTERN(__imp__sub_822252D0);
REX_EXTERN(__imp__sub_8240A058);
REX_EXTERN(__imp__sub_8240B550);

extern "C" REX_FUNC(sub_82225238) {
  using namespace harmony::chapters;
  uint32_t chapter = ctx.r4.u32;
  // With a team flag array the title reads the per-chapter "open" flag, which
  // the lobby hooks below already filled with the chained rule.
  if (chapter > kLastBuiltInChapter && chapter <= kChapterSlots && ctx.r6.u32 == 0) {
    GuestMemory mem{base};
    ctx.r3.u64 = DlcChapterUnlocked(mem, ctx.r3.u32, chapter, (ctx.r5.u32 & 0xFF) != 0) ? 1 : 0;
    LogOnce("chapter check");
    return;
  }
  __imp__sub_82225238(ctx, base);
}

extern "C" REX_FUNC(sub_822252D0) {
  using namespace harmony::chapters;
  uint32_t save = ctx.r3.u32;
  __imp__sub_822252D0(ctx, base);
  GuestMemory mem{base};
  ctx.r3.u64 = ApplyDlcUnlocks(mem, save, ctx.r3.u64);
}

extern "C" REX_FUNC(sub_8240A058) {
  __imp__sub_8240A058(ctx, base);
  uint64_t result = ctx.r3.u64;
  RefreshTeamFlags(base);
  ctx.r3.u64 = result;
}

extern "C" REX_FUNC(sub_8240B550) {
  __imp__sub_8240B550(ctx, base);
  uint64_t result = ctx.r3.u64;
  RefreshTeamFlags(base);
  ctx.r3.u64 = result;
}
