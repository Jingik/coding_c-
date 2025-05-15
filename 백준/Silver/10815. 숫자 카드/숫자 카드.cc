#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    long long N, M;
    cin >> N;
    vector<long long> have_num(N);
    for (long long i = 0; i < N; i++) {
        cin >> have_num[i];
    }

    sort(have_num.begin(), have_num.end());

    cin >> M;
    vector<long long> compare_num(M);
    for (long long i = 0; i < M; i++) {
        cin >> compare_num[i];
    }

    string result;

    for (long long i = 0; i < M; i++) {
        int check = 0;
        long long target = compare_num[i];
        long long left = 0, right = N - 1;

        while (left <= right) {
            long long mid = (left + right) / 2;
            if (have_num[mid] == target) {
                check = 1;
                break;
            } else if (have_num[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        result += to_string(check) + " ";
    }

    cout << result << '\n';
    return 0;
}
