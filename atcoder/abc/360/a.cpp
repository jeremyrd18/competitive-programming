//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    bool no = 1;
    for(int i = 0; i<3; i++){
        if(no && s[i] == 'M'){
            cout << "No" << endl;
            return;
        }
        else if(s[i] == 'R'){
            no = 0;
        }
    }
    cout << "Yes" << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}