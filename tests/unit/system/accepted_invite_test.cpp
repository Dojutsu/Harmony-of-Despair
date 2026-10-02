#include <catch2/catch_test_macros.hpp>

#include <future>
#include <thread>

#include <rex/system/xam/accepted_invite.h>
#include <rex/system/xam/session.h>

namespace rex::system::xam {
namespace {

AcceptedInviteIdentity Identity(uint64_t token = 1, uint32_t user = 0) {
  AcceptedInviteIdentity identity;
  identity.operation_token = token;
  identity.title_generation = token;
  identity.title_id = 0x58410A7A;
  identity.local_user_index = user;
  identity.local_xuid = 0xB13E000000000001ull;
  identity.directory_session_id = "directory-session";
  identity.directory_attempt_id = "00112233445566778899aabbccddeeff";
  identity.admission_generation = "0123456789abcdef0123456789abcdef";
  identity.admission_lifecycle_token = token + 10;
  identity.xbox_session_id = {1, 2, 3, 4, 5, 6, 7, 8};
  return identity;
}

ReadyConfiguredInvite Ready() {
  ReadyConfiguredInvite ready;
  ready.operation.operation_token = 1;
  ready.operation.title_generation = 1;
  ready.operation.title_id = 0x58410A7A;
  ready.operation.local_user_index = 0;
  ready.operation.local_xuid = 0xB13E000000000001ull;
  ready.directory_session_id = "directory-session";
  ready.directory_attempt_id = "00112233445566778899aabbccddeeff";
  ready.admission_generation = "0123456789abcdef0123456789abcdef";
  ready.client_admission_lifecycle_token = 11;
  ready.host_ready = true;
  ready.private_allocation_eligible = true;
  ready.xbox_session_id = {1, 2, 3, 4, 5, 6, 7, 8};
  ready.host_xuid = 0xB13E000000000002ull;
  for (size_t i = 0; i < ready.exchange_key.size(); ++i)
    ready.exchange_key[i] = uint8_t(0xA0 + i);
  ready.host_endpoint = {0x04030201u, 30742};
  ready.xnaddr = ReconstructXnAddrIdentity(ready.host_xuid);
  return ready;
}

TEST_CASE("accepted invite record is the exact 84-byte Harmony ABI",
          "[accepted-invite][record]") {
  auto ready = Ready();
  const AcceptedInviteRecord expected = {
      0xB1, 0x3E, 0, 0, 0, 0, 0, 1,
      0xB1, 0x3E, 0, 0, 0, 0, 0, 2,
      0x58, 0x41, 0x0A, 0x7A,
      1, 2, 3, 4, 5, 6, 7, 8,
      1, 2, 3, 4, 1, 2, 3, 4, 0x78, 0x16,
      2, 0, 0, 0, 0, 0,
      2, 0, 0, 0, 0, 0, 0x3E, 0xB1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7,
      0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
      0, 0, 0, 1};
  static_assert(expected.size() == 84);
  REQUIRE(SerializeAcceptedInviteRecord(ready) == expected);
  ready.host_ready = false;
  CHECK_FALSE(SerializeAcceptedInviteRecord(ready));
  ready.host_ready = true;
  ready.private_allocation_eligible = false;
  CHECK_FALSE(SerializeAcceptedInviteRecord(ready));
  ready.private_allocation_eligible = true;
  ready.xnaddr.online_address[0] ^= 1;
  CHECK_FALSE(SerializeAcceptedInviteRecord(ready));
}

TEST_CASE("accepted invite store keeps both readers and exact old cleanup separate",
          "[accepted-invite][store]") {
  AcceptedInviteStore store;
  auto first = Identity();
  auto second = Identity(2);
  AcceptedInviteRecord bytes{};
  bytes[0] = 0xB1;
  REQUIRE(store.Publish(first, bytes));
  CHECK_FALSE(store.Publish(first, bytes));
  auto altered = bytes;
  altered[1] = 1;
  CHECK_FALSE(store.Publish(first, altered));
  CHECK_FALSE(store.Acquire(1, first.title_id));
  CHECK_FALSE(store.Acquire(0, first.title_id + 1));
  {
    auto provider = store.Acquire(0, first.title_id);
    auto title = store.Acquire(0, first.title_id);
    REQUIRE(provider);
    REQUIRE(title);
    CHECK(provider->record() == title->record());
    CHECK(provider->record() == bytes);
  }
  {
    auto title = store.Acquire(0, first.title_id);
    auto provider = store.Acquire(0, first.title_id);
    REQUIRE(title);
    REQUIRE(provider);
    CHECK(title->record() == provider->record());
  }
  REQUIRE(store.Publish(second, altered));
  CHECK_FALSE(store.Invalidate(first));
  CHECK(store.Acquire(0, second.title_id)->record() == altered);
  CHECK(store.Invalidate(second));
  CHECK_FALSE(store.Acquire(0, second.title_id));
  REQUIRE(store.Publish(second, altered));
  store.Close();
  store.Close();
  CHECK(store.size() == 0);
  CHECK_FALSE(store.Acquire(0, second.title_id));
  CHECK_FALSE(store.Publish(Identity(3), bytes));
}

TEST_CASE("accepted invite invalidation waits for an in-flight read",
          "[accepted-invite][store][race]") {
  AcceptedInviteStore store;
  auto identity = Identity();
  AcceptedInviteRecord record{};
  REQUIRE(store.Publish(identity, record));
  auto read = store.Acquire(0, identity.title_id);
  REQUIRE(read);
  std::promise<void> started;
  auto entered = started.get_future();
  std::promise<void> finished;
  auto done = finished.get_future();
  std::thread invalidator([&] {
    started.set_value();
    store.Invalidate(identity);
    finished.set_value();
  });
  entered.wait();
  CHECK(read->record() == record);
  read.reset();
  invalidator.join();
  CHECK(done.wait_for(std::chrono::seconds(0)) == std::future_status::ready);
  CHECK_FALSE(store.Acquire(0, identity.title_id));
}

TEST_CASE("registry deletion and incompatible replacement retire exact accepted state",
          "[accepted-invite][registry][invalidation]") {
  SessionManager manager(nullptr, 39401);
  auto ready = Ready();
  auto record = SerializeAcceptedInviteRecord(ready);
  REQUIRE(record);
  AcceptedInviteIdentity identity = Identity();
  SessionRecord correlated;
  correlated.info.id = ready.xbox_session_id;
  correlated.info.host_address = ready.host_endpoint;
  correlated.info.ethernet_address = ready.xnaddr.ethernet_address;
  correlated.info.online_address = ready.xnaddr.online_address;
  correlated.info.key = ready.exchange_key;
  correlated.host_xuid = ready.host_xuid;
  correlated.traversal_session_id = ready.directory_session_id;
  correlated.traversal_attempt_id = ready.directory_attempt_id;
  auto installed = manager.registry().UpsertDiscovered(correlated);
  REQUIRE(installed);
  REQUIRE(manager.accepted_invites().Publish(identity, *record));
  auto public_search = correlated;
  public_search.traversal_session_id.clear();
  public_search.traversal_attempt_id.clear();
  public_search.info.host_address.port = 1;
  CHECK(manager.registry().UpsertDiscovered(public_search) == installed);
  CHECK(manager.accepted_invites().size() == 1);
  CHECK(manager.registry().Delete(ready.xbox_session_id));
  CHECK(manager.accepted_invites().size() == 0);

  REQUIRE(manager.registry().UpsertDiscovered(correlated));
  REQUIRE(manager.accepted_invites().Publish(identity, *record));
  auto replacement = correlated;
  replacement.info.key[0] ^= 0x80;
  REQUIRE(manager.registry().UpsertDiscovered(replacement));
  CHECK(manager.accepted_invites().size() == 0);
  manager.ShutdownAsyncActivity();
}

}  // namespace
}  // namespace rex::system::xam
