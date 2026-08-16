#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 3];
    for(int i = 1; i <= n; i++){
        adj[i].push_back(0);
        adj[i].push_back(n + 1);
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> l1(n + 3), l2(n + 3), r1(n + 3), r2(n + 3);
    for(int i = 1; i <= n; i++){
        auto x = adj[i];
        int cur = lower_bound(x.begin(), x.end(), i) - x.begin();
        l1[i] = adj[i][cur - 1];
        l2[i] = adj[i][cur - 2];
        r1[i] = adj[i][cur];
        r2[i] = adj[i][cur + 1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(r1[i] != (n + 1) && l1[r1[i]] == i){
            ans += 2*(i - max(l2[r1[i]], l1[i]))*(min(r2[i], r1[r1[i]]) - r1[i]);
        }
        ans += (i - l1[i])*(r1[i] - i);
    }
    cout << ans << endl;
}