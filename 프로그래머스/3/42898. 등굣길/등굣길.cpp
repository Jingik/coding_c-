#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int Mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (auto ax : puddles) {
        int x = ax[0];
        int y = ax[1];
        dp[y][x] = -1;
    }
    
    dp[1][1] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if(i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % Mod;
            if(j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % Mod;

        }
    }

    return dp[n][m];
}
