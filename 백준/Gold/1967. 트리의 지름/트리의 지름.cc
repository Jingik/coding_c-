#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
bool visited[10001];
int maxDist = 0;
int faternode = 0;
void DFS(int node, int dist) {
    if (maxDist < dist) {
        maxDist = dist;
        faternode = node;
    }
    for (const auto& val : graph[node]) {
        if (!visited[val.first]) {
            visited[val.first] = true;
            DFS(val.first, dist + val.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int start, end, val;
        cin >> start >> end >> val;
        graph[start].push_back({ end, val });
        graph[end].push_back({ start, val });
    }

    memset(visited, false, sizeof(visited));
    visited[1] = true;
    DFS(1, 0);

    maxDist = 0;
    memset(visited, false, sizeof(visited));
    visited[faternode] = true;
    DFS(faternode, 0);

    cout << maxDist << '\n';

    return 0;
}
