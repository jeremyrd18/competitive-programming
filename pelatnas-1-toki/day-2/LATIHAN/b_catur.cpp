#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

void solve(){
    int r, c, q;
    cin >> r >> c >> q;
    while(q--){
        string t; int a, b;
        cin >> t >> a >> b;
        if(t == "P"){
            if(a == b){
                cout << b - a << " " << 1;
            }
            else cout << 0 << " " << 0;
        }
        else if(t == "R"){
            if(a == b){
                cout << 1 << " " << 1;
            }
            else{
                cout << 2 << " " << 2;
            }
        }
        else{
            int ans = 0;
            if(a == b){
                cout << 1 << " " << 1;
            }
            else if(r - 1)
        }
        cout << endl;
    }
}

signed main(){
    gas
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}