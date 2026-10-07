/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2014 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

#pragma once

#include <memory>
#include <mutex>
#include <vector>

#include <rex/platform.h>
#include <rex/thread/mutex.h>

namespace rex::arch {
class Exception;
class HostThreadContext;
}  // namespace rex::arch

namespace rex::guest::detail { struct MappedAccessClassifier; }

namespace rex::runtime {

typedef uint32_t (*MMIOReadCallback)(void* ppc_context, void* callback_context, uint32_t addr);
typedef void (*MMIOWriteCallback)(void* ppc_context, void* callback_context, uint32_t addr,
                                  uint32_t value);

struct MMIORange {
  uint32_t address;
  uint32_t mask;
  uint32_t size;
  void* callback_context;
  MMIOReadCallback read;
  MMIOWriteCallback write;
};

// NOTE: only one can exist at a time!
class MMIOHandler {
 public:
  virtual ~MMIOHandler();

  typedef uint32_t (*HostToGuestVirtual)(const void* context, const void* host_address);
  typedef bool (*AccessViolationCallback)(
      std::unique_lock<std::recursive_mutex> global_lock_locked_once, void* context,
      void* host_address, bool is_write);

  // access_violation_callback is called with global_critical_region locked once
  // on the thread, so if multiple threads trigger an access violation in the
  // same page, the callback will be called only once.
  static std::unique_ptr<MMIOHandler> Install(uint8_t* virtual_membase, uint8_t* physical_membase,
                                              uint8_t* membase_end,
                                              HostToGuestVirtual host_to_guest_virtual,
                                              const void* host_to_guest_virtual_context,
                                              AccessViolationCallback access_violation_callback,
                                              void* access_violation_callback_context);
  static MMIOHandler* global_handler();

  bool RegisterRange(uint32_t virtual_address, uint32_t mask, uint32_t size, void* context,
                     MMIOReadCallback read_callback, MMIOWriteCallback write_callback);
  MMIORange* LookupRange(uint32_t virtual_address);

  bool CheckLoad(uint32_t virtual_address, uint32_t* out_value);
  bool CheckStore(uint32_t virtual_address, uint32_t value);

#if REX_PLATFORM_LINUX
  // Metadata-only, normal-context admission check. This intentionally does not
  // depend on current host page protection and never invokes a device callback.
  bool IsMappedAddress(const void* host_address,
                       uint32_t* mapped_guest_address = nullptr) const noexcept;
  // Check a contiguous admitted virtual interval before bulk side effects.
  // The runtime's known host-to-guest translator must be affine on the clipped
  // interval; overflowing/nonlinear endpoint translations are refused.
  bool IsMappedRange(const void* host_address, size_t length) const noexcept;

  // Normal-context recovery for registered Linux accesses. The caller must hold
  // its ExecutionActivation's AdjudicationScope; this API never runs in a signal
  // handler and never replays a completed callback. Native callback faults are
  // deliberately outside registered access-leaf ownership.
  enum class DeferredAccessKind { kScalar32, kScalarRam, kVector128, kAtomic, kForwardBulk };
  enum class DeferredRecovery { kRetry, kCompleted, kGuestFault, kUnsupported };
  class DeferredTransaction {
   public:
    enum class Phase { kUnstarted, kResolving, kRetryReady, kCompleted, kGuestFault,
                       kUnsupported, kPoisoned };
    DeferredTransaction();
    DeferredTransaction(const DeferredTransaction&) = delete;
    DeferredTransaction& operator=(const DeferredTransaction&) = delete;
    Phase phase() const { return phase_; }
    // A repaired unfinished RAM/watch access may be attempted again. Completed
    // MMIO suboperations cannot transition back to an unstarted transaction.
    bool BeginRetry();
    // Record successful native completion after the registered leaf returns,
    // or explicit MMIO completion after its guarded callback returns normally.
    // Neither completion can be repeated or restarted.
    bool CompleteNative();
    bool CompleteExplicit();

