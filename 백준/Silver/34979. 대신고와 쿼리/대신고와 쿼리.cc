#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> arr(5, vector<int>(N + 2, 0));

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;

            arr[a][b]++;
            if (b - 1 >= 1) arr[a][b - 1]++;
            if (b + 1 <= N) arr[a][b + 1]++;
            if (a - 1 >= 1) arr[a - 1][b]++;
            if (a + 1 <= 4) arr[a + 1][b]++;
        } else {
            int a;
            cin >> a;

            int mx = -1, idx = 1;
            for (int i = 1; i <= N; i++) {
                if (arr[a][i] > mx) {
                    mx = arr[a][i];
                    idx = i;
                }
            }
            cout << idx << '\n';
        }
    }

    int bestVal = -1, bestFloor = 1, bestClass = 1;
    for (int f = 1; f <= 4; f++) {
        for (int c = 1; c <= N; c++) {
            if (arr[f][c] > bestVal ||
               (arr[f][c] == bestVal &&
               (f < bestFloor ||
               (f == bestFloor && c < bestClass)))) {
                bestVal = arr[f][c];
                bestFloor = f;
                bestClass = c;
            }
        }
    }

    cout << bestFloor << " " << bestClass << '\n';
    return 0;
}
