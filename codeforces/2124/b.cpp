//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    int prefm = 0, ma = 0, s = 0;
    for(int i = 1; i<=n; i++){
        prefm = max(prefm, a[i]);
        int d = prefm - a[i];
        s += d;
        ma = max(ma, d);
    }
    cout << s + ma << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}