#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, maxn = 100005;

vi adj[maxn];
bool vis[maxn];

int ans = -1;

void dfs(int nd, int par){
    // cout << nd << " " << par << endl;
    int ada = 0;
    vis[nd] = 1;
    for(auto x: adj[nd]){
        if(!vis[x]){
            dfs(x, nd);
        }
        if(x == par) ada = 1;
    }
    if(par != -1){
        if(ada == 0){
            ans = nd;
            return;
        }
    }
}

void solve(){
    int p;
    cin >> p;
    int n;
    cin >> n;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            adj[i].pb(x);
        }
    }
    vi anss;
    ans = 1;
    dfs(1, -1);
    // cout << ans << endl;
    anss.pb(ans);
    ans = 2;
    dfs(2, -1);
    // cout << ans << endl;
    anss.pb(ans);
    ans = 3;
    dfs(3, -1);
    // cout << ans << endl;
    anss.pb(ans);
    sort(anss.begin(), anss.end());
    cout << anss[1] << endl;
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