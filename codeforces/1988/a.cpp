//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if(n <= k){
        cout << 1 << endl;
        return;
    }
    bool yes = 0;
    while(true){
        if(n >= k*k){
            if(!yes) ans++;
            yes = 1;
            if(n == k * k){
                ans += (k);
                break;
            }
            n -= (k - 1)*k;
            ans += k;
        }
        else{
            if(!yes) ans++;
            for(int i = 0; i < k; i++){
                if(n == 0){
                    break;
                }
                if(n == 1){
                    // ans++;
                    break;
                }
                if(n >= k){
                    n -= k;
                    ans ++;
                    continue;
                }
                if(n < k){
                    ans ++;
                    break;
                }
            }
            break;
        }
    }
    cout << ans << endl;
}

signed main(){
	int t;
    // t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}