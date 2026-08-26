#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1000000007, maxn = 0;

void solve(){
    int n, m;
    cin >> n >> m;
    int a[m + 5];
    memset(a, -1, sizeof a);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x % m] = max(a[x % m], x);
    }
    int ans = a[0] * 2;
    if(a[0] == -1) ans = -1;
    for(int i = 1; i <= m; i++){
        if(a[i] == -1 || a[m - i] == -1){
            continue;
        }
        ans = max(ans, a[i] + a[m - i]);
    }
    cout << ans << endl;
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