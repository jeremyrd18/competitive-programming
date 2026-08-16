//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;
int vis[1000003];

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, vector<int> > gen, gan;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(i % 2 == 0){
            gen[a[i]].push_back(i);
        }
        else{
            gan[a[i]].push_back(i);
        }
    }
    int ans = (k/2)*(n-k+1);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i<n; i+=2){
        for(auto x : gen[a[i]]){
            if(vis[a[i]] == 1) continue;
            vis[a[i]] = 1;
            int l = 0, r = 1;
            while(r < sizeof x){
                if(x[r] - x[l] > k){
                    l++;
                }
                else{
                    r++;
                    ans -= 1;
                }
            }
        }
    }
    memset(vis, 0, sizeof vis);
    for(int i = 1; i<n; i+=2){
        for(auto x : gan[a[i]]){
            if(vis[a[i]] == 1) continue;
            vis[a[i]] = 1;
            int l = 0, r = 0;
            while(r < sizeof x){
                if(r - l > k){
                    l++;
                }
                else{
                    r++;
                    ans -= 1;
                }
            }
        }
    }
    cout << ans;
}

signed main(){
	int t;
    t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
}