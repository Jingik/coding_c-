#include <iostream>
#include <algorithm>//min
#include <vector>
using namespace std;

struct Roll {
	int r, c, s;
};

int N, M, K;
int A[51][51];
int c_A[51][51];
vector<Roll>Op;
int Order[6];
bool check[6];
int Min = 987654321;

void Rolling(int r, int c, int s) {
	for (int d = 1; d <= s; d++) {
		int tmp = c_A[r - d][c - d];
		for (int i = r - d + 1; i <= r + d; i++) {
			c_A[i - 1][c - d] = c_A[i][c - d];
		}
		for (int i = c - d + 1; i <= c + d; i++) {
			c_A[r + d][i - 1] = c_A[r + d][i];
		}
		for (int i = r + d - 1; i >= r - d; i--) {
			c_A[i + 1][c + d] = c_A[i][c + d];
		}
		for (int i = c + d - 1; i > c - d; i--) {
			c_A[r - d][i + 1] = c_A[r - d][i];
		}
		c_A[r - d][c - d + 1] = tmp;
	}
}

void Simul() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			c_A[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int od = Order[i];
		int r = Op[od].r;
		int c = Op[od].c;
		int s = Op[od].s;
		Rolling(r, c, s);
	}
	for (int k = 1; k <= N; k++) {
		for (int j = 1; j <= M; j++) {
			res += c_A[k][j];
		}
		Min = min(Min, res);
		res = 0;
	}
}

void dfs(int cnt) {
	if (cnt == K) {
		Simul();
		return;
	}
	for (int i = 0; i < K; i++) {
		if (check[i] == true)
			continue;
		check[i] = true;
		Order[cnt] = i;
		dfs(cnt + 1);
		check[i] = false;
	}
}

void solution() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		Op.push_back({ r,c,s });
	}
	dfs(0);
	cout << Min << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	solution();
	return 0;
}