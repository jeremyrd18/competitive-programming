#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = -2e9;
    for(int i = 0; i < n - 1; ++i) {
        ans = max(ans, sum - a[i] - a[i + 1] - a[i] - a[i + 1]);
    }
    cout << ans << '\n';
}
 
signed main() {
    int t;
    cin >> t;
    while(t--) solve();
}