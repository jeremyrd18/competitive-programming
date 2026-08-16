#include <bits/stdc++.h>
using namespace std;
#define int long long

map<int, int> mp, d;
void div(int n) {
    for (int i = 2; i * i <= n; i++){
        while (n % i == 0){
            mp[i]++;
            n /= i;
        } 
    } 
    if (n > 1) mp[n]++;
}
bool cek() {
    d.clear();
    for (auto [l, r] : mp) {
        r++;
        for (int i = 2; i * i <= r; i++){
            while (r % i == 0){
                d[i]++;
                r /= i;
            } 
        } 
        if (r > 1) d[r]++;
    }
    for (auto [l, r] : d)
        if (mp[l] < r)
            return 0;
    return 1;
}
signed main() {
    int t, n, q, k, x;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        mp.clear();
        div(n);
        while (q--) {
            cin >> k;
            if (k == 1) {
                cin >> x;
                div(x);
                if (cek()) cout << "YES" << endl;
                else cout << "NO" << endl;
            } else {
                mp.clear();
                div(n);
            }
        }
        cout << endl;
    }
    return 0;
}