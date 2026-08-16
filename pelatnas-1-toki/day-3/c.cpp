#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int ans[5001][5001], dp[5001][5001], n, q;

void solve(){
    cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(ans, 0, sizeof ans);
    for(int i = 0; i < n; i++){
        unordered_map<int, int> mp;
        for(int j = i - 1; j >= 0; j--){
            int tmp = mp[-a[j]];
            mp[a[i] + a[j]]++;
            ans[i][j] += tmp;
        }
    }
    memset(dp, 0, sizeof dp);
    for(int i = 2; i < n; i++){
        for(int j = 0; j + i < n; j++){
            dp[j + i][j] = dp[j + i][j + 1] + dp[j + i - 1][j] - dp[j + i - 1][j + 1] + ans[j + i][j];
            // cout << j << " " << j + i << " " << dp[j + i][j] << endl;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << dp[r][l] << endl;
    }    
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