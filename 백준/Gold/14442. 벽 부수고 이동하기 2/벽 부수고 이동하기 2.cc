#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State {
    int x, y, dist, broken;
};

int n, m, k;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int Map[1001][1001];
int visited[1001][1001][10];

bool isValid(int x, int y) {
    return 0 <= x && x < m && 0 <= y && y < n;
}

int BFS() {
    //vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
    queue<State> q;

    q.push({ 0, 0, 1, 0 });
    visited[0][0][0] = true;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        if (cur.x == m - 1 && cur.y == n - 1) {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (!isValid(nx, ny)) continue;

            if (Map[ny][nx] == 0 && !visited[ny][nx][cur.broken]) {
                visited[ny][nx][cur.broken] = true;
                q.push({ nx, ny, cur.dist + 1, cur.broken });
            }

            else if (Map[ny][nx] == 1 && cur.broken < k && !visited[ny][nx][cur.broken + 1]) {
                visited[ny][nx][cur.broken + 1] = true;
                q.push({ nx, ny, cur.dist + 1, cur.broken + 1 });
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    //vector<vector<int>> Map(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            Map[i][j] = row[j] - '0';
        }
    }

    cout << BFS() << '\n';
    return 0;
}
