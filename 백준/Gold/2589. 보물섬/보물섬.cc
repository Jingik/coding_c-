#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring> 

using namespace std;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

int n, m;
string Map[50];

int visited[50][50];

int max_shortest_dist = 0;

struct State {
    int r, c, dist;
};

void BFS(int start_r, int start_c) {
    memset(visited, -1, sizeof(visited));

    queue<State> q;
    q.push({ start_r, start_c, 0 });
    visited[start_r][start_c] = 0;

    int current_max_dist_from_source = 0;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        current_max_dist_from_source = max(current_max_dist_from_source, cur.dist);

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            if (Map[nr][nc] == 'L' && visited[nr][nc] == -1) {
                visited[nr][nc] = cur.dist + 1;
                q.push({ nr, nc, cur.dist + 1 });
            }
        }
    }
    max_shortest_dist = max(max_shortest_dist, current_max_dist_from_source);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> Map[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == 'L') {
                BFS(i, j);
            }
        }
    }

    cout << max_shortest_dist << endl;

    return 0;
}