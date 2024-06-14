#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int countZeros(char *s){
    int c = 0;
    int l = strlen(s);
    for (int i = 0; i<l; i++){
        if (s[i] == '0'){
            c++;
        }
    }
    return c;
}

int main(){
    char a[101], b[101];
    char o;

    cin>>a;
    cin>>o;
    cin>>b;

    if (o == '+'){
        string r;
        int c = 0;
        int lenA = strlen(a);
        int lenB = strlen(b);
        int maxLen = max(lenA, lenB);

        for (int i = 0; i < maxLen; ++i) {
            int dA = (i < lenA) ? a[lenA - 1 - i] - '0' : 0;
            int dB = (i < lenB) ? b[lenB - 1 - i] - '0' : 0;
            int s = dA + dB + c;
            c = s / 10;
            r.push_back((s % 10) + '0');
        }

        if (c > 0) {
            r.push_back(c + '0');
        }

        reverse(r.begin(), r.end());
        cout<<r;
    }
    else {
        cout<<"1";
        for (int i = 0; i<countZeros(a); i++){
            cout<<0;
        }
        for (int i = 0; i<countZeros(b); i++){
            cout<<0;
        }
    }
    return 0;
}