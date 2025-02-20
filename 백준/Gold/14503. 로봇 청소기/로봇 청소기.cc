#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool visited[52][52];
int Map[52][52];
int result = 0;

void BFS(int x, int y, int d) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    result++;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        bool check = false;
        for (int i = 1; i <= 4; i++) {
            int nd = (d + 3) % 4;
            int nx = cx + dx[nd];
            int ny = cy + dy[nd];

            if (!visited[nx][ny] && Map[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
                d = nd;
                result++;
                check = true;
                break;
            }
            d = nd;
        }

        if (!check) {
            int nx = cx - dx[d];
            int ny = cy - dy[d];

            if (Map[nx][ny] == 1) break;
            q.push({ nx, ny });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    memset(Map, 1, sizeof(Map));

    int x, y, d;
    cin >> x >> y >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }
    }

    BFS(x, y, d);
    cout << result << '\n';

    return 0;
}
