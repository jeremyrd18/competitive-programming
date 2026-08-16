#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[2][205][1805];

signed main(){
    string dummy;
    cin >> dummy;
    int n, k;
    cin >> n >> k;
    string p, s;
    cin >> p >> s;
    vector<int> bebek;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            bebek.push_back(i + 1);
        }
    }
    int m = bebek.size();
    // cout << bebek.size() << endl;
    // cout << sum << endl;
    // for(int i = 0; i < n; i++){
    //     cout << p[i] << " ";
    // }cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << s[i] << " ";
    // }
    for(int i = 0; i <= 1; i++) for(int j = 0; j <= m; j++) for(int w =  0; w <= 9 * m; w++){
        if(w == 0) dp[i][j][w] = 0;
        else dp[i][j][w] = k + 1;
    }
    dp[0][0][0] = 0; 
    // dp[1][0][0] = 0; 
    // dp[0][1][0] = 0; 
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int now = (i % 2), bef = 1 - now;
        int v = p[i - 1] - '0';
        for(int j = 1; j <= m; j++){
            for(int w = 0; w <= 9 * n; w++){
                dp[now][j][w] = dp[bef][j][w];
                if(w >= v) dp[now][j][w] = min(dp[now][j][w], dp[bef][j - 1][w - v] + abs(i - bebek[j - 1]));
                // cout << dp[i][j][w] << endl;
            }
        }
    }
    for(int v = 0; v <= 9 * m; v++){
        if(dp[n % 2][m][v] <= k) ans = v;
    }
    cout << ans << endl;
}