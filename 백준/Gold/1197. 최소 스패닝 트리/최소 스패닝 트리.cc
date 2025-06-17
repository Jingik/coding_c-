#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State {
	int ed, w;
};

int v, e;
int weight = 0;
vector<vector<State>> graph;
vector<bool> visited;

struct cmp {
	bool operator()(State a, State b) {
		return a.w > b.w;
	}
};

void BFS(int st) {
	priority_queue<State, vector<State>, cmp> pq;
	pq.push({ st, 0 });
	while (!pq.empty()) {
		State cur = pq.top(); pq.pop();
		if (visited[cur.ed]) continue;
		visited[cur.ed] = true;
		weight += cur.w;
		for (const auto& val : graph[cur.ed]) {
			pq.push({ val.ed, val.w });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> v >> e;

	graph.resize(v + 1);
	visited.resize(v + 1);

	for (int i = 0; i < e; i++) {
		int st, ed, we;
		cin >> st >> ed >> we;
		graph[st].push_back({ ed, we });
		graph[ed].push_back({ st, we });
	}

	for (int i = 1; i < v + 1; i++) {
		if (visited[i]) continue;
		BFS(i);
	}

	cout << weight << '\n';
	return 0;
}