#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, maxn = 300005;

map<pii, int> pos;
int timer = 1;

bool vis[maxn];

map<int, int> timur;

vi adj[maxn];

int ans = 0;

void dfs(int nd){
    vis[nd] = 1;
    if(timur[nd] == 1){
        ans++;
    }
    for(auto x : adj[nd]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    priority_queue<pii> posa;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pos[{x, y}] = timer;
        
        if(x == 0){
            posa.push({y, timer});
        }
        if(x == a){
            timur[timer] = 1;
        }

        timer++;
    }
    for(int i = 0; i < m; i++){
        int x, y, k;
        cin >> x >> y >> k;
        adj[x].pb(y);
        if(k == 2) adj[y].pb(x);
    }
    while(!posa.empty()){
        pii cur = posa.top();
        posa.pop();
        memset(vis, 0, sizeof vis);
        ans = 0;
        dfs(cur.se);
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