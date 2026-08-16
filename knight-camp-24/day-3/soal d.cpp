//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
const int N = 200004;
int n, m;
vector<pair<int, int> > adj[N];
bool visited[N];
int val[N];

void dfs(int x){
    visited[x] = 1;
    for(auto a : adj[x]){
        if(!visited[a.first]){
            val[a.first] = val[x] + a.second;
            dfs(a.first);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i<= n + 3; i++){
        adj[i].clear();
        visited[i] = 0;
        val[i] = 0;
    }
    vector<pair<int, pair<int, int> > > v;
    for(int i = 0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, {y, z}});
        adj[x].push_back({y, z});
        adj[y].push_back({x, -z});
    }
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    // for(int i = 0; i<n; i++){
    //     cout << val[i] << " ";
    // }cout << endl;
    for(int i = 0; i<m; i++){
        int a = v[i].first, b = v[i].second.first, c = v[i].second.second;
        if(val[a] + c != val[b]){
            // cout << val[a] << " " << val[b] << endl;
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}