#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;
int n, m, k;
vector<int> adj[N], g, jaw;
int b[N];
bool vis[N];

void dfs(int x){
    jaw.push_back(b[x]);
    vis[x] = 1;
    for(auto v : adj[x]){
        if(!vis[v]){
             dfs(v);
        }
    }
}

signed main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> b[i + 1];
        vis[i + 1] = 0;
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        g.push_back(x);
    }
    // sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            sort(jaw.begin(), jaw.end());
            if(jaw.size() % 2 == 1){
                int med = jaw[jaw.size() / 2];
                int ub = upper_bound(g.begin(), g.end(), med) - g.begin();
                int temp = 1e18;
                if(ub != m){
                    int tempp = 0;
                    for(int j = 0; j < jaw.size(); j++){
                        tempp += abs(jaw[j] - g[ub]);
                    }
                    temp = min(tempp, temp);
                }
                if(ub != 0){
                    int tempp = 0;
                    for(int j = 0; j < jaw.size(); j++){
                        tempp += abs(jaw[j] - g[ub - 1]);
                    }
                    temp = min(tempp, temp);
                }
                ans += temp;
            }
            else{
                int med = jaw[jaw.size() / 2];
                int ub = upper_bound(g.begin(), g.end(), med) - g.begin();
                int temp = 1e18;
                if(ub != m){
                    int tempp = 0;
                    for(int j = 0; j < jaw.size(); j++){
                        tempp += abs(jaw[j] - g[ub]);
                    }
                    temp = min(tempp, temp);
                }
                if(ub != 0){
                    int tempp = 0;
                    for(int j = 0; j < jaw.size(); j++){
                        tempp += abs(jaw[j] - g[ub - 1]);
                    }
                    temp = min(tempp, temp);
                }
                med = jaw[jaw.size() / 2 - 1];
                ub = upper_bound(g.begin(), g.end(), med) - g.begin();
                if(ub != m){
                    int tempp = 0;
                    for(int j = 0; j < jaw.size(); j++){
                        tempp += abs(jaw[j] - g[ub]);
                    }
                    temp = min(tempp, temp);
                }
                if(ub != 0){
                    int tempp = 0;
                    for(int j = 0; j < jaw.size(); j++){
                        tempp += abs(jaw[j] - g[ub - 1]);
                    }
                    temp = min(tempp, temp);
                }
                ans += temp;
            }
            jaw.clear();
        }
    }
    cout << ans << endl;
}