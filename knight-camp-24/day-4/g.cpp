#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
class SGTree {
public: 
    vector<int> seg;
    SGTree(int n) {
        seg.resize(4 * n + 1);
        for(int i = 0; i<= 4*n; i++){
            seg[i] = LLONG_MAX;
        }
    }
    int query(int ind, int low, int high, int l, int r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return LLONG_MAX;
 
        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return seg[ind];
 
        int mid = (low + high) >> 1;
        int left = query(2 * ind , low, mid, l, r);
        int right = query(2 * ind + 1, mid + 1, high, l, r);
        return min(left ,right);
    }
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        
        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind , low, mid, i, val);
        else update(2 * ind + 1, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind ] , seg[2 * ind + 1]);
    }
};

void solve(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<pair<int,int> > v[n + 3];
    for(int i = 1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[b].push_back({a, c});
    }
    int dp[n + 3];
    SGTree sg(n + 3);
    memset(dp, INT_MAX, sizeof dp);
    dp[0] = 0;
    sg.update(1, 0, n, 0, 0);
    for(int i = 1; i<=n; i++){
        dp[i] = dp[i - 1] + s;
        for(auto a : v[i]){
            dp[i] = min(dp[i], sg.query(1, 0, n, a.first - 1, i - 1) + a.second);
        }
        sg.update(1, 0, n, i, dp[i]);
    }
    // for(int i = 1; i<=n; i++){
    //     cout << dp[i] << endl;
    // }
    // sg.update(1, 0, n, n, dp[n]);
    cout << dp[n] << endl;
}

signed main(){
  int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}