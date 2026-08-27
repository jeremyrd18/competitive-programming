#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

signed main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int cnt = 1;
        while(x % 2 == 0){
            x /= 2;
            cnt *= 2;
        }
        a.push_back({x, cnt});
    }

    sort(a.rbegin(), a.rend());

    int ans = 0;

    for(auto x: a){
        if(k >= x.se){
            ans += x.fi * x.se;
            k -= x.se;
        }
        else{
            ans += x.fi * k;
            break;
        }
    }
    
    cout << ans << endl;
}