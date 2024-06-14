$mode = $args[0]

$binDirectory = "./bin"
if (-not (Test-Path -Path $binDirectory -PathType Container)) {
    New-Item -ItemType Directory -Path $binDirectory | Out-Null
}

$sourceDirectory = "./src"
$suffix = ""

if ($mode -eq "--tray"){
    $sourceDirectory = "./tray"
    $suffix = "_tray"
}

$sourceFiles = Get-ChildItem -Path $sourceDirectory

foreach ($file in $sourceFiles) {
    $compileCommand = $null

    if (($file.Extension -eq ".cc") -or ($file.Extension -eq ".cpp")){
        $compileCommand = "g++ `"$sourceDirectory/$($file.Name)`" -o `"./bin/$($file.BaseName)$($suffix)`""
        Write-Host $compileCommand
    }
    elseif (($file.Extension -eq ".c")){
        $compileCommand = "gcc `"$sourceDirectory/$($file.Name)`" -o `"./bin/$($file.BaseName)$($suffix)`""
        Write-Host $compileCommand
    }
    elseif (($file.Extension -eq ".rs")){
        $compileCommand = "rustc `"$sourceDirectory/$($file.name)`" -o `"./bin/$($file.BaseName)$($suffix)`""
        Write-Host $compileCommand
    }
    else {
        continue
    }

    Write-Host "Compiling $($file.BaseName)"

    Invoke-Expression -Command $compileCommand -ErrorAction SilentlyContinue

    if ($LASTEXITCODE -ne 0) {
        throw "Error compiling $($file.Name). Check the source code for errors."
    }
}

Write-Host "Compiled all submissions successfully!"
