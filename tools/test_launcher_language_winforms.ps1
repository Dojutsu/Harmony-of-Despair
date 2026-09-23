$ErrorActionPreference = 'Stop'
$launcher = Join-Path $PSScriptRoot '../Setup-Harmony.ps1'
$tokens = $null
$errors = $null
$ast = [System.Management.Automation.Language.Parser]::ParseFile($launcher, [ref]$tokens, [ref]$errors)
if ($errors.Count -ne 0) { throw "Settings script has $($errors.Count) parse error(s)." }
foreach ($name in @('Test-HarmonyLanguage', 'Test-HarmonyPlayerName',
                   'Read-LauncherProfile', 'Write-LauncherProfile',
                   'Show-HarmonySettings')) {
    $definition = $ast.Find({ param($node)
        $node -is [System.Management.Automation.Language.FunctionDefinitionAst] -and
        $node.Name -eq $name
    }, $true)
    if (-not $definition) { throw "Missing $name function." }
    . ([scriptblock]::Create($definition.Extent.Text))
}
Add-Type -AssemblyName System.Windows.Forms

function Check-SettingsDialog([string]$currentLanguage, [int]$selectedIndex,
                              [string]$expectedLanguage, [bool]$cancel = $false,
                              [string]$enteredName = 'New Name') {
    $script:dialogError = $null
    $script:enteredNameForDialog = $enteredName
    $script:cancelForDialog = $cancel
    $script:selectedIndexForDialog = $selectedIndex
    $script:currentLanguageForDialog = $currentLanguage
    $timer = [System.Windows.Forms.Timer]::new()
    $timer.Interval = 100
    $timer.Add_Tick({
        $timer.Stop()
        try {
            $form = [System.Windows.Forms.Application]::OpenForms[0]
            if (-not $form) { throw 'Settings form did not open.' }
            $nameBox = @($form.Controls | Where-Object { $_ -is [System.Windows.Forms.TextBox] })[0]
            $languageBox = @($form.Controls | Where-Object { $_ -is [System.Windows.Forms.ComboBox] })[0]
            $save = @($form.Controls | Where-Object { $_ -is [System.Windows.Forms.Button] -and $_.Text -eq 'Save' })[0]
            if (-not $nameBox -or -not $languageBox -or -not $save) { throw 'Missing settings control.' }
            $labels = @('Use default (English)', 'English', 'Japanese', 'German',
                        'French', 'Spanish', 'Italian')
            if ($languageBox.Items.Count -ne $labels.Count) { throw 'Wrong language choice count.' }
            for ($index = 0; $index -lt $labels.Count; $index++) {
                if ($languageBox.Items[$index] -cne $labels[$index]) {
                    throw "Language ID $index has wrong label: $($languageBox.Items[$index])"
                }
            }
            $expectedInitialIndex = if (Test-HarmonyLanguage $script:currentLanguageForDialog) { [int]$script:currentLanguageForDialog } else { 0 }
            if ($languageBox.SelectedIndex -ne $expectedInitialIndex) { throw 'Stored language was not selected.' }
            $nameBox.Text = $script:enteredNameForDialog
            if ($nameBox.Text -cne $script:enteredNameForDialog) { throw 'Name input was silently truncated.' }
            $languageBox.SelectedIndex = $script:selectedIndexForDialog
            if ($script:cancelForDialog) { $form.Close() } else { $save.PerformClick() }
        } catch {
            $script:dialogError = $_
            if ($form) { $form.Close() }
        }
    })
    try {
        $timer.Start()
        $result = Show-HarmonySettings 'Old Name' $currentLanguage
        if ($script:dialogError) { throw $script:dialogError }
        if ($cancel) {
            if ($null -ne $result) { throw 'Cancel returned settings to save.' }
            return $null
        }
        if (-not $result -or $result.Name -cne $enteredName -or
            $result.Language -cne $expectedLanguage) {
            throw "Wrong dialog result: $($result | Out-String)"
        }
        return $result
    } finally {
        $timer.Stop()
        $timer.Dispose()
    }
}

$profileRoot = Join-Path ([IO.Path]::GetTempPath()) ('harmony-language-ui-test-' + [guid]::NewGuid().ToString('N'))
$profilePath = Join-Path $profileRoot 'launcher-profile.cfg'
try {
    foreach ($language in 1..6) {
        $selected = Check-SettingsDialog '' $language ([string]$language)
        Write-LauncherProfile '2002' $selected.Name $selected.Language
        $stored = Read-LauncherProfile
        if ($stored.Xuid -cne '2002' -or $stored.Name -cne 'New Name' -or
            $stored.Language -cne [string]$language) {
            throw "Language ID $language did not persist with identity and name."
        }
    }
    $beforeCancel = (Get-FileHash -LiteralPath $profilePath).Hash
    Check-SettingsDialog '6' 2 '2' $true | Out-Null
    if ((Get-FileHash -LiteralPath $profilePath).Hash -cne $beforeCancel) {
        throw 'Cancel changed the launcher profile.'
    }
    $default = Check-SettingsDialog '6' 0 ''
    Write-LauncherProfile '2002' $default.Name $default.Language
    if ((Read-LauncherProfile).Language -cne '' -or
        (Get-Content -LiteralPath $profilePath -Raw) -match 'HARMONY_USER_LANGUAGE=') {
        throw 'Default choice wrote a language selection.'
    }
    $longName = Check-SettingsDialog '' 0 '' $false 'ABCDEFGHIJKLMNOP'
    if (Test-HarmonyPlayerName $longName.Name) {
        throw 'Existing player-name validator accepted a 16-character name.'
    }
    Write-Host 'Launcher settings WinForms passed: exact labels/IDs 1-6, persistence, default, cancel, and name validation.'
} finally {
    $resolvedRoot = [IO.Path]::GetFullPath($profileRoot)
    $resolvedTemp = [IO.Path]::GetFullPath([IO.Path]::GetTempPath())
    if (-not $resolvedRoot.StartsWith($resolvedTemp, [StringComparison]::OrdinalIgnoreCase) -or
        -not ((Split-Path -Leaf $resolvedRoot) -match '^harmony-language-ui-test-[0-9a-f]{32}$')) {
        throw 'Refusing to remove an unexpected test directory.'
    }
    if (Test-Path -LiteralPath $resolvedRoot) {
        Remove-Item -LiteralPath $resolvedRoot -Recurse -Force
    }
}
