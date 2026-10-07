// Actual session-owned registration records; no sockets or network services.
#include <catch2/catch_test_macros.hpp>
#include <rex/system/xam/session_arbitration.h>

namespace {
using namespace rex::system::xam;
ArbitrationToken Token(uint8_t byte) { ArbitrationToken value{}; value.fill(byte); return value; }
ArbitrationIdentity Identity() {
  ArbitrationIdentity value{};
  value.session_id.fill(1); value.exchange_key.fill(2); value.incarnation = Token(3);
  value.nonce = 0x123456789ABCDEF0; value.host_xuid = 0x10001; value.host_machine_id = 0x20001;
  return value;
}
struct Fixture {
  ArbitrationIdentity identity = Identity();
  ArbitrationToken local_credential = Token(4), remote_credential = Token(5);
  ArbitrationEndpoint admission{0x0100007F, 20000}, registration{0x0100007F, 20001};
  ArbitrationJoinClaim claim{0x10002, 0x20002, admission, Token(6), {}};
  SessionArbitrationAuthority authority{identity, local_credential};
  ArbitrationRegistration Request() const {
    return {identity, claim.xuid, claim.machine_id, registration, remote_credential, Token(7)};
  }
  void Admit() {
    REQUIRE(authority.Admit(claim, remote_credential,
        SessionArbitrationAuthority::Clock::time_point{}).status == ArbitrationStatus::kAccepted);
  }
};
} // namespace

TEST_CASE("Session arbitration registers client first then host using actual accepted records",
          "[session][arbitration][registration]") {
  Fixture fixture; fixture.Admit();
  const auto lookup = fixture.authority.CredentialForVerification(
      fixture.identity, fixture.claim.xuid, fixture.claim.machine_id);
  REQUIRE(lookup); CHECK(*lookup == fixture.remote_credential);
  auto joined = fixture.authority.Snapshot(); REQUIRE(joined); CHECK(joined->registrants.empty());
  auto request = fixture.Request();
  CHECK(fixture.authority.Register(request) == ArbitrationStatus::kCredentialMismatch);
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kAccepted);
  auto client = fixture.authority.Snapshot(); REQUIRE(client); REQUIRE(client->registrants.size() == 1);
  CHECK(client->registrants[0].machine_id == fixture.claim.machine_id);
  CHECK(client->registrants[0].trustworthiness == 0);
  CHECK(client->registrants[0].xuids == std::vector<uint64_t>{fixture.claim.xuid});
  CHECK(fixture.authority.RegisterLocal(fixture.identity.host_xuid, fixture.identity.host_machine_id,
      fixture.identity.nonce, Token(8)) == ArbitrationStatus::kAccepted);
  auto host = fixture.authority.Snapshot(); REQUIRE(host); REQUIRE(host->registrants.size() == 2);
  CHECK(host->registrants[0].machine_id == fixture.identity.host_machine_id);
  CHECK(host->registrants[0].xuids == std::vector<uint64_t>{fixture.identity.host_xuid});
  CHECK(host->registrants[1].machine_id == fixture.claim.machine_id);
  CHECK(host->revision > client->revision);
}

TEST_CASE("Verified registration pins its separate observed endpoint without moving admission",
          "[session][arbitration][registration]") {
  Fixture fixture; fixture.Admit(); auto request = fixture.Request();
  REQUIRE(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kAccepted);
  const auto before = fixture.authority.Snapshot(); REQUIRE(before);
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kReplay);
  CHECK(fixture.authority.Register(request) == ArbitrationStatus::kReplay);
  REQUIRE(fixture.authority.Snapshot()); CHECK(fixture.authority.Snapshot()->revision == before->revision);
  auto changed = request; changed.endpoint = fixture.admission;
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(changed) == ArbitrationStatus::kCredentialMismatch);
  changed = request; ++changed.endpoint.port;
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(changed) == ArbitrationStatus::kCredentialMismatch);
  changed = request; changed.endpoint.ipv4 = 0x0200007F;
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(changed) == ArbitrationStatus::kCredentialMismatch);
  changed = request; changed.attempt = Token(9);
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(changed) == ArbitrationStatus::kRetiredAttempt);
  auto rejoin = fixture.claim; rejoin.credential = fixture.remote_credential;
  CHECK(fixture.authority.CheckAdmission(rejoin, {}).status == ArbitrationStatus::kReplay);
  rejoin.endpoint = fixture.registration;
  CHECK(fixture.authority.CheckAdmission(rejoin, {}).status == ArbitrationStatus::kCredentialMismatch);
  CHECK(fixture.authority.Snapshot()->revision == before->revision);
}

