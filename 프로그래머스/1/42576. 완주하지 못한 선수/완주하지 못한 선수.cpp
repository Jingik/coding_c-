#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    unordered_map<string, int> check;

    for (auto& name : participant) {
        check[name] += 1;
    }
    for (auto& name : completion) {
        check[name] -= 1;
    }

    string answer = "";

    for (auto x : check) {
        if (x.second != 0) {
            answer = x.first;
        }
    }

    return answer;
}