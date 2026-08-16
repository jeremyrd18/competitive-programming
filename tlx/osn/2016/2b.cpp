#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve(){
    string subtask;
    cin >> subtask;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = 0;
    int unik[n];
    // for(int i = 0; i < n; i++) unik[i] = 1;
    int mp[n + 1];
    memset(mp, 0, sizeof mp);
    int temp = 1;
    while(l < n && r < n){
        int rr = a[r], ll = a[l];
        if(r <= l){
            mp[ll] = 1;
            r++;
            continue;
        }
        if(mp[rr] == 1){
            unik[l] = temp;
            temp--;
            mp[ll] = 0;
            temp = max(temp, 1LL);
            l++;
        }
        else{
            temp++;
            mp[rr] = 1;
            r++;
        }
    }
    // cout << l << " " << r << endl;
    for(int i = l; i < n; i++){
        unik[i] = temp;
        temp--;
    }
    pii pref[n];
    for(int i = 0; i < n; i++){
        if(i == 0){
            pref[i].first = unik[i];
            pref[i].second = i;
            continue;
        }
        if(unik[i] > pref[i - 1].first){
            pref[i] = {unik[i], i};
        }
        else{
            pref[i] = pref[i - 1];
        }
    }
    vector<pii> ans(n);
    for(int i = 0; i < n; i++){
        ans[i] = {0, 0};
        if(i - unik[i] >= 0){
            int idx = pref[i - unik[i]].second;
            ans[i] = {min(pref[i - unik[i]].first, unik[i]), idx};
        }
    }
    pii res = {-1, -1};
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(ans[i].fi > res.fi){
            res = ans[i];
            idx = i;
            // cout << res.fi << " " << res.se << " " << idx << endl;
        }
    }
    cout << res.se + 1 << " " << res.se + res.fi << " " << idx + 1<< " " << idx + res.fi << endl;
}

signed main(){
    gas
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}