$name=$args[0]

$dir = "./tests"

if (!$name){
    throw "Invalid Parameter!"
}

if (Test-Path -Path "$dir/$name.py" -PathType Leaf){
    Invoke-Expression -Command "py $($dir)/$($name).py"
}
else {
    Write-Host "Test does not exist for $($name)!"
}