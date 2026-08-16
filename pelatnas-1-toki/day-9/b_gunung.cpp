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
    int n; double h;
    cin >> n >> h;
    vector<double> posx, posy;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        posx.pb(x);
        posy.pb(y);
    }
    vector<pair<double, double> > range;
    for(int i = 0; i < n; i++){
        if(i == 0 || i == n - 1 || i % 2 == 1) continue;
        double grl = posy[i] - posy[i - 1];
        grl /= (posx[i] - posx[i - 1]);
        double left = (h - posy[i] + (grl * posx[i])) / grl;
        double grr = posy[i] - posy[i + 1];
        grr /= (posx[i] - posx[i + 1]);
        double right = (h - posy[i] + (grr * posx[i])) / grr;
        // cout << grl << " " << grr << endl;
        range.pb({left, right});
    }
    
    sort(range.begin(), range.end());

    bool awal = 0;
    double kanan, kiri;
    int ans = 0;
    // cout << range.size() << endl;
    for(pair<double, double> x : range){
        // cout << x.fi << " " << x.se << " " << ans << endl;
        if(!awal){
            awal = 1;
            kiri = x.fi;
            kanan = x.se;
            continue;
        }
        if(x.fi > kanan){
            ans++;
            kiri = x.fi;
            kanan = x.se;
            continue;
        }
        if(x.se <= kanan){
            kiri = x.fi;
            kanan = x.se;
            continue;
        }
        kiri = x.fi;        
    }
    cout << ans + 1 << endl;
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