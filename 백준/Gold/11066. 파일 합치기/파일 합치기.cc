#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int K;
int arr[501];
int sum[501];
int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // 다시 풀어 보기
    cin >> T;
    while (T--) {
        cin >> K;
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));

        for (int i = 1; i <= K; i++) {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }

        for (int len = 2; len <= K; len++) {
            for (int i = 1; i <= K - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = 1e9;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                        dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][K] << '\n';
    }

    return 0;
}
