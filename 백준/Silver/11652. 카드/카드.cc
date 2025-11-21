#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<long long, int> freq;
    long long x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        freq[x]++;
    }

    long long answer = 0;
    int maxCnt = 0;

    for (auto &p : freq) {
        long long num = p.first;
        int count = p.second;

        if (count > maxCnt) {
            maxCnt = count;
            answer = num;
        }
    }

    cout << answer << "\n";
    return 0;
}
