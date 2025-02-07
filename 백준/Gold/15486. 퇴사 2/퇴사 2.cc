#include <iostream>
#include <vector>
#include <algorithm> 
#include <cstring>
using namespace std;

int N;
int dp[1500002];
int P[1500001], T[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(dp, 0, sizeof(dp));
    memset(P, 0, sizeof(P));
    memset(T, 0, sizeof(T));
    for (int i = 1; i < N + 1; i++) {
        cin >> T[i] >> P[i];
    }
    
    for (int i = 1; i < N + 1; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + T[i] <= N + 1) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
    }

    cout << *max_element(dp, dp + 1500002) << '\n';

    return 0;
}
