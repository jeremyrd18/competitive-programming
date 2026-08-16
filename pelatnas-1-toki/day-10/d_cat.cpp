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

// int v[25000][25000];

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        int y = (x - '0');
        a[i] = y;
    }
    int ans = 0;
    stack<int> st;
    st.push(-1);
    int dpl[n + 5], dpr[n + 5];
    memset(dpl, 0, sizeof dpl); memset(dpr, 0, sizeof dpr);
    for(int i = 0; i < n; i++){
        while(a[i] < st.top() && st.top() != -1){
            st.pop();
        }
        if(a[i] == st.top()){
            st.pop();
        }
        else ans++;
        dpl[i + 1] = ans;
        st.push(a[i]);
    }
    while(st.top() != -1){
        st.pop();
    }
    reverse(a.begin(), a.end());
    ans = 0;
    for(int i = 0; i < n; i++){
        while(a[i] < st.top() && st.top() != -1){
            st.pop();
        }
        if(a[i] == st.top()){
            st.pop();
        }
        else ans++;
        dpr[n - i] = ans;
        st.push(a[i]);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << dpl[l - 1] + dpr[r + 1] << endl;
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