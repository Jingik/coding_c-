#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int h;
	stack<pair<int, int>> stk; 
	string ans;
	for (int i = 1; i <= N; i++) {
		cin >> h;
		if (stk.empty()) {
			stk.push({ h, i });
			ans.append("0");
		}
		else {
			while (!stk.empty() && stk.top().first < h) stk.pop();
			if (stk.empty()) ans.append("0");
			else ans.append(to_string(stk.top().second));
			stk.push({ h, i });
		}
		ans.append(" ");
	}
	cout << ans;
}