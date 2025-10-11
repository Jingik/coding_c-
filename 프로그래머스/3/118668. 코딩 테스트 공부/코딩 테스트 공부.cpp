#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = 0, max_cop = 0;
    for (auto& p : problems) {
        max_alp = max(max_alp, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    
    if (alp >= max_alp && cop >= max_cop) return 0;
    
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    
    vector<vector<int>> dp(max_alp + 1, vector<int>(max_cop + 1, 1e9));
    dp[alp][cop] = 0;
    
    for (int a = alp; a <= max_alp; a++) {
        for (int c = cop; c <= max_cop; c++) {
            if (a < max_alp) dp[a + 1][c] = min(dp[a + 1][c], dp[a][c] + 1);
            if (c < max_cop) dp[a][c + 1] = min(dp[a][c + 1], dp[a][c] + 1);
            
            for (auto& p : problems) {
                int alp_req = p[0], cop_req = p[1], alp_rwd = p[2], cop_rwd = p[3], cost = p[4];
                if (a >= alp_req && c >= cop_req) {
                    int next_alp = min(max_alp, a + alp_rwd);
                    int next_cop = min(max_cop, c + cop_rwd);
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[a][c] + cost);
                }
            }
        }
    }
    
    return dp[max_alp][max_cop];
}