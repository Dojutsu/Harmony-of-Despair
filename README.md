# HarmonyRecomp

HarmonyRecomp is a native recompilation project for *Castlevania: Harmony of
Despair*. This repository and its releases do not include the original game.

## Public online multiplayer

The canonical Windows launcher configures HarmonyRecomp's production session
directory and UDP rendezvous service automatically. It can establish a direct
peer-to-peer connection between ordinary home networks. The
in-game flow remains unchanged: the host creates a team, and the client uses
Multiplayer Search, selects the host, and joins. Rendezvous coordinates the
public discovery and gameplay endpoints; Harmony's existing UDP transport
carries gameplay directly between the players.

The rendezvous service listens on UDP 30740. A correctly configured public
deployment normally requires neither Tailscale nor manual forwarding of
Harmony's UDP 30741/30742 ports. There is currently no relay fallback, so highly
restrictive NAT or firewall configurations can still fail. A public Search may
occasionally miss while mappings are established; retrying Search is safe.

The production directory is `https://hod.dojutsu.net`. It issues short-lived,
role-specific rendezvous capabilities automatically. Host and Search obtain
their own capabilities without attempt IDs, manual credentials, or networking
edits. Test credentials, server secrets, and machine-specific addresses are
never included in release artifacts. The directory/rendezvous server does not
relay gameplay. Some carrier, hotspot, NAT, and firewall combinations can block
direct peer traffic even when rendezvous succeeds; relay support is not
currently implemented.

## Optional Windows online companion

Run `Launch-Harmony.bat --online` to open the separate Harmony Online window.
It shows the current player name, Hosting/Joined/Offline status, public host
invite code with Copy Code, and the current party roster. Play and Join by Code
use the existing launcher; close a running game before using either action.
Change Name opens the existing launcher settings for player name and game
language. Changes apply on the next launch and preserve the player XUID.

Closing this window does not close the game or change a session. Harmony works
without the companion. If several game instances are running, select a PID in
the window; their parties are never merged. `Player ...XXXX` means the runtime
does not know that member's name. Earlier guests may lack later guests' names;
no additional name-distribution networking is implemented.

The window reads bounded, process-specific JSON files under
`%LOCALAPPDATA%\HarmonyRecomp\online-status-<pid>.json`. It checks process
creation time as well as PID, so crash leftovers are not displayed as live.
The existing `--show-invite` action retains its legacy `active-invite-code.txt`
for compatibility; the new companion reads only unified status snapshots.

## Bring your own game

You must provide files from your own legally obtained Xbox 360 copy. The
companion importer accepts a folder containing the original base-game and TU2
STFS/LIVE packages, with any optional owned DLC packages, or a complete
already-extracted TU2 directory as an advanced fallback.

### Windows first run

1. Download and extract `HarmonyRecomp-windows-amd64.zip` to a normal writable
   folder. Do not place original game data inside that folder.
2. Run `Launch-Harmony.bat`.
3. On first launch, select the folder containing your legally owned Xbox 360
   Harmony of Despair content files.
4. HarmonyRecomp identifies the compatible base game and TU2 update by package
   metadata, extracts them transactionally into
   `%LOCALAPPDATA%\HarmonyRecomp\game-data`, and installs detected DLC.
5. The game starts. Future launches reuse that managed local installation and
   require no folder selection or command line. The same launcher supports
   single-player, LAN multiplayer, and automatic public multiplayer.

First launch also asks for a player name. Harmony stores the 1-15 character
name beside the persistent player XUID in
`%LOCALAPPDATA%\HarmonyRecomp\launcher-profile.cfg`. Change the name or game
language later without changing the XUID by running:

```text
Launch-Harmony.bat --configure
```

The settings window offers English, Japanese, German, French, Spanish, and
Italian. Its “Use default (English)” choice leaves the language unset and lets
ReXGlue keep its current default. A selected language is saved as
`HARMONY_USER_LANGUAGE=1` through `6` in the launcher profile and takes effect
on the next game launch. Existing profiles without this line remain unchanged;
the launcher passes no language override for them.

To join a friend's hosted session using its six-character invite code, run:

```text
Launch-Harmony.bat --join-code
```

The launcher validates the code and then uses the normal Harmony Search,
rendezvous, NAT traversal, and join path. A host can display the active code in
a separate launcher message with `Launch-Harmony.bat --show-invite`. This
reports `No active hosted session` until public directory registration has
completed.

The source folder must contain the owned base Arcade package and its matching
TU2 installer package. DLC is optional and never prevents base/TU2 setup.
Package filenames do not matter: identification uses Xbox content type, Title
ID, Media ID, version metadata, and required package contents. The importer
stages and validates a replacement before promotion, so a failed import does
not replace a working installation.

