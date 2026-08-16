#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, maxn = 205;

int n, k, m, r;

bool vis[maxn];

vi adj[maxn], c(maxn), a(maxn);

vi dfs(int nd, int len){
    vi v = {nd};
    if(len == 0){
        return v;
    }
    vis[nd] = 1;
    for(auto x : adj[nd]){
        vi tmp = dfs(x, len - 1);
        for(auto y : tmp){
            v.pb(y);
        }
        // v.emplace_back(dfs(x, len - 1));
    }
    return v;
}

bool comp(int a, int b){
    return c[a] < c[b];
}

void solve(){
    cin >> n >> k >> m >> r;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < k; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int q;
    cin >> q;
    while(q--){
        int vx, vy;
        cin >> vx >> vy;
        c[vx] -= vy;
        int ans = 0;
        vi udah;
        for(int i = 0; i < k; i++){
            int x = a[i];
            memset(vis, 0, sizeof vis);
            vi akan = dfs(x, r);
            sort(akan.begin(), akan.end(), comp);
            // for(auto x : akan){
            //     cout << x << " ";
            // } cout << endl;
            bool ok = 0;
            for(auto y : udah){
                if(akan[0] == y){
                    ok = 1;
                }
            }
            if(ok){
                continue;
            }
            else{
                udah.pb(akan[0]);
                ans += c[akan[0]];
            }
        }
        c[vx] += vy;
        cout << ans << endl;
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