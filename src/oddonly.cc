#include <iostream>


using namespace std;

bool checkOdd(int x){
    return ((x % 2) != 0);
}

int main(){
    int n;
    cin>>n;

    long long x[n];

    for (int i=0; i<n; i++){
        cin>>x[i];
    }

    for (int i=0; i<n; i++){
        if ((checkOdd(x[i]))){
            cout<<'T'<<endl;
        }
        else {
            cout<<'F'<<endl;
        }
    }

    return 0;
}