   private:
    friend class MMIOHandler;
    const uint64_t owner_id_;
    Phase phase_ = Phase::kUnstarted;
    // Linux registered RAM/watch repair must remain protected from a new GPU
    // watch until the unfinished native access completes. This is normal
    // context RAII; no signal handler acquires or releases this mutex.
    std::unique_lock<std::recursive_mutex> retry_lock_;
  };
  DeferredRecovery ResolveAccessFault(arch::Exception& exception,
                                     DeferredAccessKind kind,
                                     DeferredTransaction& transaction);
#endif

 protected:
  MMIOHandler(uint8_t* virtual_membase, uint8_t* physical_membase, uint8_t* membase_end,
              HostToGuestVirtual host_to_guest_virtual, const void* host_to_guest_virtual_context,
              AccessViolationCallback access_violation_callback,
              void* access_violation_callback_context);

  static bool ExceptionCallbackThunk(arch::Exception* ex, void* data);
  bool ExceptionCallback(arch::Exception* ex);

  uint8_t* virtual_membase_;
  uint8_t* physical_membase_;
  uint8_t* memory_end_;

  std::vector<MMIORange> mapped_ranges_;

  HostToGuestVirtual host_to_guest_virtual_;
  const void* host_to_guest_virtual_context_;

  AccessViolationCallback access_violation_callback_;
  void* access_violation_callback_context_;

  static MMIOHandler* global_handler_;

  rex::thread::global_critical_region global_critical_region_;

 private:
#if REX_PLATFORM_LINUX
  friend struct rex::guest::detail::MappedAccessClassifier;
  // Fresh normal-context classification for checked scalar consumers. The
  // translator is the same admitted deterministic runtime metadata translator
  // used by IsMappedRange. No result survives this operation.
  __attribute__((visibility("hidden")))
  bool ClassifyMappedAccess(const void* host_address, size_t length,
                            uint32_t* point_guest_address, bool* point_mapped) const noexcept;
#endif
  struct DecodedLoadStore {
    // Matches the Xn/Wn register number for 0 reads and ignored writes in many
    // usage cases.
    static constexpr uint8_t kArm64RegZero = 31;

    // Matches the actual register number encoding for an SP base in AArch64
    // load and store instructions.
    static constexpr uint8_t kArm64MemBaseRegSp = kArm64RegZero;

    static constexpr uint8_t kArm64ValueRegX0 = 0;
    static constexpr uint8_t kArm64ValueRegZero = kArm64ValueRegX0 + kArm64RegZero;
    static constexpr uint8_t kArm64ValueRegV0 = 32;

    size_t length;
    // Inidicates this is a load (or conversely a store).
    bool is_load;
    // Indicates the memory must be swapped.
    bool byte_swap;
    // Source (for store) or target (for load) register.
    // For x86-64:
    // AX  CX  DX  BX  SP  BP  SI  DI   // REX.R=0
    // R8  R9  R10 R11 R12 R13 R14 R15  // REX.R=1
    // For AArch64:
    // - kArm64ValueRegX0 + [0...30]: Xn (Wn for 32 bits - upper 32 bits of Xn
    //   are zeroed on Wn write).
    // - kArm64ValueRegZero: Zero constant for register read, ignored register
    //   write (though memory must still be accessed - a MMIO load may have side
    //   effects even if the result is discarded).
    // - kArm64ValueRegV0 + [0...31]: Vn (Sn for 32 bits).
    uint8_t value_reg;
    // [base + (index * scale) + displacement]
    bool mem_has_base;
    // On AArch64, if mem_base_reg is kArm64MemBaseRegSp, the base register is
    // SP, not Xn.
    uint8_t mem_base_reg;
    // For AArch64 pre- and post-indexing. In case of a load, the base register
    // is written back after the loaded data is written to the register,
    // overwriting the value register if it's the same.
    bool mem_base_writeback;
    int32_t mem_base_writeback_offset;
    bool mem_has_index;
    uint8_t mem_index_reg;
    uint8_t mem_index_size;
    bool mem_index_sign_extend;
    uint8_t mem_scale;
    ptrdiff_t mem_displacement;
    bool is_constant;
    int32_t constant;
  };

  static bool TryDecodeLoadStore(const uint8_t* p, DecodedLoadStore& decoded_out);
};

}  // namespace rex::runtime
