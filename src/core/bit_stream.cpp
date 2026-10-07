/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2021 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

#include <algorithm>
#include <cstring>

#include <rex/assert.h>
#include <rex/stream.h>

namespace rex::stream {

BitStream::BitStream(uint8_t* buffer, size_t size_in_bits)
    : buffer_(buffer), size_bits_(size_in_bits) {}

BitStream::~BitStream() = default;

void BitStream::SetOffset(size_t offset_bits) {
  assert_false(offset_bits > size_bits_);
  offset_bits_ = std::min(offset_bits, size_bits_);
}

size_t BitStream::BitsRemaining() {
  return size_bits_ - offset_bits_;
}

uint64_t BitStream::Peek(size_t num_bits) {
  assert_false(num_bits > 57);
  assert_false(num_bits > BitsRemaining());
  if (num_bits > 57 || num_bits > BitsRemaining() || (!buffer_ && num_bits))
    return 0;

  // Read MSB-first bytes without requiring alignment or eight padding bytes
  // after the requested field. A 0-bit read touches no memory and never shifts
  // by the integer width.
  uint64_t bits = 0;
  size_t cursor = offset_bits_;
  size_t remaining = num_bits;
  while (remaining) {
    const size_t bit_in_byte = cursor & 7;
    const size_t count = std::min(remaining, 8 - bit_in_byte);
    const size_t shift = 8 - bit_in_byte - count;
    const uint32_t mask = (uint32_t(1) << count) - 1;
    bits = (bits << count) | ((buffer_[cursor >> 3] >> shift) & mask);
    cursor += count;
    remaining -= count;
  }
  return bits;
}

uint64_t BitStream::Read(size_t num_bits) {
  uint64_t val = Peek(num_bits);
  // Preserve the offset when a release caller violates the asserted range.
  if (num_bits <= 57 && num_bits <= BitsRemaining() && (buffer_ || !num_bits))
    Advance(num_bits);
  return val;
}

bool BitStream::Write(uint64_t val, size_t num_bits) {
  // Validate before touching the buffer. Subtraction avoids offset+length
  // overflow; writing the last bit and an empty write at EOF are both valid.
  if (num_bits > 57 || num_bits > BitsRemaining() || (!buffer_ && num_bits))
    return false;
  size_t cursor = offset_bits_;
  size_t remaining = num_bits;
  while (remaining) {
    const size_t bit_in_byte = cursor & 7;
    const size_t count = std::min(remaining, 8 - bit_in_byte);
    const size_t destination_shift = 8 - bit_in_byte - count;
    const uint32_t low_mask = (uint32_t(1) << count) - 1;
    const uint8_t mask = static_cast<uint8_t>(low_mask << destination_shift);
    const auto field = static_cast<uint8_t>(((val >> (remaining - count)) & low_mask)
                                           << destination_shift);
    auto& byte = buffer_[cursor >> 3];
    byte = static_cast<uint8_t>((byte & ~mask) | field);
    cursor += count;
    remaining -= count;
  }
  offset_bits_ = cursor;
  return true;
}

size_t BitStream::Copy(uint8_t* dest_buffer, size_t num_bits) {
  size_t offset_bytes = offset_bits_ >> 3;
  size_t rel_offset_bits = offset_bits_ - (offset_bytes << 3);
  size_t bits_left = num_bits;
  size_t out_offset_bytes = 0;

  // First: Copy the first few bits up to a byte boundary.
  if (rel_offset_bits) {
    uint64_t bits = Peek(8 - rel_offset_bits);
    uint8_t clear_mask = ~((uint8_t(1) << rel_offset_bits) - 1);
    dest_buffer[out_offset_bytes] &= clear_mask;
    dest_buffer[out_offset_bytes] |= (uint8_t)bits;

    bits_left -= 8 - rel_offset_bits;
    Advance(8 - rel_offset_bits);
    out_offset_bytes++;
  }

  // Second: Use memcpy for the bytes left.
  if (bits_left >= 8) {
    std::memcpy(dest_buffer + out_offset_bytes, buffer_ + offset_bytes + out_offset_bytes,
                bits_left / 8);
    out_offset_bytes += (bits_left / 8);
    Advance((bits_left / 8) * 8);
    bits_left -= (bits_left / 8) * 8;
  }

  // Third: Copy the last few bits.
  if (bits_left) {
    uint64_t bits = Peek(bits_left);
    bits <<= 8 - bits_left;

    uint8_t clear_mask = ((uint8_t(1) << bits_left) - 1);
    dest_buffer[out_offset_bytes] &= clear_mask;
    dest_buffer[out_offset_bytes] |= (uint8_t)bits;
    Advance(bits_left);
  }

  // Return the bit offset to the copied bits.
  return rel_offset_bits;
}

void BitStream::Advance(size_t num_bits) {
  SetOffset(offset_bits_ + num_bits);
}

}  // namespace rex::stream
