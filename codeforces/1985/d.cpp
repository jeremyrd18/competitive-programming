//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, m;
    cin >> n >> m;
    int mp[n + 2];
    int x, y;
    bool fi = 0;
    char mat[n + 1][m + 1];
    memset(mp, 0, sizeof mp);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= m; j++){
            char a = mat[i][j];
            if(a == '#'){
                mp[i]++;
            }
            if(mp[i] == 1 && !fi){
                fi = 1;
                x = j;
                y = i;
                break;
            }
            if(j == m && mp[i] < mp[i - 1]){
                y = i - 1;
                cout << y << " " << x << endl;
                return;
            }
        }
        // cout << endl;
    }
    // cout << "yes" << endl;
    cout << y << " " << x << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        // cout << i << endl;
        solve();
    }
}