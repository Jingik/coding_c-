#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Value {
    int val;
    int index;
};

bool compare(const Value& x, const Value& y) {
    if (x.val != y.val) return x.val > y.val;
    return x.index < y.index;
}

vector<int> solution(vector<int> answers) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<Value> number = { {0, 1}, { 0, 2 }, { 0, 3 } };
    int num2_rules[] = {1, 3, 4, 5};
    int num3_rules[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for (int i = 0; i < answers.size(); i++) {
        // 1번
        if (answers[i] == (i % 5) + 1) number[0].val++;

        // 2번
        if (i % 2 == 0) {
            if (answers[i] == 2) number[1].val++;
        } else {
            if (answers[i] == num2_rules[(i / 2) % 4]) number[1].val++;
        }

        // 3번
        if (answers[i] == num3_rules[i % 10]) number[2].val++;
    }

    sort(number.begin(), number.end(), compare);

    vector<int> answer;
    int check = number[0].val;
    for (const auto& ck : number) {
        if (ck.val == check) answer.push_back(ck.index);
    }
    return answer;
}
