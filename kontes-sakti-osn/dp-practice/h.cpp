#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define hitaf ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fi first
#define se second
 
const ll MOD = 1e9 + 7;
const ll INF = 4500000000000000000LL;
 
ll n, m, a[1000005];
bitset<200005> dp;
 
int main(){
    hitaf
    ll t = 1;
    //cin >> t;
    
    while(t--){
        cin >> n;
        
        vector<ll> pref(n + 2);
        for(int i = 0; i < n; pref[i] = (i == 0 ? 0 : pref[i - 1]) + a[i], i++) cin >> a[i];
        
        ll ans = 0;
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            dp |= dp << a[i];
            if(dp[i]) ans = max(ans, pref[i] - i);
            dp[i] = 0;
        }
        
        for(int i = n; i < 2 * n; i++){
            if(dp[i]) ans = max(ans, pref[n - 1] - i);
        }
        
        cout << ans << endl;
    }
}