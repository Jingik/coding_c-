#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool isAcceptable(const string& s) {
    bool hasVowel = false;
    int vowelCount = 0;
    int consonantCount = 0;

    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            hasVowel = true;
            vowelCount++;
            consonantCount = 0;
        }
        else {
            consonantCount++;
            vowelCount = 0;
        }

        if (vowelCount >= 3 || consonantCount >= 3) {
            return false;
        }

        if (i > 0 && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') {
            return false;
        }
    }

    return hasVowel;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string exam;
    while (true) {
        cin >> exam;
        if (exam == "end") break;

        bool acceptable = isAcceptable(exam);
        cout << "<" << exam << "> is " << (acceptable ? "acceptable." : "not acceptable.") << '\n';
    }

    return 0;
}