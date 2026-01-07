#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int v;
    long long w;
};

struct State {
    long long cost;
    int u;
    int used; // 0 = false, 1 = true

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

// Standard State-Space Dijkstra
vector<vector<long long>> runDijkstra(int n, int src, const vector<vector<Edge>>& adj) {
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[src][0] = 0;
    pq.push({0, src, 0});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        long long d = curr.cost;
        int u = curr.u;
        int used = curr.used;

        if (d > dist[u][used]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.v;
            long long w = edge.w;

            // Option 1: Normal Travel (Keep current 'used' state)
            if (d + w < dist[v][used]) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }

            // Option 2: Use Coupon (Only if used == 0)
            if (used == 0) {
                if (d + (w / 2) < dist[v][1]) {
                    dist[v][1] = d + (w / 2);
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }
    return dist;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Outbound: From 1 (Tracks shortest normal and shortest discounted)
    vector<vector<long long>> out = runDijkstra(n, 1, adj);
    
    // Return: From N (Tracks shortest normal and shortest discounted)
    vector<vector<long long>> ret = runDijkstra(n, n, adj);

    // Scenario 1: Use coupon on the way there, full price back
    long long case1 = (out[n][1] == INF || ret[1][0] == INF) ? INF : out[n][1] + ret[1][0];

    // Scenario 2: Full price there, use coupon on the way back
    long long case2 = (out[n][0] == INF || ret[1][1] == INF) ? INF : out[n][0] + ret[1][1];

    long long final_ans = min(case1, case2);

    if (final_ans >= INF) cout << -1 << endl;
    else cout << final_ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}