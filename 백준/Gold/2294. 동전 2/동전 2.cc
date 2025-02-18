#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n);
    vector<int> dp(k + 1, 10001);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    for (int c = 0; c < n; c++) {
        for (int i = coin[c]; i < k + 1; i++) {
            dp[i] = min(dp[i], dp[i - coin[c]] + 1);
        }
    }

    cout << (dp[k] == 10001 ? -1 : dp[k]) << "\n";
    return 0;
}
