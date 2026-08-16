#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;

    vector<pair<int, int> > factors;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            int cntExp = 0;
            while(n % i == 0){
                cntExp++;
                n /= i;
            }
            factors.push_back({i, cntExp});
        }
    }

    if(n > 1){
        factors.push_back({n, 1});
    }

    int ans = factors[0].first;
    int curExp = factors[0].second;

    for(auto [p, a]: factors){
        if(curExp > a){
            ans = p;
            curExp = a;
        }
    }

    cout << ans << endl;
}