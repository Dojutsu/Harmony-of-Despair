# Native protected direct LAN

This candidate provides production private UDP discovery/admission and encrypted
per-pair gameplay transport. Tests use synthetic payloads. Actual title stages,
offline title behavior and SteamOS hardware are still integration requirements.
The legacy directory control path is separate; it does not have the opaque
metadata guarantees of this private mode.

Generate fresh host and distinct client invitations from configured local XUIDs:

```
python3 -B tools/private_lan_invitation.py \
  --directory /absolute/private/new-group \
  --host-xuid 0009000000000001 \
  --client-xuid 0009000000000002
```

Only give `client-0009000000000002.hpli` to that client, through an existing
trusted private channel. This file grants possession-based membership, not Xbox
Live account ownership. Keep `host.hpli` private. Default lifetime is one day;
`--expires-in` accepts 1–604800 seconds. Current-session departure retires traffic
keys; a still-valid invitation permits a fresh join. Replace the group to revoke
the continuing invitation trust grant.

On the recipient, keep the transferred file in a same-owner 0700 directory,
with mode 0600, no symlinks and only one hard link. Import into a new directory:

```
python3 -B tools/private_lan_invitation.py \
  --import-file /absolute/private/received/client-0009000000000002.hpli \
  --directory /absolute/private/installed-group \
  --local-xuid 0009000000000002
```

Import validates exact bounded contents, owner/mode/link/path, expiry and the
expected local XUID before creating output. Existing groups are never replaced.
Neither command prints secrets; output is only the generated/imported file path.
Do not put file contents in Git, command arguments, cvars, screenshots or logs.

Launch with normal legitimate asset, renderer, controller and license arguments
after `--`. These helpers preserve the working directory and exec the native
executable; they do not install dependencies or alter the host/network.

Host:

```
python3 -B tools/private_lan_launch.py --game /absolute/path/HarmonyRecomp \
  --mode host --invitation /absolute/private/new-group/host.hpli \
  --xuid 0009000000000001 --name Host --bind-ip 192.168.1.10 -- <normal-game-options>
```

Client:

```
python3 -B tools/private_lan_launch.py --game /absolute/path/HarmonyRecomp \
  --mode client --invitation /absolute/private/installed-group/client-0009000000000002.hpli \
  --xuid 0009000000000002 --name Client --bind-ip 192.168.1.11 \
  --host-ip 192.168.1.10 -- <normal-game-options>
```

The helper uses hexadecimal XUID input and passes the runtime's decimal uint64
cvar correctly. It validates expected grant role/XUID, private literal addresses,
ports and display name; it prevents additional arguments overriding protected
network/profile settings. It removes inherited network/profile cvar environment
values and explicitly disables raw legacy mode, directory and manual rendezvous.
Discovery/gameplay defaults are UDP 30741/30742. The same discovery port is needed
on each peer. Only loopback/RFC1918 IPv4 is supported in this direct mode.
No DNS, broadcast metadata, third-party service, relay, telemetry or router
change is needed. `--check` validates without executing and makes no hardware
claim. Select/Create the team in the ordinary game menu; no admin service exists.

Offline launch consumes no invitation:

```
python3 -B tools/private_lan_launch.py --game /absolute/path/HarmonyRecomp \
  --mode offline -- <normal-game-options>
```

This selects local sign-in and no external multiplayer configuration. Native
local session creation passes without grants; actual title-stage offline
semantics remain unverified. Missing/invalid grants fail closed for multiplayer.
Normal gameplay UDP stays protected pending admission. The old raw LAN path is
available only with explicit `private_lan_allow_legacy_diagnostics=true` for
isolated diagnostics; never select it as a protected multiplayer fallback.

Validation: 20 invitation/import/launch Python tests passed in the pinned Steam
Runtime 4. Merged retained-send/invitation SDK full525/525 CTests passed. Three independent real production LAN
services and XSocket processes exchanged all six synthetic encrypted directions
for 36.072 seconds, rejected wrong grants/spoof/MITM/downgrade, registered actual
arbitration, departed with nine opaque replies deliberately dropped, recovered
through exact-request leave retry, rejected eighteen captured retired requests,
rejoined with fresh socket/key/challenge and renewed beyond the original lease.
All processes exited zero. Run `tools/private_lan_discovery_audit.py` inside the
pinned runner with the built unit executable and a fresh private output directory.
Actual game stages and synchronized title gameplay have not run in this candidate.
