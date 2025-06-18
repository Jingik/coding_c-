#include <iostream>
#include <queue>
#include <vector> 
#include <limits> 

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Map[101][101];
int dist[101][101];

struct State {
    int x, y, weight;

    bool operator>(const State& other) const {
        return weight > other.weight;
    }
};

int n, m;

int Dijkstra() {
    priority_queue<State, vector<State>, greater<State>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = numeric_limits<int>::max();
        }
    }

    pq.push({ 0, 0, 0 });
    dist[0][0] = 0;

    while (!pq.empty()) {
        State cur = pq.top(); pq.pop();
        if (dist[cur.y][cur.x] < cur.weight) continue;
        if (cur.y == n - 1 && cur.x == m - 1) return cur.weight;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            int next_weight = cur.weight;
            if (Map[ny][nx] == 1) {
                next_weight += 1;
            }

            if (next_weight < dist[ny][nx]) {
                dist[ny][nx] = next_weight;
                pq.push({ nx, ny, next_weight });
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cell;
            cin >> cell;
            Map[i][j] = cell - '0';
        }
    }

    int answer = Dijkstra();
    cout << answer << '\n';

    return 0;
}