//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    int h[n];
    int minh = MOD, minidx = 0;
    for(int i = 0; i<n; i++){
        cin >> h[i];
        if(minh > h[i] && i!=(n-1)){
            minidx = i + 1;
            minh = min(minh, h[i]);
        }
    }
    cout << h[n-1] + minh << endl;
    if(q==1){
        cout << 1 << endl;
        cout << minidx << " " << n;
    }

}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}