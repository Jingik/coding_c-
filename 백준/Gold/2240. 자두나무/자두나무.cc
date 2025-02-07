#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, W;
    cin >> T >> W;

    vector<int> tree(T + 1);
    vector<vector<int>> dp(T + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= T; i++) {
        cin >> tree[i];
    }

    for (int i = 1; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];

            if ((tree[i] == 1 && j % 2 == 0) || (tree[i] == 2 && j % 2 == 1)) {
                dp[i][j]++;
            }

            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    cout << *max_element(dp[T].begin(), dp[T].end()) << '\n';

    return 0;
}
