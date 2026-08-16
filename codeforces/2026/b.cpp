#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

// mungkin ga bisa di paint double

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vector<int> mins;
    set<pii> don;
    for(int i = 0; i < n; i++){
        if(i == 0){
            mins.push_back(a[i + 1] - a[i]);
            continue;
        }
        if(i == n - 1){
            mins.push_back(a[i] - a[i - 1]);
            continue;
        }
        int tmp = a[i] - a[i - 1];
        tmp = min(tmp, a[i + 1] - a[i]);
        mins.push_back(tmp);
    }
    sort(mins.rbegin(), mins.rend());
    int ans = mins[0];
    for(auto x : mins){
        // cout << x << endl;
        if(x < ans){
            ans = x;
            break;
        }
    }
    // cout << endl;
    cout << ans << endl;
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