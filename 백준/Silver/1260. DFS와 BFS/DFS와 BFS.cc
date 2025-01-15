#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V; 
vector<vector<int>> graph; 
vector<bool> visited;      


void dfs(int start) {
    cout << start << " ";
    visited[start] = true;

    for (int next : graph[start]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}


void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int next : graph[current]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> V;

    graph.resize(N + 1); 

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from); 
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    visited.resize(N + 1, false);
    dfs(V);
    cout << endl;

    fill(visited.begin(), visited.end(), false); 
    bfs(V);

    return 0;
}