#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

const int N = 200005;

int n, m, s;
vector<pair<int, int> > adj[N];
vector<int> st(4 * N);

void build(int nd, int l, int r){
    if(l == r){
        if(l == 0) st[nd] = 0;
        else st[nd] = 1e15;
        return;
    }
    int mid = (l + r) / 2;
    build(nd * 2, l, mid);
    build(nd * 2 + 1, mid + 1, r);
}

int query(int nd, int l, int r, int ql, int qr){
    if(l > qr || r < ql){
        return 1e15;
    }
    if(l >= ql && r <= qr){
        return st[nd];
    }
    int mid = (l + r) / 2;
    return min(query(nd * 2, l, mid, ql, qr), query(nd * 2 + 1, mid + 1, r, ql, qr));
}

void update(int nd, int l, int r, int idx, int val){
    if(l > idx || r < idx){
        return;
    }
    if(l == idx && r == idx){
        st[nd] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(nd * 2, l, mid, idx, val);
    update(nd * 2 + 1, mid + 1, r, idx, val);
    st[nd] = min(st[nd * 2], st[nd * 2 + 1]);
}

signed main(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
    }
    int dp[n + 3];
    dp[0] = 0;
    build(1, 0, n);
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + s;
        for(auto x : adj[i]){
            dp[i] = min(dp[i], query(1, 0, n, x.fi - 1, i - 1) + x.se);
        }
        update(1, 0, n, i, dp[i]);
    }
    cout << dp[n] << endl;
}