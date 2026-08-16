#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);


const long long mod = 998244353;

long long fpb(int x, int y){
  if(y == 0) return x;
  return fpb(y, x % y);
}

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

vector<int> menari(int n, int q, vi a, vi l, vi r) {
    long long ans[n + 5][n + 5];
    memset(ans, 0, sizeof ans);
    for(int i = 0; i < n; i++){
      long long tmp = 1;
      for(int j = i; j >= 0; j--){
        long long tempp = tmp;
        tmp *= a[j];
        tmp *= pow_mod(fpb(a[j], tempp), mod - 2);
        tmp %= mod;
        ans[j][i] = tmp;
      }
    }
    long long dp[n + 5][n + 5];
    memset(dp, 0, sizeof dp);
    for(int sz = 1; sz <= n; sz++){
      for(int i = 0; i + sz - 1 < n; i++){
        int j = i + sz - 1;
        if(i == j){
          dp[i][j] = ans[i][j];
        }
        else if(i + 1 == j){
          dp[i][j] = ans[i][i] + ans[j][j] + ans[i][j];
        }
        else{
          dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + ans[i][j];
        }
        dp[i][j] %= mod;
      }
    }
    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++){
    //     cout << i + 1 << " " << j + 1 << " " << dp[i][j] << " " << ans[i][j]<< endl;
    //   }
    // }
    vector<int> jaw;
    for(int i = 0; i < q; i++){
      jaw.pb(dp[l[i] - 1][r[i] - 1] % mod);
    }
    return jaw;
}

// int main() {
//     int N, Q;
//     std::cin >> N >> Q;
//     std::vector<int> A(N);
//     for(auto &a : A) {
//         std::cin >> a;
//     }
//     std::vector<int> L(Q), R(Q);
//     for(ll i = 0; i < Q; ++i)
//       std::cin >> L[i] >> R[i];
//     std::vector<int> answer = menari(N, Q, A, L, R);
//     for(auto x : answer)
//       std::cout << x << " ";
//     std::cout << std::endl;
//     return 0;
// }