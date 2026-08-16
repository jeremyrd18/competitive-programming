#include <bits/stdc++.h>
using namespace std;
#define int long long
//const int INF = ;5

signed main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m), b(m), c(m);
    int dp[n + 3][n + 3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = 1000000007;
        }
    }
//    memset(dp, 1000000007, sizeof dp);
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        dp[a[i]][b[i]] = min(dp[a[i]][b[i]], c[i]);
        dp[b[i]][a[i]] = min(dp[b[i]][a[i]], c[i]);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) dp[i][j] = 0;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
    int cur;
    cin >> cur;
    cur--;
    int ans = 0;
    for(int i = 1; i < q; i++){
        int nx;
        cin >> nx;
        nx--;
//        cout << cur << " " << nx << endl;
        ans += dp[cur][nx];
        cur = nx;
    }
    cout << ans << endl;
}