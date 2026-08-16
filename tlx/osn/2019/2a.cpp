//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> fr(n), ls(n);
    vector<pair<int, int> > tur(n);
    for(int i = 0; i<n; i++){
        cin >> fr[i] >> ls[i];
        tur[i] = {fr[i], ls[i]};
    }
    sort(fr.begin(), fr.end());
    sort(ls.begin(), ls.end());
    for(int i = 0; i<n; i++){
        int f = upper_bound(fr.begin(), fr.end(), tur[i].second) - fr.begin();
        int l = lower_bound(ls.begin(), ls.end(), tur[i].first) - ls.begin();
        cout << f - l - 1 << endl;
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}