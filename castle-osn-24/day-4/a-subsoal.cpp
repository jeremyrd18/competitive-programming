#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>

const int MOD = 1000000007;

void solve(){
    int n, a, b;
    cin >> a >> b >> n;
    if(n == 2 && (a + b) == 2){
        if(a == 1){
            int va, vb;
            cin >> va >> vb;
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 <= va && y2 <= vb){
                cout << 1 << endl;
            }
            else if(y1 <= vb && x2 <= va){
                cout << 1 << endl;
            }
            else if(x1 <= va && x2 <= va){
                cout << 2 << endl;
            }
            else if(y1 <= vb && y2 <= vb){
                cout << 2 << endl;
            }
            else cout << -1 << endl;
        }
        else if(b == 2){
            int b1, b2;
            cin >> b1 >> b2;
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if(y1 <= b1 && y2 <= b2){
                cout << 1 << endl;
            }
            else if(y1 <= b2 && y2 <= b1){
                cout << 1 << endl;
            }
            else if(y1 <= b1 && y2 <= b1){
                cout << 2 << endl;
            }
            else if(y1 <= b2 && y2 <= b2){
                cout << 2 << endl;
            }
            else cout << -1 << endl;
        }
        else{
            int b1, b2;
            cin >> b1 >> b2;
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 <= b1 && x2 <= b2){
                cout << 1 << endl;
            }
            else if(x1 <= b2 && x2 <= b1){
                cout << 1 << endl;
            }
            else if(x1 <= b1 && x2 <= b1){
                cout << 2 << endl;
            }
            else if(x1 <= b2 && x2 <= b2){
                cout << 2 << endl;
            }
            else cout << -1 << endl;
        }
    }
}

signed main(){
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}