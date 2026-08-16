#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200006;
int n, k, vis[N], dis[N], a[N];
bool yes = 1;

void dfs(int x, int d){
    if(yes == 0) return;
    if(a[x] == 0) return;
    if(vis[x]){
        if(d - dis[x] != k){
            yes = 0;
        }
        return;
    }
    vis[x] = 1;
    dis[x] = d;
    dfs(a[x], d + 1);
    a[x] = 0;
    vis[x] = 0;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        vis[i] = 0;
        dis[i] = 0;
        cin >> a[i];
    }
    yes = 1;
    if(k == 1){
        for(int i = 1; i <= n; i++){
            if(a[i] != i){
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == i){
            cout << "NO" << endl;
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i, 0);
    }
    if(yes == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}