//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, p;
    cin >> n >> p;
    vector<int> a1, a2;
    for(int i = 0; i < p; i++){
        int x, y;
        cin >> x >> y;
        if(x == 1){
            a1.push_back(y);
        }
        else{
            a2.push_back(y);
        }
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        int ans1 = lower_bound(a1.begin(), a1.end(), max(x, y)) - a1.begin();
        ans1 = a1.size() - ans1 + 1;
        ans1 %= 2;
        int ans2 = upper_bound(a2.begin(), a2.end(), min(x, y)) - a2.begin();
        ans2++;
        ans2 %= 2;
        ans1 = (ans1 + ans2) % 2;
        cout << ans1 << endl;
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}