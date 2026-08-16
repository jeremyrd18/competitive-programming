#include "kucing.h"
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define vi vector<long long>
#define pb push_back
#define pii pair<long long, long long>

const long long maxn = 200005;
long long idx[maxn];

long long NN;

pii st[4 * maxn];

void build(long long nd, long long l, long long r){
    if(l == r){
        st[nd] = {idx[l], l};
        return;
    }
    long long mid = (l + r) / 2;
    build(nd * 2, l, mid);
    build(nd * 2 + 1, mid + 1, r);
    st[nd] = max(st[nd * 2], st[nd * 2 + 1]);
}

pii query(long long nd, long long l, long long r, long long ql, long long qr){
    if(l >= ql && r <= qr){
        return st[nd];
    }
    if(l > qr || r < ql){
        return {-1e16, - 1e16};
    }
    long long mid = (l + r) / 2;
    return max(query(nd * 2, l, mid, ql, qr), query(nd * 2 + 1, mid + 1, r, ql, qr));
}

long long dnc(long long idx, long long l, long long r){
    if(l == r){
        return 1;
    }
    long long ans = 0;
    pii nx = query(1, 0, NN - 1, l, r);
    ans += abs(nx.se - idx);
    if(nx.se == l){
        return ans + dnc(nx.se, l + 1, r);
    }
    else if(nx.se == r){
        return ans + dnc(nx.se, l, r - 1);
    }
    else{
        return ans + max(dnc(nx.se, l, nx.se - 1), dnc(nx.se, nx.se + 1, r));
    }
}

long long latihanKucing(int n, std::vector<int> p, std::vector<int> a, std::vector<int> b) {
    NN = n;
    for(long long i = 0; i < n; i++){
        idx[i] = p[i];
    }
    build(1, 0, n - 1);
    pii maxv = query(1, 0, n - 1, 0, n - 1);

    if(maxv.se == 0){
        return dnc(0, 1, n - 1);
    }
    else if(maxv.se == n - 1){
        return dnc(n - 1, 0, n - 2);
    }
    else{
        return max(dnc(maxv.se, 0, maxv.se - 1), dnc(maxv.se, maxv.se + 1, n - 1));
    }
}