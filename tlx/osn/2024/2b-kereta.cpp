#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1000000007, maxn = 0, INF = 1e18;

void solve(){
    int n, m, k, t, p, q;
    cin >> n >> m >> k >> t >> p >> q;
    /*
    k = biaya angkot
    t = harga entry stasiun
    p = start
    q = end
    */
    vector<pii> temp_adj[n + 1];
    vector<pii> adj[2 * n + 1];
    for(int i = 1; i < n; i++){
        adj[i].pb({i + 1, k}); // angkot
        adj[i + 1].pb({i, k});
        adj[i].pb({i + n, t}); // masuk stasiun
        adj[i + n].pb({i, 0});
    }
    adj[n].pb({2 * n, t});
    adj[2 * n].pb({n, 0});

    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b) swap(a, b);
        adj[a + n].pb({b + n, d});
        adj[b + n].pb({a + n, d});
        temp_adj[a].pb({c, b});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 1; i < n; i++){
        for(auto x: temp_adj[i]){
            pq.push(x);
        }

        while(!pq.empty() && pq.top().second <= i){
            pq.pop();
        }

        if(!pq.empty()){
            adj[i + n].pb({i + 1 + n, pq.top().fi});
            adj[i + 1 + n].pb({i + n, pq.top().fi});
        }
    }

    while(!pq.empty()) pq.pop();

    vi dist(2 * n + 1, INF);
    dist[p] = 0;
    pq.push({0, p});

    while(!pq.empty()){
        auto [cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;
        
        for(auto nx: adj[cur]){
            int nx_node = nx.fi;
            int nx_cost = nx.se;
            if(dist[nx_node] > cost + nx_cost){
                dist[nx_node] = cost + nx_cost;
                pq.push({dist[nx_node], nx_node});
            }
        }
    }

    cout << min(dist[q], dist[n + q]) << endl;
}

signed main(){
    gas
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}