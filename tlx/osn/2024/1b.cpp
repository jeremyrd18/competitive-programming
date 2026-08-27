#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 6e5 + 5;
vector<int> a(maxn), stmin(4 * maxn), stmax(4 * maxn), freq(300005, 0);
int n, k;

void build(int nd, int l, int r){
    if(l == r){
        stmax[nd] = a[l];
        stmin[nd] = a[l];
        return;
    }
    int left = nd * 2, right = nd * 2 + 1, mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    stmin[nd] = min(stmin[left], stmin[right]);
    stmax[nd] = max(stmax[left], stmax[right]);
}

int max_query(int nd, int l, int r, int ql, int qr){
    if(l > qr || r < ql){
        return -1e18;
    }
    if(l >= ql && r <= qr){
        return stmax[nd];
    }
    int mid = (l + r) / 2, nl = 2 * nd, nr = 2 * nd + 1;
    return max(max_query(nl, l, mid, ql, qr), max_query(nr, mid + 1, r, ql, qr));
}

int min_query(int nd, int l, int r, int ql, int qr){
    if(l > qr || r < ql){
        return 1e18;
    }
    if(l >= ql && r <= qr){
        return stmin[nd];
    }
    int mid = (l + r) / 2, nl = 2 * nd, nr = 2 * nd + 1;
    return min(min_query(nl, l, mid, ql, qr), min_query(nr, mid + 1, r, ql, qr));
}

signed main(){
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[n + i] = a[i];
    }
    n = 2 * n;
    int r = 0;
    int ans = 0;

    build(1, 0, n - 1);

    for(int l = 0; l < n; l++){
        while(r - l + 1 <= k && r < n && freq[a[r]] == 0){
            int cur_max = max(max_query(1, 0, n - 1, l, r), a[r]);
            int cur_min = min(min_query(1, 0, n - 1, l, r), a[r]);

            if(cur_max - cur_min >= k){
                break;
            }
            freq[a[r]]++;
            r++;
        }
        ans = max(ans, r - l);

        if(l < r) freq[a[l]]--;
        else r = l + 1;
    }

    cout << k - ans << endl;
}