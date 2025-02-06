#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector <long long> floid_list(N);

	for (int i = 0; i < N; i++) {
		cin >> floid_list[i];
	}

	int left = 0; int right = N-1; long long result = INT_MAX;
	
	while (left < right) {
		long long total = floid_list[left] + floid_list[right];

		if (abs(total) < abs(result)) {
			result = total;
		}
		if (total < 0) {
			left++;
		}
		else if (total > 0) {
			right--;
		}
		else {
			result = 0;
			break;
		}
	}

	cout << result << '\n';

	return 0;
}