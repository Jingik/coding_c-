#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
vector<vector<int>> Map;
vector<vector<bool>> visited;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<vector<pair<int, int>>> find_unions() {
    visited.assign(N, vector<bool>(N, false));
    vector<vector<pair<int, int>>> unions; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                vector<pair<int, int>> union_list;
                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;
                int total_population = Map[i][j];
                int total_count = 1;
                union_list.push_back({ i, j });

                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.first + dx[d];
                        int ny = cur.second + dy[d];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                            int diff = abs(Map[cur.first][cur.second] - Map[nx][ny]);

                            if (L <= diff && diff <= R) {
                                visited[nx][ny] = true;
                                q.push({ nx, ny });
                                union_list.push_back({ nx, ny });
                                total_population += Map[nx][ny];
                                total_count++;
                            }
                        }
                    }
                }

                if (union_list.size() > 1) {
                    unions.push_back(union_list);
                }
            }
        }
    }

    return unions;
}

void move_population(const vector<vector<pair<int, int>>>& unions) {
    for (const auto& union_list : unions) {
        int total_population = 0;
        for (const auto& pos : union_list) {
            total_population += Map[pos.first][pos.second];
        }

        int new_population = total_population / union_list.size();
        for (const auto& pos : union_list) {
            Map[pos.first][pos.second] = new_population;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    Map.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }

    int result = 0;

    while (true) {
        vector<vector<pair<int, int>>> unions = find_unions();

        if (unions.empty()) break;
        move_population(unions);
        result++;
    }

    cout << result << '\n';
    return 0;
}
