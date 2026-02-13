#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> getPi(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    int j = 0;

    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            pi[i] = ++j;
    }

    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (!cin || n == 0) break;

        string s;
        cin >> s;

        vector<int> pi = getPi(s);
        int l = pi[n - 1];

        cout << s + s.substr(l) << "\n";
    }

    return 0;
}
