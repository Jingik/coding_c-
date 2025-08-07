#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, new_score, P;
    cin >> N >> new_score >> P;

    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    if (N == P && new_score <= scores.back()) {
        cout << -1 << endl;
        return 0;
    }

    int rank = 1;
    for (int i = 0; i < N; ++i) {
        if (new_score >= scores[i]) {
            rank = i + 1;
            break; 
        }
        else {
            rank = i + 2;
        }
    }
    cout << rank << endl;

    return 0;
}