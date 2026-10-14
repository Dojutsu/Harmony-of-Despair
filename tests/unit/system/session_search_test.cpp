#include <catch2/catch_test_macros.hpp>

#include <array>
#include <cstdint>
#include <string>
#include <vector>

#include <rex/system/xam/session_directory.h>

using namespace rex::system::xam;

namespace {
std::string ListedSession(const std::string& id, const std::string& code,
                          const std::string& host_xuid, bool searchable, unsigned open_public,
                          const std::string& build = "harmony-test") {
  return std::string(R"({"session_id":")") + id +
         R"(","server_name":"Host","player_count":1,"max_players":6,"title_id":"58410A7A",)"
         R"("protocol_version":1,"build_id":")" + build + R"(","connectivity_candidates":[{"type":"public","address":"203.0.113.5",)"
         R"("discovery_port":30741,"gameplay_port":30742}],)"
         R"("invite_code":")" + code + R"(","listing":{"searchable":)" +
         (searchable ? "true" : "false") +
         R"(,"xbox_session":"0102030405060708","key":"00112233445566778899aabbccddeeff",)"
         R"("host_ipv4":"0a000001","host_port":30742,"ethernet":"aabbccddeeff",)"
         R"("online":"000102030405060708090a0b0c0d0e0f10111213","host_xuid":")" + host_xuid +
         R"(","open_public":)" + std::to_string(open_public) +
         R"(,"open_private":0,"filled_public":1,"filled_private":0,)"
         R"("contexts":[[32778,1],[3,1]],"properties":[[536870927,"000000000001f89e"],[1,"zz"]]}})";
}
}  // namespace

TEST_CASE("team search lists only open, searchable lobbies from other hosts",
          "[session][directory][search]") {
  const std::string body = std::string(R"({"sessions":[)") +
      ListedSession("open-one", "ABC234", "00000000000000AA", true, 2) + "," +
      ListedSession("mine", "DEF567", "0000000000001001", true, 2) + "," +
      ListedSession("hidden", "GHJ789", "00000000000000BB", false, 2) + "," +
      ListedSession("full", "KMN234", "00000000000000CC", true, 0) + "," +
      ListedSession("other-build", "PQR567", "00000000000000DD", true, 2, "old-build") + "," +
      R"({"session_id":"no-listing","server_name":"Old","player_count":1,"max_players":6,)"
      R"("title_id":"58410A7A","protocol_version":1,"build_id":"harmony-test",)"
      R"("connectivity_candidates":[{"type":"public","address":"203.0.113.6",)"
      R"("discovery_port":30741,"gameplay_port":30742}]})" + "]}";
  auto listings = ParseDirectoryListingResponse(body, 0x58410A7A, "harmony-test", 0x1001);
  REQUIRE(listings.size() == 1);
  const auto& listing = listings.front();
  CHECK(listing.session_id == "open-one");
  CHECK(listing.invite_code == "ABC234");
  CHECK(listing.host_xuid == 0xAA);
  CHECK(listing.xbox_session_id == std::array<uint8_t, 8>{1, 2, 3, 4, 5, 6, 7, 8});
  CHECK(listing.key[15] == 0xFF);
  CHECK(listing.host_port == 30742);
  CHECK(reinterpret_cast<const uint8_t*>(&listing.host_ipv4)[0] == 0x0A);
  CHECK(listing.online_address[19] == 0x13);
  CHECK(listing.open_public_slots == 2);
  CHECK(listing.filled_public_slots == 1);
  REQUIRE(listing.contexts.size() == 2);
  CHECK(listing.contexts[0] == std::pair<uint32_t, uint32_t>{0x800A, 1});
  // Malformed property bytes are dropped without discarding the lobby.
  REQUIRE(listing.properties.size() == 1);
  CHECK(listing.properties[0].first == 0x2000000F);
  CHECK(listing.properties[0].second ==
        std::vector<uint8_t>{0, 0, 0, 0, 0, 1, 0xF8, 0x9E});
}

TEST_CASE("team search rejects malformed directory list bodies", "[session][directory][search]") {
  CHECK(ParseDirectoryListingResponse("not json", 0x58410A7A, "harmony-test", 0).empty());
  CHECK(ParseDirectoryListingResponse(R"({"sessions":{}})", 0x58410A7A, "harmony-test", 0).empty());
  auto bad_key = ListedSession("x", "ABC234", "00000000000000AA", true, 2);
  bad_key.replace(bad_key.find("00112233445566778899aabbccddeeff"), 32, "0011");
  CHECK(ParseDirectoryListingResponse("{\"sessions\":[" + bad_key + "]}", 0x58410A7A,
                                      "harmony-test", 0).empty());
  auto bad_code = ListedSession("x", "not a code", "00000000000000AA", true, 2);
  CHECK(ParseDirectoryListingResponse("{\"sessions\":[" + bad_code + "]}", 0x58410A7A,
                                      "harmony-test", 0).empty());
}
