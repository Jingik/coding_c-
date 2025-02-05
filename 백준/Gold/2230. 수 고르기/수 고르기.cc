#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> num_list(N);

    for (int i = 0; i < N; i++) {
        cin >> num_list[i];
    }

    sort(num_list.begin(), num_list.end());

    int left = 0, right = 0;
    int result = INT_MAX;

    while (right < N) {
        int diff = num_list[right] - num_list[left];

        if (diff >= M) {
            result = min(result, diff);
            left++; 
        }
        else {
            right++; 
        }

        if (left > right) {
            right = left;
        }
    }

    cout << result << "\n";
    return 0;
}
