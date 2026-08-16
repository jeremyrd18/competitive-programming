//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n), h(n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin >> c[i] >> h[i];
        sum += h[i];
    }
    vector<int> dp(sum + 5, 1e18);
    dp[0] = 0;
    for(int i = 0; i<n; i++){
        for(int j = sum; j >= h[i]; j--){
            if(dp[j - h[i]] + c[i] <= x){
                dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
            }
        }
    }
    for(int i = sum; i>=0; i--){
        if(dp[i] != 1e18){
            cout << i << endl;
            return;
        }
    }
}

signed main(){
	int t;
    // cin >> t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}