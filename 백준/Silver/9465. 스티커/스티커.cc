#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<int>> board(2, vector<int>(n + 1));
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> board[i][j];
            }
        }

        vector<vector<int>> dp(3, vector<int>(n + 1, 0));

        for (int j = 1; j <= n; ++j) {
            dp[0][j] = board[0][j] + max(dp[1][j - 1], dp[2][j - 1]);
            dp[1][j] = board[1][j] + max(dp[0][j - 1], dp[2][j - 1]);
            dp[2][j] = max({ dp[0][j - 1], dp[1][j - 1], dp[2][j - 1] });
        }

        int result = max({ dp[0][n], dp[1][n], dp[2][n] });
        cout << result << '\n';
    }

    return 0;
}