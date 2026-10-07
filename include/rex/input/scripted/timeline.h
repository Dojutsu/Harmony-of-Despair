#pragma once

#include <array>
#include <charconv>
#include <cstdint>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace rex::input::scripted {

// Offline test input only: timestamp milliseconds, buttons, LT, RT, LX, LY, RX, RY.
// State remains active until the next row. Scripts must explicitly release buttons.
struct Frame {
  uint32_t milliseconds = 0;
  uint16_t buttons = 0;
  uint8_t left_trigger = 0, right_trigger = 0;
  int16_t left_x = 0, left_y = 0, right_x = 0, right_y = 0;
  bool operator==(const Frame&) const = default;
  bool IsNeutral() const {
    return !buttons && !left_trigger && !right_trigger && !left_x && !left_y && !right_x && !right_y;
  }
};

class Timeline {
 public:
  static constexpr size_t kMaximumBytes = 256 * 1024;
  static constexpr size_t kMaximumFrames = 4096;
  static constexpr uint32_t kMaximumMilliseconds = 3600000;

  bool Parse(std::string_view text, std::string& error) {
    std::vector<Frame> candidate;
    if (text.size() > kMaximumBytes) {
      error = "input script exceeds 256 KiB";
      return false;
    }
    std::istringstream stream{std::string(text)};
    std::string line;
    size_t line_number = 0;
    while (std::getline(stream, line)) {
      ++line_number;
      const auto comment = line.find('#');
      if (comment != std::string::npos) line.resize(comment);
      std::istringstream row(line);
      std::array<int64_t, 8> values{};
      std::string token;
      if (!(row >> token)) continue;
      bool valid = true;
      for (size_t i = 0; i < values.size(); ++i) {
        if (i && !(row >> token)) { valid = false; break; }
        auto result = std::from_chars(token.data(), token.data() + token.size(), values[i]);
        if (result.ec != std::errc{} || result.ptr != token.data() + token.size()) {
          valid = false;
          break;
        }
      }
      if (row >> token) valid = false;
      valid = valid && values[0] >= 0 && values[0] <= kMaximumMilliseconds &&
              values[1] >= 0 && values[1] <= UINT16_MAX &&
              values[2] >= 0 && values[2] <= UINT8_MAX &&
              values[3] >= 0 && values[3] <= UINT8_MAX;
      for (size_t i = 4; i < 8; ++i)
        valid = valid && values[i] >= INT16_MIN && values[i] <= INT16_MAX;
      if (!candidate.empty()) valid = valid && values[0] > candidate.back().milliseconds;
      if (!valid || candidate.size() == kMaximumFrames) {
        error = "invalid input script row " + std::to_string(line_number);
        return false;
      }
      candidate.push_back({static_cast<uint32_t>(values[0]), static_cast<uint16_t>(values[1]),
                           static_cast<uint8_t>(values[2]), static_cast<uint8_t>(values[3]),
                           static_cast<int16_t>(values[4]), static_cast<int16_t>(values[5]),
                           static_cast<int16_t>(values[6]), static_cast<int16_t>(values[7])});
    }
    if (candidate.empty()) { error = "input script contains no frames"; return false; }
    frames_ = std::move(candidate);
    error.clear();
    return true;
  }

  // Validate the complete new schedule before publishing it. Appending never
  // renumbers an accepted packet or changes already accepted future frames.
  bool Extend(std::string_view text, uint64_t elapsed_ms, std::string& error) {
    Timeline candidate;
    if (!candidate.Parse(text, error)) return false;
    if (candidate.frames_.size() < frames_.size()) {
      error = "input script accepted rows were removed"; return false;
    }
    for (size_t i = 0; i < frames_.size(); ++i) {
      if (candidate.frames_[i] != frames_[i]) {
        error = "input script accepted rows were changed"; return false;
      }
    }
    if (candidate.frames_.size() > frames_.size() &&
        candidate.frames_[frames_.size()].milliseconds <= elapsed_ms) {
      error = "input script appended row is not in the future"; return false;
    }
    if (candidate.frames_.size() > frames_.size()) {
      const auto& release = candidate.frames_.back();
      if (!release.IsNeutral()) {
        error = "input script extension needs a final fully neutral release"; return false;
      }
    }
    frames_ = std::move(candidate.frames_);
    error.clear(); return true;
  }
  size_t frame_count() const { return frames_.size(); }
  bool ends_neutral() const { return !frames_.empty() && frames_.back().IsNeutral(); }

  Frame Sample(uint64_t elapsed_ms, uint32_t* packet = nullptr) const {
    Frame state;
    uint32_t selected = 0;
    for (size_t i = 0; i < frames_.size(); ++i) {
      if (frames_[i].milliseconds > elapsed_ms) break;
      state = frames_[i];
      selected = static_cast<uint32_t>(i + 1);
    }
    if (packet) *packet = selected;
    return state;
  }

 private:
  std::vector<Frame> frames_;
};

}  // namespace rex::input::scripted
