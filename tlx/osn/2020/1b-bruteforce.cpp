//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i<q; i++){
        int x;
        cin >> x;
        if(x % n == 0){
            cout << n << endl;
            continue;
        }
        cout << x % n << endl;
    }
    
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}