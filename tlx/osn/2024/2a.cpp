#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>

int n, m;
vector<pii> ve;

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        ve.push_back({l, r});
    }
    sort(ve.begin(), ve.end());
    vector<pii> edges;
    int ujung;
    for(int i = 0; i < n; i++){
        int l = ve[i].fi, r = ve[i].se;
        if(i == 0){
            edges.push_back({l, r});
            ujung = r;
        }
        else{
            if(r <= ujung){
                continue;
            }
            else{
                ujung = r;
                edges.push_back({l, r});
            }
        }
    }
    int n = edges.size();
    int maxv = -1, minv = 1e16;
    int cr = 0;
    cin >> m;
    // for(int i = 0; i < n; i++){
    //     cout << edges[i].fi << " " << edges[i].se << endl;
    // }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        maxv = max(maxv, x);
        minv = min(minv, x);
        // cout << i << " " << cr << " " << minv << " " << maxv << endl;
        // cout << maxv << " " << minv << endl;
        int l = 0, r = n - 1;
        int ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            // cout << mid << " " << edges[mid].fi << endl;
            if(edges[mid].fi <= minv){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        // cout << ans << endl;
        if(ans == -1){
            cout << -1 << endl;
            return 0;
        }
        l = 0, r = n - 1;
        int tans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(edges[mid].fi <= x){
                tans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(tans == -1){
            cout << -1 << endl;
            return 0;
        }
        if(edges[tans].se < x){
            cout << -1 << endl;
            return 0;
        }
        l = edges[ans].fi, r = edges[ans].se;
        if(maxv > r){
            cr++;
            minv = x; maxv = x;
        }
        else continue;
    }
    cout << cr << endl;
    // cout << minv << " " << maxv << endl;
}