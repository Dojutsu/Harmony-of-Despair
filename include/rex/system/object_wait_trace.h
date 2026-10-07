#pragma once

#include <cstdint>
#include <string_view>

namespace rex::system {

// Opt-in, bounded observations of one guest handle. This does not inspect guest
// buffers or change wait semantics. Sequence numbers order observations, not
// operations performed inside the underlying native wait-handle mutex.
void TraceObjectWait(uint32_t handle, std::string_view operation, int64_t value1,
                     int64_t value2, uint32_t status, bool lifecycle = false);

}  // namespace rex::system
