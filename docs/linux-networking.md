# Linux networking validation

The Full-Send-Comp Linux runtime retains the existing discovery, invite,
member admission, gameplay authorization and per-peer UDP protocol. Directory
hosting now uses the same portable host loop on Linux with libcurl and secure
`getrandom` identities. An empty `session_directory_url` still disables it;
this change adds no default service, telemetry, relay or host exposure.

Linux translates Xbox socket option and ioctl numbers and BE32/BE16 values,
Winsock last-error codes, and guest select handle arrays/timeouts. `poll`/`ppoll`
avoid the native `FD_SETSIZE` limit. Native closure atomically invalidates the
handle once; explicit close followed by destruction cannot close a recycled fd.
The existing guest cancellation lock and NAT detach barrier remain authoritative.
This does not establish arbitrary concurrent synchronous native-call/close
parity: a thread holding a descriptor snapshot outside those owners still needs
lifetime coordination. Physical Windows regression has not run here.

Remote-input fixes reject oversized Linux discovery datagrams instead of
accepting their copied prefix, reject wrong-type registration/heartbeat fields
without throwing out of the directory worker, and publish terminal overlapped
receive errors with zero bytes and one event signal. Guest receive errors keep
source/query output buffers intact. Packets and HMAC domains are unchanged.

## Reproduce in the isolated project

From Full-Send-Comp, prepare the pinned userspace with its build instructions,
then run:

```sh
scripts/dev-exec.sh /bin/sh -ec '
  cd "$HARMONY_SDK"
  cmake --preset linux-steamos-amd64-l0
  cmake --build "$HARMONY_BUILD_ROOT/sdk" --config Debug \
    --target unit_tests recvfrom_lifetime_test -j 2
  "$HARMONY_BUILD_ROOT/sdk/bin/Debug/recvfrom_lifetime_test"
  "$HARMONY_BUILD_ROOT/sdk/bin/Debug/unit_tests" "[network],[directory]" --reporter compact
'
scripts/dev-exec.sh /bin/sh -ec '
  cd "$HARMONY_SOURCE"
  python3 -B -m tools.gameplay_traversal_audit.integration \
    --unit-tests "$HARMONY_BUILD_ROOT/sdk/bin/Debug/unit_tests" \
    --output-directory "$HARMONY_BUILD_ROOT/network-integration-new"
'
```

The output directory must be new. `dev-exec.sh` uses a private network namespace
with external networking disabled, read-only source mounts and private build
outputs. The integration HTTP and UDP services bind loopback only.

## Verified 2026-10-07

- 71 network/directory cases, 2,788 assertions passed in Debug.
- The portable real guest receive fixture passed pending/incomplete/completion,
  reused initiation storage, payload/source/event, synchronous receive,
  cancellation before/after queued data and a waiting query unblocked by close.
- Guest entry tests passed Xbox options/ioctls, BE timeout preservation,
  read/write/exception arrays, high native descriptors, capacity/invalid-handle
  rejection, 64-entry/duplicate handling, Winsock errors, preserved receive
  error outputs and terminal-error event publication exactly once.
- Three isolated native processes used the production directory/admission/NAT
  stack, retired discovery attempts, kept three distinct gameplay endpoints
  behind one IPv4, and exchanged unchanged 39-byte synthetic payloads over all
  three bidirectional peer pairs. Clean teardown returned zero in every process.

Receipts are under Full-Send-Comp `build/Debug/network-*.log` and
`build/Debug/network-integration/validation.json`. These are transport tests,
not title stage entry or synchronized game logic. Actual Harmony multiplayer
stage/gameplay, controller/audio/render behavior and SteamOS hardware validation
remain separate acceptance requirements. LAN identities and admission do not
prove ownership of an Xbox account/XUID; no new guarantee is asserted here.
