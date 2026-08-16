//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
vector<int> a(1000005), vgcd(1800005);

void build(int idx, int l, int r){
    if(l==r){
        vgcd[idx] = a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    vgcd[idx] = __gcd(vgcd[2*idx], vgcd[2*idx+1]);
}

int query(int idx, int l, int r, int ql, int qr){
    if(l > qr || r < ql)return 0;
    if(l >= ql && r <= qr){
        return vgcd[idx];
    }
    int mid = (l + r)/2;
    return __gcd(query(2*idx, l, mid, ql, qr), query(2*idx+1, mid+1, r, ql, qr));
}

void solve(){
    int n;
    cin >> n;
    int awal, samasemua = 1;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        if(i == 1){
            awal = a[i];
        }
        else{
            if(a[i] != awal){
                samasemua = 0;
            }
        }
    }
    if(samasemua){
        cout << 0 << endl;
        return;
    }
    for(int i = 1; i<=n; i++){
        a[i + n] = a[i];
    }
    build(1, 1, 2*n);
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l + r)/2;
        int benar = 1, cek = query(1, 1, 2*n, 1, 1+mid);
        for(int i = 2; i<=n; i++){
            if(query(1, 1, 2*n, i, i+mid) != cek){
                benar = 0;
                break;
            }
        }
        if(benar){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}