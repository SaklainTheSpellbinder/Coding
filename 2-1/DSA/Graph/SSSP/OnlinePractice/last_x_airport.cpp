#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int main() {
    int n, m, x_last;
    cin >> n >> m >> x_last;

    vector<pair<ll, int>> adj[n + 1], rev_adj[n + 1];
    struct RawEdge { int u, v; ll w; };
    vector<RawEdge> edges;

    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        rev_adj[v].push_back({w, u});
        edges.push_back({u, v, w});
    }

    // 1. Forward Dijkstra: No discounts allowed
    vector<ll> dist_start(n + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist_start[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        ll d = pq.top().first; int u = pq.top().second; pq.pop();
        if(d > dist_start[u]) continue;
        for(auto& e : adj[u]) {
            if(dist_start[u] + e.first < dist_start[e.second]) {
                dist_start[e.second] = dist_start[u] + e.first;
                pq.push({dist_start[e.second], e.second});
            }
        }
    }

    // 2. Backward Dijkstra (Reversed Graph): Tracking steps from the end
    // dist_rev[node][steps_from_end]
    vector<vector<ll>> dist_rev(n + 1, vector<ll>(x_last + 1, INF));
    // {distance, {node, steps}}
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq_rev;
    
    dist_rev[n][0] = 0;
    pq_rev.push({0, {n, 0}});

    while(!pq_rev.empty()){
        ll d = pq_rev.top().first;
        int u = pq_rev.top().second.first;
        int s = pq_rev.top().second.second;
        pq_rev.pop();

        if(d > dist_rev[u][s]) continue;
        if(s >= x_last) continue; // Can't go further than X steps back

        for(auto& e : rev_adj[u]) {
            if(dist_rev[u][s] + e.first < dist_rev[e.second][s + 1]) {
                dist_rev[e.second][s + 1] = dist_rev[u][s] + e.first;
                pq_rev.push({dist_rev[e.second][s + 1], {e.second, s + 1}});
            }
        }
    }

    // 3. Final Calculation
    ll ans = dist_start[n]; // Initial shortest path without any discount

    for(auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        ll w = edge.w;

        // Try using the discount on this specific edge (u -> v)
        // This is only valid if v is within X-1 steps of the end
        for(int s = 0; s < x_last; s++) {
            if(dist_start[u] != INF && dist_rev[v][s] != INF) {
                ans = min(ans, dist_start[u] + (w / 2) + dist_rev[v][s]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}