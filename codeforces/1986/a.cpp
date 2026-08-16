//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int a[3];
    for(int i = 0; i<3; i++){
        cin >> a[i];
    }
    sort(a, a+3);
    cout<< a[2] - a[0] << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}