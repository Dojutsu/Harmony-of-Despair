#include <rex/audio/game_audio_capture.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <vector>
#include <catch2/catch_test_macros.hpp>
#if defined(__linux__)
#include <sys/stat.h>
#include <unistd.h>
#endif

using rex::audio::Pcm16CaptureBuffer;
namespace {
uint32_t LE(std::span<const uint8_t> data, size_t offset, size_t count) {
  uint32_t value = 0;
  for (size_t i = 0; i < count; ++i) value |= uint32_t(data[offset + i]) << (8 * i);
  return value;
}
}

TEST_CASE("Game PCM capture validates duration and bounded delay before allocation", "[audio][capture]") {
  CHECK_THROWS_AS(Pcm16CaptureBuffer(0), std::invalid_argument);
  CHECK_THROWS_AS(Pcm16CaptureBuffer(31), std::invalid_argument);
  CHECK_THROWS_AS(Pcm16CaptureBuffer(UINT32_MAX), std::invalid_argument);
  CHECK_THROWS_AS(Pcm16CaptureBuffer(1, 601), std::invalid_argument);
  CHECK_THROWS_AS(Pcm16CaptureBuffer(1, UINT32_MAX), std::invalid_argument);
  CHECK_NOTHROW(Pcm16CaptureBuffer(30, 600));
}

TEST_CASE("Game PCM WAV header is explicit little endian PCM16 stereo", "[audio][capture]") {
  auto header = Pcm16CaptureBuffer::WavHeader(192000);
  REQUIRE(header);
  CHECK(std::memcmp(header->data(), "RIFF", 4) == 0);
  CHECK(std::memcmp(header->data() + 8, "WAVEfmt ", 8) == 0);
  CHECK(std::memcmp(header->data() + 36, "data", 4) == 0);
  CHECK(LE(*header, 4, 4) == 192036);
  CHECK(LE(*header, 16, 4) == 16);
  CHECK(LE(*header, 20, 2) == 1);
  CHECK(LE(*header, 22, 2) == 2);
  CHECK(LE(*header, 24, 4) == 48000);
  CHECK(LE(*header, 28, 4) == 192000);
  CHECK(LE(*header, 32, 2) == 4);
  CHECK(LE(*header, 34, 2) == 16);
  CHECK(LE(*header, 40, 4) == 192000);
  CHECK(Pcm16CaptureBuffer::WavHeader(0));
  CHECK(Pcm16CaptureBuffer::WavHeader(Pcm16CaptureBuffer::kMaximumBytes));
  CHECK_FALSE(Pcm16CaptureBuffer::WavHeader(1));
  CHECK_FALSE(Pcm16CaptureBuffer::WavHeader(2));
  CHECK_FALSE(Pcm16CaptureBuffer::WavHeader(Pcm16CaptureBuffer::kMaximumBytes + 4));
  CHECK_FALSE(Pcm16CaptureBuffer::WavHeader(UINT32_MAX));
  CHECK_FALSE(Pcm16CaptureBuffer::WavHeader(SIZE_MAX));
}

TEST_CASE("Game PCM quantization clamps finite samples and silences nonfinite input", "[audio][capture]") {
  Pcm16CaptureBuffer buffer(1);
  const std::array<float, 10> samples{-1, 1, 0.5f, -0.5f, -2, 2,
      std::numeric_limits<float>::quiet_NaN(), std::numeric_limits<float>::infinity(),
      -std::numeric_limits<float>::infinity(), 0};
  REQUIRE(buffer.Append(samples));
  const std::array<uint8_t, 20> expected{0x00,0x80,0xFF,0x7F,0x00,0x40,0x00,0xC0,
      0x00,0x80,0xFF,0x7F,0,0,0,0,0,0,0,0};
  CHECK(std::equal(buffer.pcm().begin(), buffer.pcm().end(), expected.begin(), expected.end()));
  CHECK(buffer.frames() == 5);
  CHECK_FALSE(buffer.complete());
  CHECK_FALSE(buffer.Append(std::span(samples).first(1)));
  CHECK(buffer.frames() == 5);
  std::array<float, 514> too_large{};
  CHECK_FALSE(buffer.Append(too_large));
  CHECK(buffer.frames() == 5);
}

