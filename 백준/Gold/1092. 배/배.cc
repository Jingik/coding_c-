#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
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

    if (cranes[0] < boxes[0]) {
        cout << -1 << '\n';
        return 0;
    }

    vector<bool> moved(m, false);
    int time = 0;
    int moved_count = 0;

    while (moved_count < m) {
        time++;
        int box_idx = 0;
        for (int i = 0; i < n; ++i) {
            while (box_idx < m) {
                if (!moved[box_idx] && cranes[i] >= boxes[box_idx]) {
                    moved[box_idx] = true;
                    moved_count++;
                    break;
                }
                box_idx++;
            }
        }
    }

    cout << time << '\n';

    return 0;
}