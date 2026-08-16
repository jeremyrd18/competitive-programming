//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> a, ta, tb, tc;
    bool able = 1;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        if(i < 2){
            a.push_back(x);
            continue;
        }
        a.push_back(x);
        if(__gcd(a[i - 2], a[i - 1]) > __gcd(a[i - 1], a[i])){
            for(int j = 0; j<=i; j++){
                if(j == i - 2){
                    tb.push_back(a[i - 2]);
                    tc.push_back(a[i - 2]);
                }
                else if(j == i - 1){
                    ta.push_back(a[i - 1]);
                    tc.push_back(a[i - 1]);
                }
                else if(j == i){
                    ta.push_back(a[i]);
                    tb.push_back(a[i]);
                }
                else if(j < i - 2){
                    ta.push_back(a[j]);
                    tb.push_back(a[j]);
                    tc.push_back(a[j]);
                }
            }
            able = 0;
            break;
        }
    }
    if(able){
        cout << "YES" << endl;
        return;
    }
    if(n - 1 == 2){
        cout << "YES" << endl;
        return;
    }
    for(int i = a.size(); i<n; i++){
        int x;
        cin >> x;
        ta.push_back(x);
        tb.push_back(x);
        tc.push_back(x);
    }
    // for(int i = 0; i<n - 1; i++){
    //     cout << tc[i] << " ";
    // }
    for(int i = 2; i < ta.size(); i++){
        if(__gcd(ta[i - 2], ta[i - 1]) > __gcd(ta[i - 1], ta[i])){
            able = 0;
            break;
        }
        able = 1;
    }
    if(able){
        cout << "YES" << endl;
        return;
    }
    for(int i = 2; i < tb.size(); i++){
        if(__gcd(tb[i - 2], tb[i - 1]) > __gcd(tb[i - 1], tb[i])){
            able = 0;
            break;
        }
        able = 1;
    }
    if(able){
        cout << "YES" << endl;
        return;
    }
    for(int i = 2; i < tc.size(); i++){
        if(__gcd(tc[i - 2], tc[i - 1]) > __gcd(tc[i - 1], tc[i])){
            // cout << " " << tc[i - 1] << " " << tc[i];
            able = 0;
            break;
        }
        // cout << __gcd(tc[i - 2], tc[i - 1]) << " ";
        able = 1;
    }
    if(able) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}