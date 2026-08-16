//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    int idx = 0;
    int jarak = min(n, b-a);
        ans = (n-jarak)*a + jarak*(2*b - (jarak - 1))/2;
    cout << ans << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}