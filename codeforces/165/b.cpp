#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, N = 200005;

bool check(int v, int n, int k) {
    int sum = 0;
    int cur = v;
    while (cur > 0) {
        sum += cur;
        cur /= k;
    }
    return sum >= n;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int l = 1, r = n, ans = n;
    while (l <= r) { // bsta
        int mid = (l + r) / 2;
        if (check(mid, n, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
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