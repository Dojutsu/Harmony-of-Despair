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
$profileRoot = Join-Path $env:LOCALAPPDATA 'HarmonyRecomp'
$profilePath = Join-Path $profileRoot 'launcher-profile.cfg'

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

function Test-HarmonyXuid([string]$value) {
    if ($value -notmatch '^\d+$') {
        return $false
    }
    $parsed = [uint64]0
    if (-not [uint64]::TryParse(
            $value,
            [Globalization.NumberStyles]::Integer,
            [Globalization.CultureInfo]::InvariantCulture,
            [ref]$parsed)) {
        return $false
    }
    return $parsed -ne 0 -and ($parsed -band [uint64]0x00C0000000000000) -eq 0
}

function New-HarmonyXuid {
    $bytes = New-Object byte[] 8
    $rng = [Security.Cryptography.RandomNumberGenerator]::Create()
    try {
        do {
            $rng.GetBytes($bytes)
            # Harmony rejects XUIDs with either of bits 54 or 55 set.
            $bytes[6] = [byte]($bytes[6] -band 0x3F)
            $value = [BitConverter]::ToUInt64($bytes, 0)
        } while ($value -eq 0)
    } finally {
        $rng.Dispose()
    }
    return $value.ToString([Globalization.CultureInfo]::InvariantCulture)
}

function Get-OrCreateLauncherXuid {
    try {
        if (Test-Path -LiteralPath $profilePath -PathType Leaf) {
            foreach ($line in Get-Content -LiteralPath $profilePath) {
                if ($line -match '^\s*HARMONY_USER_XUID=(\d+)\s*$') {
                    if (Test-HarmonyXuid $Matches[1]) {
                        return $Matches[1]
                    }
                    break
                }
            }
            throw "The launcher profile does not contain a valid HARMONY_USER_XUID: $profilePath"
        }

        [void](New-Item -ItemType Directory -Path $profileRoot -Force)
        $xuid = New-HarmonyXuid
        $temporaryProfile = "$profilePath.$([Guid]::NewGuid().ToString('N')).tmp"
        try {
            [IO.File]::WriteAllText(
                $temporaryProfile,
                "# Generated per-install player identity. This value is not a credential.`r`nHARMONY_USER_XUID=$xuid`r`n",
                [Text.UTF8Encoding]::new($false))
            Move-Item -LiteralPath $temporaryProfile -Destination $profilePath
        } finally {
            if (Test-Path -LiteralPath $temporaryProfile -PathType Leaf) {
                Remove-Item -LiteralPath $temporaryProfile -Force
            }
        }
        return $xuid
    } catch {
        Write-Warning ("Persistent player identity is unavailable; HarmonyRecomp will use its runtime fallback for this launch. " + $_.Exception.Message)
        return ''
    }
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

$settings = @{
    HARMONY_GPU_PLUGIN = 'xenos'
    HARMONY_MNK_MODE = 'true'
    HARMONY_LICENSE_MASK = '1'
    HARMONY_USER_XUID = Get-OrCreateLauncherXuid
    HARMONY_USER_NAME = ''
    HARMONY_LOG_LEVEL = 'info'
    HARMONY_LOG_NOISY = 'false'
    HARMONY_LAN_ONLINE = 'true'
    HARMONY_LAN_DISCOVERY_PORT = '30741'
    HARMONY_LAN_GAMEPLAY_PORT = '30742'
    HARMONY_SESSION_DIRECTORY_URL = 'https://hod.dojutsu.net'
    HARMONY_SESSION_DIRECTORY_CANDIDATE_TYPE = 'public'
    HARMONY_SESSION_DIRECTORY_INVITE_CODE = ''
}
$config = Join-Path $root 'harmonyrecomp-user.cfg'
if (Test-Path -LiteralPath $config -PathType Leaf) {
    foreach ($line in Get-Content -LiteralPath $config) {
        if ($line -match '^\s*([A-Z_]+)=(.*)$' -and $settings.ContainsKey($Matches[1])) {
            $settings[$Matches[1]] = $Matches[2]
        }
    }
}

# A process-scoped environment value is the most explicit launcher override.
foreach ($name in @($settings.Keys)) {
    $environmentValue = [Environment]::GetEnvironmentVariable($name, 'Process')
    if (-not [string]::IsNullOrEmpty($environmentValue)) {
        $settings[$name] = $environmentValue
    }
}

if ($settings.HARMONY_USER_XUID -and -not (Test-HarmonyXuid $settings.HARMONY_USER_XUID)) {
    Show-SetupMessage 'HARMONY_USER_XUID must be a nonzero unsigned decimal 64-bit value with bits 54 and 55 clear.'
    exit 25
}

if ($NoLaunch) {
    exit 0
}

$arguments = @(
    "--game_data_root=$managedRoot"
    "--update_data_root=$managedRoot"
    "--gpu_plugin=$($settings.HARMONY_GPU_PLUGIN)"
    "--mnk_mode=$($settings.HARMONY_MNK_MODE)"
    "--license_mask=$($settings.HARMONY_LICENSE_MASK)"
    "--log_level=$($settings.HARMONY_LOG_LEVEL)"
    "--log_noisy=$($settings.HARMONY_LOG_NOISY)"
    "--lan_online=$($settings.HARMONY_LAN_ONLINE)"
    "--lan_discovery_port=$($settings.HARMONY_LAN_DISCOVERY_PORT)"
    "--lan_gameplay_port=$($settings.HARMONY_LAN_GAMEPLAY_PORT)"
    "--session_directory_url=$($settings.HARMONY_SESSION_DIRECTORY_URL)"
    "--session_directory_candidate_type=$($settings.HARMONY_SESSION_DIRECTORY_CANDIDATE_TYPE)"
)
if ($settings.HARMONY_USER_XUID) { $arguments += "--user_xuid=$($settings.HARMONY_USER_XUID)" }
if ($settings.HARMONY_USER_NAME) { $arguments += "--user_name=$($settings.HARMONY_USER_NAME)" }
if ($settings.HARMONY_SESSION_DIRECTORY_INVITE_CODE) {
    $inviteCode = $settings.HARMONY_SESSION_DIRECTORY_INVITE_CODE.ToUpperInvariant()
    if ($inviteCode -notmatch
            '^[ABCDEFGHJKMNPQRSTUVWXYZ23456789]{6}$') {
        Show-SetupMessage 'HARMONY_SESSION_DIRECTORY_INVITE_CODE must contain six invite-code characters.'
        exit 26
    }
    $arguments += "--session_directory_invite_code=$inviteCode"
}

& $game @arguments
exit $LASTEXITCODE
