# Offline scripted controller tests

`--input_script=/absolute/path/schedule.txt` explicitly replaces input for one
process with a synthetic controller on guest user zero. Default physical input
is unchanged when this option is empty. It supports windowed and headless tests.
The ordinary schedule is loaded once before guest execution. This hook never
edits game data. Use an independent test save/config profile.

Each non-comment row has eight decimal integers:

```
milliseconds buttons LT RT LX LY RX RY
```

Time begins on the first guest XInput state poll; a row remains active until the
next row. Buttons are the Xbox bitmask (Start16, A4096, B8192, X16384, Y32768,
up1, down2, left4, right8). Triggers are0..255 and axes -32768..32767.
Always add a release row. Timestamps must strictly increase, be within one hour;
file size is bounded256KiB and total row count4096. Invalid initial input rejects
the driver setup and logs the parse failure.

## Optional Linux live append

`--input_script_append=true` opts into a bounded local-file reload during state
polls, at most once per250ms. It defaults tofalse. The file must be a regular
file owned by the runtime UID with no group/other permissions (use mode0600).
Symlinks and replacement inodes are rejected. The accepted byte prefix,
including comments and already accepted future actions, must remain unchanged.
There is no listener, control socket, watcher thread or network service.

A newline commits a row; an incomplete final line remains pending. Every newly
accepted extension must start strictly after the current script time and end
with a fully neutral row (all seven control values zero); the initial live
schedule must also end neutral. Append a press and
its future release together. A complete press with a partial/missing release
is retained as pending input without publishing the press. All limits apply
to the full schedule, including previously accepted rows. Failed reloads retain
the previous schedule and its releases; repeated errors with the same reason
are suppressed, and diagnostics never print rejected file contents.

The first guest poll logs `Offline controller append clock` with the local
monotonic clock, process ID, device/inode identity, and whether a fixture clock
was supplied. UI-only sampling may reload but cannot start this clock.

`tools/append_input_script.py` is an optional local helper. Run it on the same
Linux host as the title, using the owned schedule and a bounded runtime log
containing exactly one clock anchor. It checks the live owned process, prevents
PID-reuse/stale anchors, uses O_NOFOLLOW and the exact device/inode, and appends
one future press/release pair without truncating or replacing the file.
It uses a minimum1000ms lead and a50..10000ms hold (default150ms).
For example, save the JSON receipt from:

```
python3 -B tools/append_input_script.py append --script schedule.txt \
  --anchor-log runtime.log --buttons 4096 > append-receipt.json
python3 -B tools/append_input_script.py verify --manifest append-receipt.json \
  --runtime-log runtime.log
```

A receipt records the clock/file identity, exact source packets, planned rows,
and SHA256 of the prior prefix, appended tail and resulting scheduled prefix.
It records scheduling, not runtime acceptance. Verification requires actual
`Offline controller transition` records with the expected source packets and
button masks; raw UI and `UI-consumed` records cannot establish guest delivery.
Existing logs record button masks only, so this helper's verification qualifies
button delivery, not trigger/axis values. Copy a bounded log containing the
anchor and relevant records if the runtime log exceeds64MiB. The helper never
rewrites a rejected/pending tail; inspect it before scheduling another pair.

## Qualification

The Linux `scripted_input_reload_test` target exercises the actual driver and
InputSystem. An externally prepared foreign-owner file can be supplied with
`--wrong-owner /path`; normal unprivileged runs report that case as skipped when
no file is supplied, and never require chown or root. The optional helper test
is `scripted_input_append_helper`. Both are included in the Linux local preset;
older packages may omit these executables/helpers.

These hooks permit guest navigation without a human holding a controller.
They do not themselves prove title menus, gameplay, synchronization or physical
controller support. Record actual title state/screens/logs and source commits.
