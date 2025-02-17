#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101;
int N;
int input[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { -1, 1, 0, 0 };

void BFS(int y, int x, int height) {
    queue<pair<int, int>> q;
    visited[y][x] = true;
    q.emplace(y, x);

    while (!q.empty()) {
        auto [cy, cx] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
                if (!visited[ny][nx] && input[ny][nx] >= height) {
                    visited[ny][nx] = true;
                    q.emplace(ny, nx);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    int maxHeight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
            maxHeight = max(maxHeight, input[i][j]);
        }
    }

    int maxCount = 1;

    for (int h = 1; h <= maxHeight; h++) {
        fill(&visited[0][0], &visited[N][N], false);
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && input[i][j] >= h) {
                    BFS(i, j, h);
                    cnt++;
                }
            }
        }

        maxCount = max(maxCount, cnt);
    }

    cout << maxCount << "\n";
    return 0;
}
