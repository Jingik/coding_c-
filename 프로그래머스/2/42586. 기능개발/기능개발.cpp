#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> answer;
    queue<int> que;

    for (int i = 0; i < progresses.size(); i++) {
        double remaining = (100 - progresses[i]);
        double speed = speeds[i];
        int days = ceil(remaining / speed);
        que.push(days);
    }

    int front = que.front();
    while (!que.empty()) {
        int num = 0;
        while (!que.empty()&&front >= que.front()) {
            num++;
            que.pop();
        }
        answer.push_back(num);
        front = que.front();
    }

    return answer;
}