#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T, N, M;
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> N;
		unordered_map<int, int> m;
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			m[num] = 1;
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			if (m[num] == 1) 
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
	return 0;
}