#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge {
    int to, length;
};

vector<vector<Edge>> tree;
vector<int> dist;

void bfs(int start, int& farthest_node, int& max_distance) {
    int n = tree.size();
    dist.assign(n, -1);
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (const auto& edge : tree[node]) {
            if (dist[edge.to] == -1) {
                dist[edge.to] = dist[node] + edge.length;
                q.push(edge.to);
            }
        }
    }
    
    max_distance = 0;
    for (int i = 0; i < n; ++i) {
        if (dist[i] > max_distance) {
            max_distance = dist[i];
            farthest_node = i;
        }
    }
}

signed main() {
    int N;
    cin >> N;
    
    tree.resize(N);
    int total_length = 0;
    
    for (int i = 0; i < N - 1; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        --A; --B; // To convert to 0-based indexing
        tree[A].push_back({B, C});
        tree[B].push_back({A, C});
        total_length += C;
    }

    int farthest_node = 0, max_distance = 0;
    
    // First BFS to find one endpoint of the diameter
    bfs(0, farthest_node, max_distance);
    
    // Second BFS from the farthest_node found to find the diameter
    int temp = farthest_node;
    farthest_node = 0;
    bfs(temp, farthest_node, max_distance);
    
    // The minimum travel distance is twice the total length of edges minus the diameter
    int result = 2 * total_length - max_distance;
    
    cout << total_length << " " << max_distance;
    return 0;
}