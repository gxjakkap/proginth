$binDirectory = "./bin"
if (-not (Test-Path -Path $binDirectory -PathType Container)) {
    New-Item -ItemType Directory -Path $binDirectory | Out-Null
}

# Step 2: Loop through "./src" folder
$sourceDirectory = "./src"
$sourceFiles = Get-ChildItem -Path $sourceDirectory -Filter *.cc

# Step 3: Compile all .cc files individually using g++ and output to "bin" folder
foreach ($file in $sourceFiles) {
    $outputFileName = Join-Path $binDirectory "$($file.BaseName).exe"
    $compileCommand = "g++ `"$($file.FullName)`" -o `"$outputFileName`""

    Write-Host "Compiling $($file.BaseName)"

    Invoke-Expression -Command $compileCommand -ErrorAction SilentlyContinue

    # Step 4: If the compilation fails, throw an error
    if ($LASTEXITCODE -ne 0) {
        throw "Error compiling $($file.Name). Check the source code for errors."
    }
}

# Step 5: If all files compiled successfully, print out "Compiled all submissions successfully!"
Write-Host "Compiled all submissions successfully!"