Run `Launch-Harmony.bat --setup` to choose and safely re-import a different
source. Deleting `%LOCALAPPDATA%\HarmonyRecomp\game-data` also triggers setup on
the next launch. The launcher always passes this managed directory explicitly
as both `--game_data_root` and `--update_data_root`; it never silently launches
against an incomplete base-only installation.

The optional `harmonyrecomp-user.example.cfg` contains advanced runtime
settings only. Ordinary setup does not require copying or editing a config.
`harmonyrecomp-user.cfg` remains ignored by Git because it may contain local
identity settings.

On first launch, a random non-secret player XUID is stored in
`%LOCALAPPDATA%\HarmonyRecomp\launcher-profile.cfg`. It remains stable across
normal launches, reimports, and package updates so independent installations do
not share one default multiplayer identity. It is not derived from a username,
machine identifier, network address, or hardware identifier. An explicit
`HARMONY_USER_XUID` environment value or advanced user config overrides it.

### Advanced import

The launcher is the normal setup path. The companion importer also exposes its
container discovery and aggregate operation directly:

```powershell
.\harmonyrecomp-import.exe --inspect-containers "D:\Owned Harmony Content"
.\harmonyrecomp-import.exe --aggregate "D:\Owned Harmony Content" --force --install-dlc
.\harmonyrecomp-import.exe --verify
```

An already extracted complete TU2 hierarchy remains supported as an advanced
fallback. Ordinary users do not need to extract XEX, XEXP, DLLP, or DLC files
manually.

The importer stores verified private data under
`%LOCALAPPDATA%\HarmonyRecomp\game-data`. `Launch-Harmony.bat` invokes the same
importer with TU2 validation and atomic replacement enabled.

For development, bypass the managed installation with an explicit complete
game-data directory:

```powershell
.\harmonyrecomp.exe --game_data_root="D:\path\to\complete-game-data" --license_mask=1
```

The explicit `--game_data_root` always wins. It is intentionally a development
escape hatch and does not mark or modify the selected directory.

Run:

```text
harmonyrecomp-import <package-or-directory>
```

The importer identifies the title from Xbox 360 metadata, validates the game
executable and six player modules, copies or extracts the data locally, verifies
the completed installation, and never uploads anything. It preserves the
complete source hierarchy; the seven executable files are validation anchors,
not a seven-file runtime package. A source containing only those seven private
build inputs is rejected as incomplete gameplay data.

The currently supported executable chain is:

- Title ID `58410A7A`, Media ID `6480C08F`
- base game `0.0.1.4`
- matching TU2 patch to `0.0.2.4`

Other legitimate base versions and title updates remain unsupported until they
are individually tested and added to the compatibility table.

## Private game-data location

Normal launches automatically use:

- Windows: `%LOCALAPPDATA%\HarmonyRecomp\game-data`
- Linux: `$XDG_DATA_HOME/HarmonyRecomp/game-data`, or
  `~/.local/share/HarmonyRecomp/game-data`

Verify an installation without launching:

```text
harmonyrecomp-import --verify
```

To import again, rerun with `--force`. The replacement is staged and verified
before the previous installation is removed. To uninstall the copyrighted game
data, remove the `game-data` directory above.

Developers can preserve existing workflows by passing:

```text
harmonyrecomp --game_data_root=/path/to/extracted/game
```

An explicit override always wins over the per-user default.

## What is private and what is redistributable?

The original `default.xex`, Xbox 360 player DLLs, and gameplay assets remain
private user-owned data. They are required at runtime because ReXGlue loads the
original executable/module images for Xbox metadata, data sections, imports,
and the virtual game filesystem.

The native HarmonyRecomp executable, recompiled `.so`/`.dll` module libraries,
and ReXGlue runtime libraries are redistributable project output. GitHub
Actions packages only an explicit platform allowlist and fails if any `.xex`,
original player DLL, or other unapproved executable/DLL appears.

The exact minimum gameplay-asset subset has not been derived yet. Until the
authoritative complete extraction is audited, the importer deliberately keeps
the complete package hierarchy instead of guessing or discarding files. A
verified-install marker is written only in a staging directory after identity,
version, extraction, and executable-layer validation succeed; that marked tree
is re-verified before it replaces the active installation.

## Troubleshooting

- **Wrong game selected:** confirm the package is *Castlevania: Harmony of
  Despair*, not another Castlevania title.
- **Unsupported version:** keep your files; support can be added without
  requiring an exact hash match.
- **Missing file:** re-extract or re-import from the complete original package.
- **Destination not writable or disk full:** free space and check permissions,
  then rerun the importer.
- **Custom setup:** use `--destination <directory>` when importing and launch
  with the matching `--game_data_root=<directory>`.

Do not seek replacement files from unofficial download sites. HarmonyRecomp
does not download or transmit game data.
