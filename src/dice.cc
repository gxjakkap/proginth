#include <iostream>
#include <string>

using namespace std;

// default dice: 1, 2, 3, 5, 4, 6 : Top, Front, Left, Rear, Right, Bottom
/**
    Actions:
    F - Forward (top>front, front>bottom, bottom>rear, rear>top)
    B - Backward (front>top, top>rear, rear>bottom, bottom>front)
    L - Left (right>top, top>left, left>bottom, bottom>right)
    R - Right (left>top, top>right, right>bottom, bottom>left)
    C - Clockwise (front>left, left>rear, rear>right, right>front)
    D - Counter Clockwise (front>right, right>rear, rear>left, left>front)
*/
int n, d[6][6];
string s[6];

void diceOps(int i, char a){
    int t;
    switch (a){
        case 'F':
            t = d[i][0];
            d[i][0] = d[i][3];
            d[i][3] = d[i][5];
            d[i][5] = d[i][1];
            d[i][1] = t;
            break;
        case 'B': //wrong   
            t = d[i][1];
            d[i][1] = d[i][5];
            d[i][5] = d[i][3];
            d[i][3] = d[i][0];
            d[i][0] = t;
            break;
        case 'L':
            t = d[i][4];
            d[i][4] = d[i][5];
            d[i][5] = d[i][2];
            d[i][2] = d[i][0];
            d[i][0] = t;
            break;
        case 'R':
            t = d[i][2];
            d[i][2] = d[i][5];
            d[i][5] = d[i][4];
            d[i][4] = d[i][0];
            d[i][0] = t;
            break;
        case 'C':
            t = d[i][1];
            d[i][1] = d[i][4];
            d[i][4] = d[i][3];
            d[i][3] = d[i][2];
            d[i][2] = t;
            break;
        case 'D':
            t = d[i][1];
            d[i][1] = d[i][2];
            d[i][2] = d[i][3];
            d[i][3] = d[i][4];
            d[i][4] = t;
            break;
    
    }
}

int main(){
    cin>>n;

    for (int i = 0; i<n; i++){
        d[i][0] = 1;
        d[i][1] = 2;
        d[i][2] = 3;
        d[i][3] = 5;
        d[i][4] = 4;
        d[i][5] = 6;
    }

    for (int i = 0; i<n; i++){
        cin>>s[i];
    }

    for (int i = 0; i<n; i++){
        string c = s[i];
        for (int j = 0; j<s[i].length(); j++){
            diceOps(i, c[j]);
        }
    }

    for (int i = 0; i<n; i++){
        cout<<d[i][1]<<" ";
        if (i == n-1){
            cout<<endl;
        }
    }

    return 0;
}