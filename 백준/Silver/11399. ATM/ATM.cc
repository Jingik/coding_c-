#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; int ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        ans += arr[i] * (n - i);
    }

    cout << ans << '\n';

    return 0;
}