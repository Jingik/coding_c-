#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> heights(N);
    vector<int> result(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    vector<pair<int, int>> s; 

    for (int i = 0; i < N; i++) {
        while (!s.empty() && s.back().second <= heights[i]) {
            s.pop_back();
        }
        if (!s.empty()) {
            result[i] = s.back().first + 1; 
        }
        s.push_back({ i, heights[i] });
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}
