#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int mod = 1000000007, maxn = 1000005;

int dp[maxn];
 
int fastexpo(int a, int b) {
    if(b == 1) {
        return a;
    }
 
    int tmp = fastexpo(a, b/2);
 
    if(b & 1) {
        return ((tmp * tmp)%mod * a)%mod;
    } else {
        return (tmp * tmp)%mod;
    }
}
 
int kombinasi(int a, int b) {
    int ans = ((dp[a]%mod*fastexpo(dp[b],mod-2))%mod*fastexpo(dp[a-b], mod-2))%mod;
    return ans;
}

bool good = true;
 
void isGood(int x, int a, int b) {
    if(x < 10) {
        if(x != a && x != b) {
            good = false;
        }
        return;
    } else {
        if(x%10 != a && x%10 != b) {
            good = false;
        }
 
        isGood(x/10, a, b);
    }
}
 
void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
 
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = i * dp[i-1];
        dp[i] %= mod;
    }
 
    for(int i = 0; i <= n; i++) {
        int xa = n-i;
        int xb = i;
 
        int digs = xa * a + xb * b;
 
        isGood(digs, a, b);
 
        if(good) {
            int kombin = kombinasi(n,xa);
            ans += kombin;
            ans %= mod;
        }
        good = true;
    }
 
    cout << ans;
}

signed main() {
    gas
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
