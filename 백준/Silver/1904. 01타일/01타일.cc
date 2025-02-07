#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector <long long> dp(n + 1, 1);
    dp[2] = 2;
    for (long long i = 3; i < n + 1; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    }
    
    cout << dp[n] << '\n';

    return 0;
}
