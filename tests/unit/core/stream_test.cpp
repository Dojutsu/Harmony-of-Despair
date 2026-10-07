/**
 * Unit tests for stream utilities (BitStream, ByteStream)
 *
 * Tests bit-level and byte-level stream operations.
 */

#include <array>
#include <cstdint>
#include <cstring>
#include <limits>
#include <random>
#include <vector>

#include <catch2/catch_test_macros.hpp>

#include <rex/stream.h>

using namespace rex::stream;

// =============================================================================
// ByteStream Basic Tests
// =============================================================================

TEST_CASE("ByteStream construction and initial state", "[stream][bytestream]") {
  std::array<uint8_t, 16> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  CHECK(stream.data() == buffer.data());
  CHECK(stream.data_length() == 16);
  CHECK(stream.offset() == 0);
}

TEST_CASE("ByteStream construction with offset", "[stream][bytestream]") {
  std::array<uint8_t, 16> buffer{};
  ByteStream stream(buffer.data(), buffer.size(), 8);

  CHECK(stream.offset() == 8);
}

TEST_CASE("ByteStream Advance moves offset", "[stream][bytestream]") {
  std::array<uint8_t, 16> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  stream.Advance(4);
  CHECK(stream.offset() == 4);

  stream.Advance(8);
  CHECK(stream.offset() == 12);
}

TEST_CASE("ByteStream set_offset works", "[stream][bytestream]") {
  std::array<uint8_t, 16> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  stream.set_offset(10);
  CHECK(stream.offset() == 10);

  stream.set_offset(0);
  CHECK(stream.offset() == 0);
}

// =============================================================================
// ByteStream Read/Write Tests
// =============================================================================

TEST_CASE("ByteStream Write and Read span", "[stream][bytestream]") {
  std::array<uint8_t, 16> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  std::array<uint8_t, 4> write_data = {0x11, 0x22, 0x33, 0x44};
  stream.Write(write_data.data(), write_data.size());

  CHECK(stream.offset() == 4);
  CHECK(buffer[0] == 0x11);
  CHECK(buffer[1] == 0x22);
  CHECK(buffer[2] == 0x33);
  CHECK(buffer[3] == 0x44);

  // Read it back
  stream.set_offset(0);
  std::array<uint8_t, 4> read_data{};
  stream.Read(read_data.data(), read_data.size());

  CHECK(read_data == write_data);
  CHECK(stream.offset() == 4);
}

TEST_CASE("ByteStream Write and Read template primitives", "[stream][bytestream]") {
  std::array<uint8_t, 32> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  // Write various types
  stream.Write<uint8_t>(0x12);
  stream.Write<uint16_t>(0x3456);
  stream.Write<uint32_t>(0x789ABCDE);
  stream.Write<uint64_t>(0xFEDCBA9876543210);

  CHECK(stream.offset() == 1 + 2 + 4 + 8);

  // Read them back
  stream.set_offset(0);
  CHECK(stream.Read<uint8_t>() == 0x12);
  CHECK(stream.Read<uint16_t>() == 0x3456);
  CHECK(stream.Read<uint32_t>() == 0x789ABCDE);
  CHECK(stream.Read<uint64_t>() == 0xFEDCBA9876543210);
}

TEST_CASE("ByteStream Write and Read void* overloads", "[stream][bytestream]") {
  std::array<uint8_t, 16> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  const char* msg = "test";
  stream.Write(msg, 4);

  stream.set_offset(0);
  char read_buf[5] = {};
  stream.Read(read_buf, 4);

  CHECK(std::memcmp(read_buf, msg, 4) == 0);
}

TEST_CASE("ByteStream Write and Read std::string", "[stream][bytestream]") {
  std::array<uint8_t, 64> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  std::string original = "Hello, World!";
  stream.Write(std::string_view(original));

  stream.set_offset(0);
  std::string result = stream.Read<std::string>();

  CHECK(result == original);
}

TEST_CASE("ByteStream Write and Read std::u16string", "[stream][bytestream]") {
  std::array<uint8_t, 64> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  std::u16string original = u"Unicode\u00AE";
  stream.Write(std::u16string_view(original));

  stream.set_offset(0);
  std::u16string result = stream.Read<std::u16string>();

  CHECK(result == original);
}

TEST_CASE("ByteStream empty string round-trip", "[stream][bytestream]") {
  std::array<uint8_t, 16> buffer{};
  ByteStream stream(buffer.data(), buffer.size());

  stream.Write(std::string_view(""));

  stream.set_offset(0);
  std::string result = stream.Read<std::string>();

  CHECK(result.empty());
}

