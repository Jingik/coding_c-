#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> score(N);

        for (int i = 0; i < N; i++) {
            cin >> score[i].first >> score[i].second;
        }

        sort(score.begin(), score.end());

        int count = 1;
        int Max_score = score[0].second;

        for (int i = 1; i < N; i++) {
            if (score[i].second < Max_score) {
                count++;
                Max_score = score[i].second;
            }

        }
        cout << count << '\n';
    }

    return 0;
}