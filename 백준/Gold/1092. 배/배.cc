#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cranes(n);
    for (int i = 0; i < n; i++) {
        cin >> cranes[i];
    }

    int m;
    cin >> m;
    vector<int> boxes(m);
    for (int i = 0; i < m; i++) {
        cin >> boxes[i];
    }

    sort(cranes.begin(), cranes.end(), greater<int>());
    sort(boxes.begin(), boxes.end(), greater<int>());

    if (cranes[0] < boxes[0]) {
        cout << -1 << '\n';
        return 0;
    }

    int time = 0;
    int moved_count = 0;
    vector<int> pos(n, 0);
    vector<bool> moved(m, false);

    while (moved_count < m) {
        time++;
        for (int i = 0; i < n; i++) {
            while (pos[i] < m) {
                if (!moved[pos[i]] && cranes[i] >= boxes[pos[i]]) {
                    moved[pos[i]] = true;
                    moved_count++;
                    pos[i]++;
                    break;
                }
                pos[i]++;
            }
        }
    }

    cout << time << '\n';

    return 0;
}