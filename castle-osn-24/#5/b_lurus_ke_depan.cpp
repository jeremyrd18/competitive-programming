#include <iostream>
#include <algorithm>
using namespace std;
int va[2002], vb[2002], a[2002], b[2002], mat[2002][2002];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> va[i];
        a[i] = va[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> vb[i];
        b[i] = vb[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int cur = __gcd(a[i], b[j]);
            mat[i][j] = cur;
            a[i] /= cur;
            b[j] /= cur;
        }
    }
    for(int i = 1; i <= n; i++){
        int tmp = 1;
        for(int j = 1; j <= m; j++){
            tmp *= mat[i][j];
        }
        // cout << tmp << " ";
        if(tmp != va[i]){
            cout << -1 << endl << endl;
            return;
        }
    }
    for(int i = 1; i <= m; i++){
        int tmp = 1;
        for(int j = 1; j <= n; j++){
            tmp *= mat[j][i];
        }
        // cout << tmp << " ";
        if(tmp != vb[i]){
            cout << -1 << endl << endl;
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        solve();
    }
}