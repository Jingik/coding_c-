#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3; //기본 패턴
        for (int j = 4; j <= i; j += 2) {
            dp[i] += dp[i - j] * 2; //추가 패턴
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
