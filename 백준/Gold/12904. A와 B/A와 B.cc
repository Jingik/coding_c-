#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    while (t.length() > s.length()) {
        char last_char = t.back();
        t.pop_back();

        if (last_char == 'B') {
            reverse(t.begin(), t.end());
        }
    }

    if (s == t) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}