#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, N = 200005;
vi a(N), h(N), pref(N);
int n, k;

void solve(){
    cin >> n >> k;
    
    pref.assign(n + 2, 0);
    vi valid(n + 2, 0), pref_valid(n + 2, 0);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    
    for(int i = 1; i < n; i++){
        if(h[i] % h[i + 1] != 0){
            valid[i] = 1;
        } else {
            valid[i] = 0;
        }
        pref_valid[i] = pref_valid[i - 1] + valid[i];
    }
    pref_valid[n] = pref_valid[n - 1];
    
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        bool ok = false;
        for(int i = 1; i <= n - mid + 1; i++){
            int j = i + mid - 1;
            int sum_fruits = pref[j] - pref[i - 1];
            int bad_transitions = pref_valid[j - 1] - pref_valid[i - 1];
            
            if(sum_fruits <= k && bad_transitions == 0){
                ok = true;
                break;
            }
        }
        
        if(ok){
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans << "\n";
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