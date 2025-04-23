#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxCount = 0;

void dfs(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count) {
    maxCount = max(maxCount, count);

    for (int i = 0; i < dungeons.size(); ++i) {
        int need = dungeons[i][0];
        int cost = dungeons[i][1];

        if (!visited[i] && k >= need) {
            visited[i] = true;
            dfs(k - cost, dungeons, visited, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    dfs(k, dungeons, visited, 0);
    return maxCount;
}
