bool is_refill_node[n + 1]; // Marked true for specific nodes

while (!pq.empty()) {
    auto curr = pq.top(); pq.pop();
    ll d = curr.d; int u = curr.u; int j = curr.used;

    if (d > dist[u][j]) continue;

    for (auto& e : adj[u]) {
        int v = e.second; ll w = e.first;

        // 1. Regular Move: Full Price
        if (dist[u][j] + w < dist[v][j]) {
            dist[v][j] = dist[u][j] + w;
            
            // If V is a refill node, we can immediately reset to 0 used
            if (is_refill_node[v]) {
                if (dist[v][j] < dist[v][0]) {
                    dist[v][0] = dist[v][j];
                    pq.push({dist[v][0], v, 0});
                }
            }
            pq.push({dist[v][j], v, j});
        }

        // 2. Regular Move: Use Coupon
        if (j < k) {
            if (dist[u][j] + w/2 < dist[v][j + 1]) {
                dist[v][j + 1] = dist[u][j] + w/2;
                
                // If V is a refill node, we can reset this state too!
                if (is_refill_node[v]) {
                    if (dist[v][j+1] < dist[v][0]) {
                        dist[v][0] = dist[v][j+1];
                        pq.push({dist[v][0], v, 0});
                    }
                }
                pq.push({dist[v][j + 1], v, j + 1});
            }
        }
    }
}