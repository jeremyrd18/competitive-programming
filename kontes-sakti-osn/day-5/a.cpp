#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while (t--)
    {
    int n, k; 
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    int j = 0, x = 1;
    while (k--) {
        while (j < n && a[j] <= x+j)
            j++;
        x += j;
    }
 
    cout << x << endl;
    }
}
