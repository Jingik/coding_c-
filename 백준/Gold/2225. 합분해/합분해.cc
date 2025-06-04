#include <iostream>
using namespace std;

const int MOD = 1000000000;
int dp[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= k; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[k][n] << '\n';
    return 0;
}
