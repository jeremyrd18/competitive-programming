#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;
const int maxn = 200005;
int n;
vi h(maxn), st_h(4 * maxn), st_u(4 * maxn), st_d(4 * maxn);

void buildh(int nd, int l, int r) {
    if (l == r) {
        st_h[nd] = h[l];
        return;
    }
    int mid = (l + r) / 2;
    buildh(2 * nd, l, mid);
    buildh(2 * nd + 1, mid + 1, r);
    st_h[nd] = max(st_h[2 * nd], st_h[2 * nd + 1]);
}

int qh(int nd, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return LLONG_MIN;
    }
    if (l >= ql && r <= qr) {
        return st_h[nd];
    }
    int mid = (l + r) / 2;
    return max(qh(2 * nd, l, mid, ql, qr), qh(2 * nd + 1, mid + 1, r, ql, qr));
}

void buildu(int nd, int l, int r) {
    if (l == r) {
        st_u[nd] = h[l] - l;
        return;
    }
    int mid = (l + r) / 2;
    buildu(2 * nd, l, mid);
    buildu(2 * nd + 1, mid + 1, r);
    st_u[nd] = max(st_u[2 * nd], st_u[2 * nd + 1]);
}

int qu(int nd, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return LLONG_MIN;
    }
    if (l >= ql && r <= qr) {
        return st_u[nd];
    }
    int mid = (l + r) / 2;
    return max(qu(2 * nd, l, mid, ql, qr), qu(2 * nd + 1, mid + 1, r, ql, qr));
}

void buildd(int nd, int l, int r) {
    if (l == r) {
        st_d[nd] = h[l] + l;
        return;
    }
    int mid = (l + r) / 2;
    buildd(2 * nd, l, mid);
    buildd(2 * nd + 1, mid + 1, r);
    st_d[nd] = max(st_d[2 * nd], st_d[2 * nd + 1]);
}

int qd(int nd, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return LLONG_MIN;
    }
    if (l >= ql && r <= qr) {
        return st_d[nd];
    }
    int mid = (l + r) / 2;
    return max(qd(2 * nd, l, mid, ql, qr), qd(2 * nd + 1, mid + 1, r, ql, qr));
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    buildh(1, 1, n);
    buildu(1, 1, n);
    buildd(1, 1, n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        if (abs(s - t) == 1) {
            if (h[s] > h[t]) {
                cout << h[s] - h[t] << endl;
            } else if (h[s] < h[t]) {
                cout << (h[t] - h[s]) * 4 << endl;
            } else {
                cout << 2 << endl;
            }
            continue;
        }

        if (s < t) {
            int ans = 0;
            int hi = qh(1, 1, n, s + 1, t - 1);
            if (h[hi] >= h[s] && h[hi] >= h[t]) {
                int sep = qu(1, 1, n, s + 1, hi - 1);
                cout << sep << " ";
                if (h[sep] - sep - h[s] + s <= 0) {
                    ans += (h[hi] - h[s]) * 4 + (hi - s - h[hi] + h[s]) * 2;
                } else {
                    ans += (h[hi] - h[s] + 2 * sep) * 4;
                    ans += (hi - h[hi] + h[sep] - sep + s) * 2;
                }
                // sep = 
            }
            cout << ans << endl;
        }
    }
}

signed main() {
    gas
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}
