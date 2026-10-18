# HarmonyRecomp

HarmonyRecomp is a native recompilation of *Castlevania: Harmony of Despair*
(Xbox 360 Live Arcade) for PC, Linux/SteamOS, Mac, Android and iPhone/iPad,
with online co-op between all of them.

This repository and its releases do **not** include the original game. You
must supply files from your own legally obtained Xbox 360 copy (see
[Bring your own game](#bring-your-own-game)).

## Where the code lives

| Platform | Game branch | Runtime branch |
| --- | --- | --- |
| Windows PC and Linux / SteamOS | `master` | `rexglue-sdk/windows-private-lan` |
| Mac (Apple Silicon) | `full-send-comp/macos` | `rexglue-sdk/macos` |
| Android | `full-send-comp/android-port` | `rexglue-sdk/android-port` |
| iPhone / iPad | `full-send-comp/ios` | `rexglue-sdk/ios` |

The game code lives on the `full-send-comp/*` branches (and `master`) and the
ReXGlue runtime on the `rexglue-sdk/*` branches. GitHub Actions builds the PC
and Linux packages from `master` and the Mac app from `full-send-comp/macos`.
iPhone/iPad builds are made locally with Xcode.

## Downloads

Ready-to-play download packages for each platform will be available on the
Releases page. You still need your own game files (see below).

## Launcher

Every platform opens to the same simple start screen: a player name box, one
**Play** button, and an invite-code box for joining a friend. Game-file setup
appears only until your game files are installed.

On PC, start the game with `Harmony of Despair.exe`. It runs setup the first
time, then opens the start screen, with no console window. Windows may say
"Windows protected your PC" the first time because the launcher isn't signed;
click **More info**, then **Run anyway**. `Launch-Harmony.bat` still works as a
backup.

Touch-screen devices get on-screen controls: a D-pad in menus, a joystick that
appears where your thumb lands during stages, optional vibration, and a camera
zoom button.

## Bring your own game

You need these files from your own copy:

- the base Arcade package (Title ID `58410A7A`, Media ID `6480C08F`, version
  `0.0.1.4`)
- the matching Title Update 2 package (to version `0.0.2.4`)
- any DLC packages you own (optional)

File names do not matter; the importer identifies packages by their Xbox
metadata. Other base versions and title updates are not supported yet.

### Windows first run

1. Download and extract `HarmonyRecomp-windows-amd64.zip` to a normal writable
   folder. Do not put the original game files inside it.
2. Double-click `Harmony of Despair.exe` (`Launch-Harmony.bat` still works).
   On first open Windows may say "Windows protected your PC"; click
   **More info**, then **Run anyway**.
3. The first time, choose the folder with your Harmony of Despair content
   files. The game is checked and installed into
   `%LOCALAPPDATA%\HarmonyRecomp\game-data`, along with any DLC found.
4. Enter a player name and press **Play**, or type a friend's invite code to
   join them.

Later launches skip setup and go straight to the start screen.
`"Harmony of Despair.exe" --setup` re-imports from a different folder;
`"Harmony of Despair.exe" --configure` changes the player name or language
(English, Japanese, German, French, Spanish or Italian).

Your player name and a random player ID are stored in
`%LOCALAPPDATA%\HarmonyRecomp\launcher-profile.cfg`. The ID is not based on
your username, machine, network address or hardware, and stays the same across
updates.

### Other platforms

Mac, Android and iPhone/iPad builds show the same first-run setup inside the
app: pick the folder with your game files (on mobile, copy them to the device
first) and the app installs them. Linux/SteamOS notes are in
[docs/LINUX_STEAMOS_STARTUP.md](docs/LINUX_STEAMOS_STARTUP.md) and
[docs/LINUX_STEAM_LAUNCH.md](docs/LINUX_STEAM_LAUNCH.md).

## Game-data location

- Windows: `%LOCALAPPDATA%\HarmonyRecomp\game-data`
- Linux: `$XDG_DATA_HOME/HarmonyRecomp/game-data` or
  `~/.local/share/HarmonyRecomp/game-data`
- Mac: `~/Library/Application Support/HarmonyRecomp`

Delete that folder to uninstall the game data; setup runs again on next
launch.

## Advanced import

The launcher is the normal path. The importer can also be run directly:

```powershell
.\harmonyrecomp-import.exe --inspect-containers "D:\Owned Harmony Content"
.\harmonyrecomp-import.exe --aggregate "D:\Owned Harmony Content" --force --install-dlc
.\harmonyrecomp-import.exe --verify
```

Imports are staged and verified before they replace a working installation,
so a failed import never breaks an existing one. An already extracted
complete TU2 folder is accepted as a fallback.

For development, point the game at a complete extracted game-data folder:

```powershell
.\harmonyrecomp.exe --game_data_root="D:\path\to\complete-game-data" --license_mask=1
```

An explicit `--game_data_root` always wins over the per-user default.
`harmonyrecomp-user.example.cfg` lists advanced runtime settings; ordinary
setup never needs it.

## What is private and what is redistributable

The original `default.xex`, the Xbox 360 player DLLs and the game assets stay
private, user-owned data; the runtime loads them from your installation. The
native HarmonyRecomp executable, the recompiled module libraries and the
ReXGlue runtime are project output and can be shared. Release packaging uses
an explicit allowlist and fails if any original game executable or DLL slips
in. HarmonyRecomp never downloads or uploads game data.

## Troubleshooting

- **Wrong game selected:** make sure the package is *Castlevania: Harmony of
  Despair*, not another Castlevania title.
- **Unsupported version:** keep your files; support can be added later.
- **Missing file:** re-import from the complete original package.
- **Disk full or folder not writable:** free space or check permissions, then
  run setup again.

Do not get replacement files from unofficial download sites.
