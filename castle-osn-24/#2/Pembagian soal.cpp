//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1000000007;

int pow_mod(int x, int p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        int y = pow_mod(x, p / 2);
        return (y * y) % mod;
    }
    return (x * pow_mod(x, p - 1)) % mod;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(100003, 0);
    int maxi = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        maxi = max(a, maxi);
        v[a]++;
    }
    // sort(v.rbegin(), v.rend());
    // if(m != 1){
    //     cout << pow_mod(2, v[0]) << endl;
    // }
    // else{
    //     int ans = 0;
    //     for(int i = 0; i < n; i++){
    //         ans += pow_mod(2, v[i]);
    //         ans %= mod;
    //     }
    //     cout << ans << endl;    
    // }
    for(int i = 0; i < maxi; i++){
        int x = v[i];
        v[i + 1] += (x / 2);
        if(x % 2 == 1){
            v[i] = 1;
        }
        else{
            v[i] = 0;
        }
    }
    // cout << endl;
    // int ans = v[maxi] / m;
    // ans += (v[maxi] % m == 0);
    // ans *= pow_mod(2, maxi);
    // if(v[maxi] % m != 0){
    //     cout << ans << endl;
    // }
    int res = 0;
    for(int i = maxi; i >= 0; i--){
        int ans = v[i] / m;
        if(v[i] % m == 0){
            // ans++;
            ans *= pow_mod(2, i);
            res += ans;
            res += mod;
            res %= mod;
        }
        else{
            ans++;
            ans *= pow_mod(2, i);
            res += ans;
            res += mod;
            res %= mod;
            cout << res << endl;
            return;
        }
    }
    // cout << "yes" << endl;
    res = (res + mod) % mod;
    cout << res << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}