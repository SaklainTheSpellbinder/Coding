struct Edge {
    int to;
    ll weight;
    int type; // 0 = Flight, 1 = Bus, 2 = Train
};

// ... inside the Dijkstra loop ...
for (auto& e : adj[u]) {
    int v = e.to;
    ll w = e.weight;
    int t = e.type;

    // Option 1: Standard price (Always available for all types)
    if (dist[u][j] + w < dist[v][j]) {
        dist[v][j] = dist[u][j] + w;
        pq.push({dist[v][j], v, j});
    }

    // Option 2: Use coupon (ONLY if type is 0/Flight)
    if (t == 0 && j < k) {
        if (dist[u][j] + w/2 < dist[v][j+1]) {
            dist[v][j+1] = dist[u][j] + w/2;
            pq.push({dist[v][j+1], v, j+1});
        }
    }
}