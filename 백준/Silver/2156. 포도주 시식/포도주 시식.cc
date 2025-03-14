#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[10001] = { 0 };
    int dp[10001] = { 0 };

    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    if (n >= 2) {
        dp[2] = arr[1] + arr[2];
    }
    
    for (int i = 3; i < n + 1; i++) {
        dp[i] = max({dp[i-1], dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]});
    }

    cout << dp[n] << "\n";
    return 0;
}
