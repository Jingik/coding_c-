#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int x, n;
	while (cin >> x >> n) {
		x *= 10000000;
		vector<int> vec;
		int temp;

		for (int i = 0; i < n; i++) {
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());

		int low = 0, high = vec.size() - 1;
		bool flag = false;

		while (low < high) {

			int sum = vec[low] + vec[high];
			if (sum == x) {
				flag = true;
				break;
			}
			if (sum < x) { 
				low++;
			}
			else {
				high--;
			}
		}

		if (flag)
			cout << "yes " << vec[low] << ' ' << +vec[high] << endl;
		else
			cout << "danger" << endl;

	}



	return 0;
}