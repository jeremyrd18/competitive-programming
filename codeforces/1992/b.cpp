//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(int i = 0 ; i < k; i++){
        cin >> a[i];
        if(a[i] == n){
            cout << 0 << endl;
            return;
        }
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int len = 0;
    for(int i = 0; i < k - 1; i++){
        ans += (a[i] - 1 + a[i]);
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