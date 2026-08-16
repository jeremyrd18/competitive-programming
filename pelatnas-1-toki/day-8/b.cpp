#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, maxn = 605;
vi adj[maxn];

vector<pii> ans;

int n, m;
bool ada = 0;

void cari(int x, vector<pii> v){
    if(x == n){
        vi va, vb, vc;
        for(int i = 0; i < n; i++){
            if(v[i].fi == 1){
                va.pb(v[i].se);
            }
            else if(v[i].fi == 2){
                vb.pb(v[i].se);
            }
            else{
                vc.pb(v[i].se);
            }
        }
        for(auto cur : va){
            int cnt = 0;
            for(auto z : adj[cur]){
                for(auto y : va){
                    if(y == z && y != cur){
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt != va.size() - 1){
                return;
            }
        }
        for(auto cur : vb){
            int cnt = 0;
            for(auto z : adj[cur]){
                for(auto y : vb){
                    if(y == z && y != cur){
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt != vb.size() - 1){
                return;
            }
        }
        for(auto cur : vc){
            int cnt = 0;
            for(auto z : adj[cur]){
                for(auto y : vc){
                    if(y == z && y != cur){
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt != vc.size() - 1){
                return;
            }
        }
        ada = 1;
        ans = v;
        return;
    }
    v.pb({1,x + 1});
    cari(x + 1, v);
    v.pop_back();
    v.pb({2,x + 1});
    cari(x + 1, v);
    v.pop_back();
    v.pb({3,x + 1});
    cari(x + 1, v);
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    cari(2, {{1,1}, {2,2}});
    if(ada == 0){
        cout << "impossible";
    }
    else{
        vi va;
        vi vb;
        vi vc;
        for(auto x : ans){
            // cout << x.fi << " " << x.se << endl;
            if(x.fi == 1){
                va.pb(x.se);
            }
            else if(x.fi == 2){
                vb.pb(x.se);
            }
            else vc.pb(x.se);
        }
        for(auto x : va){
            cout << x << " ";
        } cout << endl;
        for(auto x : vb){
            cout << x << " ";
        } cout << endl;
        // for(auto x : vc){
        //     cout << x << " ";
        // }
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