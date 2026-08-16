#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int l, r, k;
    cin >> l >> r >> k;
    int p = r - l - k + 1;
    int ans = 0, i = 1;
    while(p > 0){
        ans += p;
        i++;
        // cout << ans << endl;
        p = r - l - (i * k) + 1;
    }
    cout << ans << endl;
}