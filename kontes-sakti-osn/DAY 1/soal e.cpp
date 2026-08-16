//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1; i * i <= n; i++){
        for(int j=1; j * j <= m; j++){
            if(__gcd(i,j)==1){
                ans += min(n/i, m/j) / (i + j);
            }
        }
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