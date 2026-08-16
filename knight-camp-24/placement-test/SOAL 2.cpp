//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

int fac(int x, int batas){
    if(x == batas){
        return 1;
    }
    else return x*fac(x-1, batas);
}

int combin(int n, int r){
    int maxo = max(r, n-r), mino = min(r, n-r);
    int ans = fac(n, maxo);
    ans /= fac(mino, mino);
    return ans;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cout << combin(i, j);
            if(j<i){
                cout <<" ";
            }
        }
        cout << endl;
    }
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}