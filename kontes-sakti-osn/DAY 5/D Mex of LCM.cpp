#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5;
int n,a[N+5];
void solve(){
    cin >> n;
    set<int> s;
    vector<int> x;
    int l = n*(n + 1)/2 + 1;
    for(int i=1;i<=n;++i){
        int val;
        cin >> val;
        vector<int> y;
        for(int a : x){
            int d = a / __gcd(a,val) * val;
            if (d <= l) y.push_back(d);
        }
        x.clear();
        y.push_back(val);
        for (int j = 0; j < y.size(); ++j)
            if (!j || y[j]!=y[j-1]){
                x.push_back(y[j]);
                s.insert(y[j]);
            }
    }
    int ans = 1;
    for (int x : s) ans += (ans==x);
    cout << ans << endl;
}
signed main(){
    int t;
    cin >> t;
    while (t--) solve();
}