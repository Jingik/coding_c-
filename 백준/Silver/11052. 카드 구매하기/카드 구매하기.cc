#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> P, dp;

int solve(int i) {
    if (i == 0) return 0;

    if (dp[i] != -1) return dp[i];

    for (int j = 1; j <= i; j++) {
        dp[i] = max(dp[i], solve(i - j) + P[j]);
    }

    return dp[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    P.resize(N + 1);
    dp.assign(N + 1, -1); 
    for (int i = 1; i <= N; i++) cin >> P[i];

    cout << solve(N) << '\n';
    return 0;
}
