#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int list[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    sort(list, list + n);

    for (int goal = n - 1; goal >= 0; goal--) {
        for (int right = goal - 1; right >= 0; right--) {
            for (int left = 0; left <= right; left++) {

                int target = list[goal] - list[right] - list[left];
                if (target < 0) break;
                if (binary_search(list + left, list + right + 1, target)) {
                    cout << list[goal] << '\n';
                    return 0;
                }
            }
        }
    }

    return 0;
}
