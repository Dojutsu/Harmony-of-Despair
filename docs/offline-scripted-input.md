# Offline scripted controller tests

`--input_script=/absolute/path/schedule.txt` explicitly replaces input for one
process with a synthetic controller on guest user zero. Default physical input
is unchanged when this option is empty. It supports windowed and headless tests.
No listener, remote command facility, polling file watcher or telemetry is added.
The schedule is loaded once before guest execution and never edits game data.
Use an independent test save/config profile.

Each non-comment row has eight decimal integers:

```
milliseconds buttons LT RT LX LY RX RY
```

Time begins on the first guest XInput state poll; a row remains active until the
next row. Buttons are the Xbox bitmask (Start16, A4096, B8192, X16384, Y32768,
up1, down2, left4, right8). Triggers are0..255 and axes -32768..32767.
Always add a release row. Timestamps must strictly increase, be within one hour;
file size is bounded256KiB and row count4096. Invalid input disables input and
logs the parse failure, without substituting an accepted schedule.

This hook permits real guest navigation without a human holding a controller.
It does not itself prove menus, gameplay, synchronization or physical controller
support. Record actual title state/screens/logs and the tested source commits.
