#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, x;
    cin >> n >> x;
    int vis[n + 2];
    vector<pair<int, int> > c(n);
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++){
        int y = a[i];
        int z = b[i];
        // cout << y << " " << z << endl;
        c[i] = {(y - z), i};
        vis[i] = 0;
    }
    sort(c.begin(), c.end());
    // for(int i = 0; i < n; i++){
    //     cout << c[i].first << " " << c[i].second << endl;
    // }
    int ansb = 0;
    for(int i = 0; i < x; i++){
        // cout << c[i].second << endl;
        vis[c[i].second] = 1;
        ansb += a[c[i].second];
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ansb += min(a[i], b[i]);
        }
    }
    int ansa = 0;
    for(int i = 0; i < n; i++){
        vis[i] = 0;
    }
    sort(c.rbegin(), c.rend());
    for(int i = 0; i < x; i++){
        // cout << c[i].second << endl;
        vis[c[i].second] = 1;
        ansa += a[c[i].second];
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            ansa += max(a[i], b[i]);
        }
    }
    cout << ansa - ansb << endl;
}