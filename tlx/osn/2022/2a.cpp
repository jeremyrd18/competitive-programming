#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second

int n, m, q;
int par[100005], vis[100005], sz[100005];
vector<pair<int, int> > h;
vector<int> adj[100005];
vector<int> vs[100005];

pair<int, int> dfs(int x){
    pair<int, int> minval = {h[x].fi, x};
    vis[x] = 1;
    for(auto i : adj[x]){
        if(!vis[i]){
            pair<int, int> tmp = dfs(i);
            if(tmp.fi < minval.fi){
                minval = tmp;
            }
            // cout << "a" << minval << endl;
        }
    }
    return minval;
}

// DSU

int getroot(int x){
    if(par[x] == x) return x;
    return par[x] = getroot(par[x]);
}

void merge(int a, int b){
    par[getroot(a)] = getroot(b);
}

bool cek(int a, int b){return getroot(a) == getroot(b);}

bool sortbysize(int a, int b){
    return sz[par[a]] < sz[par[b]];
}

signed main(){
    memset(vis, 0, sizeof vis);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        par[i] = i;
        sz[i] = 0;
        int x;
        cin >> x;
        h.push_back({x, i});
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(!cek(a, b)){
            // cout << a + 1 << " " << b + 1 << endl;
            merge(a, b);
        }
    }
    // cout << endl;
    // int alr = 0;
    // for(int i = 0; i < n; i++){
    //     if(par[i] == i){
    //         alr++;
    //     }
    // }
    // if(alr == 1){
    //     cout << 0 << endl;
    //     return 0;
    // }
    int c = 0;
    vector<pair<int, int> > comp;
    vector<int> pakai;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(adj[i].empty()){
            c++;
            comp.push_back({h[i].fi, i});
            sum += comp.back().fi;
            pakai.push_back(i);
        }
        else{
            if(!vis[i]){
                c++;
                pair<int, int> temp = dfs(i);
                comp.push_back(temp);
                sum += comp.back().fi;
                pakai.push_back(temp.se);
                // cout << sum << endl;
            }
        }
    }
    if(c == 1){
        cout << 0 << endl;
        return 0;
    }
    if(2 * (c - 1) > n){
        cout << -1 << endl;
        return 0;
    }
    int cur = c;
    sort(comp.rbegin(), comp.rend());
    sort(h.rbegin(), h.rend());
    // cout << sum << endl;
    while(cur < 2 * (c - 1)){
        if(!comp.empty()){
            if(comp.back().se == h.back().se){
                comp.pop_back();
                h.pop_back();
            }
            else{
                sum += h.back().fi;
                pakai.push_back(h.back().se);
                h.pop_back();
                cur++;
            }
        }
        else{
            sum += h.back().fi;
            pakai.push_back(h.back().se);
            h.pop_back();
            cur++;
        }
        // cout << sum << endl;
    }
    cout << sum << endl;
    if(q){
        cout << c - 1 << endl;
        for(int i : pakai){
            sz[getroot(par[i])]++;
        }
        priority_queue<int> sz1;
        priority_queue<pair<int, vector<int> > > sz2;
        set<int> pars;
        // cout << getroot(par[12]) << " " << getroot(par[13]);
        for(int i : pakai){
            if(sz[getroot(par[i])] == 1){
                // cout << i + 1 << " ";
                sz1.push(i);
            }
            else{
                pars.insert(getroot(par[i]));
                vs[getroot(par[i])].push_back(i);
            }
        }
        // cout << endl;
        for(int i : pars){
            // cout << i  << endl;
            vector<int> tempe;
            // cout << i + 1 << " ";
            for(auto xx : vs[i]){
                // cout << xx + 1 << " ";
                tempe.push_back(xx);
            }
            // cout << endl;
            sz2.push({sz[i], tempe});
        }
        while(true){
            if(sz1.empty()){
                break;
            }
            if(sz2.empty()){
                // cout << "dusu ";
                cout << sz1.top() + 1 << " ";
                sz1.pop();
                cout << sz1.top() + 1 << endl;
                sz1.pop();
                continue;
            }
            int cursize = sz2.top().fi;
            vector<int> curv = sz2.top().se;
            sz2.pop();
            cout << curv.back() + 1 << " " << sz1.top() + 1 << endl;
            sz1.pop();
            cursize--;
            curv.pop_back();
            if(cursize == 1){
                sz1.push(curv[0]);
            }
            else sz2.push({cursize, curv});
        }
    }
}