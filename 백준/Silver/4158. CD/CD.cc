#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<int> sang(N);
        vector<int> sun(M);

        for (int i = 0; i < N; i++) cin >> sang[i];
        for (int i = 0; i < M; i++) cin >> sun[i];

        int i = 0, j = 0, answer = 0;
        while (i < N && j < M) {
            if (sang[i] == sun[j]) {
                answer++;
                i++; j++;
            }
            else if (sang[i] < sun[j]) i++;
            else j++;
        }

        cout << answer << '\n';
    }

    return 0;
}
