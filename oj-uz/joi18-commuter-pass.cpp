//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, m; // node, edge
    int s, t; // start and end commuter pass
    int u, v; // start and end
    cin >> n >> m >> s >> t >> u >> v;
    vector<pair<int, int> > adj[n + 3];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> scp(n + 5, -1); // c-pass dari s
    vector<int> tcp(n + 5, -1); // c-pass dari t
    priority_queue<pair<int, int> > pq;
    pq.push({0, s});
    // cari scp, pake minus karna dijkstra
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
    pq.push({0, t});
    while(!pq.empty()){
        int cost = - pq.top().first;
        int nd = pq.top().second;
        pq.pop();
        if(tcp[nd] != -1) continue;
        tcp[nd] = cost;
        for(auto x : adj[nd]){
            if(tcp[x.first] == -1){
                pq.push({-(cost + x.second), x.first});
            }
        }
    }
    int len = scp[t];
//    cout << len << endl;
    // conditions
    // 0 -> dijkstra biasa
    // 1 -> gunakan c-pass s -> t
    // 2 -> gunakan c-pass t -> S
    // 3 -> habis c-pass, menuju v
    // cost ga berubah di 1 dan 2
    priority_queue<tuple<int, int, int> > dj; // dist, nd, conditions
    dj.push({0, u, 0});
    int dis[n + 3][4];
    memset(dis, -1, sizeof dis);
    while(!dj.empty()){
//    	cout << "e" << endl;
        int cost = - get<0>(dj.top());
        int nd = get<1>(dj.top());
        int c = get<2>(dj.top());
        dj.pop();
        if(dis[nd][c] != -1){
            continue;
        }
        dis[nd][c] = cost;
        if(c == 0){
            // lanjutttt di c = 0
            for(auto x : adj[nd]){
                if(dis[x.first][c] == -1){
                    dj.push({-(cost + x.second), x.first, 0});
                }
            }
            // c => 1
            for(auto x : adj[nd]){
                if(scp[nd] +  tcp[x.first] + x.second == len && dis[x.first][1] == -1){
                    dj.push({-cost, x.first, 1});
                }
            }
            // c => 2
            for(auto x : adj[nd]){
                if(tcp[nd] +  scp[x.first] + x.second == len && dis[x.first][2] == -1){
                    dj.push({-cost, x.first, 2});
                }
            }
        }
        else if(c == 1){
            // lanjut di c = 1
            for(auto x : adj[nd]){
                if(scp[nd] +  tcp[x.first] + x.second == len && dis[x.first][1] == -1){
                    dj.push({-cost, x.first, 1});
                }
            }
            // c => 3
            for(auto x : adj[nd]){
                if(dis[x.first][3] == -1){
                    dj.push({-(cost + x.second), x.first, 3});
                }
            }
        }
        else if(c == 2){
            // lanjut di c = 2
            for(auto x : adj[nd]){
                if(tcp[nd] +  scp[x.first] + x.second == len && dis[x.first][2] == -1){
                    dj.push({-cost, x.first, 2});
                }
            }
            // c => 3
            for(auto x : adj[nd]){
                if(dis[x.first][3] == -1){
                    dj.push({-(cost + x.second), x.first, 3});
                }
            }
        }
        else{
            for(auto x : adj[nd]){
                if(dis[x.first][c] == -1){
                    dj.push({-(cost + x.second), x.first, 3});
                }
            }
        }
    }
//    int ans = dis[v][0];
//    ans = min(ans , dis[v][1]);
//    ans = min(ans , dis[v][2]);
//    ans = min(ans , dis[v][3]);
//    cout << ans << endl;
	int ans = 1e15;
	for(int i = 0; i < 4; i++){
		if(dis[v][i] != -1){
			ans = min(ans, dis[v][i]);
		}
//		cout << dis[v][i] << endl;
	}
	cout << ans << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}