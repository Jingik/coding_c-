#include <iostream>

using namespace std;
int dp[100001];
int board[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		dp[i] = dp[i - 1] + board[i];
	}

	int x1, x2, ans;
	for (int i = 0; i < m; i++) {
		cin >> x1 >> x2;
		ans = dp[x2] - dp[x1-1];
		cout << ans << '\n';
	}

	return 0;
}