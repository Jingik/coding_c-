#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int bfs(int N, int K) {
    const int MAX = 100000;
    vector<bool> visited(MAX + 1, false);
    queue<pair<int, int>> que; 
    que.push({ N, 0 });

    while (!que.empty()) {
        int current = que.front().first;
        int time = que.front().second;
        que.pop();

        if (current == K) {
            return time;
        }

        if (visited[current]) {
            continue;
        }
        visited[current] = true;

        if (current - 1 >= 0 && !visited[current - 1]) {
            que.push({ current - 1, time + 1 });
        }
        if (current + 1 <= MAX && !visited[current + 1]) {
            que.push({ current + 1, time + 1 });
        }
        if (current * 2 <= MAX && !visited[current * 2]) {
            que.push({ current * 2, time + 1 });
        }
    }

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << bfs(N, K) << '\n';
    return 0;
}
