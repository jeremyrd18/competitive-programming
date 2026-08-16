#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

signed main(){
    int n, m;
    cin >> n >> m;
    if(n == 1){
        int ans = 2;
        for(int i = 2; i <= m; i++){
            ans *= 3;
            ans %= mod;
        }
        cout << ans << endl;
    }
    else{
        int a[m + 1], b[m + 1], c[m + 1], d[m + 1], penuh[m + 1];
        a[1] = 1;
        b[1] = 2;
        c[1] = 1;
        d[1] = 1;
        penuh[1] = a[1] + b[1] + 2 * c[1] + d[1];
        for(int i = 2; i <= m; i++){
            a[i] = ((3 * d[i - 1]) + b[i - 1] + c[i - 1] + penuh[i - 1]) % mod;
            b[i] = ((3 * c[i - 1]) + a[i - 1] + d[i - 1] + (2 * penuh[i - 1])) % mod;
            c[i] = ((3 * b[i - 1]) + a[i - 1] + d[i - 1] + penuh[i - 1]) % mod;
            d[i] = ((3 * a[i - 1]) + b[i - 1] + c[i - 1] + penuh[i - 1]) % mod;
            penuh[i] = (a[i] + b[i] + (2 * c[i]) + d[i]) % mod;
        }
        cout << penuh[m];
    }
}