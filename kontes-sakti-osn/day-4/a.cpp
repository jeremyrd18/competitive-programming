// https://codeforces.com/contest/1872/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100003;
int a[N], tree[4*N];
string s;
int n;

void build(int node, int st, int ed){
    if(st == ed){
        tree[node] = a[st];
        return;
    }
    int l = node*2, r = (node*2) + 1, mid = (st + ed)/2;
    build(l, st, mid);
    build(r, mid + 1, ed);
    tree[node] = (tree[l] ^ tree[r]);
}

int query(int node, int st, int ed, int l, int r){
    if(st == l && ed == r){
        return tree[node];
    }
    int lf = node*2, rg = (node*2) + 1, mid = (st + ed)/2;
    if(r <= mid){
        return query(lf, st, mid, l, r);
    }
    else if(l > mid){
        return query(rg, mid + 1, ed, l, r);
    }
    else{
        int a1 = query(lf, st, mid, l, mid);
        int a2 = query(rg, mid + 1, ed, mid + 1, r);
        return (a1 ^ a2);
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> s;
    int zero = 0, one = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            one ^= a[i];
        }
        else{
            zero ^= a[i];
        }
    }
    int q;
    cin >> q;
    build(1, 0, n - 1);
    while(q--){
        int tp;
        cin >> tp;
        if(tp == 1){
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l - 1, r - 1);
            zero ^= ans;
            one ^= ans;
        }
        else{
            int x;
            cin >> x;
            if(x == 1){
                cout << one << " ";
            }
            else{
                cout << zero << " ";
            }
        }
    }
    cout << endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}