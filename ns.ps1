$fileName = $args[0]
$ext = $args[1]

if ($null -eq $ext){
    $ext = "cc"
}

try {
    if (($ext -eq "cc") -or ($ext -eq "cpp")){
        if (Test-Path -Path "./src/$fileName.cc" -PathType Leaf){
            Write-Host "./src/$fileName.cc already existed!"
        }
        else {
            Copy-Item "./template/cpp.cc" -Destination "./src/$fileName.cc" -ErrorAction Stop
            Write-Host "./src/$fileName.cc created successfully!"
        }
    }
    elseif ($ext -eq "c"){
        if (Test-Path -Path "./src/$fileName.c" -PathType Leaf){
            Write-Host "./src/$fileName.c already existed!"
        }
        else {
            Copy-Item "./template/c_template.c" -Destination "./src/$fileName.c" -ErrorAction Stop
            Write-Host "./src/$fileName.c created successfully!"
        }
    }
    elseif (($ext -eq "rs") -or ($ext -eq "rust")){
        if (Test-Path -Path "./src/$fileName.rs" -PathType Leaf){
            Write-Host "./src/$fileName.rs already existed!"
        }
        else {
            Copy-Item "./template/rust.rs" -Destination "./src/$fileName.rs" -ErrorAction Stop
            Write-Host "./src/$fileName.rs created successfully!"
        }
    }
    else {
        if (Test-Path -Path "./src/$fileName.$ext" -PathType Leaf){
            Write-Host "./src/$fileName.$ext already existed!"
        }
        else {
            New-Item -Path "./src/$fileName.$ext" -ItemType file -ErrorAction Stop
            Write-Host "./src/$fileName.$ext created successfully!"
        }
    }
}
catch {
    Write-Host "Error while creating $_"
}