#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> dp_inc(n, 1);
    vector<int> dp_dec(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (A[j] < A[i]) {
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
            }
        }
    }

    int max_length = 0;
    for (int i = 0; i < n; i++) {
        max_length = max(max_length, dp_inc[i] + dp_dec[i] - 1);
    }

    cout << max_length << "\n";

    return 0;
}
