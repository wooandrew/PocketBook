# run.ps1

param(
    [Parameter(Mandatory=$true)]
    [ValidateSet("clean", "build", "run", "all")]
    [string]$Target
)

$buildDir = "build"
$binDir = "bin/"
$executable = "finmanp.exe"  # change if needed

function Clean {
    Write-Host "Cleaning build directory..."
    if (Test-Path $buildDir) {
        Remove-Item -Recurse -Force $buildDir
    } else {
        Write-Host "Build directory does not exist."
    }

    if (Test-Path $binDir) {
        Remove-Item -Recurse -Force $binDir
    } else {
        Write-Host "Bin directory does not exist."
    }
}

function Configure {
    Write-Host "Configuring project..."
    cmake -S . -B $buildDir
}

function Build {
    Write-Host "Building project..."
    cmake --build $buildDir
}

function Run {
    $exePath = Join-Path $binDir $executable
    if (Test-Path $exePath) {
        Write-Host "Running executable..."
        & $exePath
    } else {
        Write-Host "Executable not found at $exePath"
    }
}

switch ($Target) {
    "clean" { Clean }
    "build" { Configure; Build }
    "run" { Run }
    "all" { Clean; Configure; Build; Run }
}
