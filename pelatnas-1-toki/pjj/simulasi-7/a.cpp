#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

int par[200005], sz[200005];

int getroot(int a){
    if(par[a] == a) return a;
    return par[a] = getroot(par[a]);
}

void merge(int a, int b){
    int aa = getroot(a);
    int bb = getroot(b);
    par[aa] = bb;
    sz[bb] += sz[aa];
}

signed main(){
    int n, k, q;
    cin >> n >> k >> q;
    pair<int,int> a[n + 1];
    int mxh = -1;
    for(int i = 0; i <= 200004; i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = i;
        mxh = max(mxh, a[i].fi);
    }
    sort(a + 1, a + n + 1);
    // for(int i = 1; i <= n; i++) cout << a[i].se << " ";
    // cout << endl;
    int v[n + 5], h[mxh + 5];
    for(int i = 0; i <= n + 4; i++) v[i] = 0;
    for(int i = 0; i <= mxh + 1; i++) h[i] = -1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cur = a[i].fi + 1;
        v[a[i].se] = 1;
        int len = 0;
        if(v[a[i].se - 1] == 1){
            int sz1 = sz[getroot(a[i].se - 1)];
            merge(a[i].se, a[i].se - 1);
            // if(i == 4){
            //     cout << sz[a[i].se - 1] << endl;
            // }
            if(v[a[i].se + 1] == 1){
                int sz2 = sz[getroot(a[i].se + 1)];
                merge(a[i].se, a[i].se + 1);
                ans -= sz1 * (sz1 + 1) / 2;
                ans -= sz2 * (sz2 + 1) / 2;
                // cout << i << " " << sz1 << " " << sz2 << endl;
                ans += (sz1 + sz2 + 1) * (sz1 + sz2 + 2) / 2;
            }else{
                // cout << i << " " << sz1 << endl;
                ans -= sz1 * (sz1 + 1) / 2;
                sz1++;
                ans += sz1 * (sz1 + 1) / 2;
            }
        }
        else if(v[a[i].se + 1] == 1){
            int sz2 = sz[getroot(a[i].se + 1)];
            // cout << i << " " << sz2 << endl;
            merge(a[i].se, a[i].se + 1);
            ans -= sz2 * (sz2 + 1) / 2;
            sz2++;
            ans += (sz2 + 1) * (sz2) / 2;
        }
        else ans++;
        h[cur] = max(h[cur], ans);
    }
    h[0] = 0;
    for(int i = 1; i <= mxh + 1; i++){
        if(h[i] == -1){
            h[i] = h[i - 1];
        }
        // cout << h[i] << " ";
    }
    // cout << endl;
    int day = -1;
    while(q--){
        day++;
        int t, x;
        cin >> t >> x;
        if(t == 1){
            x -= (day * k);
            if(x <= 0) cout << 0 << endl;
            else if(x > mxh) cout << n*(n + 1) / 2 << endl;
            else cout << h[x] << endl;
        }
        else{
            int ans = 0;
            int l = 0, r = mxh + 1;
            while(l <= r){
                int mid = (l + r) / 2;
                if(h[mid] >= x){
                    r = mid - 1;
                    ans = mid;
                }
                else l = mid + 1;
            }
            if(ans == 0) cout << -1 << endl;
            else cout << ans + (day * k) << endl;
        }
    }
}