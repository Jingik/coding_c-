#include <iostream>
#include <queue>
#include <cstring> // memset 사용

using namespace std;

const int MAX = 50; 
int N, L, R;
int Map[MAX][MAX];
int visited[MAX][MAX]; 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int find_unions() {
    memset(visited, 0, sizeof(visited));
    int move_count = 0;

    pair<int, int> union_list[MAX * MAX];
    int union_size = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) { 
                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = 1;

                int total_population = Map[i][j];
                int total_count = 1;

                union_list[0] = { i, j };
                union_size = 1;

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0) {
                            int diff = abs(Map[cur.first][cur.second] - Map[nx][ny]);

                            if (L <= diff && diff <= R) {
                                visited[nx][ny] = 1;
                                q.push({ nx, ny });

                                total_population += Map[nx][ny];
                                union_list[union_size++] = { nx, ny };
                                total_count++;
                            }
                        }
                    }
                }

                if (union_size > 1) {
                    int new_population = total_population / total_count;

                    for (int k = 0; k < union_size; k++) {
                        Map[union_list[k].first][union_list[k].second] = new_population;
                    }

                    move_count++;
                }
            }
        }
    }

    return move_count; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }

    int result = 0;

    while (true) {
        int moved = find_unions();
        if (moved == 0) break;
        result++;
    }

    cout << result << '\n';
    return 0;
}
