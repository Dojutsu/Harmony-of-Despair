#include "scene_cache_hook.h"

bool HarmonySkipAbsentSceneNotification(PPCRegister& scene) {
  // An idle scene manager has no screen to notify. Preserve all register state
  // and the generated behavior for every nonzero guest pointer.
  return scene.u32 == 0;
}
