#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> floid_list(N);

    for (int i = 0; i < N; i++) {
        cin >> floid_list[i];
    }

    sort(floid_list.begin(), floid_list.end());  // 정렬 (O(N log N))

    vector<long long> result(3);
    long long closest = 1e18;  // 0에 가장 가까운 합 저장

    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;

        while (left < right) {
            long long sum = floid_list[i] + floid_list[left] + floid_list[right];

            if (abs(sum) < abs(closest)) {
                closest = sum;
                result[0] = floid_list[i];
                result[1] = floid_list[left];
                result[2] = floid_list[right];
            }

            if (sum < 0) {
                left++;
            }
            else if (sum > 0) {
                right--;
            }
            else {
                cout << floid_list[i] << " " << floid_list[left] << " " << floid_list[right] << "\n";
                return 0;  // 0에 가장 가까운 값이므로 즉시 종료
            }
        }
    }

    cout << result[0] << " " << result[1] << " " << result[2] << "\n";
    return 0;
}
