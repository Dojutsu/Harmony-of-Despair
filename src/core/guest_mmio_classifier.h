#pragma once
#include <rex/system/mmio_handler.h>
namespace rex::guest::detail {
// Runtime-private friend bridge; it exposes no dynamic entry or cached pointer.
struct MappedAccessClassifier {
  static bool Classify(const runtime::MMIOHandler& handler, const void* address,
                       size_t width, uint32_t& point_guest_address,
                       bool& point_mapped) noexcept {
    return handler.ClassifyMappedAccess(address, width, &point_guest_address, &point_mapped);
  }
};
} // namespace rex::guest::detail
