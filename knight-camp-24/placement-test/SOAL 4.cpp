//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, q;
    cin >> n >> q;
    int a[n], pref[n+1];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    pref[0] = 0;
    for(int i = 1; i<=n; i++){
        pref[i] = pref[i-1] + a[i - 1];
    }
    for(int i = 0; i<q; i++){
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        int idx = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(a[mid] <= x){
                l = mid + 1;
                idx = mid;
            }
            else{
                r = mid - 1;
            }
        }
        if(idx == -1){
            cout << pref[n] - n*x<<endl;
            continue;
        }
        int luaskiri = (idx+1)*x, luaskanan = (n-idx - 1)*x;
        int rilkiri = pref[idx + 1], rilkanan = pref[n] - pref[idx + 1];
        cout << luaskiri - rilkiri + (rilkanan - luaskanan) << endl;
        //cout << idx << " " << luaskiri << " " << rilkiri << " " << luaskanan << " " << rilkanan << endl;
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}