#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define endl '\n'
 
const ll MOD = 998244353;
 
ll n, x, c[55], h[55], dp[55][100005];
string s;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t = 1;
    cin >> t;    
    
    while(t--){
        cin >> n >> x;
        
        ll sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> c[i] >> h[i];
            sum += h[i];
        }
        
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                dp[i][j] = 1e18;
            }
        }
        
        for(int i = 1; i <= n; i++) dp[i][0] = 0;
        
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= h[i]){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - h[i]] + c[i]);
                }
                
                if(dp[i][j] <= x * (i - 1)) ans = max(ans,(ll)j);
                else dp[i][j] = 1e18;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}