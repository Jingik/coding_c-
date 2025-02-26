#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int N, M, start, finish;
vector<vector<Edge>> graph;

bool canCross(int weight) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto& edge : graph[cur]) {
            if (!visited[edge.to] && edge.weight >= weight) {
                visited[edge.to] = true;
                q.push(edge.to);
                if (edge.to == finish) return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    graph.resize(N + 1);

    int minWeight = 1, maxWeight = 0;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({ B, C });
        graph[B].push_back({ A, C });
        maxWeight = max(maxWeight, C);
    }

    cin >> start >> finish;

    int result = 0;
    int low = minWeight, high = maxWeight;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canCross(mid)) {
            result = mid;
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}
