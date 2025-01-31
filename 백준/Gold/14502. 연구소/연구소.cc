#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> lab;
vector<pair<int, int>> virus;
vector<pair<int, int>> emptyCells;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int maxSafeArea = 0;  

int bfs() {
    vector<vector<int>> tempLab = lab;
    queue<pair<int, int>> q;

    for (auto v : virus) {
        q.push(v);
    }

    int safeArea = emptyCells.size() - 3; 
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && tempLab[nx][ny] == 0) {
                tempLab[nx][ny] = 2;
                q.push({nx, ny});
                safeArea--; 

                
                if (safeArea <= maxSafeArea) return 0;
            }
        }
    }

    return safeArea;
}


void buildWall(int count, int startIdx) {
    
    if (count == 3) {
        int safeArea = bfs();
        if (safeArea > maxSafeArea) {
            maxSafeArea = safeArea; 
        }
        return;
    }

    if (emptyCells.size() - startIdx < (3 - count)) return;

    for (int i = startIdx; i < emptyCells.size(); i++) {
        int x = emptyCells[i].first;
        int y = emptyCells[i].second;

        lab[x][y] = 1;
        buildWall(count + 1, i + 1);
        lab[x][y] = 0;  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    lab.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];

            if (lab[i][j] == 2) {
                virus.push_back({i, j});
            } else if (lab[i][j] == 0) {
                emptyCells.push_back({i, j});
            }
        }
    }

    buildWall(0, 0);  

    cout << maxSafeArea << "\n";
    return 0;
}
