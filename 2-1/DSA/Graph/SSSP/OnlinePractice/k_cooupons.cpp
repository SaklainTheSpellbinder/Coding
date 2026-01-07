#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct State {
    ll cost;
    int u;
    int k_used;

    // Min-heap: priority queue picks the smallest cost
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, ll>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // dist[node][coupons_used]
    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, INF));
    priority_queue<State, vector<State>, greater<State>> pq;

    // Start at node 1 with 0 coupons used
    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        ll d = curr.cost;
        int u = curr.u;
        int used = curr.k_used;

        if (d > dist[u][used]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;

            // 1. Don't use a coupon on this edge
            if (dist[u][used] + w < dist[v][used]) {
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], v, used});
            }

            // 2. Use a coupon on this edge (if available)
            if (used < k) {
                if (dist[u][used] + (w / 2) < dist[v][used + 1]) {
                    dist[v][used + 1] = dist[u][used] + (w / 2);
                    pq.push({dist[v][used + 1], v, used + 1});
                }
            }
        }
    }

    // The answer is the minimum value at node n across all possible coupon counts
    ll ans = INF;
    for (int i = 0; i <= k; i++) {
        ans = min(ans, dist[n][i]);
    }

    cout << ans << endl;

    return 0;
}