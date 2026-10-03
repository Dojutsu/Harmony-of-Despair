// harmonyrecomp - ReXGlue Recompiled Project

#include "generated/default/harmonyrecomp_init.h"

#include "harmonyrecomp_app.h"

#if defined(__linux__)
REXCVAR_DEFINE_STRING(harmony_config_root, "", "Paths",
    "Absolute Linux configuration root; defaults to XDG_CONFIG_HOME or HOME/.config.");
#endif

REX_DEFINE_APP(harmonyrecomp, HarmonyrecompApp::Create)
