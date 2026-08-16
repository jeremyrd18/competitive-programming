#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
vector<pair<int, int> > adj;
vector<int> val, prefnew, prefisland, st(4 * 1e5);
int m;

void build(int nd, int l, int r){
    if(l == r){
        st[nd] = prefnew[l];
        return;
    }
    int mid = (l + r) / 2;
    build(nd * 2, l, mid);
    build(nd * 2 + 1, mid + 1, r);
    st[nd] = min(st[nd * 2], st[nd * 2 + 1]);
}

int query(int nd, int l, int r, int ql, int qr){
    if(l > qr || r < ql){
        return 1e18;
    }
    if(l >= ql && r <= qr){
        return st[nd];
    }
    int mid = (l + r) / 2;
    return min(query(2 * nd, l, mid, ql, qr), query(2 * nd + 1, mid + 1, r, ql, qr));
}

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pref(n + 1);
    pref[0] = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    int q;
    cin >> q;
    if(q != 0){
        vector<pair<int, int> > vq(q);
        for(int i = 0; i < q; i++){
            cin >> vq[i].fi >> vq[i].se;
        }
        sort(vq.begin(), vq.end());
        for(int j = 1; j < vq[0].fi; j++){
            adj.push_back({j, j});
        }
        adj.push_back({vq[0]});
        int hi = vq[0].se;
        for(int i = 1; i < q; i++){
            if(vq[i].fi > hi){
                for(int j = hi + 1; j < vq[i].fi; j++){
                    adj.push_back({j, j});
                }
                hi = vq[i].se;
                adj.push_back({vq[i].fi, hi});
            }
            else{
                hi = max(hi, vq[i].se);
                adj[adj.size() - 1] = {adj[adj.size() - 1].fi, hi};
            }
        }
        for(int j = hi + 1; j <= n; j++){
            adj.push_back({j, j});
        }
        m = adj.size();
        // cout << m << endl;
        // for(auto x : adj){
        //     cout << x.fi << " " << x.se << endl;
        // }
        // cout << 1;
        prefisland.push_back(0);
        for(int i = 0; i < m; i++){
            int a1 = adj[i].fi, a2 = adj[i].se;
            val.push_back(pref[a2] - pref[a1 - 1]);
            prefisland.push_back(prefisland[i] + (a2 - a1 + 1));
        }
        prefnew.push_back(0);
        for(int i = 0; i < m; i++){
            prefnew.push_back(prefnew[i] + val[i]);
        }
        // for(auto x : prefisland){
        //     cout << x << endl;
        // } cout << endl;
        build(1, 0, m);
        int ans = 0;
        for(int i = 1; i <= m; i++){
            int l = 1, r = i, mid, res = -1;
            while(l <= r){
                mid = (l + r) / 2;
                if(prefisland[i] - prefisland[mid - 1] > k){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                    res = mid;
                }
            }
            // cout << res << endl;
            if(res == -1) continue;
            
            // from mid to i, maxquery the prefnew[i] - prefnew[j - 1]
            // mid <= j <= i
            // so, find the minimum of prefnew[j - 1]
            // cout << i << " " << prefnew[i] << " - " << query(1, 0, m , res - 1, i - 1) << endl;
            ans = max(ans, prefnew[i] - query(1, 0, m , res - 1, i - 1));
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
    else{
        q = n;
        vector<pair<int, int> > vq(q);
        for(int i = 0; i < q; i++){
            vq[i] = {i + 1, i + 1};
        }
        sort(vq.begin(), vq.end());
        adj.push_back({vq[0]});
        int hi = vq[0].se;
        for(int i = 1; i < q; i++){
            if(vq[i].fi > hi){
                for(int j = hi + 1; j < vq[i].fi; j++){
                    adj.push_back({j, j});
                }
                hi = vq[i].se;
                adj.push_back({vq[i].fi, hi});
            }
            else{
                hi = max(hi, vq[i].se);
                adj[adj.size() - 1] = {adj[adj.size() - 1].fi, hi};
            }
        }
        for(int j = hi + 1; j <= n; j++){
            adj.push_back({j, j});
        }
        m = adj.size();
        // cout << m << endl;
        // for(auto x : adj){
        //     cout << x.fi << " " << x.se << endl;
        // }
        // cout << 1;
        prefisland.push_back(0);
        for(int i = 0; i < m; i++){
            int a1 = adj[i].fi, a2 = adj[i].se;
            val.push_back(pref[a2] - pref[a1 - 1]);
            prefisland.push_back(prefisland[i] + (a2 - a1 + 1));
        }
        prefnew.push_back(0);
        for(int i = 0; i < m; i++){
            prefnew.push_back(prefnew[i] + val[i]);
        }
        // for(auto x : prefisland){
        //     cout << x << endl;
        // } cout << endl;
        build(1, 0, m);
        int ans = 0;
        for(int i = 1; i <= m; i++){
            int l = 1, r = i, mid, res = -1;
            while(l <= r){
                mid = (l + r) / 2;
                if(prefisland[i] - prefisland[mid - 1] > k){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                    res = mid;
                }
            }
            // cout << res << endl;
            if(res == -1) continue;
            
            // from mid to i, maxquery the prefnew[i] - prefnew[j - 1]
            // mid <= j <= i
            // so, find the minimum of prefnew[j - 1]
            // cout << i << " " << prefnew[i] << " - " << query(1, 0, m , res - 1, i - 1) << endl;
            ans = max(ans, prefnew[i] - query(1, 0, m , res - 1, i - 1));
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
}