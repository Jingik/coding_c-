#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int N;
vector<vector<int>> Map_normal, Map_diff;
vector<vector<bool>> vis_normal, vis_diff;

// BFS 함수
int Bfs(vector<vector<int>>& Map, vector<vector<bool>>& vis, int x, int y) {
    if (vis[x][y]) return 0; // 이미 방문한 곳이면 BFS 수행 X

    queue<pair<int, int>> q;
    q.push({ x, y });
    vis[x][y] = true;
    int color = Map[x][y]; // 현재 색상 저장

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int cur_x = cur.first, cur_y = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!vis[nx][ny] && Map[nx][ny] == color) {
                    vis[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
    return 1; // 새로운 구역 탐색 완료
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    Map_normal.resize(N, vector<int>(N));
    Map_diff.resize(N, vector<int>(N));
    vis_normal.resize(N, vector<bool>(N, false));
    vis_diff.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            if (str[j] == 'R') {
                Map_normal[i][j] = 1;
                Map_diff[i][j] = 1;  
            }
            else if (str[j] == 'G') {
                Map_normal[i][j] = 2; 
                Map_diff[i][j] = 1;   
            }
            else {
                Map_normal[i][j] = 3;  
                Map_diff[i][j] = 3;
            }
        }
    }

    int nor_res = 0, dif_res = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            nor_res += Bfs(Map_normal, vis_normal, i, j);
            dif_res += Bfs(Map_diff, vis_diff, i, j);
        }
    }

    cout << nor_res << " " << dif_res << '\n';
    return 0;
}
