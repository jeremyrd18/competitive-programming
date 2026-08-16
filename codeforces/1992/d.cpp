//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, m, k; // size, jump, swim
    cin >> n >> m >> k;
    string s = "L";
    string a;
    cin >> a;
    s += a;
    s += 'L';
    // cout << s;
    // cout << s;
    int dp[n + 3];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    int last[n + 3];
    int idx = 0;
    last[0] = 0;
    for(int i = 1; i <= n + 1; i++){
        if(s[i] == 'L'){
            idx = i;
        }
        last[i] = idx;
    }
    pair<int, int> croc[n + 3];
    for(int i = 0; i <= n + 2; i++){
        croc[i] = {0, 0};
    }
    for(int i = 1; i <= n + 1; i++){
        if(k < 0){
            break;
        }
        int cur = s[i];
        int bef = s[i - 1];
        if(cur == 'L'){
            if(bef == 'L'){
                dp[i] = 1;
            }
            else{
                if(i - last[i - 1] <= m){
                    dp[i] = 1;
                }
                else if(croc[last[i - 1]].first == 0){
                    if(i - last[i - 1] - k <= m){
                        dp[i] = 1;
                        k -= (i - last[i - 1] - m);
                    }
                    else{
                        dp[i] = 0;
                        break;
                    }
                }
                else{
                    int jarak = i - croc[last[i - 1]].second;
                    jarak = min(jarak, i - (last[i - 1] + m));
                    // cout << i << " " << jarak;
                    if(jarak <= k){
                        if(croc[last[i - 1]].second - last[i - 1] <= m){
                            k -= jarak;
                            dp[i] = 1;
                        }
                    }
                    else{
                        dp[i] = 0;
                        break;
                    }
                }
            }
        }
        else if(cur == 'C'){
            dp[i] = 0;
            croc[last[i]] = {1, i + 1};
        }
        else{
            dp[i] = 0;
        }
        // cout << i << " " << dp[i] << " "<<k<<endl;
    }
    if(dp[n + 1] == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}