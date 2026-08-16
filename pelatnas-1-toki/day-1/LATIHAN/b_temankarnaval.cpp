#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

string tanya(int a, int b){
    cout << "pantau " << a << " " << b << endl;
    string x;
    cin >> x;
    return x;
}

void tmb(int x){
    cout << "tembak " << x << endl;
}

void solve(){
    string s;
    cin >> s;
    int pm, vm;
    cin >> pm >> vm;
    int l = 0, r = vm, mid;
    int de = 1;
    int ans = -1;
    int awal;
    // if(awal == 0){
        while(l <= r){
            mid = (l + r) / 2;
            if(tanya(awal + l * de, awal + mid * de) == "YA"){
                ans = mid;
                r = mid;
                if(l == r){
                    break;
                }
            }
            else{
                l = mid + 1;
            }
            de++;
        }
        tmb(awal + ans * (de + 1));
    // }
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