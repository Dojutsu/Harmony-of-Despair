param()

$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)
$testRoot = Join-Path ([IO.Path]::GetTempPath()) ("Harmony launcher tests {0} with spaces" -f [Guid]::NewGuid().ToString('N'))
$artifactRoot = Join-Path $testRoot 'Artifact With Spaces'
$sourceRoot = Join-Path $testRoot 'Owned Source With Spaces'
$recognizedEnvironment = @(
    'HARMONY_USER_XUID',
    'HARMONY_USER_NAME',
    'HARMONY_GPU_PLUGIN',
    'HARMONY_MNK_MODE',
    'HARMONY_LICENSE_MASK',
    'HARMONY_LOG_LEVEL',
    'HARMONY_LOG_NOISY',
    'HARMONY_LAN_ONLINE',
    'HARMONY_LAN_DISCOVERY_PORT',
    'HARMONY_LAN_GAMEPLAY_PORT',
    'HARMONY_SESSION_DIRECTORY_URL',
    'HARMONY_SESSION_DIRECTORY_CANDIDATE_TYPE',
    'HARMONY_SESSION_DIRECTORY_INVITE_CODE',
    'HARMONY_TEST_ARGUMENTS_PATH',
    'HARMONY_TEST_IMPORT_LOG',
    'HARMONY_TEST_FAIL_OPERATION',
    'HARMONY_TEST_GAME_EXIT',
    'HARMONY_NO_PAUSE'
)
$savedEnvironment = @{}
foreach ($name in @('LOCALAPPDATA') + $recognizedEnvironment) {
    $savedEnvironment[$name] = [Environment]::GetEnvironmentVariable($name, 'Process')
}

function Assert-True([bool]$condition, [string]$message) {
    if (-not $condition) {
        throw "Launcher test failed: $message"
    }
}

function Invoke-Setup(
    [string]$localAppData,
    [string[]]$extraArguments = @()
) {
    $env:LOCALAPPDATA = $localAppData
    $command = @(
        '-NoLogo', '-NoProfile', '-ExecutionPolicy', 'Bypass',
        '-File', (Join-Path $artifactRoot 'Setup-Harmony.ps1'),
        '-NoDialogs'
    ) + $extraArguments
    $previousPreference = $ErrorActionPreference
    $ErrorActionPreference = 'Continue'
    try {
        $output = @(& powershell.exe @command 2>&1)
        $exitCode = $LASTEXITCODE
    } finally {
        $ErrorActionPreference = $previousPreference
    }
    return [pscustomobject]@{ ExitCode = $exitCode; Output = $output }
}

function Get-ProfileXuid([string]$localAppData) {
    $profile = Join-Path $localAppData 'HarmonyRecomp\launcher-profile.cfg'
    Assert-True (Test-Path -LiteralPath $profile -PathType Leaf) "profile was not created at $profile"
    $line = Get-Content -LiteralPath $profile | Where-Object { $_ -match '^HARMONY_USER_XUID=' }
    Assert-True ($null -ne $line) 'profile has no XUID entry'
    return ($line -split '=', 2)[1]
}

function Get-ProfileName([string]$localAppData) {
    $profile = Join-Path $localAppData 'HarmonyRecomp\launcher-profile.cfg'
    Assert-True (Test-Path -LiteralPath $profile -PathType Leaf) "profile was not created at $profile"
    $line = Get-Content -LiteralPath $profile | Where-Object { $_ -match '^HARMONY_USER_NAME=' }
    Assert-True ($null -ne $line) 'profile has no player-name entry'
    return ($line -split '=', 2)[1]
}

function Get-GameArguments([string]$path) {
    Assert-True (Test-Path -LiteralPath $path -PathType Leaf) "fake game did not record arguments at $path"
    return @(Get-Content -LiteralPath $path)
}

