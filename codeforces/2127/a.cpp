#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1000000007, maxn = 0;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    int x = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] != -1 && x == -1){
            x = a[i];
        }
    }
    if(x == -1){
        cout << "YES" << endl;
        return;
    }
    else if(x == 0){
        cout << "NO" << endl;
        return;
    }
    else{
        for(int i = 0; i < n; i++){
            if(a[i] == -1 || a[i] == x){
                continue;
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

signed main(){
    gas
	int t;
    t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}