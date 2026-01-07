ll tolls[n + 1]; // The cost to enter each city

for (auto& neighbor : adj[u]) {
    int v = neighbor; 
    ll t_v = tolls[v]; // Cost is associated with the node v

    // Option 1: No discount
    if (dist[u][j] + t_v < dist[v][j]) {
        dist[v][j] = dist[u][j] + t_v;
        pq.push({dist[v][j], v, j});
    }

    // Option 2: Discount the city toll
    if (j < k) {
        if (dist[u][j] + (t_v / 2) < dist[v][j + 1]) {
            dist[v][j + 1] = dist[u][j] + (t_v / 2);
            pq.push({dist[v][j + 1], v, j + 1});
        }
    }
}