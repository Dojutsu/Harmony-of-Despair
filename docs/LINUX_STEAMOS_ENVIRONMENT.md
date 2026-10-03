# Linux SteamOS build environment

The `port/linux-steamos` branch prepares Linux x86-64 compilation with the
existing SDL3/Vulkan/input/audio implementations. Windows production remains a
separate workflow. This environment does not launch the game, import game data,
change saves, or establish controller/audio/gameplay/WAN acceptance. Linux ARM64
and Android ARM64 remain later targets.

## Pinned SDK userspace

`tools/linux-steamos/steamrt4.lock.json` selects official Steam Runtime 4 SDK
**4.0.20260805.254769** and its exact archive SHA-256:

```text
d105e579c1261755714b403bafd842e9acb3d79d5a13df869693818a49b72379
```

The archive is 1,117,449,485 bytes and extracts about 3.4 GB of regular files.
Tools include Clang 19.1.7, libstdc++ 14.2.0, glibc 2.41, CMake 3.31.6 and Ninja
1.12.1. This Linux compiler is separate from Windows production Clang 22.1.8.
Do not replace dependencies with newer versions to bypass a build failure.

Requirements for bootstrap: Linux x86-64, Python 3.9 or newer, GNU tar, sufficient
external disk space, and HTTPS access to the official pinned archive unless a
verified local copy is supplied. No host package installation is performed.

Choose environment and build directories outside both source repositories and
Git metadata. Paths below are examples to replace with local paths:

```sh
HARMONY_STEAMRT4_ROOT=/path/outside/source/steamrt4
HARMONY_LINUX_BUILD_ROOT=/path/outside/source/linux-steamos-build
HARMONY_LINUX_SDK_SOURCE=/path/to/rexglue-sdk
python3 -B tools/linux-steamos/bootstrap_steamrt4.py --root "$HARMONY_STEAMRT4_ROOT"
```

Bootstrap downloads only the versioned official URL in the lock, verifies size
and SHA-256, checks archive member paths/types, and extracts into a new `sysroot/`.
It preserves merged-usr symlinks and checks the SDK build ID. It records verified
provenance beside the sysroot. It never overwrites or cleans an existing sysroot.
A failed extraction remains available for diagnosis. Absolute symlink targets in
the SDK are interpreted in the container root; do not run SDK binaries directly
against the host filesystem.

Reuse an existing archive with `--archive /path/to/the-pinned-archive.tar.gz`.
`--verify-only` reports archive verification without writing. To adopt an already
extracted copy, use `--verify-existing` with the exact archive: every archived
regular file is hash/size/mode checked, along with symlinks and hardlinks, before
provenance is recorded. Extra disposable files outside archived paths may remain.
No author-owned files are removed.

## Dedicated Docker runner

The runner requires a working local Docker daemon and the exact Alpine 3.20
carrier image recorded by both immutable registry digest and image ID in the lock.
Provision that image when Docker storage is available:

```sh
docker pull --platform linux/amd64 alpine@sha256:d9e853e87e55526f6b2917df91a2115c36dd7c696a35be12163d44e6e2a4b6bc
docker image inspect alpine@sha256:d9e853e87e55526f6b2917df91a2115c36dd7c696a35be12163d44e6e2a4b6bc --format '{{.Id}}'
```

The inspected image ID must equal
`sha256:bf8527eb54c3680e728d5b4b383a8ba730d72dae7236fbc8dff97ed6b224a731`.
The runner checks that ID and Linux/amd64 platform and uses `--pull never`.
It never builds a full SDK image, automatically pulls an image, prunes Docker,
changes daemon storage, or alters services. A missing image fails; the explicit
pinned pull above provisions the carrier without selecting a mutable tag.

The carrier contributes normal Docker process/device mounts. The SDK supplies
/bin, /sbin, /lib, /lib64, /usr, /etc and dpkg metadata through read-only binds.
Compiler, headers, loader and libraries therefore come from the pinned SDK;
no host /usr or /lib is mounted. Both source repositories and their common Git
worktree/submodule directories are read-only at the same absolute paths. Only the
external build directory is writable, plus bounded tmpfs /tmp. Source/build/SDK
path overlap is rejected to prevent writable aliases. Docker mount paths may have
spaces but cannot contain commas or control characters.

