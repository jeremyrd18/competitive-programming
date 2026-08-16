#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 105, mod = 1000000000;

int n, m;
vector<int> a(maxn);
vector<bool> vis(maxn, 0);
vector<vector<int> > dp;

vector<vector<int> > adj(maxn);

void dfs(int x){
    vis[x] = 1;
    dp[x][a[x]] = 1;
    for(auto node : adj[x]){
        if(!vis[node]){
            dfs(node);
            for(int i = 1; i <= m; i++){
                dp[x][i] += dp[node][i];
                dp[x][i] %= mod;
                if(i >= a[x]){
                    dp[x][i] += dp[node][i - a[x]];
                }
                dp[x][i] %= mod;
            }
        }
    }
}

signed main(){
    cin >> n >> m;
    dp.resize(n + 5);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i].resize(m + 5);
    }

    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans += dp[1][i];
        ans %= mod;
        cout << ans << endl;
    }
}