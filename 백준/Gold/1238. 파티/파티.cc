#include <iostream>
#include <vector>
#include <queue>
#include <limits> 

using namespace std;

const int INF = numeric_limits<int>::max();

struct State {
    int node;
    int dist; 

    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};

vector<pair<int, int>> graph[1001]; 
vector<pair<int, int>> reverse_graph[1001]; 

int n, m, x;

vector<int> dijkstra(int start_node, vector<pair<int, int>>(&adj_list)[1001]) {

    vector<int> dist(n + 1, INF);
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[start_node] = 0;
    pq.push({ start_node, 0 });

    while (!pq.empty()) {
        State current = pq.top(); 
        pq.pop();

        int u = current.node;
        int d = current.dist;

        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : adj_list[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ v, dist[v] });
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> x; 

    for (int i = 0; i < m; i++) {
        int u, v, time;
        cin >> u >> v >> time;
        graph[u].push_back({ v, time }); 
        reverse_graph[v].push_back({ u, time }); 
    }

    vector<int> dist_from_x = dijkstra(x, graph);
    vector<int> dist_to_x = dijkstra(x, reverse_graph);

    int max_total_time = 0;

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;

        int total_time = dist_to_x[i] + dist_from_x[i];
        max_total_time = max(max_total_time, total_time);
    }

    cout << max_total_time << '\n'; 

    return 0;
}