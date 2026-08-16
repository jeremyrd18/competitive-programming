//https://portal.kokocoder.com/contests/knight-camp-5-0-placement-test
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b>=c && b<=a){
        cout << "Yes";
    }
    else if(b<=c && b >= a){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}