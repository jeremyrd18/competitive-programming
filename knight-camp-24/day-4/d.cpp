#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> g[200007];
int todo(200007), good(200007);

void dfs(int v, int p) {
    for (int u : g[v]) {
        if (u != p) {
            dfs(u, v);
            if (todo[u]) {
                todo[v] = true;
            }
            if (good[u]) {
                good[v] = true;
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i<= n + 2; i++){
        g[i].erase();
    }
    todo.clear();
    good.clear();
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    memset(todo, false, sizeof todo);
    memset(good, false, sizeof good);
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        --v;
        todo[v] = true;
    }
    good[y] = true;
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(x, -1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == x) {
            continue;
        }
        if (good[i]) {
            ++ans;
        } else if (todo[i]) {
            ans += 2;
        }
    }
    cout << ans << '\n';
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}