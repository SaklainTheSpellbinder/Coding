#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct State {
    long long cost;
    int u, used;
    bool operator>(const State& other) const { return cost > other.cost; }
};

// K-Layer Dijkstra
vector<vector<long long>> runKDijkstra(int n, int k, int src, const vector<vector<pair<int, int>>>& adj) {
    vector<vector<long long>> dist(n + 1, vector<long long>(k + 1, INF));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[src][0] = 0;
    pq.push({0, src, 0});

    while (!pq.empty()) {
        State curr = pq.top(); pq.pop();
        if (curr.cost > dist[curr.u][curr.used]) continue;

        for (auto& edge : adj[curr.u]) {
            int v = edge.first;
            int w = edge.second;

            // Option 1: No coupon
            if (dist[curr.u][curr.used] + w < dist[v][curr.used]) {
                dist[v][curr.used] = dist[curr.u][curr.used] + w;
                pq.push({dist[v][curr.used], v, curr.used});
            }

            // Option 2: Use coupon (if budget allows)
            if (curr.used < k) {
                if (dist[curr.u][curr.used] + (w / 2) < dist[v][curr.used + 1]) {
                    dist[v][curr.used + 1] = dist[curr.u][curr.used] + (w / 2);
                    pq.push({dist[v][curr.used + 1], v, curr.used + 1});
                }
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Run layered Dijkstra for both legs
    vector<vector<long long>> out = runKDijkstra(n, k, 1, adj);
    vector<vector<long long>> ret = runKDijkstra(n, k, n, adj);

    long long min_round_trip = INF;

    // Distribute K coupons: 'i' for outbound, 'k-i' for return
    for (int i = 0; i <= k; i++) {
        int j = k - i;
        if (out[n][i] != INF && ret[1][j] != INF) {
            min_round_trip = min(min_round_trip, out[n][i] + ret[1][j]);
        }
    }

    if (min_round_trip >= INF) cout << -1 << endl;
    else cout << min_round_trip << endl;
}