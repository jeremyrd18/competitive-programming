#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a0, a1, b0, b1;
const int MOD = 1000000007;
int ans = 0;

void hitung(int idx, int c, int jum, int a, int b){
    if(idx > a0 + a1){
        return;
    }
    if(a < 0 || b < 0) return;
    if(idx <= a0 + a1){
        if(jum >= 2){
            // cout << c << " " << a << " " << b << " " << idx << endl;
            ans++;
            ans %= MOD;
        }
    }
    if(c == 0){
        hitung(idx + 1, c, jum, a - 1, b);
        hitung(idx + b1, 1, jum + 1, a, b - b1);
    }
    else{
        hitung(idx + 1, c, jum, a, b - 1);
        hitung(idx + b0, 0, jum + 1, a - b0, b);
    }
}

signed main(){
    cin >> a0 >> a1 >> b0 >> b1;
    hitung(b1, 1, 1, a0, a1 - b1);
    hitung(b0, 0, 1, a0 - b0, a1);
    cout << ans % MOD << endl;
}