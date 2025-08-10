#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long m;
	cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int start = 0;
	int end = 0;
	long long sum = 0;
	int count = 0;

	while (true) {
		if (sum >= m) {
			sum -= a[start];
			start++;
		}
		else if (end == n) {
			break;
		}
		else {
			sum += a[end];
			end++;
		}

		if (sum == m) {
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}