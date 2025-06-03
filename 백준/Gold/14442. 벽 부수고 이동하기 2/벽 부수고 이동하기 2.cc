#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

#define X first
#define Y second

int n, m, k;
string board[1001];
int dist[1001][1001]; 
int broke[1001][1001]; 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// BFS 함수
int BFS() {
    queue<pair<int, int>> Q;
    Q.push({ 0, 0 });
    dist[0][0] = 1;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        if (cur.X == n - 1 && cur.Y == m - 1)
            return dist[cur.X][cur.Y];

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (board[nx][ny] == '0') {
                if (dist[nx][ny] > 0 && broke[nx][ny] <= broke[cur.X][cur.Y]) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                broke[nx][ny] = broke[cur.X][cur.Y];
                Q.push({ nx, ny });
            }
            else {
                if (broke[cur.X][cur.Y] == k) continue;
                if (dist[nx][ny] > 0 && broke[nx][ny] <= broke[cur.X][cur.Y] + 1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                broke[nx][ny] = broke[cur.X][cur.Y] + 1;
                Q.push({ nx, ny });
            }
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    int answer = BFS();
    cout << answer << '\n';

    return 0;
}
