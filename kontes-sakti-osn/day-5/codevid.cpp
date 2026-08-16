//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int n, m;

int stringtoidx(string s){
    int tmp = 1, res = 0;
    for(int i = 0; i < n; i++){
        res += tmp * (s[i] - '0');
        tmp *= 2;
    }
    return res;
}

void solve(){
    cin >> n >> m;
    string s;
    cin >> s;
    int st = stringtoidx(s);
    vector<int> a(m), b(m), day(m);
    for(int i = 0; i < m; i++){
        string x, y;
        cin >> day[i];
        cin >> x >> y;
        a[i] = stringtoidx(x);
        b[i] = stringtoidx(y);
    }
    const int MAXN = 1e15;
    vector<int> dis((1 << n) + 3, MAXN);
    vector<bool> vis((1 << n) + 3, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, st});
    dis[st] = 0;
    
    while(!pq.empty()){
        int len = pq.top().first;
        int nd = pq.top().second;
        pq.pop();

        if(vis[nd] == true) continue;
        if(dis[nd] < len) continue;
        vis[nd] = true;
        for(int i = 0; i < m; i++){
            int cur = nd;
            for(int j = 0; j < n; j++){
                if((nd & (1 << j)) == (a[i] & (1 << j))){
                    cur -= nd & (1 << j);
                }
            }
            cur |= b[i];
            if(vis[cur] == true) continue; 
            if(len + day[i] > dis[cur]) continue;
            dis[cur] = len + day[i];
            pq.push({dis[cur], cur});
        }
    }
    if(dis[0] != MAXN){
        cout << dis[0] << endl;
    }
    else cout << -1 << endl;
}

signed main(){
	int t;
    cin >> t;
    for(int i = 1; i<=t; i++){
        solve();
    }
}