try {
    foreach ($name in $recognizedEnvironment) {
        [Environment]::SetEnvironmentVariable($name, $null, 'Process')
    }

    [void](New-Item -ItemType Directory -Path $artifactRoot -Force)
    [void](New-Item -ItemType Directory -Path $sourceRoot -Force)
    Copy-Item -LiteralPath (Join-Path $repoRoot 'Launch-Harmony.bat') -Destination $artifactRoot
    Copy-Item -LiteralPath (Join-Path $repoRoot 'Setup-Harmony.ps1') -Destination $artifactRoot

    $fakeSource = @'
using System;
using System.Diagnostics;
using System.IO;

public static class LauncherFixture
{
    public static int Main(string[] args)
    {
        string executable = Path.GetFileName(Process.GetCurrentProcess().MainModule.FileName);
        if (executable.IndexOf("import", StringComparison.OrdinalIgnoreCase) >= 0)
        {
            string importLog = Environment.GetEnvironmentVariable("HARMONY_TEST_IMPORT_LOG");
            if (!String.IsNullOrEmpty(importLog))
                File.AppendAllText(importLog, String.Join("|", args) + Environment.NewLine);
            string failOperation = Environment.GetEnvironmentVariable("HARMONY_TEST_FAIL_OPERATION");
            if (args.Length > 0 && !String.IsNullOrEmpty(failOperation) && args[0] == failOperation)
            {
                Console.Error.WriteLine("synthetic importer failure for " + failOperation);
                return 37;
            }
            return 0;
        }

        string argumentPath = Environment.GetEnvironmentVariable("HARMONY_TEST_ARGUMENTS_PATH");
        if (!String.IsNullOrEmpty(argumentPath))
            File.WriteAllLines(argumentPath, args);
        int exitCode;
        return Int32.TryParse(Environment.GetEnvironmentVariable("HARMONY_TEST_GAME_EXIT"), out exitCode)
            ? exitCode : 0;
    }
}
'@
    $fake = Join-Path $testRoot 'launcher-fixture.exe'
    Add-Type -TypeDefinition $fakeSource -Language CSharp -OutputAssembly $fake -OutputType ConsoleApplication
    Copy-Item -LiteralPath $fake -Destination (Join-Path $artifactRoot 'harmonyrecomp.exe')
    Copy-Item -LiteralPath $fake -Destination (Join-Path $artifactRoot 'harmonyrecomp-import.exe')

    $firstLocal = Join-Path $testRoot 'First Local AppData'
    $firstArguments = Join-Path $testRoot 'first arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $firstArguments
    $first = Invoke-Setup $firstLocal @('-PlayerName', 'Alice')
    Assert-True ($first.ExitCode -eq 0) "first launch exited $($first.ExitCode)"
    $firstXuid = Get-ProfileXuid $firstLocal
    Assert-True ($firstXuid -match '^\d+$') 'generated XUID is not unsigned decimal'
    $firstValue = [uint64]::Parse($firstXuid, [Globalization.CultureInfo]::InvariantCulture)
    Assert-True ($firstValue -ne 0) 'generated XUID is zero'
    Assert-True (($firstValue -band [uint64]0x00C0000000000000) -eq 0) 'generated XUID has a prohibited bit set'
    Assert-True ((Get-ProfileName $firstLocal) -eq 'Alice') 'first launch did not persist the player name'

    $arguments = Get-GameArguments $firstArguments
    foreach ($required in @(
        '--lan_online=true',
        '--lan_discovery_port=30741',
        '--lan_gameplay_port=30742',
        '--session_directory_url=https://hod.dojutsu.net',
        '--session_directory_candidate_type=public',
        "--user_xuid=$firstXuid"
        '--user_name=Alice'
    )) {
        Assert-True ($required -in $arguments) "missing launch argument $required"
    }
    foreach ($forbiddenPrefix in @(
        '--session_directory_publish_address=',
        '--session_directory_build_id=',
        '--nat_probe_server=',
        '--nat_probe_attempt=',
        '--nat_probe_credential=',
        '--nat_probe_participant=',
        '--direct_connect_address=',
        '--lan_bind_address='
    )) {
        Assert-True (-not ($arguments | Where-Object { $_.StartsWith($forbiddenPrefix) })) "unexpected proof/manual argument $forbiddenPrefix"
    }
    $expectedRoot = "--game_data_root=$(Join-Path $firstLocal 'HarmonyRecomp\game-data')"
    Assert-True ($expectedRoot -in $arguments) 'path containing spaces was split or altered'

    $secondArguments = Join-Path $testRoot 'second arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $secondArguments
    $second = Invoke-Setup $firstLocal
    Assert-True ($second.ExitCode -eq 0) "second launch exited $($second.ExitCode)"
    Assert-True ((Get-ProfileXuid $firstLocal) -eq $firstXuid) 'second launch changed the persistent XUID'
    Assert-True ("--user_xuid=$firstXuid" -in (Get-GameArguments $secondArguments)) 'second launch did not use the persistent XUID'
    Assert-True ('--user_name=Alice' -in (Get-GameArguments $secondArguments)) 'second launch did not reuse the player name'

    $reimportArguments = Join-Path $testRoot 'reimport arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $reimportArguments
    $reimport = Invoke-Setup $firstLocal @('-Setup', '-Source', $sourceRoot)
    Assert-True ($reimport.ExitCode -eq 0) "reimport launch exited $($reimport.ExitCode)"
    Assert-True ((Get-ProfileXuid $firstLocal) -eq $firstXuid) 'reimport changed the persistent XUID'
    Assert-True ((Get-ProfileName $firstLocal) -eq 'Alice') 'reimport changed the player name'

    $secondLocal = Join-Path $testRoot 'Independent Local AppData'
    $independentArguments = Join-Path $testRoot 'independent arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $independentArguments
    $independent = Invoke-Setup $secondLocal @('-PlayerName', 'Alice')
    Assert-True ($independent.ExitCode -eq 0) "independent launch exited $($independent.ExitCode)"
    Assert-True ((Get-ProfileXuid $secondLocal) -ne $firstXuid) 'independent profile generated the same XUID'
    Assert-True ((Get-ProfileName $secondLocal) -eq 'Alice') 'duplicate display name was not preserved'

    $xuidOnlyLocal = Join-Path $testRoot 'XUID Only Local AppData'
    $xuidOnlyProfileRoot = Join-Path $xuidOnlyLocal 'HarmonyRecomp'
    [void](New-Item -ItemType Directory -Path $xuidOnlyProfileRoot -Force)
    Set-Content -LiteralPath (Join-Path $xuidOnlyProfileRoot 'launcher-profile.cfg') -Encoding ASCII -Value 'HARMONY_USER_XUID=2002'
    $xuidOnlyArguments = Join-Path $testRoot 'xuid-only arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $xuidOnlyArguments
    $xuidOnly = Invoke-Setup $xuidOnlyLocal @('-PlayerName', 'LegacyUser')
    Assert-True ($xuidOnly.ExitCode -eq 0) "XUID-only profile launch exited $($xuidOnly.ExitCode)"
    Assert-True ((Get-ProfileXuid $xuidOnlyLocal) -eq '2002') 'name prompt changed XUID-only profile identity'
    Assert-True ((Get-ProfileName $xuidOnlyLocal) -eq 'LegacyUser') 'XUID-only profile did not persist prompted name'

    $configureArguments = Join-Path $testRoot 'configure should not launch.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $configureArguments
    $configured = Invoke-Setup $firstLocal @('-Configure', '-PlayerName', 'Bob')
    Assert-True ($configured.ExitCode -eq 0) "configure exited $($configured.ExitCode)"
    Assert-True ((Get-ProfileXuid $firstLocal) -eq $firstXuid) 'configure changed the persistent XUID'
    Assert-True ((Get-ProfileName $firstLocal) -eq 'Bob') 'configure did not update the player name'
    Assert-True (-not (Test-Path -LiteralPath $configureArguments)) 'configure launched the game'

    foreach ($invalidName in @('   ', '0123456789ABCDEF', "Bad`nName")) {
        $invalidLocal = Join-Path $testRoot ("Invalid Name " + [Guid]::NewGuid().ToString('N'))
        $invalidNameResult = Invoke-Setup $invalidLocal @('-PlayerName', $invalidName)
        Assert-True ($invalidNameResult.ExitCode -eq 27) "invalid player name was accepted: length=$($invalidName.Length) exit=$($invalidNameResult.ExitCode)"
    }

    $printableLocal = Join-Path $testRoot 'Printable Name Local AppData'
    $printable = Invoke-Setup $printableLocal @('-PlayerName', '  A-B_2  ', '-NoLaunch')
    Assert-True ($printable.ExitCode -eq 0) 'printable ASCII player name was rejected'
    Assert-True ((Get-ProfileName $printableLocal) -eq 'A-B_2') 'player-name whitespace was not trimmed'

    Set-Content -LiteralPath (Join-Path $artifactRoot 'harmonyrecomp-user.cfg') -Encoding ASCII -Value @(
        'HARMONY_USER_XUID=2001',
        'HARMONY_USER_NAME=ConfigName'
    )
    $overrideArguments = Join-Path $testRoot 'override arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $overrideArguments
    $env:HARMONY_USER_XUID = '1001'
    $env:HARMONY_USER_NAME = 'EnvironmentName'
    $override = Invoke-Setup $firstLocal
    Assert-True ($override.ExitCode -eq 0) "override launch exited $($override.ExitCode)"
    $overridden = Get-GameArguments $overrideArguments
    Assert-True ('--user_xuid=1001' -in $overridden) 'environment XUID did not override config/profile'
    Assert-True ('--user_name=EnvironmentName' -in $overridden) 'environment username did not override config'
    Remove-Item -LiteralPath (Join-Path $artifactRoot 'harmonyrecomp-user.cfg')
    $env:HARMONY_USER_XUID = $null
    $env:HARMONY_USER_NAME = $null

    Set-Content -LiteralPath (Join-Path $artifactRoot 'harmonyrecomp-user.cfg') -Encoding ASCII -Value @(
        'HARMONY_SESSION_DIRECTORY_INVITE_CODE=BAD'
    )
    $invalidInvite = Invoke-Setup $firstLocal
    Assert-True ($invalidInvite.ExitCode -eq 26) "invalid invite exited $($invalidInvite.ExitCode), expected 26"

    Set-Content -LiteralPath (Join-Path $artifactRoot 'harmonyrecomp-user.cfg') -Encoding ASCII -Value @(
        'HARMONY_SESSION_DIRECTORY_INVITE_CODE=ab7k2q'
    )
    $inviteArguments = Join-Path $testRoot 'invite arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $inviteArguments
    $invite = Invoke-Setup $firstLocal
    Assert-True ($invite.ExitCode -eq 0) "invite launch exited $($invite.ExitCode)"
    Assert-True ('--session_directory_invite_code=AB7K2Q' -in
        (Get-GameArguments $inviteArguments)) 'invite code was not forwarded to Harmony'
    Remove-Item -LiteralPath (Join-Path $artifactRoot 'harmonyrecomp-user.cfg')

    $joinArguments = Join-Path $testRoot 'join-code arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $joinArguments
    $joinCode = Invoke-Setup $firstLocal @('-JoinByInviteCode', '-InviteCode', 'cd8m3r')
    Assert-True ($joinCode.ExitCode -eq 0) "join-code action exited $($joinCode.ExitCode)"
    Assert-True ('--session_directory_invite_code=CD8M3R' -in
        (Get-GameArguments $joinArguments)) 'join-code action did not normalize and forward the code'
    foreach ($invalidCode in @('BAD', 'ABC10O', 'ABCDEF7')) {
        $invalidJoin = Invoke-Setup $firstLocal @('-JoinByInviteCode', '-InviteCode', $invalidCode)
        Assert-True ($invalidJoin.ExitCode -eq 26) "invalid join code was accepted: $invalidCode"
    }

    $inviteStateRoot = Join-Path $firstLocal 'HarmonyRecomp'
    $inviteStatePath = Join-Path $inviteStateRoot 'active-invite-code.txt'
    [IO.File]::WriteAllText($inviteStatePath, 'EF7K2Q', [Text.UTF8Encoding]::new($false))
    $shown = Invoke-Setup $firstLocal @('-ShowInviteCode')
    Assert-True ($shown.ExitCode -eq 0) 'show-invite action failed with active state'
    Assert-True (($shown.Output | Out-String) -match 'Invite Code: EF7K2Q') 'show-invite did not display the active code'
    Remove-Item -LiteralPath $inviteStatePath
    $notShown = Invoke-Setup $firstLocal @('-ShowInviteCode')
    Assert-True (($notShown.Output | Out-String) -match 'No active hosted session') 'show-invite did not report inactive hosting'

    $env:HARMONY_TEST_FAIL_OPERATION = '--aggregate'
    $failedImport = Invoke-Setup $firstLocal @('-Setup', '-Source', $sourceRoot)
    Assert-True ($failedImport.ExitCode -eq 24) "setup failure exited $($failedImport.ExitCode), expected 24"
    Assert-True (($failedImport.Output | Out-String) -match 'synthetic importer failure') 'setup hid the underlying importer error'
    $env:HARMONY_TEST_FAIL_OPERATION = $null

    $missingRoot = Join-Path $testRoot 'Missing Importer Artifact'
    [void](New-Item -ItemType Directory -Path $missingRoot)
    Copy-Item -LiteralPath (Join-Path $repoRoot 'Launch-Harmony.bat') -Destination $missingRoot
    [IO.File]::WriteAllText(
        (Join-Path $missingRoot 'Setup-Harmony.ps1'),
        "[Console]::Error.WriteLine('synthetic setup boundary')`r`nexit 21`r`n",
        [Text.UTF8Encoding]::new($false))
    $env:LOCALAPPDATA = Join-Path $testRoot 'Missing Importer Local AppData'
    $env:HARMONY_NO_PAUSE = '1'
    Push-Location $missingRoot
    try {
        $previousPreference = $ErrorActionPreference
        $ErrorActionPreference = 'Continue'
        try {
            $batchOutput = @(& cmd.exe /d /c Launch-Harmony.bat 2>&1)
            $batchExit = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
    } finally {
        Pop-Location
    }
    Assert-True ($batchExit -eq 21) "batch launcher returned $batchExit instead of setup exit 21"
    $batchText = $batchOutput | Out-String
    Assert-True ($batchText -match 'synthetic setup boundary') 'batch launcher hid the setup error'
    Assert-True ($batchText -match 'failed with exit code 21') 'batch launcher omitted the preserved exit code'

    Write-Host 'Launcher tests passed: 10 scenarios.'
} finally {
    foreach ($name in @('LOCALAPPDATA') + $recognizedEnvironment) {
        [Environment]::SetEnvironmentVariable($name, $savedEnvironment[$name], 'Process')
    }
    if (Test-Path -LiteralPath $testRoot) {
        Remove-Item -LiteralPath $testRoot -Recurse -Force
    }
}

exit 0
