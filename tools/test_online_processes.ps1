param([Parameter(Mandatory=$true)][string]$FixtureExe)
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot '../Online-Harmony.ps1') -FunctionsOnly
$root = Join-Path ([IO.Path]::GetTempPath()) ('harmony-online-process-test-' + [guid]::NewGuid().ToString('N'))
[void][IO.Directory]::CreateDirectory($root)
$fixtureDirectory = Split-Path -Parent (Resolve-Path -LiteralPath $FixtureExe).Path
# This is the asset-free test executable, named for the production reader's
# process-name check. It initializes only a tool-mode Runtime and synthetic
# XSession; it cannot run Harmony gameplay.
$testExecutable = Join-Path $root 'harmonyrecomp.exe'
Copy-Item -LiteralPath $FixtureExe -Destination $testExecutable
foreach ($dependency in @('rexruntimerd.dll', 'TracyClientrd.dll')) {
    Copy-Item -LiteralPath (Join-Path $fixtureDirectory $dependency) -Destination $root
}
$processes = @()
try {
    foreach ($number in 1..2) {
        $start = [Diagnostics.ProcessStartInfo]::new()
        $start.FileName = $testExecutable; $start.Arguments = '"' + $root + '"'
        $start.UseShellExecute = $false; $start.CreateNoWindow = $true
        $processes += [Diagnostics.Process]::Start($start)
    }
    $deadline = [datetime]::UtcNow.AddSeconds(8)
    do {
        $snapshots = @(foreach ($process in $processes) {
            $path = Join-Path $root "online-status-$($process.Id).json"
            if (Test-Path -LiteralPath $path) {
                try { $value = Get-Content -LiteralPath $path -Raw | ConvertFrom-Json; if ($value.mode -eq 'hosting') { $value } } catch {}
            }
        })
        if ($snapshots.Count -eq 2) { break }
        Start-Sleep -Milliseconds 50
    } while ([datetime]::UtcNow -lt $deadline)
    if ($snapshots.Count -ne 2) { throw 'Two live independent snapshots were not published.' }
    if (@(Get-OnlineSnapshots $root).Count -ne 2) { throw 'Production file reader failed to identify both live instances.' }
    foreach ($snapshot in $snapshots) {
        $actual = Get-Process -Id $snapshot.process_id
        if (-not (Test-OnlineSnapshot $snapshot)) { throw 'Real process identity rejected.' }
        $snapshot.process_start_time = ([Int64]$snapshot.process_start_time - 1).ToString()
        if (Test-OnlineSnapshot $snapshot) { throw 'PID reuse mismatch accepted.' }
    }
    $first = $processes[0]
    $firstPath = Join-Path $root "online-status-$($first.Id).json"
    [IO.File]::WriteAllText("$firstPath.stop", '')
    if (-not $first.WaitForExit(5000) -or $first.ExitCode -ne 0) { throw 'First lifecycle fixture failed.' }
    if (Test-Path -LiteralPath $firstPath) { throw 'Clean exit left its own snapshot.' }
    if (@(Get-OnlineSnapshots $root).Count -ne 1) { throw 'Reader did not isolate the surviving instance.' }
    $second = $processes[1]
    $secondPath = Join-Path $root "online-status-$($second.Id).json"
    if ($second.HasExited -or -not (Test-Path -LiteralPath $secondPath)) { throw 'First exit affected second publisher.' }
    [IO.File]::WriteAllText("$secondPath.stop", '')
    if (-not $second.WaitForExit(5000) -or $second.ExitCode -ne 0) { throw 'Second lifecycle fixture failed.' }
    if (Test-Path -LiteralPath $secondPath) { throw 'Second snapshot remained after clean shutdown.' }
    # A crash leftover must remain observationally offline. The reader must
    # neither trust its timestamp nor delete the abandoned file.
    $stale = Join-Path $root "online-status-$($snapshots[0].process_id).json"
    $snapshots[0] | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath $stale
    if (@(Get-OnlineSnapshots $root).Count -ne 0) { throw 'Reader accepted an exited process snapshot.' }
    if (-not (Test-Path -LiteralPath $stale)) { throw 'Reader deleted process-owned state.' }
    Write-Output 'Two real publisher processes: XSession lifecycle, PID/start identity, independent files, and clean shutdown passed.'
} finally {
    foreach ($process in $processes) {
        if (-not $process.HasExited) {
            [IO.File]::WriteAllText((Join-Path $root "online-status-$($process.Id).json.stop"), '')
            [void]$process.WaitForExit(12000)
        }
        $process.Dispose()
    }
    # Keep small output artifacts for diagnosis; delete no game-owned state.
    Write-Output "Fixture results: $root"
}
