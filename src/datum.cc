#include <iostream>
#include <string>

using namespace std;

int main(){
    int sd[12] = {5, 1, 1, 4, 6, 2, 4, 7, 3, 5, 1, 3};
    string dow[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int d, m, o;
    cin>>d>>m;

    int f = (8-sd[m-1]);
    if (d<=f){
        cout<<dow[sd[m-1]+d-2]<<endl;
    }
    else {
        int n = d-f;
        if (n<8){
            cout<<dow[n-1]<<endl;
        }
        else if (n<15){
            cout<<dow[n-8]<<endl;
        }
        else if (n<22){
            cout<<dow[n-15]<<endl;
        }
        else if (n<29) {
            cout<<dow[n-22]<<endl;
        }
        else {
            cout<<dow[n-29]<<endl;
        }
    }
    return 0;
}