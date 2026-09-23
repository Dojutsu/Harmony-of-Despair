param([string]$ImagePath)
$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot '../Online-Harmony.ps1') -FunctionsOnly
function Read-OnlinePlayerName { 'QA Player' }
function Get-OnlineSnapshots {
    [pscustomobject]@{
        process_id = 42; process_start_time = '123'; mode = 'hosting'; invite_code = 'AB7K2Q'
        local_player = @{ name = 'DOJUTSU' }; player_count = 6; max_players = 6
        members = @(
            @{ xuid = '0000000000000001'; name = 'DOJUTSU'; is_host = $true },
            @{ xuid = '0000000000000002'; name = 'Alice'; is_host = $false },
            @{ xuid = '0000000000000003'; name = 'Bob'; is_host = $false },
            @{ xuid = '0000000000000004'; name = 'Charlie'; is_host = $false },
            @{ xuid = '0000000000000005'; name = 'Player ...5AA1'; is_host = $false },
            @{ xuid = '0000000000000006'; name = 'Player ...6BB2'; is_host = $false }
        )
    }
}
$result = @{ Error = $null; Passed = $false }
$realOnlineAction = ${function:Get-OnlineAction}
$joinCapture = @{ Code = $null; Arguments = $null }
function Get-OnlineAction([string]$Action, [string]$Code, [bool]$GameRunning) {
    $joinCapture.Code = $Code
    $joinCapture.Arguments = & $realOnlineAction $Action $Code $false
    # Exercise the button without launching a game or changing membership.
    return @('-NoProfile', '-Command', 'exit 0')
}
Start-OnlineCompanion {
    param($form)
    try {
        $roster = @($form.Controls | Where-Object { $_ -is [Windows.Forms.ListView] })[0]
        if ($roster.Items.Count -ne 6) { throw 'Six-member roster did not render.' }
        if ($roster.Items[0].Text -ne 'HOST') { throw 'Missing host badge.' }
        if ($roster.Items[4].SubItems[1].Text -ne 'Player ...5AA1') { throw 'Missing fallback.' }
        $copy = @($form.Controls | Where-Object Text -eq 'Copy Code')[0]
        if (-not $copy.Enabled) { throw 'Copy button disabled for valid host code.' }
        # Exercise actual clipboard handler and restore the prior plain text.
        $oldData = [Windows.Forms.Clipboard]::GetDataObject()
        $savedData = [Windows.Forms.DataObject]::new()
        if ($oldData) {
            foreach ($format in $oldData.GetFormats($false)) {
                $savedData.SetData($format, $false, $oldData.GetData($format, $false))
            }
        }
        try {
            $copy.PerformClick()
            if ([Windows.Forms.Clipboard]::GetText() -cne 'AB7K2Q') { throw 'Clipboard content mismatch.' }
        } finally {
            if ($oldData) { [Windows.Forms.Clipboard]::SetDataObject($savedData, $true) }
            else { [Windows.Forms.Clipboard]::Clear() }
        }
        if ($ImagePath) {
            $bitmap = [Drawing.Bitmap]::new($form.Width, $form.Height)
            try { $form.DrawToBitmap($bitmap, [Drawing.Rectangle]::new(0, 0, $form.Width, $form.Height)); $bitmap.Save($ImagePath) }
            finally { $bitmap.Dispose() }
        }
        $codeBox = @($form.Controls | Where-Object { $_ -is [Windows.Forms.TextBox] })[0]
        $codeBox.Text = 'D8RCFE'
        $joinButton = @($form.Controls | Where-Object Text -eq 'Join by Code')[0]
        $joinButton.PerformClick()
        if ($joinCapture.Code -cne 'D8RCFE') { throw 'Join button lost the entered code.' }
        if ($joinCapture.Arguments[-1] -cne 'D8RCFE' -or
            $joinCapture.Arguments[-3] -cne '-JoinByInviteCode') { throw 'Join launcher arguments incorrect.' }
        $result.Passed = $true
    } catch { $result.Error = $_ }
    finally { $form.Close() }
}
if ($result.Error) { throw $result.Error }
if (-not $result.Passed) { throw 'WinForms test did not execute.' }
Write-Output 'WinForms rendering, host badge, fallback, clipboard, and independent close passed.'
