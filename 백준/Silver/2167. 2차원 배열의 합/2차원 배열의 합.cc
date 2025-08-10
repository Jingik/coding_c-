#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[301][301];
int dp[301][301];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1] + arr[i][j];
		}
	}
	int tc;
	cin >> tc;
	
	int x1, y1, x2, y2;
	int result = 0;
	for (int i = 0; i < tc; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << result << '\n';
	}

	return 0;
}