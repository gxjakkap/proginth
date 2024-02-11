#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    int x[n];
    for (int i = 0; i<n; i++){
        cin>>x[i];
    }

    int s = sizeof(x) / sizeof(n);
    sort(x, x + s);

    if (x[0] == 0){
        for (int i = 1; i<n; i++){
            if (x[i] != 0){
                int r = x[i];
                x[i] = 0;
                x[0] = r;
                break;
            }
        }
    }

    for (int i = 0; i<n; i++){
        cout<<x[i];
    }

    return 0;
}