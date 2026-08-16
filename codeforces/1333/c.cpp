#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, N = 200005;

vi a(N), pref(N), last_bad(N);

void solve() {
    int n;
    cin >> n;
    
    map<int, int> mp;
    mp[0] = 0;
    
    int max_bad = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        
        if (mp.count(pref[i])) {
            max_bad = max(max_bad, mp[pref[i]] + 1);
        }
        last_bad[i] = max_bad;
        mp[pref[i]] = i;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int min_valid = max(1LL, last_bad[i] + 1);
        int l = 1, r = i, valid_l = i + 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid >= min_valid) {
                valid_l = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (valid_l <= i) {
            ans += (i - valid_l + 1);
        }
    }

    cout << ans << "\n";
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