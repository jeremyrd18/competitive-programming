#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int dp[1000005], prefdp[1000005];

int fastexpo(int x, int p){
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        int y = fastexpo(x, p / 2);
        return (y * y) % mod;
    }
    return (x * fastexpo(x, p - 1)) % mod;
}

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    memset(dp, 0, sizeof dp);
    memset(prefdp, 0, sizeof prefdp);
    for(int i = 1; i <= n; i++){
        if(i >= k){
            dp[i] = (prefdp[i - 1] - prefdp[i - k]) * (m - 1);
        }
        else{
            dp[i] = prefdp[i - 1] * (m - 1);
            dp[i] += m;
        }
        dp[i] %= mod;
        prefdp[i] = prefdp[i - 1] + dp[i];
        prefdp[i] %= mod;
    }
    cout << (fastexpo(m, n) - dp[n] + mod * 3 ) % mod << endl;

}