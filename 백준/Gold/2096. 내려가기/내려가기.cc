#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int max_dp[3] = { 0 }, min_dp[3] = { 0 };
    int cur[3];

    for (int i = 0; i < N; i++) {
        cin >> cur[0] >> cur[1] >> cur[2];

        if (i == 0) {
            max_dp[0] = min_dp[0] = cur[0];
            max_dp[1] = min_dp[1] = cur[1];
            max_dp[2] = min_dp[2] = cur[2];
        }
        else {
            int max0 = max(max_dp[0], max_dp[1]) + cur[0];
            int max1 = max({ max_dp[0], max_dp[1], max_dp[2] }) + cur[1];
            int max2 = max(max_dp[1], max_dp[2]) + cur[2];

            int min0 = min(min_dp[0], min_dp[1]) + cur[0];
            int min1 = min({ min_dp[0], min_dp[1], min_dp[2] }) + cur[1];
            int min2 = min(min_dp[1], min_dp[2]) + cur[2];

            max_dp[0] = max0;
            max_dp[1] = max1;
            max_dp[2] = max2;

            min_dp[0] = min0;
            min_dp[1] = min1;
            min_dp[2] = min2;
        }
    }

    cout << *max_element(max_dp, max_dp + 3) << " " << *min_element(min_dp, min_dp + 3) << "\n";

    return 0;
}
