#include <bits/stdc++.h>
using namespace std;
#define int long long

 
typedef pair<int, int> PII;
typedef long long LL;
 
const int N = 2e5 + 10;
 
int n, q;
std::vector<int> g[N];
int col[N], fa[N], cnt[N];
 
void dfs(int u) {
    for (auto v : g[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs(v);
    }
}
 
void solve() {
    cin >> n >> q;
    cnt[0] = 0;
    for (int i = 1; i <= n; i ++)
        cin >> col[i], g[i].clear(), cnt[i] = 0, fa[i] = 0;
    int u, v;
    for (int i = 1; i < n; i ++)
        cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    dfs(1);
 
    int thr = 0, wht = 0;
    set<int> two;
    for (int i = 1; i <= n; i ++)
        if (col[i]) {
            if (!col[fa[i]]) wht ++;
            cnt[fa[i]] ++;
            if (cnt[fa[i]] == 2) two.insert(fa[i]);
            else if (cnt[fa[i]] == 3) thr ++;
        }
 
    while (q -- ) {
        int u;
        cin >> u;
 
        col[u] ^= 1;
        if (col[u]) {
            if (!col[fa[u]]) wht ++;
            wht -= cnt[u], cnt[fa[u]] ++;
            if (cnt[fa[u]] == 2) two.insert(fa[u]);
            else if (cnt[fa[u]] == 3) thr ++;
        } else {
            if (!col[fa[u]]) wht --;
            wht += cnt[u], cnt[fa[u]] --;
            if (cnt[fa[u]] == 2) thr --;
            else if (cnt[fa[u]] == 1) two.erase(fa[u]);
        }
        if (wht == 1 && (two.size() == 0 || two.size() == 1 && !col[fa[*two.begin()]]) && !thr) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
 
signed main() {
 
    int t;
    cin >> t;
 
    while (t --)
        solve();
 
    return 0;
}