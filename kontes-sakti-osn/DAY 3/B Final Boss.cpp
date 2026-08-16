//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), c(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }
    set<pair<int, int> > s;
    for(int i = 0; i<n; i++){
        s.insert({1, i});
    }
    int last = 1;
    while(h > 0){
        auto [x, i] = *s.begin();
        s.erase(s.begin());
        h -= a[i];
        last = x;
        s.insert({x + c[i], i});
    }
    cout << last << endl;
}
signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        // cout << i << "euy" << endl;
        solve();
    }
}