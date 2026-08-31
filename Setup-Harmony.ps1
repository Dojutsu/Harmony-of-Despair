param(
    [switch]$Setup,
    [string]$Source,
    [switch]$NoLaunch,
    [switch]$NoDialogs
)

$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$importer = Join-Path $root 'harmonyrecomp-import.exe'
$game = Join-Path $root 'harmonyrecomp.exe'

if (-not $env:LOCALAPPDATA) {
    Write-Error 'LOCALAPPDATA is unavailable; HarmonyRecomp cannot locate managed game data.'
    exit 20
}

$managedRoot = Join-Path $env:LOCALAPPDATA 'HarmonyRecomp\game-data'

function Show-SetupMessage([string]$message, [string]$title = 'HarmonyRecomp Setup') {
    Write-Host $message
    if ([Environment]::UserInteractive -and -not $NoDialogs) {
        Add-Type -AssemblyName System.Windows.Forms
        [void][System.Windows.Forms.MessageBox]::Show(
            $message, $title, 'OK', 'Information')
    }
}

function Invoke-Importer([string[]]$arguments) {
    $previousPreference = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        $output = @(& $importer @arguments 2>&1)
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    return [pscustomobject]@{ ExitCode = $exitCode; Output = $output }
}

function Test-Tu2Installation([string]$path) {
    $result = Invoke-Importer @('--verify-tu2', $path)
    return $result.ExitCode -eq 0
}

if (-not (Test-Path -LiteralPath $importer -PathType Leaf)) {
    Show-SetupMessage 'harmonyrecomp-import.exe is missing from the extracted artifact.'
    exit 21
}
if (-not (Test-Path -LiteralPath $game -PathType Leaf)) {
    Show-SetupMessage 'harmonyrecomp.exe is missing from the extracted artifact.'
    exit 22
}

$needsSetup = $Setup -or -not (Test-Tu2Installation $managedRoot)
if ($needsSetup) {
    if (-not $Source) {
        Add-Type -AssemblyName System.Windows.Forms
        $picker = [System.Windows.Forms.FolderBrowserDialog]::new()
        $picker.Description =
            'Choose the folder containing your legally owned Castlevania: Harmony of Despair Xbox 360 content files.'
        $picker.ShowNewFolderButton = $false
        if ($picker.ShowDialog() -ne [System.Windows.Forms.DialogResult]::OK) {
            Write-Host 'HarmonyRecomp setup was canceled. No game data was imported.'
            exit 0
        }
        $Source = $picker.SelectedPath
    }

    $containerValidation = Invoke-Importer @('--inspect-containers', $Source)
    if ($containerValidation.ExitCode -eq 0) {
        $importResult = Invoke-Importer @('--aggregate', $Source, '--destination', $managedRoot, '--force', '--install-dlc')
    } else {
        # Advanced fallback for an already extracted, complete TU2 hierarchy.
        $directoryValidation = Invoke-Importer @('--validate-tu2', $Source)
        if ($directoryValidation.ExitCode -ne 0) {
            $details = ($containerValidation.Output | ForEach-Object { $_.ToString() }) -join [Environment]::NewLine
            Show-SetupMessage ("HarmonyRecomp could not find a compatible base game and required TU2 update in the selected folder.`n`nOptional DLC may be absent, but the base game and TU2 update are both required.`n`n" + $details)
            exit 23
        }
        $importResult = Invoke-Importer @($Source, '--destination', $managedRoot, '--force', '--require-tu2')
    }
    if ($importResult.ExitCode -ne 0 -or -not (Test-Tu2Installation $managedRoot)) {
        $details = ($importResult.Output | ForEach-Object { $_.ToString() }) -join [Environment]::NewLine
        Show-SetupMessage ("HarmonyRecomp could not complete the local import. Any previous working installation was preserved.`n`n" + $details)
        exit 24
    }
    Write-Host "HarmonyRecomp game data was imported to: $managedRoot"
}

if ($NoLaunch) {
    exit 0
}

$settings = @{
    HARMONY_GPU_PLUGIN = 'xenos'
    HARMONY_MNK_MODE = 'true'
    HARMONY_LICENSE_MASK = '1'
    HARMONY_USER_XUID = ''
    HARMONY_USER_NAME = ''
    HARMONY_LOG_LEVEL = 'info'
    HARMONY_LOG_NOISY = 'false'
}
$config = Join-Path $root 'harmonyrecomp-user.cfg'
if (Test-Path -LiteralPath $config -PathType Leaf) {
    foreach ($line in Get-Content -LiteralPath $config) {
        if ($line -match '^\s*([A-Z_]+)=(.*)$' -and $settings.ContainsKey($Matches[1])) {
            $settings[$Matches[1]] = $Matches[2]
        }
    }
}

$arguments = @(
    "--game_data_root=$managedRoot"
    "--update_data_root=$managedRoot"
    "--gpu_plugin=$($settings.HARMONY_GPU_PLUGIN)"
    "--mnk_mode=$($settings.HARMONY_MNK_MODE)"
    "--license_mask=$($settings.HARMONY_LICENSE_MASK)"
    "--log_level=$($settings.HARMONY_LOG_LEVEL)"
    "--log_noisy=$($settings.HARMONY_LOG_NOISY)"
)
if ($settings.HARMONY_USER_XUID) { $arguments += "--user_xuid=$($settings.HARMONY_USER_XUID)" }
if ($settings.HARMONY_USER_NAME) { $arguments += "--user_name=$($settings.HARMONY_USER_NAME)" }

& $game @arguments
exit $LASTEXITCODE
