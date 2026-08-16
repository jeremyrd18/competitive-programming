//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int ax[n], ay[n];
    for(int i = 0; i<n; i++){
        cin >> ax[i] >> ay[i];
    }
    sort(ax, ax+n);
    sort(ay, ay+n);
    cout << ax[n/2] << " " << ay[n/2] << endl;    
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}