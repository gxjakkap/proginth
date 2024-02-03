#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x, y, t;
    int rt;
    cin>>x>>y;

    if (x > y){
        cout<<2;
        return 0;
    }

    t = y / x;
    rt = round(t);

    if (rt < t){
        cout<<(rt + 1);
    }
    else {
        cout<<rt;
    }

    return 0;
}