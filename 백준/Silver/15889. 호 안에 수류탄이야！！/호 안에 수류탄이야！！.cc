#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];

    if (N == 1) {
        cout << "권병장님, 중대장님이 찾으십니다";
        return 0;
    }

    vector<long long> r(N, 0);
    for (int i = 0; i < N - 1; i++) cin >> r[i];

    long long farthest = 0;
    int j = 0;

    for (int i = 0; i < N; i++) {
        if (i > farthest) break;
        while (j < N && x[j] - x[i] <= r[i]) {
            farthest = max(farthest, (long long)j);
            j++;
        }
        if (farthest >= N - 1) {
            cout << "권병장님, 중대장님이 찾으십니다";
            return 0;
        }
    }

    cout << "엄마 나 전역 늦어질 것 같아";
    return 0;
}
