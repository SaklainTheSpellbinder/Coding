#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

struct Edge {
    int a, b;
    ll weight;
    int id; // Track original ID to facilitate removal
};

int main() {
    FAST_IO;
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    while (true) {
        vector<ll> dist(n + 1, 0);
        vector<int> parent(n + 1, -1);
        int x = -1;

        // Bellman-Ford to find a negative cycle
        for (int i = 1; i <= n; i++) {
            x = -1;
            for (auto& e : edges) {
                if (dist[e.a] + e.weight < dist[e.b]) {
                    dist[e.b] = dist[e.a] + e.weight;
                    parent[e.b] = e.a;
                    x = e.b;
                }
            }
        }

        // If no node was relaxed in the N-th iteration, no negative cycles remain
        if (x == -1) break;

        // Move into the cycle
        for (int i = 0; i < n; i++) x = parent[x];

        // Identify the cycle edges
        vector<int> cycle_nodes;
        int v = x;
        while (true) {
            cycle_nodes.push_back(v);
            if (v == x && cycle_nodes.size() > 1) break;
            v = parent[v];
        }
        reverse(cycle_nodes.begin(), cycle_nodes.end());

        // We will remove the edge that closes the cycle: (cycle_nodes[last-1] -> cycle_nodes[last])
        int u_rem = cycle_nodes[0];
        int v_rem = cycle_nodes[1];

        cout << "Found negative cycle: ";
        for(int node : cycle_nodes) cout << node << " ";
        cout << "\nRemoving edge: " << u_rem << " -> " << v_rem << endl;

        // Remove the edge from the vector
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->a == u_rem && it->b == v_rem) {
                edges.erase(it);
                break; 
            }
        }
    }

    cout << "All negative cycles removed." << endl;
    return 0;
}