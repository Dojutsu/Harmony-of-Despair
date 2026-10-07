// Capture-only submission ownership. Ordinary presentation is unaffected.
#pragma once

#include <cstdint>
#include <exception>
#include <memory>
#include <mutex>
#include <utility>

#include <rex/ui/vulkan/device.h>

namespace rex::ui::vulkan {

// The command buffer is owned by command_pool. Keep the source image reference
// alongside every handle referenced by submitted work, including its fence.
class VulkanCaptureSubmission {
 public:
  VulkanCaptureSubmission(VkDevice device, const VulkanDevice::Functions& functions,
                          std::shared_ptr<void> source_image)
      : device_(device), functions_(functions), source_image_(std::move(source_image)) {}
  VulkanCaptureSubmission(const VulkanCaptureSubmission&) = delete;
  VulkanCaptureSubmission& operator=(const VulkanCaptureSubmission&) = delete;

  ~VulkanCaptureSubmission() {
    // A timeout is not completion. Never destroy in-flight resources even if an
    // ownership programming error would otherwise reach this destructor.
    if (pending_) {
      std::terminate();
    }
    if (command_pool != VK_NULL_HANDLE) {
      functions_.vkDestroyCommandPool(device_, command_pool, nullptr);
    }
    if (buffer != VK_NULL_HANDLE) {
      functions_.vkDestroyBuffer(device_, buffer, nullptr);
    }
    if (memory != VK_NULL_HANDLE) {
      functions_.vkFreeMemory(device_, memory, nullptr);
    }
    if (fence != VK_NULL_HANDLE) {
      functions_.vkDestroyFence(device_, fence, nullptr);
    }
  }

  void MarkSubmitted() {
    if (pending_ || fence == VK_NULL_HANDLE) {
      std::terminate();
    }
    pending_ = true;
  }

  VkResult Wait(uint64_t timeout_ns) {
    if (!pending_) {
      return VK_SUCCESS;
    }
    VkResult result = functions_.vkWaitForFences(device_, 1, &fence, VK_TRUE, timeout_ns);
    // Vulkan Lost Device: for determining whether resources are in use,
    // VK_ERROR_DEVICE_LOST is equivalent to VK_SUCCESS. It is not permission to
    // read the now undefined contents of the download buffer.
    if (result == VK_SUCCESS || result == VK_ERROR_DEVICE_LOST) {
      pending_ = false;
    }
    return result;
  }

  bool pending() const { return pending_; }

  VkCommandPool command_pool = VK_NULL_HANDLE;
  VkCommandBuffer command_buffer = VK_NULL_HANDLE;
  VkBuffer buffer = VK_NULL_HANDLE;
  VkDeviceMemory memory = VK_NULL_HANDLE;
  VkFence fence = VK_NULL_HANDLE;

 private:
  VkDevice device_;
  const VulkanDevice::Functions& functions_;
  std::shared_ptr<void> source_image_;
  bool pending_ = false;
};

// Serialize captures per device and allow at most one unresolved readback.
// This state belongs to the device, so a capture thread and presenter can leave
// it behind without dropping the source image or any submitted Vulkan handle.
class VulkanCaptureState {
 public:
  ~VulkanCaptureState() { Shutdown(); }

  std::unique_lock<std::mutex> Acquire() { return std::unique_lock<std::mutex>(mutex_); }

  // Caller holds Acquire throughout capture. Never wait for a previous timeout.
  bool ReapCompleted() {
    if (device_lost_) {
      return false;
    }
    if (!pending_) {
      return true;
    }
    VkResult result = pending_->Wait(0);
    if (pending_->pending()) {
      return false;
    }
    pending_.reset();
    device_lost_ = result == VK_ERROR_DEVICE_LOST;
    return !device_lost_;
  }

  VkResult AwaitCapture(std::unique_ptr<VulkanCaptureSubmission>& submission) {
    if (pending_ || !submission || !submission->pending()) {
      std::terminate();
    }
    constexpr uint64_t kCaptureFenceWaitNs = 1000000000;
    VkResult result = submission->Wait(kCaptureFenceWaitNs);
    if (result != VK_SUCCESS) {
      if (submission->pending()) {
        Defer(std::move(submission));
      } else {
        DeviceLost();
      }
    }
    return result;
  }

  // Ownership is transferred before the capture worker returns on any wait
  // error, including timeout. No additional allocation is needed to retain it.
  void Defer(std::unique_ptr<VulkanCaptureSubmission> submission) {
    if (pending_ || !submission || !submission->pending()) {
      std::terminate();
    }
    pending_ = std::move(submission);
  }

  void DeviceLost() { device_lost_ = true; }

  // Called before vkDestroyDevice, after clients have stopped accessing it.
  // Device teardown still requires completion/device loss; there is no legal
  // bounded wait that permits destruction of pending Vulkan work. The capture
  // worker itself never calls this path or waits indefinitely.
  void Shutdown() {
    auto lock = Acquire();
    if (pending_) {
      pending_->Wait(UINT64_MAX);
      if (pending_->pending()) {
        std::terminate();
      }
      pending_.reset();
    }
  }

 private:
  std::mutex mutex_;
  std::unique_ptr<VulkanCaptureSubmission> pending_;
  bool device_lost_ = false;
};

}  // namespace rex::ui::vulkan
