//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int t, n, k;
string s;
int a[N], ans[N], inx[N];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) ans[i] = 1;
    ans[1] = inx[1] = 1;
    for(int i=2;i<=n;i++){
        int l = max(i - a[i], 1LL);
        int r = a[i] - (i - l);
        if(ans[l] + r <= n) ans[i] = ans[l] + r;
        else if(ans[l] - r >= 1) ans[i] = ans[l] - r;
        inx[i] = l;
    }
    cout << "YES" << endl;
    for(int i=1;i<=n;i++) cout << i << ' ' << ans[i] << endl;
    for(int i=1;i<=n;i++) cout << inx[i] << ' '; cout << endl;
}

signed main(){
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}