$name=$args[0]
$ext = $args[1]
$mode = $args[2]

$dir = "./src"

if (!$name){
    throw "Invalid Parameter!"
}

if ($mode -eq "--tray"){
    $dir = "./tray"
    $name = "$name" + "_tray"
}

if ($null -eq $ext){
    $ext = "cc"
}

if (($ext -eq "cc") -or ($ext -eq "cpp")){
    if (Test-Path -Path "$dir/$name.cc" -PathType Leaf){
        $compileCommand = "g++ `"$dir\$name.cc`" -o `".\bin\$name`""
        Write-Host "Compiling with command: $compileCommand"
        
        Invoke-Expression -Command $compileCommand -ErrorAction Stop

        if ($LASTEXITCODE -ne 0) {
            throw "Error compiling $name. Check the source code for errors."
        }
        else {
            Write-Host "$name.$ext compiled successfully!"
        }
    }
    else {
        Write-Host "File does not exist!"
    }
}
elseif (($ext -eq "c")){
    if (Test-Path -Path "$dir/$name.c" -PathType Leaf){
        $compileCommand = "gcc `"$dir\$name.c`" -o `".\bin\$name`""
        Write-Host "Compiling with command: $compileCommand"
        
        Invoke-Expression -Command $compileCommand -ErrorAction Stop

        if ($LASTEXITCODE -ne 0) {
            throw "Error compiling $name. Check the source code for errors."
        }
        else {
            Write-Host "$name.$ext compiled successfully!"
        }
    }
    else {
        Write-Host "File does not exist!"
    }
}
elseif (($ext -eq "rs") -or ($ext -eq "rust")){
    if (Test-Path -Path "$dir/$name.rs" -PathType Leaf){
        $compileCommand = "rustc `"$dir\$name.rs`" -o `".\bin\$name`""
        Write-Host "Compiling with command: $compileCommand"
        
        Invoke-Expression -Command $compileCommand -ErrorAction Stop

        if ($LASTEXITCODE -ne 0) {
            throw "Error compiling $name. Check the source code for errors."
        }
        else {
            Write-Host "$name.$ext compiled successfully!"
        }
    }
    else {
        Write-Host "File does not exist!"
    }
}
else {
    Write-Host "Compile command does not exist for $ext!"
    throw "Error"
}