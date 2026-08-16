//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    char num[n];
    int adanol = 0;
    for(int i = 0; i<n; i++){
        cin >> num[i];
        if(num[i] == 0) adanol = 1;
    }
    if(n == 2){
        if(num[0] == 0){
            cout << num[1] << endl;
        }
        else cout << num[0] << num[1] << endl;
    }
    else if(adanol){
        cout << 0 << endl;
    }
    else{
        
    }
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}