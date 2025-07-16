#include <iostream>
#include <string>

using namespace std;

string addStrings(string a, string b) {
    string result = "";
    int carry = 0;

    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;

    for (int i = a.length() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result = char((sum % 10) + '0') + result;
    }

    if (carry) result = '1' + result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << addStrings(a, b) << '\n';
}
