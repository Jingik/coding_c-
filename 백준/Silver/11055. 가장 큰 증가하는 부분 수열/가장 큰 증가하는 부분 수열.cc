#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    int A[1000], dp[1000];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        dp[i] = A[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }
    }

    cout << *max_element(dp, dp + n) << '\n';
    return 0;
}
