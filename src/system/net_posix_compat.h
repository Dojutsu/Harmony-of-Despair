/**
 * @file        system/net_posix_compat.h
 * @brief       macOS equivalents of the Linux-only primitives used by the
 *              online/LAN socket stack.
 *
 * Private to the runtime. Every helper here exists only on REX_PLATFORM_MAC
 * and stands in for one Linux API at its call site:
 *
 *   process_vm_readv/writev(getpid())  -> ReadSelf / WriteSelf
 *   ppoll(..., timespec, nullptr)      -> PollTimespec
 *   eventfd(EFD_CLOEXEC|EFD_NONBLOCK)  -> CreateWakePipe
 *   SOCK_CLOEXEC / accept4 / MSG_NOSIGNAL -> ConfigureSocketDescriptor
 *   recvfrom(flags | MSG_TRUNC)        -> ReceiveReportingTruncation
 *   getrandom                          -> arc4random_buf (used inline)
 *
 * Linux and Windows never include anything from this header.
 */
#pragma once

#include <rex/platform.h>

#if REX_PLATFORM_MAC
#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <cstring>

#include <fcntl.h>
#include <mach/mach.h>
#include <mach/mach_vm.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <time.h>
#include <unistd.h>

namespace rex::net::mac {

// Chunks no larger than this always take XNU's kernel-buffer copy path
// (copyin/copyout), so a copy never substitutes pages in the destination
// mapping (which could break the aliasing of shared guest views) and an
// unmapped or protected page simply fails the call. 4 KiB is below the
// small-copy threshold for both 4 KiB (x86_64) and 16 KiB (arm64) pages.
inline constexpr size_t kSelfCopyChunk = 4096;

// process_vm_readv(getpid()) equivalent: copy from an address in this process
// that may be unmapped or unreadable. Returns false instead of faulting.
inline bool ReadSelf(void* destination, const void* source, size_t length) noexcept {
  auto* to = static_cast<uint8_t*>(destination);
  auto* from = static_cast<const uint8_t*>(source);
  while (length) {
    const size_t chunk = std::min(length, kSelfCopyChunk);
    mach_vm_size_t copied = 0;
    const kern_return_t result = mach_vm_read_overwrite(
        mach_task_self(), static_cast<mach_vm_address_t>(reinterpret_cast<uintptr_t>(from)),
        static_cast<mach_vm_size_t>(chunk),
        static_cast<mach_vm_address_t>(reinterpret_cast<uintptr_t>(to)), &copied);
    if (result != KERN_SUCCESS || copied != chunk) return false;
    to += chunk;
    from += chunk;
    length -= chunk;
  }
  return true;
}

// process_vm_writev(getpid()) equivalent: copy into an address in this
// process that may be unmapped or read-only. Returns false instead of
// faulting. As with process_vm_writev, a failure may leave a prefix written.
inline bool WriteSelf(void* destination, const void* source, size_t length) noexcept {
  auto* to = static_cast<uint8_t*>(destination);
  auto* from = static_cast<const uint8_t*>(source);
  while (length) {
    const size_t chunk = std::min(length, kSelfCopyChunk);
    const kern_return_t result = mach_vm_write(
        mach_task_self(), static_cast<mach_vm_address_t>(reinterpret_cast<uintptr_t>(to)),
        static_cast<vm_offset_t>(reinterpret_cast<uintptr_t>(from)),
        static_cast<mach_msg_type_number_t>(chunk));
    if (result != KERN_SUCCESS) return false;
    to += chunk;
    from += chunk;
    length -= chunk;
  }
  return true;
}

// ppoll(descriptors, count, timeout, nullptr) equivalent. macOS has no ppoll;
// no signal mask is ever passed by the callers, so only the timeout differs.
// A finite timeout is rounded up to whole milliseconds so it never returns
// early, and clamped to poll's signed range.
inline int PollTimespec(pollfd* descriptors, nfds_t count, const timespec* timeout) noexcept {
  int milliseconds = -1;
  if (timeout) {
    if (timeout->tv_sec < 0 || timeout->tv_nsec < 0) {
      milliseconds = 0;
    } else {
      const uint64_t seconds = static_cast<uint64_t>(timeout->tv_sec);
      const uint64_t extra = (static_cast<uint64_t>(timeout->tv_nsec) + 999999u) / 1000000u;
      const uint64_t total = seconds > uint64_t(INT_MAX) / 1000u
                                 ? uint64_t(INT_MAX)
                                 : seconds * 1000u + extra;
      milliseconds = static_cast<int>(std::min<uint64_t>(total, uint64_t(INT_MAX)));
    }
  }
  return ::poll(descriptors, count, milliseconds);
}

// Close-on-exec and nonblocking for a descriptor (SOCK_CLOEXEC/EFD_* stand-in).
inline bool SetCloseOnExec(int descriptor) noexcept {
  const int flags = ::fcntl(descriptor, F_GETFD);
  return flags >= 0 && ::fcntl(descriptor, F_SETFD, flags | FD_CLOEXEC) == 0;
}
inline bool SetNonBlocking(int descriptor) noexcept {
  const int flags = ::fcntl(descriptor, F_GETFL);
  return flags >= 0 && ::fcntl(descriptor, F_SETFL, flags | O_NONBLOCK) == 0;
}

// Applied to every socket the online stack creates or accepts: replaces
// SOCK_CLOEXEC / accept4(SOCK_CLOEXEC) and MSG_NOSIGNAL (SO_NOSIGPIPE makes a
// write to a reset stream return EPIPE instead of raising SIGPIPE).
inline bool ConfigureSocketDescriptor(int descriptor) noexcept {
  int enabled = 1;
  return SetCloseOnExec(descriptor) &&
         ::setsockopt(descriptor, SOL_SOCKET, SO_NOSIGPIPE, &enabled, sizeof(enabled)) == 0;
}

// eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK) equivalent for a one-shot, sticky
// wake: poll the read end for POLLIN; write one byte to the write end. The
// byte is never drained, so every later wait also wakes, like the eventfd.
inline bool CreateWakePipe(int& read_end, int& write_end) noexcept {
  read_end = write_end = -1;
  int descriptors[2] = {-1, -1};
  if (::pipe(descriptors) != 0) return false;
  if (!SetCloseOnExec(descriptors[0]) || !SetCloseOnExec(descriptors[1]) ||
      !SetNonBlocking(descriptors[0]) || !SetNonBlocking(descriptors[1])) {
    const int error = errno;
    ::close(descriptors[0]);
    ::close(descriptors[1]);
    errno = error;
    return false;
  }
  read_end = descriptors[0];
  write_end = descriptors[1];
  return true;
}

// recvfrom(fd, buffer, size, flags | MSG_TRUNC, ...) equivalent. Linux then
// returns the real datagram length, so callers detect an oversized datagram
// by result > size. Darwin truncates silently in recvfrom; recvmsg reports
// MSG_TRUNC in msg_flags, which is mapped to a result of size + 1.
inline ssize_t ReceiveReportingTruncation(int descriptor, void* buffer, size_t size, int flags,
                                          sockaddr* source, socklen_t* source_length) noexcept {
  iovec segment{buffer, size};
  msghdr message{};
  message.msg_name = source;
  message.msg_namelen = source && source_length ? *source_length : 0;
  message.msg_iov = &segment;
  message.msg_iovlen = 1;
  const ssize_t received = ::recvmsg(descriptor, &message, flags);
  if (received < 0) return received;
  if (source && source_length) *source_length = message.msg_namelen;
  if ((message.msg_flags & MSG_TRUNC) && size < size_t(SSIZE_MAX)) return ssize_t(size) + 1;
  return received;
}

}  // namespace rex::net::mac
#endif  // REX_PLATFORM_MAC
