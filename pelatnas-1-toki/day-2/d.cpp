#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 998244353;

void solve(){
    int n;
    cin >> n;
    int a[n + 5];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int dp[n + 5];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        int maxv = LLONG_MIN, minv = LLONG_MAX;
        for(int j = i; j >= 1; j--){
            maxv = max(maxv, a[j]);
            minv = min(minv, a[j]);
            dp[i] += (maxv - minv) * dp[j - 1];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;
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