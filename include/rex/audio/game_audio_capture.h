#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <memory>
#include <optional>
#include <span>
#include <string_view>
#include <thread>
#include <vector>

namespace rex::audio {

// Game-submitted stereo PCM only. No audio-device input or desktop monitoring.
// Allocate once at setup; Append performs bounded conversion with no allocation.
class Pcm16CaptureBuffer final {
 public:
  static constexpr uint32_t kSampleRate = 48000;
  static constexpr uint32_t kChannels = 2;
  static constexpr uint32_t kMaximumSeconds = 30;
  static constexpr uint32_t kMaximumDelaySeconds = 600;
  static constexpr size_t kMaximumFrameSamples = 512;
  static constexpr size_t kMaximumBytes = size_t(kMaximumSeconds) * kSampleRate * 4;

  Pcm16CaptureBuffer(uint32_t seconds, uint32_t delay_seconds = 0);
  bool Append(std::span<const float> interleaved_stereo) noexcept;
  bool complete() const noexcept { return written_ == pcm_.size(); }
  size_t frames() const noexcept { return written_ / 4; }
  std::span<const uint8_t> pcm() const noexcept { return {pcm_.data(), written_}; }
  static std::optional<std::array<uint8_t, 44>> WavHeader(size_t bytes) noexcept;

 private:
  std::vector<uint8_t> pcm_;
  size_t written_ = 0;
  size_t delay_frames_ = 0;
};

#if defined(__linux__)
// One exclusive 0600 WAV in an existing private, owned directory. Append uses
// a nonblocking producer guard and never touches disk or wakes the writer.
// The writer runs only once the bounded buffer is full or Close stops capture.
class GameAudioCapture final {
 public:
  static std::unique_ptr<GameAudioCapture> Open(const std::filesystem::path& path,
      uint32_t seconds, uint32_t delay_seconds, std::string_view* error = nullptr) noexcept;
  ~GameAudioCapture();
  void Append(std::span<const float> interleaved_stereo) noexcept;
  void Close() noexcept;
  bool accepting() const noexcept { return accepting_.load(std::memory_order_acquire); }
  // Query only after Close; the buffer is then immutable.
  size_t frames() const noexcept { return buffer_.frames(); }
  bool succeeded() const noexcept { return succeeded_.load(std::memory_order_acquire); }

 private:
  GameAudioCapture(int fd, uint32_t seconds, uint32_t delay_seconds);
  void WriteCapture() noexcept;
  int fd_;
  Pcm16CaptureBuffer buffer_;
  std::atomic_flag producer_busy_ = ATOMIC_FLAG_INIT;
  std::atomic<bool> accepting_{true};
  std::atomic<bool> ready_{false};
  std::atomic<bool> closing_{false};
  std::atomic<bool> closed_{false};
  std::atomic<bool> succeeded_{false};
  std::jthread writer_;
};
#endif

}  // namespace rex::audio
