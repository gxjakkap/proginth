#include <iostream>

using namespace std;

int main () {
    int m, n;
    int a[110][110];
    int b[110][110];

    cin >> m >> n ;

    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }

    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cin>>b[i][j];
        }
    }

    for (int i = 0; i<m; i++){
        for (int j = 0; j<n; j++){
            cout<<a[i][j] + b[i][j]<<" ";
        }
        cout << "\n";
    }

    return 0;
}