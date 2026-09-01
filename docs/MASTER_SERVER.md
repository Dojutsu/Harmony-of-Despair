# HarmonyRecomp session directory prototype

## Scope

The directory is discovery only. It stores short-lived lobby metadata and one
or more connection candidates. It never receives or proxies Harmony's UDP
30741 discovery/join packets or UDP 30742 gameplay packets.

LAN and manual `--direct_connect_address=<IPv4>` remain independent. If the
directory is unavailable, hosting and both existing connection paths must
continue normally.

## Run locally

The service uses only the Python standard library and binds to loopback by
default:

```text
python3 -m tools.master_server.server --host 127.0.0.1 --port 8080 --ttl 45
```

Run its tests from the repository root:

```text
python3 -m unittest tools.master_server.test_server -v
```

The registry is intentionally in memory. Restarting the process clears all
sessions. A session expires 45 seconds after its last successful registration
or heartbeat by default.

## API

### Register

`POST /sessions`

```json
{
  "server_name": "DesktopHost",
  "player_count": 1,
  "max_players": 6,
  "title_id": "58410A7A",
  "protocol_version": 1,
  "build_id": "harmony-0.0.1.4-p1",
  "host_instance_id": "<opaque per-Host-Game ID>",
  "host_instance_token": "<secret recovery proof>",
  "connectivity_candidates": [
    {
      "type": "tailscale",
      "address": "100.64.0.10",
      "discovery_port": 30741,
      "gameplay_port": 30742
    }
  ]
}
```

The runtime generates a fresh host-instance ID and secret proof once for each
real Host Game flow. Replaying `POST /sessions` with that same pair is an
authenticated idempotent upsert: it refreshes and returns the one existing
public lobby instead of creating another. A different Host Game generates a
different pair. Neither value is returned by the public listing, used as player
identity, derived from an IP address, or logged.

The response contains a server-generated opaque `session_id` and a secret
`registration_token` required for heartbeat and deletion. An idempotent replay
returns the same values so a host can recover from a lost create response. The
tokens are never returned by the public listing endpoint.

### Heartbeat

`POST /sessions/{session_id}/heartbeat`

Send the same validated metadata with:

```text
Authorization: Bearer <registration_token>
```

The prototype heartbeat interval is 15 seconds. It refreshes mutable player
counts and connectivity metadata as well as the expiry deadline.

A transport timeout, TLS/TCP failure, malformed success response, rate limit,
or HTTP 5xx does not prove that the directory forgot the lobby. The runtime
retains the current session ID and token and retries the same heartbeat with
bounded backoff. A genuine 404 enters registration recovery with the same host
instance identity; if the old record still exists, the server returns it, and
if it genuinely expired or the in-memory server restarted, recovery creates one
replacement after the old record is already absent. Authentication rejection
does not fall through into creation of another lobby.

### List

`GET /sessions?title_id=58410A7A&protocol_version=1&build_id=harmony-0.0.1.4-p1`

The response is `{ "sessions": [...] }`. Clients must still validate and
filter title ID, protocol version, build ID, candidate type, IPv4 literal, and
ports. A selected candidate is not trusted as a complete XGI session: the
client probes it using the existing Direct Connect UDP 30741 advertisement
exchange before inserting the returned `SessionRecord` into the guest search
results.

### Unregister

`DELETE /sessions/{session_id}` with the bearer token removes the record
immediately. Missing deletes are harmless because stale records expire.

## Validation and privacy

- Request bodies are limited to 8 KiB.
- Server names are limited to 48 printable characters.
- Build IDs are limited to 64 characters.
- Counts, ports, protocol versions, title IDs, and candidate types are checked.
- At most four candidates are accepted.
- Loopback, multicast, and unspecified addresses are rejected.
- XUIDs, XGI session keys, player names, game data, packets, and private files
  are not part of the public schema.
- As with any HTTPS request, the directory operator and reverse proxy can
  observe the connecting machine's source IP and request timing even though
  neither is a JSON field. Avoid enabling access logs unless they are needed,
  and set an appropriate retention policy when they are enabled.
