#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

const int n = 256;

void solve(){
    cout << "TANYA 128" << endl;
    for(int i = 1; i <= 128; i++){
        cout << i << " ";
    } cout << endl;
    int x;
    cin >> x;
    if(x == 0){
        cout << "TANYA 128" << endl;
        for(int i = 129; i <= 256; i++){
            cout << i << " ";
        } cout << endl;
        cin >> x;
        cout << "TANYA 255" << endl;
        for(int i = 1; i < 129 - x; i++){
            cout << i << " ";
        }
        for(int i = 129 - x + 1; i <= 256; i++){
            cout << i << " ";
        } cout << endl;
        int y;
        cin >> y;
        cout << "JAWAB ";
        if(y == 1){
            cout << 129 - x << endl;
        }
        else cout << x << endl;
    }
    else{
        cout << "TANYA 255" << endl;
        for(int i = 1; i < 128 + x; i++){
            cout << i << " ";
        }
        for(int i = 128 + x + 1; i <= 256; i++){
            cout << i << " ";
        } cout << endl;
        int y;
        cin >> y;
        cout << "JAWAB ";
        if(y == 1){
            cout << 128 + x << endl;
        }
        else cout << 257 - x << endl;
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