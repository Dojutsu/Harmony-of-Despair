# HarmonyRecomp

HarmonyRecomp is a native recompilation project for *Castlevania: Harmony of
Despair*. This repository and its releases do not include the original game.

## Bring your own game

You must provide files from your own legally obtained Xbox 360 copy. The
companion importer accepts either:

- the original Xbox 360 STFS/LIVE package; or
- a complete directory you extracted from that package.

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

The currently supported base-game identity is:

- Title ID: `58410A7A`
- Media ID: `6480C08F`
- Version: `0.0.1.4`

Other legitimate versions and title updates will receive a clear unsupported
version error until they are individually tested and added to the compatibility
table.

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

The native HarmonyRecomp executable, recompiled `.so` module libraries, and
ReXGlue runtime libraries are redistributable project output. GitHub Actions
packages only an explicit allowlist and fails if any `.xex` or original
`.dll` appears.

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
