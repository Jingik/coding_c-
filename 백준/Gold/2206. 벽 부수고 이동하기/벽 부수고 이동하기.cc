#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct State {
    int y, x;
    int broken;
    int dist;
};

int n, m;
int map[1001][1001];
int visited[1001][1001][2];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    string row;
    for (int i = 0; i < n; ++i) {
        cin >> row;
        for (int j = 0; j < m; ++j) {
            map[i][j] = row[j] - '0';
        }
    }

    queue<State> q;
    q.push({ 0, 0, 0, 1 });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1) {
            cout << cur.dist << '\n';
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (map[ny][nx] == 0 && visited[ny][nx][cur.broken] == 0) {
                visited[ny][nx][cur.broken] = 1;
                q.push({ ny, nx, cur.broken, cur.dist + 1 });
            }

            if (map[ny][nx] == 1 && cur.broken == 0 && visited[ny][nx][1] == 0) {
                visited[ny][nx][1] = 1;
                q.push({ ny, nx, 1, cur.dist + 1 });
            }
        }
    }

    // 도착 불가능
    cout << -1 << '\n';
    return 0;
}
