// Harmony of Despair release launcher.
// Does what Launch-Harmony.bat does, but as a windowed program, so no console
// window ever appears. The PowerShell launcher itself is unchanged.
#include <windows.h>
#include <shellapi.h>

#include <string>
#include <vector>

namespace {

constexpr wchar_t kTitle[] = L"Harmony of Despair";

void ShowError(const std::wstring& message) {
  MessageBoxW(nullptr, message.c_str(), kTitle, MB_OK | MB_ICONERROR);
}

std::wstring ModuleDirectory() {
  std::vector<wchar_t> buffer(MAX_PATH);
  for (;;) {
    DWORD length = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
    if (length == 0) return L"";
    if (length < buffer.size()) {
      std::wstring path(buffer.data(), length);
      size_t slash = path.find_last_of(L"\\/");
      return slash == std::wstring::npos ? L"" : path.substr(0, slash);
    }
    buffer.resize(buffer.size() * 2);
  }
}

std::wstring PowerShellPath() {
  wchar_t system[MAX_PATH];
  UINT length = GetSystemDirectoryW(system, MAX_PATH);
  if (length == 0 || length >= MAX_PATH) return L"";
  return std::wstring(system, length) + L"\\WindowsPowerShell\\v1.0\\powershell.exe";
}

bool FileExists(const std::wstring& path) {
  DWORD attributes = GetFileAttributesW(path.c_str());
  return attributes != INVALID_FILE_ATTRIBUTES && !(attributes & FILE_ATTRIBUTE_DIRECTORY);
}

// Runs one script with a hidden console and waits for it, as the batch file
// does. Returns the script's exit code, or -1 when it could not be started.
int RunScript(const std::wstring& powershell, const std::wstring& directory,
              const std::wstring& script, const std::wstring& extra) {
  std::wstring command = L"\"" + powershell +
                         L"\" -NoLogo -NoProfile -STA -ExecutionPolicy Bypass -File \"" +
                         directory + L"\\" + script + L"\"";
  if (!extra.empty()) command += L" " + extra;
  STARTUPINFOW startup{};
  startup.cb = sizeof(startup);
  PROCESS_INFORMATION process{};
  if (!CreateProcessW(powershell.c_str(), command.data(), nullptr, nullptr, FALSE,
                      CREATE_NO_WINDOW, nullptr, directory.c_str(), &startup, &process)) {
    return -1;
  }
  CloseHandle(process.hThread);
  WaitForSingleObject(process.hProcess, INFINITE);
  DWORD exit_code = 1;
  GetExitCodeProcess(process.hProcess, &exit_code);
  CloseHandle(process.hProcess);
  return static_cast<int>(exit_code);
}

}  // namespace

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
  const std::wstring directory = ModuleDirectory();
  const std::wstring powershell = PowerShellPath();
  if (directory.empty()) {
    ShowError(L"Harmony of Despair could not find its own folder.");
    return 1;
  }
  if (powershell.empty() || !FileExists(powershell)) {
    ShowError(L"Windows PowerShell was not found on this PC. It is required to start Harmony of Despair.");
    return 1;
  }
  for (const wchar_t* script : {L"Setup-Harmony.ps1", L"Online-Harmony.ps1"}) {
    if (!FileExists(directory + L"\\" + script)) {
      ShowError(std::wstring(script) +
                L" was not found next to Harmony of Despair.exe.\n\nExtract the whole zip and start the game from that folder.");
      return 1;
    }
  }

  // The same switches Launch-Harmony.bat accepts.
  int argc = 0;
  LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
  std::wstring option = (argv && argc > 1) ? argv[1] : L"";
  if (argv) LocalFree(argv);

  int result = 0;
  if (option.empty()) {
    result = RunScript(powershell, directory, L"Setup-Harmony.ps1", L"-NoLaunch");
    if (result == 0) result = RunScript(powershell, directory, L"Online-Harmony.ps1", L"");
  } else if (_wcsicmp(option.c_str(), L"--online") == 0) {
    result = RunScript(powershell, directory, L"Online-Harmony.ps1", L"");
  } else {
    std::wstring setup_arg;
    if (_wcsicmp(option.c_str(), L"--setup") == 0 || _wcsicmp(option.c_str(), L"--reimport") == 0) {
      setup_arg = L"-Setup";
    } else if (_wcsicmp(option.c_str(), L"--configure") == 0) {
      setup_arg = L"-Configure";
    } else if (_wcsicmp(option.c_str(), L"--join-code") == 0) {
      setup_arg = L"-JoinByInviteCode";
    } else if (_wcsicmp(option.c_str(), L"--show-invite") == 0) {
      setup_arg = L"-ShowInviteCode";
    } else {
      ShowError(L"Usage: Harmony of Despair.exe [--setup|--configure|--join-code|--show-invite|--online]");
      return 2;
    }
    result = RunScript(powershell, directory, L"Setup-Harmony.ps1", setup_arg);
    if (result > 0) {
      ShowError(L"HarmonyRecomp setup or launch failed with exit code " + std::to_wstring(result) + L".");
    }
  }
  if (result == -1) {
    ShowError(L"Windows PowerShell could not be started (error " + std::to_wstring(GetLastError()) + L").");
    return 1;
  }
  return result;
}
