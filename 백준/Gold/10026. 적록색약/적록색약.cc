#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector <vector<int>> Map_normal;
vector <vector<int>> Map_diff;
vector <vector<bool>> vis_normal;
vector <vector<bool>> vis_diff;
int N;

int Bfs(int check, pair<int, int> cur) {
	if (check == 1) {
		queue<pair<int, int>> que;
		que.push(cur);
		if (vis_normal[cur.first][cur.second] == true) {
			return 0;
		}
		vis_normal[cur.first][cur.second] = true;
		while (!que.empty()) {
			pair<int, int> cu = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int cx = cu.first + dx[i];
				int cy = cu.second + dy[i];

				if (0 <= cx && cx < N && 0 <= cy && cy < N && vis_normal[cx][cy] == false && Map_normal[cx][cy] == Map_normal[cur.first][cur.second]) {
					que.push({ cx, cy });
					vis_normal[cx][cy] = true;
				}
			}
		}
	}
	else {
		queue<pair<int, int>> que;
		que.push(cur);
		if (vis_diff[cur.first][cur.second] == true) {
			return 0;
		}
		vis_diff[cur.first][cur.second] = true;
		while (!que.empty()) {
			pair<int, int> cu = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				int cx = cu.first + dx[i];
				int cy = cu.second + dy[i];

				if (0 <= cx && cx < N && 0 <= cy && cy < N && vis_diff[cx][cy] == false && Map_diff[cx][cy] == Map_diff[cur.first][cur.second]) {
					que.push({ cx, cy });
					vis_diff[cx][cy] = true;
				}
			}
		}

	}
	return 1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	Map_normal.resize(N, vector<int>(N, 0));
	Map_diff.resize(N, vector<int>(N, 0));
	vis_normal.resize(N, vector<bool>(N, false));
	vis_diff.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'R') {
				Map_diff[i][j] = 1;
				Map_normal[i][j] = 1;
			}
			else if (str[j] == 'G') {
				Map_diff[i][j] = 1;
				Map_normal[i][j] = 2;
			}
			else {
				Map_diff[i][j] = 2;
				Map_normal[i][j] = 3;
			}
		}
	}
	int nor_res = 0;
	int dif_res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nor_res += Bfs(1, {i,j});
			dif_res += Bfs(2, {i,j});
		}
	}

	cout << nor_res << " " << dif_res << '\n';
	return 0;
}