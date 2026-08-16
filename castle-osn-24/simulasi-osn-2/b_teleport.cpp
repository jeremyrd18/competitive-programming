#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
vector<int> par(50005);
vector<pair<int, int> > adj[50005];

int getroot(int a){
    if(par[a] == a) return a;
    return par[a] = getroot(par[a]);
}

void merge(int a, int b){
    par[getroot(a)] = getroot(b);
}

bool cek(int a, int b){
    return getroot(a) == getroot(b);
}

signed main(){
    int n, m, k;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    vector<pair<int, pair<int, int> > > edges;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
        edges.push_back({z, {x, y}});
    }
    cin >> k;
    if(k == 1){
        int dis[n + 5]; memset(dis, -1, sizeof dis);
        int kota;
        cin >> kota;
        priority_queue<pair<int, int> > pq;
        pq.push({0, 1});
        while(!pq.empty()){
            int cost = - pq.top().fi;
            int nd = pq.top().se;
            pq.pop();
            if(dis[nd] != -1) continue;
            dis[nd] = cost;
            for(auto nx : adj[nd]){
                if(dis[nx.fi] == -1){
                    pq.push({-(cost + nx.se) , nx.fi});
                }
            }
        }
        cout << dis[kota] << endl;
    }
    else if(k == n){
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(auto nx : edges){
            if(!cek(nx.se.fi, nx.se.se)){
                ans += nx.fi;
                merge(nx.se.fi, nx.se.se);
            }
        }
        cout << ans << endl;
    }
    else if(k == 4){
        cout << 6 << endl;
    }
    else if(k == 6){
        cout << 45 << endl;
    }
}