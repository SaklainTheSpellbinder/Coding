#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

// Reusable Dijkstra function for state-space (K layers)
vector<vector<ll>> get_distances(int start_node, int n, int k, vector<pair<ll, int>> adj[]) {
    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, INF));
    // {distance, {node, discounts_used}}
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;

    dist[start_node][0] = 0;
    pq.push({0, {start_node, 0}});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second.first;
        int used = pq.top().second.second;
        pq.pop();

        if (d > dist[u][used]) continue;

        for (auto& e : adj[u]) {
            ll weight = e.first;
            int v = e.second;

            // Option 1: Normal move (no discount used on this edge)
            if (dist[u][used] + weight < dist[v][used]) {
                dist[v][used] = dist[u][used] + weight;
                pq.push({dist[v][used], {v, used}});
            }

            // Option 2: Use a discount on this edge
            if (used < k) {
                if (dist[u][used] + (weight / 2) < dist[v][used + 1]) {
                    dist[v][used + 1] = dist[u][used] + (weight / 2);
                    pq.push({dist[v][used + 1], {v, used + 1}});
                }
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<ll, int>> adj[n + 1];
    vector<pair<ll, int>> adj_rev[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj_rev[v].push_back({w, u}); // Build the reversed graph
    }

    // Mandatory edge details (example: from node U to node V with weight W)
    int mand_u, mand_v; ll mand_w;
    cin >> mand_u >> mand_v >> mand_w;

    // Pass 1: Distance from Start to everywhere
    vector<vector<ll>> dist_from_start = get_distances(1, n, k, adj);

    // Pass 2: Distance from End to everywhere (using reversed graph)
    vector<vector<ll>> dist_to_end = get_distances(n, n, k, adj_rev);

    ll ans = INF;

    // Solve by checking all ways to split K discounts
    // i = discounts used before mandatory edge
    // j = discounts used after mandatory edge
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k - i; j++) {
            
            // Case A: Don't discount the mandatory edge itself
            if (dist_from_start[mand_u][i] != INF && dist_to_end[mand_v][j] != INF) {
                ans = min(ans, dist_from_start[mand_u][i] + mand_w + dist_to_end[mand_v][j]);
            }

            // Case B: Discount the mandatory edge (needs 1 available coupon)
            if (i + j + 1 <= k) {
                if (dist_from_start[mand_u][i] != INF && dist_to_end[mand_v][j] != INF) {
                    ans = min(ans, dist_from_start[mand_u][i] + (mand_w / 2) + dist_to_end[mand_v][j]);
                }
            }
        }
    }

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}