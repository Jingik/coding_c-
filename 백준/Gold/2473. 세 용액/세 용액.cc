#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector <long long> floid_list(N);

	for (int i = 0; i < N; i++) {
		cin >> floid_list[i];
	}
	sort(floid_list.begin(), floid_list.end());
	
	vector <long long> result(3);
	long long compare = 1e18;

	for (int i = 0; i < N - 2; i++) {
		int left = i + 1; int right = N - 1;
		while (left < right) {
			long long current = floid_list[i] + floid_list[left] + floid_list[right];
			if (abs(current) < abs(compare)) {
				result[0] = floid_list[i]; 
				result[1] = floid_list[left];
				result[2] = floid_list[right];
				compare = current;
			}
			if (current < 0) {
				left++;
			}
			else if (current > 0) {
				right--;
			}
			else {
                cout << floid_list[i] << " " << floid_list[left] << " " << floid_list[right] << "\n";
                return 0;
			}
		}

	}

    cout << result[0] << " " << result[1] << " " << result[2] << "\n";

	return 0;
}