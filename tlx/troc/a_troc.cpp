#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN], timer;
bool used[MAXN];
vector<int> articulation_points;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (used[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                articulation_points.push_back(v);
            }
            children++;
        }
    }
    if (p == -1 && children > 1) {
        articulation_points.push_back(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    timer = 0;
    fill(begin(used), end(used), false);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    sort(articulation_points.begin(), articulation_points.end());
    articulation_points.erase(unique(articulation_points.begin(), articulation_points.end()), articulation_points.end());
    
    cout << articulation_points.size() << endl;
    
    return 0;
}
