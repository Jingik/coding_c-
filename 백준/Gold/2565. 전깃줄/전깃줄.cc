#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> wires(n);
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> wires[i].first >> wires[i].second;
    }

    sort(wires.begin(), wires.end());

    int max_LIS = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (wires[j].second < wires[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_LIS = max(max_LIS, dp[i]);
    }

    cout << (n - max_LIS) << "\n";

    return 0;
}
