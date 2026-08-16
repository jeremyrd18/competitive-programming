//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
int n, m, w;
int we[1005], b[1005], dp[1005][1005];
vector<int> child[1005];
class DisjointSet {
public:
    vector<int>  parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            for(auto x : child[ulp_u]){
                child[ulp_v].push_back(x);
            }
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            //child[ulp_v].push_back(ulp_u);
            for(auto x : child[ulp_v]){
                child[ulp_u].push_back(x);
            }
        }
    }
};
void solve(){
    cin >> n >> m >> w;
    for(int i = 0; i<n; i++){
        cin >> we[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }
    for(int i = 0; i<n; i++){
        child[i].push_back(i);
    }
    DisjointSet ds(n);
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ds.unionBySize(u, v);
    }
    vector<int> par;
    for(int i = 0; i<n; i++){
        if(ds.parent[i] == i){
            par.push_back(i);
        }
    }
    memset(dp, 0, sizeof dp);
    for(int i = 0; i<par.size(); i++){
        for(int j = 0; j<=w; j++){
            dp[i + 1][j] = dp[i][j];
            int ans = 0;
            int totalwe = 0, totalbe = 0;
            for(auto k : child[par[i]]){
                if(j - we[k] >=0){
                    ans = max(ans, dp[i][j - we[k]] + b[k]);
                }
                totalwe += we[k];
                totalbe += b[k];
            }
            if(j - totalwe >= 0){
                ans = max(ans, dp[i][j - totalwe] + totalbe);
            }
            dp[i + 1][j] = max(dp[i + 1][j], ans);
        }
    }
    cout << dp[par.size()][w] << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}