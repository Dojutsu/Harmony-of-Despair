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
    $output = @(& powershell.exe @command 2>&1)
    return [pscustomobject]@{ ExitCode = $LASTEXITCODE; Output = $output }
}

function Get-ProfileXuid([string]$localAppData) {
    $profile = Join-Path $localAppData 'HarmonyRecomp\launcher-profile.cfg'
    Assert-True (Test-Path -LiteralPath $profile -PathType Leaf) "profile was not created at $profile"
    $line = Get-Content -LiteralPath $profile | Where-Object { $_ -match '^HARMONY_USER_XUID=' }
    Assert-True ($null -ne $line) 'profile has no XUID entry'
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
    $first = Invoke-Setup $firstLocal
    Assert-True ($first.ExitCode -eq 0) "first launch exited $($first.ExitCode)"
    $firstXuid = Get-ProfileXuid $firstLocal
    Assert-True ($firstXuid -match '^\d+$') 'generated XUID is not unsigned decimal'
    $firstValue = [uint64]::Parse($firstXuid, [Globalization.CultureInfo]::InvariantCulture)
    Assert-True ($firstValue -ne 0) 'generated XUID is zero'
    Assert-True (($firstValue -band [uint64]0x00C0000000000000) -eq 0) 'generated XUID has a prohibited bit set'

    $arguments = Get-GameArguments $firstArguments
    foreach ($required in @(
        '--lan_online=true',
        '--lan_discovery_port=30741',
        '--lan_gameplay_port=30742',
        '--session_directory_url=https://hod.dojutsu.net',
        '--session_directory_candidate_type=public',
        "--user_xuid=$firstXuid"
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

    $reimportArguments = Join-Path $testRoot 'reimport arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $reimportArguments
    $reimport = Invoke-Setup $firstLocal @('-Setup', '-Source', $sourceRoot)
    Assert-True ($reimport.ExitCode -eq 0) "reimport launch exited $($reimport.ExitCode)"
    Assert-True ((Get-ProfileXuid $firstLocal) -eq $firstXuid) 'reimport changed the persistent XUID'

    $secondLocal = Join-Path $testRoot 'Independent Local AppData'
    $independentArguments = Join-Path $testRoot 'independent arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $independentArguments
    $independent = Invoke-Setup $secondLocal
    Assert-True ($independent.ExitCode -eq 0) "independent launch exited $($independent.ExitCode)"
    Assert-True ((Get-ProfileXuid $secondLocal) -ne $firstXuid) 'independent profile generated the same XUID'

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
