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

    if(m % n != 0){
        cout << -1 << endl;
        return;
    }

    map<int, int> pfn, pfm;

    for(int i = 2; i <= n; i++){
        while(n % i == 0){
            pfn[i]++;
            n /= i;
        }
    }

     for(int i = 2; i <= m; i++){
        while(m % i == 0){
            pfm[i]++;
            m /= i;
        }
    }

    int ans = 0;

    for(auto [x, y]: pfm){
        int curn = pfn[x], curm = pfm[x];
        if(curn == 0 || curm < curn){
            cout << -1 << endl;
            return;
        }
        int cnt = 0;
        while(curn < curm){
            cnt++;
            curn *= 2;
        }
        ans = max(ans, cnt);
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