#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector <int> T(N + 1);
	vector <int> P(N + 1);
	vector <int> dp(N + 2, 0);
	
	for (int i = 1; i < N + 1; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = 1; i < N + 1; i++) {
		dp[i] = max(dp[i], dp[i - 1]);
		if (i + T[i] <= N + 1) {
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}