TEST_CASE("Credential lookup and verified registration require the exact current member identity",
          "[session][arbitration][registration]") {
  Fixture fixture; fixture.Admit();
  for (unsigned field = 0; field < 6; ++field) {
    auto wrong = fixture.identity;
    switch (field) {
      case 0: wrong.session_id[0] ^= 1; break;
      case 1: wrong.exchange_key[0] ^= 1; break;
      case 2: wrong.incarnation[0] ^= 1; break;
      case 3: ++wrong.nonce; break;
      case 4: ++wrong.host_xuid; break;
      case 5: ++wrong.host_machine_id; break;
    }
    CHECK_FALSE(fixture.authority.CredentialForVerification(wrong, fixture.claim.xuid, fixture.claim.machine_id));
    auto request = fixture.Request(); request.identity = wrong;
    CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kInvalid);
  }
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity, fixture.identity.host_xuid, fixture.identity.host_machine_id));
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity, 0, fixture.claim.machine_id));
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity, fixture.claim.xuid, 0));
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity, fixture.claim.xuid + 1, fixture.claim.machine_id));
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity, fixture.claim.xuid, fixture.claim.machine_id + 1));
  auto request = fixture.Request(); request.credential = Token(10);
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kCredentialMismatch);
  request = fixture.Request(); ++request.machine_id;
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kCredentialMismatch);
  request = fixture.Request(); ++request.xuid;
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kUnknownMember);
  request = fixture.Request(); request.attempt = {};
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kInvalid);
  request = fixture.Request(); request.endpoint.port = 0;
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kInvalid);
  auto before = fixture.authority.Snapshot(); REQUIRE(before); CHECK(before->registrants.empty());
  // Invalid first requests must not reserve or redirect a registration socket.
  request = fixture.Request(); ++request.endpoint.port;
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kAccepted);
}

TEST_CASE("Removed members revoke copied verification credentials and old registration requests",
          "[session][arbitration][registration]") {
  Fixture fixture; fixture.Admit(); const auto old = fixture.Request();
  REQUIRE(fixture.authority.RegisterFromVerifiedEndpoint(old) == ArbitrationStatus::kAccepted);
  auto copied = fixture.authority.CredentialForVerification(fixture.identity, fixture.claim.xuid, fixture.claim.machine_id);
  REQUIRE(copied); CHECK(*copied == fixture.remote_credential);
  REQUIRE(fixture.authority.Remove(fixture.claim.xuid));
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity, fixture.claim.xuid, fixture.claim.machine_id));
  CHECK_FALSE(fixture.authority.MachineId(fixture.claim.xuid));
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(old) == ArbitrationStatus::kUnknownMember);
  CHECK(fixture.authority.CheckAdmission(fixture.claim, {}).status == ArbitrationStatus::kRetiredAttempt);
  auto next = fixture.claim; next.challenge = Token(11);
  REQUIRE(fixture.authority.Admit(next, Token(12), {}).status == ArbitrationStatus::kAccepted);
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(old) == ArbitrationStatus::kCredentialMismatch);
  auto current = fixture.authority.CredentialForVerification(fixture.identity, next.xuid, next.machine_id);
  REQUIRE(current); CHECK(*current == Token(12)); CHECK(*current != *copied);
  auto fresh = fixture.Request(); fresh.credential = Token(12); fresh.attempt = Token(13);
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(fresh) == ArbitrationStatus::kAccepted);
  auto snapshot = fixture.authority.Snapshot(); REQUIRE(snapshot); CHECK(snapshot->registrants.size() == 1);
}

TEST_CASE("Session invalidation closes verification and registration despite retained credential copies",
          "[session][arbitration][registration]") {
  Fixture fixture; fixture.Admit(); auto request = fixture.Request();
  REQUIRE(fixture.authority.CredentialForVerification(fixture.identity, fixture.claim.xuid, fixture.claim.machine_id));
  fixture.authority.Invalidate();
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity, fixture.claim.xuid, fixture.claim.machine_id));
  CHECK_FALSE(fixture.authority.Snapshot()); CHECK_FALSE(fixture.authority.MachineId(fixture.claim.xuid));
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(request) == ArbitrationStatus::kClosed);
  CHECK(fixture.authority.Register(request) == ArbitrationStatus::kClosed);
  CHECK(fixture.authority.RegisterLocal(fixture.identity.host_xuid, fixture.identity.host_machine_id,
      fixture.identity.nonce, Token(8)) == ArbitrationStatus::kClosed);
  CHECK(fixture.authority.Admit(fixture.claim, fixture.remote_credential, {}).status == ArbitrationStatus::kClosed);
}

