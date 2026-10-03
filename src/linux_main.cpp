// Linux entry point: the normal SDL/title path remains the default.
#include <cstdio>
#include <string_view>

#include "generated/default/harmonyrecomp_init.h"
#include "linux_graphics.h"
#include "linux_startup.h"
#include <rex/ui/windowed_app.h>

int main(int argc, char** argv) {
  if (argc > 1 && std::string_view(argv[1]) == "--graphics-probe") {
    if (argc != 3) {
      std::fputs("usage: harmonyrecomp --graphics-probe /absolute/run/runtime.log\n", stderr);
      return 2;
    }
    return harmony::RunLinuxGraphicsProbe(argv[2]);
  }
  if (argc > 1 && (std::string_view(argv[1]) == "--startup-probe" ||
                   std::string_view(argv[1]) == "--guest-probe")) {
    if (argc != 3) {
      std::fputs("usage: harmonyrecomp --startup-probe|--guest-probe /absolute/run/runtime.log\n", stderr);
      return 2;
    }
    return std::string_view(argv[1]) == "--guest-probe"
        ? harmony::RunLinuxGuestProbe(PPCImageConfig, argv[2])
        : harmony::RunLinuxStartupProbe(PPCImageConfig, argv[2]);
  }
  return rex::ui::RunWindowedApp(argc, argv);
}
