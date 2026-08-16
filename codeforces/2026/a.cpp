#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

void solve(){
    int x, y, k;
    cin >> x >> y >> k;
    int len = min(x, y);
    cout << 0 << " " << len << " " << len << " " << 0 << endl;
    cout << 0  << " "<<  0 << " " << len  << " "<< len << endl;
}

signed main(){
    gas
	int t;
    t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}