#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct State {
    ll cost; int u, k_used;
    bool operator>(const State& other) const { return cost > other.cost; }
};

struct Parent {
    int u, k_used;
    bool discounted;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, ll>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, INF));
    // parent[node][k_used] stores how we got to this specific state
    vector<vector<Parent>> parent(n + 1, vector<Parent>(k + 1, {-1, -1, false}));
    
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        State curr = pq.top(); pq.pop();
        if (curr.cost > dist[curr.u][curr.k_used]) continue;

        for (auto& edge : adj[curr.u]) {
            int v = edge.first; ll w = edge.second;

            // 1. Regular Move
            if (dist[curr.u][curr.k_used] + w < dist[v][curr.k_used]) {
                dist[v][curr.k_used] = dist[curr.u][curr.k_used] + w;
                parent[v][curr.k_used] = {curr.u, curr.k_used, false};
                pq.push({dist[v][curr.k_used], v, curr.k_used});
            }

            // 2. Discounted Move
            if (curr.k_used < k) {
                if (dist[curr.u][curr.k_used] + (w / 2) < dist[v][curr.k_used + 1]) {
                    dist[v][curr.k_used + 1] = dist[curr.u][curr.k_used] + (w / 2);
                    parent[v][curr.k_used + 1] = {curr.u, curr.k_used, true};
                    pq.push({dist[v][curr.k_used + 1], v, curr.k_used + 1});
                }
            }
        }
    }

    // Find which layer at node N has the minimum distance
    int best_k = 0;
    for (int i = 1; i <= k; i++) {
        if (dist[n][i] < dist[n][best_k]) best_k = i;
    }

    if (dist[n][best_k] == INF) {
        cout << "No path found" << endl;
        return 0;
    }

    // Backtrack to find the path
    vector<string> path_steps;
    int curr_u = n, curr_k = best_k;

    while (curr_u != -1) {
        Parent p = parent[curr_u][curr_k];
        if (p.u == -1) {
            path_steps.push_back("Start at node " + to_string(curr_u));
            break;
        }
        string status = p.discounted ? " (DISCOUNTED)" : " (Full Price)";
        path_steps.push_back("Node " + to_string(curr_u) + status);
        curr_u = p.u;
        curr_k = p.k_used;
    }

    reverse(path_steps.begin(), path_steps.end());
    for (const string& s : path_steps) cout << s << endl;
    cout << "Total Cost: " << dist[n][best_k] << endl;

    return 0;
}