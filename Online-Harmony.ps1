param([switch]$FunctionsOnly)

$ErrorActionPreference = 'Stop'
$script:companionRoot = $PSScriptRoot

function Test-OnlineCode([string]$Code) {
    return $Code -cmatch '^[ABCDEFGHJKMNPQRSTUVWXYZ23456789]{6}$'
}

function Test-OnlineSnapshot($Value, [scriptblock]$FindProcess = { param($Id) Get-Process -Id $Id -ErrorAction Stop }) {
    try {
        if ($Value.schema_version -ne 1 -or $Value.process_id -le 0 -or
            $Value.process_start_time -notmatch '^\d+$' -or
            $Value.mode -notin @('offline', 'hosting', 'joined') -or
            $Value.local_player.name -isnot [string] -or $Value.local_player.name.Length -gt 48 -or
            $Value.player_count -ne @($Value.members).Count -or
            @($Value.members).Count -gt 64 -or $Value.max_players -lt 0) { return $false }
        foreach ($member in $Value.members) {
            if ($member.xuid -notmatch '^[0-9A-F]{16}$' -or
                $member.name -isnot [string] -or $member.name.Length -gt 48 -or
                $member.is_host -isnot [bool] -or
                $member.is_host -ne ($member.xuid -ceq $Value.host_xuid)) { return $false }
        }
        $process = & $FindProcess ([int]$Value.process_id)
        return $process.ProcessName -eq 'harmonyrecomp' -and
            $process.StartTime.ToUniversalTime().ToFileTimeUtc().ToString() -ceq [string]$Value.process_start_time
    } catch { return $false }
}

function Get-OnlineSnapshots([string]$Directory) {
    if (-not (Test-Path -LiteralPath $Directory -PathType Container)) { return }
    foreach ($file in Get-ChildItem -LiteralPath $Directory -Filter 'online-status-*.json' -File) {
        try {
            # Open with delete sharing so atomic replacement is never impeded.
            $stream = [IO.File]::Open($file.FullName, 'Open', 'Read',
                ([IO.FileShare]::ReadWrite -bor [IO.FileShare]::Delete))
            try {
                if ($stream.Length -gt 65536) { continue }
                $reader = [IO.StreamReader]::new($stream)
                try { $snapshot = $reader.ReadToEnd() | ConvertFrom-Json }
                finally { $reader.Dispose() }
            } finally { $stream.Dispose() }
            if ($file.Name -ceq "online-status-$($snapshot.process_id).json" -and
                (Test-OnlineSnapshot $snapshot)) { $snapshot }
        } catch { # Missing/replaced/invalid files are simply not live state.
        }
    }
}

function Get-OnlineView($Snapshot, [string]$PersistedName) {
    if ($null -eq $Snapshot) {
        return [pscustomobject]@{ Name = $PersistedName; Status = 'Offline'; Code = ''; Party = '0 / 0'; Rows = @() }
    }
    $rows = @(foreach ($member in $Snapshot.members) {
        $name = [string]$member.name
        if (-not $name) { $name = 'Player ...' + $member.xuid.Substring(12) }
        [pscustomobject]@{ Badge = $(if ($member.is_host) { 'HOST' } else { '' }); Name = $name }
    })
    $code = ''
    if ($Snapshot.mode -eq 'hosting' -and (Test-OnlineCode $Snapshot.invite_code)) { $code = $Snapshot.invite_code }
    return [pscustomobject]@{
        Name = $Snapshot.local_player.name
        Status = @{ offline = 'Offline'; hosting = 'Hosting'; joined = 'Joined' }[$Snapshot.mode]
        Code = $code; Party = "$($Snapshot.player_count) / $($Snapshot.max_players)"; Rows = $rows
    }
}

