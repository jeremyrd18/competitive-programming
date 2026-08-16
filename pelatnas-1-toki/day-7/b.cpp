#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, maxn = 2005;

int dist1[maxn][maxn], dist2[maxn][maxn], n;
vi adj[maxn];

map<pii, int> found;

class LCA {
public:
    LCA(int n) {
        maxLog = log2(n) + 1;
        parent.resize(n + 5, vector<int>(maxLog, -1));
        depth.resize(n + 5, 0);
        graph.resize(n + 5);
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int node, int par, int dep) {
        parent[node][0] = par;
        depth[node] = dep;
        for (int i = 1; i < maxLog; ++i) {
            if (parent[node][i - 1] != -1) {
                parent[node][i] = parent[parent[node][i - 1]][i - 1];
            }
        }
        for (int neighbor : graph[node]) {
            if (neighbor != par) {
                dfs(neighbor, node, dep + 1);
            }
        }
    }

    void preprocess(int root) {
        dfs(root, -1, 0);
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = maxLog - 1; i >= 0; --i) {
        	if(parent[u][i] == -1) continue;
            if (depth[parent[u][i]] >= depth[v]) {
                u = parent[u][i];
            }
        }
        if (u == v) return u;
        for (int i = maxLog - 1; i >= 0; --i) {
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }

private:
    vector<vector<int>> graph;
    vector<vector<int>> parent;
    vector<int> depth;
    int maxLog;
};  

vector<int> dfss(int nd, int par, int cari, vector<int> node){
//	cout << nd << endl;
    node.pb(nd);
    if(nd == cari){
        return node;
    }
    for(auto x : adj[nd]){
        if(x != par){
        	
            vi tmpp = dfss(x, nd, cari, node);
            if(tmpp[tmpp.size() - 1] != cari){
            	continue;
			}
			else{
				for(auto v : tmpp){
					node.pb(v);
				}
			}
        }
    }
    return node;
}

void solve(){
    cin >> n;
    LCA lca(n);
    for(int i = 0; i < n - 1; i++){
        int u, v, t1, t2;
        cin >> u >> v >> t1 >> t2;
        lca.addEdge(u, v);
        lca.addEdge(v, u);
        adj[u].pb(v);
        adj[v].pb(u);
        dist1[u][v] = t1;
        dist1[v][u] = t1;
        dist2[u][v] = t2;
        dist2[v][u] = t2;
    }
    lca.preprocess(1);
    int sum = 0;
    for(int i = 1; i < n; i++){
    	// cout << "case " << i << endl;
        int lowca = lca.lca(i, i + 1);
        vi dariu = dfss(lowca, -1, i, {});
        vi dariv = dfss(lowca, -1, i + 1, {});
//        cout << dariv.size() << endl;
        int sz = dariu.size();
        if(sz > 1){
for(int i = 0; i < sz - 1; i++){
            
            int uu = dariu[i], vv = dariu[i + 1];
            if(uu > vv) swap(uu, vv);
            found[{uu, vv}]++;
            sum += dist1[uu][vv];
        }
        }
        
        sz = dariv.size();
        if(sz > 1){
        for(int i = 0; i < sz - 1; i++){
            int uu = dariv[i], vv = dariv[i + 1];
            if(uu > vv) swap(uu, vv);
            found[{uu, vv}]++;
            sum += dist1[uu][vv];
        }
        }
        // cout << sum << endl;
    }
    for(auto x : found){
        int awal = x.fi.fi;
        int akhir = x.fi.se;
        int jum = x.se;
        // cout << awal << " " << akhir << " " << jum << endl;
        if(dist1[awal][akhir] * jum < dist2[awal][akhir]) continue;
        else{
            sum -= dist1[awal][akhir] * jum;
            sum += dist2[awal][akhir];
        }
    }
    cout << sum << endl;
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