// harmonyrecomp - ReXGlue Recompiled Project

#include "generated/default/harmonyrecomp_init.h"

#include "harmonyrecomp_app.h"

#if defined(__APPLE__)
REXCVAR_DEFINE_STRING(harmony_config_root, "", "Paths",
    "Absolute macOS configuration root; defaults to HOME/Library/Application Support.");
// The Mac app has no separate launcher: the start screen is the launcher.
REXCVAR_DEFINE_BOOL(harmony_start_screen, true, "General",
    "Show the start screen (player name, Play, join by invite code) and play online.");
#elif defined(__linux__)
REXCVAR_DEFINE_STRING(harmony_config_root, "", "Paths",
    "Absolute Linux configuration root; defaults to XDG_CONFIG_HOME or HOME/.config.");
REXCVAR_DEFINE_BOOL(harmony_start_screen, false, "General",
    "Show the start screen (player name, Play, join by invite code) and play online.");
#endif

REX_DEFINE_APP(harmonyrecomp, HarmonyrecompApp::Create)
