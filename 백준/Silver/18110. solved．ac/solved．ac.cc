#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> opinions(n);
    for (int i = 0; i < n; i++) {
        cin >> opinions[i];
    }

    sort(opinions.begin(), opinions.end());

    int cut = round(n * 0.15);
    int sum = 0;
    for (int i = cut; i < n - cut; i++) {
        sum += opinions[i];
    }

    int count = n - cut * 2;
    double average = static_cast<double>(sum) / count;

    cout << round(average) << '\n';

    return 0;
}
