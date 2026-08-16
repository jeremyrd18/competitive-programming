//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n; cin >> n;
    int cnt0 = 0, cnt1 = 0;
    bool streak = 0;
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        if(x == '1'){
            cnt1++;
            streak = 0;
        }
        else{
            if(!streak) cnt0++;
            streak = 1;
        }
    }
    if(cnt1 > cnt0){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

signed main(){
	int t;
    // t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}