- Hosts must explicitly choose the address they publish. The runtime must not
  silently infer and upload a local adapter address.
- Registration and host-instance tokens are random process-local capabilities,
  not user accounts. Production use is restricted to HTTPS (with loopback HTTP
  retained only for local testing); tokens are compared in constant time,
  omitted from public responses and logs, and discarded when the host leaves
  or the record expires.

## Caddy example

Caddy terminates HTTPS and forwards only HTTP API traffic to the loopback-bound
service:

```caddyfile
harmony-directory.example.com {
    encode zstd gzip
    reverse_proxy 127.0.0.1:8080
}
```

Run the service as its own unprivileged account/process. Do not configure Caddy
as a UDP 30741/30742 proxy or gameplay relay.

## Runtime integration

The opt-in Windows runtime client lives beside `SessionRecord` and
`LanDiscoveryService` in ReXGlue:

1. Host `XGISessionCreateImpl` creates and advertises the normal LAN session.
2. A background directory client registers a copy of safe metadata and sends
   heartbeats while the `SessionRecord` remains hosted.
3. `XGISessionDelete`, abandoned-host teardown, and object destruction stop the
   heartbeat and attempt authenticated deletion.
4. Transient heartbeat failures retry the same registration; an authoritative
   404 performs an idempotent recovery without exposing two searchable lobbies.
   Directory failure is still logged and ignored by LAN hosting.
5. A normal client search starts an asynchronous, short-lived directory query
   and immediately continues the normal LAN broadcast path.
6. Compatible directory candidates are probed with the existing unicast UDP
   30741 discovery packet. Real host advertisements are normalized into the
   same `SessionRecord` list as LAN results and deduplicated by session ID.
7. Harmony's original guest result list and selection path feed the selected
   session into the existing XGI join and UDP 30742 gameplay path unchanged.

Automatic registration and queries are disabled unless
`--session_directory_url` is configured. Production URLs must use HTTPS;
loopback HTTP is accepted only for local testing. The Harmony build pins the
compatibility identifier to `harmony-0.0.1.4-p1` unless an explicit config or
command-line value overrides it.

Hosting additionally requires an explicit publish address. This is deliberate:
the runtime never guesses which adapter address to disclose. While a session is
advertised, the host creates one logical registration, refreshes it every 15
seconds, and attempts deletion when hosting stops. Lost requests or responses
reuse the same per-Host-Game identity. Directory failures are warnings only and
do not stop the existing LAN host.

Windows HTTP operations use short per-stage timeouts with connection retries
disabled. Normal search never blocks on directory HTTPS: it uses the latest
completed cached result while a background refresh runs. An unreachable
directory cannot become the gameplay transport and does not disable LAN or
manual Direct Connect. The explicit directory-index debug path remains
synchronous with short timeouts.

Client search always gives manual `--direct_connect_address` priority. With a
directory URL but no selected index, compatible sessions are merged into
Harmony's original in-game search results beside LAN sessions. With
`--session_directory_session_index=<zero-based-index>`, the selected candidate
is instead probed through the existing unicast UDP 30741 exchange as a debug
fallback. The directory response is never treated as authoritative XGI session
state.

The WinHTTP client is currently built on Windows. Other platforms retain LAN
and manual Direct Connect and log that directory HTTPS access is unavailable.

## Manual paired Tailscale test

Run the service locally or behind Caddy first. For a loopback-only API test,
use `http://127.0.0.1:8080`; a two-machine test requires an HTTPS URL reachable
by both PCs.

1. Start the Desktop host with its existing verified LAN/Tailscale arguments,
   plus:

   ```text
   --session_directory_url=https://<directory-host>
   --session_directory_publish_address=<host-tailscale-ip>
   --session_directory_candidate_type=tailscale
   ```

2. Create the normal multiplayer lobby. Confirm the host log contains
   `Session directory: registered` and does not print a token or XUID.
