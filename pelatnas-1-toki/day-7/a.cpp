#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define gas ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;

const int maxn = 100005;
vi adj[maxn];
int vis[maxn];

bool cycle = 0;

void dfs(int nd){
    if(vis[nd] == 1){
        cycle = 1;
        return;
    }
    vis[nd] = 1;
    for(auto x : adj[nd]){
        dfs(x);
    }
    vis[nd] = 0;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vi ans;
    int indegree[n + 5];
    for(int i = 1; i <= n; i++) ans.pb(i), indegree[i] = 0;
    vi order[m];
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            order[i].pb(x);
        }
    }
    int l = 0, r = m - 1, mid;
    while(l <= r){
        for(int i = 0; i <= n; i++) adj[i].clear();
        cycle = 0;
        mid = (l + r) / 2;
        
        int tmp;
        for(int i = 0; i <= mid; i++){
            int k = order[i].size();
            for(int j = 0; j < k; j++){
                if(j == 0){
                    tmp = order[i][j];
                }
                else{
                    int x = order[i][j];
                    adj[tmp].pb(x);
                    tmp = x;
                    indegree[x]++;
                }
            }
        }
        memset(vis, 0, sizeof vis);
        vi anstmp;
        for(int j = 1; j <= n; j++){
            dfs(j);
        }
        if(cycle){
            r = mid - 1;
            continue;
        }
        priority_queue<int> pq;
        for(int j = 1; j <= n; j++){
            if(indegree[j] == 0) pq.push(-j);
        }
        int udah[n + 5];
        memset(udah, 0, sizeof udah);
        int tmpindg[n + 5];
        for(int i = 1; i <= n; i++){
            tmpindg[i] = indegree[i];
        }
        while(!pq.empty()){
            int curnd = - pq.top();
            pq.pop();
            anstmp.pb(curnd);
            udah[curnd] = 1;
            for(auto x : adj[curnd]){
                if(!udah[x]){
                    tmpindg[x]--;
                    if(tmpindg[x] == 0){
                        pq.push(-x);
                    }
                }
            }
        }
        l = mid + 1;
        ans = anstmp;
        // cout << mid << endl;
        // for(auto x : ans){
        //     cout << x << " ";
        // } cout << endl;
    }
    // cout << mid << endl;
    for(auto x : ans){
        cout << x << " ";
    }
}

signed main(){
    gas
	int t;
    t = 1;
    // cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}