//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int r, c;
    cin >> r >> c;
    int pref[r + 5][c + 5];
    memset(pref, 0, sizeof pref);
    for(int i = 1; i<=r; i++){
        for(int j = 1; j <= c; j++){
            char x;
            cin >> x;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (x - '0');
        }
    }
    // for(int i = 1; i<=r; i++){
    //     for(int j = 1; j <= c; j++){
    //         cout << pref[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int total = pref[r][c];
    int maxset = 0;
    for(int k = 1; k<=total; k++){
        if(total % k != 0){
            continue;
        }
        int len = k;
        int wide = total/k;
        if(len > r || wide > c) continue;
        for(int i = len; i <=r; i++){
            for(int j = wide; j<=c; j++){
                maxset = max(maxset, pref[i][j] - pref[i][j - wide]
                - pref[i - len][j] + pref[i - len][j - wide]);
            }
        }
    }
    if(maxset == 0) cout << -1 << endl;
    else cout << total - maxset << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}