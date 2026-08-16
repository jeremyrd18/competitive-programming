//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int cnt[n + 2], dp[n + 2];
    bool able[n + 2];
    memset(cnt, 0, sizeof cnt);
    memset(dp, 0, sizeof dp);
    memset(able, 1, sizeof able);
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i = n; i>=1; i--){
        int temp = 0;
        for(int j = i; j <= n; j += i){
            dp[i] -= dp[j];
            temp += cnt[j];
        }
        dp[i] += temp * (temp - 1) / 2;
    }
    for(int i = 1; i<=n; i++){
        if(cnt[i] > 0 && able[i] == 1){
            for(int j = i; j <= n; j+=i){
                able[j] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(able[i] == 1){
            ans += dp[i];
        }
    }
    cout << ans << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}