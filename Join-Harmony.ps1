param([string]$InviteCode)

$ErrorActionPreference = 'Stop'

# This entry point is intended to be invoked from PowerShell, where the code
# arrives as a data argument rather than being expanded inside a batch file.
if ($args.Count -ne 0 -or -not $InviteCode) {
    Write-Output 'Supply exactly one six-character invite code.'
    exit 26
}

$normalizedCode = $InviteCode.ToUpperInvariant()
if ($normalizedCode -cnotmatch '^[ABCDEFGHJKMNPQRSTUVWXYZ23456789]{6}$') {
    Write-Output 'Please enter a valid six-character invite code.'
    exit 26
}

& powershell.exe -NoLogo -NoProfile -STA -ExecutionPolicy Bypass `
    -File (Join-Path $PSScriptRoot 'Setup-Harmony.ps1') `
    -JoinByInviteCode -InviteCode $normalizedCode
exit $LASTEXITCODE
