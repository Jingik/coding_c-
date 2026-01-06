#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    int maxSize = 0;
    int bestBack = 0;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int a;
            cin >> a;
            q.push(a);

            int sz = q.size();
            int back = q.back();

            if (sz > maxSize) {
                maxSize = sz;
                bestBack = back;
            } else if (sz == maxSize) {
                bestBack = min(bestBack, back);
            }
        } else {
            q.pop();
        }
    }

    cout << maxSize << " " << bestBack;
    return 0;
}
