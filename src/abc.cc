#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i[3];
    char order[4];

    for (int j=0; j<3; j++){
        cin>>i[j];
    }

    sort(i, i+3);

    cin>>order;

    for (int j=0; j<3; j++){
        char co = order[j];
        if (co == 'A'){
            cout<<i[0]<<" ";
        }
        else if (co == 'B'){
            cout<<i[1]<< " ";
        }
        else {
            cout<<i[2]<< " ";
        }
    }

    return 0;
}