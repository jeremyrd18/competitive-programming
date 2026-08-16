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
    vector<int> v;
    vector<int> lens = {120, 1, 10000, 2832, 1873, 99, 234};

    for(int i = 0; i < n; i++){
        v.pb(i);
    }
    shuffle(v.begin(), v.end(), g);
    cout << n << endl;
    
    while(v.size() > 1){
        x = rand() % (n - 1) + 1;
        int y = rand() % 7;
        cout << v[0] + 1 << " " << v[x] + 1 << " " << lens[y] << endl;
        v.erase(v.begin());
        n--;
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