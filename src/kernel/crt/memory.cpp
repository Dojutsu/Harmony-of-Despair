/**
 * @file        kernel/crt/memory.cpp
 *
 * @brief       Native memory operation hooks -- replaces recompiled PPC
 *              implementations of memcpy, memmove, memset, etc.
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 * @license     BSD 3-Clause License
 */
#include <cstring>

#include <rex/hook.h>

namespace rex::kernel::crt {

#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
static void* checked_copy(void* dst, const void* src, size_t n) {
  rex::guest::CopyBytes(dst, src, n);
  return dst;
}

static void* checked_move(void* dst, const void* src, size_t n) {
  if (!n || dst == src) return dst;
  auto destination = reinterpret_cast<uintptr_t>(dst);
  auto source = reinterpret_cast<uintptr_t>(src);
  if (destination > source ? destination - source < n : source - destination < n) {
    rex::guest::FaultContractFailure("overlapping-memmove-not-admitted");
  }
  return checked_copy(dst, src, n);
}
#endif

// ---------------------------------------------------------------------------
// Standard memory operations
// ---------------------------------------------------------------------------

static void* native_memcpy(void* dst, const void* src, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  return checked_copy(dst, src, n);
#else
  return std::memcpy(dst, src, n);
#endif
}

static void* native_memmove(void* dst, const void* src, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  return checked_move(dst, src, n);
#else
  return std::memmove(dst, src, n);
#endif
}

static void* native_memset(void* dst, int val, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  rex::guest::FillBytes(dst, static_cast<unsigned char>(val), n);
  return dst;
#else
  return std::memset(dst, val, n);
#endif
}

static void* native_memchr(const void* ptr, int val, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  auto* bytes = static_cast<const unsigned char*>(ptr);
  for (size_t i = 0; i < n; ++i) {
    if (rex::guest::Read<unsigned char>(bytes + i) == static_cast<unsigned char>(val)) {
      return const_cast<unsigned char*>(bytes + i);
    }
  }
  return nullptr;
#else
  return const_cast<void*>(std::memchr(ptr, val, n));
#endif
}

// ---------------------------------------------------------------------------
// Xbox/VMX-optimized variants (same semantics, native speed)
// ---------------------------------------------------------------------------

static void* native_XMemCpy(void* dst, const void* src, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  return native_memcpy(dst, src, n);
#else
  return std::memcpy(dst, src, n);
#endif
}

static void* native_XMemSet(void* dst, int val, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  return native_memset(dst, val, n);
#else
  return std::memset(dst, val, n);
#endif
}

static void* native_XMemSet128(void* dst, int val, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  return native_memset(dst, val, n);
#else
  return std::memset(dst, val, n);
#endif
}

static void* native_memset_vmx(void* dst, int val, size_t n) {
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  return native_memset(dst, val, n);
#else
  return std::memset(dst, val, n);
#endif
}

// ---------------------------------------------------------------------------
// Secure variants (return errno_t)
// ---------------------------------------------------------------------------

static int native_memcpy_s(void* dst, size_t dstsz, const void* src, size_t count) {
  if (!dst || !src || count > dstsz)
    return 22;  // EINVAL
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  checked_copy(dst, src, count);
#else
  std::memcpy(dst, src, count);
#endif
  return 0;
}

static int native_memmove_s(void* dst, size_t dstsz, const void* src, size_t count) {
  if (!dst || !src || count > dstsz)
    return 22;  // EINVAL
#if REX_PLATFORM_LINUX && REX_ARCH_AMD64
  checked_move(dst, src, count);
#else
  std::memmove(dst, src, count);
#endif
  return 0;
}

}  // namespace rex::kernel::crt

REX_HOOK(rexcrt_memcpy, rex::kernel::crt::native_memcpy)
REX_HOOK(rexcrt_memmove, rex::kernel::crt::native_memmove)
REX_HOOK(rexcrt_memset, rex::kernel::crt::native_memset)
REX_HOOK(rexcrt_memchr, rex::kernel::crt::native_memchr)
REX_HOOK(rexcrt_XMemCpy, rex::kernel::crt::native_XMemCpy)
REX_HOOK(rexcrt_XMemSet, rex::kernel::crt::native_XMemSet)
REX_HOOK(rexcrt_XMemSet128, rex::kernel::crt::native_XMemSet128)
REX_HOOK(rexcrt_memset_vmx, rex::kernel::crt::native_memset_vmx)
REX_HOOK(rexcrt_memcpy_s, rex::kernel::crt::native_memcpy_s)
REX_HOOK(rexcrt_memmove_s, rex::kernel::crt::native_memmove_s)
