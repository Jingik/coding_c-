#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    deque<pair<int, int>> que;
    deque<int> compare(priorities.begin(), priorities.end());
    for (int i = 0; i < priorities.size(); i++) {
        que.push_back({ priorities[i], i });
    }

    int answer = 0;
    sort(priorities.begin(), priorities.end(), greater<>());
    while (!que.empty()) {
        auto current = que.front();
        que.pop_front();

        if (current.first == priorities[answer]) {
            answer++;
            if (current.second == location) {
                return answer;
            }
        }
        else {
            que.push_back(current);
        }
    }

    return answer;
}