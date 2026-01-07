#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<ll, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    // Max-heaps to store the k shortest distances to each node
    priority_queue<ll> best_costs[n + 1];
    
    // Min-heap for Dijkstra: {distance, node}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 1});
    best_costs[1].push(0);

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If this distance is worse than the k-th best distance we've 
        // already processed for node u, we can safely ignore it.
        if (d > best_costs[u].top()) continue;

        for (auto& edge : adj[u]) {
            ll w = edge.first;
            int v = edge.second;
            ll new_dist = d + w;

            if (best_costs[v].size() < k) {
                best_costs[v].push(new_dist);
                pq.push({new_dist, v});
            } else if (new_dist < best_costs[v].top()) {
                // We found a better path than the current k-th best
                best_costs[v].pop();
                best_costs[v].push(new_dist);
                pq.push({new_dist, v});
            }
        }
    }

    // The best_costs[n] heap contains the k shortest paths to n.
    // We need to extract them and print them in increasing order.
    vector<ll> ans;
    while (!best_costs[n].empty()) {
        ans.push_back(best_costs[n].top());
        best_costs[n].pop();
    }
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}