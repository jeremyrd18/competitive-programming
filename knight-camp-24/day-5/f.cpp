//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
int n, s, q;
class DisjointSet {
public:
    vector<int>  parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve(){
    cin >> n >> s >> q;
    vector<tuple<int, int, int> > v;
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        for(int j = 1; j<=x; j++){
            int a, b;
            cin >> a >> b;
            v.push_back({a, b, i});
        }
    }
    sort(v.begin(), v.end());
    DisjointSet ds(n + 3);;
    pair<int, int> cur = {get<1>(v[0]), get<2>(v[0])};
    for(int i = 1; i<(int)v.size(); i++){
        int l = get<0>(v[i]), r = get<1>(v[i]), idx = get<2>(v[i]);
        if(cur.first >= l){
            ds.unionBySize(cur.second, idx);
        }
        if(cur.first < r){
            cur = {r, idx};
        }
    }
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        cout << ds.size[ds.findUPar(x)] << endl;
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}