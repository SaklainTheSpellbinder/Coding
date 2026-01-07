#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct State {
    ll d;
    int u;
    bool used50;
    bool used20;

    // Min-heap comparison
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<ll, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    // dist[node][used50][used20]
    vector<vector<vector<ll>>> dist(n + 1, vector<vector<ll>>(2, vector<ll>(2, INF)));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[1][0][0] = 0;
    pq.push({0, 1, false, false});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        ll d = curr.d;
        int u = curr.u;
        bool u50 = curr.used50;
        bool u20 = curr.used20;

        if (d > dist[u][u50][u20]) continue;

        for (auto& edge : adj[u]) {
            ll w = edge.first;
            int v = edge.second;

            // 1. Pay Full Price
            if (d + w < dist[v][u50][u20]) {
                dist[v][u50][u20] = d + w;
                pq.push({dist[v][u50][u20], v, u50, u20});
            }

            // 2. Use 50% Coupon (if not used yet)
            if (!u50) {
                ll cost = d + (w / 2);
                if (cost < dist[v][1][u20]) {
                    dist[v][1][u20] = cost;
                    pq.push({dist[v][1][u20], v, true, u20});
                }
            }

            // 3. Use 20% Coupon (if not used yet)
            // Note: 20% off means you pay 80% of the price (0.8 * w)
            if (!u20) {
                ll cost = d + (ll)(w * 0.8); 
                if (cost < dist[v][u50][1]) {
                    dist[v][u50][1] = cost;
                    pq.push({dist[v][u50][1], v, u50, true});
                }
            }
        }
    }

    // The answer is the best distance found in any of the 4 "coupon" states at node N
    ll ans = min({dist[n][0][0], dist[n][0][1], dist[n][1][0], dist[n][1][1]});
    cout << ans << endl;

    return 0;
}