// =============================================================================
// BitStream Basic Tests
// =============================================================================

TEST_CASE("BitStream construction and initial state", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer{};
  BitStream stream(buffer.data(), buffer.size() * 8);

  CHECK(stream.buffer() == buffer.data());
  CHECK(stream.size_bits() == 128);
  CHECK(stream.offset_bits() == 0);
  CHECK(stream.BitsRemaining() == 128);
}

TEST_CASE("BitStream SetOffset works", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer{};
  BitStream stream(buffer.data(), buffer.size() * 8);

  stream.SetOffset(32);
  CHECK(stream.offset_bits() == 32);
  CHECK(stream.BitsRemaining() == 96);
}

TEST_CASE("BitStream Advance works", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer{};
  BitStream stream(buffer.data(), buffer.size() * 8);

  stream.Advance(10);
  CHECK(stream.offset_bits() == 10);

  stream.Advance(5);
  CHECK(stream.offset_bits() == 15);
}

// =============================================================================
// BitStream Peek/Read Tests
// =============================================================================

TEST_CASE("BitStream Peek reads without advancing", "[stream][bitstream]") {
  // Buffer with known pattern: 0xAB = 10101011
  std::array<uint8_t, 16> buffer = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A};
  BitStream stream(buffer.data(), buffer.size() * 8);

  uint64_t val1 = stream.Peek(8);
  CHECK(stream.offset_bits() == 0);  // No advance

  uint64_t val2 = stream.Peek(8);
  CHECK(val1 == val2);  // Same value
}

TEST_CASE("BitStream Read advances offset", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A};
  BitStream stream(buffer.data(), buffer.size() * 8);

  stream.Read(8);
  CHECK(stream.offset_bits() == 8);

  stream.Read(16);
  CHECK(stream.offset_bits() == 24);
}

TEST_CASE("BitStream Read byte-aligned values", "[stream][bitstream]") {
  // Big-endian data: reading first byte should give 0xAB
  std::array<uint8_t, 16> buffer = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A};
  BitStream stream(buffer.data(), buffer.size() * 8);

  CHECK(stream.Read(8) == 0xAB);
  CHECK(stream.Read(8) == 0xCD);
  CHECK(stream.Read(8) == 0xEF);
}

TEST_CASE("BitStream Read 16-bit aligned", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A};
  BitStream stream(buffer.data(), buffer.size() * 8);

  // Reading 16 bits from big-endian: 0xABCD
  CHECK(stream.Read(16) == 0xABCD);
  CHECK(stream.Read(16) == 0xEF12);
}

TEST_CASE("BitStream Read 32-bit aligned", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A};
  BitStream stream(buffer.data(), buffer.size() * 8);

  CHECK(stream.Read(32) == 0xABCDEF12);
}

TEST_CASE("BitStream Read non-byte-aligned", "[stream][bitstream]") {
  // 0xAB = 10101011, 0xCD = 11001101
  std::array<uint8_t, 16> buffer = {0xAB, 0xCD, 0xEF, 0x12, 0x34, 0x56, 0x78, 0x9A};
  BitStream stream(buffer.data(), buffer.size() * 8);

  // Read 4 bits: should be 1010 = 0xA
  CHECK(stream.Read(4) == 0xA);

  // Read 4 bits: should be 1011 = 0xB
  CHECK(stream.Read(4) == 0xB);

  // Read 8 bits: should be 0xCD
  CHECK(stream.Read(8) == 0xCD);
}

