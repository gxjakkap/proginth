$fileName = $args[0]
$ext = $args[1]

if ($null -eq $ext){
    $ext = "cc"
}

try {
    if (($ext -eq "cc") -or ($ext -eq "cpp")){
        if (Test-Path -Path "./tray/$fileName.cc" -PathType Leaf){
            Write-Host "./tray/$fileName.cc already existed!"
        }
        else {
            Copy-Item "./template/cpp.cc" -Destination "./tray/$fileName.cc" -ErrorAction Stop
            Write-Host "./tray/$fileName.cc created successfully!"
        }
    }
    elseif ($ext -eq "c"){
        if (Test-Path -Path "./tray/$fileName.c" -PathType Leaf){
            Write-Host "./tray/$fileName.c already existed!"
        }
        else {
            Copy-Item "./template/c_template.c" -Destination "./tray/$fileName.c" -ErrorAction Stop
            Write-Host "./tray/$fileName.c created successfully!"
        }
    }
    elseif (($ext -eq "rs") -or ($ext -eq "rust")){
        if (Test-Path -Path "./tray/$fileName.rs" -PathType Leaf){
            Write-Host "./tray/$fileName.rs already existed!"
        }
        else {
            Copy-Item "./template/rust.rs" -Destination "./tray/$fileName.rs" -ErrorAction Stop
            Write-Host "./tray/$fileName.rs created successfully!"
        }
    }
    else {
        if (Test-Path -Path "./tray/$fileName.$ext" -PathType Leaf){
            Write-Host "./tray/$fileName.$ext already existed!"
        }
        else {
            New-Item -Path "./tray/$fileName.$ext" -ItemType file -ErrorAction Stop
            Write-Host "./tray/$fileName.$ext created successfully!"
        }
    }
}
catch {
    Write-Host "Error while creating $_"
}