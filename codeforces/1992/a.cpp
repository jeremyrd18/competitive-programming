#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    for(int i = 0; i < 5; i++){
        sort(a.begin(), a.end());
        a[0]++;
    }
    cout << a[0]*a[1]*a[2] << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}