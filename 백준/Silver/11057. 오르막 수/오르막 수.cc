#include <iostream>
using namespace std;

int dp[1001][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i <= 9; i++) dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) {
        result = (result + dp[n][i]) % 10007;
    }

    cout << result << '\n';
}
