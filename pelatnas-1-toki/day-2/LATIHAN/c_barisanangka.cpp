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
    int n;
    cin >> n;
    vi a(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) ans = 1;
    }
    stack<int> st;
    st.push(-1);
    for(int i = 0; i < n; i++){
        while(a[i] < st.top() && st.top() != -1){
            st.pop();
        }
        if(a[i] == st.top()){
            st.pop();
        }
        else ans++;
        st.push(a[i]);
    }
    cout << ans << endl;
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