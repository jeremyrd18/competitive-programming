//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = n; i >= k; i--){
        cout << i << " ";
    }
    for(int i = k - 1; i > m; i--){
        cout << i << " ";
    }
    for(int i = 1; i <= m; i++){
        cout << i << " ";
    }
    cout << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}