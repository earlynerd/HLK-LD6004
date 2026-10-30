#Requires -RunAsAdministrator
[CmdletBinding()]
param(
    [ValidateRange(10, 120)]
    [int]$DurationSeconds = 60
)

$ErrorActionPreference = 'Stop'
$radarProjectRoot = Split-Path -Parent $PSScriptRoot
$radarCaptureStamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$radarCaptureName = "ld6004-usb-$radarCaptureStamp-$PID"
$radarCaptureDirectory = Join-Path $radarProjectRoot "captures\usb-enumeration\$radarCaptureName"
$radarTracePath = Join-Path $radarCaptureDirectory 'enumeration.etl'
$radarLogPath = Join-Path $radarCaptureDirectory 'capture.log'
$radarTraceStarted = $false
$radarTraceStopped = $false

New-Item -ItemType Directory -Path $radarCaptureDirectory | Out-Null

# USBHUB3: Default, USBError, StateMachine, Enumeration, Rundown.
# No transfer payload keywords; no driver, device, or firmware changes.
$radarProvider = 'Microsoft-Windows-USB-USBHUB3'
$radarKeywords = '0x8603'
$radarMetadata = [ordered]@{
    StartedAt       = (Get-Date).ToString('o')
    DurationSeconds = $DurationSeconds
    SessionName     = $radarCaptureName
    Provider        = $radarProvider
    Keywords        = $radarKeywords
    MaximumMiB      = 32
    TracePath       = $radarTracePath
    Scope           = 'USB hub enumeration events; no device reset or firmware operation is performed by this script.'
}
$radarMetadata | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $radarCaptureDirectory 'capture.json') -Encoding utf8

try {
    $radarStartOutput = & logman.exe start $radarCaptureName -ets `
        -o $radarTracePath -p $radarProvider $radarKeywords 5 `
        -nb 16 64 -bs 64 -f bincirc -max 32 2>&1
    $radarStartExit = $LASTEXITCODE
    $radarStartOutput | Out-File -LiteralPath $radarLogPath -Encoding utf8
    if ($radarStartExit -ne 0) {
        throw "Could not start the USB trace (exit $radarStartExit). See $radarLogPath"
    }
    $radarTraceStarted = $true

    Write-Host ""
    Write-Host "RECORDING for $DurationSeconds seconds." -ForegroundColor Green
    Write-Host 'Repeat the failing radar connection / 3.3 V power-cycle once now.'
    Write-Host 'The script only records Windows USB events. It will stop automatically.'
    Write-Host "Output: $radarCaptureDirectory"

    $radarDeadline = [DateTimeOffset]::Now.AddSeconds($DurationSeconds)
    while ([DateTimeOffset]::Now -lt $radarDeadline) {
        Start-Sleep -Milliseconds 500
    }
}
finally {
    if ($radarTraceStarted) {
        $radarStopOutput = & logman.exe stop $radarCaptureName -ets 2>&1
        $radarStopExit = $LASTEXITCODE
        $radarStopOutput | Out-File -LiteralPath $radarLogPath -Encoding utf8 -Append
        if ($radarStopExit -eq 0) {
            $radarTraceStopped = $true
        }
        else {
            Write-Warning "Trace stop failed. Run: logman stop $radarCaptureName -ets"
        }
    }
}

if (-not $radarTraceStopped) {
    throw 'The capture did not finish normally; inspect capture.log.'
}

# Decode through the installed Windows provider manifest. Preserve the ETL
# even when event-message decoding is unavailable on this Windows build.
try {
    $radarEvents = @(Get-WinEvent -Path $radarTracePath -Oldest -ErrorAction Stop)
    $radarEvents | Select-Object TimeCreated, Id, LevelDisplayName, ProviderName, Message |
        ConvertTo-Json -Depth 5 |
        Set-Content -LiteralPath (Join-Path $radarCaptureDirectory 'events.json') -Encoding utf8

    $radarXmlWriter = [System.IO.StreamWriter]::new(
        (Join-Path $radarCaptureDirectory 'events.xml'),
        $false,
        [System.Text.UTF8Encoding]::new($false)
    )
    try {
        $radarXmlWriter.WriteLine('<Events>')
        foreach ($radarEvent in $radarEvents) {
            $radarXmlWriter.WriteLine($radarEvent.ToXml())
        }
        $radarXmlWriter.WriteLine('</Events>')
    }
    finally {
        $radarXmlWriter.Dispose()
    }
    Write-Host "Decoded $($radarEvents.Count) events."
}
catch {
    $_.Exception.Message | Set-Content -LiteralPath (Join-Path $radarCaptureDirectory 'decode-error.txt') -Encoding utf8
    Write-Warning 'The ETL was saved, but automatic event decoding failed. The raw trace remains available.'
}

$radarTraceHash = Get-FileHash -LiteralPath $radarTracePath -Algorithm SHA256
$radarTraceHash | Select-Object Algorithm, Hash, Path | ConvertTo-Json |
    Set-Content -LiteralPath (Join-Path $radarCaptureDirectory 'trace-hash.json') -Encoding utf8
Write-Host ""
Write-Host "Capture complete: $radarCaptureDirectory" -ForegroundColor Green
