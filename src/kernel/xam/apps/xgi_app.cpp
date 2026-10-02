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

#include <algorithm>
#include <unordered_set>

#include <rex/kernel/xam/apps/xgi_app.h>
#include <rex/logging.h>
#include <rex/system/xam/session.h>
#include <rex/thread.h>

namespace rex {
namespace kernel {
namespace xam {
using namespace rex::system;
using namespace rex::system::xam;
namespace apps {

bool InitializeEmptyStatsReadResults(std::span<uint8_t> results) {
  constexpr size_t kStatsReadResultsHeaderSize = 8;
  if (results.size() < kStatsReadResultsHeaderSize) {
    return false;
  }
  std::fill(results.begin(), results.end(), uint8_t{0});
  return true;
}
using namespace rex::system;

namespace {
constexpr uint32_t kSessionCreateHost = 1;
constexpr uint32_t kInvalidUserIndex = 0xFFFFFFFFu;

bool ReadableJoinArray(memory::Memory* memory, uint32_t address, uint32_t count,
                       uint32_t width) {
  const uint64_t size = uint64_t{count} * width;
  if (!size || size > UINT32_MAX ||
      uint64_t{address} + size > (uint64_t{1} << 32))
    return false;
  auto* heap = memory->LookupHeap(address);
  if (!heap ||
      heap->QueryRangeAccess(address,
                             uint32_t(uint64_t{address} + size - 1)) ==
          memory::PageAccess::kNoAccess)
    return false;
  uint64_t cursor =
      address - (address - heap->heap_base()) % heap->page_size();
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

#pragma pack(push, 1)
struct GuestSessionInfo {
  uint8_t session_id[8];
  uint8_t host_address[36];
  uint8_t key[16];
};
struct GuestSearchResult {
  GuestSessionInfo info;
  rex::be<uint32_t> open_public_slots;
  rex::be<uint32_t> open_private_slots;
  rex::be<uint32_t> filled_public_slots;
  rex::be<uint32_t> filled_private_slots;
  rex::be<uint32_t> property_count;
  rex::be<uint32_t> context_count;
  rex::be<uint32_t> properties_ptr;
  rex::be<uint32_t> contexts_ptr;
};
struct GuestSearchHeader {
  rex::be<uint32_t> result_count;
  rex::be<uint32_t> results_ptr;
};
struct GuestSessionMember {
  rex::be<uint64_t> xuid;
  rex::be<uint32_t> user_index;
  rex::be<uint32_t> flags;
};
struct GuestSessionDetails {
  rex::be<uint32_t> host_user_index;
  rex::be<uint32_t> game_type;
  rex::be<uint32_t> game_mode;
  rex::be<uint32_t> flags;
  rex::be<uint32_t> max_public_slots;
  rex::be<uint32_t> max_private_slots;
  rex::be<uint32_t> available_public_slots;
  rex::be<uint32_t> available_private_slots;
  rex::be<uint32_t> actual_member_count;
  rex::be<uint32_t> returned_member_count;
  rex::be<uint32_t> state;
  rex::be<uint64_t> nonce;
  GuestSessionInfo info;
  uint8_t arbitration_id[8];
  rex::be<uint32_t> members_ptr;
};
#pragma pack(pop)
static_assert(sizeof(GuestSessionInfo) == 60);
static_assert(sizeof(GuestSearchResult) == 92);
static_assert(sizeof(GuestSessionDetails) == 124);
constexpr size_t kGuestUserPropertySize = 24;
constexpr size_t kGuestUserContextSize = 8;

void StoreSessionInfo(GuestSessionInfo* output, const SessionInfo& info) {
  std::memset(output, 0, sizeof(*output));
  std::memcpy(output->session_id, info.id.data(), info.id.size());
  std::memcpy(output->host_address + 0, &info.host_address.ipv4, sizeof(uint32_t));
  std::memcpy(output->host_address + 4, &info.host_address.ipv4, sizeof(uint32_t));
  memory::store_and_swap<uint16_t>(output->host_address + 8, info.host_address.port);
  std::memcpy(output->host_address + 10, info.ethernet_address.data(), 6);
  std::memcpy(output->host_address + 16, info.online_address.data(), 20);
  std::memcpy(output->key, info.key.data(), info.key.size());
}
SessionInfo LoadSessionInfo(const GuestSessionInfo* input) {
  SessionInfo info;
  std::memcpy(info.id.data(), input->session_id, info.id.size());
  std::memcpy(&info.host_address.ipv4, input->host_address + 0, sizeof(uint32_t));
  if (!info.host_address.ipv4)
    std::memcpy(&info.host_address.ipv4, input->host_address + 4, sizeof(uint32_t));
  info.host_address.port = memory::load_and_swap<uint16_t>(input->host_address + 8);
  std::memcpy(info.ethernet_address.data(), input->host_address + 10, 6);
  std::memcpy(info.online_address.data(), input->host_address + 16, 20);
  std::memcpy(info.key.data(), input->key, info.key.size());
  return info;
}
XSession* LookupSession(KernelState* state, uint32_t object_ptr) {
  return state->session_manager()->LookupObject(object_ptr);
}
X_HRESULT WriteSearchResults(KernelState* state, uint32_t output_ptr, uint32_t output_size,
                             uint32_t max_results, bool refresh_network,
                             const std::vector<std::array<uint8_t, 8>>* requested_ids = nullptr,
                             uint16_t property_count = 0, uint32_t properties_ptr = 0,
                             uint16_t context_count = 0, uint32_t contexts_ptr = 0) {
  auto* manager = state->session_manager();
  manager->discovery().SetTitleId(state->title_id());
  size_t discovered_count = 0;
  if (refresh_network) {
    // Entering search is a transition out of the local host flow. Tear down
    // any abandoned advertisement before broadcasting so this instance can't
    // rediscover (or continue advertising) its former lobby.
    if (manager->discovery().IsAdvertising()) {
      manager->discovery().StopAdvertising();
      manager->registry().DeleteHostedBy(state->user_profile()->xuid());
    }
    auto discovered = manager->discovery().Search(250, max_results);
    discovered_count = discovered.size();
    for (auto& found : discovered)
      manager->registry().UpsertDiscovered(std::move(found));
  }
  // The configured XUID is the logical local-host identity. Filtering by it
  // also excludes the same session rediscovered through loopback or a second
  // adapter without conflating unrelated remote sessions.
  auto sessions = manager->registry().ListRemote(state->user_profile()->xuid());
  if (requested_ids) {
    std::erase_if(sessions, [&](const auto& session) {
      return std::find(requested_ids->begin(), requested_ids->end(), session->info.id) ==
             requested_ids->end();
    });
  }
  size_t count = std::min<size_t>(sessions.size(), max_results);
  if ((property_count && !properties_ptr) || (context_count && !contexts_ptr))
    return X_E_INVALIDARG;
  const size_t property_bytes = size_t(property_count) * kGuestUserPropertySize;
  const size_t context_bytes = size_t(context_count) * kGuestUserContextSize;
  std::vector<uint8_t> requested_properties(property_bytes);
  std::vector<uint8_t> requested_contexts(context_bytes);
  if (property_bytes) {
    std::memcpy(requested_properties.data(), state->memory()->TranslateVirtual(properties_ptr),
                property_bytes);
  }
  if (context_bytes) {
    std::memcpy(requested_contexts.data(), state->memory()->TranslateVirtual(contexts_ptr),
                context_bytes);
  }
  const size_t metadata_bytes_per_result = property_bytes + context_bytes;
  size_t required = sizeof(GuestSearchHeader) + count * sizeof(GuestSearchResult) +
                    count * metadata_bytes_per_result;
  REXKRNL_INFO(
      "XSession search results: discovered={} remote={} selected={} max={} output={:08X} "
      "size={} required={}",
      discovered_count, sessions.size(), count, max_results, output_ptr, output_size, required);
  if (!output_ptr || output_size < required) {
    REXKRNL_INFO("XSession search results rejected: insufficient buffer");
    return X_ERROR_INSUFFICIENT_BUFFER;
  }
  auto* header = state->memory()->TranslateVirtual<GuestSearchHeader*>(output_ptr);
  auto* results =
      state->memory()->TranslateVirtual<GuestSearchResult*>(output_ptr + sizeof(GuestSearchHeader));
  std::memset(header, 0, required);
  header->result_count = uint32_t(count);
  header->results_ptr = output_ptr + sizeof(GuestSearchHeader);
  uint32_t metadata_ptr =
      output_ptr + uint32_t(sizeof(GuestSearchHeader) + count * sizeof(GuestSearchResult));
  for (size_t i = 0; i < count; ++i) {
    std::lock_guard session_lock(*sessions[i]->mutex);
    StoreSessionInfo(&results[i].info, sessions[i]->info);
    results[i].open_public_slots = sessions[i]->OpenPublicSlots();
    results[i].open_private_slots = sessions[i]->OpenPrivateSlots();
    results[i].filled_public_slots = sessions[i]->FilledPublicSlots();
    results[i].filled_private_slots = sessions[i]->FilledPrivateSlots();
    results[i].property_count = property_count;
    results[i].context_count = context_count;
    if (property_bytes) {
      results[i].properties_ptr = metadata_ptr;
      std::memcpy(state->memory()->TranslateVirtual(metadata_ptr), requested_properties.data(),
                  property_bytes);
      metadata_ptr += uint32_t(property_bytes);
    }
    if (context_bytes) {
      results[i].contexts_ptr = metadata_ptr;
      std::memcpy(state->memory()->TranslateVirtual(metadata_ptr), requested_contexts.data(),
                  context_bytes);
      metadata_ptr += uint32_t(context_bytes);
    }
    REXKRNL_INFO(
        "XSession search result[{}]: host_xuid={:016X} address={:08X}:{} open_public={} "
        "filled_public={}",
        i, sessions[i]->host_xuid, sessions[i]->info.host_address.ipv4,
        sessions[i]->info.host_address.port, sessions[i]->OpenPublicSlots(),
        sessions[i]->FilledPublicSlots());
  }
  REXKRNL_INFO("XSession search results returned: count={} status={:08X}", count,
               uint32_t(X_E_SUCCESS));
  return X_E_SUCCESS;
}
}  // namespace

XgiApp::XgiApp(KernelState* kernel_state) : App(kernel_state, 0xFB) {}

// http://mb.mirage.org/bugzilla/xliveless/main.c

X_HRESULT XgiApp::DispatchMessageSync(uint32_t message, uint32_t buffer_ptr,
                                      uint32_t buffer_length) {
  // NOTE: buffer_length may be zero or valid.
  auto buffer = memory_->TranslateVirtual(buffer_ptr);
  switch (message) {
    case 0x000B0006: {
      assert_true(!buffer_length || buffer_length == 24);
      // dword r3 user index
      // dword (unwritten?)
      // qword 0
      // dword r4 context enum
      // dword r5 value
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t context_id = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t context_value = memory::load_and_swap<uint32_t>(buffer + 20);
      REXKRNL_DEBUG("XGIUserSetContextEx({:08X}, {:08X}, {:08X})", user_index, context_id,
                    context_value);
      REXKRNL_INFO("XGIUserSetContextEx: user={} id={:08X} value={:08X}", user_index,
                   context_id, context_value);
      return X_E_SUCCESS;
    }
    case 0x000B0007: {
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t property_id = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t value_size = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t value_ptr = memory::load_and_swap<uint32_t>(buffer + 24);
      REXKRNL_DEBUG("XGIUserSetPropertyEx({:08X}, {:08X}, {}, {:08X})", user_index, property_id,
                    value_size, value_ptr);
      REXKRNL_INFO("XGIUserSetPropertyEx: user={} id={:08X} size={} value={:08X}", user_index,
                   property_id, value_size, value_ptr);
      return X_E_SUCCESS;
    }
    case 0x000B0008: {
      // Raw dump so we can confirm the actual buffer layout the game sends.
      uint32_t raw0 = buffer_length >= 4 ? memory::load_and_swap<uint32_t>(buffer + 0) : 0;
      uint32_t raw4 = buffer_length >= 8 ? memory::load_and_swap<uint32_t>(buffer + 4) : 0;
      REXKRNL_INFO("XGIUserWriteAchievements called: buf_len={} raw[0]={:08X} raw[4]={:08X}",
                   buffer_length, raw0, raw4);

      assert_true(!buffer_length || buffer_length == 8);
      uint32_t achievement_count = raw0;
      uint32_t achievements_ptr = raw4;

      // Empirically confirmed from log: each entry is {u32 padding/user_index, u32 id, ...}.
      // The achievement ID sits at offset 4, not 0. Stride 8 covers the observed fields.
      constexpr uint32_t kEntryIdOffset = 4;
      constexpr uint32_t kEntryStride = 8;
      constexpr uint32_t kMaxAchievements = 1000;

      if (achievements_ptr && achievement_count > 0) {
        if (achievement_count > kMaxAchievements) {
          REXKRNL_WARN("XGIUserWriteAchievements: count={} unreasonable, ignoring",
                       achievement_count);
          return X_E_FAIL;
        }
        uint32_t span_end = achievements_ptr + achievement_count * kEntryStride - 1;
        if (!memory_->LookupHeap(achievements_ptr) || !memory_->LookupHeap(span_end)) {
          REXKRNL_WARN("XGIUserWriteAchievements: ptr {:08X} OOB", achievements_ptr);
          return X_E_FAIL;
        }
        auto* base = memory_->TranslateVirtual(achievements_ptr);
        for (uint32_t i = 0; i < achievement_count; ++i) {
          uint32_t id = memory::load_and_swap<uint32_t>(base + i * kEntryStride + kEntryIdOffset);
          REXKRNL_INFO("XGIUserWriteAchievements: id={} ({})", id, i);
          kernel_state_->UnlockAchievement(id);
        }
      } else {
        REXKRNL_INFO("XGIUserWriteAchievements: skipped (count={} ptr={:08X})", achievement_count,
                     achievements_ptr);
      }
      return X_E_SUCCESS;
    }
    case 0x000B0010: {
      assert_true(!buffer_length || buffer_length == 28);
      // Sequence:
      // - XamSessionCreateHandle
      // - XamSessionRefObjByHandle
      // - [this]
      // - CloseHandle
      uint32_t session_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t flags = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t num_slots_public = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t num_slots_private = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t session_info_ptr = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t nonce_ptr = memory::load_and_swap<uint32_t>(buffer + 24);

      REXKRNL_DEBUG(
          "XGISessionCreateImpl({:08X}, {:08X}, {}, {}, {:08X}, {:08X}, "
          "{:08X})",
          session_ptr, flags, num_slots_public, num_slots_private, user_index, session_info_ptr,
          nonce_ptr);
      auto* object = LookupSession(kernel_state_, session_ptr);
      if (!object || !session_info_ptr || !nonce_ptr || user_index != 0) {
        REXKRNL_ERROR(
            "XGISessionCreateImpl rejected arguments: object={} info={:08X} nonce={:08X} "
            "user={:08X}",
            object != nullptr, session_info_ptr, nonce_ptr, user_index);
        return X_E_INVALIDARG;
      }
      auto* profile = kernel_state_->user_profile();
      auto* guest_info = memory_->TranslateVirtual<GuestSessionInfo*>(session_info_ptr);
      auto& manager = *kernel_state_->session_manager();
      manager.discovery().SetTitleId(kernel_state_->title_id());
      std::shared_ptr<SessionRecord> session;
      if (flags & kSessionCreateHost) {
        LanAddress address{LanDiscoveryService::DetermineLanIpv4(), 3074};
        session = manager.registry().Create(profile->xuid(), profile->name(), address, flags,
                                            num_slots_public, num_slots_private);
        StoreSessionInfo(guest_info, session->info);
        if (!manager.discovery().Advertise(session)) {
          REXKRNL_ERROR("XGISessionCreateImpl: failed to advertise LAN session");
          manager.registry().Delete(session->info.id);
          return X_E_FAIL;
        }
      } else {
        auto info = LoadSessionInfo(guest_info);
        REXKRNL_INFO("INVITE_DIAG JOIN_BY_INFO_CALLED JOIN_BY_INFO_SESSION_ID={:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}",
                     info.id[0], info.id[1], info.id[2], info.id[3],
                     info.id[4], info.id[5], info.id[6], info.id[7]);
        REXKRNL_INFO("XGISessionCreateImpl: client session id={:02X}{:02X} host={:08X}:{}",
                     info.id[0], info.id[1], info.host_address.ipv4, info.host_address.port);
        session = manager.registry().Find(info.id);
        if (!session) {
          REXKRNL_WARN("INVITE_DIAG JOIN_BY_INFO_REGISTRY_NOT_FOUND");
          REXKRNL_ERROR("XGISessionCreateImpl: join-by-info session was not found");
          return X_E_NOTFOUND;
        }
        REXKRNL_INFO("INVITE_DIAG JOIN_BY_INFO_REGISTRY_FOUND");
      }
      object->set_record(session);
      memory::store_and_swap<uint64_t>(memory_->TranslateVirtual(nonce_ptr), session->nonce);
      return X_E_SUCCESS;
    }
    case 0x000B0011: {
      assert_true(!buffer_length || buffer_length == 16);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t flags = memory::load_and_swap<uint32_t>(buffer + 4);
      uint64_t session_nonce = memory::load_and_swap<uint64_t>(buffer + 8);

      REXKRNL_DEBUG("XGISessionDelete({:08X}, {:08X}, {:016X})", obj_ptr, flags, session_nonce);

      auto* object = LookupSession(kernel_state_, obj_ptr);
      if (!object || !object->record())
        return X_E_INVALIDARG;
      auto id = object->record()->info.id;
      if (object->record()->host_xuid == kernel_state_->user_profile()->xuid())
        kernel_state_->session_manager()->discovery().StopAdvertising();
      kernel_state_->session_manager()->registry().Delete(id);
      object->set_record(nullptr);
      return X_E_SUCCESS;
    }
    case 0x000B0012: {
      if ((buffer_length && buffer_length != 20) ||
          !ReadableJoinArray(memory_, buffer_ptr, 1, 20))
        return X_E_INVALIDARG;
      uint32_t session_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t user_count = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t xuid_array_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t user_index_array = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t private_slots_array = memory::load_and_swap<uint32_t>(buffer + 16);
      bool is_local = xuid_array_ptr == 0;

      REXKRNL_DEBUG("{}({:08X}, count={}, xuids={:08X}, users={:08X}, private={:08X})",
                    is_local ? "XGISessionJoinLocal" : "XGISessionJoinRemote", session_ptr,
                    user_count, xuid_array_ptr, user_index_array, private_slots_array);
      auto* object = LookupSession(kernel_state_, session_ptr);
      if (!object || !object->record() || !user_count)
        return X_E_INVALIDARG;
      if (user_count > UINT32_MAX / 4 ||
          (private_slots_array &&
           !ReadableJoinArray(memory_, private_slots_array, user_count, 4)) ||
          (!is_local &&
           !ReadableJoinArray(memory_, xuid_array_ptr, user_count, 8)) ||
          (is_local && user_index_array &&
           !ReadableJoinArray(memory_, user_index_array, user_count, 4)))
        return X_E_INVALIDARG;
      auto session = object->record();
      if (is_local && session->host_xuid != kernel_state_->user_profile()->xuid())
        REXKRNL_INFO("INVITE_DIAG XGI_JOIN_BEGIN xbox_session={:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X} members={}",
                     session->info.id[0], session->info.id[1],
                     session->info.id[2], session->info.id[3],
                     session->info.id[4], session->info.id[5],
                     session->info.id[6], session->info.id[7], user_count);
      std::vector<SessionMember> members;
      std::unordered_set<uint64_t> identities;
      for (uint32_t i = 0; i < user_count; ++i) {
        uint64_t xuid = is_local ? kernel_state_->user_profile()->xuid()
                                 : memory::load_and_swap<uint64_t>(
                                       memory_->TranslateVirtual(xuid_array_ptr + i * 8));
        uint32_t user_index = is_local && user_index_array
                                  ? memory::load_and_swap<uint32_t>(
                                        memory_->TranslateVirtual(user_index_array + i * 4))
                                  : kInvalidUserIndex;
        bool private_slot = private_slots_array &&
                            memory::load_and_swap<uint32_t>(memory_->TranslateVirtual(
                                private_slots_array + 4 * i)) != 0;
        if (is_local && session->host_xuid != kernel_state_->user_profile()->xuid())
          REXKRNL_INFO("INVITE_DIAG JOIN_BY_INFO_PRIVATE_REQUEST={} xuid={:016X}",
                       private_slot, xuid);
        SessionMember member{
            xuid,         is_local ? kernel_state_->user_profile()->name() : std::string{},
            user_index,   is_local,
            private_slot, false};
        if (!xuid || !identities.insert(xuid).second)
          return X_E_INVALIDARG;
        members.push_back(std::move(member));
      }
      if (!is_local ||
          session->host_xuid == kernel_state_->user_profile()->xuid())
        return kernel_state_->session_manager()->registry().JoinBatch(session,
                                                                       members)
                   ? X_E_SUCCESS
                   : X_E_FAIL;
      // One local profile maps to one XUID. Never turn a multi-user network
      // request into a partial sequence of host admissions.
      if (members.size() != 1)
        return X_E_INVALIDARG;
      const auto& member = members.front();
      const auto xuid = member.xuid;
      const auto user_index = member.user_index;
      REXKRNL_INFO(
          "XGISessionJoinLocal: requesting LAN join xuid={:016X} host={:016X}",
          xuid, session->host_xuid);
      auto updated = kernel_state_->session_manager()->discovery().Join(
          *session, member, 500);
      if (!updated) {
        REXKRNL_WARN("INVITE_DIAG XGI_JOIN_RESULT=FAIL_NETWORK_OR_HOST_ADMISSION private_request={}",
                     member.private_slot);
        return X_E_FAIL;
      }
      for (auto& updated_member : updated->members) {
        if (updated_member.xuid == xuid) {
          updated_member.local = true;
          updated_member.user_index = user_index;
          updated_member.name = kernel_state_->user_profile()->name();
        }
      }
      kernel_state_->session_manager()->registry().UpsertDiscovered(
          std::move(*updated));
      session = kernel_state_->session_manager()->registry().Find(session->info.id);
      object->set_record(session);
      REXKRNL_INFO(
          "GAMEPLAY_XGI_COMPLETION_CALL user={} local_xuid={:016X} host_xuid={:016X} "
          "session_present={}",
          user_index, xuid, session ? session->host_xuid : 0, session != nullptr);
      const bool gameplay_completion =
          kernel_state_->session_manager()->CompleteAcceptedInviteJoin(
              user_index, xuid, session);
      REXKRNL_INFO("GAMEPLAY_XGI_COMPLETION_RESULT success={} user={} local_xuid={:016X}",
                   gameplay_completion, user_index, xuid);
      REXKRNL_INFO("XGISessionJoinLocal: joined session with {} members",
                   session ? session->members.size() : 0);
      REXKRNL_INFO("INVITE_DIAG XGI_JOIN_RESULT=SUCCESS private_request={} members={}",
                   member.private_slot, session ? session->members.size() : 0);
      return X_E_SUCCESS;
    }
    case 0x000B0013: {
      assert_true(!buffer_length || buffer_length == 16);
      uint32_t session_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t user_count = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t xuid_array_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t user_index_array = memory::load_and_swap<uint32_t>(buffer + 12);
      bool is_local = xuid_array_ptr == 0;
      auto* object = LookupSession(kernel_state_, session_ptr);
      if (!object || !object->record())
        return X_E_INVALIDARG;
      auto session = object->record();
      for (uint32_t i = 0; i < user_count; ++i) {
        (void)user_index_array;
        uint64_t xuid = is_local ? kernel_state_->user_profile()->xuid()
                                 : memory::load_and_swap<uint64_t>(
                                       memory_->TranslateVirtual(xuid_array_ptr + i * 8));
        if (is_local && session->host_xuid != xuid) {
          auto updated = kernel_state_->session_manager()->discovery().Leave(*session, xuid, 500);
          if (updated) {
            kernel_state_->session_manager()->registry().UpsertDiscovered(std::move(*updated));
            session = kernel_state_->session_manager()->registry().Find(session->info.id);
            object->set_record(session);
          }
        }
        kernel_state_->session_manager()->registry().Leave(session->info.id, xuid);
      }
      return X_E_SUCCESS;
    }
    case 0x000B0014: {
      assert_true(!buffer_length || buffer_length == 16);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t flags = memory::load_and_swap<uint32_t>(buffer + 4);
      uint64_t session_nonce = memory::load_and_swap<uint64_t>(buffer + 8);

      REXKRNL_DEBUG("XSessionStart({:08X}, {:08X}, {:016X})", obj_ptr, flags, session_nonce);

      auto* object = LookupSession(kernel_state_, obj_ptr);
      return object && object->record() &&
                     kernel_state_->session_manager()->registry().Start(object->record()->info.id)
                 ? X_STATUS_SUCCESS
                 : X_E_INVALIDARG;
    }
    case 0x000B0015: {
      // send high scores?
      assert_true(!buffer_length || buffer_length == 16);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t flags = memory::load_and_swap<uint32_t>(buffer + 4);
      uint64_t session_nonce = memory::load_and_swap<uint64_t>(buffer + 8);

      REXKRNL_DEBUG("XSessionEnd({:08X}, {:08X}, {:016X})", obj_ptr, flags, session_nonce);

      auto* object = LookupSession(kernel_state_, obj_ptr);
      return object && object->record() &&
                     kernel_state_->session_manager()->registry().End(object->record()->info.id)
                 ? X_E_SUCCESS
                 : X_E_INVALIDARG;
    }
    case 0x000B0016: {
      assert_true(!buffer_length || buffer_length == 32);

      uint32_t proc_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t num_results = memory::load_and_swap<uint32_t>(buffer + 8);
      uint16_t num_props = memory::load_and_swap<uint16_t>(buffer + 12);
      uint16_t num_ctx = memory::load_and_swap<uint16_t>(buffer + 14);
      uint32_t props_ptr = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t ctx_ptr = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t results_buffer_size = memory::load_and_swap<uint32_t>(buffer + 24);
      uint32_t search_results_ptr = memory::load_and_swap<uint32_t>(buffer + 28);

      REXKRNL_DEBUG("XSessionSearch({}, {}, {}, {}, {}, {:08X}, {:08X}, {}, {:08X})", proc_index,
                    user_index, num_results, num_props, num_ctx, props_ptr, ctx_ptr,
                    results_buffer_size, search_results_ptr);
      REXKRNL_INFO(
          "XSessionSearch request: proc={} user={} max={} props={} contexts={} size={} "
          "output={:08X}",
          proc_index, user_index, num_results, num_props, num_ctx, results_buffer_size,
          search_results_ptr);
      return WriteSearchResults(kernel_state_, search_results_ptr, results_buffer_size, num_results,
                                true, nullptr, num_props, props_ptr, num_ctx, ctx_ptr);
    }
    case 0x000B0018: {
      assert_true(!buffer_length || buffer_length == 16);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t flags = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t maxPublicSlots = memory::load_and_swap<uint32_t>(buffer + 8);
      uint16_t maxPrivateSlots = memory::load_and_swap<uint16_t>(buffer + 12);

      REXKRNL_DEBUG("XSessionModify({:08X}, {:08X}, {:08X}, {:08X})", obj_ptr, flags,
                    maxPublicSlots, maxPrivateSlots);

      auto* object = LookupSession(kernel_state_, obj_ptr);
      return object && object->record() &&
                     kernel_state_->session_manager()->registry().Modify(
                         object->record()->info.id, flags, maxPublicSlots, maxPrivateSlots)
                 ? X_E_SUCCESS
                 : X_E_INVALIDARG;
    }
    case 0x000B001C: {
      assert_true(!buffer_length || buffer_length == 36);

      // session_search
      uint32_t proc_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t num_results = memory::load_and_swap<uint32_t>(buffer + 8);
      uint16_t num_props = memory::load_and_swap<uint16_t>(buffer + 12);
      uint16_t num_ctx = memory::load_and_swap<uint16_t>(buffer + 14);
      uint32_t props_ptr = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t ctx_ptr = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t results_buffer_size = memory::load_and_swap<uint32_t>(buffer + 24);
      uint32_t search_results_ptr = memory::load_and_swap<uint32_t>(buffer + 28);
      //
      uint32_t num_users = memory::load_and_swap<uint32_t>(buffer + 32);

      REXKRNL_DEBUG("XSessionSearchEx({}, {}, {}, {}, {}, {:08X}, {:08X}, {}, {:08X}, {})",
                    proc_index, user_index, num_results, num_props, num_ctx, props_ptr, ctx_ptr,
                    results_buffer_size, search_results_ptr, num_users);
      REXKRNL_INFO(
          "XSessionSearchEx request: proc={} user={} max={} props={} contexts={} size={} "
          "output={:08X} users={}",
          proc_index, user_index, num_results, num_props, num_ctx, results_buffer_size,
          search_results_ptr, num_users);
      if (num_props && props_ptr) {
        auto* property = memory_->TranslateVirtual(props_ptr);
        REXKRNL_INFO(
            "XSessionSearchEx property[0] raw={:08X} {:08X} {:08X} {:08X} {:08X} {:08X}",
            memory::load_and_swap<uint32_t>(property + 0),
            memory::load_and_swap<uint32_t>(property + 4),
            memory::load_and_swap<uint32_t>(property + 8),
            memory::load_and_swap<uint32_t>(property + 12),
            memory::load_and_swap<uint32_t>(property + 16),
            memory::load_and_swap<uint32_t>(property + 20));
      }
      if (num_ctx && ctx_ptr) {
        auto* contexts = memory_->TranslateVirtual(ctx_ptr);
        for (uint16_t i = 0; i < num_ctx; ++i) {
          REXKRNL_INFO("XSessionSearchEx context[{}]: id={:08X} value={:08X}", i,
                       memory::load_and_swap<uint32_t>(contexts + i * 8),
                       memory::load_and_swap<uint32_t>(contexts + i * 8 + 4));
        }
      }

      return WriteSearchResults(kernel_state_, search_results_ptr, results_buffer_size, num_results,
                                true, nullptr, num_props, props_ptr, num_ctx, ctx_ptr);
    }
    case 0x000B001D: {
      assert_true(!buffer_length || buffer_length == 24);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t details_buffer_size = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t session_details_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t reserved1 = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t reserved2 = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t reserved3 = memory::load_and_swap<uint32_t>(buffer + 20);

      REXKRNL_DEBUG("XSessionGetDetails({:08X}, {}, {:08X}, {}, {}, {})", obj_ptr,
                    details_buffer_size, session_details_ptr, reserved1, reserved2, reserved3);

      auto* object = LookupSession(kernel_state_, obj_ptr);
      if (!object || !object->record() || !session_details_ptr)
        return X_E_INVALIDARG;
      auto session = object->record();
      if (details_buffer_size < sizeof(GuestSessionDetails))
        return X_ERROR_INSUFFICIENT_BUFFER;
      std::lock_guard session_lock(*session->mutex);
      size_t member_capacity =
          (details_buffer_size - sizeof(GuestSessionDetails)) / sizeof(GuestSessionMember);
      size_t returned_members = std::min(member_capacity, session->members.size());
      size_t written_size =
          sizeof(GuestSessionDetails) + returned_members * sizeof(GuestSessionMember);
      auto* details = memory_->TranslateVirtual<GuestSessionDetails*>(session_details_ptr);
      std::memset(details, 0, written_size);
      details->host_user_index =
          session->host_xuid == kernel_state_->user_profile()->xuid() ? 0 : kInvalidUserIndex;
      details->flags = session->flags;
      details->max_public_slots = session->max_public_slots;
      details->max_private_slots = session->max_private_slots;
      details->available_public_slots = session->OpenPublicSlots();
      details->available_private_slots = session->OpenPrivateSlots();
      details->actual_member_count = uint32_t(session->members.size());
      details->returned_member_count = uint32_t(returned_members);
      details->state = uint32_t(session->state);
      details->nonce = session->nonce;
      StoreSessionInfo(&details->info, session->info);
      uint32_t members_ptr =
          returned_members ? session_details_ptr + sizeof(GuestSessionDetails) : 0;
      details->members_ptr = members_ptr;
      if (returned_members) {
        auto* members = memory_->TranslateVirtual<GuestSessionMember*>(members_ptr);
        for (size_t i = 0; i < returned_members; ++i) {
          members[i].xuid = session->members[i].xuid;
          members[i].user_index =
              session->members[i].local ? session->members[i].user_index : kInvalidUserIndex;
          members[i].flags = session->members[i].private_slot ? 1 : 0;
        }
      }
      return X_E_SUCCESS;
    }
    case 0x000B001E: {
      assert_true(!buffer_length || buffer_length == 24);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t session_info_ptr = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t reserved1 = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t reserved2 = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t reserved3 = memory::load_and_swap<uint32_t>(buffer + 20);

      REXKRNL_DEBUG("XSessionMigrateHost({:08X}, {:08X}, {}, {}, {}, {})", obj_ptr,
                    session_info_ptr, user_index, reserved1, reserved2, reserved3);

      return X_E_SUCCESS;
    }
    case 0x000B0019: {
      assert_true(!buffer_length || buffer_length == 8);

      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t session_info_ptr = memory::load_and_swap<uint32_t>(buffer + 4);

      REXKRNL_DEBUG("XSessionGetInvitationData - unimplemented({}, {:08X})", user_index,
                    session_info_ptr);

      return X_E_SUCCESS;
    }
    case 0x000B001A: {
      assert_true(!buffer_length || buffer_length == 28);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t flags = memory::load_and_swap<uint32_t>(buffer + 4);
      uint64_t session_nonce = memory::load_and_swap<uint64_t>(buffer + 8);
      uint32_t session_duration_sec = memory::load_and_swap<uint32_t>(buffer + 16);  // 300
      uint32_t results_buffer_size = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t results_ptr = memory::load_and_swap<uint32_t>(buffer + 24);

      REXKRNL_DEBUG("XSessionArbitrationRegister({:08X}, {:08X}, {:016X}, {:08X}, {:08X}, {:08X})",
                    obj_ptr, flags, session_nonce, session_duration_sec, results_buffer_size,
                    results_ptr);

      return X_E_SUCCESS;
    }
    case 0x000B001B: {
      assert_true(!buffer_length || buffer_length == 32);

      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t num_session_ids = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t session_ids_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t results_buffer_size = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t search_results_ptr = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t reserved1 = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t reserved2 = memory::load_and_swap<uint32_t>(buffer + 24);
      uint32_t reserved3 = memory::load_and_swap<uint32_t>(buffer + 28);

      REXKRNL_DEBUG("XSessionSearchByID({}, {:08X}, {:08X}, {:08X}, {:08X}, {}, {}, {})",
                    user_index, num_session_ids, session_ids_ptr, results_buffer_size,
                    search_results_ptr, reserved1, reserved2, reserved3);

      if (!num_session_ids || !session_ids_ptr)
        return X_E_INVALIDARG;
      std::vector<std::array<uint8_t, 8>> requested_ids(num_session_ids);
      auto* source = memory_->TranslateVirtual(session_ids_ptr);
      for (uint32_t i = 0; i < num_session_ids; ++i) {
        std::memcpy(requested_ids[i].data(), source + i * 8, 8);
      }
      return WriteSearchResults(kernel_state_, search_results_ptr, results_buffer_size,
                                num_session_ids, true, &requested_ids);
    }
    case 0x000B001F: {
      assert_true(!buffer_length || buffer_length == 24);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t array_count = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t xuid_array_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t reserved1 = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t reserved2 = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t reserved3 = memory::load_and_swap<uint32_t>(buffer + 20);

      REXKRNL_DEBUG("XSessionModifySkill({:08X}, {}, {:08X}, {}, {}, {})", obj_ptr, array_count,
                    xuid_array_ptr, reserved1, reserved2, reserved3);

      return X_E_SUCCESS;
    }
    case 0x000B0020: {
      assert_true(!buffer_length || buffer_length == 8);

      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t view_id = memory::load_and_swap<uint32_t>(buffer + 4);

      REXKRNL_DEBUG("XUserResetStatsView({:08X}, {})", user_index, view_id);

      return X_E_SUCCESS;
    }
    case 0x000B0021: {
      assert_true(!buffer_length || buffer_length == 28);

      uint32_t title_id = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t xuids_count = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t xuids_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t specs_count = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t specs_ptr = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t results_size = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t results_ptr = memory::load_and_swap<uint32_t>(buffer + 24);

      REXKRNL_DEBUG("XUserReadStats({}, {}, {:08X}, {}, {:08X}, {}, {:08X})", title_id, xuids_count,
                    xuids_ptr, specs_count, specs_ptr, results_size, results_ptr);

      if (!results_ptr || !InitializeEmptyStatsReadResults(std::span<uint8_t>(
                              memory_->TranslateVirtual(results_ptr), results_size))) {
        return X_E_INVALIDARG;
      }
      return X_E_SUCCESS;
    }
    case 0x000B0025: {
      assert_true(!buffer_length || buffer_length == 20);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint64_t xuid = memory::load_and_swap<uint64_t>(buffer + 4);
      uint32_t num_views = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t views_ptr = memory::load_and_swap<uint32_t>(buffer + 16);

      REXKRNL_DEBUG("XSessionWriteStats({:08X}, {:016X}, {:08X}, {:08X})", obj_ptr, xuid, num_views,
                    views_ptr);

      return X_E_SUCCESS;
    }
    case 0x000B0026: {
      assert_true(!buffer_length || buffer_length == 20);

      uint32_t obj_ptr = memory::load_and_swap<uint32_t>(buffer + 0);
      uint64_t xuid = memory::load_and_swap<uint64_t>(buffer + 4);
      uint32_t num_views = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t views_ptr = memory::load_and_swap<uint32_t>(buffer + 16);

      REXKRNL_DEBUG("XSessionFlushStats({:08X}, {:016X}, {:08X}, {:08X})", obj_ptr, xuid, num_views,
                    views_ptr);

      return X_E_SUCCESS;
    }
    case 0x000B0036: {
      // Called after opening xbox live arcade and clicking on xbox live v5759
      // to 5787 and called after clicking xbox live in the game library from
      // v6683 to v6717
      // Does not get sent a buffer
      REXKRNL_DEBUG("XInvalidateGamerTileCache, unimplemented");
      return X_E_FAIL;
    }
    case 0x000B003D: {
      assert_true(!buffer_length || buffer_length == 16);

      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t AnId_buffer_size = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t AnId_buffer_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t block = memory::load_and_swap<uint32_t>(buffer + 12);

      REXKRNL_DEBUG("XUserGetANID({:08X}, {:08X}, {:08X}, {:08X})", user_index, AnId_buffer_size,
                    AnId_buffer_ptr, block);

      return X_E_SUCCESS;
    }
    case 0x000B0041: {
      assert_true(!buffer_length || buffer_length == 32);
      // 00000000 2789fecc 00000000 00000000 200491e0 00000000 200491f0 20049340
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t context_ptr = memory::load_and_swap<uint32_t>(buffer + 16);
      auto context = context_ptr ? memory_->TranslateVirtual(context_ptr) : nullptr;
      uint32_t context_id = context ? memory::load_and_swap<uint32_t>(context + 0) : 0;
      REXKRNL_DEBUG("XGIUserGetContext({:08X}, {:08X}, {:08X}))", user_index, context_ptr,
                    context_id);
      uint32_t value = 0;
      if (context) {
        memory::store_and_swap<uint32_t>(context + 4, value);
      }
      return X_E_FAIL;
    }
    case 0x000B0060: {
      assert_true(!buffer_length || buffer_length == 32);

      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t num_session_ids = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t session_ids_ptr = memory::load_and_swap<uint32_t>(buffer + 8);
      uint32_t results_buffer_size = memory::load_and_swap<uint32_t>(buffer + 12);
      uint32_t search_results_ptr = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t reserved1 = memory::load_and_swap<uint32_t>(buffer + 20);
      uint32_t reserved2 = memory::load_and_swap<uint32_t>(buffer + 24);
      uint32_t reserved3 = memory::load_and_swap<uint32_t>(buffer + 28);

      REXKRNL_DEBUG("XSessionSearchByIds({:08X}, {:08X}, {:08X}, {:08X}, {:08X}, {}, {}, {})",
                    user_index, num_session_ids, session_ids_ptr, results_buffer_size,
                    search_results_ptr, reserved1, reserved2, reserved3);

      return X_E_SUCCESS;
    }
    case 0x000B0065: {
      assert_true(!buffer_length || buffer_length == 52);

      uint32_t proc_index = memory::load_and_swap<uint32_t>(buffer + 0);
      uint32_t user_index = memory::load_and_swap<uint32_t>(buffer + 4);
      uint32_t num_results = memory::load_and_swap<uint32_t>(buffer + 8);
      uint16_t num_weighted_properties = memory::load_and_swap<uint16_t>(buffer + 12);
      uint16_t num_weighted_contexts = memory::load_and_swap<uint16_t>(buffer + 14);
      uint32_t weighted_search_properties_ptr = memory::load_and_swap<uint32_t>(buffer + 16);
      uint32_t weighted_search_contexts_ptr = memory::load_and_swap<uint32_t>(buffer + 20);
      uint16_t num_props = memory::load_and_swap<uint16_t>(buffer + 24);
      uint16_t num_ctx = memory::load_and_swap<uint16_t>(buffer + 26);
      uint32_t non_weighted_search_properties_ptr = memory::load_and_swap<uint32_t>(buffer + 28);
      uint32_t non_weighted_search_contexts_ptr = memory::load_and_swap<uint32_t>(buffer + 32);
      uint32_t results_buffer_size = memory::load_and_swap<uint32_t>(buffer + 36);
      uint32_t search_results_ptr = memory::load_and_swap<uint32_t>(buffer + 40);
      uint32_t num_users = memory::load_and_swap<uint32_t>(buffer + 44);
      uint32_t weighted_search = memory::load_and_swap<uint32_t>(buffer + 48);

      REXKRNL_DEBUG(
          "XSessionSearchWeighted({:08X}, {:08X}, {:08X}, {}, {}, {:08X}, {:08X}, {}, {}, {:08X}, "
          "{:08X}, {:08X}, {:08X}, {:08X}, {:08X})",
          proc_index, user_index, num_results, num_weighted_properties, num_weighted_contexts,
          weighted_search_properties_ptr, weighted_search_contexts_ptr, num_props, num_ctx,
          non_weighted_search_properties_ptr, non_weighted_search_contexts_ptr, results_buffer_size,
          search_results_ptr, num_users, weighted_search);

      return X_E_SUCCESS;
    }
    case 0x000B0071: {
      REXKRNL_DEBUG("XGI 0x000B0071, unimplemented");
      return X_E_SUCCESS;
    }
  }
  REXKRNL_ERROR(
      "Unimplemented XGI message app={:08X}, msg={:08X}, arg1={:08X}, "
      "arg2={:08X}",
      app_id(), message, buffer_ptr, buffer_length);
  return X_E_FAIL;
}

}  // namespace apps
}  // namespace xam
}  // namespace kernel
}  // namespace rex
