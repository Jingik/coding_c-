#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        unordered_map<string, int> mp;
        for (int i = 0; i < N; i++) {
            string s;
            int x;
            cin >> s >> x;
            mp[s] += x;
        }

        vector<pair<string, int>> v;
        for (auto &p : mp) {
            v.push_back(p);
        }

        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        cout << v.size() << '\n';
        for (auto &p : v) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    return 0;
}
