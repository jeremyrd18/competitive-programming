#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, pair<int, int> > > > adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w, z;
        cin >> u >> v >> w >> z;
        adj[u].push_back({v, {w, z}});
        adj[v].push_back({u, {w, z}});
    }

    // First dijkstra to find distance from node 1 to N using any Z
    // dist[i] = jarak dari 1 ke node i
    vector<int> dist(n + 1, 1e18);
    // PQ nyimpen jarak dari 1 ke i (first) dan node i (second)
    priority_queue<pair<int, int> > pq; 
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int d = - pq.top().first; // jarak dari 1 ke node u (sejauh ini)
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(pair<int, pair<int, int> > x: adj[u]){
            int nd_next = x.first;
            int edge_we = x.second.first;
            if(dist[u] + edge_we < dist[nd_next]){
                dist[nd_next] = dist[u] + edge_we;
                pq.push({-dist[nd_next], nd_next});
            }
        }
    }

    // Second dijkstra to find distance from N to any node using Z = 1
    vector<int> dist1(n + 1, 1e18);
    dist1[n] = 0;
    pq.push({0, n});
    while(!pq.empty()){
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist1[u]) continue;

        for(pair<int, pair<int, int> > x: adj[u]){
            int nd_next = x.first;
            int edge_we = x.second.first;
            int edge_type = x.second.second;
            if(edge_type == 2){
                if(dist1[u] + edge_we < dist1[nd_next]){
                    dist1[nd_next] = dist1[u] + edge_we;
                    pq.push({-dist1[nd_next], nd_next});
                }
            }
        }
    }

    vector<pair<int, int> > candidates;
    for(int i = 1; i <= n; i++){
        if(dist[i] != 1e18 && dist1[i] != 1e18){
            candidates.push_back({dist[i], dist[i] + dist1[i]});
        }
    }

    if(candidates.empty()){
        int q;
        cin >> q;
        while(q--){
            int t;
            cin >> t;
            cout << -1 << endl;
        }
        return 0;
    }

    // greedy
    sort(candidates.begin(), candidates.end());

    int N = candidates.size();
    vector<int> prefmin(N); // prefMin[i] to keep smallest time from index 0 to i
    prefmin[0] = candidates[0].second;
    for(int i = 1; i < N; i++){
        prefmin[i] = min(prefmin[i - 1], candidates[i].second);
    }

    int Q;
    cin >> Q;
    while(Q--){
        int t;
        cin >> t;
        int l = 0, r = N - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(candidates[mid].first <= t){
                ans = prefmin[mid];
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}

/*
DIJKSTRA:
- Priority Queue
- Weighted
*/