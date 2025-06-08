#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int next : graph[cur]) {
            if (color[next] == 0) {
                color[next] = -color[cur]; 
                q.push(next);
            }
            else if (color[next] == color[cur]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<vector<int>> graph(v + 1);
        vector<int> color(v + 1, 0);

        for (int i = 0; i < e; i++) {
            int u, v2;
            cin >> u >> v2;
            graph[u].push_back(v2);
            graph[v2].push_back(u);
        }

        bool isBipartite = true;

        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                if (!bfs(i, graph, color)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << '\n';
    }

    return 0;
}
