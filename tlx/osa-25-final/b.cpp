#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int a[n + 5], ans[n + 5], pos[n + 5];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans[i] = i;
        pos[i] = i;
        ans[pos[a[i]]] = i;
        ans[pos[i]] = a[i];
        pos[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}