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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int q;
    cin >> q;

    while(q--){
        int tipe;
        cin >> tipe;
        // cout << "# " << q << endl;
        if(tipe == 1){
            vi tmp;
            int idx, w;
            cin >> idx >> w;
            a[idx - 1] = w;
            tmp = a;
            sort(tmp.begin(), tmp.end());
            bool ada = 1;
            for(int i = 0; i < m; i++){
                if(tmp.size() == 0){
                    cout << -1 << endl;
                    ada = 0;
                    break;
                }
                // cout << b[i] << "   ";
                // for(auto x : tmp){
                //     cout << x << " ";
                // } cout << endl;
                int l = 0, r = tmp.size() - 1, mid;
                int val = -1;
                while(l <= r){
                    mid = (l + r) / 2;
                    if(tmp[mid] <= b[i]){
                        val = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                if(val == -1) continue;
                vi tmp1;
                for(int i = 0; i < tmp.size(); i++){
                    if(i == val) continue;
                    tmp1.pb(tmp[i]);
                }
                tmp = tmp1;
            }
            if(!ada) continue;
            else{
                if(tmp.size() == 0){
                    cout << -1 << endl;
                }
                else cout << tmp[tmp.size() -1] << endl;
            }
        }
        else{
            vi tmp;
            int idx, w;
            cin >> idx >> w;
            b[idx - 1] = w;
            tmp = a;
            sort(tmp.begin(), tmp.end());
            bool ada = 1;
            for(int i = 0; i < m; i++){
                if(tmp.size() == 0){
                    cout << -1 << endl;
                    ada = 0;
                    break;
                }
                // cout << b[i] << "   ";
                // for(auto x : tmp){
                //     cout << x << " ";
                // } cout << endl;
                int l = 0, r = tmp.size() - 1, mid;
                int val = -1;
                while(l <= r){
                    mid = (l + r) / 2;
                    if(tmp[mid] <= b[i]){
                        val = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                if(val == -1) continue;
                vi tmp1;
                for(int i = 0; i < tmp.size(); i++){
                    if(i == val) continue;
                    tmp1.pb(tmp[i]);
                }
                tmp = tmp1;
            }
            if(!ada) continue;
            else{
                if(tmp.size() == 0){
                    cout << -1 << endl;
                }
                else cout << tmp[tmp.size() - 1] << endl;
            }
        }
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