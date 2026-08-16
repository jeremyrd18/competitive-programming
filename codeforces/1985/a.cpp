//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    string a, b;
    cin >> a >> b;
    cout << b[0] << a[1] << a[2] << " " << a[0] << b[1] << b[2] << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}