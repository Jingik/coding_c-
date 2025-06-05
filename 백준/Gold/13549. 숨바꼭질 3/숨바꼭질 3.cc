#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n, k;
const int MAX = 100001;
int dist[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    fill(dist, dist + MAX, 1e9);

    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;

    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();

        if (cur * 2 < MAX && dist[cur * 2] > dist[cur]) {
            dist[cur * 2] = dist[cur];
            dq.push_front(cur * 2);
        }
        if (cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1) {
            dist[cur - 1] = dist[cur] + 1;
            dq.push_back(cur - 1);
        }
        if (cur + 1 < MAX && dist[cur + 1] > dist[cur] + 1) {
            dist[cur + 1] = dist[cur] + 1;
            dq.push_back(cur + 1);
        }
    }

    cout << dist[k] << '\n';
    return 0;
}
