#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> psum(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        psum[i] = psum[i - 1] + x;
    }

    int M;
    cin >> M;

    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << psum[j] - psum[i - 1] << "\n";
    }

    return 0;
}
