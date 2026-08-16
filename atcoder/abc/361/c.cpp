#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    k = n - k - 1;
    int ans = 10000000098;
    for(int i = 0; i < n; i++){
        int r = i + k;
        if(r >= n) break;
        ans = min(ans, a[r] - a[i]);
    }
    cout << ans << endl;
}