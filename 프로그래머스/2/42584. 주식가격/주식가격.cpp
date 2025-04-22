#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<int> answer;
    deque<int> que(prices.begin(), prices.end());
    while (!que.empty()) {
        int check = 0;
        int cur = que.front();
        que.pop_front();

        for (const auto x : que) {
            if (cur <= x) check += 1;
            else {
                check += 1;
                break;
            }
        }
        answer.push_back(check);
    }

    return answer;
}