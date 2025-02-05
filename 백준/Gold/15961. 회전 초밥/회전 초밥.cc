#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector <int> susi_list(N);

	// susi 체크용
	int dp[3001] = { 0, };

	for (int i = 0; i < N; i++) {
		cin >> susi_list[i];
	}

	// 초기 값 설정
	int current = 0;
	for (int i = 0; i < k; i++) {
		if (dp[susi_list[i]] == 0) {
			current++;
		}
		dp[susi_list[i]]++;
	}

	//슬라이딩 윈도우 형식
	int result = current + (dp[c] == 0);

	for (int i = 0; i < N; i++) {
		int remove_idx = i;
		int add_idx = (i + k) % N;

		dp[susi_list[remove_idx]]--;
		if (dp[susi_list[remove_idx]] == 0) current--;

		if (dp[susi_list[add_idx]] == 0) current++;
		dp[susi_list[add_idx]]++;

		result = max(result, current + (dp[c] == 0));
	}

	cout << result << '\n';

	return 0;
}