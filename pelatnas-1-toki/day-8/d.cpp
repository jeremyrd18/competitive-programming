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
    string s;
    cin >> s;
    int n = s.length();
    vector<string> pos;
    pos.pb("0");
    for(int i = 1; i < 1000; i++){
        if(i % 8 == 0){
            string x = "";
            int cur = i;
            while(cur > 0){
                x += to_string((cur % 10));
                cur /= 10;
            }
            reverse(x.begin(), x.end());
            pos.pb(x);
        }
    }
    for(string x : pos){
        int len = x.length();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(cnt == len){
                cout << x << endl;
                return;
            }
            if(x[cnt] == s[i]){
                cnt++;
            }
        }
        if(cnt == len){
            cout << x << endl;
            return;
        }
    }
    cout << -1 << endl;
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