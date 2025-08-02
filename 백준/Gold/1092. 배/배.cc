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

    int time = 0;
    while (!boxes.empty()) {
        time++;
        int crane_idx = 0; 

        for (int i = 0; i < cranes.size(); ++i) {
            for (int j = 0; j < boxes.size(); ++j) {
                if (cranes[i] >= boxes[j]) {
                    boxes.erase(boxes.begin() + j); 
                    goto next_crane; 
                }
            }
        next_crane:;
        }
    }

    cout << time << '\n';

    return 0;
}