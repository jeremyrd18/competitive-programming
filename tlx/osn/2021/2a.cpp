#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

const int mod = 1000000007;

signed main(){
    int n;
    cin >> n;
    int a[n + 1]; a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int dp[n + 1];
    int pref[n + 1];
    memset(dp, 0, sizeof dp);
    memset(pref, 0, sizeof pref);
    stack<int> st;
    st.push(0); // 0 menandakan bahwa sudah sampai ujung
    int jum = 0;
    for(int i = 1; i <= n; i++){
        while(a[i] < a[st.top()] && st.top() != 0){ // st will never be empty
            jum = (jum - dp[st.top()] + 2 * mod) % mod;
            st.pop();
        }
        int ujung = st.top();
        dp[i] = (jum + pref[i - 1] - pref[ujung] + 2 * mod) % mod;
        if(ujung == 0) dp[i]++;
        jum = (jum + dp[i] + 2 * mod) % mod;
        pref[i] = (pref[i - 1] + dp[i] + 2 * mod) % mod;
        st.push(i);
        // cout << dp[i] << endl;
    }
    int minval = a[n], ans = dp[n];
    for(int i = n - 1; i >= 1; i--){
        if(a[i] < minval){
            ans += dp[i];
            ans %= mod;
            minval = a[i];
        }
    }
    cout << ans << endl;
}