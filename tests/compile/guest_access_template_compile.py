#!/usr/bin/env python3
"""Compile the static access template for both Linux and preserved raw selectors.

This syntax probe uses the pinned runner compiler. The raw selector is compiled
on Linux to validate macro expansion; it does not claim Windows execution.
"""
from pathlib import Path
import argparse
import subprocess
import tempfile

PRELUDE = r"""
#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>
#include <immintrin.h>
using u8 = uint8_t; using u16 = uint16_t;
using u32 = uint32_t; using u64 = uint64_t;
using simde__m128i = __m128i;
inline simde__m128i simde_mm_load_si128(const simde__m128i* p) { return _mm_load_si128(p); }
inline void simde_mm_store_si128(simde__m128i* p, simde__m128i v) { _mm_store_si128(p, v); }
namespace rex::guest {
template<class T> T Read(const void*);
template<class T> void Write(void*, T);
std::string ReadString(const void*, size_t);
u32 MmioRead32(uint8_t*, u32);
void MmioWrite32(uint8_t*, u32, u32);
template<class T> T ReadVector(const void*);
template<class T> void WriteVector(void*, T);
u32 ReadReserved32(const void*); u64 ReadReserved64(const void*);
u32 CompareExchange32(void*, u32, u32); u64 CompareExchange64(void*, u64, u64);
void FillBytes(void*, uint8_t, size_t);
}
namespace rex::runtime {
struct MMIOHandler {
  static MMIOHandler* global_handler();
  bool CheckStore(u32, u32); bool CheckLoad(u32, u32*);
};
}
"""
EXERCISE = r"""
void Exercise(uint8_t* base, u32 address, u64 value, simde__m128i vector) {
  REX_STORE_U8(address, static_cast<u8>(value));
  REX_STORE_U16(address, static_cast<u16>(value));
  REX_STORE_U32(address, static_cast<u32>(value));
  REX_STORE_U64(address, value);
  (void)REX_LOAD_U8(address); (void)REX_LOAD_U16(address);
  (void)REX_LOAD_U32(address); (void)REX_LOAD_U64(address);
  (void)REX_LOAD_STRING(address, 1);
  REX_MM_STORE_U8(address, value); REX_MM_STORE_U16(address, value);
  REX_MM_STORE_U32(address, value); REX_MM_STORE_U64(address, value);
  (void)REX_MM_LOAD_U8(address); (void)REX_MM_LOAD_U16(address);
  (void)REX_MM_LOAD_U32(address); (void)REX_MM_LOAD_U64(address);
  REX_STORE_VECTOR(address, vector); (void)REX_LOAD_VECTOR(address);
  (void)REX_LOAD_RESERVED_U32(address); (void)REX_LOAD_RESERVED_U64(address);
  (void)REX_COMPARE_EXCHANGE_U32(address, 1u, 2u);
  (void)REX_COMPARE_EXCHANGE_U64(address, 1ull, 2ull);
  REX_FILL_BYTES(address, 0, 128);
}
"""

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler', required=True)
    parser.add_argument('--sdk-root', type=Path, default=Path(__file__).resolve().parents[2])
    args = parser.parse_args()
    template = (args.sdk_root / 'resources/templates/codegen/pch_h.inja').read_text()
    start = template.index('#if REX_PLATFORM_WIN32 || (REX_PLATFORM_MAC && REX_ARCH_ARM64)')
    end = template.index('//=============================================================================\n// Function Dispatch', start)
    # Compile the actual emitted static macro block. Stubs describe call syntax;
    # production API and runtime semantics are covered by the focused unit tests.
    block = template[start:end].replace('#include <rex/platform/guest_memory.h>', '')
    with tempfile.TemporaryDirectory(prefix='rex-template-compile-') as directory:
        for name, linux in [('linux', 1), ('preserved-raw', 0)]:
            source = Path(directory) / (name + '.cpp')
            source.write_text(PRELUDE + block + EXERCISE)
            subprocess.run([args.compiler, '-std=c++23', '-fsyntax-only',
                '-DREX_PLATFORM_LINUX=' + str(linux), '-DREX_PLATFORM_WIN32=' + str(1-linux),
                '-DREX_PLATFORM_MAC=0', '-DREX_ARCH_AMD64=1', '-DREX_ARCH_ARM64=0',
                str(source)], check=True)
            print(name + ': access template syntax PASS')
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
