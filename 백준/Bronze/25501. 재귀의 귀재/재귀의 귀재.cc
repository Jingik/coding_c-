#include <iostream>
#include <string.h>

using namespace std;

int call_count = 0;

int recursion(const char *s, int l, int r) {
    call_count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
    call_count = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        
        int result = isPalindrome(s.c_str());
        cout << result << " " << call_count << '\n';
    }

    return 0;
}
