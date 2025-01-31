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

int maxSafeArea = 0;  // 최대 안전 영역 저장

// BFS를 이용한 바이러스 확산
int bfs() {
    vector<vector<int>> tempLab = lab;
    queue<pair<int, int>> q;

    for (auto v : virus) {
        q.push(v);
    }

    int safeArea = emptyCells.size() - 3; // 벽 3개를 제외한 안전 영역 크기
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
                safeArea--; // 안전 영역이 줄어듦

                // ✅ 가지치기: 현재 safeArea가 maxSafeArea보다 작아지면 중단
                if (safeArea <= maxSafeArea) return 0;
            }
        }
    }

    return safeArea;
}

// 백트래킹을 이용하여 벽 3개를 세우는 과정 (Pruning 추가)
void buildWall(int count, int startIdx) {
    // ✅ 1. 벽을 3개 세운 경우 → BFS 실행 후 조기 종료 가능
    if (count == 3) {
        int safeArea = bfs();
        if (safeArea > maxSafeArea) {
            maxSafeArea = safeArea;  // 최댓값 갱신
        }
        return;
    }

    // ✅ 2. 가지치기: 남은 빈 칸 수가 3개 미만이면 탐색 중단
    if (emptyCells.size() - startIdx < (3 - count)) return;

    for (int i = startIdx; i < emptyCells.size(); i++) {
        int x = emptyCells[i].first;
        int y = emptyCells[i].second;

        lab[x][y] = 1;  // 벽 세우기
        buildWall(count + 1, i + 1);
        lab[x][y] = 0;  // 원래 상태로 복구 (백트래킹)
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

    buildWall(0, 0);  // 백트래킹 시작

    cout << maxSafeArea << "\n";
    return 0;
}
