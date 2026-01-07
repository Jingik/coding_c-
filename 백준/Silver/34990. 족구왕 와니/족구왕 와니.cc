#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> X(N), Y(N), R(N);
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> R[i] >> S[i];
    }

    int ans = 0;
    bool skip = false;

    for (int i = 0; i < M; i++) {
        long long tx, ty;
        cin >> tx >> ty;

        if (skip) {
            skip = false;
            continue;
        }

        int best = -1;
        for (int j = 0; j < N; j++) {
            long long dx = X[j] - tx;
            long long dy = Y[j] - ty;
            if (dx * dx + dy * dy <= R[j] * R[j]) {
                if (best == -1 || S[j] > S[best]) {
                    best = j;
                }
            }
        }

        if (best == -1) {
            skip = true;
        } else if (best == 0) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
