# HarmonyRecomp Direct Connect

## Status

Direct Connect is implemented as a focused runtime candidate and covered by
ReXGlue session/network tests. The existing paired LAN path remains the known-
good multiplayer baseline. A paired Tailscale run is still required before
Direct Connect is called runtime-verified.

## Architecture

Harmony's existing multiplayer sequence is retained:

1. XSession search obtains a complete host advertisement.
2. The guest receives the session ID, key, host XUID, membership, slots, IPv4,
   and gameplay port in its normal search result.
3. `XGISessionCreateImpl` resolves that session record.
4. `XGISessionJoinLocal` sends the existing join exchange on UDP 30741.
5. XNet maps the advertised address for the guest.
6. Harmony's logical UDP 1000 gameplay socket continues to use native UDP
   30742 through the existing port translation.

With no Direct Connect address, search still uses the existing UDP 30741 LAN
broadcast and loopback probe. With `--direct_connect_address=<IPv4>`, search
instead sends the same query by unicast to that address. The explicit endpoint
remains authoritative through the returned advertisement and join response;
all other session data still comes from the host.

UDP 30741 is still required after the host address is known because it carries
the existing session advertisement and membership join/leave exchange. It is
not used for gameplay payloads. UDP 30742 remains the only gameplay port.

## Tailscale test configuration

Use each machine's current Tailscale IPv4 address. Do not reuse the physical
LAN addresses from the earlier paired test.

Host additions:

```text
--lan_bind_address=<HOST_TAILSCALE_IPV4>
--lan_discovery_port=30741
--lan_gameplay_port=30742
```

Client additions:

```text
--lan_bind_address=<CLIENT_TAILSCALE_IPV4>
--direct_connect_address=<HOST_TAILSCALE_IPV4>
--lan_discovery_port=30741
--lan_gameplay_port=30742
```

Keep the existing distinct `--user_xuid`, `--user_name`, `--lan_online=true`,
game-data, renderer, input, and license options on both machines.

The Tailscale ACL and each host firewall must permit peer UDP traffic on 30741
and 30742. Tailscale does not require router port forwarding. A raw public-IP
test without Tailscale requires externally routable UDP 30741/30742 or manual
port forwarding; NAT discovery, punching, and relays are not implemented.

## Manual paired test

1. Confirm both machines are connected to Tailscale and can reach the other's
   Tailscale IPv4 address.
2. Launch the host with its Tailscale address as `--lan_bind_address` and no
   Direct Connect option.
3. Enter Multiplayer and create a team on the host.
4. Launch the client with its own Tailscale bind address and the host's address
   as `--direct_connect_address`.
5. On the client, enter Multiplayer, choose Search, select the host result, and
   join it.
6. Confirm the lobby reaches two members, then launch one chapter and verify
   both players can move and interact.
7. Preserve both runtime logs. The client should show a Direct Connect query to
   the host on UDP 30741, a successful join response, binds on UDP 30742, and
   sustained bidirectional gameplay packets without invalid-handle, flags,
   timeout, or network-error messages.
8. Repeat once with `--direct_connect_address` removed on both machines while
   using their physical LAN bind addresses. This is the LAN regression check.

## Future server directory

A future master directory should return signed or otherwise authenticated
session endpoints and metadata. The client can then probe a selected endpoint
with the same unicast advertisement query used by Direct Connect before
inserting it into the existing session registry. NAT classification, endpoint
candidate exchange, hole punching, and relay selection belong behind that
endpoint-resolution layer; none are part of this milestone.

## Current limitations

- IPv4 literals only; no DNS names or IPv6.
- One manually selected host endpoint per process start.
- No NAT punching, relay, invitations, or public matchmaking.
- The existing 500 ms join timeout may be too short for some internet paths;
  do not change it without paired latency evidence.
- Search-result property/context presentation remains separate incomplete work.
