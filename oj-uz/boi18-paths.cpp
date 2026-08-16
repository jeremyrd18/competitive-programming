#include <bits/stdc++.h>
using namespace std;
// #define int long long

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> col(n);
    for(int i = 0; i < n; i++) cin >> col[i], col[i]--;
    vector<int> adj[n + 5];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long dp[k + 5][n + 5][35];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) dp[0][i][(1 << col[i])] = 1;
    for(int i = 1; i < k; i++){
        for(int j = 0; j < n; j++){
            for(int x : adj[j]){
                for(int mask = 0; mask < (1 << k); mask++){
                    if(!(mask & (1 << col[j]))){
                        dp[i][j][mask | (1 << col[j])] += dp[i - 1][x][mask];
                    }
                }
            }
        }
    }
    // cout << (1 << k) << endl;
    long long ans = 0;
    for(int i = 1; i < k; i++){
        for(int j = 0; j < n; j++){
            for(int mask = 0; mask < (1 << k); mask++){
                ans += dp[i][j][mask];
            }
        }
    }
    cout << ans << endl;
}