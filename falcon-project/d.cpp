#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1000000007, maxn = 0;

map<pair<int, pair<int, int> >, int> vis;

int ans = 0;
pair<int, pair<int, int> > jaw;

void bf(int a, int b, int c){
    if(vis[{a, {b, c}}] == 1){
        return;
    }
    vis[{a, {b, c}}] = 1;
    if(b > 12) return;
    if(b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12){
        if(a <= 31){
            ans++;
            jaw = {a, {b, c}};
        }
    }
    else if(b == 2){
        if(a <= 28){
            ans++;
            jaw = {a, {b, c}};
        }
    }
    else{
        if(a <= 30){
            ans++;
            jaw = {a, {b, c}};
        }
    }
    return;
}


void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    bf(a, b, c);
    bf(a, c, b);
    bf(b, c, a);
    bf(b, a, c);
    bf(c, a, b);
    bf(c, b, a);
    if(ans == 1){
        if(jaw.fi <= 9){
            cout << 0;
        }
        cout << jaw.fi << "/";
        if(jaw.se.fi <= 9){
            cout << 0;
        }
        cout << jaw.se.fi << "/";
        if(jaw.se.se <= 9){
            cout << 0;
        }
        cout << jaw.se.se << endl;
    }
    else{
        cout << "SELAMAT" << endl;
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