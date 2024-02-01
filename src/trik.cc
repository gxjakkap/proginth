#include <iostream>

using namespace std;

int main() {
    int p = 1;
    string c;

    cin>>c;

    for(int i = 0; i<c.size(); i++){

        if (c[i] == 'A'){
            if (p == 1){
                p = 2;
            }
            else if (p == 2) {
                p = 1;
            }
        }

        else if (c[i] == 'B'){
            if (p == 2){
                p = 3;
            }
            else if (p == 3) {
                p = 2;
            }
        }
        else if (c[i] == 'C'){
            if (p == 1){
                p = 3;
            }
            else if (p == 3){
                p = 1;
            }
        }
    }

    cout<<p;

    return 0;
}