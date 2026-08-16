#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

vector<pair<int, int> > adj[100005];
vector<int> comp[100005];

int par[100005];

int find(int a){
    if(a == par[a]){
        return a;
    }
    return par[a] = find(par[a]);
}

void merge(int a, int b){
    par[find(a)] = find(b);
}

bool cek(int a, int b){
    return find(a) == find(b);
}

signed main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    int k;
    cin >> k;
    vector<int> spec(k + 1);
    priority_queue<pair<int, int> > pq;
    pair<int, int> dis[n + 3];
    int dist[n + 3];
    for(int i = 0; i <= n; i++){
        dis[i] = {1e15, -1};
        dist[i] = 1e15;
    }
    for(int i = 0; i < k; i++){
        cin >> spec[i];
        pq.push({0, spec[i]});
        dis[spec[i]] = {0, spec[i]};
    }
    while(!pq.empty()){
        int cur = - pq.top().fi;
        int nd = pq.top().se;
        pq.pop();
        if(cur > dis[nd].fi) continue;
        for(auto i : adj[nd]){
            if(dis[i.fi].fi > cur + i.se){
                // cout << dis[nd].se << endl;
                dis[i.fi].fi = cur + i.se;
                dis[i.fi].se = dis[nd].se;
                pq.push({ - dis[i.fi].fi, i.fi});
            }
        }
    }
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int cur = - pq.top().fi;
        int nd = pq.top().se;
        pq.pop();
        if(cur > dist[nd]) continue;
        for(auto i : adj[nd]){
            if(dist[i.fi] > cur + i.se){
                // cout << "aaym" << endl;
                dist[i.fi] = cur + i.se;
                pq.push({ -dist[i.fi], i.fi});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        par[i] = i;
        int curcomp = dis[i].se;
        // cout << curcomp << endl;
        comp[curcomp].push_back(i);
    }
    vector<pair<int, pair<int, int> > > edges;
    int ans = 0;
    if(dis[1].se != 1){
        int tmp = 1e15;
        for(int i = 2; i <= n; i++){
            // cout << dist[i] << endl;

            tmp = min(tmp, dist[i]);
        }
        // cout << dist[1] << endl;
        // cout << endl;
        ans += tmp;
    }
    for(int i = 0; i < k; i++){
        int curcomp = spec[i];
        for(auto x : comp[curcomp]){
            for(int j = 0; j < adj[x].size(); j++){
                auto y = adj[x][j];
                int nxcomp = dis[y.fi].se;
                if(nxcomp == -1 || curcomp == -1) continue;
                if(nxcomp != curcomp){
                    edges.push_back({dis[x].fi + dis[y.fi].fi + adj[x][j].se, {curcomp, nxcomp}});
                }
            }
        }
    }
    // for(int i = 1; i <= n; i++) cout << dis[i].fi << " ";
    // cout << endl;
    // for(auto x : spec){
    //     for(auto y : comp[x]){
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    sort(edges.begin(), edges.end());
    for(auto x : edges){
        if(x.se.fi == -1 || x.se.se == -1) continue;
        if(!cek(x.se.fi, x.se.se)){
            // cout << x.se.fi << " " << x.se.se << " " << x.fi << endl;
            ans += x.fi;
            merge(x.se.fi, x.se.se);
        }
    }
    cout << ans << endl;
}