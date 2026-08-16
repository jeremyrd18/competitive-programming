#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e6+3;
vector<int> lama(maxn);
vector<int> adj[maxn];
vector<bool> vis(maxn);
map<string, int> m;

int dfs(int cur) {
    vis[cur] = 1;

    int sum = lama[cur];

    int mex = 0;
    for(auto next : adj[cur]) {
        if(!vis[next]) {
            mex = max(dfs(next), mex);
        }
    }

    return sum + mex;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s,p;cin>>n>>s>>p;

    for(int i = 1; i<=n; i++) {
        cin>>lama[i];
    }

    vector<pair<string,int>> virus;

    for(int i = 0; i<p; i++) {
        string S; cin>>S;
        int k; cin>>k;

        // k itu index
        virus.push_back({ S,k });
    }

    for(int i = 0; i<(n-p); i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    // traverse dari A,B -- > semua s mungkin
    // m[a] = max(m[a], currentmax)
    vector<string> saved;
    for(int i = 0; i<virus.size(); i++) {
        string fir = virus[i].first;
        int time = virus[i].second;

        m[fir] = max(m[fir], dfs(time));
    }

    pair<string,int> ans;
    
    int minim = -1;
    for(auto i : m) {
        string fir = i.first;
        int num = i.second;


        if(num > minim) {
            minim = num;
            ans = {fir, num};
        }
    }

    cout << ans.first << '\n' << ans.second << '\n';
}