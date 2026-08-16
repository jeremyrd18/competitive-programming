#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, maxn = 400005;


int n, m; 
vi adj[maxn]; 

vector<bool> visited;
vector<int> tin, low;
int timer;
map<pii, bool> bridges;

void IS_BRIDGE(int v,int to){
    bridges[{v, to}] = 1;
    bridges[{to, v}] = 1;
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

// MST to find the biggest cycle

int par[maxn], sz[maxn];

int getroot(int a){
    if(par[a] == a) return a;
    return par[a] = getroot(par[a]);
}

void merge(int a, int b){
    int aa = getroot(a);
    int bb = getroot(b);
    par[aa] = bb;
    sz[bb] += sz[aa];
}

vector<pii> anss;

map<pii, bool> udah;

void dfss(int nd, int par){
    udah[{nd, par}] = 1;
    udah[{par, nd}] = 1;
    for(auto x : adj[nd]){
        if(x == par) continue;
        if(udah[{x, nd}]) continue;
        anss.pb({x, nd});
        dfss(x, nd);
    }
}

void solve(){
    cin >> n >> m;
    vector<pii> edges;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
        edges.pb({x, y});
    }
    find_bridges();
    for(int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
    for(int i = 0; i < m; i++){
        if(bridges[{edges[i].fi, edges[i].se}] == 1) continue;
        // cout << le << " " << ri << endl;
        if(getroot(edges[i].fi) == getroot(edges[i].se)) continue;
        merge(edges[i].fi, edges[i].se);
    }
    int start = 0, tmp = 0;
    for(int i = 0; i < n; i++){
        // cout << sz[i] << endl;
        int tempe = getroot(i);
        if(sz[tempe] > tmp){
            start = tempe;
            tmp = sz[tempe];
        }
    }
    dfss(start, -1);
    cout << tmp << endl;
    for(auto x : anss){
        cout << x.fi + 1 << " " << x.se + 1 << endl;
    }
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