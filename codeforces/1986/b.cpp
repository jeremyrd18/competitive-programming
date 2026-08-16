//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n+3][m+3];
    memset(a, 0, sizeof a);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            int change = max(max(a[i][j - 1], a[i - 1][j]),max(a[i][j+1], a[i + 1][j]));
            if(a[i][j] > change){
                a[i][j] = change;
            }
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}