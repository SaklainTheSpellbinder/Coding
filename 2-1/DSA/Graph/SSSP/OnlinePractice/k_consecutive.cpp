// dist[node][coupons_activated][remaining_steps]
// Assume X is the duration of one coupon
vector<vector<vector<ll>>> dist(n + 1, vector<vector<ll>>(k + 1, vector<ll>(x + 1, INF)));

while (!pq.empty()) {
    auto curr = pq.top(); pq.pop();
    ll d = curr.d; int u = curr.u; int j = curr.j; int rem = curr.rem;

    if (d > dist[u][j][rem]) continue;

    for (auto& e : adj[u]) {
        int v = e.second; ll w = e.first;

        if (rem > 0) {
            // Use existing power-up
            if (dist[u][j][rem] + w/2 < dist[v][j][rem - 1]) {
                dist[v][j][rem - 1] = dist[u][j][rem] + w/2;
                pq.push({dist[v][j][rem - 1], v, j, rem - 1});
            }
        } else {
            // No power-up active
            // 1. Just walk normally
            if (dist[u][j][0] + w < dist[v][j][0]) {
                dist[v][j][0] = dist[u][j][0] + w;
                pq.push({dist[v][j][0], v, j, 0});
            }
            // 2. Activate a new power-up
            if (j < k) {
                if (dist[u][j][0] + w/2 < dist[v][j + 1][x - 1]) {
                    dist[v][j + 1][x - 1] = dist[u][j][0] + w/2;
                    pq.push({dist[v][j + 1][x - 1], v, j + 1, x - 1});
                }
            }
        }
    }
}