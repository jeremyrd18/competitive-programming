//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, t;
    cin >> n >> t;
    t *= 2;
    string s;
    cin >> s;
    vector<int> x(n + 3);
    for(int i = 0; i<n; i++){
        cin >> x[i];
    }
    int l = 0, r = 1, ans = 0, cntr = 0;
    while(l < n && r < n){
        if(l >= r){
            r++;
            continue;
        }
        if(s[l] == '0'){
            l++;
            continue;
        }
        if(s[r] == '0'){
            if(x[r] - x[l] <= t){
                // cout << l << " " << r << " " << cntr + 1 <<endl;
                // lastr = r;
                // cntr++;
                ans += cntr + 1;
                r++;
            }
            else{
                if(cntr == 0){
                    l++;
                    continue;
                }
                cntr--;
                l++;
            }
        }
        else{
            cntr++;
            r++;
        }
    }
    cout << ans << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}