TEST_CASE("unconfirmed admission expires without expiring confirmed lobby peers", "[session][arbitration]") {
  using namespace rex::system::xam;
  ArbitrationIdentity identity; identity.session_id[0]=1; identity.exchange_key[0]=2;
  identity.incarnation[0]=3; identity.nonce=4; identity.host_xuid=5; identity.host_machine_id=6;
  ArbitrationToken local{}; local[0]=7;
  SessionArbitrationAuthority authority(identity,local);
  const auto now=SessionArbitrationAuthority::Clock::time_point{};
  ArbitrationJoinClaim pending{8,9,{0x0100007fu,1000},{},{}}; pending.challenge[0]=10;
  ArbitrationToken credential{}; credential[0]=11;
  REQUIRE(authority.Admit(pending,credential,now).accepted());
  CHECK(authority.ExpireUnconfirmed(now+std::chrono::seconds(29)).empty());
  REQUIRE(authority.ExpireUnconfirmed(now+std::chrono::seconds(30))==std::vector<uint64_t>{8});
  CHECK_FALSE(authority.MachineId(8));
  CHECK(authority.CheckAdmission(pending,now+std::chrono::seconds(31)).status==ArbitrationStatus::kRetiredAttempt);
  pending.challenge[0]=12; credential[0]=13;
  REQUIRE(authority.Admit(pending,credential,now+std::chrono::seconds(31)).accepted());
  pending.credential=credential;
  REQUIRE(authority.Admit(pending,credential,now+std::chrono::seconds(32)).status==ArbitrationStatus::kReplay);
  CHECK(authority.ExpireUnconfirmed(now+std::chrono::hours(1)).empty());
  REQUIRE(authority.MachineId(8)==9);
  CHECK(authority.Snapshot()->registrants.empty());
}

TEST_CASE("expired admission retains only exact private receipt capability", "[session][arbitration][expiry]") {
  Fixture fixture; fixture.Admit();
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,fixture.claim));
  REQUIRE(fixture.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
      std::chrono::seconds(30))==std::vector<uint64_t>{fixture.claim.xuid});
  const auto before=fixture.authority.Snapshot(); REQUIRE(before); CHECK(before->registrants.empty());
  const auto receipt=fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,fixture.claim);
  REQUIRE(receipt); CHECK(*receipt==fixture.remote_credential);
  CHECK_FALSE(fixture.authority.CredentialForVerification(fixture.identity,fixture.claim.xuid,fixture.claim.machine_id));
  CHECK_FALSE(fixture.authority.MachineId(fixture.claim.xuid));
  CHECK(fixture.authority.RegisterFromVerifiedEndpoint(fixture.Request())==ArbitrationStatus::kUnknownMember);
  CHECK(fixture.authority.CheckAdmission(fixture.claim,{}).status==ArbitrationStatus::kRetiredAttempt);
  CHECK(fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,fixture.claim)==receipt);
  CHECK(fixture.authority.Snapshot()->revision==before->revision);
}

TEST_CASE("expiry receipt lookup requires all original identity and admission fields", "[session][arbitration][expiry]") {
  Fixture fixture; fixture.Admit();
  REQUIRE(fixture.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
      std::chrono::seconds(30)).size()==1);
  auto identity=fixture.identity; identity.session_id[0]^=1;
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(identity,fixture.claim));
  identity=fixture.identity; identity.exchange_key[0]^=1;
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(identity,fixture.claim));
  identity=fixture.identity; identity.incarnation[0]^=1;
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(identity,fixture.claim));
  identity=fixture.identity; ++identity.nonce;
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(identity,fixture.claim));
  identity=fixture.identity; ++identity.host_xuid;
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(identity,fixture.claim));
  identity=fixture.identity; ++identity.host_machine_id;
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(identity,fixture.claim));
  for(unsigned field=0;field<5;++field) {
    auto claim=fixture.claim;
    if(field==0)++claim.xuid; else if(field==1)++claim.machine_id;
    else if(field==2)++claim.endpoint.ipv4; else if(field==3)++claim.endpoint.port;
    else claim.challenge[0]^=1;
    CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,claim));
  }
}

