//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
int N, m;
int a[505];

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

    bool unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return false;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
};

int pow_mod(int x, int p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        int y = pow_mod(x, p / 2);
        return (y * y) % m;
    }
    return (x*pow_mod(x, p - 1)) % m;
}

void solve(){
    cin >> N >> m;
    DisjointSet ds(N);
    for(int i = 0; i<N; i++){
        cin >> a[i];
    }
    vector<vector<int> > v;
    int vsize = 0;
    for(int i = 0; i<N; i++){
        for(int j = i ; j<N; j++){
            if(i == j) continue;
            int cnt = pow_mod(a[j], a[i]) + pow_mod(a[i], a[j]);
            cnt %= m;
            vsize++;
            v.push_back({cnt, i, j});            
        }
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i = 0; i < vsize; i++){
        // cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
        if(ds.unionBySize(v[i][1], v[i][2])){
            ans += v[i][0];
        }
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