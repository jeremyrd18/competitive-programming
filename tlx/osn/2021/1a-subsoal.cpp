#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;

int pow_mod(int x, int p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        int y = pow_mod(x, p / 2);
        return (y * y) % mod;
    }
    return (x * pow_mod(x, p - 1)) % mod;
}

signed main(){
    int n;
    cin >> n;
    cout << pow_mod(2, n - 1) % mod;
}