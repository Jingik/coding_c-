#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dp[1000] = { 0, };


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <int> card_list(n+2);

	for (int i = 1; i < n+1; i++) {
		cin >> card_list[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card_list[j]);
		}
	}
	cout << dp[n];
	return 0;
}