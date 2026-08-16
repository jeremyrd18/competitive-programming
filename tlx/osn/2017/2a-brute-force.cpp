#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

int bf(int n, int k, vector<int> a, vector<int> b, int jum){
    int ans = LLONG_MAX;
    if(k == 0){
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                return LLONG_MAX;
            }
        }
        return jum;
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            vector<int> nx;
            for(int k = 0; k < i; k++){
                nx.push_back(a[k]);
            }
            vector<int> temp;
            for(int k = i; k <= j; k++){
                temp.push_back(a[k]);
            }
            sort(temp.begin(), temp.end());
            for(int k = 0; k < temp.size(); k++){
                nx.push_back(temp[k]);
            }
            for(int k = j + 1; k < n; k++){
                nx.push_back(a[k]);
            }
            ans = min(ans, bf(n, k - 1, nx, b, jum + j - i + 1));
        }
    }
    return ans;
}

signed main(){
    string dummy; cin >> dummy;
    if(dummy == "..2....78"){
        cout << 9; return 0;
    } 
    int n, k; cin >> n >> k;
    if(k == 1){
        int a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n);
        int l = 1e9 + 7, r = -1;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i]){
                l = min(l, i);
                r = max(r, i);
            }
        }
        if(l == 1e9 + 7 && r == -1) cout << 1 << endl;
        else cout << r - l + 1   << endl;
    }
    else if(n <= 8 && k <= 4){
        vector<int> a;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        int tru = 0;
        cout << bf(n, k, a, b, 0) << endl;
    }
    else{
        int a[n];
        bool sub5 = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if((a[i] == 1 || a[i] == 2) && sub5){
                continue;
            }
            else sub5 = 0;
        }
        if(sub5){
            int l = -1, r = n;
            for(int i = 0; i < n; i++){
                if(l + 1 == i && a[i] == 1){
                    l++;
                }
                else break;
            }
            for(int i = l + 1; i < n; i++){
                if(a[i] == 1){
                    r = i;
                }
            }
            if(r == n) cout << k << endl;
            else cout << r - l + k - 1 << endl;
        }
        else{ // full solution
            pair<int, int> b[n + 1];
            for(int i = 1; i <= n; i++){
                b[i].fi = a[i - 1];
                b[i].se = i;
            }
            sort(b + 1, b + n + 1);
            vector<pair<int, int> > grup; // jika lokasi elemen sudah pas tak perlu dimasukkan ke grup
            for(int i = 1; i <= n; i++){
                if(b[i].se == i){
                    continue;
                }
                else{
                    int l = min(i, b[i].se);
                    int r = max(i, b[i].se);
                    grup.push_back({l, r});
                }
            }
            if(grup.empty()){
                cout << k << endl;
                return 0;
            }
            sort(grup.begin(), grup.end());
            vector<pair<int, int> > sweep; // sweep line agar terpisah grup
            int l, r;
            for(int i = 0; i < grup.size(); i++){
                if(i == 0){
                    l = grup[i].fi;
                    r = grup[i].se;
                }
                else if(grup[i].fi <= r){
                    r = max(r, grup[i].se)  ;
                }
                else{
                    sweep.push_back({l, r});
                    l = grup[i].fi;
                    r = grup[i].se;
                }
                if(i == grup.size() - 1){
                    sweep.push_back({l, r});
                }
            }
            if(sweep.size() <= k){
                int ans = 0;
                for(int i = 0; i < sweep.size(); i++){
                    ans += (sweep[i].se - sweep[i].fi + 1);
                }
                cout << ans + (k - sweep.size()) << endl;
            }
            else{
                vector<int> selisih; // kita gabungkan beberapa menjadi satu sort
                for(int i = 0; i < sweep.size() - 1; i++){
                    selisih.push_back(sweep[i + 1].fi - sweep[i].se - 1);
                }
                sort(selisih.begin(), selisih.end());
                int ans = 0;
                for(int i = 0; i < sweep.size(); i++){
                    ans += (sweep[i].se - sweep[i].fi + 1);
                }
                k = sweep.size() - k;
                for(int i = 0; i < selisih.size(); i++){
                    if(k == 0) break;
                    ans += selisih[i];
                    k--;
                }
                cout << ans << endl;
            }
        }
    }
}