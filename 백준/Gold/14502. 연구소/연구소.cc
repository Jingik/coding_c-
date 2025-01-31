#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> lab;
vector<pair<int, int>> virus;
vector<pair<int, int>> emptyCells;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs() {
    vector<vector<int>> tempLab = lab;
    queue<pair<int, int>> q;

    for (auto v : virus) {
        q.push(v);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && tempLab[nx][ny] == 0) {
                tempLab[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }

    int safeArea = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempLab[i][j] == 0) {
                safeArea++;
            }
        }
    }

    return safeArea;
}

int maxSafeArea() {
    int maxArea = 0;

    int size = emptyCells.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                lab[emptyCells[i].first][emptyCells[i].second] = 1;
                lab[emptyCells[j].first][emptyCells[j].second] = 1;
                lab[emptyCells[k].first][emptyCells[k].second] = 1;

                maxArea = max(maxArea, bfs());

                lab[emptyCells[i].first][emptyCells[i].second] = 0;
                lab[emptyCells[j].first][emptyCells[j].second] = 0;
                lab[emptyCells[k].first][emptyCells[k].second] = 0;
            }
        }
    }

    return maxArea;
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
                virus.push_back({ i, j });
            }
            else if (lab[i][j] == 0) {
                emptyCells.push_back({ i, j });
            }
        }
    }

    cout << maxSafeArea() << "\n";
    return 0;
}
