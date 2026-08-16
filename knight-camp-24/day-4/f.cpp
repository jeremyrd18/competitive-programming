//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, c;
    cin >> n >> c;
    int a[n];
    pair<int, int> opt[n];
    int minval = LLONG_MAX;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        a[i] = x + i + 1;
        minval = min(minval, a[i]);
        opt[i] = {x + min(i + 1, n-i), i};
    }
    if(minval > c){
        cout << 0 << endl;
        return;
    }
    sort(opt, opt + n);
    map<int, int> idxopt;
    for(int i = 0; i<n; i++){
        idxopt[opt[i].second] = i;
    }
    int pref[n + 1];
    pref[0] = 0;
    for(int i = 1; i<=n; i++){
        pref[i] = pref[i - 1] + opt[i - 1].first;
    }
    // for(int i = 1; i<=n; i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    // cout << c << endl;
    int ans = 0;
    for(int i = 0; i<n; i++){
        int l = 0, r = n - 1, jw = 0, energi = c - a[i];
        while(l <= r){
            int mid = (l + r)/2;
            if(idxopt[i] <= mid){
                if(pref[mid + 1] - pref[idxopt[i] + 1] + pref[idxopt[i]] <= energi){
                    // temp = pref[mid + 1] - a[i];
                    l = mid + 1;
                    jw = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(pref[mid + 1] <= energi){
                    // temp = pref[mid + 1];
                    l = mid + 1;
                    jw = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        ans = max(ans, jw);
    }
    cout << ans + 1 << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}