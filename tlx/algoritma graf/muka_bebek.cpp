#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
vector<pair<int, pair<int ,int> > > adj;
int par[105];

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

bool comp(pair<int, pair<int, int> >  x, pair<int, pair<int, int> > y){
    return y.fi > x.fi;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(i >= j) continue;
            adj.push_back({x, {i, j}});
            // adj.push_back({x, {j, i}});
        }
    }
    sort(adj.begin(), adj.end(), comp);
    int ans = 0;
    for(auto x : adj){
        if(!cek(x.se.fi, x.se.se)){
            merge(x.se.fi, x.se.se);
            ans += x.fi;
            // cout << ans << " " << x.se.fi << " " << x.se.se << endl;
        }
    }
    cout << ans << endl;
}