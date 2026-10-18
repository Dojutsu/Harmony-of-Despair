// Chapter unlock rules over a small fake guest image.
#include "chapter_unlock_hooks.h"

#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

namespace {
using namespace harmony::chapters;

unsigned checks = 0;
unsigned failures = 0;
void Check(bool condition, const char* name) {
  ++checks;
  if (!condition) { ++failures; std::cerr << "FAIL " << name << '\n'; }
}

struct FakeMemory {
  std::map<uint32_t, uint8_t> bytes;
  uint8_t Load8(uint32_t a) const { auto it = bytes.find(a); return it == bytes.end() ? 0 : it->second; }
  uint32_t Load32(uint32_t a) const {
    return (uint32_t{Load8(a)} << 24) | (uint32_t{Load8(a + 1)} << 16) |
           (uint32_t{Load8(a + 2)} << 8) | Load8(a + 3);
  }
  void Store8(uint32_t a, uint8_t v) { bytes[a] = v; }
  void Store32(uint32_t a, uint32_t v) {
    for (int i = 0; i < 4; ++i) bytes[a + i] = uint8_t(v >> (24 - 8 * i));
  }
};

constexpr uint32_t kManager = 0x40000000;
constexpr uint32_t kList = 0x40001000;
constexpr uint32_t kStages = 0x40002000;
constexpr uint32_t kSave = 0x40010000;
constexpr uint32_t kFlags = 0x40020000;
constexpr uint32_t kPairs = 0x40030000;

FakeMemory Image(const std::vector<uint32_t>& chapters) {
  FakeMemory mem;
  mem.Store32(kChapterManagerPointer, kManager);
  mem.Store32(kManager + kChapterListBegin, kList);
  mem.Store32(kManager + kChapterListEnd, kList + 4 * uint32_t(chapters.size()));
  for (size_t i = 0; i < chapters.size(); ++i) {
    mem.Store32(kList + 4 * uint32_t(i), kStages + 0x100 * uint32_t(i));
    mem.Store32(kStages + 0x100 * uint32_t(i), chapters[i]);
  }
  for (uint32_t c = 1; c <= kChapterSlots; ++c) mem.Store32(kFlags + 4 * (c - 1), kPairs + 2 * (c - 1));
  return mem;
}

void Clear(FakeMemory& mem, uint32_t chapter, bool hard) {
  mem.Store8(kSave + kClearFlagsOffset + 2 * (chapter - 1) + (hard ? 1 : 0), 1);
}
}  // namespace

int main() {
  const std::vector<uint32_t> all = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  {  // Fresh save: every DLC chapter is closed.
    auto mem = Image(all);
    for (uint32_t c = 7; c <= 11; ++c) Check(!DlcChapterUnlocked(mem, kSave, c, false), "fresh closed");
  }
  {  // Beating 6 opens 7 only; beating 7 opens 8.
    auto mem = Image(all);
    Clear(mem, 6, false);
    Check(DlcChapterUnlocked(mem, kSave, 7, false), "6 opens 7");
    Check(!DlcChapterUnlocked(mem, kSave, 8, false), "6 keeps 8 closed");
    Check(!DlcChapterUnlocked(mem, kSave, 7, true), "normal clear keeps hard 7 closed");
    Clear(mem, 7, false);
    Check(DlcChapterUnlocked(mem, kSave, 8, false), "7 opens 8");
    Check(!DlcChapterUnlocked(mem, kSave, 9, false), "7 keeps 9 closed");
  }
  {  // Hard follows hard clears.
    auto mem = Image(all);
    Clear(mem, 6, true);
    Check(DlcChapterUnlocked(mem, kSave, 7, true), "hard 6 opens hard 7");
    Check(!DlcChapterUnlocked(mem, kSave, 7, false), "hard 6 alone keeps normal 7 closed");
  }
  {  // A chapter already beaten stays open even out of order.
    auto mem = Image(all);
    Clear(mem, 10, false);
    Check(DlcChapterUnlocked(mem, kSave, 10, false), "beaten 10 stays open");
    Check(DlcChapterUnlocked(mem, kSave, 11, false), "beaten 10 opens 11");
    Check(!DlcChapterUnlocked(mem, kSave, 9, false), "9 still closed");
  }
  {  // Missing DLC is skipped: 7 and 9 installed, 8 not.
    auto mem = Image({1, 2, 3, 4, 5, 6, 7, 9});
    Clear(mem, 7, false);
    Check(DlcChapterUnlocked(mem, kSave, 9, false), "9 follows 7 when 8 is missing");
  }
  {  // Packed mask: only DLC bits change.
    auto mem = Image(all);
    Clear(mem, 6, false);
    uint64_t original = 0xFFFFFFFFFFFFFFFFull;
    uint64_t mask = ApplyDlcUnlocks(mem, kSave, original);
    Check((mask & 0x3F) == 0x3F, "built-in normal bits kept");
    Check(((mask >> 32) & 0x3F) == 0x3F, "built-in hard bits kept");
    Check((mask >> 6) & 1, "7 normal set");
    Check(!((mask >> 7) & 1), "8 normal cleared");
    Check(!((mask >> 38) & 1), "7 hard cleared");
    Check((mask >> 11) & 1, "uninstalled 12 untouched");
  }
  {  // Lobby flags follow the same rule.
    auto mem = Image(all);
    for (uint32_t c = 7; c <= 11; ++c) { mem.Store8(kPairs + 2 * (c - 1), 1); mem.Store8(kPairs + 2 * (c - 1) + 1, 1); }
    Clear(mem, 6, false);
    ApplyDlcUnlocksToTeamFlags(mem, kSave, kFlags);
    Check(mem.Load8(kPairs + 2 * 6) == 1, "flags 7 open");
    Check(mem.Load8(kPairs + 2 * 6 + 1) == 0, "flags 7 hard closed");
    Check(mem.Load8(kPairs + 2 * 7) == 0, "flags 8 closed");
  }

  std::cout << checks - failures << '/' << checks << " checks passed\n";
  return failures ? 1 : 0;
}
