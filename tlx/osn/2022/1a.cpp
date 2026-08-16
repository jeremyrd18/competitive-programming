#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, q;
    cin >> n >> q;
    while(q--){
        int x; cin >> x;
        int a = (x % (n + 1)), b = (x % (n + 2)), c = (x / (n + 1)), d = (x / (n + 2));
        if(x > n * (n + 1) / 2) cout << 0 << endl; // over the sum
        else if(x <= n || x == n * (n + 1) / 2) cout << 1 << endl; // only one possible answer for both case
        else if(a == 0) cout << (n / 2) + 1 - c << endl;
        else if(b == 0) cout << ((n - 1) / 2) - d + 1<< endl; 
        else if(a > c && (n + 1) / 2 >= a) cout << 1 << endl; // THIS TOO
        else if((n + 1) / 2 < b && n >= b + d) cout << 1 << endl; // IDK THIS BRO
        else cout << 0 << endl;
    }
}