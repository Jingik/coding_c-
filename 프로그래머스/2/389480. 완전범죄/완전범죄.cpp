#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = 1e9;
    int size = info.size();
    vector<vector<int>> dp(size + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (dp[i][j] == INF) continue;
            
            int new_a = j + info[i][0];
            if (new_a < n) {
                dp[i + 1][new_a] = min(dp[i + 1][new_a], dp[i][j]);
            }
            
            int new_b = dp[i][j] + info[i][1];
            if (new_b < m) {
                dp[i + 1][j] = min(dp[i + 1][j], new_b);
            }
        }
    }
    
    int answer = INF;
    for (int a = 0; a <= n; ++a) {
        if (dp[size][a] < m) {
            answer = min(answer, a);
        }
    }
    return (answer == INF) ? -1 : answer;
}