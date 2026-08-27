#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 100005;

int n, w[maxn], d[maxn], dp[maxn][2];
vector<int> adj[maxn];

void dfs(int nd){
    dp[nd][1] = w[nd];
    dp[nd][0] = - w[nd];
    
    priority_queue<int> setuju, gasetuju;

    for(auto x : adj[nd]){
        dfs(x);
        
        setuju.push({dp[x][0] - dp[x][1]});
        gasetuju.push({dp[x][1] - dp[x][0]});

        dp[nd][1] += dp[x][1];
        dp[nd][0] += dp[x][0];
    }

    for(int i = 0; i < d[nd]; i++){
        dp[nd][1] += setuju.top();
        dp[nd][0] += gasetuju.top();
        setuju.pop();
        gasetuju.pop();
    }
}

signed main(){
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> d[i];

    dfs(1);
    cout << max(dp[1][1], dp[1][0]) << endl;
}