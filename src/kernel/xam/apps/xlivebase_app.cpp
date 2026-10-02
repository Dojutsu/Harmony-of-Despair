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

#include <rex/kernel/xam/apps/xlivebase_app.h>
#include <rex/system/xmemory.h>
#include <rex/logging.h>
#include <rex/thread.h>

#include <cstring>

namespace rex {
namespace kernel {
namespace xam {
using namespace rex::system;
using namespace rex::system::xam;
namespace apps {
using namespace rex::system;

namespace {
bool GuestRangeAccessible(memory::Memory* memory, uint32_t address,
                          uint32_t size, bool writable) {
  if (!memory || !address || !size ||
      uint64_t{address} + size > (uint64_t{1} << 32))
    return false;
  auto* heap = memory->LookupHeap(address);
  if (!heap)
    return false;
  const uint32_t last = uint32_t(uint64_t{address} + size - 1);
  const auto access = heap->QueryRangeAccess(address, last);
  if (access == memory::PageAccess::kNoAccess ||
      (writable && access != memory::PageAccess::kReadWrite &&
       access != memory::PageAccess::kExecuteReadWrite))
    return false;
  uint64_t cursor = address - (address - heap->heap_base()) % heap->page_size();
  const uint64_t end = uint64_t{address} + size;
  while (cursor < end) {
    memory::HeapAllocationInfo info{};
    if (!heap->QueryRegionInfo(uint32_t(cursor), &info) || !info.region_size ||
        !(info.state & memory::kMemoryAllocationCommit))
      return false;
    cursor += info.region_size;
  }
  return true;
}

std::optional<uint32_t> DecodeGuestPointer(uint64_t encoded) {
  const auto address = uint32_t(encoded);
  if (!address || encoded != uint64_t(int64_t(int32_t(address))))
    return std::nullopt;
  return address;
}
}  // namespace

X_HRESULT DispatchAcceptedInviteGetInfo(
    memory::Memory* memory, uint32_t argument_list_ptr,
    uint32_t current_title_id, const AcceptedInviteRecordProvider& provider) {
  constexpr uint32_t kDescriptorStride = 16;
  constexpr uint32_t kCountOffset = 0x200;
  REXKRNL_INFO("INVITE_DIAG XLIVEBASE_58023_CALLED title={:08X}", current_title_id);
  auto invalid = [](const char* reason) {
    REXKRNL_WARN("INVITE_DIAG XLIVEBASE_58023_FAIL_{}", reason);
    return X_E_INVALIDARG;
  };
  if (!GuestRangeAccessible(memory, argument_list_ptr, 0x204, false))
    return invalid("ARGUMENT_RANGE");
  const auto* arguments = memory->TranslateVirtual(argument_list_ptr);
  if (memory::load_and_swap<uint32_t>(arguments + kCountOffset) != 2)
    return invalid("DESCRIPTOR_COUNT");
  std::array<uint32_t, 2> pointers{};
  for (uint32_t i = 0; i < pointers.size(); ++i) {
    const uint32_t offset = i * kDescriptorStride;
    if (memory::load_and_swap<uint32_t>(arguments + offset) != 4)
      return invalid("DESCRIPTOR_SIZE");
    auto pointer = DecodeGuestPointer(
        memory::load_and_swap<uint64_t>(arguments + offset + 8));
    if (!pointer)
      return invalid("DESCRIPTOR_POINTER");
    pointers[i] = *pointer;
  }
  if (!GuestRangeAccessible(memory, pointers[0], 4, false) ||
      !GuestRangeAccessible(memory, pointers[1], kAcceptedInviteRecordSize, true))
    return invalid("GUEST_RANGE");
  const uint32_t user_index =
      memory::load_and_swap<uint32_t>(memory->TranslateVirtual(pointers[0]));
  if (user_index != 0)
    return invalid("USER_INDEX");
  auto lease = provider ? provider(user_index, current_title_id) : std::nullopt;
  if (!lease) {
    REXKRNL_WARN("INVITE_DIAG XLIVEBASE_58023_FAIL_NO_ACTIVE_RECORD user={} title={:08X}",
                 user_index, current_title_id);
    return X_E_FAIL;
  }
  // The shared read lock remains held until this one complete guest write ends.
  std::memcpy(memory->TranslateVirtual(pointers[1]), lease->record().data(),
              lease->record().size());
  REXKRNL_INFO("INVITE_DIAG XLIVEBASE_58023_SUCCESS user={} title={:08X} bytes={}",
               user_index, current_title_id, lease->record().size());
  return X_E_SUCCESS;
}

XLiveBaseApp::XLiveBaseApp(KernelState* kernel_state) : App(kernel_state, 0xFC) {}

// http://mb.mirage.org/bugzilla/xliveless/main.c

X_HRESULT XLiveBaseApp::DispatchMessageSync(uint32_t message, uint32_t buffer_ptr,
                                            uint32_t buffer_length) {
  // NOTE: buffer_length may be zero or valid.
  auto buffer = memory_->TranslateVirtual(buffer_ptr);
  switch (message) {
    case 0x00058004: {
      // Called on startup, seems to just return a bool in the buffer.
      assert_true(!buffer_length || buffer_length == 4);
      REXKRNL_DEBUG("XLiveBaseGetLogonId({:08X})", buffer_ptr);
      memory::store_and_swap<uint32_t>(buffer + 0, 1);  // ?
      return X_E_SUCCESS;
    }
    case 0x00058006: {
      assert_true(!buffer_length || buffer_length == 4);
      REXKRNL_DEBUG("XLiveBaseGetNatType({:08X})", buffer_ptr);
      memory::store_and_swap<uint32_t>(buffer + 0, 1);  // XONLINE_NAT_OPEN
      return X_E_SUCCESS;
    }
    case 0x00058007: {
      // Occurs if title calls XOnlineGetServiceInfo, expects dwServiceId
      // and pServiceInfo. pServiceInfo should contain pointer to
      // XONLINE_SERVICE_INFO structure.
      REXKRNL_DEBUG("CXLiveLogon::GetServiceInfo({:08X}, {:08X})", buffer_ptr, buffer_length);
      return 0x80151802;  // ERROR_CONNECTION_INVALID
    }
    case 0x00058020: {
      // 0x00058004 is called right before this.
      // We should create a XamEnumerate-able empty list here, but I'm not
      // sure of the format.
      // buffer_length seems to be the same ptr sent to 0x00058004.
      REXKRNL_DEBUG("CXLiveFriends::Enumerate({:08X}, {:08X}) unimplemented", buffer_ptr,
                    buffer_length);
      return X_E_FAIL;
    }
    case 0x00058023: {
      // Harmony passes a context in arg1 and a descriptor-list guest pointer
      // in arg2; the inherited buffer_length name is misleading here.
      return DispatchAcceptedInviteGetInfo(
          memory_, buffer_length, kernel_state_->title_id(),
          [this](uint32_t user, uint32_t title) {
            return kernel_state_->session_manager()->GetAcceptedInviteRecord(
                user, title);
          });
    }
    case 0x00058046: {
      // Required to be successful for 4D530910 to detect signed-in profile
      // Doesn't seem to set anything in the given buffer, probably only takes
      // input
      REXKRNL_DEBUG("XLiveBaseUnk58046({:08X}, {:08X}) unimplemented", buffer_ptr, buffer_length);
      return X_E_SUCCESS;
    }
    case 0x00058037: {
      REXKRNL_DEBUG("XPresenceInitialize({:08X}, {:08X})", buffer_ptr, buffer_length);
      return X_E_SUCCESS;
    }
  }
  REXKRNL_ERROR(
      "Unimplemented XLIVEBASE message app={:08X}, msg={:08X}, arg1={:08X}, "
      "arg2={:08X}",
      app_id(), message, buffer_ptr, buffer_length);
  return X_E_FAIL;
}

}  // namespace apps
}  // namespace xam
}  // namespace kernel
}  // namespace rex