TEST_CASE("Game PCM captures exact bounded duration and truncates the last block", "[audio][capture]") {
  Pcm16CaptureBuffer buffer(1);
  std::array<float, 512> samples;
  samples.fill(1);
  for (size_t i = 0; i < 188; ++i) REQUIRE(buffer.Append(samples));
  CHECK(buffer.complete());
  CHECK(buffer.frames() == 48000);
  CHECK(buffer.pcm().size() == 192000);
  CHECK_FALSE(buffer.Append(samples));
  CHECK(buffer.pcm().size() == 192000);
  CHECK(LE(buffer.pcm(), buffer.pcm().size() - 4, 4) == 0x7FFF7FFF);
}

TEST_CASE("Game PCM delay is measured in submitted frames including split blocks", "[audio][capture]") {
  Pcm16CaptureBuffer buffer(1, 1);
  std::array<float, 512> samples;
  samples.fill(0.5f);
  for (size_t i = 0; i < 187; ++i) REQUIRE(buffer.Append(samples));
  CHECK(buffer.frames() == 0);
  REQUIRE(buffer.Append(samples));
  CHECK(buffer.frames() == 128);
  CHECK(buffer.pcm().size() == 512);
  CHECK(LE(buffer.pcm(), 0, 4) == 0x40004000);
}

#if defined(__linux__)
using rex::audio::GameAudioCapture;
namespace {
struct PrivateDirectory {
  PrivateDirectory() {
    std::array<char, 64> path{};
    std::strcpy(path.data(), "/tmp/rex-game-audio-XXXXXX");
    const char* created = mkdtemp(path.data());
    if (!created) throw std::runtime_error("mkdtemp failed");
    root = created;
  }
  ~PrivateDirectory() { std::error_code error; std::filesystem::remove_all(root, error); }
  std::filesystem::path root;
};
std::vector<uint8_t> ReadBytes(const std::filesystem::path& path) {
  std::ifstream input(path, std::ios::binary);
  return std::vector<uint8_t>(std::istreambuf_iterator<char>(input), {});
}
}

TEST_CASE("Game PCM capture writes private fresh WAV and preserves existing files", "[audio][capture]") {
  PrivateDirectory directory;
  const auto path = directory.root / "game.wav";
  std::string_view error;
  auto capture = GameAudioCapture::Open(path, 1, 0, &error);
  REQUIRE(capture);
  CHECK(error.empty());
  struct stat info{};
  REQUIRE(stat(path.c_str(), &info) == 0);
  CHECK((info.st_mode & 0777) == 0600);
  CHECK(info.st_uid == getuid());
  std::array<float, 4> samples{1, -1, 0.5f, 0};
  capture->Append(samples);
  capture->Close();
  CHECK_FALSE(capture->accepting());
  CHECK(capture->succeeded());
  CHECK(capture->frames() == 2);
  capture->Append(samples);
  capture->Close();
  const auto bytes = ReadBytes(path);
  REQUIRE(bytes.size() == 52);
  CHECK(LE(bytes, 4, 4) == 44);
  CHECK(LE(bytes, 40, 4) == 8);
  CHECK(LE(bytes, 44, 4) == 0x80007FFF);
  CHECK_FALSE(GameAudioCapture::Open(path, 1, 0, &error));
  CHECK_FALSE(error.empty());
  CHECK(ReadBytes(path) == bytes);
}

