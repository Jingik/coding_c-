#include <iostream>
#include <string>

using namespace std;

string s;
int result = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;

    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[i + 1])
            result++;

    if (!result)
        cout << result;

    else cout << result / 2;
}