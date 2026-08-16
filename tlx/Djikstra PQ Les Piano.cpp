//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int v, e, a, b;
    cin >> v >> e >> a >> b;
    vector<pair<int, int> > adj[v + 2];
    for(int i = 0; i<e; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    priority_queue<pair<int, int> > pq;
    int dis[v + 3];
    memset(dis, 1000000007, sizeof dis);
    dis[a] = 0;
    pq.push({0, a});
    while(!pq.empty()){
        int val = - pq.top().first;
        int next = pq.top().second;
        // cout << val << endl;
        pq.pop();
        if(val > dis[next]){
            continue;
        }
        for(auto x : adj[next]){
            int node = x.first;
            int edge = x.second;
            // cout << dis[node];
            if(dis[node] > val + edge){
                dis[node] = val + edge;
                pq.push({- dis[node], node});
            }
        }
    }
    cout << dis[b] << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}