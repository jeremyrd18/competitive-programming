//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int m, x;
    cin >> m >> x;
    int c[m + 5], h[m + 5];
    for(int i = 0; i<m; ++i){
        cin >> c[i] >> h[i];
    }
    int sumh=accumulate(h, h+m, 0);
	vector<int> dp(sumh+1, 1e12);
    dp[0] = 0;
    for(int i = 0; i<   m; ++i){
        for(int j = sumh; j>=0; --j){
            if(j + h[i] > sumh || x * i < dp[j] + c[i]) continue;
            dp[j + h[i]] = min(dp[j + h[i]], dp[j] + c[i]);
        }
    }
    for(int i = sumh; i >= 0; --i){
        if(dp[i] != 1e12){
            cout << i << endl;
            return;
        }
    }
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}