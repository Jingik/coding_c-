#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<vector<int>> board;
long long memo[17][17][3];

long long solve(int r, int c, int dir) {
    if (r == N - 1 && c == N - 1) {
        return 1;
    }

    if (memo[r][c][dir] != -1) {
        return memo[r][c][dir];
    }

    long long count = 0;

    if (dir == 0) {
        if (c + 1 < N && board[r][c + 1] == 0) {
            count += solve(r, c + 1, 0);
        }
        if (r + 1 < N && c + 1 < N &&
            board[r][c + 1] == 0 && board[r + 1][c] == 0 && board[r + 1][c + 1] == 0) {
            count += solve(r + 1, c + 1, 2);
        }
    }
    else if (dir == 1) {
        if (r + 1 < N && board[r + 1][c] == 0) {
            count += solve(r + 1, c, 1);
        }
        if (r + 1 < N && c + 1 < N &&
            board[r][c + 1] == 0 && board[r + 1][c] == 0 && board[r + 1][c + 1] == 0) {
            count += solve(r + 1, c + 1, 2);
        }
    }
    else {
        if (c + 1 < N && board[r][c + 1] == 0) {
            count += solve(r, c + 1, 0);
        }
        if (r + 1 < N && board[r + 1][c] == 0) {
            count += solve(r + 1, c, 1);
        }
        if (r + 1 < N && c + 1 < N &&
            board[r][c + 1] == 0 && board[r + 1][c] == 0 && board[r + 1][c + 1] == 0) {
            count += solve(r + 1, c + 1, 2);
        }
    }

    return memo[r][c][dir] = count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    memset(memo, -1, sizeof(memo));

    cout << solve(0, 1, 0) << endl;

    return 0;
}