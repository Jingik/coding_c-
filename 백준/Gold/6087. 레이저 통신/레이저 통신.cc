#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<vector>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int w, h;
int Map[100][100];
int visited[100][100][4];  // 방향 포함

pair<int, int> start, end_;

struct Node {
    int x, y, dir, cnt;
};

bool is_valid(int x, int y) {
    return 0 <= x && x < w && 0 <= y && y < h;
}

void BFS() {
    queue<Node> q;

    // 4방향 모두 시도
    for (int d = 0; d < 4; d++) {
        q.push({ start.first, start.second, d, 0 });
        visited[start.second][start.first][d] = 0;
    }

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int dir = cur.dir;
        int cnt = cur.cnt;

        // 다음 위치 계속 직진
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (is_valid(nx, ny) && Map[ny][nx] != 1) {
            if (visited[ny][nx][dir] > cnt) {
                visited[ny][nx][dir] = cnt;
                q.push({ nx, ny, dir, cnt });
            }
        }

        // 방향 바꿔서 거울 설치
        for (int nd = 0; nd < 4; nd++) {
            if (nd == dir) continue;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if (!is_valid(nx, ny) || Map[ny][nx] == 1) continue;

            if (visited[ny][nx][nd] > cnt + 1) {
                visited[ny][nx][nd] = cnt + 1;
                q.push({ nx, ny, nd, cnt + 1 });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> w >> h;
    string row;
    int C_cnt = 0;

    for (int i = 0; i < h; i++) {
        cin >> row;
        for (int j = 0; j < w; j++) {
            char c = row[j];
            if (c == '*') Map[i][j] = 1;
            else if (c == '.') Map[i][j] = 0;
            else if (c == 'C') {
                if (C_cnt == 0) {
                    start = { j, i };
                }
                else {
                    end_ = { j, i };
                }
                C_cnt++;
                Map[i][j] = 0;
            }

            for (int d = 0; d < 4; d++) {
                visited[i][j][d] = 1e9;
            }
        }
    }

    BFS();

    int ans = 1e9;
    for (int d = 0; d < 4; d++) {
        ans = min(ans, visited[end_.second][end_.first][d]);
    }

    cout << ans << "\n";
    return 0;
}
