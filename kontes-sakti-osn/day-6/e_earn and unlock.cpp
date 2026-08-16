#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 4;
bitset<N> dp;
int n, a[N];
int ans, sum;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
	dp[1] = 1;
	for (int i = 1; i < (n << 1); ++i) {
		sum += a[i];
		if (dp[i]) ans = max(ans, sum - i + 1);
		if (i <= n) {
			dp[i - 1] = 0;
			dp = dp | (dp << a[i]);
		}
	}
	cout << ans;
	return 0;
}