//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, m;
    cin >> n >> m;
    set<int> cntL;
    int maxofL[n + 3], pref[n + 3];
    memset(pref, 0, sizeof pref);
    memset(maxofL, 0, sizeof maxofL);
    for(int i = 0; i<m; i++){
        int l, r;
        cin >> l >> r;
        maxofL[l] = max(maxofL[l], r);
        cntL.insert(l);
        pref[l]++;
        pref[r + 1]--;
    }
    for(int i = 1; i<=n; i++){
        pref[i] += pref[i - 1];
    }
    int dp[n + 3][2]; //state : steps, makan/tidak
    memset(dp, 0, sizeof dp);
    auto cur = cntL.begin();
    int ans = 0;
    for(int i = 1; i<=n; i++){
        while(maxofL[*cur] < i && cur != cntL.end()){
            cur++;
        }
        if(cur == cntL.end()){
            break;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[*cur][0] + pref[i];
        ans = max(max(ans, dp[i][0]), dp[i][1]);
    }
    // for(int i = 1; i<=n; i++) ans = max(ans, max(dp[i][1], dp[i][0]));
    cout << ans << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}