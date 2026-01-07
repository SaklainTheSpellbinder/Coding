#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dijkstraGrid(int R, int C, const vector<vector<int>>& grid, pair<int, int> start) {
    vector<vector<long long>> dist(R, vector<long long>(C, INF));
    // Priority Queue: {distance, {r, c}}
    priority_queue<pair<long long, pair<int, int>>, 
                   vector<pair<long long, pair<int, int>>>, 
                   greater<pair<long long, pair<int, int>>>> pq;

    dist[start.first][start.second] = grid[start.first][start.second];
    pq.push({dist[start.first][start.second], start});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (d > dist[r][c]) continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                // The cost to move to (nr, nc) is the value in grid[nr][nc]
                if (dist[r][c] + grid[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + grid[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }
    // Output distance to bottom-right cell as an example
    cout << "Shortest path to end: " << dist[R-1][C-1] << endl;
}