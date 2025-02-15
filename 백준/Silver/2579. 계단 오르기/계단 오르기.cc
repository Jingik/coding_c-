#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	vector <int> dp(N + 1, 0);
	vector <int> arr(N + 1);

	for (int i = 1; i < N + 1; i++) {
		cin >> arr[i];
	}
	
	dp[1] = arr[1];

	if (N >= 2) dp[2] = arr[1] + arr[2];
	if (N >= 3) dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[N] << '\n';

	return 0;
}