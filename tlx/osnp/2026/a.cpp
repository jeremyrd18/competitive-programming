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
    string s;
    cin >> s;
    int amt_a = 0, amt_b = 0, n = s.size();
    for(int i = 0; i < n; i++){
        amt_a += s[i] == 'A';
        amt_b += s[i] == 'B';
    }
    if(amt_a * 3 >= amt_b){
        cout << amt_b / 3;
    }
    else{
        cout << amt_a + (amt_b - amt_a * 3) / 4;
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