3. Start the Ally with its existing verified LAN/Tailscale arguments, plus:

   ```text
   --session_directory_url=https://<directory-host>
   ```

4. Open multiplayer Search once and confirm the host appears in Harmony's
   original in-game session list. LAN results remain available in the same
   search.
5. Select the host normally and join without restarting the client or supplying
   a session index.
6. Verify the log shows the directory query, candidate probe, normalized host
   advertisement, `XGISessionCreateImpl`, the existing UDP 30741 join exchange,
   and then the existing UDP 30742 gameplay handshake. Play long enough to
   confirm sustained traffic. For diagnostics only, the old
   `--session_directory_session_index=0` path remains available.
7. End the host lobby. Confirm it disappears immediately, or within the
   service's 45-second expiry if shutdown prevented explicit deletion.
8. Regression-check both old paths: remove all directory arguments for LAN;
   separately use `--direct_connect_address=<host IPv4>` to confirm manual
   Direct Connect still takes priority.

Do not expose the service's loopback HTTP port directly to the internet. Caddy
terminates HTTPS for directory metadata only; it is not a UDP proxy or relay.
The directory accepts Caddy's `X-Forwarded-For` observation only when the
immediate HTTP peer is loopback, validates it as IPv4, and uses the final proxy
hop. It never accepts a public endpoint from client-supplied session JSON.

## UDP rendezvous for public online play

The same process can optionally expose a UDP rendezvous listener:

```text
python tools/master_server/server.py --host 127.0.0.1 --port 8080 \
  --rendezvous-host 0.0.0.0 --rendezvous-public-host rendezvous.example.com \
  --rendezvous-port 30740
```

`--rendezvous-host` is the local UDP bind address;
`--rendezvous-public-host` is the routable DNS name or address returned by the
HTTPS API and is required for wildcard binds. Only UDP 30740 must be exposed
for rendezvous. Caddy continues to proxy only
the HTTPS directory API; it does not proxy UDP or gameplay. Apply host/provider
rate limiting to UDP 30740 for an internet deployment.

The listener records only source endpoints observed by `recvfrom()`. It accepts
no client-selected destination and forwards no gameplay. Packets are fixed
size, replies are no larger than requests, attempts have a short TTL and global
cap, and each participant/role registration is rate bounded. Host/client and
discovery/gameplay roles remain distinct.

The HTTPS directory creates each public join attempt. `POST
/sessions/{session_id}/join-attempts` returns only the short-lived client
capability. The lobby owner polls `GET /sessions/{session_id}/join-attempts`
with its existing registration bearer token and receives only host
capabilities. Attempt IDs and the two random 16-byte capabilities are bound to
one lobby for 20 seconds. Attempts are capped per lobby, creation and UDP
registration are rate bounded, and session deletion or expiry revokes all
linked attempts. `DELETE
/sessions/{session_id}/join-attempts/{attempt_id}` retires a completed attempt
when authenticated with either participant capability.

The UDP listener accepts only attempts pre-issued by HTTPS and compares the
capability for the claimed participant in constant time. Capabilities are used
only with the rendezvous server; peer punch/ack packets use the unguessable
attempt identity and must arrive from the exact server-observed peer endpoint.
Neither participant receives the other participant's capability. Never place
capabilities in source, release launchers, logs, or long-lived configuration.

For automatic public traversal configure both builds with the normal directory
settings only:

```text
--session_directory_url=https://<directory-host>
--session_directory_build_id=<compatible-build-id>
--session_directory_candidate_type=public
```

No `nat_probe_attempt`, `nat_probe_credential`, or participant option is
required. The directory response supplies the rendezvous host and UDP port.

Both clients punch from their actual discovery and gameplay sockets. Search
retains the responding mapped discovery endpoint through Join, while gameplay
continues over Harmony's existing peer-to-peer UDP path. No relay is
implemented. Restrictive NAT/firewall configurations may still fail, and users
can retry Search after a bounded miss.
