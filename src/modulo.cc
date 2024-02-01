#include <iostream>

using namespace std;

int main() {
    int x[11];
    int y[11];

    for (int i=0; i<10; i++){
        cin>>x[i];
    }

    for (int i=0; i<10; i++){
        y[i] = x[i] % 42;
    }

    int d = 1;

    for (int i=1; i<10; i++){
        int j = 0;
        for (j=0; j<10; j++){
            if (y[i] == y[j]){
                break;
            }
        }
        if (i == j){
            d++;
        }
    }

    cout<<d;

    return 0;
}