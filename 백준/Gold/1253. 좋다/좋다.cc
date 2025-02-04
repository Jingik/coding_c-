#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool twoPointer(vector<int>& num_list, int target) {
    int left = 0, right = num_list.size() - 1;
    int targetValue = num_list[target];

    while (left < right) {
        if (left == target) {
            left++;
            continue;
        }
        if (right == target) {
            right--;
            continue;
        }

        int sum = num_list[left] + num_list[right];

        if (sum == targetValue) {
            return true;
        }
        else if (sum < targetValue) {
            left++;
        }
        else {
            right--;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> num_list(N);

    for (int i = 0; i < N; i++) {
        cin >> num_list[i];
    }

    sort(num_list.begin(), num_list.end());

    int result = 0;
    for (int i = 0; i < N; i++) { 
        if (twoPointer(num_list, i)) {
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}
