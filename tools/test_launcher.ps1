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

function Invoke-JoinScript(
    [string]$localAppData,
    [string[]]$extraArguments = @(),
    [switch]$ViaCmd
) {
    $env:LOCALAPPDATA = $localAppData
    Push-Location $artifactRoot
    try {
        $previousPreference = $ErrorActionPreference
        $ErrorActionPreference = 'Continue'
        try {
            if ($ViaCmd) {
                $output = @(& cmd.exe /d /c powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File Join-Harmony.ps1 @extraArguments 2>&1)
            } else {
                $output = @(& (Join-Path $artifactRoot 'Join-Harmony.ps1') @extraArguments 2>&1)
            }
            $exitCode = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
    } finally {
        Pop-Location
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

function Get-ProfileLanguage([string]$localAppData) {
    $profile = Join-Path $localAppData 'HarmonyRecomp\launcher-profile.cfg'
    $line = Get-Content -LiteralPath $profile | Where-Object { $_ -match '^HARMONY_USER_LANGUAGE=' }
    if (-not $line) { return '' }
    return ($line -split '=', 2)[1]
}

function Assert-LanguageArgument([string]$path, [string]$expected) {
    $matches = @(Get-GameArguments $path | Where-Object { $_ -like '--user_language=*' })
    if ($expected) {
        Assert-True ($matches.Count -eq 1 -and $matches[0] -ceq "--user_language=$expected") "wrong language argument: $($matches -join ', ')"
    } else {
        Assert-True ($matches.Count -eq 0) 'unset language emitted a user_language argument'
    }
}

function Get-GameArguments([string]$path) {
    Assert-True (Test-Path -LiteralPath $path -PathType Leaf) "fake game did not record arguments at $path"
    return @(Get-Content -LiteralPath $path)
}

function Assert-InviteArgument([string]$path, [string]$code) {
    $matches = @(Get-GameArguments $path | Where-Object { $_ -like '--session_directory_invite_code=*' })
    Assert-True ($matches.Count -eq 1 -and $matches[0] -ceq "--session_directory_invite_code=$code") "wrong invite arguments: $($matches -join ', ')"
}

try {
    foreach ($name in $recognizedEnvironment) {
        [Environment]::SetEnvironmentVariable($name, $null, 'Process')
    }

    [void](New-Item -ItemType Directory -Path $artifactRoot -Force)
    [void](New-Item -ItemType Directory -Path $sourceRoot -Force)
    Copy-Item -LiteralPath (Join-Path $repoRoot 'Launch-Harmony.bat') -Destination $artifactRoot
    Copy-Item -LiteralPath (Join-Path $repoRoot 'Join-Harmony.ps1') -Destination $artifactRoot
    Copy-Item -LiteralPath (Join-Path $repoRoot 'Setup-Harmony.ps1') -Destination $artifactRoot
    Copy-Item -LiteralPath (Join-Path $repoRoot 'Online-Harmony.ps1') -Destination $artifactRoot

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
    Assert-True ((Get-ProfileLanguage $firstLocal) -eq '') 'first launch selected a language without user choice'
    Assert-LanguageArgument $firstArguments ''

    $preflightArguments = Join-Path $testRoot 'preflight must not launch.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $preflightArguments
    $preflight = Invoke-Setup $firstLocal @('-NoLaunch')
    Assert-True ($preflight.ExitCode -eq 0 -and -not (Test-Path -LiteralPath $preflightArguments)) 'existing-profile preflight launched the game'
    Assert-True ((Get-ProfileXuid $firstLocal) -eq $firstXuid -and (Get-ProfileName $firstLocal) -eq 'Alice') 'preflight changed the saved profile'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $firstArguments

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
    Assert-LanguageArgument $secondArguments ''

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

    $freshPreflightLocal = Join-Path $testRoot 'Fresh Preflight Local AppData'
    $freshPreflightArguments = Join-Path $testRoot 'fresh preflight must not launch.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $freshPreflightArguments
    $freshPreflight = Invoke-Setup $freshPreflightLocal @('-PlayerName', 'Fresh', '-NoLaunch')
    Assert-True ($freshPreflight.ExitCode -eq 0 -and -not (Test-Path -LiteralPath $freshPreflightArguments)) 'first-run preflight launched the game'
    Assert-True ((Get-ProfileName $freshPreflightLocal) -eq 'Fresh') 'first-run preflight did not save name'

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
    Assert-True ((Get-ProfileLanguage $xuidOnlyLocal) -eq '') 'legacy profile gained a language'
    Assert-LanguageArgument $xuidOnlyArguments ''

    $languageOnlyLocal = Join-Path $testRoot 'Name And Language Only Local AppData'
    $languageOnlyProfileRoot = Join-Path $languageOnlyLocal 'HarmonyRecomp'
    [void](New-Item -ItemType Directory -Path $languageOnlyProfileRoot -Force)
    Set-Content -LiteralPath (Join-Path $languageOnlyProfileRoot 'launcher-profile.cfg') -Encoding ASCII -Value @(
        'HARMONY_USER_NAME=ExistingName', 'HARMONY_USER_LANGUAGE=2')
    $languageOnlyArguments = Join-Path $testRoot 'name and language only arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $languageOnlyArguments
    $languageOnlyLaunch = Invoke-Setup $languageOnlyLocal
    Assert-True ($languageOnlyLaunch.ExitCode -eq 0) 'profile missing XUID could not launch'
    Assert-True ((Get-ProfileXuid $languageOnlyLocal) -match '^\d+$') 'missing XUID was not generated'
    Assert-True ((Get-ProfileName $languageOnlyLocal) -eq 'ExistingName') 'XUID generation dropped name'
    Assert-True ((Get-ProfileLanguage $languageOnlyLocal) -eq '2') 'XUID generation dropped language'
    Assert-LanguageArgument $languageOnlyArguments '2'

    $configureArguments = Join-Path $testRoot 'configure should not launch.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $configureArguments
    $configured = Invoke-Setup $firstLocal @('-Configure', '-PlayerName', 'Bob')
    Assert-True ($configured.ExitCode -eq 0) "configure exited $($configured.ExitCode)"
    Assert-True ((Get-ProfileXuid $firstLocal) -eq $firstXuid) 'configure changed the persistent XUID'
    Assert-True ((Get-ProfileName $firstLocal) -eq 'Bob') 'configure did not update the player name'
    Assert-True (-not (Test-Path -LiteralPath $configureArguments)) 'configure launched the game'

    foreach ($language in 1..6) {
        $configuredLanguage = Invoke-Setup $firstLocal @('-Configure', '-GameLanguage', [string]$language)
        Assert-True ($configuredLanguage.ExitCode -eq 0) "language $language could not be saved"
        Assert-True ((Get-ProfileLanguage $firstLocal) -ceq [string]$language) "language $language did not round-trip through profile"
        Assert-True ((Get-ProfileName $firstLocal) -eq 'Bob') "language $language changed player name"
        $languageArguments = Join-Path $testRoot "language $language arguments.txt"
        $env:HARMONY_TEST_ARGUMENTS_PATH = $languageArguments
        $languageLaunch = Invoke-Setup $firstLocal
        Assert-True ($languageLaunch.ExitCode -eq 0) "language $language launch failed"
        Assert-LanguageArgument $languageArguments ([string]$language)
    }
    $renamed = Invoke-Setup $firstLocal @('-Configure', '-PlayerName', 'Carol')
    Assert-True ($renamed.ExitCode -eq 0) 'renaming configured profile failed'
    Assert-True ((Get-ProfileLanguage $firstLocal) -eq '6') 'renaming dropped language'
    $languageReimport = Invoke-Setup $firstLocal @('-Setup', '-Source', $sourceRoot)
    Assert-True ($languageReimport.ExitCode -eq 0) 'reimport with language failed'
    Assert-True ((Get-ProfileLanguage $firstLocal) -eq '6') 'reimport dropped language'
    $badLanguage = Invoke-Setup $firstLocal @('-Configure', '-GameLanguage', '12')
    Assert-True ($badLanguage.ExitCode -eq 27) 'unsupported language choice was accepted'
    Assert-True ((Get-ProfileLanguage $firstLocal) -eq '6') 'invalid choice changed profile'
    $profileWithLanguage = Join-Path $firstLocal 'HarmonyRecomp\launcher-profile.cfg'
    foreach ($invalid in @('0', '7', '12', '999', 'garbage', '1 --log_level=trace')) {
        $originalProfile = Get-Content -LiteralPath $profileWithLanguage -Raw
        [IO.File]::WriteAllText($profileWithLanguage,
            ($originalProfile -replace 'HARMONY_USER_LANGUAGE=6', "HARMONY_USER_LANGUAGE=$invalid"),
            [Text.UTF8Encoding]::new($false))
        $invalidArguments = Join-Path $testRoot "invalid language $invalid arguments.txt"
        $env:HARMONY_TEST_ARGUMENTS_PATH = $invalidArguments
        $invalidLaunch = Invoke-Setup $firstLocal
        Assert-True ($invalidLaunch.ExitCode -eq 0) "invalid stored language $invalid broke launch"
        Assert-LanguageArgument $invalidArguments ''
        [IO.File]::WriteAllText($profileWithLanguage, $originalProfile, [Text.UTF8Encoding]::new($false))
    }
    $unsetLanguage = Invoke-Setup $firstLocal @('-Configure', '-GameLanguage', 'default')
    Assert-True ($unsetLanguage.ExitCode -eq 0) "clearing language failed: exit=$($unsetLanguage.ExitCode) $($unsetLanguage.Output -join ' ')"
    Assert-True ((Get-ProfileLanguage $firstLocal) -eq '') 'clearing language left profile selection'
    $unsetArguments = Join-Path $testRoot 'unset language arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $unsetArguments
    $unsetLaunch = Invoke-Setup $firstLocal
    Assert-True ($unsetLaunch.ExitCode -eq 0) 'unset language launch failed'
    Assert-LanguageArgument $unsetArguments ''

    foreach ($invalidName in @('   ', '0123456789ABCDEF', "Bad`nName", 'Café',
                               'fuck', 'FUCK', 'F.u.c.k', 'S_H_I_T', 'F-U-C-K', 'f u c k',
                               'NIGGA', 'faggot', 'blowjob')) {
        $invalidLocal = Join-Path $testRoot ("Invalid Name " + [Guid]::NewGuid().ToString('N'))
        $invalidArguments = Join-Path $testRoot ("invalid name arguments " + [Guid]::NewGuid().ToString('N'))
        $env:HARMONY_TEST_ARGUMENTS_PATH = $invalidArguments
        $invalidNameResult = Invoke-Setup $invalidLocal @('-PlayerName', $invalidName)
        Assert-True ($invalidNameResult.ExitCode -eq 27) "invalid player name was accepted: length=$($invalidName.Length) exit=$($invalidNameResult.ExitCode)"
        Assert-True (-not (Test-Path -LiteralPath $invalidArguments)) 'invalid name launched the game'
    }

    foreach ($validName in @('A', '123456789012345', 'Alice', 'A-B_2',
                            'Scunthorpe', 'Essex', 'Dickens', 'Classics', 'Passion', 'Fuchs')) {
        $validLocal = Join-Path $testRoot ("Valid Name " + [Guid]::NewGuid().ToString('N'))
        $validArguments = Join-Path $testRoot ("valid name arguments " + [Guid]::NewGuid().ToString('N'))
        $env:HARMONY_TEST_ARGUMENTS_PATH = $validArguments
        $validResult = Invoke-Setup $validLocal @('-PlayerName', $validName)
        Assert-True ($validResult.ExitCode -eq 0) "ordinary name was rejected: $validName"
        Assert-True ((Get-ProfileName $validLocal) -ceq $validName) 'valid name did not persist'
        $actualNames = @(Get-GameArguments $validArguments | Where-Object { $_ -like '--user_name=*' })
        Assert-True ($actualNames.Count -eq 1 -and $actualNames[0] -ceq "--user_name=$validName") 'valid name did not produce one correct launch argument'
    }

    $protectedProfile = Join-Path $firstLocal 'HarmonyRecomp\launcher-profile.cfg'
    $preservedXuid = Get-ProfileXuid $firstLocal
    $preservedName = Get-ProfileName $firstLocal
    $protectedLanguage = Invoke-Setup $firstLocal @('-Configure', '-GameLanguage', '2')
    Assert-True ($protectedLanguage.ExitCode -eq 0) 'could not set language for name-policy tests'
    $profileBeforeReject = (Get-FileHash -LiteralPath $protectedProfile).Hash
    $rejectedChange = Invoke-Setup $firstLocal @('-Configure', '-PlayerName', 'F.u.c.k')
    Assert-True ($rejectedChange.ExitCode -eq 27) 'configure accepted a prohibited name'
    Assert-True ((Get-FileHash -LiteralPath $protectedProfile).Hash -eq $profileBeforeReject) 'rejected configure changed profile'
    Assert-True ((Get-ProfileLanguage $firstLocal) -eq '2') 'rejected name changed language'
    $acceptedChange = Invoke-Setup $firstLocal @('-Configure', '-PlayerName', 'Scunthorpe')
    Assert-True ($acceptedChange.ExitCode -eq 0) 'configure rejected innocent name'
    Assert-True ((Get-ProfileXuid $firstLocal) -eq $preservedXuid -and
                 (Get-ProfileLanguage $firstLocal) -eq '2') 'accepted name change altered identity or language'
    $cancelChange = Invoke-Setup $firstLocal @('-Configure')
    Assert-True ($cancelChange.ExitCode -eq 0 -and (Get-ProfileName $firstLocal) -eq 'Scunthorpe') 'cancel-like configure changed name'
    $restoreName = Invoke-Setup $firstLocal @('-Configure', '-PlayerName', $preservedName, '-GameLanguage', 'default')
    Assert-True ($restoreName.ExitCode -eq 0) 'name-policy tests could not restore profile'

    $manualLocal = Join-Path $testRoot 'Manually Edited Name Local AppData'
    $manualProfileRoot = Join-Path $manualLocal 'HarmonyRecomp'
    [void](New-Item -ItemType Directory -Path $manualProfileRoot -Force)
    $manualProfile = Join-Path $manualProfileRoot 'launcher-profile.cfg'
    Set-Content -LiteralPath $manualProfile -Encoding ASCII -Value @(
        'HARMONY_USER_XUID=2002', 'HARMONY_USER_NAME=F.u.c.k', 'HARMONY_USER_LANGUAGE=2')
    $manualHash = (Get-FileHash -LiteralPath $manualProfile).Hash
    $manualRead = Invoke-Setup $manualLocal @('-ReadPlayerName')
    Assert-True ($manualRead.ExitCode -eq 0 -and -not ($manualRead.Output | Where-Object { $_ -match 'F\.u\.c\.k' })) 'companion query exposed invalid stored name'
    Assert-True ((Get-FileHash -LiteralPath $manualProfile).Hash -eq $manualHash) 'read-only query modified manual profile'
    $manualArguments = Join-Path $testRoot 'manual invalid name arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $manualArguments
    $manualLaunch = Invoke-Setup $manualLocal
    Assert-True ($manualLaunch.ExitCode -eq 27 -and -not (Test-Path -LiteralPath $manualArguments)) 'manual invalid name reached game launch'
    Assert-True ((Get-ProfileLanguage $manualLocal) -eq '2') 'invalid-name rejection changed language'
    $manualRecovery = Invoke-Setup $manualLocal @('-Configure', '-PlayerName', 'Recovered')
    Assert-True ($manualRecovery.ExitCode -eq 0 -and (Get-ProfileXuid $manualLocal) -eq '2002' -and
                 (Get-ProfileLanguage $manualLocal) -eq '2') 'manual profile recovery lost identity or language'
    $manualReimport = Invoke-Setup $manualLocal @('-Setup', '-Source', $sourceRoot)
    Assert-True ($manualReimport.ExitCode -eq 0 -and (Get-ProfileName $manualLocal) -eq 'Recovered' -and
                 (Get-ProfileLanguage $manualLocal) -eq '2') 'reimport lost validated name or language'

    $missingXuidLocal = Join-Path $testRoot 'Invalid Name Missing XUID'
    $missingXuidProfileRoot = Join-Path $missingXuidLocal 'HarmonyRecomp'
    [void](New-Item -ItemType Directory -Path $missingXuidProfileRoot -Force)
    Set-Content -LiteralPath (Join-Path $missingXuidProfileRoot 'launcher-profile.cfg') -Encoding ASCII -Value @(
        'HARMONY_USER_NAME=F.u.c.k', 'HARMONY_USER_LANGUAGE=3')
    $missingXuidResult = Invoke-Setup $missingXuidLocal
    Assert-True ($missingXuidResult.ExitCode -eq 27) 'invalid name with missing XUID passed validation'
    Assert-True ((Get-ProfileXuid $missingXuidLocal) -match '^\d+$' -and
                 (Get-ProfileName $missingXuidLocal) -eq '' -and
                 (Get-ProfileLanguage $missingXuidLocal) -eq '3') 'XUID creation repersisted invalid name or lost language'

    $invalidOverrideArguments = Join-Path $testRoot 'invalid override arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $invalidOverrideArguments
    $env:HARMONY_USER_NAME = 'F.u.c.k'
    $invalidOverride = Invoke-Setup $firstLocal
    Assert-True ($invalidOverride.ExitCode -eq 27 -and
                 -not (Test-Path -LiteralPath $invalidOverrideArguments)) 'invalid environment name reached game launch'
    $env:HARMONY_USER_NAME = $null
    $configPath = Join-Path $artifactRoot 'harmonyrecomp-user.cfg'
    Set-Content -LiteralPath $configPath -Encoding ASCII -Value 'HARMONY_USER_NAME=F.u.c.k'
    $invalidConfigArguments = Join-Path $testRoot 'invalid config name arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $invalidConfigArguments
    $invalidConfig = Invoke-Setup $firstLocal
    Assert-True ($invalidConfig.ExitCode -eq 27 -and
                 -not (Test-Path -LiteralPath $invalidConfigArguments)) 'invalid config name reached game launch'
    Remove-Item -LiteralPath $configPath

    $printableLocal = Join-Path $testRoot 'Printable Name Local AppData'
    $printable = Invoke-Setup $printableLocal @('-PlayerName', '  A-B_2  ', '-NoLaunch')
    Assert-True ($printable.ExitCode -eq 0) 'printable ASCII player name was rejected'
    Assert-True ((Get-ProfileName $printableLocal) -eq 'A-B_2') 'player-name whitespace was not trimmed'
    $profileFile = Join-Path $printableLocal 'HarmonyRecomp/launcher-profile.cfg'
    $profileHash = (Get-FileHash -LiteralPath $profileFile).Hash
    $readName = Invoke-Setup $printableLocal @('-ReadPlayerName')
    Assert-True ($readName.ExitCode -eq 0 -and 'A-B_2' -in $readName.Output) 'companion name query failed'
    Assert-True ((Get-FileHash -LiteralPath $profileFile).Hash -eq $profileHash) 'name query changed identity/profile'
    $emptyProfileRoot = Join-Path $testRoot 'Read Only Missing Profile'
    $readMissingName = Invoke-Setup $emptyProfileRoot @('-ReadPlayerName')
    Assert-True ($readMissingName.ExitCode -eq 0) 'missing-name query failed'
    Assert-True (-not (Test-Path -LiteralPath $emptyProfileRoot)) 'name query created profile or imported data'

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
    foreach ($validCode in @('E6CK9X', 'HEKUJC', 'e6ck9x')) {
        $joinScriptArguments = Join-Path $testRoot "join script $validCode arguments.txt"
        $env:HARMONY_TEST_ARGUMENTS_PATH = $joinScriptArguments
        $joinScript = Invoke-JoinScript $firstLocal @($validCode)
        Assert-True ($joinScript.ExitCode -eq 0) "PowerShell join entry failed for $validCode"
        Assert-InviteArgument $joinScriptArguments $validCode.ToUpperInvariant()
    }
    $cmdJoinArguments = Join-Path $testRoot 'cmd join script arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $cmdJoinArguments
    $cmdJoin = Invoke-JoinScript $firstLocal @('HEKUJC') -ViaCmd
    Assert-True ($cmdJoin.ExitCode -eq 0) 'cmd join entry failed for valid code'
    Assert-InviteArgument $cmdJoinArguments 'HEKUJC'
    foreach ($cmdInvalid in @('E6CK9', 'E6CK9XX', 'ABC123')) {
        $cmdInvalidArguments = Join-Path $testRoot "cmd invalid $cmdInvalid arguments.txt"
        $env:HARMONY_TEST_ARGUMENTS_PATH = $cmdInvalidArguments
        $cmdRejected = Invoke-JoinScript $firstLocal @($cmdInvalid) -ViaCmd
        Assert-True ($cmdRejected.ExitCode -eq 26 -and -not (Test-Path -LiteralPath $cmdInvalidArguments)) "cmd accepted invalid code $cmdInvalid"
    }
    $sentinel = Join-Path $artifactRoot 'injected-sentinel.txt'
    $rejectedCodes = @(
        '', 'E6CK9', 'E6CK9XX', 'ABC123', 'E6CK0X',
        'E6CK9X"', 'E6CK9X&', 'E6CK9X&&', 'E6CK9X|', 'E6CK9X||',
        'E6CK9X>', 'E6CK9X<', 'E6CK9X^', 'E6CK9X%', 'E6CK9X!',
        'E6CK9X(', 'E6CK9X)', 'E6C K9X', '%CD%', '!CD!',
        '$(echo INJECTED)',
        ('E6CK9X" & echo INJECTED > "{0}" & "' -f $sentinel)
    )
    for ($i = 0; $i -lt $rejectedCodes.Count; $i++) {
        $rejectedArguments = Join-Path $testRoot "rejected join $i arguments.txt"
        $env:HARMONY_TEST_ARGUMENTS_PATH = $rejectedArguments
        $rejected = Invoke-JoinScript $firstLocal @($rejectedCodes[$i])
        Assert-True ($rejected.ExitCode -eq 26) "unsafe or invalid code was accepted: case $i"
        Assert-True (-not (Test-Path -LiteralPath $rejectedArguments)) "invalid code reached the game: case $i"
        Assert-True (-not (Test-Path -LiteralPath $sentinel)) "invalid code executed a sentinel command: case $i"
    }
    $extraJoinArguments = Join-Path $testRoot 'extra join script arguments.txt'
    $env:HARMONY_TEST_ARGUMENTS_PATH = $extraJoinArguments
    $extraJoin = Invoke-JoinScript $firstLocal @('E6CK9X', '-NoLaunch')
    Assert-True ($extraJoin.ExitCode -eq 26 -and -not (Test-Path -LiteralPath $extraJoinArguments)) 'extra join option reached setup or game'
    $cmdSentinel = Join-Path $artifactRoot 'cmd-injected-sentinel.txt'
    foreach ($cmdPayload in @('E6CK9X&echo INJECTED>cmd-injected-sentinel.txt',
            'E6CK9X&&echo INJECTED>cmd-injected-sentinel.txt',
            'E6CK9X|echo INJECTED>cmd-injected-sentinel.txt',
            'E6CK9X||echo INJECTED>cmd-injected-sentinel.txt')) {
        $env:HARMONY_TEST_ARGUMENTS_PATH = Join-Path $testRoot 'cmd rejected arguments.txt'
        $command = 'powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File Join-Harmony.ps1 "' + $cmdPayload + '"'
        Push-Location $artifactRoot
        try {
            $previousPreference = $ErrorActionPreference
            $ErrorActionPreference = 'Continue'
            try {
                $cmdOutput = @(& cmd.exe /d /s /c $command 2>&1)
                $cmdExit = $LASTEXITCODE
            } finally {
                $ErrorActionPreference = $previousPreference
            }
        } finally {
            Pop-Location
        }
        Assert-True ($cmdExit -eq 26) "quoted hostile cmd argument was accepted: $cmdPayload"
        Assert-True (-not (Test-Path -LiteralPath $cmdSentinel)) "cmd executed hostile code: $cmdPayload"
    }
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
        "[IO.File]::WriteAllLines(`$env:HARMONY_TEST_ARGUMENTS_PATH, [string[]]`$args)`r`n[Console]::Error.WriteLine('synthetic setup boundary')`r`nexit 21`r`n",
        [Text.UTF8Encoding]::new($false))
    $env:LOCALAPPDATA = Join-Path $testRoot 'Missing Importer Local AppData'
    $env:HARMONY_NO_PAUSE = '1'
    $env:HARMONY_TEST_ARGUMENTS_PATH = Join-Path $testRoot 'ordinary batch dispatch.txt'
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
    Assert-True (-not (Test-Path -LiteralPath (Join-Path $missingRoot 'Online-Harmony.ps1'))) 'missing-importer test unexpectedly contains menu'
    $defaultDispatch = @(Get-GameArguments $env:HARMONY_TEST_ARGUMENTS_PATH)
    Assert-True ($defaultDispatch.Count -eq 1 -and $defaultDispatch[0] -ceq '-NoLaunch') 'double-click path did not perform setup before opening menu'
    [IO.File]::WriteAllText((Join-Path $missingRoot 'Setup-Harmony.ps1'),
        "[IO.File]::WriteAllLines(`$env:HARMONY_TEST_ARGUMENTS_PATH, [string[]]`$args)`r`nexit 0`r`n",
        [Text.UTF8Encoding]::new($false))
    [IO.File]::WriteAllText((Join-Path $missingRoot 'Online-Harmony.ps1'),
        "[IO.File]::WriteAllText((Join-Path `$PSScriptRoot 'menu-opened.txt'), 'opened')`r`nexit 0`r`n",
        [Text.UTF8Encoding]::new($false))
    $env:HARMONY_TEST_ARGUMENTS_PATH = Join-Path $testRoot 'successful default dispatch.txt'
    Push-Location $missingRoot
    try { & cmd.exe /d /c Launch-Harmony.bat | Out-Null; $menuExit = $LASTEXITCODE }
    finally { Pop-Location }
    Assert-True ($menuExit -eq 0 -and (Test-Path -LiteralPath (Join-Path $missingRoot 'menu-opened.txt'))) 'double-click path did not open menu after setup'
    Assert-True ((Get-GameArguments $env:HARMONY_TEST_ARGUMENTS_PATH) -ceq '-NoLaunch') 'menu opened without preflight setup'
    [IO.File]::WriteAllText((Join-Path $missingRoot 'Setup-Harmony.ps1'),
        "[IO.File]::WriteAllLines(`$env:HARMONY_TEST_ARGUMENTS_PATH, [string[]]`$args)`r`nexit 21`r`n",
        [Text.UTF8Encoding]::new($false))
    $env:HARMONY_TEST_ARGUMENTS_PATH = Join-Path $testRoot 'missing invite batch dispatch.txt'
    Push-Location $missingRoot
    try {
        $previousPreference = $ErrorActionPreference
        $ErrorActionPreference = 'Continue'
        try {
            $missingOutput = @(& cmd.exe /d /c Launch-Harmony.bat --join-code 2>&1)
            $missingExit = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
    } finally {
        Pop-Location
    }
    Assert-True ($missingExit -eq 21) 'missing-code batch dispatch changed'
    $missingDispatch = @(Get-GameArguments $env:HARMONY_TEST_ARGUMENTS_PATH)
    Assert-True ($missingDispatch.Count -eq 1 -and $missingDispatch[0] -ceq '-JoinByInviteCode') 'missing-code batch path no longer invokes the interactive join flow'
    $env:HARMONY_TEST_ARGUMENTS_PATH = Join-Path $testRoot 'configure batch dispatch.txt'
    Push-Location $missingRoot
    try {
        $previousPreference = $ErrorActionPreference
        $ErrorActionPreference = 'Continue'
        try {
            $configureOutput = @(& cmd.exe /d /c Launch-Harmony.bat --configure 2>&1)
            $configureExit = $LASTEXITCODE
        } finally {
            $ErrorActionPreference = $previousPreference
        }
    } finally {
        Pop-Location
    }
    Assert-True ($configureExit -eq 21) 'configure batch dispatch changed'
    $configureDispatch = @(Get-GameArguments $env:HARMONY_TEST_ARGUMENTS_PATH)
    Assert-True ($configureDispatch.Count -eq 1 -and $configureDispatch[0] -ceq '-Configure') 'configure batch path changed'

    Write-Host 'Launcher tests passed: base flows plus language IDs 1-6, invalid values, and legacy profiles.'
} finally {
    foreach ($name in @('LOCALAPPDATA') + $recognizedEnvironment) {
        [Environment]::SetEnvironmentVariable($name, $savedEnvironment[$name], 'Process')
    }
    if (Test-Path -LiteralPath $testRoot) {
        Remove-Item -LiteralPath $testRoot -Recurse -Force
    }
}

exit 0
