#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;
const int N = 2 * 100000 + 5;
int n;
vector<int> h(N), pref;
vector<pair<int, int> > habis;
vector<pair<int, int> > st(4 * N);

void build(int nd, int l, int r){
    if(l == r){
        st[nd].first = h[l];
        st[nd].second = l;
        return;
    }
    int le = (nd * 2), ri = (nd * 2) + 1, mid = (l + r) / 2;
    build(le, l, mid);
    build(ri, mid + 1, r);
    if(st[le].first < st[ri].first){
        st[nd].first = st[le].first;
        st[nd].second = st[le].second;
    }
    else{
        st[nd].first = st[ri].first;
        st[nd].second = st[ri].second;
    }
}

pair<int, int> query(int nd, int l, int r, int ql, int qr){
    if(l > qr || r < ql){
        return {1e16, 1e16};
    }
    if(l >= ql && r <= qr){
        return st[nd];
    }
    int mid = (l + r) / 2, nl = 2 * nd, nr = 2 * nd + 1;
    return min(query(nl, l, mid, ql, qr), query(nr, mid + 1, r, ql, qr));
}

void gas(int l, int r, int cur){
    if(l > r) return;
    if(l == r){
        pref.push_back(h[l] - cur);
        habis.push_back({l, r});
        return;
    }
    pair<int, int> mid = query(1, 0, n - 1, l, r);
    // cout << mid.first << endl;
    // cout << mid.second << endl;
    if(mid.first == cur){ // satu segmen mrq sama
        gas(l, mid.second - 1, cur);
        gas(mid.second + 1, r, cur);
        // cout << 1 << endl;
    }
    else{ // lebih
        // cout << 1 << endl;
        pref.push_back((mid.first - cur)*(r - l + 1));
        habis.push_back({l, r});
        gas(l, mid.second - 1, mid.first);
        gas(mid.second + 1, r, mid.first);
    }
}



void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    build(1, 0, n - 1);
    // cout << 1 << endl;
    // for(int i = 0; i < 10; i++){
    //     cout << st[i].first << " " << st[i].second << endl;
    // }
    gas(0, n - 1, 0);
    int sz = pref.size();
    for(int i = 1; i < sz; i++){
        pref[i] += pref[i - 1];
    }
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        int l = 0, r = sz - 1, idx = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(pref[mid] >= k){
                idx = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        int sisa = k;
        if(idx != 0){
            sisa = k - pref[idx - 1];
        }
        l = habis[idx].first;
        r = habis[idx].second;
        int len = (r - l + 1);
        if(sisa % len == 0){
            cout << r + 1 << endl;
            continue;
        }
        cout << (sisa % len) + l << endl;
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}

/*
Segment tree untuk save jumlah ambil dalam sebuah range
minimum range query
prefix di add lagi agar prefix sum
binser prefixnya
*/