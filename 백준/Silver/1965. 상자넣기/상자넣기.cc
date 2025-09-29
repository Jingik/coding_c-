#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;  
    vector<int> boxes(n);

    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }

    vector<int>dp(n + 1, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (boxes[i] > boxes[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}