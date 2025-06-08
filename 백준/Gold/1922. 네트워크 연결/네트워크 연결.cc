#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct value {
    int ed, val;
    bool operator>(const value& other) const {
        return val > other.val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<value>> graph(n + 1);
    bool visited[1001];
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    priority_queue<value, vector<value>, greater<value>> pq;
    int result = 0;

    pq.push({ 1, 0 });

    while (!pq.empty()) {
        value cur = pq.top(); pq.pop();

        if (visited[cur.ed]) continue; 

        visited[cur.ed] = true;
        result += cur.val;

        for (const auto& next : graph[cur.ed]) {
            if (!visited[next.ed]) {
                pq.push(next);
            }
        }
    }

    cout << result << '\n';

    return 0;
}
