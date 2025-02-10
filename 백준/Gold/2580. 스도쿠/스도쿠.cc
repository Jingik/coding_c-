#include <iostream>
#include <vector>
using namespace std;

int arr[9][9], L;
vector<pair<int, int> > v;

bool isend = false;

bool check(int x, int y, int value) {
	for (int i = 0; i < 9; i++) {
		if(arr[i][y] == value) return false;
		if (arr[x][i] == value) return false;
	}
	int part_x = x / 3;
	int part_y = y / 3;
	part_x *= 3;
	part_y *= 3;
	for (int i = part_x; i < part_x + 3; i++) {
		for (int j = part_y; j < part_y + 3; j++) {
			if (arr[i][j] == value) return false;
		}
	}
	return true;
}

void DFS(int cur) {
	if (isend == true) return;
	if (cur == L) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		isend = true;
	}
	else{
		int nx = v[cur].first;
		int ny = v[cur].second;
		for (int i = 1; i <= 9; i++) {
			if (check(nx, ny, i)) {
				arr[nx][ny] = i;
				DFS(cur + 1);
				arr[nx][ny] = 0;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	L = v.size();
	DFS(0);
}