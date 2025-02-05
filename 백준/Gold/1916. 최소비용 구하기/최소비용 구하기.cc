#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

vector<int> dijkstra(int N, int start, vector<vector<pair<int, int>>>& graph) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
    vector<int> dist(N + 1, INF);

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node]) continue; // 이미 처리된 노드

        for (auto& next : graph[node]) {
            int next_node = next.first;
            int next_cost = cost + next.second;

            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push({ next_cost, next_node });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({ to, cost });
    }

    int start, destination;
    cin >> start >> destination;

    vector<int> min_cost = dijkstra(N, start, graph);

    cout << min_cost[destination] << '\n';

    return 0;
}
