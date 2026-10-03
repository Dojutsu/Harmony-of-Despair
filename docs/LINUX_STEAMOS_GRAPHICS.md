# Bounded SteamOS graphics deployment

Build on BuildServer in the pinned Steamrt4 SDK `4.0.20260805.254769` with Clang
`19.1.7`. The Ally remains a runtime target. This workflow does not install
packages, change SteamOS protections, restart Steam/Gamescope, alter Steam Input
or add permanent Steam shortcuts.

First package the committed build with `tools/linux-steamos/package_startup.py`
inside `run_steamrt4.py`. Select `--l3`, which also includes the production L2
recovery fixtures.
Keep artifacts, archives and receipts outside source repositories. The package
records both Git commits, dependency pins and every ELF hash, including the
pinned loader. Run `deploy_startup.py --bundle <archive> --output-directory
<external-receipt-directory>` to install and qualify the immutable build through
the existing L1/L2 tests. A graphics run uses that already verified build ID.

Run the graphical probe from BuildServer:

```sh
python3 -B tools/linux-steamos/deploy_graphics.py \
  --target harmony-ally \
  --build-id <verified-build-id> \
  --mode gaming \
  --arg=--graphics-probe \
  --arg='{run}/runtime.log' \
  --timeout 30 \
  --output-directory <external-receipt-directory>
```

The target defaults to the existing SSH alias with strict host-key checking and
batch authentication. `--ssh-config`, `--identity` and `--known-hosts` select
existing transport configuration when needed; no keys or credentials enter the
bundle. The default deployment root is the established deck-user directory
`/home/deck/.local/share/harmony-dev`.

`--mode gaming` requires one active local graphical logind session and a live
same-session Gamescope process. It refuses a KDE desktop session rather than
switching modes. An explicitly authorized current Desktop Mode probe uses
`--mode desktop`; it is recorded as Desktop Mode evidence, not Gaming Mode
acceptance. The harness never changes sessions.

The launcher discovers the current session each time, imports only selected
graphics/session variables from a verified same-user Steam, Gamescope, KWin or
Plasma process, and validates the runtime directory, Wayland/X11 socket and
session bus. It excludes arbitrary inherited loader/preload, Steam compatibility
and overlay variables. Authentication files are checked by metadata; their
contents are never read or reported. No display number, session ID or socket
name is compiled into Harmony. SDL chooses its normal video backend. An explicit
`--video-driver wayland|x11` is available for evidence-based comparison and is
recorded in the receipt.

Each run verifies the installed manifest and copies its payload into its own
`logs/<run-id>/payload` directory. The process uses that copy's pinned ELF loader
and library path; HOME, temporary, config, data and cache paths are confined to
the run. Vulkan's installed device driver remains a platform dependency. The
graphics trace must report the backend, extensions, device, surface and
presentation outcome; a loader/driver mismatch is a diagnostic failure, not a
reason to silently swap arbitrary libraries.

The bounded probe creates the real Harmony SDL window and uses the existing
Xenos/Vulkan presentation path. Its clear/present frame proves presentation; it
does not establish title boot, gameplay, networking, controller mapping or audio
playback. The observation interval is fixed at three seconds. The harness timeout is
independent and remains conservative.

Stdout, stderr, runtime logs and a JSON deployment receipt return to BuildServer.
The receipt records the discovered session, exact argv/environment, build/source
identity, exit or signal status and timeout. The launcher owns an isolated
process group, cleans its remaining children and removes its temporary payload.
It never kills Steam, Gamescope or processes by name. A serialized launch lock
prevents concurrent ownership confusion; a stale launcher run is terminated only
when its PID, UID, start time, process group and command hash still match the
recorded identity. A reused or changed PID is refused.

Accepted immutable builds and organized evidence logs remain under the owned
development root. Reconnecting SSH and repeating the command rediscovers current
session values; no reboot, mode change or service restart is part of the test.

Run harness safety checks in the pinned runner:

```sh
python3 -B -m unittest discover \
  -s "$HARMONY_SOURCE/tools/linux-steamos" -p 'test_deploy*.py' -v
```

These checks cover session selection/refusal, socket ownership, injected
environment exclusion, immutable payload tampering, stale PID refusal,
timeouts/cleanup, unrelated-process preservation and failure-log capture. They
complement the unchanged L1/L2 deployment tests.
