#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, S;
    cin >> N >> S;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int minLength = N + 1;
    int sum = 0;
    int start = 0, end = 0;

    while (true) {
        if (sum >= S) {
            minLength = min(minLength, end - start);
            sum -= arr[start++];
        }
        else if (end == N) {
            break;
        }
        else {
            sum += arr[end++];
        }
    }

    cout << (minLength == N + 1 ? 0 : minLength) << '\n';
    return 0;
}
