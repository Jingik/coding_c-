#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, num, result;
	cin >> n;
	string s;
	queue<int> q;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			q.push(num);
		}
		else if (s == "front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "empty") {
			if (!q.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
		else {
			cout << q.size() << '\n';
		}
	}

	return 0;
}