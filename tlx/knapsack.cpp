#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, w;
    cin >> w >> n;
    vector<int> cap(n + 5), val(n + 5);
    for(int i = n; i >= 1; i--){
        cin >> cap[i] >> val[i];
    }
    int dp[n + 5][w + 5];
    for(int i = 0; i <= w; i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j<= w; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= cap[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cap[i]] + val[i]);
            }
        }
    }
    int weight = w;
    int idx = n;
    while(dp[idx][weight] == dp[idx][weight - 1] && weight > 0){
        weight--;
    }
    while(idx > 0){
        if((dp[idx][weight] == (dp[idx - 1][weight - cap[idx]] + val[idx])) && weight >= cap[idx]){
            cout << n - idx + 1 << endl;
            weight -= cap[idx];
        }
        idx--;
    }
    // cout << dp[n][w] << endl;
}