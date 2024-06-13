#include <iostream>

using namespace std;

bool checkPrime(string x){
    int l = x.length();

    if (l == 1 && x[0]== '1'){
        return true;
    }

    if (l == 1 && x[0]== '2'){
        return true;
    }

    if ((x[l-1] - '0')%2 != 0){
        return true;
    }

    return false;
}

int main(){
    int n;
    cin>>n;

    string x[n];

    for (int i=0; i<n; i++){
        cin>>x[i];
    }

    for (int i=0; i<n; i++){
        if (checkPrime(x[i])){
            cout<<'T'<<endl;
        }
        else {
            cout<<'F'<<endl;
        }
    }

    return 0;
}