Containers have no network, no capabilities or Docker socket, no-new-privileges,
a read-only root, 1 GiB /dev/shm, and CPU/memory/PID limits. They use the calling UID/GID. Source
checkouts and the external build directory must be accessible to that identity
and to the Docker daemon. Run on a local daemon where supplied bind paths exist;
remote-daemon path translation is not supported. Git ownership trust is limited
to the exact two read-only source paths via process-local safe.directory settings,
with GIT_OPTIONAL_LOCKS=0; no host/global Git configuration is changed. No host GPU/input/audio devices,
user home directories, authentication files or session sockets are passed through.

Initialize the SDK's committed dependency pins outside the runner before
compilation. Keep the Windows/private SDK lock unchanged; Linux feature work uses
its separately reviewed integration ref. The runner accepts explicit source, SDK,
and build paths, and exposes HARMONY_SOURCE, HARMONY_SDK,
HARMONY_LINUX_SDK_SOURCE, HARMONY_BUILD_ROOT and REXGLUE_LINUX_BUILD_ROOT to the
container. Both L0 presets use the latter build-root variable.

Inspect the complete command without creating a container:

```sh
python3 -B tools/linux-steamos/run_steamrt4.py \
  --sysroot "$HARMONY_STEAMRT4_ROOT/sysroot" --source "$PWD" \
  --sdk "$HARMONY_LINUX_SDK_SOURCE" --build-root "$HARMONY_LINUX_BUILD_ROOT" \
  --dry-run -- /bin/sh -c 'clang-19 --version; cmake --version'
```

When Docker is available, run the existing Harmony L0 configure, compile-only
build, and portable tests:

```sh
python3 -B tools/linux-steamos/run_steamrt4.py \
  --sysroot "$HARMONY_STEAMRT4_ROOT/sysroot" --source "$PWD" \
  --sdk "$HARMONY_LINUX_SDK_SOURCE" --build-root "$HARMONY_LINUX_BUILD_ROOT" \
  -- /bin/sh -ec 'cd "$HARMONY_SOURCE"; cmake --preset linux-steamos-amd64-l0; cmake --build --preset linux-steamos-amd64-l0; ctest --preset linux-steamos-amd64-l0'
```

The Harmony build preset selects SHA-256, game-data and DLC-header tests plus
both importers and stfs_inspect. Compilation does not invoke those importers on
real data. A separate SDK invocation can change directory to "$HARMONY_SDK" and
use its `linux-steamos-amd64-l0` presets; its output is under build-root/sdk,
while Harmony output is under build-root/harmony. CPU and memory limits can be
set with `--cpus` and `--memory`; an explicit interactive shell requires
`--interactive -- /bin/bash`. Keep build logs outside source Git.

## Current validation limits

The official archive checksum, extraction, merged-usr layout and package metadata
were verified during the Linux audit. In the existing development container, a
process-local chroot using this SDK passed C++23 expected/format/byteswap,
clock_time_conversion/clock_cast, unchanged SDK chrono header compilation, ELF
inspection, and graphics/audio dependency queries. That fallback used disposable
header/output copies inside the SDK root; it did not create a dedicated container.
It shares the existing container's isolation and is not the production runner.

At preparation time, Docker container creation was blocked by its existing storage
capacity. The dedicated runner has syntax, provenance and dry-run validation only
until a real dedicated-container run is recorded. Do not label the chroot result
as dedicated-runner success. The fallback's absent /proc can affect ELF $ORIGIN
resolution and test discovery; normal Docker supplies /proc. Any temporary
LD_LIBRARY_PATH workaround belongs only to disposable fallback probes, not this
runner or production loader configuration.

Environment preparation and CMake preset changes are separate logical source
changes. No new runtime/graphics/input/audio or Windows behavior is introduced here.
