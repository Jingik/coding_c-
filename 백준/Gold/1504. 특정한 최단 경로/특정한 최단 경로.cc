#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
struct Edge {
    int to, weight;
};

vector<int> dijkstra(int start, const vector<vector<Edge>>& graph, int N) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            int cost = edge.weight;

            if (dist[v] > d + cost) {
                dist[v] = d + cost;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    cin >> N >> E;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist1 = dijkstra(1, graph, N);
    vector<int> distV1 = dijkstra(v1, graph, N);
    vector<int> distV2 = dijkstra(v2, graph, N);

    long long route1 = (long long)dist1[v1] + distV1[v2] + distV2[N];
    long long route2 = (long long)dist1[v2] + distV2[v1] + distV1[N];

    long long result = min(route1, route2);
    if (result >= INF) cout << -1 << "\n";
    else cout << result << "\n";

    return 0;
}
