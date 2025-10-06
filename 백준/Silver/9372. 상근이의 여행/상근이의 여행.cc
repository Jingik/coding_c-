#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>

using namespace std;

bool visited[1001];
int result = 0;

void DFS(unordered_map<int, vector<int>>& graph, int cur) {
	if (visited[cur]) return;
	visited[cur] = true;

	for (auto& x : graph[cur]) {
		if (!visited[x]) {
			result++;
			DFS(graph, x);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t, n, m, x, y;
	cin >> t;

	while (t > 0) {
		t--;
		result = 0;
		memset(visited, false, sizeof(visited));

		unordered_map<int, vector<int>> graph;
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for (int i = 1; i < n + 1; i++) {
			if (visited[i]) continue;
			DFS(graph, i);
		}
		cout << result << '\n';
	}

	return 0;
}