//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

int dfs(int node, int par, vector<vector<int>> &adj, int tmp, int &cut) {
    int cur = 1;
    for (auto child : adj[node]) {
        if (child != par) {
            cur+=dfs(child, node, adj, tmp, cut);
        }
    }
    if(cur>=tmp) {
        cur=0;
        cut++;
    }
    return cur;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 1, r = n, ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cut = 0;
        vector<int> size(n + 1, 0);
        int temp = dfs(1, 0, adj, mid, cut);
        if (cut > k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}
 

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}