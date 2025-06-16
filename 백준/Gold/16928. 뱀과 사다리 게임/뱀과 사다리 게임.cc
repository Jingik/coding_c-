#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[101];
int dist[101];

void BFS() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == 100) {
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int next = current + i;

            if (next > 100) {
                continue;
            }

            if (board[next] != 0) {
                next = board[next];
            }

            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 101; ++i) {
        board[i] = 0;
        dist[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    BFS();

    cout << dist[100] << '\n';

    return 0;
}