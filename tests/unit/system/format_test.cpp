// Shared format semantics: Linux selects registered reads; Windows retains raw
// reads. These fixed guest byte buffers use the same inputs on either platform.
#include <rex/system/format.h>

#include <catch2/catch_test_macros.hpp>

#include <array>
#include <cstring>

namespace {

struct FormatFixture {
  std::array<uint8_t, 4096> memory{};
  PPCContext context{};
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  rex::guest::ExecutionActivation activation;
#endif
  void String(size_t address, const char* value) {
    std::memcpy(memory.data() + address, value, std::strlen(value) + 1);
  }
  void Word(size_t address, uint32_t value) {
    uint32_t stored = __builtin_bswap32(value);
    std::memcpy(memory.data() + address, &stored, sizeof(stored));
  }
  void Quad(size_t address, uint64_t value) {
    uint64_t stored = __builtin_bswap64(value);
    std::memcpy(memory.data() + address, &stored, sizeof(stored));
  }
};

}  // namespace

TEST_CASE("Format engine preserves guest strings and integer padding",
          "[kernel][format]") {
  FormatFixture fixture;
  fixture.String(128, "%08X:%s");
  fixture.String(256, "abc");
  fixture.context.r3.u64 = 0x1AB;
  fixture.context.r4.u64 = 256;
  rex::system::format::StackArgList args(fixture.context, fixture.memory.data(), 0);
  rex::system::format::StringFormatData data(fixture.memory.data() + 128);
  CHECK(rex::system::format::format_core(fixture.memory.data(), data, args, false) == 12);
  CHECK(data.str() == "000001AB:abc");

}

TEST_CASE("Format engine preserves existing terminal percent-n result and count write",
          "[kernel][format]") {
  FormatFixture fixture;
  fixture.String(128, "%08X:%s%n");
  fixture.String(256, "abc");
  fixture.context.r3.u64 = 0x1AB;
  fixture.context.r4.u64 = 256;
  fixture.context.r5.u64 = 512;
  rex::system::format::StackArgList args(fixture.context, fixture.memory.data(), 0);
  rex::system::format::StringFormatData data(fixture.memory.data() + 128);
  // The existing parser writes %n then continues in FS_Type. Its terminal NUL
  // returns -1; Linux access routing must preserve this Windows/shared behavior.
  CHECK(rex::system::format::format_core(fixture.memory.data(), data, args, false) == -1);
  CHECK(data.str() == "000001AB:abc");
  CHECK(fixture.memory[512] == 0);
  CHECK(fixture.memory[513] == 0);
  CHECK(fixture.memory[514] == 0);
  CHECK(fixture.memory[515] == 12);
}

TEST_CASE("Format engine preserves 64-bit stack and array argument slot endian layout",
          "[kernel][format]") {
  FormatFixture fixture;
  fixture.String(128, "%llx");
  fixture.context.r1.u32 = 1024;
  fixture.Quad(1024 + 0x54, 0x1122334455667788);
  rex::system::format::StackArgList stack_args(fixture.context, fixture.memory.data(), 8);
  rex::system::format::StringFormatData stack_data(fixture.memory.data() + 128);
  CHECK(rex::system::format::format_core(fixture.memory.data(), stack_data, stack_args, false) ==
        16);
  CHECK(stack_data.str() == "1122334455667788");

  fixture.String(128, "%llx:%d");
  fixture.Quad(2048, 0x1122334455667788);
  fixture.Quad(2056, 0xFFFFFFFF);
  rex::system::format::ArrayArgList array_args(fixture.memory.data(), 2048);
  rex::system::format::StringFormatData array_data(fixture.memory.data() + 128);
  CHECK(rex::system::format::format_core(fixture.memory.data(), array_data, array_args, false) ==
        19);
  CHECK(array_data.str() == "1122334455667788:-1");
}

TEST_CASE("Format engine preserves big-endian wide guest strings",
          "[kernel][format]") {
  FormatFixture fixture;
  // Write both strings as guest big-endian UTF-16, not host wchar_t.
  const uint16_t format[] = {__builtin_bswap16('%'), __builtin_bswap16('s'), 0};
  const uint16_t input[] = {__builtin_bswap16('H'), __builtin_bswap16('i'), 0};
  std::memcpy(fixture.memory.data() + 128, format, sizeof(format));
  std::memcpy(fixture.memory.data() + 256, input, sizeof(input));
  fixture.context.r3.u64 = 256;
  rex::system::format::StackArgList args(fixture.context, fixture.memory.data(), 0);
  rex::system::format::WideStringFormatData data(
      reinterpret_cast<const uint16_t*>(fixture.memory.data() + 128));
  CHECK(rex::system::format::format_core(fixture.memory.data(), data, args, true) == 2);
  CHECK(data.wstr() == u"Hi");
}
