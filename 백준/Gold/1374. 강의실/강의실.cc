#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Value {
    int st, ed;
};

bool compare(const Value& A, const Value& B) {
    return A.st < B.st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Value> v(n);
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num >> v[i].st >> v[i].ed;
    }

    sort(v.begin(), v.end(), compare);

    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(v[0].ed);

    for (int i = 1; i < n; i++) {
        if (pq.top() <= v[i].st) pq.pop();
        pq.push(v[i].ed);
    }

    cout << pq.size() << '\n';
    return 0;
}
