#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    vector<ll> dist(n + 1, INF), cnt(n + 1, 0);
    vector<int> min_e(n + 1, 2e9), max_e(n + 1, 0);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    cnt[1] = 1;
    min_e[1] = 0;
    max_e[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            ll w = edge.first;
            int v = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                min_e[v] = min_e[u] + 1;
                max_e[v] = max_e[u] + 1;
                pq.push({dist[v], v});
            } 
            else if (dist[u] + w == dist[v]) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                min_e[v] = min(min_e[v], min_e[u] + 1);
                max_e[v] = max(max_e[v], max_e[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << cnt[n] << " " << min_e[n] << " " << max_e[n] << endl;

    return 0;
}