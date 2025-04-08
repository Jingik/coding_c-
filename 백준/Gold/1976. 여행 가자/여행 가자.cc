#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int connected;
            cin >> connected;
            if (connected == 1) {
                adj[i].push_back(j);
            }
        }
    }

    vector<int> plan(m);
    for (int i = 0; i < m; ++i) {
        cin >> plan[i];
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;

    int start = plan[0];
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    bool possible = true;
    for (int city : plan) {
        if (!visited[city]) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << endl;

    return 0;
}
