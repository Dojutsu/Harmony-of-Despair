// No GPU is required: exercise the production capture owner with fake Vulkan
// entry points. Failed/timed-out work must keep every submitted handle alive.
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <thread>
#include <vector>
#include <type_traits>

#include "ui/vulkan/capture_submission.h"

#if REX_PLATFORM_GNU_LINUX
#include <sys/wait.h>
#include <unistd.h>
#endif

namespace {
using rex::ui::vulkan::VulkanCaptureState;
using rex::ui::vulkan::VulkanCaptureSubmission;
using rex::ui::vulkan::VulkanDevice;

unsigned checks = 0;
std::vector<char> destroyed;
std::vector<uint64_t> waits;
VkResult wait_result = VK_SUCCESS;

void Check(bool value, const char* message) {
  ++checks;
  if (!value) {
    std::fprintf(stderr, "FAIL %s\n", message);
    std::exit(1);
  }
}

VKAPI_ATTR VkResult VKAPI_CALL Wait(VkDevice, uint32_t count, const VkFence* fences,
                                   VkBool32 all, uint64_t timeout) {
  Check(count == 1 && fences && *fences != VK_NULL_HANDLE && all == VK_TRUE,
        "valid capture fence wait");
  waits.push_back(timeout);
  return wait_result;
}
VKAPI_ATTR void VKAPI_CALL DestroyPool(VkDevice, VkCommandPool, const VkAllocationCallbacks*) {
  destroyed.push_back('P');
}
VKAPI_ATTR void VKAPI_CALL DestroyBuffer(VkDevice, VkBuffer, const VkAllocationCallbacks*) {
  destroyed.push_back('B');
}
VKAPI_ATTR void VKAPI_CALL FreeMemory(VkDevice, VkDeviceMemory, const VkAllocationCallbacks*) {
  destroyed.push_back('M');
}
VKAPI_ATTR void VKAPI_CALL DestroyFence(VkDevice, VkFence, const VkAllocationCallbacks*) {
  destroyed.push_back('F');
}

struct Image {
  ~Image() { destroyed.push_back('I'); }
};

VulkanDevice::Functions Functions() {
  VulkanDevice::Functions f;
  f.vkWaitForFences = Wait;
  f.vkDestroyCommandPool = DestroyPool;
  f.vkDestroyBuffer = DestroyBuffer;
  f.vkFreeMemory = FreeMemory;
  f.vkDestroyFence = DestroyFence;
  return f;
}

template <typename T>
T Handle(uintptr_t value) {
  if constexpr (std::is_pointer_v<T>) {
    return reinterpret_cast<T>(value);
  } else {
    return static_cast<T>(value);
  }
}

std::unique_ptr<VulkanCaptureSubmission> Submission(const VulkanDevice::Functions& functions,
                                                    bool submitted = true) {
  auto s = std::make_unique<VulkanCaptureSubmission>(
      Handle<VkDevice>(1), functions, std::make_shared<Image>());
  s->command_pool = Handle<VkCommandPool>(2);
  s->command_buffer = Handle<VkCommandBuffer>(3);
  s->buffer = Handle<VkBuffer>(4);
  s->memory = Handle<VkDeviceMemory>(5);
  s->fence = Handle<VkFence>(6);
  if (submitted) {
    s->MarkSubmitted();
  }
  return s;
}

void Reset() {
  destroyed.clear();
  waits.clear();
  wait_result = VK_SUCCESS;
}

void TimeoutAndLaterCompletion(const VulkanDevice::Functions& functions) {
  Reset();
  VulkanCaptureState state;
  auto lock = state.Acquire();
  Check(state.ReapCompleted(), "empty capture state admits capture");
  auto s = Submission(functions);
  wait_result = VK_TIMEOUT;
  Check(state.AwaitCapture(s) == VK_TIMEOUT, "bounded wait reports timeout");
  Check(!s, "timeout transfers ownership to device state");
  Check(waits == std::vector<uint64_t>{1000000000}, "one second capture deadline");
  Check(!s && destroyed.empty(), "deferred owner retains all handles and image");
  for (unsigned i = 0; i < 16; ++i) {
    Check(!state.ReapCompleted(), "unresolved capture refuses another allocation");
    Check(waits.back() == 0 && destroyed.empty(), "later attempt polls without freeing or waiting");
  }
  wait_result = VK_SUCCESS;
  Check(state.ReapCompleted(), "completed capture admits later capture");
  Check(destroyed == std::vector<char>{'P','B','M','F','I'}, "completed handles and image freed once");
  Check(state.ReapCompleted() && destroyed.size() == 5, "empty reap does not double free");
  lock.unlock();
  state.Shutdown();
  Check(destroyed.size() == 5 && waits.size() == 18, "shutdown of reaped state does not wait again");
}

void WaitErrorsRetain(const VulkanDevice::Functions& functions) {
  for (VkResult result : {VK_ERROR_OUT_OF_HOST_MEMORY, VK_ERROR_OUT_OF_DEVICE_MEMORY,
                         VK_ERROR_UNKNOWN, VK_TIMEOUT}) {
    Reset();
    VulkanCaptureState state;
    auto lock = state.Acquire();
    auto s = Submission(functions);
    wait_result = result;
    Check(state.AwaitCapture(s) == result && !s, "noncompletion error transfers ownership");
    Check(!state.ReapCompleted() && destroyed.empty(), "failed poll cannot free submitted resources");
    wait_result = VK_SUCCESS;
    lock.unlock();
    state.Shutdown();
    Check(waits.back() == UINT64_MAX, "only device teardown awaits retained work indefinitely");
    Check(destroyed == std::vector<char>{'P','B','M','F','I'}, "shutdown waits before destroying all resources");
    state.Shutdown();
    Check(destroyed.size() == 5, "shutdown is idempotent");
  }
}

void DeviceLoss(const VulkanDevice::Functions& functions) {
  Reset();
  auto s = Submission(functions);
  wait_result = VK_ERROR_DEVICE_LOST;
  Check(s->Wait(1000000000) == VK_ERROR_DEVICE_LOST && !s->pending(), "device loss permits destruction");
  s.reset();
  Check(destroyed == std::vector<char>{'P','B','M','F','I'}, "device lost resources destroyed once");

  Reset();
  VulkanCaptureState state;
  auto lock = state.Acquire();
  s = Submission(functions);
  wait_result = VK_TIMEOUT;
  Check(state.AwaitCapture(s) == VK_TIMEOUT && !s, "timed out capture transferred before device loss");
  wait_result = VK_ERROR_DEVICE_LOST;
  Check(!state.ReapCompleted(), "device lost deferred capture refuses subsequent capture");
  Check(destroyed == std::vector<char>{'P','B','M','F','I'}, "lost deferred capture releases references");
  size_t wait_count = waits.size();
  Check(!state.ReapCompleted() && waits.size() == wait_count, "lost state does not submit or poll again");
  lock.unlock();
  state.Shutdown();
}

void PartialAndUnsubmittedCleanup(const VulkanDevice::Functions& functions) {
  Reset();
  auto s = std::make_unique<VulkanCaptureSubmission>(
      Handle<VkDevice>(1), functions, std::make_shared<Image>());
  s.reset();
  Check(destroyed == std::vector<char>{'I'}, "preallocation failure only drops host image reference");
  Reset();
  s = Submission(functions, false);
  Check(s->Wait(1) == VK_SUCCESS && waits.empty(), "never wait on an unsubmitted fence");
  s.reset();
  Check(destroyed == std::vector<char>{'P','B','M','F','I'}, "failed recording or submission cleans resources");
  Reset();
  s = Submission(functions, false);
  s->command_pool = VK_NULL_HANDLE;
  s->fence = VK_NULL_HANDLE;
  s.reset();
  Check(destroyed == std::vector<char>{'B','M','I'}, "partial allocation failure skips null handles");
}

void TerminalOwnershipGuards(const VulkanDevice::Functions& functions) {
#if REX_PLATFORM_GNU_LINUX
  for (bool teardown_error : {false, true}) {
    Reset();
    pid_t child = fork();
    Check(child >= 0, "create isolated pending ownership child");
    if (child == 0) {
      std::set_terminate([] { _exit(destroyed.empty() ? 86 : 87); });
      auto s = Submission(functions);
      if (teardown_error) {
        VulkanCaptureState state;
        state.Defer(std::move(s));
        wait_result = VK_ERROR_OUT_OF_HOST_MEMORY;
        state.Shutdown();
      } else {
        s.reset();
      }
      _exit(97);
    }
    int status = 0;
    Check(waitpid(child, &status, 0) == child, "collect isolated ownership child");
    Check(WIFEXITED(status) && WEXITSTATUS(status) == 86,
          "unproved completion terminates before freeing any GPU resource");
  }
#endif
}

void SerializedCaptures() {
  Reset();
  VulkanCaptureState state;
  std::atomic<unsigned> inside{0}, entries{0}, overlaps{0};
  std::vector<std::thread> threads;
  for (unsigned t = 0; t < 4; ++t) {
    threads.emplace_back([&] {
      for (unsigned i = 0; i < 100; ++i) {
        auto lock = state.Acquire();
        if (inside.fetch_add(1) != 0) {
          overlaps.fetch_add(1);
        }
        entries.fetch_add(1);
        std::this_thread::yield();
        inside.fetch_sub(1);
      }
    });
  }
  for (auto& t : threads) {
    t.join();
  }
  Check(entries == 400 && overlaps == 0 && inside == 0, "capture owner access is serialized per device");
}
}  // namespace

int main() {
  auto functions = Functions();
  TimeoutAndLaterCompletion(functions);
  WaitErrorsRetain(functions);
  DeviceLoss(functions);
  PartialAndUnsubmittedCleanup(functions);
  SerializedCaptures();
  TerminalOwnershipGuards(functions);
  std::printf("PASS Vulkan capture lifetime all %u checks\n", checks);
  return 0;
}
