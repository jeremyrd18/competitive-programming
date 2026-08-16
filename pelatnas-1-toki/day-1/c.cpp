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
    int n, x;
    cin >> n >> x;
    vector<int> c(n), h(n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin >> c[i] >> h[i];
        sum += h[i];
    }
    vector<pair<int, vector<int> >> dp(sum + 5);
    for(int i = 0; i < sum + 5; i++){
        dp[i] = {1e18, {}};
    }
    dp[0] = {0, {}};
    for(int i = 0; i<n; i++){
        for(int j = sum; j >= h[i]; j--){
            if(dp[j - h[i]].fi + c[i] <= x){
                if(dp[j].fi > dp[j - h[i]].fi + c[i]){
                    dp[j].fi = dp[j - h[i]].fi + c[i];
                    vi tmpp = dp[j - h[i]].se;
                    tmpp.push_back(i + 1);
                    dp[j].se = tmpp;
                }
            }
        }
    }
    for(int i = sum; i>=0; i--){
        if(dp[i].fi != 1e18){
            cout << i << endl;
            cout << dp[i].se.size() << endl;
            for(auto v : dp[i].se){
            	cout << v << " ";
			}
            return;
        }
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