TEST_CASE("explicit leave closed and confirmed records never provide expiry recovery", "[session][arbitration][expiry]") {
  Fixture left; left.Admit(); REQUIRE(left.authority.Remove(left.claim.xuid));
  CHECK_FALSE(left.authority.ExpiredJoinCredentialForVerification(left.identity,left.claim));
  Fixture cancelled; cancelled.Admit();
  REQUIRE(cancelled.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
      std::chrono::seconds(30)).size()==1);
  REQUIRE(cancelled.authority.ExpiredJoinCredentialForVerification(cancelled.identity,cancelled.claim));
  CHECK_FALSE(cancelled.authority.Remove(cancelled.claim.xuid));
  CHECK_FALSE(cancelled.authority.ExpiredJoinCredentialForVerification(cancelled.identity,cancelled.claim));
  Fixture closed; closed.Admit();
  REQUIRE(closed.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
      std::chrono::seconds(30)).size()==1);
  closed.authority.Invalidate();
  CHECK_FALSE(closed.authority.ExpiredJoinCredentialForVerification(closed.identity,closed.claim));
  Fixture confirmed; confirmed.Admit(); auto claim=confirmed.claim; claim.credential=confirmed.remote_credential;
  REQUIRE(confirmed.authority.Admit(claim,Token(9),{}).status==ArbitrationStatus::kReplay);
  CHECK(confirmed.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
      std::chrono::hours(1)).empty());
  CHECK_FALSE(confirmed.authority.ExpiredJoinCredentialForVerification(confirmed.identity,confirmed.claim));
  Fixture registered; registered.Admit();
  REQUIRE(registered.authority.RegisterFromVerifiedEndpoint(registered.Request())==ArbitrationStatus::kAccepted);
  CHECK(registered.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
      std::chrono::hours(1)).empty());
  CHECK_FALSE(registered.authority.ExpiredJoinCredentialForVerification(registered.identity,registered.claim));
}

TEST_CASE("fresh admission supersedes expiry capability without reviving retired challenge", "[session][arbitration][expiry]") {
  Fixture fixture; fixture.Admit();
  REQUIRE(fixture.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
      std::chrono::seconds(30)).size()==1);
  auto fresh=fixture.claim; fresh.challenge=Token(12);
  CHECK(fixture.authority.Admit(fresh,fixture.remote_credential,{}).status==ArbitrationStatus::kInvalid);
  REQUIRE(fixture.authority.Admit(fresh,Token(13),{}).status==ArbitrationStatus::kAccepted);
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,fixture.claim));
  CHECK(fixture.authority.CheckAdmission(fixture.claim,{}).status==ArbitrationStatus::kRetiredAttempt);
  CHECK(fixture.authority.CredentialForVerification(fixture.identity,fresh.xuid,fresh.machine_id)==Token(13));
  REQUIRE(fixture.authority.Remove(fresh.xuid));
  CHECK_FALSE(fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,fixture.claim));
}

TEST_CASE("expiry receipt storage never evicts its bounded retired challenges", "[session][arbitration][expiry]") {
  Fixture fixture;
  for(unsigned index=0;index<SessionArbitrationAuthority::kMaxRetiredAttempts;++index) {
    auto claim=fixture.claim; claim.challenge=Token(static_cast<uint8_t>(index+64));
    const auto credential=Token(static_cast<uint8_t>(index+128));
    REQUIRE(fixture.authority.Admit(claim,credential,{}).status==ArbitrationStatus::kAccepted);
    REQUIRE(fixture.authority.ExpireUnconfirmed(SessionArbitrationAuthority::Clock::time_point{}+
        std::chrono::seconds(30)).size()==1);
    CHECK(fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,claim)==credential);
  }
  auto fresh=fixture.claim; fresh.challenge=Token(63);
  CHECK(fixture.authority.Admit(fresh,Token(62),{}).status==ArbitrationStatus::kExhausted);
  auto original=fixture.claim; original.challenge=Token(64);
  CHECK(fixture.authority.CheckAdmission(original,{}).status==ArbitrationStatus::kRetiredAttempt);
  CHECK(fixture.authority.ExpiredJoinCredentialForVerification(fixture.identity,original)==Token(128));
}

TEST_CASE("Prepared encrypted arbitration replies fail without publishing registration", "[session][arbitration][security]") {
  Fixture fixture;fixture.Admit();const auto before=fixture.authority.Snapshot();REQUIRE(before);
  size_t calls=0;
  CHECK_FALSE(fixture.authority.RegisterFromVerifiedEndpointIf(fixture.Request(),[&](const auto& snapshot){
    ++calls;CHECK(snapshot.registrants.size()==1);CHECK(snapshot.revision>before->revision);return false;}));
  CHECK(calls==1);CHECK(fixture.authority.Snapshot()->registrants.empty());CHECK(fixture.authority.Snapshot()->revision==before->revision);
  CHECK_FALSE(fixture.authority.RegisterFromVerifiedEndpointIf(fixture.Request(),[](const auto&)->bool {throw std::bad_alloc{};}));
  CHECK(fixture.authority.Snapshot()->registrants.empty());CHECK(fixture.authority.Snapshot()->revision==before->revision);
  const auto committed=fixture.authority.RegisterFromVerifiedEndpointIf(fixture.Request(),[](const auto&){return true;});
  REQUIRE(committed);CHECK(committed->registrants.size()==1);CHECK(fixture.authority.Snapshot()->revision==committed->revision);
  auto wrong=fixture.Request();++wrong.endpoint.port;
  CHECK_FALSE(fixture.authority.RegisterFromVerifiedEndpointIf(wrong,[&](const auto&){++calls;return true;}));CHECK(calls==1);
}
