#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007, N = 600005;

vector<int> a(N);
vector<pii> stmn(4 * N), stmx(4 * N);

void buildmn(int nd, int l, int r){
    if(l == r){
        stmn[nd].fi = a[l];
        stmn[nd].se = l;
        return;
    }
    int mid = (l + r) / 2;
    buildmn(nd * 2, l, mid);
    buildmn(nd * 2 + 1, mid + 1, r);
    stmn[nd] = min(stmn[nd * 2], stmn[nd * 2 + 1]);
}

pii qmin(int nd, int l, int r, int ql, int qr){
    if(l > qr || r < ql){
        return {1e15,1e15};
    }
    if(l >= ql || r <= qr){
        return stmn[nd];
    }
    int mid = (l + r) / 2;
    return min(qmin(nd * 2, l, mid, ql, qr), qmin(nd * 2 + 1, mid + 1, r, ql, qr));
}

void buildmx(int nd, int l, int r){
    if(l == r){
        stmx[nd].fi = a[l];
        stmx[nd].se = l;
        return;
    }
    int mid = (l + r) / 2;
    buildmx(nd * 2, l, mid);
    buildmx(nd * 2 + 1, mid + 1, r);
    stmx[nd] = max(stmx[nd * 2], stmx[nd * 2 + 1]);
}

pii qmax(int nd, int l, int r, int ql, int qr){
    if(l > qr || r < ql){
        return {-1e15,-1e15};
    }
    if(l >= ql || r <= qr){
        return stmx[nd];
    }
    int mid = (l + r) / 2;
    return max(qmax(nd * 2, l, mid, ql, qr), qmax(nd * 2 + 1, mid + 1, r, ql, qr));
}

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    // two pointer to find longest same element
    int lp = 0, rp = 2 * n - 1;
    int tp[2 * n];
    bool vis[2 * n - 1];
    while(rp <= 2 * n - 1 && lp <= 2 * n - 1){
        if(rp == 2 * n - 1){
            tp[lp] = rp;
            lp++;
            continue;
        }
        if(lp >= rp){
            tp[lp] = lp;
            rp++;
            continue;
        }
        if(vis[a[rp]] == 1){
            tp[lp] = rp;
            vis[a[lp]] = 0;
            lp++;
        }
        else{
            vis[rp] = 1;
            tp[lp] = rp;
            rp++;
        }
    } 

    buildmn(1, 0, 2 * n - 1);
    buildmx(1, 0, 2 * n - 1);
    for(int i = 0; i < 2 * n - k; i++){
        int l = i, r = i + k - 1;
        int tmp = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            int maxv = qmax(1, 0, 2 * n - 1, i, r).fi, minv = qmin(1, 0, 2 * n - 1, i, r).fi;
            int val =  maxv - minv + 1;
            if(tp[i] >= mid && val == mid - i + 1){
                tmp = val;
                l = mid + 1;
            }
            else r = mid - 1;
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