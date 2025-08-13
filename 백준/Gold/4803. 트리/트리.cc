#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> graph[501];
bool visited[501];

void checkComponent(int u, int& nodeCount, int& edgeCountSum) {
    visited[u] = true;
    nodeCount++;
    edgeCountSum += graph[u].size();

    for (int v : graph[u]) {
        if (!visited[v]) {
            checkComponent(v, nodeCount, edgeCountSum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    int caseNum = 1;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 1; i <= n; ++i) {
            graph[i].clear();
        }
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int treeCount = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                int nodeCount = 0;
                int edgeCountSum = 0; 
                checkComponent(i, nodeCount, edgeCountSum);
                int edgeCount = edgeCountSum / 2;
                if (edgeCount == nodeCount - 1) {
                    treeCount++;
                }
            }
        }

        cout << "Case " << caseNum++ << ": ";
        if (treeCount == 0) {
            cout << "No trees.\n";
        }
        else if (treeCount == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << treeCount << " trees.\n";
        }
    }

    return 0;
}