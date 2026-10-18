#pragma once

#include <cstdint>

// Chapter unlock rules shared by the title hooks and their tests.
//
// The title stores two clear flags per chapter (normal, hard) in the save
// block, and treats every chapter above 6 (the DLC chapters) as always open.
// Harmony chains the DLC chapters after Chapter 6 instead: a DLC chapter opens
// once the previous installed chapter is cleared on the same difficulty. A
// chapter the save already shows as cleared stays open.
namespace harmony::chapters {

constexpr uint32_t kLastBuiltInChapter = 6;
constexpr uint32_t kChapterSlots = 32;

// Guest addresses and offsets in the TU2 image.
constexpr uint32_t kChapterManagerPointer = 0x8291D9C8;  // lis -32110 / lwz -9784
constexpr uint32_t kChapterListBegin = 204;               // vector of stage objects
constexpr uint32_t kChapterListEnd = 208;
constexpr uint32_t kGameStateAddress = 0x82933588;        // returned by sub_82223348
constexpr uint32_t kSaveBlockOffset = 4120;               // game state -> save block
constexpr uint32_t kClearFlagsOffset = 14012;             // save block -> clear flags
constexpr uint32_t kTeamFlagsPointerOffset = 19228;       // game state -> lobby flags
constexpr uint32_t kTeamFlagArrayOffset = 72;             // lobby flags -> per-chapter

template <typename Memory>
bool ChapterInstalled(const Memory& mem, uint32_t chapter) {
  uint32_t manager = mem.Load32(kChapterManagerPointer);
  if (!manager) return false;
  uint32_t begin = mem.Load32(manager + kChapterListBegin);
  uint32_t end = mem.Load32(manager + kChapterListEnd);
  if (end < begin || end - begin > 4 * 64) return false;
  for (uint32_t entry = begin; entry < end; entry += 4) {
    uint32_t stage = mem.Load32(entry);
    if (stage && mem.Load32(stage) == chapter) return true;
  }
  return false;
}

template <typename Memory>
uint32_t PreviousInstalledChapter(const Memory& mem, uint32_t chapter) {
  for (uint32_t candidate = chapter - 1; candidate > kLastBuiltInChapter; --candidate) {
    if (ChapterInstalled(mem, candidate)) return candidate;
  }
  return kLastBuiltInChapter;
}

template <typename Memory>
bool ChapterCleared(const Memory& mem, uint32_t save, uint32_t chapter, bool hard) {
  if (chapter == 0 || chapter > kChapterSlots) return false;
  return mem.Load8(save + kClearFlagsOffset + 2 * (chapter - 1) + (hard ? 1 : 0)) != 0;
}

// Only meaningful for chapter > kLastBuiltInChapter.
template <typename Memory>
bool DlcChapterUnlocked(const Memory& mem, uint32_t save, uint32_t chapter, bool hard) {
  if (ChapterCleared(mem, save, chapter, hard)) return true;
  return ChapterCleared(mem, save, PreviousInstalledChapter(mem, chapter), hard);
}

// Rewrites the DLC bits of the title's packed unlock mask: low word normal,
// high word hard, bit (chapter - 1).
template <typename Memory>
uint64_t ApplyDlcUnlocks(const Memory& mem, uint32_t save, uint64_t mask) {
  for (uint32_t chapter = kLastBuiltInChapter + 1; chapter <= kChapterSlots; ++chapter) {
    if (!ChapterInstalled(mem, chapter)) continue;
    uint64_t normal_bit = uint64_t{1} << (chapter - 1);
    uint64_t hard_bit = normal_bit << 32;
    mask &= ~(normal_bit | hard_bit);
    if (DlcChapterUnlocked(mem, save, chapter, false)) mask |= normal_bit;
    if (DlcChapterUnlocked(mem, save, chapter, true)) mask |= hard_bit;
  }
  return mask;
}

// Rewrites the DLC entries of the lobby's per-chapter flag array (one pointer
// per chapter to a {normal, hard} byte pair).
template <typename Memory>
void ApplyDlcUnlocksToTeamFlags(Memory& mem, uint32_t save, uint32_t flag_array) {
  for (uint32_t chapter = kLastBuiltInChapter + 1; chapter <= kChapterSlots; ++chapter) {
    if (!ChapterInstalled(mem, chapter)) continue;
    uint32_t pair = mem.Load32(flag_array + 4 * (chapter - 1));
    if (!pair) continue;
    mem.Store8(pair, DlcChapterUnlocked(mem, save, chapter, false) ? 1 : 0);
    mem.Store8(pair + 1, DlcChapterUnlocked(mem, save, chapter, true) ? 1 : 0);
  }
}

}  // namespace harmony::chapters
