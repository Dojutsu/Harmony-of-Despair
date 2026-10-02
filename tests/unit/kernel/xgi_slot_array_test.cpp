// Exercise the real XGI join dispatch against allocated guest memory.
#include <rex/runtime.h>
#include <rex/logging.h>
#include <rex/kernel/xam/apps/xgi_app.h>
#include <rex/system/xam/session.h>
#include <array>
#include <iostream>
#include <stdexcept>

using namespace rex;
using namespace rex::system;
using namespace rex::system::xam;
static void Check(bool value, const char* message) {
  if (!value) throw std::runtime_error(message);
}

static void Run(KernelState* kernel) {
  auto* mem = kernel->memory();
  const uint32_t guest = mem->SystemHeapAlloc(16384);
  Check(guest != 0, "guest allocation");
  auto put = [&](uint32_t offset, uint32_t value) {
    memory::store_and_swap<uint32_t>(mem->TranslateVirtual(guest + offset), value);
  };
  auto object = make_object<XSession>(kernel);
  Check(object->Initialize(), "session object");
  auto& registry = kernel->session_manager()->registry();
  const uint64_t host = kernel->user_profile()->xuid();
  auto reset = [&] {
    if (object->record()) registry.Delete(object->record()->info.id);
    object->set_record(registry.Create(host, "Host", {}, 1, 4, 2));
  };
  kernel::xam::apps::XgiApp app(kernel);
  auto join = [&](uint32_t count, uint32_t xuids, uint32_t users, uint32_t flags) {
    put(0, object->guest_object()); put(4, count); put(8, xuids);
    put(12, users); put(16, flags);
    return app.DispatchMessageSync(0x000B0012, guest, 20);
  };
  const std::array<uint64_t, 2> ids{0x1122334455667788ull, 0x8877665544332211ull};
  for (size_t i = 0; i < ids.size(); ++i)
    memory::store_and_swap<uint64_t>(mem->TranslateVirtual(guest + 64 + 8*i), ids[i]);
  const std::array<std::array<uint32_t, 2>, 6> values{{{0,0},{1,0},{0,1},{1,0},{1,1},{0,0}}};
  for (size_t test = 0; test < values.size(); ++test) {
    reset();
    const uint32_t count = test < 2 ? 1 : 2;
    for (uint32_t i = 0; i < count; ++i) put(96 + 4*i, values[test][i]);
    Check(join(count, guest + 64, 0, guest + 96) == X_E_SUCCESS, "remote join");
    auto record = object->record();
    Check(record->members.size() == count + 1, "exact member count");
    Check(record->host_xuid == host, "host identity");
    for (uint32_t i = 0; i < count; ++i) {
      const auto& member = record->members[i+1];
      Check(member.xuid == ids[i], "BE64 XUID stride eight");
      Check(member.private_slot == (values[test][i] != 0), "BE32 private flag stride four");
      Check(!member.local && member.user_index == UINT32_MAX, "remote metadata");
    }
  }
  reset();
  Check(join(2, guest+64, 0, 0) == X_E_SUCCESS, "null flags join");
  Check(!object->record()->members[1].private_slot &&
        !object->record()->members[2].private_slot, "null flags false");
  reset();
  put(112, 0x01020304); put(116, 0x10203040);
  put(96, 0); put(100, 1);
  Check(join(2, 0, guest+112, guest+96) == X_E_INVALIDARG, "duplicate local XUID batch rejected");
  Check(object->record()->members.size() == 1 && !object->record()->members[0].private_slot,
        "duplicate local batch has no partial mutation");
  for (uint32_t i = 0; i < 2; ++i) {
    Check(join(1, 0, guest+112+4*i, guest+96+4*i) == X_E_SUCCESS, "local single join");
    const auto& local = object->record()->members[0];
    Check(local.xuid == host && local.local &&
          local.user_index == (i ? 0x10203040u : 0x01020304u) && local.private_slot == (i != 0),
          "BE32 local index and private flag");
  }
  reset();
  Check(kernel->session_manager()->registry().Modify(object->record()->info.id, 1, 2, 2),
        "one available public slot");
  put(96, 0); put(100, 0);
  Check(join(2, guest+64, 0, guest+96) == X_E_FAIL, "whole remote batch exceeds capacity");
  Check(object->record()->members.size() == 1, "XGI batch rolls back first member");
  memory::store_and_swap<uint64_t>(mem->TranslateVirtual(guest + 72), ids[0]);
  Check(join(2, guest+64, 0, guest+96) == X_E_INVALIDARG, "duplicate remote batch");
  Check(object->record()->members.size() == 1, "duplicate remote has no partial mutation");
  memory::store_and_swap<uint64_t>(mem->TranslateVirtual(guest + 72), ids[1]);

  reset();
  auto reject = [&](uint32_t count, uint32_t xuids, uint32_t users, uint32_t flags) {
    Check(join(count, xuids, users, flags) == X_E_INVALIDARG, "malformed array rejected");
    Check(object->record()->members.size() == 1, "no partial admission");
  };
  reject(UINT32_MAX, guest+64, 0, guest+96);
  reject(0x40000000, 0, 0, 0);
  reject(0x20000000, guest+64, 0, 0);
  reject(2, guest+64, 0, 0xfffffffc);
  reject(2, 0xfffffff8, 0, 0);
  reject(2, 0, 0xfffffffc, 0);
  reject(1, guest+64, 0, 1);
  // A readable first entry followed by a no-access page must be rejected
  // before even the first member is inserted.
  auto* heap = mem->LookupHeap(guest);
  const uint32_t page = heap->page_size();
  const uint32_t boundary = (guest + page - 1) / page * page + page;
  Check(heap->Protect(boundary, page, 0), "protect short buffer boundary");
  reject(2, guest+64, 0, boundary-4);
  reject(2, boundary-8, 0, 0);
  reject(2, 0, boundary-4, 0);
  Check(app.DispatchMessageSync(0x000B0012, boundary-4, 20) == X_E_INVALIDARG,
        "short message rejected");
  Check(heap->Protect(boundary, page, memory::kMemoryProtectRead | memory::kMemoryProtectWrite),
        "restore test page");
  Check(heap->Decommit(boundary, page), "decommit short buffer boundary");
  reject(2, guest+64, 0, boundary-4);
  object->set_record(nullptr);
  object->ReleaseHandle();
  object.reset();
  mem->SystemHeapFree(guest);
  std::cout << "PASS: six flag vectors, null, remote/local identity strides, malformed/short "
               "arrays and message, overflow, and no partial admission\n";
}
int main() {
  InitLogging();
  Runtime runtime("");
  RuntimeConfig config;
  config.tool_mode = true;
  if (runtime.Setup(std::move(config))) return 2;
  int result = 0;
  try { Run(runtime.kernel_state()); }
  catch (const std::exception& e) { std::cerr << e.what() << '\n'; result = 1; }
  runtime.Shutdown();
  return result;
}
