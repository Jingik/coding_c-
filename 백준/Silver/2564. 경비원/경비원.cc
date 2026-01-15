#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;

    vector<int> shops(n);
    for (int i = 0; i < n; i++) {
        int d, x;
        cin >> d >> x;
        if (d == 1) shops[i] = x;
        else if (d == 4) shops[i] = w + x;
        else if (d == 2) shops[i] = w + h + (w - x);
        else shops[i] = w + h + w + (h - x);
    }

    int d, x;
    cin >> d >> x;
    int pos;
    if (d == 1) pos = x;
    else if (d == 4) pos = w + x;
    else if (d == 2) pos = w + h + (w - x);
    else pos = w + h + w + (h - x);

    int per = 2 * (w + h);
    int ans = 0;
    for (int s : shops) {
        int diff = abs(pos - s);
        ans += min(diff, per - diff);
    }

    cout << ans;
    return 0;
}
