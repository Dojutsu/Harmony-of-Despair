// Included privately by the actual adapter after its checked staging helpers.
// A bounded event-driven owner retains only host input; guest output is resolved
// anew under a short memory pin/lease at completion. No queue lock spans I/O.
#if REX_PLATFORM_GNU_LINUX
using PendingMemoryControl = memory::GuestMemoryAccessControl;
using PendingMemoryPin = memory::GuestMemoryAccessPin;
using PendingMemoryLease = memory::MappingAccessLease;
constexpr int kPendingSendFlags = MSG_DONTWAIT;
inline std::shared_ptr<PendingMemoryControl> PendingMemoryControlOf(KernelState* state) {
  return state->memory()->access_control();
}
#else
// Windows has no cooperative mapping gate. The kernel state owns Memory for
// the worker's lifetime (teardown joins the worker), so a pin carries the
// pointer only. Winsock has no per-call MSG_DONTWAIT; the datagram send below
// uses the socket's own mode.
struct PendingMemoryControl { memory::Memory* memory; };
struct PendingMemoryPin {
  explicit PendingMemoryPin(const std::shared_ptr<PendingMemoryControl>& control)
      : memory_(control ? control->memory : nullptr) {}
  memory::Memory* memory() const { return memory_; }
  memory::Memory* memory_;
};
struct PendingMemoryLease {};
constexpr int kPendingSendFlags = 0;
inline std::shared_ptr<PendingMemoryControl> PendingMemoryControlOf(KernelState* state) {
  return std::make_shared<PendingMemoryControl>(PendingMemoryControl{state->memory()});
}
#endif
struct PendingSocketSend {
  std::mutex mutex;
  object_ref<XSocket> socket;
  XSocket::NativeLease native;
  object_ref<XThread> owner;
  object_ref<XEvent> event;
  std::shared_ptr<PendingMemoryControl> memory_control;
  uint32_t socket_handle = 0, overlapped = 0, flags = 0;
  XWSAOVERLAPPED identity{};
  N_XSOCKADDR_IN destination{};
  bool has_destination = false, ready = false, complete = false;
  uint32_t error = 0, transferred = 0;
  uint64_t sequence = 0;
  size_t admitted_bytes = 0;
  std::vector<uint8_t> payload;
  std::chrono::steady_clock::time_point deadline, completed_at;
};
struct PendingSocketSendService {
  static constexpr size_t kMaximumOperations = 64;
  static constexpr size_t kMaximumPayloadBytes = 2 * 1024 * 1024;
  std::mutex mutex;
  std::condition_variable changed;
  std::unordered_map<uint32_t, std::shared_ptr<PendingSocketSend>> operations;
  bool accepting = true, stopping = false;
  uint64_t revision = 0, sequence = 0;
  std::thread worker;
  ~PendingSocketSendService() { if (worker.joinable()) worker.join(); }
};
std::mutex pending_send_services_mutex;
std::unordered_map<KernelState*, std::shared_ptr<PendingSocketSendService>> pending_send_services;

