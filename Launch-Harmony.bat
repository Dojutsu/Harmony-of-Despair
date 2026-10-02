@echo off
setlocal

set "HARMONY_ROOT=%~dp0"
set "HARMONY_SETUP_ARG="

if "%~1"=="" (
  powershell.exe -NoLogo -NoProfile -STA -ExecutionPolicy Bypass -File "%HARMONY_ROOT%Setup-Harmony.ps1" -NoLaunch
  if errorlevel 1 goto :launcher_exit
  powershell.exe -NoLogo -NoProfile -STA -ExecutionPolicy Bypass -File "%HARMONY_ROOT%Online-Harmony.ps1"
  goto :launcher_exit
)

if /i "%~1"=="--online" (
  powershell.exe -NoLogo -NoProfile -STA -ExecutionPolicy Bypass -File "%HARMONY_ROOT%Online-Harmony.ps1"
  exit /b
)

if /i "%~1"=="--setup" (
  set "HARMONY_SETUP_ARG=-Setup"
) else if /i "%~1"=="--reimport" (
  set "HARMONY_SETUP_ARG=-Setup"
) else if /i "%~1"=="--configure" (
  set "HARMONY_SETUP_ARG=-Configure"
) else if /i "%~1"=="--join-code" (
  set "HARMONY_SETUP_ARG=-JoinByInviteCode"
) else if /i "%~1"=="--show-invite" (
  set "HARMONY_SETUP_ARG=-ShowInviteCode"
) else if not "%~1"=="" (
  echo Usage: Launch-Harmony.bat [--setup^|--configure^|--join-code^|--show-invite^|--online]
  exit /b 2
)

powershell.exe -NoLogo -NoProfile -STA -ExecutionPolicy Bypass ^
  -File "%HARMONY_ROOT%Setup-Harmony.ps1" %HARMONY_SETUP_ARG%

set "HARMONY_EXIT_CODE=%ERRORLEVEL%"
if not "%HARMONY_EXIT_CODE%"=="0" (
  echo.
  echo HarmonyRecomp setup or launch failed with exit code %HARMONY_EXIT_CODE%.
  if not defined HARMONY_NO_PAUSE pause
)

exit /b %HARMONY_EXIT_CODE%

:launcher_exit
exit /b %ERRORLEVEL%
