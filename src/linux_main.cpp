// Linux entry point: the normal SDL/title path remains the default.
#include <cstdio>
#include <string_view>

#include "generated/default/harmonyrecomp_init.h"
#include "linux_startup.h"
#include <rex/ui/windowed_app.h>

int main(int argc, char** argv) {
  if (argc > 1 && std::string_view(argv[1]) == "--startup-probe") {
    if (argc != 3) {
      std::fputs("usage: harmonyrecomp --startup-probe /absolute/run/runtime.log\n", stderr);
      return 2;
    }
    return harmony::RunLinuxStartupProbe(PPCImageConfig, argv[2]);
  }
  return rex::ui::RunWindowedApp(argc, argv);
}
