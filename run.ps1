# run.ps1

param(
    [Parameter(Mandatory=$true)]
    [ValidateSet("clean", "build", "run", "all")]
    [string]$Target,

    [ValidateSet("Debug", "Release")]
    [string]$Config = "Debug"
)

$buildDir   = "build/$Config"
$binDir     = "bin/$Config"
$executable = "finmanp.exe"  # change if needed

function Clean {
    Write-Host "Cleaning build and bin directories..."
    if (Test-Path "build") {
        Remove-Item -Recurse -Force "build"
    }
    if (Test-Path "bin") {
        Remove-Item -Recurse -Force "bin"
    }
}

function Configure {
    Write-Host "Configuring project ($Config)..."
    cmake -S . -B $buildDir `
        -DCMAKE_BUILD_TYPE=$Config `
        -DCMAKE_RUNTIME_OUTPUT_DIRECTORY="$PWD/$binDir"
}

function Build {
    Write-Host "Building project ($Config)..."
    cmake --build $buildDir --config $Config
}

function Run {
    $exePath = Join-Path $binDir $executable
    if (Test-Path $exePath) {
        Write-Host "Running executable ($Config)..."
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
