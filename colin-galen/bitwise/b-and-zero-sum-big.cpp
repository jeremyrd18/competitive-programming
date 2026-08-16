//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for(int i = 0; i<k; i++){
        ans *= n;
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}