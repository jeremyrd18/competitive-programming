#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>

const int MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int cnt = 0;
    sort(a.rbegin(), a.rend());
    int temp = 0;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            temp++;
            // cout << temp << endl;
            if(temp % 2){
                cout << "YES" << endl;
                return;
            }
            temp = 0;
        }
        else{
            temp++;
        }
    }
    temp++;
    if(temp % 2){
        cout << "YES" << endl;
        return;
    }    
    cout << "NO" << endl;
    // cout << (cnt % 2 == 1 ? "YES" : "NO") << endl;
}

signed main(){
	int t;
    t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}