#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    cout << "0 0" << endl;
    cout << "1 0" << endl;
    int l = 2, r = 1, lastl = 1, lastr = 0;
    for(int i = 3; i <= n; i++){
        lastl += l;
        lastr += r;
        cout << lastl << " " << lastr << endl;
        l++;
        r++;
    }

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