//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    priority_queue<int> pq[n + 3];
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }
    for(int i = 0; i<n; i++){
        pq[a[i]].push(-b[i]);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(pq[i].size() <= 1){
            continue;
        }
        while(pq[i].size() > 1){
            ans -= pq[i].top();
            pq[i].pop();
        }
    }
    cout << ans << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}