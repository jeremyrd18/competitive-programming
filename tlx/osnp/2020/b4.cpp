#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    int dp[n + 5], a[n +5];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1] = 0;
    // dp[2] = (a[2] - a[1]) * (a[2] - a[1]);
    for(int i = 2; i <= n; i++){
        if(i > 2) dp[i] = min(dp[i - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]), dp[i - 2] + 3 * (a[i] - a[i - 2]) * (a[i] - a[i - 2]));
        else dp[i] = dp[i - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
        if(i < n){
            dp[i] = min(dp[i], dp[i - 1] + 3 * (a[i - 1] - a[i + 1]) * (a[i - 1] - a[i + 1]) + (a[i + 1] - a[i]) * (a[i + 1] - a[i]));
        }
    }
    cout << dp[n] << endl;
}