#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int main() {
    int n, m, max_steps = 5; // Can only discount within first 5 edges
    cin >> n >> m;

    vector<pair<ll, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    // dist[node][state][steps_taken]
    // We need steps_taken because a shorter distance path with more steps 
    // might block a slightly longer path that still has discount eligibility.
    ll dist[n + 1][2][max_steps + 2];
    for(int i=0; i<=n; i++)
        for(int j=0; j<2; j++)
            for(int s=0; s<=max_steps+1; s++) dist[i][j][s] = INF;

    // {distance, {node, {state, steps}}}
    priority_queue<pair<ll, pair<int, pair<int, int>>>, 
                   vector<pair<ll, pair<int, pair<int, int>>>>, 
                   greater<pair<ll, pair<int, pair<int, int>>>>> pq;

    dist[1][0][0] = 0;
    pq.push({0, {1, {0, 0}}});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second.first;
        int state = pq.top().second.second.first;
        int s = pq.top().second.second.second;
        pq.pop();

        if (d > dist[u][state][s]) continue;

        for (auto& edge : adj[u]) {
            ll w = edge.first;
            int v = edge.second;
            int next_s = min(max_steps + 1, s + 1); // Cap steps at max_steps + 1

            // 1. Move without using a discount
            if (d + w < dist[v][state][next_s]) {
                dist[v][state][next_s] = d + w;
                pq.push({dist[v][state][next_s], {v, {state, next_s}}});
            }

            // 2. Move using a discount
            // Only if state is 0 AND we haven't exceeded max_steps
            if (state == 0 && s < max_steps) {
                if (d + (w / 2) < dist[v][1][next_s]) {
                    dist[v][1][next_s] = d + (w / 2);
                    pq.push({dist[v][1][next_s], {v, {1, next_s}}});
                }
            }
        }
    }

    ll ans = INF;
    for(int s=0; s<=max_steps+1; s++) {
        ans = min({ans, dist[n][0][s], dist[n][1][s]});
    }
    cout << ans << endl;

    return 0;
}