#include <rex/kernel/xam/apps/xlivebase_app.h>
#include <rex/logging.h>
#include <rex/runtime.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xmemory.h>
#include <rex/system/xnotifylistener.h>

#include <array>
#include <cstring>
#include <iostream>
#include <stdexcept>

namespace {
using namespace rex::system::xam;
using rex::X_HRESULT;
using rex::X_RESULT;
using rex::X_STATUS;
using rex::kernel::xam::apps::DispatchAcceptedInviteGetInfo;

void Check(bool value, const char* message) {
  if (!value)
    throw std::runtime_error(message);
}

uint64_t Canonical(uint32_t address) {
  return uint64_t(int64_t(int32_t(address)));
}

void Run() {
  rex::InitLogging();
  rex::Runtime runtime("");
  rex::RuntimeConfig config;
  config.tool_mode = true;
  Check(runtime.Setup(std::move(config)) == 0, "runtime setup failed");
  auto* kernel = runtime.kernel_state();
  auto* memory = runtime.memory();
  Check(kernel && memory, "kernel memory unavailable");

  auto first = rex::system::object_ref<rex::system::XNotifyListener>(
      new rex::system::XNotifyListener(kernel));
  auto second = rex::system::object_ref<rex::system::XNotifyListener>(
      new rex::system::XNotifyListener(kernel));
  first->Initialize(0x2, 1);
  second->Initialize(0x2, 1);
  const auto first_handle = first->handle();
  const auto second_handle = second->handle();
  Check(kernel->CountNotifyListenersAccepting(kXnLiveInviteAccepted) == 2,
        "two live listeners were not selected");

  AcceptedInviteStore store;
  AcceptedInviteIdentity identity;
  identity.operation_token = 1;
  identity.title_generation = 1;
  identity.title_id = 0x58410A7A;
  identity.local_xuid = 0xB13E000000000001ull;
  identity.admission_lifecycle_token = 1;
  AcceptedInviteRecord expected{};
  for (size_t i = 0; i < expected.size(); ++i)
    expected[i] = uint8_t(i ^ 0xA6);
  Check(store.Publish(identity, expected), "record publication failed");

  auto* heap = memory->LookupHeap(0x80000000u);
  Check(heap != nullptr, "guest heap unavailable");
  const uint32_t page = heap->page_size();
  uint32_t allocation = 0;
  Check(heap->Alloc(page * 3, page,
                    rex::memory::kMemoryAllocationReserve |
                        rex::memory::kMemoryAllocationCommit,
                    rex::memory::kMemoryProtectRead |
                        rex::memory::kMemoryProtectWrite,
                    false, &allocation),
        "guest allocation failed");
  const uint32_t arguments = allocation;
  const uint32_t user = allocation + page;
  const uint32_t output = user + 16;
  auto* list = memory->TranslateVirtual(arguments);
  auto* out = memory->TranslateVirtual(output);
  std::memset(list, 0, 0x204);
  rex::memory::store_and_swap<uint32_t>(list, 4);
  rex::memory::store_and_swap<uint64_t>(list + 8, Canonical(user));
  rex::memory::store_and_swap<uint32_t>(list + 16, 4);
  rex::memory::store_and_swap<uint64_t>(list + 24, Canonical(output));
  rex::memory::store_and_swap<uint32_t>(list + 0x200, 2);
  rex::memory::store_and_swap<uint32_t>(memory->TranslateVirtual(user), 0);
  auto provider = [&](uint32_t local_user, uint32_t title_id) {
    return store.Acquire(local_user, title_id);
  };
  auto call = [&](uint32_t title = 0x58410A7A) {
    return DispatchAcceptedInviteGetInfo(memory, arguments, title, provider);
  };
  auto failure = [&](const char* name) {
    std::memset(out, 0x5A, expected.size());
    Check(call() != X_E_SUCCESS, name);
    for (size_t i = 0; i < expected.size(); ++i)
      Check(out[i] == 0x5A, "failure changed output");
  };

  Check(kernel->BroadcastNotificationIfAtLeast(kXnLiveInviteAccepted, 0, 2) == 2,
        "two-listener broadcast failed");
  for (auto* listener : {first.get(), second.get()}) {
    rex::system::XNotificationID id{};
    uint32_t data = UINT32_MAX;
    Check(listener->DequeueNotification(&id, &data) &&
              id == kXnLiveInviteAccepted && data == 0,
          "listener did not receive accepted event");
    std::memset(out, 0, expected.size());
    Check(call() == X_E_SUCCESS, "accepted ABI read failed");
    Check(std::memcmp(out, expected.data(), expected.size()) == 0,
          "listener read different bytes");
  }
  for (auto* listener : {second.get(), first.get()}) {
    (void)listener;
    Check(call() == X_E_SUCCESS, "reverse repeated read failed");
    Check(std::memcmp(out, expected.data(), expected.size()) == 0,
          "reverse repeated read changed bytes");
  }

  rex::memory::store_and_swap<uint32_t>(list + 0x200, 1);
  failure("bad descriptor count succeeded");
  rex::memory::store_and_swap<uint32_t>(list + 0x200, 2);
  rex::memory::store_and_swap<uint32_t>(list, 8);
  failure("bad first descriptor size succeeded");
  rex::memory::store_and_swap<uint32_t>(list, 4);
  rex::memory::store_and_swap<uint32_t>(list + 16, 8);
  failure("bad second descriptor size succeeded");
  rex::memory::store_and_swap<uint32_t>(list + 16, 4);
  Check(DispatchAcceptedInviteGetInfo(memory, 0, identity.title_id, provider) !=
            X_E_SUCCESS,
        "null descriptor pointer succeeded");
  rex::memory::store_and_swap<uint64_t>(list + 8, 0);
  failure("null user pointer succeeded");
  rex::memory::store_and_swap<uint64_t>(list + 8, Canonical(user));
  rex::memory::store_and_swap<uint64_t>(list + 24, 0);
  failure("null output pointer succeeded");
  rex::memory::store_and_swap<uint64_t>(list + 24, Canonical(output));
  rex::memory::store_and_swap<uint32_t>(memory->TranslateVirtual(user), 1);
  failure("bad local user succeeded");
  rex::memory::store_and_swap<uint32_t>(memory->TranslateVirtual(user), 0);
  std::memset(out, 0x5A, expected.size());
  Check(call(identity.title_id + 1) != X_E_SUCCESS,
        "stale title succeeded");
  for (size_t i = 0; i < expected.size(); ++i)
    Check(out[i] == 0x5A, "stale title changed output");
  // Diagnostic failure logging must leave the published record usable after
  // malformed or stale-title requests from either listener.
  std::memset(out, 0, expected.size());
  Check(call() == X_E_SUCCESS, "valid read failed after diagnostic failures");
  Check(std::memcmp(out, expected.data(), expected.size()) == 0,
        "diagnostic failures changed the published record");
  Check(store.Invalidate(identity), "invalidation failed");
  failure("missing accepted record succeeded");
  store.Close();
  failure("closed store read succeeded");

  Check(kernel->object_table()->ReleaseHandle(first_handle) ==
            X_STATUS_SUCCESS,
        "first listener close failed");
  Check(kernel->BroadcastNotificationIfAtLeast(kXnLiveInviteAccepted, 0, 2) == 0,
        "one listener incorrectly met two-listener gate");
  Check(kernel->BroadcastNotificationIfAtLeast(kXnLiveInviteAccepted, 0, 1) == 1,
        "main-menu listener did not receive accepted event");
  {
    rex::system::XNotificationID id{};
    uint32_t data = UINT32_MAX;
    Check(second->DequeueNotification(&id, &data) &&
              id == kXnLiveInviteAccepted && data == 0,
          "single live listener missed accepted event");
  }
  Check(kernel->object_table()->ReleaseHandle(second_handle) ==
            X_STATUS_SUCCESS,
        "second listener close failed");
  heap->Release(allocation, nullptr);
  runtime.Shutdown();
}
}  // namespace

int main() {
  try {
    Run();
    std::cout << "accepted 0x58023 ABI, two listeners, failures and output integrity passed\n";
    return 0;
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}
