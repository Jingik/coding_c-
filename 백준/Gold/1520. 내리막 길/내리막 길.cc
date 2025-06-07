#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int Map[501][501];
int dp[501][501];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int dfs(int y, int x) {
    if (y == n - 1 && x == m - 1) return 1;
    if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (Map[ny][nx] < Map[y][x]) {
            dp[y][x] += dfs(ny, nx);
        }
    }

    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> Map[i][j];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';

    return 0;
}
