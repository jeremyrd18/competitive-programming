//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    map<int, int> x, y;
    map<pair<int,int>, int> sa;
    vector<int> row, col;
    for(int i = 0; i<n; i++){
        int r, c, e;
        cin >> r >> c >> e;
        x[r] += e;
        y[c] += e;
        row.push_back(r);
        col.push_back(c);
        sa[{r, c}] += e;
    }
    int ansrow = 0, anscol = 0, idxr, idxc;
    for(int i = 0; i<n; i++){
        if(ansrow < x[row[i]]){
            idxr = row[i];
            ansrow = max(ansrow, x[row[i]]);
        }
    } 
    for(int i = 0; i<n; i++){
        if(anscol < y[col[i]] - sa[{idxr, col[i]}]){
            idxc = col[i];
            anscol = max(anscol, y[col[i]] - sa[{idxr, col[i]}]);
        }
    }
    int ans = ansrow + anscol;
    // cout << ans << endl;
    ansrow = 0, anscol = 0;
    for(int i = 0; i<n; i++){
        if(anscol < y[col[i]]){
            idxc = col[i];
            anscol = max(anscol, y[col[i]]);
        }
    } 
    for(int i = 0; i<n; i++){
        if(ansrow < x[row[i]] - sa[{row[i], idxc}]){
            idxr = row[i];
            ansrow = max(ansrow, x[row[i]] - sa[{row[i], idxc}]);
        }
    }
    ans = max(ans, anscol + ansrow);
    // cout << anscol + ansrow << endl;
    // cout << idxr << " " << idxc << endl;
    // cout << ansrow <<" "<< anscol <<" "<< sa[{idxr, idxc}] << endl;
    cout << ans;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}