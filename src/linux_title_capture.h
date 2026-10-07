#pragma once
#if defined(__linux__)
#include <thread>
namespace rex::ui { class Presenter; }
namespace harmony {
// Explicit local test capture: guest output only, never the compositor/desktop.
std::jthread StartLinuxTitleCapture(rex::ui::Presenter* presenter);
}
#endif
