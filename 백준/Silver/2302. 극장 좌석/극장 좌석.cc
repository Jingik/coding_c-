#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> VIP(M);
    for (int i = 0; i < M; i++) cin >> VIP[i];

    vector<int> dp(N + 1, 1);
    if (N >= 2) dp[2] = 2; 

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = 1, last = 0;

    for (int i = 0; i < M; i++) {
        int section_length = VIP[i] - last - 1;
        result *= dp[section_length];
        last = VIP[i];
    }

    result *= dp[N - last];

    cout << result << '\n';
    return 0;
}
