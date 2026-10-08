# Protected direct LAN

The native Linux adapter authenticates possession of a private invitation for
an expected host XUID and one expected client XUID. This grants access to that
private group; it does not prove Xbox Live account ownership. Each client gets
a distinct grant. Only that client's identity can use it. The host retains its
own file containing up to five grants. No directory, DNS, broadcast secret,
rendezvous, third-party relay, or public control service is needed.

## Create and import a private group

From the companion Harmony checkout, generate a fresh group using the local
profile XUIDs (these arguments are hexadecimal):

```
python3 -B tools/private_lan_invitation.py \
  --directory /absolute/private/invitations \
  --host-xuid 0009000000000001 \
  --client-xuid 0009000000000002 \
  --client-xuid 0009000000000003
```

The new leaf directory must not exist. It is created as same-owner 0700, with
`host.hpli` and each `client-<xuid>.hpli` as 0600 single-link regular files.
Transfer only the matching client's file through an existing trusted private
channel. Keep the host file private. Invitations expire after one day by
default; `--expires-in` accepts 1–604800 seconds. Generate a fresh group when a
new trust grant is required. Revocation of one member removes its current
session admission; possession of a still-valid invitation permits a fresh
join. Replace the group invitation to revoke that continuing trust grant.

The native loader requires absolute symlink-free paths, a same-owner 0700
parent, a same-owner private non-executable single-link regular file, and exact
bounded contents. It rejects expired/far-future invitations, duplicate XUIDs,
selectors or secrets, zero values and trailing bytes. Keys are cleansed when
native objects are destroyed. No key is a cvar, argument, discovery field or
log message. Configure only the private file path.

## Launch

Use separate local profiles and distinct configured `user_xuid` values. The
runtime uint64 cvar takes decimal values; the example hexadecimal XUIDs above
are 2533274790395905, 2533274790395906 and 2533274790395907 in decimal. Preserve
the normal legitimate game-data, renderer, controller and license arguments.
Set the host's physical private IPv4 explicitly on both devices; no host DNS
lookup or broadcast discovery is needed.

Host additions:

```
--user_xuid=2533274790395905 --lan_online=true
--private_lan_invitation_file=/absolute/private/invitations/host.hpli
--private_lan_allow_legacy_diagnostics=false
--lan_bind_address=192.168.1.10 --lan_discovery_port=30741 --lan_gameplay_port=30742
--session_directory_url=
```

Client additions:

```
--user_xuid=2533274790395906 --lan_online=true
--private_lan_invitation_file=/absolute/private/invitations/client-0009000000000002.hpli
--private_lan_allow_legacy_diagnostics=false
--lan_bind_address=192.168.1.11 --direct_connect_address=192.168.1.10
--lan_discovery_port=30741 --lan_gameplay_port=30742 --session_directory_url=
```

Direct routes accept loopback/RFC1918 IPv4 and exact nonzero endpoints. Leave
host firewall/router/service configuration unchanged. Offline local session
creation needs no grant. Grant-free external gameplay UDP is closed by default.
`private_lan_allow_legacy_diagnostics=true` explicitly selects the old raw LAN
path for isolated diagnostics; it is not a protected multiplayer setting.
A configured invalid or expired invitation always fails closed, even if legacy
diagnostics are requested. Actual offline title semantics are still unverified;
local session creation alone is not evidence that a stage can be played.

## Protocol and publication

Private v3 UDP frames are exactly 1,440 bytes. Their fixed authenticated 40-byte
header exposes protocol/version, direction, a random recipient selector,
fresh 96-bit nonce and fixed length. The selector chooses one of at most five
distinct grants; it contains no XUID or session identity and rotates with fresh
invitations. Addresses, timing and the grant-lifetime selector remain visible.
Names, title/session identity, participants, ephemeral keys, proofs, ticket
keys and fixed checked padding are AES-256-GCM ciphertext. Configured private
mode never invokes the legacy parser or accepts raw gameplay while admission
is pending. Outer keys use RFC 5869 HKDF-SHA-256 extract/expand with distinct
request/reply context. Inner possession-authenticated X25519/AES-GCM envelopes
protect independent per-pair traffic keys. Possession proofs bind operation,
full session/incarnation, member, role, endpoint, recipient key and exact RPC.

Fresh RPCs use a stable random 64-bit prefix and monotonic 64-bit sequence.
Older signed renewals cannot extend host liveness. Exact retries preserve reply
availability without renewing liveness. Sixty seconds of silence retires a
member and its links; admission generations are bounded to 256. Retained links
preserve traffic counters/replay state, keys, capabilities and physical routes.
A fresh join after departure gets a fresh challenge, generation and affected
pair keys. Tickets expire after 30 seconds; the worker renews once per second.
All input is exact-size bounded and all trust effects follow authentication.

Publication stages roster, authority, arbitration, socket cipher and direct
routes, then commits only prepared moves/swaps in lock order gameplay → record
→ route → private authority → arbitration. Provider/allocation/stale object/
invalid route/callback failures preserve prior state. Private client control
uses one owned socket across join, register, renew and leave, preserving exact
native endpoint continuity. Shutdown joins bounded workers and revokes scopes.

## Validation and limits

Pinned Steam Runtime 4 SDK: 483/483 CTests passed, including production two-peer
search/join/register/renew/leave, exact retained-record handling and grant-free
pending gameplay refusal. Three separate production LAN services plus actual
XSocket processes passed all six synthetic encrypted directions for 36.068
seconds, including wrong grant, authenticated wrong-client identity, opaque
MITM, legacy/oversize downgrade, actual UDP departure, retired replay, fresh
socket/key/challenge rejoin and renewal past the original lease. All exits zero.
Run `harmony/tools/private_lan_discovery_audit.py` inside the pinned runner.
The test proxy retains bounded opaque ciphertext in memory only. No fixture
file carries session claims or traffic keys. Production privacy/authentication
uses the real adapter, not a test API.

This does not execute Castlevania title code, menus, stages, saves, controllers
or SteamOS hardware. Actual title offline and synchronized stage gameplay remain
required before multiplayer or the project can be called playable. The adapter
is Linux-native; other platforms currently fail closed for this private mode.
