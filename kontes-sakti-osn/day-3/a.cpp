//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    map<int, int> mp;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto [x, y] : mp){
        // cout << x << " " << y << endl;
        a.push_back(y);
    }
    n = a.size();
    vector<int> dp(n + 2, MOD);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        vector<int> vdp= dp;
        for(int j = 1; j <= n; j++){
            int temp = dp[j - 1] + a[i - 1];
            if(i - j >= temp){
                vdp[j] = min(dp[j], temp);
            }
            if(j > i) break;
        }
        dp = vdp;
    }
    // for(auto i : dp){
    //     cout << i << " ";
    // }
    // cout << endl;
    int e = n;
    while(dp[e] == MOD) e--;
    cout << n - e << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}