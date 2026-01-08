#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    long long c[5] = {};
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        c[x]++;
    }

    long long boxes = 0;

    boxes += c[4];

    long long use = min(c[3], c[1]);
    boxes += c[3];
    c[1] -= use;
    c[3] = 0;

    boxes += c[2] / 2;
    c[2] %= 2;

    if (c[2]) {
        boxes++;
        if (c[1] >= 2) c[1] -= 2;
        else c[1] = 0;
    }

    boxes += (c[1] + 3) / 4;

    cout << boxes << "\n";
    return 0;
}
