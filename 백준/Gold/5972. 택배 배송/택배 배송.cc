#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

struct Info {
    int node;
    long long cost;

    bool operator>(const Info& other) const {
        return this->cost > other.cost;
    }
};

struct Edge {
    int to;
    int cost;
};

vector<Edge> graph[50001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    const long long INF = numeric_limits<long long>::max();
    vector<long long> dist(n + 1, INF);
    priority_queue<Info, vector<Info>, greater<Info>> pq;

    dist[1] = 0;
    pq.push({ 1, 0 });

    while (!pq.empty()) {
        Info current = pq.top();
        pq.pop();

        int u_node = current.node;
        long long u_cost = current.cost;

        if (u_cost > dist[u_node]) {
            continue;
        }

        if (u_node == n) {
            break;
        }

        for (const auto& edge : graph[u_node]) {
            int v_node = edge.to;
            int edge_cost = edge.cost;

            if (dist[u_node] + edge_cost < dist[v_node]) {
                dist[v_node] = dist[u_node] + edge_cost;
                pq.push({ v_node, dist[v_node] });
            }
        }
    }

    cout << dist[n] << '\n';

    return 0;
}