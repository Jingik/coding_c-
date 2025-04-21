#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    getline(cin, s);

    stack<char> stk;
    bool inTag = false;

    for (char c : s) {
        if (c == '<') {
            while (!stk.empty()) {
                cout << stk.top();
                stk.pop();
            }
            inTag = true;
            cout << c;
        }
        else if (c == '>') {
            inTag = false;
            cout << c;
        }
        else if (inTag) {
            cout << c;
        }
        else {
            if (c == ' ') {
                while (!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                cout << ' ';
            }
            else {
                stk.push(c);
            }
        }
    }

    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }

    return 0;
}
