#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    string S;
    S.reserve(N);
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        S.push_back(ch);
    }

    int left = 0, right = N - 1;
    string result;

    while (left <= right) {
        bool useLeft = false;
        int l = left, r = right;

        while (l < r && S[l] == S[r]) {
            l++;
            r--;
        }

        if (S[l] < S[r]) useLeft = true;
        else useLeft = false;

        if (useLeft) result.push_back(S[left++]);
        else result.push_back(S[right--]);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if ((i + 1) % 80 == 0) cout << '\n';
    }
    cout << '\n';

    return 0;
}
