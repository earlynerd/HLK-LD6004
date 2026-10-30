# Usage: powershell -File tools\jlink\run_identify.ps1
# Generic Cortex-M target; J-Link reports the core it actually finds.
$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$log  = Join-Path $here ("identify_" + (Get-Date -Format 'yyyyMMdd_HHmmss') + ".log")
& 'C:\Program Files\SEGGER\JLink\JLink.exe' -device Cortex-M4 -if SWD -speed 1000 -autoconnect 1 `
    -CommanderScript (Join-Path $here 'identify.jlink') 2>&1 | Tee-Object -FilePath $log
Write-Host "Log: $log"