// Called with only the operation mutex. The saved event object prevents event
// handle reuse from redirecting completion; failed output checks never fault the
// host or overwrite another operation's changed OVERLAPPED identity.
bool CompletePendingSend(PendingSocketSend& op, uint32_t error, uint32_t transferred,
                         bool teardown = false) {
  if (op.complete) return true;
  op.ready = true; op.error = error; op.transferred = error ? 0 : transferred;
  // A worker must never wait for a guest's global/mapping gate while owning
  // the operation lock. A ready result remains owned and is retried, without
  // sending its datagram again. A querying guest can publish it recursively.
  auto global = std::unique_lock<std::recursive_mutex>(
      thread::global_critical_region::mutex(), std::try_to_lock);
  if (!teardown && !global.owns_lock()) return false;
  if (!teardown) {
    PendingMemoryPin pin(op.memory_control);
    if (auto* mem = pin.memory()) {
      PendingMemoryLease lease;
      auto* host = mem->TranslateVirtual(op.overlapped);
      XWSAOVERLAPPED now{};
      if (ReadSendGuest(mem, op.overlapped, host, &now, sizeof(now)) &&
          uint32_t(now.event_handle) == uint32_t(op.identity.event_handle) &&
          uint32_t(now.offset.low) == uint32_t(op.identity.offset.low) &&
          uint32_t(now.offset.high) == uint32_t(op.identity.offset.high) &&
          uint32_t(now.internal) == 0x103 &&
          SendGuestRange(mem, op.overlapped, 8, host, true)) {
        const std::array<be_u32, 2> result{
            be_u32(error == 995 ? 0xC0000120 : error ? 0xC0000001 : 0),
            be_u32(error ? 0 : transferred)};
        if (!WriteSendGuest(mem, op.overlapped, host, result.data(), sizeof(result))) error = kWsaFault;
      } else error = kWsaFault;
    } else error = 995;
  }
  op.error = error; op.transferred = error ? 0 : transferred; op.complete = true;
  op.completed_at = std::chrono::steady_clock::now();
  // Retain ownership until query/finite expiry. Dropping a last XThread or
  // socket reference under an operation mutex could enter a global destructor.
  if (op.event) op.event->Set(0, false);
  return true;
}
void RunPendingSends(const std::shared_ptr<PendingSocketSendService>& service) {
  using namespace std::chrono_literals;
  for (;;) {
    std::array<std::shared_ptr<PendingSocketSend>, PendingSocketSendService::kMaximumOperations> slots{};
    size_t count = 0;
    uint64_t observed;
    {
      std::unique_lock lock(service->mutex);
      if (service->stopping) return;
      if (service->operations.empty()) {
        service->changed.wait(lock, [&] { return service->stopping || !service->operations.empty(); });
        if (service->stopping) return;
      }
      observed = service->revision;
      for (auto& [_, op] : service->operations) slots[count++] = op;
    }
    auto work = std::span(slots).first(count);
    std::sort(work.begin(), work.end(), [](const auto& a, const auto& b) { return a->sequence < b->sequence; });
    std::array<XSocket*, PendingSocketSendService::kMaximumOperations> blocked{};
    size_t blocked_count = 0;
    bool active = false;
    for (auto& op : work) {
      std::lock_guard operation_lock(op->mutex);
      if (op->complete) continue;
      active = true;
      if (op->ready) {
        CompletePendingSend(*op, op->error, op->transferred);
      } else if (op->native.retired() || !op->owner || !op->owner->is_running()) {
        CompletePendingSend(*op, 995, 0);
      } else if (std::chrono::steady_clock::now() >= op->deadline) {
        CompletePendingSend(*op, 10060, 0);
      } else if (std::find(blocked.begin(), blocked.begin() + blocked_count, op->socket.get()) == blocked.begin() + blocked_count) {
        // A per-call nonblocking flag preserves the guest socket's mode. The
        // original native lease remains pinned, and XSocket repeats all current
        // authorization/route/encryption checks. A closed incarnation cannot
        // fall through to an unscoped/reused descriptor.
        int sent = -1;
        uint32_t error = 0;
        try {
          sent = op->socket->SendTo(op->payload.data(), uint32_t(op->payload.size()),
              op->flags | kPendingSendFlags, op->has_destination ? &op->destination : nullptr,
              op->has_destination ? sizeof(N_XSOCKADDR_IN) : 0);
          error = sent < 0 ? LastSocketError() : 0;
        } catch (const std::bad_alloc&) { error = kWsaNoBuffers; }
          catch (const std::system_error&) { error = kWsaNoBuffers; }
        if (op->native.retired()) CompletePendingSend(*op, 995, 0);
        else if (sent >= 0) CompletePendingSend(*op, 0, uint32_t(sent));
        else if (error != 10035 && error != 10004) CompletePendingSend(*op, error, 0);
        else blocked[blocked_count++] = op->socket.get();
      }
      if (op->complete) service->changed.notify_all();
    }
    // Completed outcomes retain the exact socket identity until query, bounded
    // by the same 64-operation admission cap and a finite retention interval.
    for (auto& op : work) {
      bool expire;
      { std::lock_guard lock(op->mutex);
        expire = op->complete && std::chrono::steady_clock::now() - op->completed_at >= 60s; }
      if (expire) {
        std::lock_guard lock(service->mutex);
        auto it = service->operations.find(op->overlapped);
        if (it != service->operations.end() && it->second == op) service->operations.erase(it);
      }
    }
    std::unique_lock lock(service->mutex);
    service->changed.wait_for(lock, active ? 10ms : 1s,
        [&] { return service->stopping || service->revision != observed; });
  }
}
std::shared_ptr<PendingSocketSendService> FindPendingSendService(KernelState* state, bool create = false) {
  std::lock_guard lock(pending_send_services_mutex);
  auto it = pending_send_services.find(state);
  if (it != pending_send_services.end()) return it->second;
  if (!create || state->is_terminating_title()) return {};
  auto service = std::make_shared<PendingSocketSendService>();
  pending_send_services.emplace(state, service);
  try { service->worker = std::thread([service] { RunPendingSends(service); }); }
  catch (...) { pending_send_services.erase(state); throw; }
  return service;
}
bool PendingSendExists(KernelState* state, uint32_t address) {
  auto service = FindPendingSendService(state);
  if (!service) return false;
  std::lock_guard lock(service->mutex);
  return service->operations.contains(address);
}
uint32_t QueuePendingSend(KernelState* state, uint32_t handle, object_ref<XSocket> socket,
    const XSocket::NativeLease& native, std::vector<uint8_t> payload, uint32_t flags,
    const N_XSOCKADDR_IN* destination, uint32_t address, const XWSAOVERLAPPED& identity) {
  if (!runtime::ThreadState::Get() || !XThread::IsInThread()) return 10022;
  auto op = std::make_shared<PendingSocketSend>();
  op->owner = retain_object(XThread::GetCurrentThread());
  op->socket = std::move(socket); op->native = native;
  op->memory_control = PendingMemoryControlOf(state);
  op->socket_handle = handle; op->overlapped = address; op->identity = identity;
  op->flags = flags; op->payload = std::move(payload); op->admitted_bytes = op->payload.size();
  op->has_destination = destination != nullptr; if (destination) op->destination = *destination;
  op->deadline = std::chrono::steady_clock::now() + std::chrono::seconds(5);
  if (identity.event_handle) {
    op->event = state->object_table()->LookupObject<XEvent>(identity.event_handle);
    if (!op->event) return 10022;
  }
  auto service = FindPendingSendService(state, true);
  if (!service) return 995;
  // The existing receive store and this queue share only this short admission
  // gate, so duplicate OVERLAPPED addresses cannot overwrite either operation.
  PendingMemoryPin pin(op->memory_control);
  auto* mem = pin.memory(); if (!mem) return 995;
  PendingMemoryLease mapping_gate;
  std::lock_guard receive_gate(pending_recv_mutex);
  std::lock_guard queue_gate(service->mutex);
  if (!service->accepting || native.retired() || !op->owner->is_running()) return 995;
  if (service->operations.size() >= service->kMaximumOperations) return kWsaNoBuffers;
  if (service->operations.contains(address) || pending_recvs.contains(address)) return 10022;
  size_t total = op->payload.size();
  for (auto& [_, existing] : service->operations) {
    // Payload accounting is immutable admission size, avoiding an operation lock
    // under the queue lock (the worker may be completing with that lock held).
    total += existing->admitted_bytes;
  }
  if (total > service->kMaximumPayloadBytes) return kWsaNoBuffers;
  {
    auto* host = mem->TranslateVirtual(address);
    XWSAOVERLAPPED now{};
    if (!ReadSendGuest(mem,address,host,&now,sizeof(now)) ||
        std::memcmp(&now,&identity,sizeof(now)) != 0 || !SendGuestRange(mem,address,8,host,true)) return kWsaFault;
    service->operations.emplace(address, op);
    const std::array<be_u32,2> status{be_u32(0x103),be_u32(0)};
    if (!WriteSendGuest(mem,address,host,status.data(),sizeof(status))) {
      service->operations.erase(address); return kWsaFault;
    }
    if (op->event) op->event->Reset();
  }
  op->sequence = ++service->sequence; ++service->revision;
  service->changed.notify_all();
  return 0;
}
bool QueryPendingSend(KernelState* state, uint32_t handle, uint32_t address,
    mapped_u32 bytes, bool wait, mapped_u32 flags, uint32_t* result) {
  auto service = FindPendingSendService(state); if (!service) return false;
  std::shared_ptr<PendingSocketSend> op;
  {
    std::lock_guard lock(service->mutex);
    auto it = service->operations.find(address); if (it == service->operations.end()) return false;
    op = it->second;
  }
  *result = 0;
  if (op->socket_handle != handle ||
      state->object_table()->LookupObject<XSocket>(handle).get() != op->socket.get()) { XThread::SetLastError(10022); return true; }
  for (;;) {
    std::unique_lock operation_lock(op->mutex);
    if (!op->complete && op->ready)
      CompletePendingSend(*op, op->error, op->transferred);
    if (!op->complete) {
      operation_lock.unlock();
      if (!wait) { XThread::SetLastError(996); return true; }
      std::unique_lock queue_lock(service->mutex);
      // Read completion with its own mutex while the queue gate protects only
      // the wait transition; the worker never acquires the queue gate while
      // holding an operation mutex.
      service->changed.wait_for(queue_lock,std::chrono::milliseconds(20));
      continue;
    }
    const auto error = op->error, transferred_count = op->transferred;
    operation_lock.unlock();
    if (error) XThread::SetLastError(error);
    else {
      PendingMemoryPin pin(op->memory_control);
      auto* mem=pin.memory();
      bool written=false;
      if (mem) {
        PendingMemoryLease lease;
        if (SendGuestRange(mem,bytes.guest_address(),4,bytes.host_address(),true) &&
            (!flags || SendGuestRange(mem,flags.guest_address(),4,flags.host_address(),true))) {
          const be_u32 transferred{transferred_count}, zero{0};
          written = WriteSendGuest(mem,bytes.guest_address(),bytes.host_address(),&transferred,4) &&
              (!flags || WriteSendGuest(mem,flags.guest_address(),flags.host_address(),&zero,4));
        }
      }
      if (!written) { XThread::SetLastError(kWsaFault); return true; }
      *result=1; XThread::SetLastError(0);
    }
    std::lock_guard lock(service->mutex);
    auto it=service->operations.find(address);
    if (it!=service->operations.end() && it->second==op) service->operations.erase(it);
    ++service->revision; service->changed.notify_all(); return true;
  }
}
