#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e17; // Use a value smaller than LLONG_MAX to avoid overflow

struct Edge {
    int u, v;
    ll w;
};

// Reachability check using BFS
void bfs(int start, vector<int> adj[], vector<bool>& reachable) {
    queue<int> q;
    q.push(start);
    reachable[start] = true;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int neighbor : adj[curr]) {
            if (!reachable[neighbor]) {
                reachable[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<int> adj[n + 1], rev_adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    // Precompute reachability
    vector<bool> from_start(n + 1, false), to_end(n + 1, false);
    bfs(1, adj, from_start);
    bfs(n, rev_adj, to_end);

    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    // Bellman-Ford for N-1 iterations
    for (int i = 1; i < n; i++) {
        for (auto& e : edges) {
            if (dist[e.u] != -INF) {
                dist[e.v] = max(dist[e.v], dist[e.u] + e.w);
            }
        }
    }

    // N-th iteration to detect infinite score
    bool infinite = false;
    for (auto& e : edges) {
        if (dist[e.u] != -INF) {
            if (dist[e.u] + e.w > dist[e.v]) {
                // If this node is part of a path from 1 to N, it's infinite
                if (from_start[e.v] && to_end[e.v]) {
                    infinite = true;
                    break;
                }
                // Even if we don't break, we update to propagate
                dist[e.v] = dist[e.u] + e.w; 
            }
        }
    }

    if (infinite) cout << -1 << endl;
    else cout << dist[n] << endl;

    return 0;
}