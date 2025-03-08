#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**
    Still doesn't pass last 2 tests. I'll come back later when I understand C better :(
    https://programming.in.th/submissions/184202
*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> x(n, 0); // store magnet pole facing up
    vector<pair<int, int>> o(m); // store operations in matrix form: [a, k]
    vector<int> s(q); // store queries


    for (int i = 0; i<m; ++i){
        cin>>o[i].first>>o[i].second; // get operations input
    }

    for (int i = 0; i<q; ++i){
        cin>>s[i]; // get queries
    }

    for (int i = 0; i<m; ++i){
        int a = o[i].first-1;
        int k = o[i].second;

        for (int j = 0; j<k; ++j){
            x[a + j] ^= 1;
        }
    }


    for (int i = 0; i<q; ++i){
        int cq = s[i]-1;
        int mn = 0, mx = 0;

        // count up
        for (int j = cq; j<n; ++j){
            if (x[j] != x[cq]){
                break;
            }
            mx++;
        }

        //count down

        for (int j = cq-1; j>=0; --j){
            if (x[j] != x[cq]){
                break;
            }
            mn++;
        }
        cout<<(mn + mx)<<"\n";
    }

    return 0;

}