#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N;
int cave[126][126];
int dist[126][126];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // {비용, y, x}

    fill(&dist[0][0], &dist[125][126], INF);
    dist[0][0] = cave[0][0];
    pq.push({ dist[0][0], 0, 0 });

    while (!pq.empty()) {
        auto [cost, y, x] = pq.top();
        pq.pop();

        if (cost > dist[y][x]) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

            int newCost = cost + cave[ny][nx];
            if (newCost < dist[ny][nx]) {
                dist[ny][nx] = newCost;
                pq.push({ newCost, ny, nx });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int prob = 1;
    while (true) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> cave[i][j];

        dijkstra();

        cout << "Problem " << prob++ << ": " << dist[N - 1][N - 1] << "\n";
    }
    return 0;
}