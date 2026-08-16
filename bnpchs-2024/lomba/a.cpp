#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    string s[n + 1];
    string tmp = "";
    for(int i = 0; i < m; i++){
        tmp += '*';
    }
    // cout << tmp << endl;
    s[0] = tmp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char x;
            cin >> x;
            s[i] += x;
            if(j >= l && j <= r){
                s[i - 1][j - 1] = x;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        if(i >= l && i <= r){
            s[n][i - 1] = '*';
        }
    }
    for(int i = 0; i <= n; i++){
        cout << s[i] << endl;
    }
}