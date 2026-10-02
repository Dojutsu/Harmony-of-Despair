#pragma once
/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2015 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

#include <rex/system/kernel_state.h>
#include <rex/system/xam/app_manager.h>
#include <rex/system/xam/session.h>

#include <functional>
#include <optional>

namespace rex::memory { class Memory; }

namespace rex {
namespace kernel {
namespace xam {
namespace apps {

using AcceptedInviteRecordProvider = std::function<
    std::optional<system::xam::AcceptedInviteStore::ReadLease>(uint32_t, uint32_t)>;
X_HRESULT DispatchAcceptedInviteGetInfo(
    memory::Memory* memory, uint32_t argument_list_ptr, uint32_t current_title_id,
    const AcceptedInviteRecordProvider& provider);

class XLiveBaseApp : public system::xam::App {
 public:
  explicit XLiveBaseApp(system::KernelState* kernel_state);

  X_HRESULT DispatchMessageSync(uint32_t message, uint32_t buffer_ptr,
                                uint32_t buffer_length) override;
};

}  // namespace apps
}  // namespace xam
}  // namespace kernel
}  // namespace rex
