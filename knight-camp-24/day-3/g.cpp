//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    int pre[n + 1];
    pre[0] = 0;
    for(int i = 1; i<=n; i++){
        pre[i] = pre[i - 1] + a[i];
    }

    int l = 0, r = 1;
    set<int> st;
    int ans = 0;
    st.insert(0);
    while(l <= n && r <= n){
        if(!st.count(pre[r])){
            st.insert(pre[r]);
            r++;
           
        }
        else{
            st.erase(pre[l]);
            int temp = r - l - 1;
            ans += temp;
            l++;
            
        }
    }
    int temp = r - l - 1;
    ans += (temp)*(temp + 1)/2;
    // cout << l << " " << r << endl;
    cout << ans << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}