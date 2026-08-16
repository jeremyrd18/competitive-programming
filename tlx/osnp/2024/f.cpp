#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    cout << m*(m-1)/2 + n*(m + n - 1) << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}