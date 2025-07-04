#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, sum;
vector<int> arr;

int cnt = 0;
void dfs(int idx, int tmp) {

	if (idx == N) return;
	if (tmp + arr[idx] == sum) cnt++;

	dfs(idx + 1, tmp);
	dfs(idx + 1, tmp + arr[idx]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> sum;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	dfs(0, 0);
	cout << cnt << '\n';

	return 0;
}