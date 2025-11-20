#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	deque<int> dq;
	int od, val;
	for (int i = 0; i < n; i++) {
		cin >> od;
		if (od == 1) {
			cin >> val;
			dq.push_back(val);
		}
		else if (od == 2) {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (od == 3) {
			cout << dq.size() << '\n';
		}
		else if (od == 4) {
			if (dq.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}