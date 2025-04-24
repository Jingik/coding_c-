#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    
    vector<vector<pair<int, int>>> graph(n);
    for (auto& c : costs) {
        graph[c[0]].push_back({c[1], c[2]});
        graph[c[1]].push_back({c[0], c[2]});
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0}); 

    int totalCost = 0;
    int connected = 0;

    while (!pq.empty() && connected < n) {
        auto [cost, now] = pq.top(); pq.pop();

        if (visited[now]) continue;

        visited[now] = true;
        totalCost += cost;
        connected++;

        for (auto& [next, nextCost] : graph[now]) {
            if (!visited[next]) {
                pq.push({nextCost, next});
            }
        }
    }

    return totalCost;
}
