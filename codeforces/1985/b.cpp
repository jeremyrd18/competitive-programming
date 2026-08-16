//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    int maxv = 0, ans = 0;
    for(int i = 2; i<=n; i++){
        int temp = 0;
        for(int j = i; j<=n; j+=i){
            temp += j;
        }
        if(maxv < temp){
            maxv = temp;
            ans = i;
        }
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