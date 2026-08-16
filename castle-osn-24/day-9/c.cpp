#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

signed main(){
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int q;
    cin >> q;
    vector<pair<int, vector<int> > > que(q);
    int cons = 0;
    int bef;
    for(int i = 0; i < q; i++){
        int tipe;
        cin >> tipe;
        if(tipe == 1){
            int a, b, c;
            cin >> a >> b >> c;
            que[i] = {tipe, {a, b, c}};
        }
        else{
            int a, b;
            cin >> a >> b;
            que[i] = {tipe, {a, b}};
        }
        if(i == 0){
            bef = tipe;
        }
        else{
            if(tipe == 2 && bef == 1 && cons == 0){
                cons = 1;
                bef = 2;
            }
            else if(tipe == 1 && bef == 2 && cons == 1){
                cons = 2;
            }
        }
    }
    // for(int i = 0; i < q; i++){
    //     cout << que[i].fi << " ";
    //     for(auto x : que[i].se){
    //         cout << x << " ";
    //     }cout << endl;
    // }
    // cout << cons << endl;
    if(n > 1){ // subsoal 2
        int pref[n + 3];
        pref[0] = 0;
        pref[1] = a[1];
        for(int i = 2; i <= n; i++){
            pref[i] = a[i] - a[i - 1];
        }
        bool udah = 0;
        pair<int, int> p[n + 3]; // inc, dec
        p[1] = {1, 1};
        for(int i = 0; i < q; i++){
            if(que[i].fi == 1){
                int l = que[i].se[0], r = que[i].se[1], x = que[i].se[2];
                pref[l] += x;
                pref[r + 1] -= x;
            }
            else{
                if(!udah){
                    udah = 1;
                    for(int j = 1; j <= n; j++){
                        pref[j] += pref[j - 1];
                        // cout << pref[j] << " ";
                    }
                    // cout << endl;
                    int dec = 1, inc = 1;
                    for(int j = 2; j <= n; j++){
                        if(pref[j] > pref[j - 1]){
                            inc = dec + 1;
                        }
                        else if(pref[j] < pref[j - 1]){
                            dec = inc + 1;
                        }
                        p[j] = {inc, dec};
                        // cout << p[j].fi << " " << p[j].se << endl;
                    }
                }
                int l = que[i].se[0], r = que[i].se[1];
                // cout << p[r].fi << " a ";
                if(l == 1){
                    cout << max(p[r].fi, p[r].se) << endl;
                }
                else cout << max(p[r].fi, p[r].se) - min(p[l].fi, p[l].se) << endl;
            }
        }
    }
    else{ // subsoal 1 bruteforce & Longest alternating
        for(int i = 0; i < q; i++){
            // cout << que[i].fi << " ";
            if(que[i].fi == 1){
                int l = que[i].se[0], r = que[i].se[1], x = que[i].se[2];
                // cout << l << " " << r << " " << x;
                for(int j = l; j <= r; j++){
                    a[j] += x;
                }
            }
            else{
                int l = que[i].se[0], r = que[i].se[1];
                int inc = 1, dec = 1;
                // cout << l << " " << r ;
                for(int j = l + 1; j <= r; j++){
                    if(a[j] > a[j - 1]){
                        inc = dec + 1;
                    }
                    else if(a[j] < a[j - 1]){
                        dec = inc + 1;
                    }
                }
                cout << max(dec, inc) << endl;
            }
            // cout << endl;
        }
    }
}