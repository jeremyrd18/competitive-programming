#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0, temp = v[n - 1];
    int r = n - 1;
    for(int l = 0; l < n; l++){
        // cout << temp << endl;
        if(l == r){
            if(temp > d) ans++;
            cout << ans << endl;
            return;
        }
        if(temp > d){
            ans++;
            r--;
            temp = v[r];
            l--;
        }
        else{
            temp += v[r];
        }
    }
}

signed main(){
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}