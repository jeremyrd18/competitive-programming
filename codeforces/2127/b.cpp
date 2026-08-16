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
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k << "<-" << endl;
    vector<char> s(n + 5);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    if(k == 1 || k == n){
        cout << 1 << endl;
        return;
    }
    
    bool pagar = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '#'){
            pagar = 1;
        }
    }
    
    if(!pagar){
        
        cout << 1 << endl;
    }
    else{
        int left = -1, right = -1;
        for(int i = 1; i < k; i++){
            if(s[i] == '#'){
                left = i;
            }
        }
        for(int i = k + 1; i <= n; i++){
            if(s[i] == '#'){
                right = i;
                break;
            }
        }
        if(left == -1){
            cout << n - right + 1 << endl;
            return;
        }
        int ans = k;
        ans = max(ans, left + 1);
        int ans1 = n - k + 1;
        ans1 = max(ans1, n - right);
        cout << min(ans, ans1) << endl;
    }
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