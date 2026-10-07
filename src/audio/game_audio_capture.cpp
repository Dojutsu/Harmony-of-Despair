#include <rex/audio/game_audio_capture.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <limits>
#include <stdexcept>
#if defined(__linux__)
#include <cerrno>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

namespace rex::audio {
Pcm16CaptureBuffer::Pcm16CaptureBuffer(uint32_t seconds, uint32_t delay_seconds) {
  if (!seconds || seconds > kMaximumSeconds || delay_seconds > kMaximumDelaySeconds)
    throw std::invalid_argument("Game PCM capture duration or delay is out of bounds");
  pcm_.resize(size_t(seconds) * kSampleRate * 4);
  delay_frames_ = size_t(delay_seconds) * kSampleRate;
}

bool Pcm16CaptureBuffer::Append(std::span<const float> samples) noexcept {
  if (samples.size() > kMaximumFrameSamples || (samples.size() & 1) || complete()) return false;
  size_t first = 0;
  if (delay_frames_) {
    const auto skipped = std::min(delay_frames_, samples.size() / 2);
    delay_frames_ -= skipped;
    first = skipped * 2;
  }
  const size_t count = std::min(samples.size() - first, (pcm_.size() - written_) / 2);
  for (size_t i = 0; i < count; ++i) {
    float value = samples[first + i];
    if (!std::isfinite(value)) value = 0;
    value = std::clamp(value, -1.0f, 1.0f);
    // Deterministic round-to-nearest, independent of the host rounding mode.
    const auto quantized = static_cast<int32_t>(value >= 0 ? value * 32767.0f + 0.5f
                                                         : value * 32768.0f - 0.5f);
    const auto bits = static_cast<uint16_t>(quantized);
    pcm_[written_++] = static_cast<uint8_t>(bits);
    pcm_[written_++] = static_cast<uint8_t>(bits >> 8);
  }
  return true;
}

std::optional<std::array<uint8_t, 44>> Pcm16CaptureBuffer::WavHeader(size_t bytes) noexcept {
  if (bytes > kMaximumBytes || (bytes & 3) || bytes > std::numeric_limits<uint32_t>::max() - 36)
    return std::nullopt;
  std::array<uint8_t, 44> header{};
  const auto put = [&](size_t offset, uint32_t value, size_t count) {
    for (size_t i = 0; i < count; ++i) header[offset + i] = static_cast<uint8_t>(value >> (i * 8));
  };
  std::copy_n("RIFF", 4, header.begin());
  put(4, static_cast<uint32_t>(bytes) + 36, 4);
  std::copy_n("WAVEfmt ", 8, header.begin() + 8);
  put(16, 16, 4);
  put(20, 1, 2);  // PCM, not device-dependent float or compressed output.
  put(22, kChannels, 2);
  put(24, kSampleRate, 4);
  put(28, kSampleRate * kChannels * 2, 4);
  put(32, kChannels * 2, 2);
  put(34, 16, 2);
  std::copy_n("data", 4, header.begin() + 36);
  put(40, static_cast<uint32_t>(bytes), 4);
  return header;
}

#if defined(__linux__)
namespace {
int OpenPrivateNewFile(const std::filesystem::path& path, std::string_view& error) {
  if (path.native().find('\0') != std::filesystem::path::string_type::npos) {
    error = "Game PCM capture rejects embedded NUL path bytes";
    return -1;
  }
  if (!path.is_absolute() || path.filename().empty()) {
    error = "Game PCM capture requires a fresh absolute file path";
    return -1;
  }
  for (const auto& component : path) {
    if (component == "." || component == "..") {
      error = "Game PCM capture rejects relative path components";
      return -1;
    }
  }
  int directory = open("/", O_RDONLY | O_DIRECTORY | O_CLOEXEC);
  if (directory < 0) {
    error = "Game PCM capture cannot open its parent directory";
    return -1;
  }
  for (const auto& component : path.parent_path().relative_path()) {
    const int next = openat(directory, component.c_str(), O_RDONLY | O_DIRECTORY | O_NOFOLLOW | O_CLOEXEC);
    close(directory);
    directory = next;
    if (directory < 0) {
      error = "Game PCM capture parent must exist without symlink components";
      return -1;
    }
  }
  struct stat parent{};
  if (fstat(directory, &parent) || parent.st_uid != getuid() || (parent.st_mode & 077)) {
    close(directory);
    error = "Game PCM capture parent must be an owned private directory (0700)";
    return -1;
  }
  const int fd = openat(directory, path.filename().c_str(),
                        O_WRONLY | O_CREAT | O_EXCL | O_NOFOLLOW | O_CLOEXEC, 0600);
  close(directory);
  if (fd < 0) {
    error = "Game PCM capture file must be new and writable";
    return -1;
  }
  if (fchmod(fd, 0600)) {
    close(fd);
    error = "Game PCM capture could not set private file permissions";
    return -1;
  }
  return fd;
}

bool WriteAll(int fd, std::span<const uint8_t> bytes) noexcept {
  while (!bytes.empty()) {
    const ssize_t result = write(fd, bytes.data(), bytes.size());
    if (result < 0 && errno == EINTR) continue;
    if (result <= 0) return false;
    bytes = bytes.subspan(static_cast<size_t>(result));
  }
  return true;
}
}  // namespace

std::unique_ptr<GameAudioCapture> GameAudioCapture::Open(const std::filesystem::path& path,
    uint32_t seconds, uint32_t delay_seconds, std::string_view* error_out) noexcept {
  std::string_view error;
  int fd = -1;
  try {
    if (!seconds || seconds > Pcm16CaptureBuffer::kMaximumSeconds ||
        delay_seconds > Pcm16CaptureBuffer::kMaximumDelaySeconds) {
      error = "Game PCM capture duration or delay is out of bounds";
    } else {
      fd = OpenPrivateNewFile(path, error);
      if (fd >= 0) {
        auto capture = std::unique_ptr<GameAudioCapture>(new GameAudioCapture(fd, seconds, delay_seconds));
        if (error_out) *error_out = {};
        return capture;
      }
    }
  } catch (...) {
    if (fd >= 0) close(fd);
    error = "Game PCM capture initialization failed";
  }
  if (error_out) *error_out = error;
  return nullptr;
}

GameAudioCapture::GameAudioCapture(int fd, uint32_t seconds, uint32_t delay_seconds)
    : fd_(fd), buffer_(seconds, delay_seconds) {
  writer_ = std::jthread([this] { WriteCapture(); });
}
GameAudioCapture::~GameAudioCapture() { Close(); }

void GameAudioCapture::Append(std::span<const float> samples) noexcept {
  if (!accepting() || producer_busy_.test_and_set(std::memory_order_acquire)) return;
  bool complete = false;
  if (accepting()) {
    buffer_.Append(samples);
    complete = buffer_.complete();
  }
  if (complete) {
    accepting_.store(false, std::memory_order_release);
    ready_.store(true, std::memory_order_release);
  }
  producer_busy_.clear(std::memory_order_release);
}

void GameAudioCapture::Close() noexcept {
  if (closing_.exchange(true, std::memory_order_acq_rel)) {
    while (!closed_.load(std::memory_order_acquire)) std::this_thread::yield();
    return;
  }
  accepting_.store(false, std::memory_order_release);
  // Close runs on driver destruction, never the SDL callback. An in-flight
  // producer is bounded to 512 samples; the producer itself never waits.
  while (producer_busy_.test(std::memory_order_acquire)) std::this_thread::yield();
  ready_.store(true, std::memory_order_release);
  if (writer_.joinable()) writer_.join();
  closed_.store(true, std::memory_order_release);
}

void GameAudioCapture::WriteCapture() noexcept {
  using namespace std::chrono_literals;
  // No condition-variable signal from the audio producer, no writer access to
  // mutable PCM. Closing early publishes the partial buffer with release/acquire.
  while (!ready_.load(std::memory_order_acquire)) std::this_thread::sleep_for(25ms);
  const auto pcm = buffer_.pcm();
  const auto header = Pcm16CaptureBuffer::WavHeader(pcm.size());
  bool success = header && WriteAll(fd_, *header) && WriteAll(fd_, pcm);
  if (close(fd_)) success = false;
  fd_ = -1;
  succeeded_.store(success, std::memory_order_release);
}
#endif
}  // namespace rex::audio
