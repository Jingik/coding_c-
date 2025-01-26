#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector<int>> computer;
vector <bool> visited;
int total = 0;

void bfs(int start) {
    queue <int> que;
    que.push(start);
    visited[start] = true;

    while (!que.empty()) {
        int current;
        current = que.front();
        que.pop();
        for (int neb : computer[current]) {
            if (!visited[neb]) {
                visited[neb] = true;
                que.push(neb);
                total++;
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    computer.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        computer[x].push_back(y);
        computer[y].push_back(x);
    }


    bfs(1);

    cout << total << '\n';

    return 0;
}
