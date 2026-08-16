//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1e9 + 7;

void solve(){
    int n, d;
    cin >> n >> d;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    int vis[n] = {0};
    for(int i = 0; i<n; i++){
        if(a[i] == 1){
            int j = i;
            while(a[j] == 1 && vis[j] == 0){
                vis[j] = 1;
                j += d;
                j %= n;
                if(j == i){
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    memset(vis, 0, sizeof (vis));
    int ans = 0;
    map<int,int> mp;
    for(int i = 0; i<n; i++){
        if(a[i] == 1){
            int now = i;
            int cnt = 0;
            int yes = 0;
            while(a[now] == 1 && vis[now] == 0){
                vis[now] = 1;
                now += d;
                now %= n;
                cnt++;
                if(vis[now] == 1){
                    mp[i] = mp[now] + cnt;
                    yes = 1;
                }
            }
            if(yes == 0) mp[i] = cnt;
            ans = max(ans, mp[i]);
        }
    }
    cout << ans << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}