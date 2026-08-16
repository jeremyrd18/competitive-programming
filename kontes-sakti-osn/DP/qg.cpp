//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    int dp[n + 2];
    memset(dp, 0, sizeof dp);
    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--){
        dp[i] = dp[i + 1] + 1;
        if(a[i] + i <= n) dp[i] = min(dp[i], dp[a[i] + i + 1]);
    }
    cout << dp[1] << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}