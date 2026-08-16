//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
vector<int> adj[200007];
int special[200007], jarak[200007];
bool need[200007];
int xx, yy;


bool dfs(int ch, int par, int j){
    bool res = special[ch];
    jarak[ch] = j;
    for(int v : adj[ch]){
        if(v == par) continue;
        res |= dfs(v, ch, j+1);
    }
    return need[ch] = res;
} 

void solve(){
    int n, k;
    memset(special, 0, sizeof special);
    memset(need, 1, sizeof need);
    cin >> n >> k >> xx >> yy;
    for(int i = 0; i<=n; i++){
        adj[i].clear();
    }
    for(int i = 0; i<k; i++){
        int temp;
        cin >> temp;
        special[temp] = 1;
    }
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    special[xx] = special[yy] = true;
    dfs(xx, 0, 0);
    int ja = 0;
    for(int i = 1; i<=n; i++){
        if(need[i]) ja++;
    }
    ja--;
    cout << jarak[yy] + 2*(ja - jarak[yy]) << endl;
}

signed main(){
  int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        // cout << "t" << i << endl;
        solve();
    }
}