TEST_CASE("Game PCM capture rejects symlinks, shared parents and invalid configuration", "[audio][capture]") {
  PrivateDirectory directory;
  const auto safe = directory.root / "safe";
  std::filesystem::create_directory(safe);
  chmod(safe.c_str(), 0700);
  std::filesystem::create_directory_symlink(safe, directory.root / "alias");
  CHECK_FALSE(GameAudioCapture::Open(directory.root / "alias/game.wav", 1, 0));
  CHECK_FALSE(std::filesystem::exists(safe / "game.wav"));
  // The filesystem C APIs otherwise truncate these names at the NUL.
  std::string nul_filename = "nul.wav";
  nul_filename.push_back('\0');
  nul_filename += "ignored";
  CHECK_FALSE(GameAudioCapture::Open(directory.root / nul_filename, 1, 0));
  CHECK_FALSE(std::filesystem::exists(directory.root / "nul.wav"));
  std::string nul_parent = "safe";
  nul_parent.push_back('\0');
  nul_parent += "ignored";
  CHECK_FALSE(GameAudioCapture::Open(directory.root / nul_parent / "game.wav", 1, 0));
  CHECK_FALSE(std::filesystem::exists(safe / "game.wav"));
  CHECK_FALSE(GameAudioCapture::Open("relative.wav", 1, 0));
  CHECK_FALSE(GameAudioCapture::Open(directory.root / "../game.wav", 1, 0));
  CHECK_FALSE(GameAudioCapture::Open(directory.root / "bad.wav", 0, 0));
  CHECK_FALSE(GameAudioCapture::Open(directory.root / "bad.wav", UINT32_MAX, 0));
  CHECK_FALSE(GameAudioCapture::Open(directory.root / "bad.wav", 1, UINT32_MAX));
  CHECK_FALSE(std::filesystem::exists(directory.root / "bad.wav"));
  chmod(safe.c_str(), 0750);
  CHECK_FALSE(GameAudioCapture::Open(safe / "game.wav", 1, 0));
  chmod(safe.c_str(), 0700);
  { std::ofstream output(safe / "original"); output << "unchanged"; }
  std::filesystem::create_symlink(safe / "original", safe / "link.wav");
  CHECK_FALSE(GameAudioCapture::Open(safe / "link.wav", 1, 0));
  CHECK(ReadBytes(safe / "original") == std::vector<uint8_t>{'u','n','c','h','a','n','g','e','d'});
}

TEST_CASE("Game PCM worker finishes a full buffer without a shutdown trigger", "[audio][capture]") {
  PrivateDirectory directory;
  auto capture = GameAudioCapture::Open(directory.root / "full.wav", 1, 0);
  REQUIRE(capture);
  std::array<float, 512> samples;
  samples.fill(0.25f);
  for (size_t i = 0; i < 188; ++i) capture->Append(samples);
  CHECK_FALSE(capture->accepting());
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(2);
  while (!capture->succeeded() && std::chrono::steady_clock::now() < deadline)
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  CHECK(capture->succeeded());
  capture->Close();
  const auto bytes = ReadBytes(directory.root / "full.wav");
  REQUIRE(bytes.size() == 192044);
  CHECK(LE(bytes, 40, 4) == 192000);
  CHECK(LE(bytes, 44, 4) == 0x20002000);
}

TEST_CASE("Game PCM concurrent close waits for one immutable output", "[audio][capture]") {
  PrivateDirectory directory;
  const auto path = directory.root / "close.wav";
  auto capture = GameAudioCapture::Open(path, 1, 0);
  REQUIRE(capture);
  const std::array<float, 2> samples{0.5f, -0.5f};
  capture->Append(samples);
  std::jthread first([&] { capture->Close(); });
  std::jthread second([&] { capture->Close(); });
  first.join();
  second.join();
  CHECK(capture->succeeded());
  CHECK(capture->frames() == 1);
  const auto bytes = ReadBytes(path);
  REQUIRE(bytes.size() == 48);
  CHECK(LE(bytes, 44, 4) == 0xC0004000);
}

TEST_CASE("Game PCM close safely publishes an in-flight partial producer buffer", "[audio][capture]") {
  PrivateDirectory directory;
  auto capture = GameAudioCapture::Open(directory.root / "partial.wav", 1, 0);
  REQUIRE(capture);
  std::array<float, 512> samples;
  samples.fill(-0.25f);
  std::atomic<bool> started{false};
  std::jthread producer([&] {
    started.store(true, std::memory_order_release);
    while (capture->accepting()) capture->Append(samples);
  });
  while (!started.load(std::memory_order_acquire)) std::this_thread::yield();
  capture->Close();
  producer.join();
  CHECK(capture->succeeded());
  CHECK_FALSE(capture->accepting());
  const auto bytes = ReadBytes(directory.root / "partial.wav");
  REQUIRE(bytes.size() >= 44);
  CHECK(bytes.size() <= 192044);
  CHECK((bytes.size() - 44) % 4 == 0);
  CHECK(LE(bytes, 40, 4) == bytes.size() - 44);
  CHECK(LE(bytes, 4, 4) == bytes.size() - 8);
}
#endif
