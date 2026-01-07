#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define nl "\n"

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    FAST_IO;
    
    return 0;
}

struct State {
    ll d;
    int u, k1, k2;
    // Min-heap comparison
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

// Inside main:
vector<vector<vector<ll>>> dist(n + 1, vector<vector<ll>>(k1 + 1, vector<ll>(k2 + 1, INF)));
priority_queue<State, vector<State>, greater<State>> pq;

dist[1][0][0] = 0;
pq.push({0, 1, 0, 0});

while (!pq.empty()) {
    State curr = pq.top(); pq.pop();
    ll d = curr.d; int u = curr.u; int i = curr.k1; int j = curr.k2;

    if (d > dist[u][i][j]) continue;

    for (auto& e : adj[u]) {
        int v = e.second; ll w = e.first;

        // 1. No Coupon
        if (dist[u][i][j] + w < dist[v][i][j]) {
            dist[v][i][j] = dist[u][i][j] + w;
            pq.push({dist[v][i][j], v, i, j});
        }

        // 2. Use Type A (50% off)
        if (i < k1) {
            if (dist[u][i][j] + w/2 < dist[v][i + 1][j]) {
                dist[v][i + 1][j] = dist[u][i][j] + w/2;
                pq.push({dist[v][i + 1][j], v, i + 1, j});
            }
        }

        // 3. Use Type B (100% off)
        if (j < k2) {
            if (dist[u][i][j] < dist[v][i][j + 1]) { // Cost is 0
                dist[v][i][j + 1] = dist[u][i][j];
                pq.push({dist[v][i][j + 1], v, i, j + 1});
            }
        }
    }
}