#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    int x[5][4];
    int s[5] = {0, 0, 0, 0, 0};

    for (int i=0; i<5; i++){
        for (int j=0; j<4; j++){
            cin>>x[i][j];
        }
    }

    for (int i=0; i<5; i++){
        for (int j=0; j<4; j++){
            s[i] += x[i][j];
        }
    }

    int n = sizeof(s) / sizeof(int);

    cout<<(distance(s, max_element(s, s+n)) + 1)<<" "<<*max_element(s, s+n);

    return 0;
}