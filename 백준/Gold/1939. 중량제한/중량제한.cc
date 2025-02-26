#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;
};

int N, M, start, finish;
vector<Edge> edges;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionNodes(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    edges.resize(M);
    parent.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edges[i] = { A, B, C };
    }
    cin >> start >> finish;

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    });

    for (int i = 1; i <= N; i++) parent[i] = i;

    for (const auto& edge : edges) {
        unionNodes(edge.from, edge.to);

        if (find(start) == find(finish)) {
            cout << edge.weight << '\n';
            return 0;
        }
    }

    return 0;
}
