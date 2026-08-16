//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1), pref(n+1);
    pref[0] = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        int back = pref[i - 1];
        int cur = a[i];
        if(back > cur) continue;
        int front = 0;
        if(back == cur) ans++;
        int j;
        for(j = i + 1; j <= n; j++){
            front += a[j];
            if(back + front > cur){

                break;
            }
            else if(back + front == cur){
                ans++;
            }
        }
        i = j - 1;
    }
    cout << ans << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}