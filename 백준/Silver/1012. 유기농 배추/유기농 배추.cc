#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 }; 
int dy[4] = { 0, 0, 1, -1 };
vector<vector<bool>> visited;
vector<vector<int>> Map;    
int total = 0;                

void bfs(int x, int y, int M, int N) {
    queue<pair<int, int>> que;
    visited[x][y] = true;
    que.push({ x, y });

    while (!que.empty()) {
        pair<int, int> current = que.front();
        que.pop();

        int currentX = current.first;
        int currentY = current.second;

        for (int i = 0; i < 4; i++) {
            int cx = currentX + dx[i];
            int cy = currentY + dy[i];

            if (cx >= 0 && cx < M && cy >= 0 && cy < N && !visited[cx][cy] && Map[cx][cy] == 1) {
                visited[cx][cy] = true;
                que.push({ cx, cy });
            }
        }
    }
}

int main() {
    int tc; 
    cin >> tc;

    while (tc--) {
        int M, N, K;
        cin >> M >> N >> K;

        Map.assign(M, vector<int>(N, 0));
        visited.assign(M, vector<bool>(N, false));

        vector<pair<int, int>> cabbage_positions;

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            Map[x][y] = 1;
            cabbage_positions.push_back({ x, y });
        }

        total = 0;

        for (const auto& pos : cabbage_positions) {
            int x = pos.first;
            int y = pos.second;
            if (!visited[x][y]) {
                bfs(x, y, M, N);
                total++;
            }
        }

        cout << total << '\n'; 
    }

    return 0;
}
