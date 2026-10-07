#pragma once
#include <rex/system/xam/private_lan_authority.h>
namespace rex::system::xam {
class PrivateLanClientBinding final {
 public:
  ~PrivateLanClientBinding();
  bool Confirmed() const noexcept;
  uint64_t xuid() const noexcept;
  const ArbitrationIdentity& identity() const noexcept;
 private:
  friend class PrivateLanDiscoveryAdapter;
  struct Impl;
  explicit PrivateLanClientBinding(std::unique_ptr<Impl> impl);
  std::unique_ptr<Impl> impl_;
};
// Existing LAN search/join/register/leave operations over recipient-bound,
// metadata-opaque private frames. No directory, rendezvous or public fallback.
class PrivateLanDiscoveryAdapter final {
 public:
  PrivateLanDiscoveryAdapter(uint32_t title,uint16_t port,uint64_t machine,
      std::shared_ptr<const PrivateLanInvitation> invitation);
  ~PrivateLanDiscoveryAdapter();
  bool Start(const std::shared_ptr<SessionRecord>& session);
  void Stop();
  bool IsAdvertising() const noexcept;
  void StopClient();
  std::vector<SessionRecord> Search(uint32_t timeout_ms,uint32_t max_results);
  std::optional<SessionRecord> Join(const SessionRecord& session,
      const SessionMember& member,uint32_t timeout_ms);
  std::optional<ArbitrationSnapshot> RegisterArbitration(
      const std::shared_ptr<SessionRecord>& session,uint64_t xuid,uint64_t nonce);
  std::optional<SessionRecord> Leave(const SessionRecord& session,uint64_t xuid,uint32_t timeout_ms);
  bool Activate(const std::shared_ptr<SessionRecord>& session,uint64_t xuid);
  void SetTitle(uint32_t title);
  void SetMachine(uint64_t machine);
 private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
} // namespace rex::system::xam
