param(
    [switch]$Setup,
    [string]$Source,
    [switch]$Configure,
    [switch]$JoinByInviteCode,
    [switch]$ShowInviteCode,
    [switch]$ReadPlayerName,
    [string]$PlayerName,
    [string]$GameLanguage,
    [string]$InviteCode,
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
$activeInvitePath = Join-Path $profileRoot 'active-invite-code.txt'

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

function Test-HarmonyPlayerName([string]$value) {
    if ($null -eq $value) { return $false }
    $trimmed = $value.Trim()
    if ($trimmed -cnotmatch '^[\x20-\x7E]{1,15}$') { return $false }

    # Keep this deliberately small: whole tokens, or a word split only by
    # obvious separators. Do not search inside unrelated words or infer leetspeak.
    $prohibited = @(
        'fuck', 'shit', 'cunt', 'motherfucker', 'bitch',
        'porn', 'rape', 'blowjob', 'pussy', 'penis', 'vagina',
        'nigger', 'nigga', 'faggot', 'fag', 'kike', 'chink', 'spic'
    )
    $tokens = @($trimmed.ToLowerInvariant() -split '[ _.-]+' | Where-Object { $_ })
    foreach ($token in $tokens) {
        if ($token -in $prohibited) { return $false }
    }
    if (($tokens -join '') -in $prohibited) { return $false }
    return $true
}

function Test-HarmonyLanguage([string]$value) {
    return $value -match '^[1-6]$'
}

function Read-LauncherProfile {
    $profile = @{ Xuid = ''; Name = ''; Language = '' }
    if (Test-Path -LiteralPath $profilePath -PathType Leaf) {
        foreach ($line in Get-Content -LiteralPath $profilePath) {
            if ($line -match '^\s*HARMONY_USER_XUID=(\d+)\s*$') {
                $profile.Xuid = $Matches[1]
            } elseif ($line -match '^\s*HARMONY_USER_NAME=(.*)$') {
                $profile.Name = $Matches[1].Trim()
            } elseif ($line -match '^\s*HARMONY_USER_LANGUAGE=(.*)$') {
                $profile.Language = $Matches[1].Trim()
            }
        }
    }
    return $profile
}

if ($ReadPlayerName) {
    # Read-only companion query. Reuse the profile parser without importing,
    # creating an identity, or applying any configuration changes.
    $storedName = (Read-LauncherProfile).Name
    if (Test-HarmonyPlayerName $storedName) { Write-Output $storedName }
    exit 0
}

function Write-LauncherProfile([string]$xuid, [string]$name, [string]$language) {
    # A manually edited profile can reach this writer during XUID creation.
    # Preserve its other fields, but never persist an unvalidated player name.
    if ($name -and -not (Test-HarmonyPlayerName $name)) { $name = '' }
    [void](New-Item -ItemType Directory -Path $profileRoot -Force)
    $temporaryProfile = "$profilePath.$([Guid]::NewGuid().ToString('N')).tmp"
    try {
        $profileLines = @(
            '# Generated per-install player identity. These values are not credentials.'
            "HARMONY_USER_XUID=$xuid"
            "HARMONY_USER_NAME=$name"
        )
        if (Test-HarmonyLanguage $language) {
            $profileLines += "HARMONY_USER_LANGUAGE=$language"
        }
        $contents = (@($profileLines) + '') -join "`r`n"
        [IO.File]::WriteAllText($temporaryProfile, $contents, [Text.UTF8Encoding]::new($false))
        Move-Item -LiteralPath $temporaryProfile -Destination $profilePath -Force
    } finally {
        if (Test-Path -LiteralPath $temporaryProfile -PathType Leaf) {
            Remove-Item -LiteralPath $temporaryProfile -Force
        }
    }
}

function Read-PlayerInput([string]$title, [string]$prompt, [string]$defaultValue,
                          [string]$providedValue) {
    if ($providedValue) { return $providedValue }
    if ($NoDialogs -or -not [Environment]::UserInteractive) { return '' }
    Add-Type -AssemblyName Microsoft.VisualBasic
    return [Microsoft.VisualBasic.Interaction]::InputBox($prompt, $title, $defaultValue)
}

function Show-HarmonySettings([string]$currentName, [string]$currentLanguage) {
    Add-Type -AssemblyName System.Windows.Forms
    Add-Type -AssemblyName System.Drawing
    [System.Windows.Forms.Application]::EnableVisualStyles()
    $form = [System.Windows.Forms.Form]::new()
    $form.Text = 'HarmonyRecomp Settings'
    $form.ClientSize = [System.Drawing.Size]::new(330, 170)
    $form.FormBorderStyle = 'FixedDialog'
    $form.MaximizeBox = $false
    $form.MinimizeBox = $false
    $form.StartPosition = 'CenterScreen'
    $form.Font = [System.Drawing.Font]::new('Segoe UI', 9)
    try {
        $nameLabel = [System.Windows.Forms.Label]::new()
        $nameLabel.Text = 'Player Name'
        $nameLabel.SetBounds(16, 12, 290, 20)
        $form.Controls.Add($nameLabel)
        $nameBox = [System.Windows.Forms.TextBox]::new()
        $nameBox.Text = $currentName
        $nameBox.SetBounds(16, 34, 298, 25)
        $form.Controls.Add($nameBox)
        $languageLabel = [System.Windows.Forms.Label]::new()
        $languageLabel.Text = 'Game Language (applies on next launch)'
        $languageLabel.SetBounds(16, 68, 298, 20)
        $form.Controls.Add($languageLabel)
        $languageBox = [System.Windows.Forms.ComboBox]::new()
        $languageBox.DropDownStyle = 'DropDownList'
        $languageBox.SetBounds(16, 91, 298, 25)
        [void]$languageBox.Items.AddRange([object[]]@(
            'Use default (English)', 'English', 'Japanese', 'German',
            'French', 'Spanish', 'Italian'))
        $languageBox.SelectedIndex = if (Test-HarmonyLanguage $currentLanguage) { [int]$currentLanguage } else { 0 }
        $form.Controls.Add($languageBox)
        $save = [System.Windows.Forms.Button]::new()
        $save.Text = 'Save'
        $save.SetBounds(158, 129, 75, 28)
        $save.DialogResult = [System.Windows.Forms.DialogResult]::OK
        $form.Controls.Add($save)
        $cancel = [System.Windows.Forms.Button]::new()
        $cancel.Text = 'Cancel'
        $cancel.SetBounds(239, 129, 75, 28)
        $cancel.DialogResult = [System.Windows.Forms.DialogResult]::Cancel
        $form.Controls.Add($cancel)
        $form.AcceptButton = $save
        $form.CancelButton = $cancel
        if ($form.ShowDialog() -ne [System.Windows.Forms.DialogResult]::OK) { return $null }
        return [pscustomobject]@{
            Name = $nameBox.Text.Trim()
            Language = if ($languageBox.SelectedIndex -eq 0) { '' } else { [string]$languageBox.SelectedIndex }
        }
    } finally {
        $form.Dispose()
    }
}

if ($ShowInviteCode) {
    $activeCode = ''
    if (Test-Path -LiteralPath $activeInvitePath -PathType Leaf) {
        $activeCode = ([IO.File]::ReadAllText($activeInvitePath)).Trim()
    }
    if ($activeCode -match '^[ABCDEFGHJKMNPQRSTUVWXYZ23456789]{6}$') {
        Show-SetupMessage "Invite Code: $activeCode" 'HarmonyRecomp Invite Code'
    } else {
        Show-SetupMessage 'No active hosted session.' 'HarmonyRecomp Invite Code'
    }
    exit 0
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

$launcherProfile = Read-LauncherProfile
try {
    if (-not $launcherProfile.Xuid) {
        $launcherProfile.Xuid = New-HarmonyXuid
        Write-LauncherProfile $launcherProfile.Xuid $launcherProfile.Name $launcherProfile.Language
    } elseif (-not (Test-HarmonyXuid $launcherProfile.Xuid)) {
        throw "The launcher profile does not contain a valid HARMONY_USER_XUID: $profilePath"
    }
} catch {
    Write-Warning ("Persistent player identity is unavailable; HarmonyRecomp will use its runtime fallback for this launch. " + $_.Exception.Message)
    $launcherProfile.Xuid = ''
}

$settings = @{
    HARMONY_GPU_PLUGIN = 'xenos'
    HARMONY_MNK_MODE = 'true'
    HARMONY_LICENSE_MASK = '1'
    HARMONY_USER_XUID = $launcherProfile.Xuid
    HARMONY_USER_NAME = $launcherProfile.Name
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
$explicitUserName = $false
if (Test-Path -LiteralPath $config -PathType Leaf) {
    foreach ($line in Get-Content -LiteralPath $config) {
        if ($line -match '^\s*([A-Z_]+)=(.*)$' -and $settings.ContainsKey($Matches[1])) {
            $settings[$Matches[1]] = $Matches[2]
            if ($Matches[1] -eq 'HARMONY_USER_NAME' -and $Matches[2]) {
                $explicitUserName = $true
            }
        }
    }
}

# A process-scoped environment value is the most explicit launcher override.
foreach ($name in @($settings.Keys)) {
    $environmentValue = [Environment]::GetEnvironmentVariable($name, 'Process')
    if (-not [string]::IsNullOrEmpty($environmentValue)) {
        $settings[$name] = $environmentValue
        if ($name -eq 'HARMONY_USER_NAME') { $explicitUserName = $true }
    }
}

if ($settings.HARMONY_USER_XUID -and -not (Test-HarmonyXuid $settings.HARMONY_USER_XUID)) {
    Show-SetupMessage 'HARMONY_USER_XUID must be a nonzero unsigned decimal 64-bit value with bits 54 and 55 clear.'
    exit 25
}

if ($Configure) {
    if (-not $launcherProfile.Xuid) {
        Show-SetupMessage 'A persistent player identity is required before the player name can be changed.'
        exit 27
    }
    if ($NoDialogs -or -not [Environment]::UserInteractive -or
        $PSBoundParameters.ContainsKey('PlayerName') -or
        $PSBoundParameters.ContainsKey('GameLanguage')) {
        if (-not $PlayerName -and -not $PSBoundParameters.ContainsKey('GameLanguage')) { exit 0 }
        $configuredName = if ($PlayerName) { $PlayerName.Trim() } else { $launcherProfile.Name }
        $configuredLanguage = if ($PSBoundParameters.ContainsKey('GameLanguage')) {
            if ($GameLanguage -eq 'default') { '' } else { $GameLanguage }
        } else { $launcherProfile.Language }
    } else {
        $selectedSettings = Show-HarmonySettings $launcherProfile.Name $launcherProfile.Language
        if ($null -eq $selectedSettings) { exit 0 }
        $configuredName = $selectedSettings.Name
        $configuredLanguage = $selectedSettings.Language
    }
    if (-not (Test-HarmonyPlayerName $configuredName)) {
        Show-SetupMessage 'Please choose a different player name (1-15 printable ASCII characters).'
        exit 27
    }
    if ($configuredLanguage -and -not (Test-HarmonyLanguage $configuredLanguage)) {
        Show-SetupMessage 'Game language must be an ID from 1 through 6.'
        exit 27
    }
    Write-LauncherProfile $launcherProfile.Xuid $configuredName $configuredLanguage
    Show-SetupMessage 'Launcher settings saved. Changes apply on the next launch.'
    exit 0
}

if (-not $explicitUserName -and -not (Test-HarmonyPlayerName $settings.HARMONY_USER_NAME)) {
    $selectedName = Read-PlayerInput 'HarmonyRecomp Player Name' 'Choose a player name (1-15 printable ASCII characters):' '' $PlayerName
    $selectedName = $selectedName.Trim()
    if (-not (Test-HarmonyPlayerName $selectedName)) {
        Show-SetupMessage 'Please choose a different player name (1-15 printable ASCII characters).'
        exit 27
    }
    if ($launcherProfile.Xuid) {
        Write-LauncherProfile $launcherProfile.Xuid $selectedName $launcherProfile.Language
        $launcherProfile.Name = $selectedName
    }
    $settings.HARMONY_USER_NAME = $selectedName
} elseif ($settings.HARMONY_USER_NAME -and -not (Test-HarmonyPlayerName $settings.HARMONY_USER_NAME)) {
    Show-SetupMessage 'Please choose a different player name (1-15 printable ASCII characters).'
    exit 27
} else {
    $settings.HARMONY_USER_NAME = $settings.HARMONY_USER_NAME.Trim()
}

if ($JoinByInviteCode) {
    $selectedCode = Read-PlayerInput 'HarmonyRecomp Invite Code' 'Enter the six-character invite code:' '' $InviteCode
    $settings.HARMONY_SESSION_DIRECTORY_INVITE_CODE = $selectedCode.Trim().ToUpperInvariant()
    if (-not $settings.HARMONY_SESSION_DIRECTORY_INVITE_CODE) { exit 0 }
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
if (Test-HarmonyLanguage $launcherProfile.Language) {
    $arguments += "--user_language=$($launcherProfile.Language)"
}
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
