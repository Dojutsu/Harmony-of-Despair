// Exercise the real kernel export and physical alias that faulted in the title.
// A separate process owns its Runtime; the shared unit Memory cannot coexist
// with another Runtime's 4.5 GiB guest arena.
#include <rex/graphics/xenos.h>
#include <rex/hook.h>
#include <rex/logging.h>
#include <rex/memory.h>
#include <rex/platform/exceptions.h>
#include <rex/platform/guest_memory.h>
#include <rex/runtime.h>
#include <rex/system/thread_state.h>
#include <rex/system/xmemory.h>

#include <array>
#include <cstring>
#include <iostream>
#include <stdexcept>

extern "C" void __imp__VdSwap(PPCContext&, uint8_t*);

namespace {
constexpr uint32_t kAllocation = 0xBFBB0000;
constexpr uint32_t kRing = 0xBFBB5774;
constexpr uint32_t kFrontbuffer = kAllocation + 0x1000;
constexpr size_t kPacketBytes = 256;
unsigned checks = 0;

void Check(bool condition, const char* message) {
  ++checks;
  if (!condition) throw std::runtime_error(message);
}

struct Binding {
  rex::runtime::ThreadState* prior = rex::runtime::ThreadState::Get();
  rex::runtime::ThreadState thread;
  explicit Binding(rex::memory::Memory& memory) : thread(92, 0, 0, &memory) {
    rex::runtime::ThreadState::Bind(&thread);
  }
  ~Binding() { rex::runtime::ThreadState::Bind(prior); }
};

struct Watch {
  uint32_t physical = 0;
  unsigned notifications = 0;
  bool normal_context = true;
  bool correct_range = true;
};

std::pair<uint32_t, uint32_t> Invalidate(void* context, uint32_t start,
                                        uint32_t length, bool exact) {
  auto& watch = *static_cast<Watch*>(context);
  auto* activation = rex::guest::ExecutionActivation::Current();
  watch.normal_context &= activation &&
      activation->phase() == rex::guest::ActivationPhase::Adjudicating &&
      !rex::guest::HasArmedAccessFrame();
  watch.correct_range &= start <= watch.physical &&
      uint64_t(watch.physical) < uint64_t(start) + length && !exact;
  ++watch.notifications;
  return {start, length};
}

struct Registration {
  rex::memory::Memory& memory;
  void* handle;
  ~Registration() { memory.UnregisterPhysicalMemoryInvalidationCallback(handle); }
};

struct Allocation {
  rex::memory::BaseHeap* heap;
  uint32_t address;
  ~Allocation() { if (address) heap->Release(address); }
};

uint32_t ReadBigEndian(const uint8_t* bytes) {
  return uint32_t(bytes[0]) << 24 | uint32_t(bytes[1]) << 16 |
      uint32_t(bytes[2]) << 8 | bytes[3];
}

void Run(rex::memory::Memory& memory) {
  Binding binding(memory);
  rex::guest::ExecutionActivation activation;
  auto* heap = memory.LookupHeap(kAllocation);
  Check(heap != nullptr, "physical alias heap unavailable");
  Check(heap->AllocFixed(kAllocation, 65536, 65536,
      rex::memory::kMemoryAllocationReserve | rex::memory::kMemoryAllocationCommit,
      rex::memory::kMemoryProtectRead | rex::memory::kMemoryProtectWrite |
          rex::memory::kMemoryProtectWriteCombine), "fixed title physical alias allocation");
  Allocation physical{heap, kAllocation};
  const auto argument_address = memory.SystemHeapAlloc(4096);
  Check(argument_address != 0, "kernel argument and stack allocation");
  Allocation arguments{memory.LookupHeap(argument_address), argument_address};
  auto* input = memory.TranslateVirtual<rex::be_u32*>(argument_address);
  auto* ring = memory.TranslateVirtual<uint8_t*>(kRing);
  const auto frontbuffer_physical = memory.GetPhysicalAddress(kFrontbuffer);
  Check(frontbuffer_physical == 0x1FBB1000, "physical alias frontbuffer translation");
  Watch watch{memory.GetPhysicalAddress(kRing)};
  Check(watch.physical == 0x1FBB5774, "exact title ring physical translation");
  Registration registration{memory,
      memory.RegisterPhysicalMemoryInvalidationCallback(Invalidate, &watch)};
  Check(registration.handle != nullptr, "physical write-watch callback registration");

  // Calling the production PPC export includes pointer and stack marshalling,
  // then the actual VdSwap_entry implementation in the linked runtime.
  rex::ppc::ImportFunction<void(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32)>
      swap{__imp__VdSwap};
  PPCContext context{};
  context.r1.u32 = argument_address + 2048;
  auto call = [&](uint32_t destination) {
    swap(context, memory.virtual_membase(), destination, argument_address,
        0, 0, 0, argument_address + 32, argument_address + 36,
        argument_address + 40, argument_address + 44, argument_address + 48);
  };

  std::array<uint8_t, 16> prefix, suffix;
  prefix.fill(0xA5);
  suffix.fill(0x5A);
  std::memcpy(ring - prefix.size(), prefix.data(), prefix.size());
  std::memcpy(ring + kPacketBytes, suffix.data(), suffix.size());
  for (unsigned epoch = 0; epoch < 3; ++epoch) {
    const uint32_t width = 1280 - epoch * 160;
    const uint32_t height = 720 - epoch * 90;
    rex::graphics::xenos::xe_gpu_texture_fetch_t fetch{};
    fetch.dword_0 = 0x12340002;
    fetch.dword_1 = kFrontbuffer | uint32_t(rex::graphics::xenos::TextureFormat::k_8_8_8_8);
    fetch.size_2d.width = width - 1;
    fetch.size_2d.height = height - 1;
    fetch.dword_3 = 0x11223344 + epoch;
    fetch.dword_4 = 0x55667788;
    fetch.dword_5 = 0x99AABBCC;
    const std::array<uint32_t, 6> fetch_words{fetch.dword_0, fetch.dword_1,
        fetch.dword_2, fetch.dword_3, fetch.dword_4, fetch.dword_5};
    for (unsigned index = 0; index < fetch_words.size(); ++index) input[index] = fetch_words[index];
    input[8] = kFrontbuffer;
    input[9] = uint32_t(rex::graphics::xenos::TextureFormat::k_8_8_8_8);
    input[10] = 0;
    input[11] = width;
    input[12] = height;
    const auto before = watch.notifications;
    memory.EnablePhysicalMemoryAccessCallbacks(watch.physical & ~4095u, 4096, true, false);
    rex::memory::PageAccess access{};
    size_t length = 4096;
    Check(rex::memory::QueryProtect(ring, length, access) &&
        access == rex::memory::PageAccess::kReadOnly, "GPU watch really protects destination");
    call(kRing);
    Check(watch.notifications == before + 1, "one callback for complete packet publication");
    Check(watch.normal_context && watch.correct_range, "watch callback is normal, disarmed adjudication");
    Check(!rex::guest::HasArmedAccessFrame() && !activation.HasPendingFault() &&
        activation.phase() == rex::guest::ActivationPhase::Running,
        "kernel export leaves no live access frame or pending fault");
    // Independent fixed PM4 words check layout and endian bytes, including all
    // untouched fetch components, translated base, dimensions and 52 NOPs.
    std::array<uint32_t, 64> expected{};
    expected.fill(0x80000000);
    expected[0] = 0x00054800;
    for (unsigned index = 0; index < fetch_words.size(); ++index) expected[index + 1] = fetch_words[index];
    expected[2] = (fetch_words[1] & 0xFFF) | frontbuffer_physical;
    expected[7] = 0xC0036400;
    expected[8] = 0x53574150;
    expected[9] = frontbuffer_physical;
    expected[10] = width;
    expected[11] = height;
    for (unsigned index = 0; index < expected.size(); ++index)
      Check(ReadBigEndian(ring + index * 4) == expected[index], "complete big-endian swap packet word");
    Check(std::memcmp(ring - prefix.size(), prefix.data(), prefix.size()) == 0,
        "packet prefix sentinel unchanged");
    Check(std::memcmp(ring + kPacketBytes, suffix.data(), suffix.size()) == 0,
        "packet suffix sentinel unchanged");
    Check(std::memcmp(input, fetch_words.data(), sizeof(fetch_words)) != 0,
        "fetch arguments retain guest endian representation");
    for (unsigned index = 0; index < fetch_words.size(); ++index)
      Check(uint32_t(input[index]) == fetch_words[index], "caller fetch remains unchanged");
    rex::guest::Write<uint8_t>(ring + 1024, uint8_t(0x40 + epoch));
    Check(ring[1024] == 0x40 + epoch && watch.notifications == before + 1,
        "subsequent same-page write succeeds without duplicate callback");
  }

  bool delivered = false;
  const auto before = watch.notifications;
  const auto invalid_address = memory.SystemHeapAlloc(4096);
  Check(invalid_address != 0, "dedicated rejected destination allocation");
  auto* invalid_heap = memory.LookupHeap(invalid_address);
  Allocation invalid{invalid_heap, invalid_address};
  auto* invalid_pointer = memory.TranslateVirtual<uint8_t*>(invalid_address);
  std::array<uint8_t, kPacketBytes> rejected_before{};
  rejected_before.fill(0xD3);
  std::memcpy(invalid_pointer, rejected_before.data(), rejected_before.size());
  // Unallocated virtual heap addresses can still have a writable host VMA.
  // Establish and verify a genuinely inaccessible destination for this case.
  Check(invalid_heap->Protect(invalid_address, 4096, rex::memory::kMemoryProtectNoAccess),
      "dedicated rejected destination protection");
  rex::memory::PageAccess invalid_access{};
  size_t invalid_length = 4096;
  Check(rex::memory::QueryProtect(invalid_pointer, invalid_length, invalid_access) &&
      invalid_access == rex::memory::PageAccess::kNoAccess,
      "rejected destination is actually inaccessible");
  try {
    call(invalid_address);
  } catch (const rex::SehException& exception) {
    delivered = true;
    Check(exception.code() == rex::SehException::ACCESS_VIOLATION &&
        exception.address() == reinterpret_cast<uintptr_t>(invalid_pointer),
        "inaccessible destination forwards a guest access violation");
  }
  Check(delivered, "invalid ring pointer did not silently succeed");
  Check(watch.notifications == before && !activation.HasPendingFault() &&
      !rex::guest::HasArmedAccessFrame() && activation.published_faults() == 1 &&
      activation.consumed_faults() == 1, "terminal fault is consumed once without GPU callback");
  Check(invalid_heap->Protect(invalid_address, 4096,
      rex::memory::kMemoryProtectRead | rex::memory::kMemoryProtectWrite),
      "rejected destination protection restored");
  Check(std::memcmp(invalid_pointer, rejected_before.data(), rejected_before.size()) == 0,
      "rejected destination remains unchanged");
  std::cout << "VdSwap actual export: exact BFBB5774 physical watch, three epochs, "
      "complete 64-word BE packets, sentinels, subsequent writes and guest fault PASS ("
      << checks << " checks)\n";
  std::cout << "{\"checks\":" << checks
      << ",\"failures\":0,\"physical_alias\":\"BFBB5774\",\"epochs\":3}\n";
}
}  // namespace

int main() {
  try {
    rex::InitLogging();
    rex::Runtime runtime("");
    rex::RuntimeConfig config;
    config.tool_mode = true;
    Check(runtime.Setup(std::move(config)) == 0, "native runtime setup");
    Check(runtime.memory() != nullptr, "native runtime memory unavailable");
    Run(*runtime.memory());
    runtime.Shutdown();
    return 0;
  } catch (const std::exception& exception) {
    std::cerr << "VdSwap regression: " << exception.what() << '\n';
    return 1;
  }
}
