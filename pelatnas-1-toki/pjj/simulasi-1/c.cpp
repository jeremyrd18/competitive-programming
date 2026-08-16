//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;

void solve(){
    int n, k, d;
    cin >> n >> k >> d;
    string s;
    cin >> s;
    queue<pair<int, vector<int> >> q;
    q.push({1, {}});
    vector<int> ans(n + 3, 0);
    int cnt = 0;
    while(!q.empty()){
        int idx = q.front().first;
        vector<int> a = q.front().second;
        q.pop();
        if(a.size() == k){
            for(auto x : a){
                ans[x]++;
            }
            cnt++;
            continue;
        }
        if(idx > n){
            continue;
        }
        q.push({idx + 1, a});
        if(s[idx - 1] == 'o'){
            vector<int> b = a;
            b.push_back(idx);
            q.push({idx + d + 1, b});
        }
    }
    bool ada = 0;
    if(cnt == 0){
        cout << -1 << endl;
    }
    for(int i = 1; i <= n; i++){
        if(ans[i] == cnt){
            cout << i << endl;
            ada = 1;
        }
    }
    if(!ada) cout << -1 << endl;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}