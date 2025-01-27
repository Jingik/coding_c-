#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> Map;
vector<vector<bool>> visited;
vector<int> check_list;

int dx[4] = { 1, -1, 0, 0 }; 
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y, int N) {
    queue<pair<int, int>> que;

    if (!visited[x][y] && Map[x][y] == 1) { 
        int c_count = 1;
        que.push({ x, y });
        visited[x][y] = true;

        while (!que.empty()) {
            pair<int, int> current = que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int current_x = current.first + dx[i];
                int current_y = current.second + dy[i];

                if (current_x >= 0 && current_x < N && current_y >= 0 && current_y < N &&
                    !visited[current_x][current_y] && Map[current_x][current_y] == 1) {
                    visited[current_x][current_y] = true;
                    que.push({ current_x, current_y });
                    c_count++;
                }
            }
        }
        check_list.push_back(c_count); 
    }
}

int main() {
    int N;
    cin >> N;

    Map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++) {
            Map[i][j] = input[j] - '0'; 
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bfs(i, j, N); 
        }
    }

    sort(check_list.begin(), check_list.end());

    cout << check_list.size() << '\n'; 
    for (int size : check_list) {
        cout << size << '\n'; 
    }

    return 0;
}
