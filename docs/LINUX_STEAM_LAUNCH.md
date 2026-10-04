# Steam-managed native Linux qualification launch

Use the existing immutable Steamrt4 package; do not rebuild the title for Steam
integration. Owned TU2 data stays external to source/package/Steam shortcut data.

The physical Ally has one private Non-Steam entry, **Harmony L4 Qualification**,
created by Steam itself. Its executable is the user-owned
`/home/deck/.local/share/harmony-dev/bin/harmony-l4.sh`. That wrapper calls
`steam_title.py` with the immutable build ID, external data root, persistent
profile root, explicit SDL backend and a maximum 300-second bound. The existing
`deploy_graphics.py` must be alongside it. The launcher verifies the registered
Steam reaper/app identity, verifies current Gaming Mode, preserves Steam's
owned game DISPLAY/XAUTHORITY endpoints, and uses the package's pinned loader
and library closure. It does not forge an app ID or modify Gamescope focus.

The deployed command is equivalent to:

```sh
/usr/bin/python3 -B steam_title.py \
  --root /home/deck/.local/share/harmony-dev \
  --build-id l4config-85d3a87-779b6f9 \
  --data-root /home/deck/.local/share/harmony-dev/game-data/owned-tu2-4169faa807a6 \
  --profile-root /home/deck/.local/share/harmony-dev/runtime/l4-20261003 \
  --video-driver x11 --timeout 300
```

Logs/receipts and copied per-run package payloads live under `logs/steam-*`;
payloads are removed after execution. Config/save/cache paths stay in the external
profile. A deadline remains recorded as a timeout even if native shutdown exits 0.
`--graphics-probe` runs the existing 32-frame probe instead of owned title data.
The default backend is Wayland; the qualified Steam-managed Gaming Mode command
explicitly selects X11 on Steam's isolated game display. Direct Desktop/Wayland
launch support is unchanged. Do not hardcode a display number: Steam supplied
`:1` in the qualifying run, independently of Steam UI's `:0`.

## Native entry creation and preservation

Before adding an entry, inspect ownership and preserve exact existing
`userdata/<current-user>/config/shortcuts.vdf` bytes/mode, or record absence.
Do not read authentication state or manually edit Steam's binary configuration.
Use Steam's Add Non-Steam Game UI or the already installed SteamOS
`steamos-add-to-steam` mechanism. The installed helper uses the native
`steam://addnonsteamgame/<encoded-desktop-path>` URI and a temporary handshake
file. A URI alone is insufficient on the inspected client. Steam consumes the
handshake and generates its own shortcut/app ID; no restart was needed.

The development `bin/steam-entry.json` stores only the generated app ID, entry
name, expected reaper path and shortcut provenance. It is local deployment
metadata, never a committed Steam configuration file. Do not invent an ID or
reuse an unrelated application's identity. Register and inspect the one matching
entry before writing that metadata; reject unknown configuration formats.

## Reversal and current qualification limit

In Steam, select **Harmony L4 Qualification → Manage → Remove Non-Steam Game**.
Remove only that entry, preserving any later additions. The original shortcut
state is recorded under `runtime/steam-l4-registration/`; initially both
shortcuts.vdf and its backup were absent. Never restore an old whole file over
new user entries. Retain the entry while the user needs it for testing.
The original and revised wrapper files are preserved in the development root;
owned game data and saves are not removed with the entry.

Gaming Mode X11 probe passes 32 presentations and reports focus. The real native
title becomes Gamescope-selected, visibly reaches its splash screen, and physical
Start advances it toward the main menu. It then safely rejects a new cross-page
8-byte store, `std r29,28(r7)`, at guest 0x42A19FFC, split 4+4, with exit 86. This write
class remains excluded. Do not call this complete menu/input/audio qualification
or begin L5. Preserve the trace and investigate that access contract separately.
