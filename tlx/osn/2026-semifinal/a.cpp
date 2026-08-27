#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1000000007, maxn = 0;

void solve(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vi l(n);
    int count_odd = 0;
    
    for(int i = 0; i < n; i++){
        cin >> l[i];
        if(l[i] % 2 != 0){
            count_odd++;
        }
    }

    int used = 0;
    
    int tmp = min(k1, count_odd);
    k1 -= tmp;
    used += tmp;

    for(int i = 0; i < n; i++){
        if(l[i] % 2 != 0 && tmp > 0){
            l[i] -= 1;
            tmp--;
        }
    }

    for(int i = 0; i < n; i++){
        tmp = min(k1, l[i]);
        l[i] -= tmp;
        k1 -= tmp;
        used += tmp;
    }

    for(int i = 0; i < n; i++){
        tmp = min(k2, l[i] / 2);
        l[i] -= tmp * 2;
        k2 -= tmp;
        used += tmp;
    }

    cout << used << endl;
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