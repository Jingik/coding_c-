#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));
    
    for (const auto& s : skill) {
        int type = s[0], r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];
        int val = (type == 1) ? -degree : degree;
        diff[r1][c1] += val;
        diff[r1][c2 + 1] -= val;
        diff[r2 + 1][c1] -= val;
        diff[r2 + 1][c2 + 1] += val;
    }
    
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < m; ++j)
            diff[i][j] += diff[i][j - 1];
    
    for (int j = 0; j < m; ++j)
        for (int i = 1; i < n; ++i)
            diff[i][j] += diff[i - 1][j];
    
    int answer = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (board[i][j] + diff[i][j] > 0) ++answer;
    
    return answer;
}