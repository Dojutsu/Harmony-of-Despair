#pragma once

#include <rex/ppc/context.h>

// ReXGlue mid-assembly hook ABI. Guest addresses use the low 32 register bits.
bool HarmonySkipAbsentSceneNotification(PPCRegister& scene);
