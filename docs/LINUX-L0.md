# Linux x86-64 L0 SDK preparation

The `linux-steamos-amd64-l0` preset prepares the SDK and its existing native tests in the pinned Steam Linux Runtime 4 SDK with Clang 19. This is a build and regression-test boundary. It does not establish that a recompiled game works on Linux.

Use the verified SDK environment runner supplied by the consuming project. Set `REXGLUE_LINUX_BUILD_ROOT` to an absolute, writable directory outside this source repository. The runner must mount that directory for build outputs and expose this source tree and its initialized pinned dependencies. The preset is available on Linux only when the variable is set. Use it on a native x86-64 build host; ARM64 and cross compilation are outside this preset's scope.

The preset inherits the existing Linux `-march=x86-64-v2` CPU requirement and uses `clang-19`/`clang++-19`. The pinned SDK environment supplies the exact compiler and C++23 standard-library versions. Vulkan stays enabled; optional FidelityFX, Tracy and performance-counter instrumentation are disabled for this preparation build. Existing Windows and other platform presets retain their settings.

From the SDK source directory, inside that environment:

```sh
cmake --preset linux-steamos-amd64-l0
cmake --build --preset linux-steamos-amd64-l0-sdk --parallel 4
cmake --build --preset linux-steamos-amd64-l0-unit --parallel 4
ctest --preset linux-steamos-amd64-l0-local --show-only
ctest --preset linux-steamos-amd64-l0-local
```

The unit build compiles every existing `unit_tests` source and the existing `xgi_slot_array_test` and `accepted_invite_kernel_test` executables, including the SDK-consumer ReXApp compile check. No test sources, assertions or runtime adapters are replaced. The separate SDK build includes the real `rexglue` code generator.

The local CTest preset excludes only nine reviewed broadcast cases and two hidden gameplay fixtures by their exact current names. It retains loopback networking tests and unrelated native unit tests. Check the discovered inventory before execution, and review new or renamed networking tests before treating them as local-only. A missing test or skipped group is not passing coverage. Windows-only tests remain gated by their existing source/build conditions.

Run the nine broadcast cases separately in an isolated BuildServer network environment:

```sh
ctest --preset linux-steamos-amd64-l0-broadcast-isolated --show-only
ctest --preset linux-steamos-amd64-l0-broadcast-isolated
```

The hidden worker and three-peer gameplay fixtures require their own explicit fixture readiness checks and are excluded from both presets. The whole unit suite is still built; execution selection does not remove tests from source. Record all failures, including existing expectation failures, without changing behavior or weakening assertions to obtain a pass.

PPC instruction tests retain their existing build registration. Enabling SDK tests still checks the shipped Linux PowerPC assembler/linker during configuration. Building the named unit targets does not build the PPC generated test executable. PPC execution needs a separate explicit build/test run and must not be claimed from these presets.

Build caches, executables and install staging reside under `$REXGLUE_LINUX_BUILD_ROOT/sdk`. Keep that directory separate for different SDK revisions or toolchains. Linux loader, guest ABI, multiplayer protocol, Windows code paths and production deployment policy are unchanged by these presets.
