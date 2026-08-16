#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
    }
    int dp[2][k + 1]; // pake flying table agar tidak RTE
    memset(dp, 0, sizeof dp);
    dp[1][0] = 1;
    for(int i = 2; i <= n; i++){
        int cur = (i % 2);
        int bef = ((i - 1) % 2);
        dp[cur][0] = dp[bef][0];
        dp[cur][0] %= MOD;
        for(int j = 1; j <= k; j++){
            // if(j >= i) continue;
            dp[cur][j] = ((j + 1) * dp[bef][j]);
            dp[cur][j] %= MOD;
            dp[cur][j] += ((i - j) * dp[bef][j - 1]);
            dp[cur][j] %= MOD;
            // dp[cur][j] += (dp[bef][j - 1];
        }
    }
    cout << dp[(n % 2)][k] % MOD << endl;
}

signed main(){
    gas
  int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}