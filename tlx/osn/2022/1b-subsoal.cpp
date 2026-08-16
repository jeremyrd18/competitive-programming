#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int n;
int par[145];

int ask(int l, int r){
    cout << "? ";
    for(int i = 1; i <= n; i++){
        if(i == l) cout << 1;
        else if(i == r) cout << 2;
        else cout << 0;
        cout << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y){
    par[find(x)] = find(y);
}

bool cek(int x, int y){
    return (find(x) == find(y));
}

void sub2(){
    int k, a = -1, b;
    vector<pair<int, pair<int, int> > > res;
    bool vis[n + 2];
    bool awal = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
        par[i] = i;
        for(int j = i + 1; j <= n; j++){
            int x = ask(i, j);
            res.push_back({x, {i, j}});
        }
    }
    sort(res.begin(), res.end());
    cout << "! " << n - 1 << endl;
    for(auto x : res){
        if(cek(x.se.fi, x.se.se)) continue;
        merge(x.se.fi, x.se.se);
        cout << x.se.fi << " " << x.se.se << endl;
    }
}

signed main(){
    cin >> n;
    if(n <= 60){
        sub2();
    }
}
/*
1 4
1 2
1 2
1 3
1 2
1 3
*/