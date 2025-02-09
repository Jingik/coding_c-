#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> dp(K + 1, 0); 
    vector<pair<int, int>> items(N); 

    for (int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        items[i] = { W, V };
    }

    for (int i = 0; i < N; i++) {
        int weight = items[i].first, value = items[i].second;

        for (int j = K; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << dp[K] << '\n'; 
    return 0;
}
