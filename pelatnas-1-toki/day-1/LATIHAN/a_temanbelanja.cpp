#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

int n, m;
vi a;

vi ansa, ansb;


void bf(int idx, int val){
    if(idx >= n / 2){
        if(val == 0) return;
        if(val <= m){
            ansa.push_back(val);
        }
        return;
    }
    bf(idx + 1, val + a[idx]);
    bf(idx + 1, val);
}

void bf1(int idx, int val){
    if(idx >= n){
        if(val == 0) return;
        if(val <= m){
            ansb.push_back(val);
        }
        return;
    }
    bf1(idx + 1, val + a[idx]);
    bf1(idx + 1, val);
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > m){
            continue;
        }
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    n = a.size();
    bf(0, 0);
    bf1(n / 2, 0);
    int ans = 1;
    int sz1 = ansa.size(), sz2 = ansb.size();
    sort(ansa.begin(), ansa.end());
    sort(ansb.begin(), ansb.end());
    // for(auto v : ansa){
    //     cout << v << " ";
    // } cout << endl;
    // for(auto v : ansb){
    //     cout <<  v << " ";
    // } cout << endl;
    for(int i = 0; i < sz1; i++){
        int cur = ansa[i];
        int l = 0, r = sz2 - 1;
        int tmp = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(ansb[mid] + cur <= m){
                tmp = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(tmp == -1) continue;
        ans += (tmp + 1);
    }
    ans += sz1 + sz2;
    cout << ans << endl;
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