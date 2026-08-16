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
    int r, c, q;
    cin >> r >> c >> q;
    while(q--){
        string t;
        int a, b;
        cin >> t >> a >> b;
        int dp[r + 5][c + 5];
        memset(dp, 0, sizeof dp);
        dp[1][a] = 1;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= r; j++){
                if(i == 1 && j == a){
                    continue;
                }
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
        int ans = r - 1;
        if((0 <= b && b <= a + r - 1) || (0 >= b && b >= a - r + 1)){
            
        }
        else{
            ans += min(b - (a + r - 1), b - (a - r + 1));
        }
        cout << r - 1 << " " << dp[r][b] << endl;
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