#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, M;
vector<long long> tree;

bool compare_tree(int mid) {
	long long cur = 0;
	for (auto num : tree) {
		if (mid >= num) continue;
		cur += (num - mid);
	}
	return cur >= M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	tree.resize(N);
	for (long long i = 0; i < N; i++) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	long long left = 0, right = *max_element(tree.begin(), tree.end());
	long long result = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (compare_tree(mid)) {
			result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << result << '\n';

	return 0;
}