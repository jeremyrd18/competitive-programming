#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100005;
int n, k, q, nx[maxn], ans[maxn];
vector<int> adj[maxn];

// nx[i] adalah node selanjutnya buat path terpanjang utk node i

int dfslength(int nd){
    int tmp = 0;
    for(int i : adj[nd]){
        int sz = dfslength(i);
        if(sz > tmp){
            tmp = sz;
            nx[nd] = i;
        }
    }
    return tmp + 1;
}

void solve(int nd){
    int cur = nd;
    vector<int> pend;
    while(cur != -1){
        pend.push_back(cur);
        cur = nx[cur];
    }
    int m = pend.size(), idxpend = 0;
    for(int i = m - 1; i >= 0; i--){
        if(k >= i){
            k -= i;
            ans[pend[idxpend]] = pend[i];
            idxpend++;
        }
        else{
            ans[pend[idxpend + i]] = pend[i];
        }
    }
    for(int i : pend){
        for(int j : adj[i]){
            if(j != nx[i]){
                solve(j);
            }
        }
    }
}

signed main(){
    cin >> n >> k >> q;
    for(int i = 2; i <= n; i++){
        int par; cin >> par;
        adj[par].push_back(i);
    }
    memset(nx, -1, sizeof nx);
    dfslength(1); solve(1);
    if(k == 0){
        cout << "YA" << endl;
        if(q == 1){
            for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        }
    }
    else cout << "TIDAK" << endl;
}