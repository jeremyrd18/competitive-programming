#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, w, b, x;
    cin >> n >> w >> b >> x;
    int c, e;
    cin >> c >> e;
    if(e == 0) cout << c << endl;
    if(c == 0) cout << 0 << endl;
    else cout << min(b/e, c) << endl;
}