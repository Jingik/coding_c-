#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int num;
	cin >> num;

	int count = 0;
	while (num >= 0) {
		if (num % 5 == 0) {
			count += num / 5;
			cout << count << '\n';
			return 0;
		}
		num -= 3;
		count++;
	}

	cout << -1 << '\n';

	return 0;
}