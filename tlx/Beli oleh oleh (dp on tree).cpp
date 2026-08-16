#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000000;
int n, m;
vector<int> adj[105];
vector<int> val(105);
int dp[105][100005];
vector<bool> vis(105, false);
void dfs(int nd){
    vis[nd] = 1;
    dp[nd][val[nd]] = 1; // pasti 1 cara karna ai <= m
    for(auto x : adj[nd]){
        if(!vis[x]){
            dfs(x);
            for(int i = 1; i <= m; i++){
                dp[nd][i] += dp[x][i];
                dp[nd][i] %= mod;
                if(i >= val[nd]){
                    dp[nd][i] += dp[x][i - val[nd]];
                    dp[nd][i] %= mod;
                }
                dp[nd][i] %= mod;
            }
        }
    }
}

signed main(){
    // nd, uang
    memset(dp, 0, sizeof dp);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans += dp[1][i];
        ans %= mod;
        cout << ans << endl;
    }
}