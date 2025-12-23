#include <iostream>
#include <algorithm>

using namespace std;

int num[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n, tmp, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> x;
	sort(num, num + n);
	int sum = 0;
	int left = 0, right = n - 1;
	while (left < right) {
		if (num[left] + num[right] == x) {
			sum += 1;
			left += 1;
			right -= 1;
		}
		else if (num[left] + num[right] > x) {
			right -= 1;
		}
		else {
			left += 1;
		}
	}
	cout << sum;
	
	return 0;
}