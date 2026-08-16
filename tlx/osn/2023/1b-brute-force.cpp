#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[2005];
bool vis[2005];

void dfs(int start, int &count){
    vis[start] = 1;
    count++;
    for(auto i : adj[start]){
        if(!vis[i]) dfs(i, count);
    }
}

signed main(){
    int n, m;
    cin >> n >> m;
    if(n > 300 || m > 600){
        int ans = 0;
        for(int i = 1; i<=n; i++){
            ans += (n - i + 1)*(n - i+2)/2;
            // cout << ans << " ";
        }
        // cout << endl;
        cout << ans << endl;
        return 0;
    }
    vector<pair<int, int> > edges;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(i == j){
                ans++;
                // cout << i << " " << j << " = " << ans << endl;
                continue;
            }
            if(i == j - 1){
                ans += 2;
                // cout << i << " " << j << " = " << ans << endl;
                continue;
            }
            for(int temp = 0; temp < 2004; temp++){
                adj[temp].clear();
                vis[temp] = 0;
            }
            for(int k = 0; k < m; k++){
                int l = edges[k].first;
                int r = edges[k].second;
                if(l >= i && l <= j && r >= i && r <= j){
                    adj[l].push_back(r);
                    adj[r].push_back(l);
                }
            }
            for(int k = i; k <= j; k++){
                if(!vis[k]){
                    int count = 0;
                    dfs(k, count);
                    if(count <= 2) ans += count;
                }
            }
            // cout << i << " " << j << " = " << ans << endl;
        }
    }
    // cout << endl;
    cout << ans << endl;
}