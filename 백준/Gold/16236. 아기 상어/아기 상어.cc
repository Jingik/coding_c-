#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct State {
	int dist;
	int y;
	int x;

	bool operator<(const State& other) const {
		if (dist != other.dist) {
			return dist < other.dist;
		}
		if (y != other.y) {
			return y < other.y;
		}
		return x < other.x;
	}
};

int n;
int Map[21][21];
int shark_x, shark_y;

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				shark_y = i;
				shark_x = j;
				Map[i][j] = 0;
			}
		}
	}

	int shark_size = 2;
	int eat_count = 0;
	int total_time = 0;

	while (true) {
		queue<State> q;
		vector<vector<int>> dist_map(n, vector<int>(n, -1));
		vector<State> candidates;

		q.push({ 0, shark_y, shark_x });
		dist_map[shark_y][shark_x] = 0;

		while (!q.empty()) {
			State current = q.front();
			q.pop();

			int d = current.dist;
			int y = current.y;
			int x = current.x;

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
					continue;
				}
				if (dist_map[ny][nx] != -1 || Map[ny][nx] > shark_size) {
					continue;
				}

				dist_map[ny][nx] = d + 1;
				q.push({ dist_map[ny][nx], ny, nx });

				if (Map[ny][nx] > 0 && Map[ny][nx] < shark_size) {
					candidates.push_back({ dist_map[ny][nx], ny, nx });
				}
			}
		}

		if (candidates.empty()) {
			break;
		}

		sort(candidates.begin(), candidates.end());

		State best_target = candidates[0];

		total_time += best_target.dist;
		shark_y = best_target.y;
		shark_x = best_target.x;
		Map[shark_y][shark_x] = 0;
		eat_count++;

		if (eat_count == shark_size) {
			shark_size++;
			eat_count = 0;
		}
	}

	cout << total_time << endl;

	return 0;
}