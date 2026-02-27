#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
int x1, x2;

int binary_search(int x, int start) {
	int left = 0, right = v.size() - 1, ret = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid] <= x) {
			ret = mid + 1;
			if (v[mid] == x && start == 1) return ret - 1;
			left = mid + 1;
		}
		else right = mid - 1; 
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	v.push_back(1987654321);

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cin >> x1 >> x2;
		cout << binary_search(x2, 0) - binary_search(x1, 1) << '\n';
	}
}