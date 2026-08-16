#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

signed main(){
	string dummy; cin >> dummy;
    int a, b, q;
    cin >> a >> b >> q;
    vector<pair<int, int> > ans;
    while(true){
        if(a == 0 && b > 0){
            cout << "TIDAK MUNGKIN" << endl;
            return 0;
        }
        if(a == 0 && b == 0){
            cout << "MUNGKIN" << endl;
            break;
        }
        if(a >= b + 1){
            int x = a / (b + 1);
            a -= x * (b + 1);
            ans.push_back({1, x});
        }
        else if(b >= a){
            int x = b / a;
            b -= x * a;
            ans.push_back({0, x});
        }
    }
    reverse(ans.begin(), ans.end());
    // for(auto x : ans){
    //     cout << x.fi << " " << x.se << endl;
    // }
    int m = ans.size();
    int pref[m + 2];
    pref[0] = 0;
    for(int i = 1; i <= m; i++){
        pref[i] = pref[i - 1] + ans[i - 1].se;
    }
    pref[m + 1] = 1e18;
    while(q--){
        int kiri, kanan;
        cin >> kiri >> kanan;
        kiri++; kanan++;
        if(kanan > pref[m]){
            cout << "DI LUAR BATAS" << endl;
            continue;
        }
        int l = 0, r = m, mid, res = -1;
        while(l <= r){
            mid = (l + r) / 2;
            if(pref[mid] >= kiri){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        int idxpref = res;
        // cout << idxpref << endl;
        while(kiri <= kanan){
            if(kiri > pref[idxpref]){
                kiri++;
                idxpref++;
                cout << ans[idxpref - 1].fi;
            } 
            else{
                kiri++;
                cout << ans[idxpref - 1].fi;
            } 
        }
        cout << endl;
    }
}