#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> prev_max(3, 0), curr_max(3, 0);
    vector<int> prev_min(3, 0), curr_min(3, 0);

    for (int j = 0; j < 3; j++) {
        cin >> prev_max[j];
        prev_min[j] = prev_max[j];  // 초기값 동일하게 설정
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            cin >> num;
            if (j == 0) {
                curr_max[j] = num + max(prev_max[j], prev_max[j + 1]);
                curr_min[j] = num + min(prev_min[j], prev_min[j + 1]);
            }
            else if (j == 1) {
                curr_max[j] = num + max({ prev_max[j - 1], prev_max[j], prev_max[j + 1] });
                curr_min[j] = num + min({ prev_min[j - 1], prev_min[j], prev_min[j + 1] });
            }
            else {
                curr_max[j] = num + max(prev_max[j - 1], prev_max[j]);
                curr_min[j] = num + min(prev_min[j - 1], prev_min[j]);
            }
        }
        prev_max = curr_max;
        prev_min = curr_min;
    }

    cout << *max_element(prev_max.begin(), prev_max.end()) << " "
        << *min_element(prev_min.begin(), prev_min.end()) << "\n";

    return 0;
}
