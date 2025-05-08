#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	int N; cin >> N;
	queue<int> que;
	for (int i = 1; i < N + 1; i++) {
		que.push(i);
	}

	while (que.size() > 1) {
		que.pop();
		int fr = que.front();
		que.pop();
		que.push(fr);
	}
	int result = que.front();
	cout << result << '\n';

	return 0;
}