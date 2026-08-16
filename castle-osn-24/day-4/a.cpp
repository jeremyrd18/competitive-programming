#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
vector<pii> pasang;

int binser(int l, int r, int find, vector<pii> v){
    int idx = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(v[mid].fi <= find){
            idx = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return idx; // jika -1 maka buang find
}

int cek(vector<int> va, vector<pii> byA, vector<int> vb, vector<pii> byB){
    if(va.size() == 0 && vb.size() == 0){
        return 0;
    }
    // int a = va.size();
    // int b = vb.size();
    // int na = byA.size();
    // int nb = byB.size();
    // if(byA[na - 1].fi > va[a - 1] && pasang[byA[na - 1].se].se > vb[b - 1]){
    //     if(byB[nb - 1].fi > vb[b - 1] && pasang[byB[nb - 1].se].fi > va[a - 1]){
    //         cout << -1 << endl;
    //     }
    // }
    return 2;
}

signed main(){
    int n, a, b;
    cin >> a >> b >> n;
    vector<int> va(a), vb(b);
    for(int i = 0; i < a; i++){
        cin >> va[i];
    }
    for(int i = 0; i < b; i++){
        cin >> vb[i];
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    vector<pii> byA(n), byB(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        byA[i] = {x, i};
        byB[i] = {y, i};
        pasang.push_back({x, y});
    }
    sort(byA.begin(), byA.end());
    sort(byB.begin(), byB.end());
    if(byA[n - 1].fi > va[a - 1] && pasang[byA[n - 1].se].se > vb[b - 1]){
        if(byB[n - 1].fi > vb[b - 1] && pasang[byB[n - 1].se].fi > va[a - 1]){
            cout << -1 << endl;
        }
    }
    vector<bool> vis(n, false);
    int ans = 0;
    while(1){
        vector<int> buang, buang1;
        bool ubah = 0, ubah1 = 0;
        for(int i = 0; i < va.size(); i++){
            int cur = va[i];
            int l = 0, r = byA.size() - 1, idx = -1;
            int bs = binser(l, r, cur, byA);
            if(bs == -1){
                buang.push_back(i);
            }
            else{
                while(vis[byA[bs].se] == 1){
                    buang1.push_back(bs);
                    if(bs == 0) break;
                    bs--;
                }
                vis[byA[bs].se] = 1;
                ubah = 1;
            }
        }
        int temp = 0;
        for(auto m : buang){
            va.erase(va.begin() + (m - temp));
            temp++;
        }
        temp = 0;
        for(auto m : buang1){
            byA.erase(byA.begin() + (m - temp));
            temp++;
        }
        // B
        buang.clear(); buang1.clear();
        for(int i = 0; i < vb.size(); i++){
            int cur = vb[i];
            int l = 0, r = byB.size() - 1, idx = -1;
            int bs = binser(l, r, cur, byB);
            if(bs == -1){
                buang.push_back(i);
            }
            else{
                while(vis[byB[bs].se] == 1){
                    buang1.push_back(bs);
                    if(bs == 0) break;
                    bs--;
                }
                vis[byB[bs].se] = 1;
                ubah1 = 1;
            }
        }
        temp = 0;
        for(auto m : buang){
            vb.erase(vb.begin() + (m - temp));
            temp++;
        }
        temp = 0;
        for(auto m : buang1){
            byB.erase(byB.begin() + (m - temp));
            temp++;
        }
        if(ubah || ubah1) ans++;
        int x = cek(va, byA, vb, byB);
        // for(auto m : va){
        //     cout << m << " ";
        // }
        // cout << endl;
        // for(auto m : byA){
        //     cout << m.first << " ";
        // }
        // cout << endl;
        // for(auto m : byA){
        //     cout << m.second << " ";
        // }
        // cout << endl;
        // for(auto m : vb){
        //     cout << m << " ";
        // }
        // cout << endl;
        // for(auto m : byB){
        //     cout << m.first << " ";
        // }
        // cout << endl;
        // for(auto m : byB){
        //     cout << m.second << " ";
        // }
        // cout << endl;
        // cout << endl;
        if(x == 2){
            continue;
        }
        else{
            cout << ans << endl;;
            return 0;
        }
    }
}