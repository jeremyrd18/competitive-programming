#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    for(int i = 1; i * i <= n; i++){
        if(i * i >= n && (i * i) % n == 0){
            cout << min(i, (i * i) / n) << endl;
            return 0;
        }
    }
    cout << n << endl;
}