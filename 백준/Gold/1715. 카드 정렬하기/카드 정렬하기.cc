#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int total = 0;

    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int sum = first + second;
        total += sum;

        pq.push(sum);
    }

    cout << total << '\n';

    return 0;
}
