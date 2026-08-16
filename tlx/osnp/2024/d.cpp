#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

signed main(){
    int b; string y;
    cin >> b >> y;

    int n = y.length();

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        if(dp[i] == 0) continue;

        int val = 0;
        for(int j = 1; j <= 7; j++){
            if(i + j > n){
                break;
            }
            
            val = val * 10 + (y[i + j - 1] - '0');
            if (val >= b) {
                break;
            }

            dp[i + j] += dp[i];
            dp[i + j] %= mod;
            if(y[i] == '0') break; //avoid leading 0s
        }
    }
    cout << dp[n] << endl;
}