#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Value {
    int day;
    int val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<Value> v(n);

    int max_day = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].day >> v[i].val;
        max_day = max(max_day, v[i].day);
    }

    sort(v.begin(), v.end(), [](const Value& a, const Value& b) {
        return a.day < b.day;
    });

    priority_queue<int> pq;
    int total = 0;
    int idx = n - 1;

    for (int day = max_day; day >= 1; --day) {
        while (idx >= 0 && v[idx].day >= day) {
            pq.push(v[idx].val);
            idx--;
        }

        if (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }
    }

    cout << total << '\n';
    return 0;
}
