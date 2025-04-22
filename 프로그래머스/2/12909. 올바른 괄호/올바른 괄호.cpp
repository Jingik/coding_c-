#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    bool answer = true;
    string bk;

    if (s.back() == '(') {
        answer = false;
        return answer;
    }

    while (s.size() > 0) {
        char current = s.back();
        s.pop_back();
        if (current == '(') {
            if (bk.empty()) {
                answer = false;
                return answer;
            }
            else {
                bk.pop_back();
            }
        }
        else {
            bk.push_back(')');
        }
    }

    if (bk.size() > 0) {
        answer = false;
    }

    return answer;
}