TEST_CASE("BitStream Read single bits", "[stream][bitstream]") {
  // 0xAB = 10101011
  std::array<uint8_t, 16> buffer = {0xAB, 0xCD, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  BitStream stream(buffer.data(), buffer.size() * 8);

  // Read bits one at a time from MSB
  CHECK(stream.Read(1) == 1);  // 1
  CHECK(stream.Read(1) == 0);  // 0
  CHECK(stream.Read(1) == 1);  // 1
  CHECK(stream.Read(1) == 0);  // 0
  CHECK(stream.Read(1) == 1);  // 1
  CHECK(stream.Read(1) == 0);  // 0
  CHECK(stream.Read(1) == 1);  // 1
  CHECK(stream.Read(1) == 1);  // 1
}

TEST_CASE("BitStream Read crossing byte boundary", "[stream][bitstream]") {
  // Read bits that span byte boundaries
  std::array<uint8_t, 16> buffer = {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  BitStream stream(buffer.data(), buffer.size() * 8);

  stream.Advance(4);  // Now at bit 4

  // Read 8 bits crossing the boundary: last 4 of 0xFF + first 4 of 0x00
  // 0xFF = 11111111, last 4 = 1111
  // 0x00 = 00000000, first 4 = 0000
  // Combined: 11110000 = 0xF0
  CHECK(stream.Read(8) == 0xF0);
}

// =============================================================================
// BitStream Write Tests
// =============================================================================

TEST_CASE("BitStream Write byte-aligned", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer{};
  BitStream stream(buffer.data(), buffer.size() * 8);

  REQUIRE(stream.Write(0xAB, 8));
  CHECK(stream.offset_bits() == 8);
  CHECK(buffer[0] == 0xAB);

  stream.SetOffset(0);
  CHECK(stream.Read(8) == 0xAB);
}

TEST_CASE("BitStream Write 16-bit value", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer{};
  BitStream stream(buffer.data(), buffer.size() * 8);

  REQUIRE(stream.Write(0x1234, 16));
  CHECK(buffer[0] == 0x12);
  CHECK(buffer[1] == 0x34);

  stream.SetOffset(0);
  CHECK(stream.Read(16) == 0x1234);
}

TEST_CASE("BitStream Write non-byte-aligned", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer{};
  BitStream stream(buffer.data(), buffer.size() * 8);

  // Write 4 bits, then 4 more
  REQUIRE(stream.Write(0xA, 4));  // 1010
  REQUIRE(stream.Write(0xB, 4));  // 1011
  CHECK(buffer[0] == 0xAB);

  stream.SetOffset(0);
  CHECK(stream.Read(8) == 0xAB);
}

TEST_CASE("BitStream Write preserves surrounding bits", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  BitStream stream(buffer.data(), buffer.size() * 8);

  stream.Advance(4);
  REQUIRE(stream.Write(0x0, 4));  // Clear middle 4 bits
  CHECK(buffer[0] == 0xF0);
  CHECK(buffer[1] == 0xFF);

  stream.SetOffset(0);
  // First 4 bits should still be 1111, next 4 should be 0000
  CHECK(stream.Read(4) == 0xF);
  CHECK(stream.Read(4) == 0x0);
}

// =============================================================================
// BitStream Edge Cases
// =============================================================================

TEST_CASE("BitStream Read zero bits returns zero", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  BitStream stream(buffer.data(), buffer.size() * 8);

  CHECK(stream.Read(0) == 0);
  CHECK(stream.offset_bits() == 0);  // No advance
}

TEST_CASE("BitStream maximum bits (57)", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  BitStream stream(buffer.data(), buffer.size() * 8);

  // 57 bits of all 1s = 0x1FFFFFFFFFFFFFF
  uint64_t expected = (1ULL << 57) - 1;
  CHECK(stream.Read(57) == expected);
}

TEST_CASE("BitStream BitsRemaining decreases", "[stream][bitstream]") {
  std::array<uint8_t, 16> buffer{};
  BitStream stream(buffer.data(), 64);  // 64 bits = 8 bytes

  CHECK(stream.BitsRemaining() == 64);

  stream.Read(16);
  CHECK(stream.BitsRemaining() == 48);

  stream.Read(32);
  CHECK(stream.BitsRemaining() == 16);
}


TEST_CASE("BitStream writes explicit endian bytes across unaligned fields",
          "[stream][bitstream]") {
  std::array<uint8_t, 5> buffer{0xF0, 0x00, 0x00, 0x00, 0x0F};
  BitStream stream(buffer.data(), 36);
  stream.SetOffset(4);
  REQUIRE(stream.Write(0x12345678, 32));
  CHECK(buffer == std::array<uint8_t, 5>{0xF1, 0x23, 0x45, 0x67, 0x8F});
  CHECK(stream.offset_bits() == 36);
  CHECK(stream.BitsRemaining() == 0);
  stream.SetOffset(4);
  CHECK(stream.Peek(32) == 0x12345678);
  CHECK(stream.offset_bits() == 4);
  CHECK(stream.Read(32) == 0x12345678);
}

TEST_CASE("BitStream exact-sized fields preserve every outside bit",
          "[stream][bitstream]") {
  constexpr std::array<uint64_t, 4> values{0, UINT64_MAX, 0x0123456789ABCDEF,
                                           0xFEDCBA9876543210};
  for (size_t offset = 0; offset < 8; ++offset) {
    for (size_t width = 0; width <= 57; ++width) {
      for (auto value : values) {
        CAPTURE(offset, width, value);
        const auto size_bits = offset + width;
        std::vector<uint8_t> buffer((size_bits + 7) / 8, 0xA5);
        auto expected = buffer;
        // Independent bit-by-bit wire oracle checks order, high-value masking,
        // surrounding-bit preservation and minimal allocation boundaries.
        for (size_t bit = 0; bit < width; ++bit) {
          const auto index = offset + bit;
          const auto mask = uint8_t(0x80 >> (index & 7));
          if ((value >> (width - bit - 1)) & 1)
            expected[index / 8] |= mask;
          else
            expected[index / 8] &= uint8_t(~mask);
        }
        BitStream stream(buffer.data(), size_bits);
        stream.SetOffset(offset);
        REQUIRE(stream.Write(value, width));
        CHECK(buffer == expected);
        CHECK(stream.offset_bits() == size_bits);
        CHECK(stream.BitsRemaining() == 0);
        stream.SetOffset(offset);
        const auto expected_value = value & ((uint64_t(1) << width) - 1);
        CHECK(stream.Peek(width) == expected_value);
        CHECK(stream.Read(width) == expected_value);
        CHECK(stream.offset_bits() == size_bits);
      }
    }
  }
}

TEST_CASE("BitStream invalid writes preserve buffer and offset",
          "[stream][bitstream]") {
  std::array<uint8_t, 3> buffer{0xA5, 0x5A, 0xC3};
  const auto original = buffer;
  BitStream stream(buffer.data(), 17);
  stream.SetOffset(9);
  for (auto width : {size_t(9), size_t(58), std::numeric_limits<size_t>::max()}) {
    CHECK_FALSE(stream.Write(UINT64_MAX, width));
    CHECK(stream.offset_bits() == 9);
    CHECK(buffer == original);
  }
  stream.SetOffset(17);
  CHECK_FALSE(stream.Write(1, 1));
  CHECK(stream.offset_bits() == 17);
  CHECK(buffer == original);
  CHECK(stream.Write(UINT64_MAX, 0));
  CHECK(stream.Peek(0) == 0);
  CHECK(stream.Read(0) == 0);
  CHECK(stream.offset_bits() == 17);
  CHECK(buffer == original);
  BitStream empty(nullptr, 0);
  CHECK(empty.Write(UINT64_MAX, 0));
  CHECK(empty.Peek(0) == 0);
  CHECK(empty.Read(0) == 0);
  CHECK_FALSE(empty.Write(1, 1));
}


TEST_CASE("BitStream short unaligned copies preserve boundary bits",
          "[stream][bitstream][copy]") {
  std::array<uint8_t, 2> source{0xAB, 0xCD};
  std::array<uint8_t, 2> dest{0xFF, 0x0F};
  BitStream stream(source.data(), 16);
  stream.SetOffset(1);
  CHECK(stream.Copy(dest.data(), 2) == 1);
  CHECK(dest == std::array<uint8_t, 2>{0xBF, 0x0F});
  CHECK(stream.offset_bits() == 3);

  dest = {0xF0, 0x0F};
  stream.SetOffset(3);
  CHECK(stream.Copy(dest.data(), 10) == 3);
  CHECK(dest == std::array<uint8_t, 2>{0xEB, 0xCF});
  CHECK(stream.offset_bits() == 13);

  // Zero bits at an unaligned position must touch no memory.
  CHECK(stream.Copy(nullptr, 0) == 5);
  CHECK(stream.offset_bits() == 13);
  CHECK(dest == std::array<uint8_t, 2>{0xEB, 0xCF});
}

TEST_CASE("BitStream bounded copies match an independent wire model",
          "[stream][bitstream][copy]") {
  std::mt19937 random(0xC057B175);
  for (size_t iteration = 0; iteration < 2048; ++iteration) {
    const size_t offset = iteration < 8 * 129 ? iteration / 129 : random() % 256;
    const size_t width = iteration < 8 * 129 ? iteration % 129 : random() % 2049;
    CAPTURE(iteration, offset, width);
    const size_t padding = offset & 7;
    const size_t size_bits = offset + width;
    // Minimal allocations make even a one-byte overread visible to ASan.
    std::vector<uint8_t> source((size_bits + 7) / 8);
    std::vector<uint8_t> dest((padding + width + 7) / 8);
    for (auto& byte : source)
      byte = static_cast<uint8_t>(random());
    for (auto& byte : dest)
      byte = static_cast<uint8_t>(random());
    const auto source_before = source;
    auto expected = dest;
    for (size_t bit = 0; bit < width; ++bit) {
      const auto source_index = offset + bit;
      const auto dest_index = padding + bit;
      const auto mask = uint8_t(0x80 >> (dest_index & 7));
      if (source[source_index / 8] & (0x80 >> (source_index & 7)))
        expected[dest_index / 8] |= mask;
      else
        expected[dest_index / 8] &= uint8_t(~mask);
    }
    BitStream stream(source.data(), size_bits);
    stream.SetOffset(offset);
    // Random requests past EOF must reject before mutating either buffer.
    const auto dest_before = dest;
    CHECK(stream.Copy(dest.data(), width + 1 + random() % 128) == padding);
    CHECK(dest == dest_before);
    CHECK(source == source_before);
    CHECK(stream.offset_bits() == offset);
    CHECK(stream.Copy(dest.data(), width) == padding);
    CHECK(dest == expected);
    CHECK(source == source_before);
    CHECK(stream.offset_bits() == size_bits);
    CHECK(stream.BitsRemaining() == 0);
  }
}

TEST_CASE("BitStream invalid copy ranges and buffers leave state intact",
          "[stream][bitstream][copy]") {
  std::array<uint8_t, 3> source{0xA5, 0x5A, 0xC3};
  std::array<uint8_t, 3> dest{0x96, 0x69, 0xF0};
  const auto source_before = source;
  const auto dest_before = dest;
  BitStream stream(source.data(), 17);
  stream.SetOffset(9);
  for (auto width : {size_t(9), size_t(18), std::numeric_limits<size_t>::max()}) {
    CHECK(stream.Copy(dest.data(), width) == 1);
    CHECK(stream.offset_bits() == 9);
    CHECK(dest == dest_before);
    CHECK(source == source_before);
  }
  CHECK(stream.Copy(nullptr, 1) == 1);
  CHECK(stream.offset_bits() == 9);
  stream.SetOffset(17);
  CHECK(stream.Copy(dest.data(), 1) == 1);
  CHECK(stream.Copy(nullptr, 0) == 1);
  CHECK(stream.offset_bits() == 17);
  CHECK(dest == dest_before);
  BitStream empty(nullptr, 0);
  CHECK(empty.Copy(nullptr, 0) == 0);
  CHECK(empty.Copy(dest.data(), 1) == 0);
  CHECK(empty.offset_bits() == 0);
  BitStream missing_source(nullptr, 8);
  CHECK(missing_source.Copy(dest.data(), 8) == 0);
  CHECK(missing_source.offset_bits() == 0);
  CHECK(dest == dest_before);
}

TEST_CASE("BitStream copy rejects overlap and allows adjacent ranges",
          "[stream][bitstream][copy]") {
  std::mt19937 random(0xA11A5);
  for (size_t iteration = 0; iteration < 1024; ++iteration) {
    std::array<uint8_t, 128> storage;
    for (auto& byte : storage)
      byte = static_cast<uint8_t>(random());
    const auto before = storage;
    const size_t offset = random() % 32;
    const size_t width = 1 + random() % 129;
    const size_t padding = offset & 7;
    const size_t source_origin = 32;
    const size_t source_first = source_origin + offset / 8;
    const size_t touched_bytes = (padding + width + 7) / 8;
    // Include exact aliases, both directions, adjacent and separated ranges.
    const size_t destination = iteration % 4 == 0 ? source_first
                               : iteration % 4 == 1 ? source_first + touched_bytes
                               : iteration % 4 == 2 ? source_first - touched_bytes
                                                    : random() % 65;
    const bool overlap = destination < source_first + touched_bytes &&
                         source_first < destination + touched_bytes;
    CAPTURE(iteration, offset, width, destination, overlap);
    auto expected = before;
    if (!overlap) {
      for (size_t bit = 0; bit < width; ++bit) {
        const auto source_index = offset + bit;
        const auto dest_index = padding + bit;
        const auto mask = uint8_t(0x80 >> (dest_index & 7));
        auto& byte = expected[destination + dest_index / 8];
        if (before[source_origin + source_index / 8] & (0x80 >> (source_index & 7)))
          byte |= mask;
        else
          byte &= uint8_t(~mask);
      }
    }
    BitStream stream(storage.data() + source_origin, offset + width);
    stream.SetOffset(offset);
    CHECK(stream.Copy(storage.data() + destination, width) == padding);
    CHECK(storage == expected);
    CHECK(stream.offset_bits() == (overlap ? offset : offset + width));
  }
}
