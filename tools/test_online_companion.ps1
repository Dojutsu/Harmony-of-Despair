$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot '../Online-Harmony.ps1') -FunctionsOnly
$checks = 0
function Check($Condition, [string]$Message) {
    if (-not $Condition) { throw $Message }
    $script:checks++
}
$created = [datetime]::UtcNow
$snapshot = [pscustomobject]@{
    schema_version = 1; process_id = 42; process_start_time = $created.ToFileTimeUtc().ToString()
    revision = 1; mode = 'hosting'; session_state = 'lobby'; invite_code = 'AB7K2Q'
    local_player = @{ xuid = '0000000000000001'; name = 'Host' }
    player_count = 2; max_players = 6; host_xuid = '0000000000000001'
    members = @(
        [pscustomobject]@{ xuid = '0000000000000001'; name = 'Host'; is_host = $true },
        [pscustomobject]@{ xuid = '0000000000005AA1'; name = ''; is_host = $false }
    )
}
$process = [pscustomobject]@{ ProcessName = 'harmonyrecomp'; StartTime = $created }
$lookup = { param($Id) if ($Id -ne 42) { throw 'Missing PID' }; $process }
Check (Test-OnlineSnapshot $snapshot $lookup) 'Valid process rejected'
$snapshot.process_start_time = ($created.AddSeconds(-1)).ToFileTimeUtc().ToString()
Check (-not (Test-OnlineSnapshot $snapshot $lookup)) 'Reused PID accepted'
$snapshot.process_start_time = $created.ToFileTimeUtc().ToString()
$snapshot.schema_version = 2
Check (-not (Test-OnlineSnapshot $snapshot $lookup)) 'Unsupported schema accepted'
$snapshot.schema_version = 1
Check (-not (Test-OnlineSnapshot $snapshot { throw 'Exited' })) 'Exited process accepted'
$view = Get-OnlineView $null 'Saved'
Check ($view.Status -eq 'Offline' -and $view.Name -eq 'Saved' -and $view.Party -eq '0 / 0') 'Offline view'
$view = Get-OnlineView $snapshot 'Saved'
Check ($view.Status -eq 'Hosting' -and $view.Name -eq 'Host') 'Live profile view'
Check ($view.Code -ceq 'AB7K2Q') 'Host invite'
Check ($view.Party -eq '2 / 6') 'Count view'
Check ($view.Rows[0].Badge -eq 'HOST' -and $view.Rows[1].Badge -eq '') 'Host badge'
Check ($view.Rows[0].Name -eq 'Host' -and $view.Rows[1].Name -eq 'Player ...5AA1') 'Fallback view'
$snapshot.members[1].name = 'Alice'
Check ((Get-OnlineView $snapshot '').Rows[1].Name -eq 'Alice') 'Known name update'
$snapshot.members = @($snapshot.members[0]); $snapshot.player_count = 1
Check ((Get-OnlineView $snapshot '').Party -eq '1 / 6') 'Leave update'
$snapshot.mode = 'joined'
$view = Get-OnlineView $snapshot ''
Check ($view.Status -eq 'Joined' -and $view.Code -eq '') 'Joined view must not publish stale host code'
foreach ($bad in @('', 'ABC', 'ABC123', 'AB7K2Q secret', 'ab7k2q')) {
    Check (-not (Test-OnlineCode $bad)) "Bad clipboard code accepted: $bad"
}
$args = @(Get-OnlineAction 'join' 'ab7k2q' $false)
Check ('-JoinByInviteCode' -in $args -and '-InviteCode' -in $args -and 'AB7K2Q' -in $args) 'Join path'
Check (($args -join ' ') -match 'Setup-Harmony.ps1') 'Launcher delegation'
Check ('-Configure' -in @(Get-OnlineAction 'configure' '' $true)) 'Name action with running game'
foreach ($action in @('play', 'join')) {
    $rejected = $false
    try { Get-OnlineAction $action 'AB7K2Q' $true | Out-Null } catch { $rejected = $true }
    Check $rejected 'Duplicate launch allowed'
}
$source = Get-Content (Join-Path $PSScriptRoot '../Online-Harmony.ps1') -Raw
Check ($source -notmatch 'Stop-Process|\.Kill\(|Remove-Item|ResolveInviteCode') 'Companion owns forbidden operations'
$tokens = $null; $parseErrors = $null
[void][Management.Automation.Language.Parser]::ParseInput($source, [ref]$tokens, [ref]$parseErrors)
Check ($parseErrors.Count -eq 0) 'Companion syntax'
Write-Output "Companion: $checks checks passed."
