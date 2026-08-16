//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;


void solve(){
    string s;
    cin >> s;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == 'w' || s[i] == 'm'){
            cout << 0 << endl;
            return;
        }
    }
    int ans = 1, ulen = 0;
    int dp[s.length() + 5];
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= s.length(); i++){
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    for(int i = 0; i<s.length(); i++){
        if(s[i] != 'u'){
            if(ulen >= 2){
                ans *= dp[ulen];
                ans %= MOD;
            }
            ulen = 0;
        }
        else{
            ulen++;
        }
    }
    ans *= dp[ulen];
    ans %= MOD;
    ulen = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] != 'n'){
            if(ulen >= 2){
                ans *= dp[ulen];
                ans %= MOD;
            }
            ulen = 0;
        }
        else{
            ulen++;
        }
    }
    ans *= dp[ulen];
    ans %= MOD;
    cout << ans << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}