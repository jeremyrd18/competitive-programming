#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 1000000007, maxn = 0;

void solve(){
    int x = rand();
    random_device rd; 
    mt19937 g(rd());
    int n;
    cin >> n;
    cout << n << endl;
    for(int i = 0; i < n; i++){
        x = rand();
        cout << x % (n + 1) << " ";
    }
}

signed main(){
    gas
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}