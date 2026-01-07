#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int r1, c1, r2, c2, w;
};

void bellmanFordGrid(int R, int C, const vector<vector<int>>& grid) {
    vector<vector<long long>> dist(R, vector<long long>(C, INF));
    vector<Edge> edges;

    // 1. Convert Grid to Edge List
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                    edges.push_back({r, c, nr, nc, grid[nr][nc]});
                }
            }
        }
    }

    dist[0][0] = grid[0][0];

    // 2. Relax all edges (R*C - 1) times
    for (int i = 0; i < R * C - 1; i++) {
        for (auto& e : edges) {
            if (dist[e.r1][e.c1] != INF && dist[e.r1][e.c1] + e.w < dist[e.r2][e.c2]) {
                dist[e.r2][e.c2] = dist[e.r1][e.c1] + e.w;
            }
        }
    }

    // 3. Check for negative cycles
    bool hasCycle = false;
    for (auto& e : edges) {
        if (dist[e.r1][e.c1] != INF && dist[e.r1][e.c1] + e.w < dist[e.r2][e.c2]) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) cout << "Negative Cycle Detected!" << endl;
    else cout << "Min cost to end: " << dist[R-1][C-1] << endl;
}