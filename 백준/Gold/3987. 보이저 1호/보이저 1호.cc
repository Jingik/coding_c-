#include <iostream>
#include <cstring>
using namespace std;

int N, M;
char grid[502][502];
bool visited[502][502][4];  // 방향 포함 방문 체크

int dx[4] = {-1, 0, 1, 0};  // U, R, D, L
int dy[4] = {0, 1, 0, -1};
char dirs[4] = {'U', 'R', 'D', 'L'};
int resultDir;

bool inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int simulate(int x, int y, int dir) {
    memset(visited, false, sizeof(visited));
    int time = 0;

    while (true) {
        if (!inRange(x, y) || grid[x][y] == 'C') break;

        if (visited[x][y][dir]) return -1;  // 무한 루프
        visited[x][y][dir] = true;
        time++;

        // 거울 처리
        if (grid[x][y] == '/') {
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else dir = 2;
        } else if (grid[x][y] == '\\') {
            if (dir == 0) dir = 3;
            else if (dir == 3) dir = 0;
            else if (dir == 2) dir = 1;
            else dir = 2;
        }

        x += dx[dir];
        y += dy[dir];
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    int startX, startY;
    cin >> startX >> startY;
    startX--, startY--;  // 0-based

    int maxTime = 0;
    bool isVoyager = false;

    for (int d = 0; d < 4; ++d) {
        int t = simulate(startX, startY, d);
        if (t == -1) {
            cout << dirs[d] << '\n' << "Voyager\n";
            return 0;
        }
        if (t > maxTime) {
            maxTime = t;
            resultDir = d;
        }
    }

    cout << dirs[resultDir] << '\n' << maxTime << '\n';
    return 0;
}
