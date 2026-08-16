#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, x;
vector<ll> cor(100005), val(100005), prefVal(100005);

ll distance(ll a, ll b){
    return abs(a - b) + min(abs(a - x), abs(b-x));
}

int main(){
	cin >> n >> k >> x;
    for(ll i = 1; i<=n; i++){
        cin>>cor[i];
    }
    ll temp1 = 0;
    prefVal[0] = 0;
    for(ll i = 1; i<=n; i++){
        cin >> val[i];
        temp1+= val[i];
        prefVal[i] = temp1;
    }
    ll pos = 1;
    ll ans = 0;
    for(ll i = 1; i<=n; i++){
        if(abs(cor[pos] - x) > k){
            pos++;
        }
        while( i<=n && pos<=n && distance(cor[pos], cor[i]) <= k ){
            ans = max(ans, prefVal[pos] - prefVal[i-1]);
            pos++;
        }
    }
    cout << ans << endl;
}