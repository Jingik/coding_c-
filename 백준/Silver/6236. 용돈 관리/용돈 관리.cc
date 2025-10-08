#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> money;

bool withdraw(int K) {
    int ct = 1;
    int cur = K;

    for (int i = 0; i < N; i++) {
        if (money[i] > K) return false;
        if (cur < money[i]) {
            ct++;
            cur = K;
        }
        cur -= money[i];
    }

    return ct <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    money.resize(N);
    int maxMoney = 0;
    for (int i = 0; i < N; i++) {
        cin >> money[i];
        maxMoney = max(maxMoney, money[i]);
    }

    long long left = maxMoney;
    long long right = 10000LL * N;
    long long result = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (withdraw(mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}