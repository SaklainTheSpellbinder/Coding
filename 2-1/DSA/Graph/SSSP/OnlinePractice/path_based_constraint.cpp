// dist[node][coupons_used][last_was_discounted]
vector<vector<vector<ll>>> dist(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, INF)));

while (!pq.empty()) {
    auto curr = pq.top(); pq.pop();
    ll d = curr.d; int u = curr.u; int j = curr.j; int last = curr.last;

    if (d > dist[u][j][last]) continue;

    for (auto& e : adj[u]) {
        int v = e.second; ll w = e.first;

        // Option 1: Pay full price (Always allowed)
        // This resets 'last' to 0 for the next node
        if (dist[u][j][last] + w < dist[v][j][0]) {
            dist[v][j][0] = dist[u][j][last] + w;
            pq.push({dist[v][j][0], v, j, 0});
        }

        // Option 2: Use discount
        // ONLY allowed if last == 0 and we have coupons
        if (last == 0 && j < k) {
            if (dist[u][j][0] + w/2 < dist[v][j+1][1]) {
                dist[v][j+1][1] = dist[u][j][0] + w/2;
                pq.push({dist[v][j+1][1], v, j+1, 1});
            }
        }
    }
}