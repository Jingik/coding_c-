#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start) {
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while (!que.empty()) {
        int current = que.front();
        que.pop();
        for (auto x : graph[current]) {
            if (!visited[x]) {
                visited[x] = true;
                que.push(x);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
