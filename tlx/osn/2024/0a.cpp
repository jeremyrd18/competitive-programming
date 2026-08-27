#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int minv = 200005, maxv = -1;
    int tot = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        minv = min(x, minv + 1);
        maxv = max(x, maxv + 1);
        tot += (x + i);
        cout << minv << " " << maxv << " ";
        double rata = (double)tot/(i + 1);
        cout << fixed << setprecision(4) << rata << endl;
    }
}