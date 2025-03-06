#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int L, N;
        cin >> L >> N;

        int minTime = 0, maxTime = 0;

        for (int i = 0; i < N; i++) {
            int pos;
            cin >> pos;

            int shortest = min(pos, L - pos);
            int longest = max(pos, L - pos);

            minTime = max(minTime, shortest);
            maxTime = max(maxTime, longest);
        }

        cout << minTime << " " << maxTime << '\n';
    }

    return 0;
}
