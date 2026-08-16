#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m;
    cin >> n >> m;
    char mat[n + 1][m + 1], tmp[n + 1][m + 1];
    int maxv = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];
            tmp[i][j] = mat[i][j];
            maxv += (mat[i][j] - '0');
        }
    }
    int idx = 0;
    for(int q = 1; q <= n * m; q++){
        cout << "AKSELERASI 1" << endl;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> tmp[i][j];
                cnt += (tmp[i][j] - '0');
            }
        }
        if(cnt > maxv){
            idx = q;
            maxv = cnt;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    mat[i][j] = tmp[i][j];
                }
            }
        }
    }
    for(int i = 1; i <= idx; i++){
        cout << "AKSELERASI 1" << endl;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> tmp[i][j];
                cnt += (tmp[i][j] - '0');
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mat[i][j] == '1'){
                cout << "EKSPERIMEN " << i << " " << j << endl;
                int x;
                cin >> x;
            }
        }
    }
}