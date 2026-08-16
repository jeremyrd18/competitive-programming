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

int val[1000006];

void solve(){
    int n;
    cin >> n;
    int mat[n + 5][n + 5];
    memset(mat, -1, sizeof mat);
    memset(val, 0, sizeof val);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mat[i][j];
            int cur = mat[i][j];
            if(cur == -1) continue;
            for(int k = 2; k <= cur; k++){
                while(cur % k == 0){
                    val[k]++;
                    cur /= k;
                }
            }
        }
    }
    // for(int i = 0; i < 1000; i++){
    //     cout << i << " " << val[i] << endl;
    // }
    int ans = 1;
    for(int i = 1; i <= 1e6; i++){
        if(val[i] % n != 0 && val[i] != 0){
            for(int j = val[i] % n; j < n; j++){
                ans *= i;
                // cout << ans << endl;
            }
        }
    }
    cout << ans << endl;
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