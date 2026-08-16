#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, N = 200005;

vi a;

bool check(int max_w, int n) {
    int cnt = 1;
    int first_elem = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] - first_elem > 2 * max_w) {
            cnt++;
            first_elem = a[i];
        }
    }
    return cnt <= 3;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int l = 0, r = 1e9, ans = 1e9;
    while (l <= r) { // binary search on interval size
        int mid = (l + r) / 2;
        if (check(mid, n)) {
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
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}