#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector<int>& lectures, int maxLen, int M) {
    int count = 1, sum = 0;
    for (int len : lectures) {
        if (sum + len > maxLen) {
            count++;
            sum = len;
        }
        else {
            sum += len;
        }
    }
    return count <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> lectures(N);
    int maxLecture = 0, total = 0;

    for (int i = 0; i < N; i++) {
        cin >> lectures[i];
        maxLecture = max(maxLecture, lectures[i]);
        total += lectures[i];
    }

    int left = maxLecture;
    int right = total;
    int result = total;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(lectures, mid, M)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result << '\n';
    return 0;
}
