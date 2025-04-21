#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<string> set;
    vector<string> result;

    string name;
    for (int i = 0; i < N; ++i) {
        cin >> name;
        set.insert(name);
    }

    for (int i = 0; i < M; ++i) {
        cin >> name;
        if (set.find(name) != set.end()) {
            result.push_back(name);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (const string& s : result) {
        cout << s << '\n';
    }

    return 0;
}
