#include <iostream>
#include <queue>

using namespace std;

int n, m;
int Map[1001][1001];
bool visited[1001][1001][2];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct State {
    int x, y;
    int broken;  
    int dist;  
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        for (int j = 0; j < m; j++) {
            Map[i][j] = row[j] - '0';
        }
    }

    queue<State> q;
    q.push({ 0, 0, 0, 1 }); 
    visited[0][0][0] = true;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        if (cur.y == n - 1 && cur.x == m - 1) {
            cout << cur.dist << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            if (Map[ny][nx] == 0 && !visited[ny][nx][cur.broken]) {
                visited[ny][nx][cur.broken] = true;
                q.push({ nx, ny, cur.broken, cur.dist + 1 });
            }

            if (Map[ny][nx] == 1 && cur.broken == 0 && !visited[ny][nx][1]) {
                visited[ny][nx][1] = true;
                q.push({ nx, ny, 1, cur.dist + 1 });
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
