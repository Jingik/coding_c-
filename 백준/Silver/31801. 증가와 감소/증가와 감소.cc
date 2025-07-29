#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_B = 1000000;
vector<int> prefix_sum(MAX_B + 1, 0);

bool is_increasing_decreasing(int n) {
    string s = to_string(n);
    int len = s.length();

    if (len < 3) {
        return false;
    }

    int peak_idx = 0;
    while (peak_idx + 1 < len && s[peak_idx] < s[peak_idx + 1]) {
        peak_idx++;
    }

    if (peak_idx == 0 || peak_idx == len - 1) {
        return false;
    }

    int current_idx = peak_idx;
    while (current_idx + 1 < len && s[current_idx] > s[current_idx + 1]) {
        current_idx++;
    }

    return current_idx == len - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 1; i <= MAX_B; ++i) {
        prefix_sum[i] = prefix_sum[i - 1];
        if (is_increasing_decreasing(i)) {
            prefix_sum[i]++;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int result = prefix_sum[b] - prefix_sum[a - 1];
        cout << result << "\n";
    }

    return 0;
}