#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> desa, usaha, edges[200005];
bool vis[200005];

int dfs(int idx){
    vis[idx] = 1;
    int minval = desa[idx];
    for(auto nd : edges[idx]){
        if(!vis[nd]){
            vis[nd] = 1;
            minval = min(minval, dfs(nd));
        }
    }
    return minval;
}

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        desa.push_back(x);
        vis[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        usaha.push_back(x);
    }
    sort(usaha.begin(), usaha.end());
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> komponen;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            komponen.push_back(dfs(i));
        }
    }
    sort(komponen.rbegin(), komponen.rend());
    if(komponen.size() > m){
        cout << -1 << endl;
    }
    else{
        int ans = 0;
        for(int i = 0; i < komponen.size(); i++){
            ans += komponen[i] * usaha[i];
        }
        cout << ans;
    }
}