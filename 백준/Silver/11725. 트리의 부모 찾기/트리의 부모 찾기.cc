#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n;
int visited[100001];
vector<vector<int>> graph;

void BFS() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (const auto& val : graph[cur]) {
			if (visited[val] == -1) {
				visited[val] = cur;
				q.push(val);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	memset(visited, -1, sizeof(visited));
	cin >> n;
	graph.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int st, ed;
		cin >> st >> ed;
		graph[st].push_back(ed);
		graph[ed].push_back(st);
	}

	BFS();

	for (int i = 2; i < n + 1; i++) {
		cout << visited[i] << '\n';
	}

	return 0;
}