function Get-OnlineAction([string]$Action, [string]$Code, [bool]$GameRunning) {
    if ($Action -notin @('play', 'join', 'configure')) { throw 'Unknown launcher action.' }
    if ($Action -ne 'configure' -and $GameRunning) {
        throw 'Play and Join by Code are launch-time actions. Close the current Harmony game first.'
    }
    $arguments = @('-NoLogo', '-NoProfile', '-STA', '-ExecutionPolicy', 'Bypass',
        '-File', ('"' + (Join-Path $script:companionRoot 'Setup-Harmony.ps1') + '"'))
    if ($Action -eq 'join') {
        $Code = $Code.Trim().ToUpperInvariant()
        if (-not (Test-OnlineCode $Code)) { throw 'Enter a valid six-character invite code.' }
        $arguments += @('-JoinByInviteCode', '-InviteCode', $Code)
    } elseif ($Action -eq 'configure') { $arguments += '-Configure' }
    return $arguments
}

function Read-OnlinePlayerName {
    $name = & powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File (Join-Path $script:companionRoot 'Setup-Harmony.ps1') -ReadPlayerName
    if ($LASTEXITCODE -ne 0) { return '(not configured)' }
    if (-not $name) { return '(not configured)' }
    return [string]$name
}

function Start-OnlineCompanion([scriptblock]$OnShown) {
    if (-not $env:LOCALAPPDATA) { throw 'LOCALAPPDATA is unavailable.' }
    Add-Type -AssemblyName System.Windows.Forms
    Add-Type -AssemblyName System.Drawing
    [Windows.Forms.Application]::EnableVisualStyles()
    $form = [Windows.Forms.Form]::new()
    $form.Text = 'Harmony Online'
    $form.ClientSize = [Drawing.Size]::new(430, 510)
    $form.FormBorderStyle = 'FixedDialog'
    $form.MaximizeBox = $false
    $form.StartPosition = 'CenterScreen'
    $form.Font = [Drawing.Font]::new('Segoe UI', 10)
    function LabelAt([string]$text, [int]$x, [int]$y, [int]$width = 400) {
        $control = [Windows.Forms.Label]::new()
        $control.Text = $text; $control.SetBounds($x, $y, $width, 25)
        $form.Controls.Add($control); return $control
    }
    function ButtonAt([string]$text, [int]$x, [int]$y, [int]$width = 115) {
        $control = [Windows.Forms.Button]::new()
        $control.Text = $text; $control.SetBounds($x, $y, $width, 30)
        $form.Controls.Add($control); return $control
    }
    $player = LabelAt '' 16 16 265
    $change = ButtonAt 'Change Name' 295 12
    $hint = LabelAt 'Name changes apply on the next launch.' 16 46
    $status = LabelAt 'Offline' 16 80 175
    $play = ButtonAt 'Play' 295 76
    $instances = [Windows.Forms.ComboBox]::new()
    $instances.DropDownStyle = 'DropDownList'; $instances.SetBounds(16, 115, 394, 28)
    $form.Controls.Add($instances)
    $invite = LabelAt 'Invite Code: -' 16 159 265
    $copy = ButtonAt 'Copy Code' 295 154
    $inviteInput = [Windows.Forms.TextBox]::new()
    $inviteInput.MaxLength = 256; $inviteInput.CharacterCasing = 'Upper'; $inviteInput.SetBounds(16, 202, 155, 28)
    $form.Controls.Add($inviteInput)
    $join = ButtonAt 'Join by Code' 186 199 224
    $party = LabelAt 'PARTY  0 / 0' 16 247
    $roster = [Windows.Forms.ListView]::new()
    $roster.View = 'Details'; $roster.FullRowSelect = $true; $roster.HeaderStyle = 'None'
    $roster.SetBounds(16, 276, 394, 175)
    [void]$roster.Columns.Add('', 65); [void]$roster.Columns.Add('', 305)
    $form.Controls.Add($roster)
    $note = LabelAt 'Unknown names appear as Player ...XXXX.' 16 467
    $state = @{ Name = (Read-OnlinePlayerName); Code = ''; Action = $null; InstanceKeys = ''; LastView = '' }
    $directory = Join-Path $env:LOCALAPPDATA 'HarmonyRecomp'
    $refresh = {
        if ($state.Action -and $state.Action.HasExited) {
            if ($state.Action.ExitCode -ne 0) { [void][Windows.Forms.MessageBox]::Show('The launcher did not complete successfully.', 'Harmony Online') }
            $state.Action.Dispose(); $state.Action = $null
            $state.Name = Read-OnlinePlayerName
        }
        $snapshots = @(Get-OnlineSnapshots $directory | Sort-Object process_id)
        $keys = ($snapshots | ForEach-Object { "$($_.process_id):$($_.process_start_time)" }) -join ','
        if ($keys -cne $state.InstanceKeys) {
            $selected = [string]$instances.SelectedItem
            $instances.Items.Clear()
            foreach ($snapshot in $snapshots) { [void]$instances.Items.Add("Harmony PID $($snapshot.process_id)") }
            if ($instances.Items.Contains($selected)) { $instances.SelectedItem = $selected }
            elseif ($snapshots.Count) { $instances.SelectedIndex = 0 }
            $state.InstanceKeys = $keys
        }
        $instances.Visible = $snapshots.Count -gt 1
        $snapshot = $null
        if ($instances.SelectedIndex -ge 0 -and $instances.SelectedIndex -lt $snapshots.Count) { $snapshot = $snapshots[$instances.SelectedIndex] }
        $view = Get-OnlineView $snapshot $state.Name
        $state.Code = $view.Code
        $player.Text = 'Player: ' + $view.Name
        $status.Text = $view.Status; $invite.Text = 'Invite Code: ' + $(if ($view.Code) { $view.Code } else { '-' })
        $copy.Enabled = [bool]$view.Code; $party.Text = 'PARTY  ' + $view.Party
        $signature = $view.Rows | ConvertTo-Json -Compress
        if ($signature -cne $state.LastView) {
            $roster.BeginUpdate(); $roster.Items.Clear()
            foreach ($row in $view.Rows) {
                $item = [Windows.Forms.ListViewItem]::new($row.Badge)
                [void]$item.SubItems.Add($row.Name); [void]$roster.Items.Add($item)
            }
            $roster.EndUpdate(); $state.LastView = $signature
        }
        $play.Enabled = -not $state.Action; $join.Enabled = -not $state.Action
        $change.Enabled = -not $state.Action
    }
    $launch = {
        param($action)
        try {
            $running = @(Get-Process -Name harmonyrecomp -ErrorAction SilentlyContinue).Count -gt 0
            $arguments = Get-OnlineAction $action $inviteInput.Text $running
            $start = [Diagnostics.ProcessStartInfo]::new()
            $start.FileName = Join-Path $PSHOME 'powershell.exe'
            $start.Arguments = $arguments -join ' '
            $start.UseShellExecute = $false; $start.CreateNoWindow = $true
            $state.Action = [Diagnostics.Process]::Start($start)
            & $refresh
        } catch { [void][Windows.Forms.MessageBox]::Show($_.Exception.Message, 'Harmony Online') }
    }
    $play.Add_Click({ & $launch 'play' })
    $join.Add_Click({ & $launch 'join' })
    $change.Add_Click({ & $launch 'configure' })
    $copy.Add_Click({
        & $refresh
        if (Test-OnlineCode $state.Code) {
            try { [Windows.Forms.Clipboard]::SetText($state.Code) }
            catch { [void][Windows.Forms.MessageBox]::Show('Clipboard unavailable. Please try again.', 'Harmony Online') }
        }
    })
    $timer = [Windows.Forms.Timer]::new(); $timer.Interval = 1000
    $timer.Add_Tick({ & $refresh })
    if ($OnShown) { $form.Add_Shown({ & $OnShown $form }) }
    try { & $refresh; $timer.Start(); [void]$form.ShowDialog() }
    finally {
        $timer.Stop(); $timer.Dispose(); $form.Dispose()
        # Dispose the observation handle only; never terminate the launcher/game.
        if ($state.Action) { $state.Action.Dispose() }
    }
}

if (-not $FunctionsOnly) { Start-OnlineCompanion }
