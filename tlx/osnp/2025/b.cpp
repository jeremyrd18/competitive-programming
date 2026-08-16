#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, panjang, lebar;
    cin >> n >> panjang >> lebar;

    int l = 0, r = 2e9, mid, ans = 0;

    while(l <= r){
        mid = (l + r) / 2;
        if((mid/panjang) * (mid/lebar) < n) l = mid + 1;
        else{
            ans = mid;
            r = mid - 1;
        }
    }

    cout << ans;
}