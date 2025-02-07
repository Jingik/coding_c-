#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> T(N + 1), P(N + 1), dp(N + 2, 0);

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        // 현재까지의 최대 이익 유지
        dp[i] = max(dp[i], dp[i - 1]);

        // 상담을 선택하는 경우
        if (i + T[i] <= N + 1) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}
