#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (char digit : number) {
        while (!answer.empty() && answer.back() < digit && k > 0) {
            answer.pop_back();
            k--;
        }
        answer += digit;
    }

    if (k > 0) answer = answer.substr(0, answer.size() - k);

    return answer;
}
