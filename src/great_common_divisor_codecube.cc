#include <iostream>

using namespace std;

int main(){
    int x, y;
    cin>>x;
    cin>>y;
    while (x != 0 && y != 0){
        if (x > y){
            x = x % y;
        }
        else {
            y = y % x;
        }
    }
    if (x == 0){
        cout<<y;
    }
    else {
        cout<<x;
    }
    return 0;
}