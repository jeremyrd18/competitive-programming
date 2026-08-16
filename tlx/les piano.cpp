//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, m; 
    int s, t;
    cin >> n >> m >> s >> t;
    vector<pair<int, int> > adj[n + 3];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> scp(n + 5, -1);
    priority_queue<pair<int, int> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        int cost = - pq.top().first;
        int nd = pq.top().second;
        pq.pop();
        if(scp[nd] != -1) continue;
        scp[nd] = cost;
        for(auto x : adj[nd]){
            if(scp[x.first] == -1){
                pq.push({-(cost + x.second), x.first});
            }
        }
    }
    cout << scp[t] << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}