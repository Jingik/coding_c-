#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int count=0; int test_case;
    int n, m, val;
    cin >> test_case;

    for (int i = 0; i < test_case; ++i) {
        count = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int j = 0; j < n; ++j) {
            cin >> val;
            q.push({ j, val });
            pq.push(val);
        }
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                ++count;
                if (index == m) {
                    cout << count << endl;
                    break;
                }
            }
            else q.push({ index,value });
        }
    }
}