struct Edge {
    int to;
    ll weight;
    bool is_fixed; // true if the discount cannot be applied
};

// ... inside the Dijkstra loop ...
for (auto& edge : adj[u]) {
    int v = edge.to;
    ll w = edge.weight;
    
    // 1. Standard Transition (Same Layer)
    // Works for both fixed and discountable edges
    if (dist[u][j] + w < dist[v][j]) {
        dist[v][j] = dist[u][j] + w;
        pq.push({dist[v][j], v, j});
    }

    // 2. Discount Transition (Move to j+1)
    // ONLY works if the edge is NOT fixed and we have discounts left
    if (!edge.is_fixed && j < k) {
        ll discounted_w = w / 2; // or w * 0.8 for percentage
        if (dist[u][j] + discounted_w < dist[v][j + 1]) {
            dist[v][j + 1] = dist[u][j] + discounted_w;
            pq.push({dist[v][j + 1], v, j + 1});
        }
    }
}


struct Edge {
    int to;
    ll weight;
    int type; // 0: Standard, 1: Fixed, 2: Immune, 3: Mandatory
};

// Inside Dijkstra:
for (auto& e : adj[u]) {
    // Handling Standard & Immune & Fixed (Staying in same layer)
    if (e.type != 3) { // If not mandatory
        if (dist[u][j] + e.weight < dist[v][j]) {
            dist[v][j] = dist[u][j] + e.weight;
            pq.push({dist[v][j], v, j});
        }
    }

    // Handling Standard & Mandatory (Moving to next layer)
    if ((e.type == 0 || e.type == 3) && j < k) {
        ll cost = (e.type == 3) ? (e.weight / 2) : (e.weight / 2); 
        if (dist[u][j] + cost < dist[v][j + 1]) {
            dist[v][j + 1] = dist[u][j] + cost;
            pq.push({dist[v][j + 1], v, j + 1});
        }
    }
}