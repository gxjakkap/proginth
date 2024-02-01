$param1=$args[0]

if (!$param1){
    throw "Invalid Parameter!"
}

g++ "./src/$param1.cc" -o "./bin/$param1"

Write-Host "$param1.cc compiled succesfully!"