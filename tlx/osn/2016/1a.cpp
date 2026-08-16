#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second


pair<int, int> moves[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m, q;
int mat[40][40], vis[40][40];
vector<int> res;


void dfs(int x, int y, int ans){
    if(x < 1 || x > m || y < 1 || y > n){
        return;
    }
    if(x == m && y == n){
        ans += mat[y][x];
        res.push_back(ans);
        return;
    }
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        pair<int, int> z = moves[i];
        if(!vis[x + z.fi][y + z.se])
            dfs(x + z.fi, y + z.se, ans + mat[y][x]);
    }
    vis[x][y] = 0;
}

signed main(){
    memset(vis, 0, sizeof vis);
    string dummy; cin >> dummy;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }
    dfs(1, 1, 0);
    sort(res.begin(), res.end());
    // for(auto x: res){
    //     cout << x << " ";
    // }cout << endl;
    cin >> q;
    while(q--){
        int le, ri;
        cin >> le >> ri;
        int l = 0, r = res.size() - 1, atas = -1, bawah = res.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(res[mid] >= le){
                bawah = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        l = 0, r = res.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(res[mid] <= ri){
                atas = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << atas - bawah + 1 << endl;
        // int left = lower_bound(res.begin(), res.end(), le) - res.begin();
		// int right = upper_bound(res.begin(), res.end(), ri) - res.begin();
        // cout << right - left  << endl;
    } 
}

/*
1 ≤ N × M ≤ 36
1 ≤ K ≤ 100.000
-109 ≤ Toko(i, j) ≤ 109
*/