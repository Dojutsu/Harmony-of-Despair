#pragma once
#include <rex/system/xam/session.h>
namespace rex::system::xam {
struct LegacyLanDiagnosticsScope {
  bool previous=REXCVAR_GET(private_lan_allow_legacy_diagnostics);
  LegacyLanDiagnosticsScope(){REXCVAR_SET(private_lan_allow_legacy_diagnostics,true);}
  ~LegacyLanDiagnosticsScope(){REXCVAR_SET(private_lan_allow_legacy_diagnostics,previous);}
};
}
