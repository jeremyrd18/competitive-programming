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

bool tanya(int l, int r){
    cout << "pantau " << l << " " << r << endl;
    string s;
    cin >> s;
    return (s == "YA");
}

void tmb(int x){
    cout << "tembak " << x << endl;
}

void solve(){
    string dummy; cin >> dummy;
    int pm, vm;
    cin >> pm >> vm;
    vector<pii> pos;
    for(int i = 0; i <= pm; i++){
        for(int j = 0; j <= vm; j++){
            pos.pb({i, j});
        }
    }
    int l = 0, r = pos.size() - 1, mid;
    while(l <= r){
        l = 0; r = pos.size() - 1;
        sort(pos.begin(), pos.end());
//        for(auto x : pos){
//        	cout << x.fi << " " << x.se << endl;
//		} cout << endl;
        if(l == r){
            tmb(pos[l].fi);
            break;
        }
        mid = (l + r) / 2;
        int cur = mid;
        for(int i = mid + 1; i <= pos.size(); i++){
            if(pos[i].fi > pos[cur].fi){
                break;
            }
            cur = i;
        }
        if(tanya(pos[0].fi, pos[cur].fi)){
            vector<pii> nx;
            for(int i = 0; i <= cur; i++){
                nx.push_back({pos[i].fi + pos[i].se, pos[i].se});
            }
            pos = nx;
        }
        else{
            vector<pii> nx;
            for(int i = cur + 1; i < pos.size(); i++){
                nx.push_back({pos[i].fi + pos[i].se, pos[i].se});
            }
            pos = nx;
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