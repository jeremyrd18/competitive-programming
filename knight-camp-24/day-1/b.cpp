//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    stack<int> st1, st2;
    int lb[n + 1], rb[n + 1];
    for(int i = 1; i<=n; i++){
        lb[i] = 0;
        rb[i] = n + 1;
    }
    for(int i = 1; i<=n; i++){
        while(!st1.empty() && a[st1.top()] > a[i]){
            st1.pop();
        }
        if(!st1.empty()){
            lb[i] = st1.top();
        }
        st1.push(i);
    }
    for(int i = n; i > 0; i--){
        while(!st2.empty() && a[st2.top()] > a[i]){
            st2.pop();
        }
        if(!st2.empty()){
            rb[i] = st2.top();
        }
        st2.push(i);
    }
    /*for(int i = 1; i<=n; i++){
        cout << lb[i] << " " << rb[i] << endl;
    }*/
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans += (rb[i] - i)*(i - lb[i])*a[i];
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