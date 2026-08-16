#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

int n, s, q, par[200002], sz[200002];

int getroot(int nd){
    if(par[nd] == nd) return nd;
    return par[nd] = getroot(par[nd]);
}

void merge(int x, int y){
    int rootx = getroot(x);
    int rooty = getroot(y);
    par[rootx] = rooty;
    sz[rooty] += sz[rootx];
}

int cek(int x, int y){
    return getroot(x) == getroot(y);
}

void solve(){
    cin >> n >> s >> q;
    vector<pair<int, pair<int, int> > > v;
    // fi = start;
    // se.fi = end;
    // se.se = idx;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        for(int j = 0; j < p; j++){
            int x, y;
            cin >> x >> y;
            v.push_back({x, {y, i + 1}});
        }
    }
    sort(v.begin(), v.end());
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].fi << " " << v[i].se.fi << " " << v[i].se.se << endl;
    // }
    for(int i = 1; i <= 200000; i++){
        par[i] = i;
        sz[i] = 1;
    }
    int last, idxlast;
    for(int i = 0; i < v.size(); i++){
        int st = v[i].fi;
        int en = v[i].se.fi;
        int id = v[i].se.se;
        if(i == 0){
            last = en;
            idxlast = id;
            continue;
        }
        if(st > last){
            last = en;
            idxlast = id;
        }
        else{
            if(cek(idxlast, id)) continue;
            merge(idxlast, id);
            if(en > last){
                idxlast = id;
                last = en;
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << getroot(i) << " " << sz[getroot(i)] << endl;
    // }
    for(int i = 0; i < q; i++){
        int ask;
        cin >> ask;
        cout << sz[getroot(ask)] << endl;
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